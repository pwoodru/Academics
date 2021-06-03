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

    public boolean checkSpace(BoardPosition pos) {
        //returns true if the position specified in pos is available, false otherwise. If a space is not in bounds, then it is not available
        if (whatsAtPos(pos) == ' ') {
            return true;
        }
        else {
            System.out.println("That space is unavailable, please pick again");
            return false;
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

    public boolean checkForWinner(BoardPosition lastPos){
    //this function will check to see if the lastPos placed resulted in a winner. If so it will return true, otherwise false.
    //Passing in the last position will help limit the possible places to check for a win condition, since you can assume that any win condition that did not include the most recent play made would have been caught earlier.
    //You may call other methods to complete this method

        //Find the character of last marker placed for use in future method calls
        //also making sure it's checking for correct winner
        char playerChar = whatsAtPos(lastPos);

        //Call each method of winning
        //Return true if a method comes back true
        //Return false if no methods are true
        if (checkHorizontalWin(lastPos, playerChar)) {
            return true;
        }
        else if (checkVerticalWin(lastPos, playerChar)) {
            return true;
        }
        else if (checkDiagonalWin(lastPos, playerChar)) {
            return true;
        }
        else {
            return false;
        }

    }

    public boolean isPlayerAtPos(BoardPosition pos, char player) {
        //returns true if the player is at pos, otherwise it returns false
        //Note: this method will be implemented very similarly to
        //whatsAtPos, but it’s asking a different question. We only know they
        // will be similar because we know GameBoard will contain a 2D array. If
        //the data structure were to change in the future these two methods
        //could end up being radically different.

        return board[pos.getRow()][pos.getColumn()] == player;
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

