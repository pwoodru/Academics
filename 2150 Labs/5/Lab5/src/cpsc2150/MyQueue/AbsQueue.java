package cpsc2150.MyQueue;

public abstract class AbsQueue implements IQueue {

    @Override
    public String toString() {
        String stringData = "";
        for (int i = 0; i < size(); i++) {
            int temp = pop();
            stringData = stringData + temp + ", ";
            add(temp);
        }
        return stringData;
    }
}
