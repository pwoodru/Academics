package cpsc2150.listDec;

import java.util.List;
import java.util.Random;

public interface IShuffleList<T> extends List<T> {

    /**
     * @pre swaps > zero && size of list > one
     * @post randomly picks two positions in the list and swaps their values
     * @param swaps number of random swaps to perform
     */
    default void shuffle(int swaps) {

        for (int i  = 0; i < swaps; i++) {

            Random rand = new Random();
            int rand_num = rand.nextInt(size());

            Random rand2 = new Random();
            int rand_num2 = rand2.nextInt(size());

            swap(rand_num, rand_num2);
        }
    }

    /**
     * @pre i >= 0 && i < size of list && j >= 0 && j < size of list
     * @post the value in the list at i will be swapped with the value in the list at j
     * @param i list location of first swap value
     * @param j list location of second swap value
     */
    default void swap(int i, int j) {

        T temp1 = get(i);
        T temp2 = get(j);

        set(i, temp2);
        set(j, temp1);
    }


}
