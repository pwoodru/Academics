/* 
 * udpclient.c - A simple UDP client
 * usage: udpclient <host> <port>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <time.h>
#define BUFSIZE 1024

/* 
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];
    char recvbuf[BUFSIZE];
    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }
    /* move h_addr to ip_addr. This enables conversion to a form        */
    /* suitable for printing with the inet_ntoa() function.             */
    struct in_addr ip_addr;
    ip_addr = *(struct in_addr *)(server->h_addr);
    printf("Hostname: %s, was resolved to: %s\n", hostname, inet_ntoa(ip_addr));

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* get a message from the user */
    bzero(buf, BUFSIZE);
    printf("Please enter msg: ");
    fgets(buf, BUFSIZE, stdin);

    /* send the message to the server */
    serverlen = sizeof(serveraddr);

    //clock_t begin = clock();
    struct timeval start, end;
    // start timer. 
    gettimeofday(&start, NULL);

    n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);
    if (n < 0) 
      error("ERROR in sendto");
    
    /* print the server's reply */
    //bzero(buf, BUFSIZE);
    n = 0;
    n=recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, &serveraddr, &serverlen);
    if (n < 0) 
      error("ERROR in recvfrom");

    recvbuf[n] = '\0';

    struct sockaddr_in *addr_in = (struct sockaddr_in *)&serveraddr;
    char *cliip = inet_ntoa(addr_in->sin_addr);
    int cliport = ntohs(addr_in->sin_port);
    printf("Receive %d bytes from IP address: %s, port: %d \n", n, cliip, cliport);

    // stop timer. 
    gettimeofday(&end, NULL); 
    // Calculating total time taken by the program. 
    double time_taken; 
  
    time_taken = (end.tv_sec - start.tv_sec)*1e6; 
    time_taken = (time_taken + (end.tv_usec - start.tv_usec))*1e-6; 
    
    //clock_t end = clock();
    //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("rtt: %lf sec\n", time_taken);

    printf("Echo from server: %s\n", recvbuf);
    return 0;
}
