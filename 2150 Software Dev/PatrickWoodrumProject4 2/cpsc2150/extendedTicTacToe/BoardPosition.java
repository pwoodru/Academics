package cpsc2150.extendedTicTacToe;

public class BoardPosition {
    private int ROW;
    private int COLUMN;

    /**
     *
     * @invariants ROW = rows
     * COLUMN = cols
     * numWin = win
     * board = board[ROW][COLUMN]
     */
    public BoardPosition(int row, int column) {
        //makes a board for the game, sets rows and columns
        ROW = row;
        COLUMN = column;
    }

    /**
     * @pre WIDTH >= 0 or WIDTH <= 8
     * @post WIDTH = rows
     * @return WIDTH as rows
     */
    public int getRow() {
        //returns the row
        return ROW;
    }

    /**
     * @pre HEIGHT >= 0 or HEIGHT <= 8
     * @post HEIGHT = rows
     * @return HEIGHT as columns
     */
    public int getColumn() {
        //returns the column
        return COLUMN;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof BoardPosition)) {
            return false;
        }

        BoardPosition x = (BoardPosition) o;

        if ((this.ROW == x.ROW) && (this.COLUMN == x.COLUMN)) {
            return true;
        }

        return false;
    }

}
