package cpsc2150.MyQueue;
import java.util.Scanner;
public class StringQueueApp {

    public static void main(String[] args) {

        String BYE = "9";
        String one = "1";
        String two = "2";
        String three = "3";
        String four = "4";
        String five = "5";
        String six = "6";
        String seven = "7";
        String eight = "8";
        IQueue q;
        /*
        You will add in code here to ask the user whether they want an
        array implementation or a list implementation. Then use their
        answer to initialize q appropriately
        */

        Scanner read = new Scanner(System.in);
        String choice;

        System.out.println("Make a selection:");
        System.out.println("1. Array Implementation");
        System.out.println("2. List Implementation");

        choice = read.next();
        if (choice.equals(one)) {
            q = new ArrayQueue();
        }
        else {
            q = new ListQueue();
        }

        //Loop to check correct input on first run-through
        int yeet = -1;
        while (yeet == -1) {
            System.out.println("Your selection has been accepted, what would you like to do?");
            System.out.println("1. Add to the queue");
            System.out.println("2. Get the next string from the queue");
            System.out.println("3. Peek at the first string in the queue");
            System.out.println("4. Peek at the last string in the queue");
            System.out.println("5. Insert into a position in the queue");
            System.out.println("6. Peek at a string in any position in the queue");
            System.out.println("7. Remove a string from any position in the queue and return it");
            System.out.println("8. Exit");

            choice = read.next();
            yeet = 1;

            //If input is out of bounds, re-input
            if (!choice.equals(one) && !choice.equals(two) && !choice.equals(three) && !choice.equals(four) && !choice.equals(five) &&
                    !choice.equals(six) && !choice.equals(seven) && !choice.equals(eight)) {
                System.out.println("Invalid input parameter. Please choose a number 1-8.");
                yeet = -1;
            }
        }

        //After checking initial choice, begin loop making use of methods
        while (!choice.equals(eight)) {

            //Input parameter check again
            if (!choice.equals(one) && !choice.equals(two) && !choice.equals(three) && !choice.equals(four) && !choice.equals(five) &&
                    !choice.equals(six) && !choice.equals(seven) && !choice.equals(eight)) {
                System.out.println("Invalid input parameter. Please choose a number 1-8.");
            }
            //Add to queue
            else if (choice.equals(one)) {
                String num;
                System.out.println("What string to add to the Queue?");
                num = read.next();
                q.add(num);

                System.out.println("Queue is: ");
                System.out.println(q.toString());

            }
            //Get next number
            else if (choice.equals(two)) {
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {
                    int zero = 0;
                    Object next;
                    next = q.remove(zero);
                    System.out.println("Next string is " + next);
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
            }
            //Peek at first number
            else if (choice.equals(three)) {
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {

                    //Peek at first number, print it and queue
                    Object peeked = q.peek();
                    System.out.println("Peek: " + peeked);
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
            }
            //Peek at last number
            else if (choice.equals(four)) {
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {

                    //Peek at last number in queue, print it and queue
                    Object end = q.endOfQueue();
                    System.out.println("Peek at end: " + end);
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
            }
            //Insert at position
            else if (choice.equals(five)) {
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {
                    //Read user inputs
                    String num;
                    int position;
                    System.out.println("What string to add to the Queue?");
                    num = read.next();
                    System.out.println("What position to insert in?");
                    position = read.nextInt();

                    //Check valid positioning
                    while ((position < 0) || (position > q.size())) {
                        System.out.println("Not a valid position in the Queue!");
                        System.out.println("What position to insert in?");
                        position = read.nextInt();
                    }

                    //Insert at position and print queue
                    q.insert(num, position);
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
            }
            //Peek at any position
            else if (choice.equals(six)) {
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {
                    int position;
                    System.out.println("What position to get from the Queue?");
                    position = read.nextInt();

                    //Check valid positioning
                    while ((position < 0) || (position > q.size())) {
                        System.out.println("Not a valid position in the Queue!");
                        System.out.println("What position to insert in?");
                        position = read.nextInt();
                    }

                    //Peek at position, print it and queue
                    Object num = q.get(position);
                    System.out.println(num + " is at position " + position + " in the queue");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }


            }
            //Remove any position
            else if (choice.equals(seven)){
                //Find size of queue
                int s = q.size();
                if (s == 0) {
                    System.out.println("Queue is empty!");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
                else {
                    int position;
                    String num;
                    System.out.println("What position to remove from the Queue?");
                    position = read.nextInt();

                    //Check valid positioning
                    while ((position < 0) || (position > q.size() - 1)) {
                        System.out.println("Not a valid position in the Queue!");
                        System.out.println("What position to remove from?");
                        position = read.nextInt();
                    }

                    num = (String) q.remove(position);
                    System.out.println(num + " was at position " + position + " in the queue");
                    System.out.println("Queue is: ");
                    System.out.println(q.toString());
                }
            }

            System.out.println("Select an option: ");
            System.out.println("1. Add to the queue");
            System.out.println("2. Get the next string from the queue");
            System.out.println("3. Peek at the first value in the queue");
            System.out.println("4. Peek at the last value in the queue");
            System.out.println("5. Insert into a position in the queue");
            System.out.println("6. Peek at a value in any position in the queue");
            System.out.println("7. Remove a value from any position in the queue and return it");
            System.out.println("8. Exit");

            choice = read.next();
        }
    }
}