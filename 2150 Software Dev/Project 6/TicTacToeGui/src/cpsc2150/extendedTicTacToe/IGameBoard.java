package cpsc2150.extendedTicTacToe;


public interface IGameBoard {

    //Public static final variables for use throughout
    public static final int minRows = 3;
    public static final int maxRows = 25;
    public static final int minCols = 3;
    public static final int maxCols = 25;
    public static final int minWin = 3;
    public static final int maxWin = 25;

     /**
     * @param pos of token in board
     * @pre pos >= zero and pos <= row input and pos <= col input
     * @post true if available, false if not
     * @return true if space is available, false if not
     */
    default boolean checkSpace(BoardPosition pos) {
        //returns true if the position specified in pos is available, false otherwise. If a space is not in bounds, then it is not available
        if (whatsAtPos(pos) == ' ') {
            return true;
        }
        else {
            return false;
        }
    }

    /**
     * @param marker position on board to be marked
     * @param player the current turn's player
     * @pre marker >= zero and marker <= row input and marker <= col input
     * @post places marker if available, does not place marker if space is taken
     */
    void placeMarker(BoardPosition marker, char player);

    /**
     * @param lastPos last token placed
     * @pre lastPos >= zero and lastPos <= row input and lastPos <= col input
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    default boolean checkForWinner(BoardPosition lastPos) {
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
     * @pre row input >= zero and row input <= eight and col input >= zero and col input <= eight
     * @post true if game is tied, false if not
     * @return true if game is tied, false if not
     */
    default boolean checkForDraw() {
        //this function will check to see if the game has resulted in a
        //tie. A game is tied if there are no free board positions remaining
        //You do not need to check for any potential wins, because we can assume
        //that the players were checking for win conditions as they played the
        //game. It will return true if the game is tied, and false otherwise.

        //Check every row and every column
        //If the loops find an open spot on the board, the game is not tied and returns false
        //Otherwise the board is full and returns true
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                BoardPosition pos = new BoardPosition(i, j);
                if (whatsAtPos(pos) == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= zero and lastPos <= row input and lastPos <= col input
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    default boolean checkHorizontalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row horizontally.
        //Returns true if it does, otherwise false
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns() - (getNumToWin() - 1); j++) {
                int count = 0;
                //checking row
                for (int k = 0; k < getNumToWin(); k++) {
                    lastPos = new BoardPosition(i, j + k);
                    if ((whatsAtPos(lastPos) == player) && (whatsAtPos(lastPos) != ' ')) {
                        count++;
                    }
                }
                if (count == getNumToWin()) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= zero and lastPos <= row input and lastPos <= col input
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    default boolean checkVerticalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row vertically.
        //Returns true if it does, otherwise false
        for (int i = 0; i < getNumRows() - (getNumToWin() - 1); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                int count = 0;
                //checking column
                for (int k = 0; k < getNumToWin(); k++) {
                    lastPos = new BoardPosition(i + k, j);
                    if ((whatsAtPos(lastPos) == player) && (whatsAtPos(lastPos) != ' ')) {
                        count++;
                    }
                }
                if (count == getNumToWin()) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param lastPos last token placed
     * @param player the current turn's player
     * @pre lastPos >= zero and lastPos <= row input and lastPos <= col input
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    default boolean checkDiagonalWin(BoardPosition lastPos, char player) {
        //checks to see if the last marker placed resulted in 5 in a row diagonally.
        //Returns true if it does, otherwise false
        //Note: there are two diagonals to check

        //Check forward diagonal
        for (int i = (getNumToWin() - 1); i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns() - (getNumToWin() - 1); j++) {
                int count = 0;
                for (int k = 0; k < getNumToWin(); k++) {
                    lastPos = new BoardPosition(i - k, j + k);
                    if (whatsAtPos(lastPos) == player && whatsAtPos(lastPos) != ' ') {
                        count++;
                    }
                }
                if (count == getNumToWin()) {
                    return true;
                }
            }
        }
        //Check reverse diagonal
        for (int i = (getNumToWin() - 1); i < getNumRows(); i++) {
            for (int j = (getNumToWin() - 1); j < getNumColumns(); j++) {
                int count = 0;
                //to check specific column
                for (int k = 0; k < getNumToWin(); k++) {
                    lastPos = new BoardPosition(i - k, j - k);
                    if (whatsAtPos(lastPos) == player && whatsAtPos(lastPos) != ' ') {
                        count++;
                    }
                }
                if (count == getNumToWin()) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @param pos current board position
     * @pre pos >= zero and pos <= row input and pos <= col input
     * @post returns character at current board position, if no marker returns blank ' '
     * @return character at current board position, if no marker returns ' '
     */
    char whatsAtPos(BoardPosition pos);

    /**
     * @param pos current board position
     * @param player the current turn's player
     * @pre pos >= zero and pos <= row input and pos <= col input
     * @post true if player is at current position, false otherwise
     * @return true if player is at current position, false otherwise
     */
    default boolean isPlayerAtPos(BoardPosition pos, char player) {
        return whatsAtPos(pos) == player;
    }

    /**
     * @post returns number of rows
     * @return number of rows
     */
    int getNumRows();

    /**
     * @post returns number of columns
     * @return number of columns
     */
    int getNumColumns();

    /**
     * @post returns number required in a row to win
     * @return number required in a row to win
     */
    int getNumToWin();

}
