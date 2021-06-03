import cpsc2150.extendedTicTacToe.BoardPosition;
import cpsc2150.extendedTicTacToe.GameBoard;
import cpsc2150.extendedTicTacToe.IGameBoard;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestGameBoard {

    //Factory Method for Constructor Call
    private IGameBoard MakeTestBoard(int row, int col, int numWin){
        return new GameBoard(row, col, numWin);
    }

    //Helper function for creating a blank 2D array for comparisons
    private char[][] Make2DArray (int row, int col) {
        char[][] newA = new char[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                newA[i][j] = ' ';
            }
        }
        return newA;
    }


    private String toStringTemp(char board[][]) {
        final int MaxCol = 9;
        //overrides toString function to get formatted printing for board
        String stringData = "   ";

        for(int i = 0; i < board[0].length; i++){
            if(i <= MaxCol) {
                stringData = stringData + " " + i + "|";
            }
            else{
                stringData = stringData + "" + i + "|";
            }
        }

        for(int i = 0; i <= board[0].length - 1; i++){
            String format = String.format("%2d", i);
            stringData = stringData + "\n" + format;
            for(int j = 0; j < board[0].length; j++) {
                stringData = stringData + "|" + board[i][j] + " ";
            }

            stringData = stringData + "|";
        }
        return stringData;
    }

    //CONSTRUCTOR TESTS

    @Test
    //test amount of rows created
    public void constructor_rows(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        int testRows = 3;
        String expected = toStringTemp(expBoard);
        assertEquals(testRows, board.getNumRows());
        assertEquals(expected, board.toString());
    }

    @Test
    //test amount of columns created
    public void constructor_cols(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        int testCols = 3;
        String expected = toStringTemp(expBoard);
        assertEquals(testCols, board.getNumColumns());
        assertEquals(expected, board.toString());
    }

    @Test
    //test numWin created for the board
    public void constructor_numWin(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        int testNumWin = 3;
        assertEquals(testNumWin, board.getNumToWin());
    }

    //CHECKSPACE TESTS

    @Test
    //Tests if the column is filled after placing markers
    public void checkSpace_colFilled(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(1, 0);
        BoardPosition marker3 = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'O');
        expBoard[1][0] = 'O';
        board.placeMarker(marker3, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertFalse(board.checkSpace(marker3));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for empty space when nothing is inserted
    public void checkSpace_empty(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkSpace(marker));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for open space at the last value in the board
    public void checkSpace_tokenAtEnd(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertFalse(board.checkSpace(marker));
        assertEquals(expected, board.toString());
    }

    //CHECK HORIZONTAL WIN TESTS

    @Test
    //Tests for checkHorizontalWin in center of board (3 in a row)
    public void checkHorizontalWin_ThreePiece(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        BoardPosition marker2 = new BoardPosition(2, 1);
        BoardPosition marker3 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkHorizontalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Test horizontal win on first row
    public void checkHorizontalWin_FirstRow(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(0, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkHorizontalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Test horizontal win on last row in middle of board
    public void checkHorizontalWin_LastRow() {

        char[][] expBoard = Make2DArray(5, 5);
        IGameBoard board = MakeTestBoard(5, 5, 3);
        BoardPosition marker = new BoardPosition(4, 1);
        BoardPosition marker2 = new BoardPosition(4, 2);
        BoardPosition marker3 = new BoardPosition(4, 3);
        board.placeMarker(marker, 'X');
        expBoard[4][1] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[4][2] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[4][3] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkHorizontalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests horizontal win on last row in the bottom left
    public void checkHorizontalWin_BottomLeft() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        BoardPosition marker2 = new BoardPosition(2, 1);
        BoardPosition marker3 = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkHorizontalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    //CHECK VERTICAL WIN TESTS

    @Test
    //Tests for vertical win in center of 3-wide board
    public void checkVerticalWin_ThreePiece(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 1);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(2, 1);
        board.placeMarker(marker, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkVerticalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for vertical win left-most column at top left
    public void checkVerticalWin_FirstColumn(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        BoardPosition marker2 = new BoardPosition(1, 0);
        BoardPosition marker3 = new BoardPosition(0, 0);
        board.placeMarker(marker, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkVerticalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests far right vertical win
    public void checkVerticalWin_LastColumn() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        BoardPosition marker2 = new BoardPosition(1, 2);
        BoardPosition marker3 = new BoardPosition(0, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][2] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkVerticalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for vertical win in left-most column at bottom left
    public void checkVerticalWin_FirstColumnBottomLeft() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(1, 0);
        BoardPosition marker3 = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkVerticalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    //CHECK DIAGONAL WIN TESTS

    @Test
    //tests diagonal win ascending
    public void checkDiagonalWin_Forward(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //tests diagonal win Descending
    public void checkDiagonalWin_Backward(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 2);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //tests boundary case of 0, 0 as Diagonal Win Case
    public void checkDiagonalWin_TopLeftForward(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(0, 0);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //tests boundary case of 0, 2 as Diagonal Win Case
    public void checkDiagonalWin_TopRightBackward() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //tests boundary case of 2, 0 as Diagonal Win Case
    public void checkDiagonalWin_BottomLeftBackward() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 2);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //tests boundary case of 2, 2 as Diagonal Win Case
    public void checkDiagonalWin_BottomRightForward() {

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(1, 1);
        BoardPosition marker3 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkDiagonalWin(marker3, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Last test when diagonal win is not true
    public void checkDiagonalWin_NumWinOneLess(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(1, 1);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[1][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertFalse(board.checkDiagonalWin(marker2, 'X'));
        assertEquals(expected, board.toString());
    }

    //CHECK DRAW TESTS

    @Test
    //Tests for draw in bottom right of board
    public void checkDraw_BoundaryBottomRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(0, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        BoardPosition marker4 = new BoardPosition(1, 0);
        BoardPosition marker5 = new BoardPosition(1, 1);
        BoardPosition marker6 = new BoardPosition(1, 2);
        BoardPosition marker7 = new BoardPosition(2, 0);
        BoardPosition marker8 = new BoardPosition(2, 1);
        BoardPosition marker9 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker4, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker5, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker6, 'X');
        expBoard[1][2] = 'X';
        board.placeMarker(marker7, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker8, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker9, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkForDraw());
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for draw in top left of board
    public void checkDraw_BoundaryTopLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(0, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        BoardPosition marker4 = new BoardPosition(1, 0);
        BoardPosition marker5 = new BoardPosition(1, 1);
        BoardPosition marker6 = new BoardPosition(1, 2);
        BoardPosition marker7 = new BoardPosition(2, 0);
        BoardPosition marker8 = new BoardPosition(2, 1);
        BoardPosition marker9 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker4, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker5, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker6, 'X');
        expBoard[1][2] = 'X';
        board.placeMarker(marker7, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker8, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker9, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkForDraw());
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for draw in top right of board
    public void checkDraw_BoundaryTopRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(0, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        BoardPosition marker4 = new BoardPosition(1, 0);
        BoardPosition marker5 = new BoardPosition(1, 1);
        BoardPosition marker6 = new BoardPosition(1, 2);
        BoardPosition marker7 = new BoardPosition(2, 0);
        BoardPosition marker8 = new BoardPosition(2, 1);
        BoardPosition marker9 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker4, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker5, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker6, 'X');
        expBoard[1][2] = 'X';
        board.placeMarker(marker7, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker8, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker9, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkForDraw());
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests for draw in bottom left of board
    public void checkDraw_BoundaryBottomLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        BoardPosition marker2 = new BoardPosition(0, 1);
        BoardPosition marker3 = new BoardPosition(0, 2);
        BoardPosition marker4 = new BoardPosition(1, 0);
        BoardPosition marker5 = new BoardPosition(1, 1);
        BoardPosition marker6 = new BoardPosition(1, 2);
        BoardPosition marker7 = new BoardPosition(2, 0);
        BoardPosition marker8 = new BoardPosition(2, 1);
        BoardPosition marker9 = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        board.placeMarker(marker2, 'X');
        expBoard[0][1] = 'X';
        board.placeMarker(marker3, 'X');
        expBoard[0][2] = 'X';
        board.placeMarker(marker4, 'X');
        expBoard[1][0] = 'X';
        board.placeMarker(marker5, 'X');
        expBoard[1][1] = 'X';
        board.placeMarker(marker6, 'X');
        expBoard[1][2] = 'X';
        board.placeMarker(marker7, 'X');
        expBoard[2][0] = 'X';
        board.placeMarker(marker8, 'X');
        expBoard[2][1] = 'X';
        board.placeMarker(marker9, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.checkForDraw());
        assertEquals(expected, board.toString());
    }

    //CHECK WHATSATPOS TESTS

    @Test
    //Tests whatsAtPos at (1,1)
    public void whatsAtPos_atPos(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(1, 1);
        board.placeMarker(marker, 'X');
        expBoard[1][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertEquals('X', board.whatsAtPos(marker));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests whatsAtPos at (1,1) if token is not equal to test token
    public void whatsAtPos_wrongTokenAtPos(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(1, 1);
        board.placeMarker(marker, 'X');
        expBoard[1][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertFalse(board.whatsAtPos(marker) == '0');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests whatsAtPos at Top Left
    public void whatsAtPos_TopLeftPos(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests whatsAtPos at Top Right
    public void whatsAtPos_BoundaryCaseTopRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests whatsAtPos at Bottom Left
    public void whatsAtPos_BoundaryCaseBottomLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    //CHECK ISPLAYERATPOS TESTS

    @Test
    //Tests whatsAtPos at (1,1)
    public void isPlayerAtPos_TopLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.isPlayerAtPos(marker, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests isPlayerAtPos at bottom right
    public void isPlayerAtPos_BottomRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.isPlayerAtPos(marker, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests isPlayerAtPos at Center
    public void isPlayerAtPos_Center(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(1, 1);
        board.placeMarker(marker, 'X');
        expBoard[1][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.isPlayerAtPos(marker, 'X'));
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests isPlayerAtPos at Center with no token there
    public void isPlayerAtPos_CenterFalse(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(1, 1);
        String expected = toStringTemp(expBoard);
        assertEquals(board.isPlayerAtPos(marker, 'X'), false);
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests isPlayerAtPos with wrong token input
    public void isPlayerAtPos_WrongTokenCenter(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        board.placeMarker(marker, 'O');
        expBoard[2][0] = 'O';
        String expected = toStringTemp(expBoard);
        assertFalse(board.isPlayerAtPos(marker, 'X'));
        assertEquals(expected, board.toString());
    }

    //CHECK PLACEMARKER TESTS

    @Test
    //Tests placeMarker works at correct position
    public void placeMarker_AtPos(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(1, 1);
        board.placeMarker(marker, 'X');
        expBoard[1][1] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests placeMarker works at top left
    public void placeMarker_TopLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 0);
        board.placeMarker(marker, 'X');
        expBoard[0][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests placeMarker works at top right
    public void placeMarker_TopRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(0, 2);
        board.placeMarker(marker, 'X');
        expBoard[0][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests placeMarker works at bottom left
    public void placeMarker_BottomLeft(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 0);
        board.placeMarker(marker, 'X');
        expBoard[2][0] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }

    @Test
    //Tests placeMarker works at bottom right
    public void placeMarker_BottomRight(){

        char[][] expBoard = Make2DArray(3, 3);
        IGameBoard board = MakeTestBoard(3, 3, 3);
        BoardPosition marker = new BoardPosition(2, 2);
        board.placeMarker(marker, 'X');
        expBoard[2][2] = 'X';
        String expected = toStringTemp(expBoard);
        assertTrue(board.whatsAtPos(marker) == 'X');
        assertEquals(expected, board.toString());
    }
}
