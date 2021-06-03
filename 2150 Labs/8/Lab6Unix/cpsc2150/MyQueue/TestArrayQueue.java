package cpsc2150.MyQueue;

import org.junit.Test;
import static org.junit.Assert.*;

public class TestArrayQueue {

    private IQueue MakeAQueue() {
        return new ArrayQueue();
    }

    //Default adding to queue check to test basic functionality
    @Test
    public void addTest1() {
        IQueue<Integer> add1 = MakeAQueue();
        add1.add(0);

        Integer a1 = add1.get(1);
        Integer aSize = add1.size();

        assertTrue( a1 == 0 && aSize == 1);
    }

    //Adding multiple integers with the same value, testing that it returns the correct value
    @Test
    public void addTest2() {
        IQueue<Integer> add1 = MakeAQueue();
        add1.add(0);
        add1.add(-1);
        add1.add(0);
        add1.add(1456);
        add1.add(-3);

        Integer a1 = add1.get(4);
        Integer aSize = add1.size();

        assertTrue( a1 == 1456 && aSize == 5);
    }

    //Adding multiple negative values back to back
    @Test
    public void addTest3() {
        IQueue<Integer> add1 = MakeAQueue();
        add1.add(-1);
        add1.add(-1);
        add1.add(-1);
        add1.add(-2);
        add1.add(-2);
        add1.add(-2);
        add1.add(-3);
        add1.add(-3);
        add1.add(-3);

        Integer a1 = add1.get(6);
        Integer aSize = add1.size();

        assertTrue( a1 == -2 && aSize == 9);
    }

    //Testing peek for an array of size 1
    @Test
    public void peekTest1() {
        IQueue<Integer> peek1 = MakeAQueue();
        peek1.add(0);

        Integer a1 = peek1.peek();
        Integer aSize = peek1.size();

        assertTrue( a1 == 0 && aSize == 1);
    }

    //Testing peek for an extremely large (negative) number
    @Test
    public void peekTest2() {
        IQueue<Integer> peek1 = MakeAQueue();
        peek1.add(-8546823);
        peek1.add(0);
        peek1.add(0);
        peek1.add(8546823);

        Integer a1 = peek1.peek();
        Integer aSize = peek1.size();

        assertTrue( a1 == -8546823 && aSize == 4);
    }

    //Testing that peek pulls the correct front value when the array is much larger
    @Test
    public void peekTest3() {
        IQueue<Integer> peek1 = MakeAQueue();
        peek1.add(1);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);
        peek1.add(0);

        Integer a1 = peek1.peek();
        Integer aSize = peek1.size();

        assertTrue( a1 == 1 && aSize == 10);
    }

    //Testing that endOfQueue pulls the correct number in an array of size 1
    @Test
    public void endOfQueueTest1() {
        IQueue<Integer> eoq1 = MakeAQueue();
        eoq1.add(1);

        Integer a1 = eoq1.endOfQueue();
        Integer aSize = eoq1.size();

        assertTrue( a1 == 1 && aSize == 1);
    }

    //Testing that endOfQueue pulls the correct number in a larger array
    @Test
    public void endOfQueueTest2() {
        IQueue<Integer> eoq1 = MakeAQueue();
        eoq1.add(1);
        eoq1.add(0);
        eoq1.add(2);

        Integer a1 = eoq1.endOfQueue();
        Integer aSize = eoq1.size();

        assertTrue( a1 == 2 && aSize == 3);
    }

    //Testing that endOfQueue pulls the correct negative number from the end of the queue
    @Test
    public void endOfQueueTest3() {
        IQueue<Integer> eoq1 = MakeAQueue();
        eoq1.add(1);
        eoq1.add(-3);
        eoq1.add(5);
        eoq1.add(-6);

        Integer a1 = eoq1.endOfQueue();
        Integer aSize = eoq1.size();

        assertTrue( a1 == -6 && aSize == 4);
    }

    //Testing that insert can insert onto position 1 of an array
    @Test
    public void insertTest1() {
        IQueue<Integer> ins1 = MakeAQueue();
        ins1.add(1);
        ins1.add(2);
        ins1.add(3);
        ins1.insert(4,1);

        Integer a1 = ins1.get(1);
        Integer aSize = ins1.size();

        assertTrue( a1 == 4 && aSize == 4);
    }

    //Testing that insert can insert onto position greater than 1 of an array
    @Test
    public void insertTest2() {
        IQueue<Integer> ins1 = MakeAQueue();
        ins1.add(1);
        ins1.add(2);
        ins1.add(3);
        ins1.insert(4,2);

        Integer a1 = ins1.get(2);
        Integer aSize = ins1.size();

        assertTrue( a1 == 4 && aSize == 4);
    }

    //Testing that insert can insert onto last position of large array
    @Test
    public void insertTest3() {
        IQueue<Integer> ins1 = MakeAQueue();
        ins1.add(1);
        ins1.add(2);
        ins1.add(3);
        ins1.add(3);
        ins1.add(3);
        ins1.add(3);
        ins1.add(3);
        ins1.add(3);
        ins1.insert(4,7);

        Integer a1 = ins1.get(7);
        Integer aSize = ins1.size();

        assertTrue( a1 == 4 && aSize == 9);
    }

    //Testing that remove can remove from position 1 of an array
    @Test
    public void removeTest1() {
        IQueue<Integer> rem1 = MakeAQueue();
        rem1.add(1);
        rem1.add(2);

        Integer a1 = rem1.remove(1);
        Integer aSize = rem1.size();

        assertTrue( a1 == 1 && aSize == 1);
    }

    //Testing that remove can remove from position 1 of a larger array
    @Test
    public void removeTest2() {
        IQueue<Integer> rem1 = MakeAQueue();
        rem1.add(1);
        rem1.add(2);
        rem1.add(3);
        rem1.add(4);
        rem1.add(5);

        Integer a1 = rem1.remove(1);
        Integer aSize = rem1.size();

        assertTrue( a1 == 1 && aSize == 4);
    }

    //Testing that remove can remove from position 3 of an array of size 6
    @Test
    public void removeTest3() {
        IQueue<Integer> rem1 = MakeAQueue();
        rem1.add(1);
        rem1.add(2);
        rem1.add(3);
        rem1.add(4);
        rem1.add(5);
        rem1.add(6);

        Integer a1 = rem1.remove(3);
        Integer aSize = rem1.size();

        assertTrue( a1 == 3 && aSize == 5);
    }

    //Testing that get can retrieve from position 2 of an array size 3
    @Test
    public void getTest1() {
        IQueue<Integer> get1 = MakeAQueue();
        get1.add(1);
        get1.add(2);
        get1.add(3);

        Integer a1 = get1.get(2);
        Integer aSize = get1.size();

        assertTrue( a1 == 2 && aSize == 3);
    }

    //Testing that get can retrieve from position 1 of an array size 1
    @Test
    public void getTest2() {
        IQueue<Integer> get1 = MakeAQueue();
        get1.add(1);

        Integer a1 = get1.get(1);
        Integer aSize = get1.size();

        assertTrue( a1 == 1 && aSize == 1);
    }

    //Testing that get can retrieve from position 3 of an array size 3
    @Test
    public void getTest3() {
        IQueue<Integer> get1 = MakeAQueue();
        get1.add(1);
        get1.add(2);
        get1.add(3);

        Integer a1 = get1.get(3);
        Integer aSize = get1.size();

        assertTrue( a1 == 3 && aSize == 3);
    }
}
