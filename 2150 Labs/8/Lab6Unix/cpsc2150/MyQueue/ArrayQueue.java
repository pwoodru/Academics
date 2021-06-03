package cpsc2150.MyQueue;

    public class ArrayQueue<T> extends AbsQueue<T> implements IQueue<T> {
        // where the data is stored. myQ[0] is the front of the queue
        private T[] myQ;
        //tracks how many items in the queue
        // also used to find the end of the queue
        private int depth;

        /**
         * @invariants size > 0 and size <= MAX_DEPTH
         */
        public ArrayQueue() {
            myQ = (T[]) new Object[MAX_DEPTH];
            depth = -1;
        }

        //complete the class

        // Adds x to the end of the Queue
        public void add(T x) {
            depth++;
            myQ[depth] = x;
        }
        //removes and returns the Integer at the front of the queue
        public T pop() {
            T front = myQ[0];
            for(int i = 0; i < size(); i++) {
                if (size() + 1 <= MAX_DEPTH - 2) {
                    myQ[i] = myQ[i+1];
                }
            }
            depth--;
            return front;

        }
        //returns the number of Integers in the Queue
        public int size() {
            Integer count = 0;
            while (myQ[count] != null) {
                count++;
            }
            return count;
        }

    }
