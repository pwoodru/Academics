package cpsc2150.MyQueue;

public interface IQueue {
    /**
     * A queue containing integers.
     * A queue is a data structure where the first item added to the
     structure is the first item removed from the structure
     * This queue is bounded by MAX_DEPTH
     */
    int MAX_DEPTH = 100;

    /**
     * @pre x <= 0 or x >= 0
     * @post x added to end of queue
     * @param x integer to be added to queue
     */
    // Adds x to the end of the Queue
    void add(Integer x);

    /**
     * @pre Integer <= 0 or Integer >= 0
     * @post integer removed from queue and returned
     * @return Integer from front of queue
     */
    //removes and returns the Integer at the front of the queue
    Integer pop();

    /**
     * @pre Size >= 0
     * @post returns number of integers in queue
     * @return integer representing number of integers in queue
     */
    //returns the number of Integers in the Queue
    int size();
    }