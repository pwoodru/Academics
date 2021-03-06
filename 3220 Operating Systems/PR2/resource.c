// CPSC/ECE 3220 summer 2018 resource allocation code
//
// compile with "gcc -Wall resource.c -pthread"
// run with "./a.out" or "valgrind --tool=helgrind ./a.out"

// Programmer(s):  Patrick Woodrum, Ben VonKeller
//
// In the design of this program, I/we have followed the five steps
//   listed in section 5.5.1 of the textbook.
//
// The structure of the program is consistent with the best practices
//   listed in section 5.5.2 of the textbook.
// - Accesses to resource state variables and synchronization variables
//   are only made in the shared object methods, and not in the code
//   that uses resource objects. Although the program is written in C,
//   the object-oriented interface is:
//   * Constructor method is resource_init().
//   * Destructor method is resource_reclaim().
//   * Public methods are resource_allocate(), resource_release(),
//     and resource_print().
// - A lock is used to synchronize all accesses to the state variables,
//   and a condition variable is used to cause threads to wait on
//   resource availability.
// - The lock is acquired at the beginning of methods and released
//   before returns.
// - The lock is held whenever a condition variable operation (wait or
//   signal) is called.
// - The wait operation on a condition variable is done inside a loop.
// - sleep() is not used in the object methods for synchronization.

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define THREADS 20
#define RESOURCES 4


// ---------------------
// -- resource object --
// ---------------------

typedef struct resource_type_tag{

    // state variables

    int type;             // field to distinguish resource type
    int total_count;      // total number of resources of this type
    int available_count;  // number of currently available resources
    char *status;         // pointer to status vector on heap; encoding:
                          //     0 = available, 1 = in use
    char *owner;          // pointer to owner vector on heap; encoding:
                          //     0 to 127 are valid owner ids,
                          //     -1 is invalid owner id
    int signature;        // signature for run-time type checking; put
                          //     after a vector to catch some overflows

    // synchronization variables

    pthread_mutex_t Mlock;		//locking variable
    pthread_cond_t conditionVar;	//condition variable

    // methods other than init (constructor) and reclaim (destructor)

    int (*allocate)( struct resource_type_tag *self, int tid );
    void (*release)( struct resource_type_tag *self, int tid, int rid );
    void (*print)( struct resource_type_tag *self );

} resource_t;


// helper functions

int resource_check( resource_t *r ){

    // does not need locking operations since this is a helper function and
    //   is called by the public methods and the destructor

    if( r->signature == 0x1E5041CE ) return 0;
    else return 1;
}

void resource_error( int code ){

    // does not need locking operations since this is a helper function and
    //   is called by the constructor, the public methods, and the destructor

    switch( code ){
        case 0:  printf( "**** malloc error for resource object\n" );
                 break;
        case 1:  printf( "**** malloc error for status vector\n" );
                 break;
        case 2:  printf( "**** malloc error for owner vector\n" );
                 break;
        case 3:  printf( "**** could not initialize lock for resource\n" );
                 break;
        case 4:  printf( "**** could not initialize condition for resource\n" );
                 break;
        case 5:  printf( "**** reclaim argument is not a valid resource\n" );
                 break;
        case 6:  printf( "**** print argument is not a valid resource\n" );
                 break;
        case 7:  printf( "**** allocate signature check failed\n" );
                 break;
	case 8:  printf( "**** search for resource failed\n" );
		 break;
	case 9:  printf( "**** release signature check failed\n" );
	         break;
	case 10: printf( "**** release rid bounds check failed\n" );
		 break;
	case 11: printf( "**** release ownership check failed\n" );
		 break;
        default: printf( "**** unknown error code\n" );
    }
    exit( 0 );
}


// constructor

    // prototypes for forward referencing of public methods
    int resource_allocate( struct resource_type_tag *, int );
    void resource_release( struct resource_type_tag *, int, int );
    void resource_print( struct resource_type_tag * );

resource_t * resource_init( int type, int total ){
    resource_t *r;
    int i, rc;

    // does not need locking operations since the lock is created
    //   in this function

    r = malloc( sizeof( resource_t ) );   // obtain memory for struct
    if( r == NULL ) resource_error( 0 );

    r->type = type;                       // set data fields
    r->total_count = total;
    r->available_count = total;

    r->status = malloc( total + 1 );      // obtain memory for vector
    if( r->status == NULL )               //     extra entry allows
        resource_error( 1 );              //     faster searching
    for( i = 0; i <= total; i++ )         // 0 = available, 1 = in use
        r->status[i] = 0;

    r->owner = malloc( total );           // obtain memory for vector
    if( r->owner == NULL )
        resource_error( 2 );
    for( i = 0; i < total; i++ )          // -1 = invalid owner id
        r->owner[i] = -1;

    r->signature = 0x1E5041CE;

    // call to pthread_mutex_init() with rc as return code
    // if( rc != 0 ) resource_error( 3 );
    
	rc = pthread_mutex_init( &r->Mlock, NULL );
    
	if( rc != 0 ) { resource_error(3); }

    // call to pthread_cond_init() with rc as return code
    // if( rc != 0 ) resource_error( 4 );
    
	rc = pthread_cond_init( &r->conditionVar, NULL );
    
	if( rc != 0 ){ resource_error(4); }

    r->print = &resource_print;           // set method pointers
    r->allocate = &resource_allocate;
    r->release = &resource_release;

    return r;
}


