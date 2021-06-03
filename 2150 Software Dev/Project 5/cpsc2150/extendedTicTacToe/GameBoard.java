package cpsc2150.extendedTicTacToe;

public class GameBoard extends AbsGameBoard implements IGameBoard {
    private int ROWS;
    private int COLUMN;
    private int NUMWIN;
    private char[][] board;

    /**
     * @invariants
     * ROWS = rows
     * COLUMN = cols
     * NUMWIN = win
     * board = board[WIDTH][HEIGHT]
     */
    public GameBoard(int rows, int cols, int win) {
        ROWS = rows;
        COLUMN = cols;
        NUMWIN = win;
        board = new char[ROWS][COLUMN];

        for (int w = 0; w < ROWS; w++) {
            for (int h = 0; h < COLUMN; h++) {
                board[w][h] = ' ';
            }
        }
    }

    public void placeMarker(BoardPosition marker, char player) {
    //places the character in player on the position specified by marker, and should not be called if the space is not available.

        if (checkSpace(marker)) {
            board[marker.getRow()][marker.getColumn()] = player;
        }

    }

    public char whatsAtPos(BoardPosition pos) {
        //returns what is in the GameBoard at position pos
        return board[pos.getRow()][pos.getColumn()];
    }

    public int getNumRows() {
        return ROWS;
    }

    public int getNumColumns() {
        return COLUMN;
    }

    public int getNumToWin() {
        return NUMWIN;
    }
}

