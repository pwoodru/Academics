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

    /**
     * @pre Size >= 0
     * @post returns integer at front of queue
     * @return integer existing at front of queue
     */
    //returns the integer at the front of the queue, but does not remove it
    default Integer peek() {
        Integer x;
        Integer front = null;
        for (Integer i = 0; i < size(); i++) {
            if (i == 0) {
                front = pop();
                add(front);
            }
            else {
                x = pop();
                add(x);
            }
        }
        return front;
    }

    /**
     * @pre Size >= 0
     * @post returns integer at end of queue
     * @return integer existing at end of queue
     */
    //returns the integer at the end of the queue, but does not remove it
    default int endOfQueue() {
        Integer last = null;
        for (int i = 0; i < size(); i++) {
            last = pop();
            add(last);
        }
        return last;

    }

    /**
     * @pre pos >= 1
     * @post inserts integer at specified location in queue
     */
    //inserts x at position pos in the queue
    default void insert(int x, int pos) {
        for (int i = 0; i < size(); i++) {
            if (i == pos) {
                add(x);
            }
            int value = pop();
            add(value);
        }
    }

    /**
     * @pre pos >= 1
     * @post removes integer at specified location and returns it
     * @return integer at position pos in queue
     */
    //removes integer at position pos and returns it
    default Integer remove(int pos) {
        Integer x = null;
        for (int i = 0; i < size(); i++) {
            if (i == pos) {
                x = pop();
            }
        }
        return x;
    }

    /**
     * @pre pos >= 1
     * @post returns integer at position pos in queue
     * @return integer at position pos in queue
     */
    //returns integer at position pos in queue without removing it
    default Integer get(int pos) {
        Integer x = null;
        Integer searching = null;
        for (int i = 0; i < size(); i++) {
            if (i == pos - 1) {
                searching = pop();
                add(searching);
            }
            else {
                x = pop();
                add(x);
            }
        }
        return searching;
    }
}