// destructor

void resource_reclaim( resource_t *r ){

    // does not need locking operations since the lock is destroyed
    //   in this function

    if( resource_check( r ) ) resource_error( 5 );
    // call to pthread_cond_destroy()
    
    pthread_cond_destroy( &r->conditionVar );

    // call to pthread_mutex_destroy()

    pthread_mutex_destroy( &r->Mlock );

    free( r->owner );
    free( r->status );
    free( r );
}


// public methods

  // need to add synchronization operations as appropriate

int resource_allocate( struct resource_type_tag *self, int tid ){
    
	pthread_mutex_lock( &self->Mlock );   // sync lock
    int rid;

    if( resource_check( self ) )          // signature check
        resource_error( 7 );

    // assertion before allocating: self->available_count != 0
    
	while(self -> available_count == 0)
	{
		//wait until assertion is made
        pthread_cond_wait( &self->conditionVar, &self->Mlock );
    }

    rid = 0;                              // initialize search index
    self->status[self->total_count] = 0;  // extra entry is always available
    while( self->status[rid] != 0)        // search until available entry found
        rid++;
    if( rid >= self->total_count)         // bounds check of result
        resource_error( 8 );

    self->status[rid] = 1;                // mark this entry as in use
    self->owner[rid] = tid;               // record which thread has it
    self->available_count--;              // decr count of available resources

    pthread_mutex_unlock( &self->Mlock ); // sync unlock

    return rid;
}

void resource_release( struct resource_type_tag *self, int tid, int rid ){
    
    pthread_mutex_lock( &self->Mlock );   // sync lock

    if( resource_check( self ) )          // signature check
        resource_error( 9 );
    if( rid >= self->total_count)         // bounds check of argument
        resource_error( 10 );
    if( self->owner[rid] != tid)          // check ownership match
        resource_error( 11 );

    self->status[rid] = 0;                // mark this entry as available
    self->owner[rid] = -1;                // reset ownership
    self->available_count++;              // incr count of available resources
    
	pthread_cond_signal( &self->conditionVar ); // signal condition variable
    
	pthread_mutex_unlock( &self->Mlock ); // sync unlock
}

void resource_print( struct resource_type_tag *self ){
    
	pthread_mutex_lock( &self->Mlock );   // sync lock
    int i;
    if( resource_check( self ) )          // signature check
        resource_error( 6 );

    printf( "-- resource table for type %d --\n", self->type );
    for(i = 0; i < self->total_count; i++){
        printf(" resource #%d: %d,%d\n", i, self->status[i], self->owner[i] );
    }
    printf("-------------------------------\n");
    
	pthread_mutex_unlock( &self->Mlock ); // sync unlock

}


// -------------------
// -- end of object --
// -------------------


// argument vector for threads

typedef struct{
    resource_t *rp;
    int id;
} argvec_t;



// worker thread skeleton

void *worker( void *ap ){
    resource_t *resource = ((argvec_t *)ap)->rp;
    int thread_id = ((argvec_t *)ap)->id;
    int resource_id;

    resource_id = (resource->allocate)( resource, thread_id );

    printf( "thread #%d uses resource #%d\n", thread_id, resource_id );
    sleep(1);

    (resource->release)( resource, thread_id, resource_id );

    return NULL;
}


// observer thread

void *observer( void *ap ){
    resource_t *resource = ((argvec_t *)ap)->rp;
    int i;

    for( i = 0; i < 2; i++ ){
        sleep( 2 );
        (resource->print)( resource );
    }

    return NULL;
}


// --------------------------------------------
// -- test driver with one resource instance --
// --------------------------------------------

int main(int argc, char **argv){
    pthread_t threads[ THREADS + 1 ];
    argvec_t args[ THREADS + 1 ];
    int i;
    resource_t *resource_1;

    resource_1 = resource_init( 1, RESOURCES );

    (resource_1->print)( resource_1 );

    for( i = 0; i < THREADS; i++ ){
        args[i].rp = resource_1;
        args[i].id = i;
        if( pthread_create( &threads[i], NULL, &worker, (void *)(&args[i]) ) ){
            printf("**** could not create worker thread %d\n", i);
            exit( 0 );
        }
    }

    i = THREADS;
    args[i].rp = resource_1;
    args[i].id = i;
    if( pthread_create( &threads[i], NULL, &observer, (void *)(&args[i]) ) ){
        printf("**** could not create observer thread\n");
        exit( 0 );
    }

    for( i = 0; i < (THREADS+1); i++ ){
        if( pthread_join( threads[i], NULL ) ){
            printf( "**** could not join thread %d\n", i );
            exit( 0 );
        }
    }

    (resource_1->print)( resource_1 );

    resource_reclaim( resource_1 );

    return 0;
}

