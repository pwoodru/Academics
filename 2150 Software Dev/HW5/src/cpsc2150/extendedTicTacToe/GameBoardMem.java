package cpsc2150.extendedTicTacToe;

import java.util.*;

public class GameBoardMem extends AbsGameBoard implements IGameBoard {
    private int ROW, COL, WIN;
    private Map<Character, List<BoardPosition>> board;


    public GameBoardMem(int r, int c, int win) {
        ROW = r;
        COL = c;
        WIN = win;
        board = new HashMap<>();
    }

    public boolean checkSpace(BoardPosition pos) {
        if (board.containsValue(pos)) {
            return false;
        }
        else {
            return true;
        }
    }

    public void placeMarker(BoardPosition marker, char player) {
        if (board.containsKey(player)) {
            board.get(player).add(marker);
        }
        else {
            List<BoardPosition> getVal = new ArrayList<>();
            getVal.add(marker);
            board.put(player, getVal);
        }
    }


    public char whatsAtPos(BoardPosition pos) {
        Character player = ' ';

        for (Map.Entry<Character, List<BoardPosition>> m: board.entrySet()) {
            if (m.getValue().contains(pos)) {
                player = m.getKey();
            }
        }
        return player;
    }

    public int getNumRows() {
        return ROW;
    }

    public int getNumColumns () {
        return COL;
    }

    public int getNumToWin () {
        return WIN;
    }

    public boolean isPlayerAtPos(BoardPosition pos, char player) {
        //returns true if the player is at pos, otherwise it returns false
        //Note: this method will be implemented very similarly to
        //whatsAtPos, but it’s asking a different question. We only know they
        // will be similar because we know GameBoard will contain a 2D array. If
        //the data structure were to change in the future these two methods
        //could end up being radically different.

        return board.containsValue(pos) == board.containsKey(player);
    }
}