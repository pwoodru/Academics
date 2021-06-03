package cpsc2150.MyQueue;

    import java.util.*;
    public class ListQueue implements IQueue {
        //this time store the queue in a list
        //myQ.get(0) is the front of the queue
        private List<Integer> myQ;

        /**
         * @invariants size > 0 and size <= MAX_DEPTH
         */
        public ListQueue() {
            myQ = new ArrayList<>();
        }

        //complete the class

        // Adds x to the end of the Queue
        public void add(Integer x) {
            myQ.add(x);
        }

        //removes and returns the Integer at the front of the queue
        public Integer pop() {
            Integer y = myQ.get(0);
            myQ.remove(y);
            return y;
        }

        //returns the number of Integers in the Queue
        public int size() {
            Integer z = myQ.size();
            return z;
        }

        @Override
        public String toString() {

            String stringData = "";
            stringData = stringData + myQ;
            return stringData;

        }
    }
