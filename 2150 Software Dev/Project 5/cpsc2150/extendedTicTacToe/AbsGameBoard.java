package cpsc2150.extendedTicTacToe;

abstract class AbsGameBoard implements IGameBoard {

    @Override
    public String toString() {
        final int max = 9;
        //overrides toString function to get formatted printing for board
        String stringData = "   ";

        for(int i = 0; i < getNumColumns(); i++){
            if(i <= max) {
                stringData = stringData + " " + i + "|";
            }
            else{
                stringData = stringData + "" + i + "|";
            }
        }

        for (int i = 0; i <= getNumRows() - 1; i++) {
            String format = String.format("%2d", i);
            stringData = stringData + "\n" + format;
            for(int j = 0; j < getNumColumns(); j++) {
                BoardPosition position = new BoardPosition(i, j);
                stringData = stringData + "|" + whatsAtPos(position) + " ";
            }

            stringData = stringData + "|";
        }
        return stringData;
    }


}
