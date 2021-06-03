package cpsc2150.MyQueue;
import java.util.Scanner;
public class QueueApp {

    public static void main(String args[]) {

        IQueue q;
        /*
        You will add in code here to ask the user whether they want an
        array implementation or a list implementation. Then use their
        answer to initialize q appropriately
        */

        Scanner read = new Scanner(System.in);
        int choice;

        System.out.println("Make a selection:");
        System.out.println("1. Array Implementation");
        System.out.println("2. List Implementation");

        choice = read.nextInt();
        if (choice == 1) {
            q = new ArrayQueue();
        }
        else {
            q = new ListQueue();
        }


        Integer x = 42;
        q.add(x);
        x = 17;
        q.add(x);
        x = 37;
        q.add(x);
        x = 36;
        q.add(x);
        x = 12;
        q.add(x);

        //Add the code to print the queue. After the code is finished,
        // the queue should contain all its values in order
        System.out.println(q.toString());

    }
}
