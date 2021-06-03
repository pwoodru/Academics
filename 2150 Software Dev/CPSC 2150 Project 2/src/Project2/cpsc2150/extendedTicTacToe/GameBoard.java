package cpsc2150.extendedTicTacToe;

public class GameBoard {
    private int ROWS = 8;
    private int COLUMN = 8;
    private int NUMWIN = 5;
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
    }

    /**
     * @param pos of token in board
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post true if available, false if not
     * @return true if space is available, false if not
     */
    public boolean checkSpace(BoardPosition pos) {
    //returns true if the position specified in pos is available, false otherwise. If a space is not in bounds, then it is not available
        char P1 = 'X';
        char P2 = 'O';


        if (pos.getColumn() < 0 || pos.getColumn() > 7 || pos.getRow() < 0 || pos.getRow() > 7) {
            System.out.println("That space is unavailable, please pick again");
            return false;
        }
        else if (isPlayerAtPos(pos, P1)) {
            System.out.println("That space is unavailable, please pick again");
            return false;
        }
        else if (isPlayerAtPos(pos, P2)) {
            System.out.println("That space is unavailable, please pick again");
            return false;
        }
        else {
            return true;
        }
    }

    /**
     * @param marker position on board to be marked
     * @param player the current turn's player
     * @pre marker >= 0 and marker <= ROWS and marker <= COLUMN
     * @post places marker if available, does not place marker if space is taken
     */
    public void placeMarker(BoardPosition marker, char player) {
    //places the character in player on the position specified by marker, and should not be called if the space is not available.

        if (checkSpace(marker)) {
            board[marker.getRow()][marker.getColumn()] = player;
        }

    }

    /**
     * @param lastPos last token placed
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
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

    /**
     * @pre ROWS >= 0 and ROWS <= 8 and COLUMN >= 0 and COLUMN <= 8
     * @post true if game is tied, false if not
     * @return true if game is tied, false if not
     */
    public boolean checkForDraw() {
    //this function will check to see if the game has resulted in a
    //tie. A game is tied if there are no free board positions remaining
    //You do not need to check for any potential wins, because we can assume
    //that the players were checking for win conditions as they played the
    //game. It will return true if the game is tied, and false otherwise.

        //Check every row and every column
        //If the loops find an open spot on the board, the game is not tied and returns false
        //Otherwise the board is full and returns true
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMN; j++) {
                if ((board[i][j] != 'X') && (board[i][j] != 'O')) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    public boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row horizontally.
        //Returns true if it does, otherwise false
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMN - (NUMWIN - 1); j++) {
                int count = 0;
                //checking row
                for (int k = 0; k < NUMWIN; k++) {
                    lastPos = new BoardPosition(i, j + k);
                    if ((whatsAtPos(lastPos) == player) && (whatsAtPos(lastPos) != ' ')) {
                        count++;
                    }
                }
                if (count == NUMWIN) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    public boolean checkVerticalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row vertically.
        //Returns true if it does, otherwise false
        for (int i = 0; i < ROWS - (NUMWIN - 1); i++) {
            for (int j = 0; j < COLUMN; j++) {
                int count = 0;
                //checking column
                for (int k = 0; k < NUMWIN; k++) {
                    lastPos = new BoardPosition(i + k, j);
                    if ((whatsAtPos(lastPos) == player) && (whatsAtPos(lastPos) != ' ')) {
                        count++;
                    }
                }
                if (count == NUMWIN) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    public boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row diagonally.
        //Returns true if it does, otherwise false
        //Note: there are two diagonals to check

        //Check forward diagonal
        for (int i = (NUMWIN - 1); i < ROWS; i++) {
            for (int j = 0; j < COLUMN - (NUMWIN - 1); j++) {
                int count = 0;
                for (int k = 0; k < NUMWIN; k++) {
                    lastPos = new BoardPosition(i - k, j + k);
                    if (whatsAtPos(lastPos) == player && whatsAtPos(lastPos) != ' ') {
                        count++;
                    }
                }
                if (count == NUMWIN) {
                    return true;
                }
            }
        }
        //Check reverse diagonal
        for (int i = (NUMWIN - 1); i < ROWS; i++) {
            for (int j = (NUMWIN - 1); j < COLUMN; j++) {
                int count = 0;
                //to check specific column
                for (int k = 0; k < NUMWIN; k++) {
                    lastPos = new BoardPosition(i - k, j - k);
                    if (whatsAtPos(lastPos) == player && whatsAtPos(lastPos) != ' ') {
                        count++;
                    }
                }
                if (count == NUMWIN) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param pos current board position
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post returns character at current board position, if no marker returns blank ' '
     * @return character at current board position, if no marker returns ' '
     */
    public char whatsAtPos(BoardPosition pos) {
    //returns what is in the GameBoard at position pos
    //If no marker is there it returns a blank space char ‘ ‘

        if (!isPlayerAtPos(pos, 'X') && !isPlayerAtPos(pos, 'O')) {
            return ' ';
        }
        else {
            return board[pos.getRow()][pos.getColumn()];
        }
    }

    /**
     * @param pos current board position
     * @param player the current turn's player
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post true if player is at current position, false otherwise
     * @return true if player is at current position, false otherwise
     */
    public boolean isPlayerAtPos(BoardPosition pos, char player) {
    //returns true if the player is at pos, otherwise it returns false
    //Note: this method will be implemented very similarly to
    //whatsAtPos, but it’s asking a different question. We only know they
    //will be similar because we know GameBoard will contain a 2D array. If
    //the data structure were to change in the future these two methods
    //could end up being radically different.

        if (board[pos.getRow()][pos.getColumn()] == player) {
            return true;
        }
        else {
            return false;
        }
    }

    @Override
    public String toString() {
        final int max = 9;
        //overrides toString function to get formatted printing for board
        String stringData = "   ";

        for(int i = 0; i < ROWS; i++){
            if(i <= max) {
                stringData = stringData + " " + i + "|";
            }
            else{
                stringData = stringData + "" + i + "|";
            }
        }

        for (int i = 0; i <= ROWS - 1; i++) {
            String format = String.format("%2d", i);
            stringData = stringData + "\n" + format;
            for(int j = 0; j < COLUMN; j++) {
                BoardPosition position = new BoardPosition(i, j);
                stringData = stringData + "|" + whatsAtPos(position) + " ";
            }

            stringData = stringData + "|";
        }
        return stringData;
    }
}
