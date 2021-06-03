package cpsc2150.extendedTicTacToe;

public interface IGameBoard {
     /**
     * @param pos of token in board
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post true if available, false if not
     * @return true if space is available, false if not
     */
    boolean checkSpace(BoardPosition pos);

    /**
     * @param marker position on board to be marked
     * @param player the current turn's player
     * @pre marker >= 0 and marker <= ROWS and marker <= COLUMN
     * @post places marker if available, does not place marker if space is taken
     */
    void placeMarker(BoardPosition marker, char player);

    /**
     * @param lastPos last token placed
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
     * @post true if lastPos results in winner, false if not
     * @return true if lastPos results in winner, false if not
     */
    boolean checkForWinner(BoardPosition lastPos);

    /**
     * @pre ROWS >= 0 and ROWS <= 8 and COLUMN >= 0 and COLUMN <= 8
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
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
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
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
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
     * @pre lastPos >= 0 and lastPos <= ROWS and lastPos <= COLUMN
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
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post returns character at current board position, if no marker returns blank ' '
     * @return character at current board position, if no marker returns ' '
     */
    char whatsAtPos(BoardPosition pos);

    /**
     * @param pos current board position
     * @param player the current turn's player
     * @pre pos >= 0 and pos <= ROWS and pos <= COLUMN
     * @post true if player is at current position, false otherwise
     * @return true if player is at current position, false otherwise
     */
    boolean isPlayerAtPos(BoardPosition pos, char player);

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
