package cpsc2150.MyQueue;

public abstract class AbsQueue<T> implements IQueue<T> {

    @Override
    public String toString() {
        String stringData = "";
        for (int i = 0; i < size(); i++) {
            T temp = pop();
            stringData = stringData + temp + ", ";
            add(temp);
        }
        return stringData;
    }
}
