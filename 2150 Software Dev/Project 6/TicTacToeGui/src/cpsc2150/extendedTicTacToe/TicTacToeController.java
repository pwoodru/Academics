package cpsc2150.extendedTicTacToe;

/**
 * The TicTacToe controller class will handle communication between our TicTacToeView and our Model (IGameBoard and BoardPosition)
 *
 * This is where you will write code
 *
 * You will need to include your BoardPosition class, the IGameBoard interface
 * and the implementations from previous homeworks
 * If your code was correct you will not need to make any changes to your IGameBoard classes
 */
public class TicTacToeController{
    //our current game that is being played
    private IGameBoard curGame;

    //The screen that provides our view
    private TicTacToeView screen;

    //All private data fields necessary for program to function
    private static final int ZERO = 0;
    private static final int ONE = 1;
    public static final int MAX_PLAYERS = 10;
    private int count = 0;
    private int whichPlayer = 0;
    private final char[] characters = { 'X', 'O', 'A', 'S', 'W', '#', '@', 'M', 'G', 'H' };
    private boolean end = false;
    private int numPlayers;
    private int numWin;
    private boolean full = false;

    /**
     *
     * @param model the board implementation
     * @param view the screen that is shown
     * @param np The number of players for the game
     * @post the controller will respond to actions on the view using the model.
     */
    TicTacToeController(IGameBoard model, TicTacToeView view, int np){
        this.curGame = model;
        this.screen = view;
        this.numPlayers = np;

    }

    /**
     *
     * @param row the row of the activated button
     * @param col the column of the activated button
     * @pre row and col are in the bounds of the game represented by the view
     * @post The button pressed will show the right token and check if a player has won.
     */
    public void processButtonClick(int row, int col) {

        //Create new BoardPosition
        BoardPosition pos = new BoardPosition(row, col);

        //If there are no issues, the current player goes.
        if(count == ZERO && !full && !end) {
            screen.setMessage("It is " + characters[whichPlayer] + "'s turn");
            count++;
        }
        //This portion of the if statement only runs if a player chose an occupied space.
        //Throws an error message and requires the same player to pick
        else if (count == ZERO && full && !end) {
            count++;
        }

        //Checks for a win or a draw and creates a new game if true
        //Runs when player hits button to start another game and board has not been wiped
        if (curGame.checkForDraw() || curGame.checkForWinner(pos) || end){
            newGame();
        }

        //After a potentially new game is created
        //Sets the num to win for the current game
        numWin = curGame.getNumToWin();

        //Checking the selected space
        //If space is open, places marker for that player
        if (curGame.checkSpace(pos) && !end) {
            curGame.placeMarker(pos, characters[whichPlayer]);
            screen.setMarker(row, col, characters[whichPlayer]);
            full = false;
        }
        //If space is full, sets boolean value to true which skips the turn rotation
        //Causes program to show error message and ask the player to pick again
        else {
            screen.setMessage("Space is taken. Player " + characters[whichPlayer] + " pick again.");
            full = true;
            count = 0;
        }

        //Checking for a horizontal win
        if (curGame.checkHorizontalWin(pos, characters[whichPlayer])) {
            screen.setMessage("Player " + characters[whichPlayer] + " won by " + numWin + " in a row Horizontally!" + "\n" +
                    "Press any button to start a new game.");
            end = true;
            full = false;
        }

        //Checking for a vertical win
        else if (curGame.checkVerticalWin(pos, characters[whichPlayer])) {
            screen.setMessage("Player " + characters[whichPlayer] + " won by " + numWin + " in a row Vertically!" + "\n" +
                    "Press any button to start a new game.");
            end = true;
            full = false;
        }

        //Checking for a diagonal win
        else if (curGame.checkDiagonalWin(pos, characters[whichPlayer])) {
            screen.setMessage("Player " + characters[whichPlayer] + " won by " + numWin + " in a row Diagonally!" + "\n" +
                    "Press any button to start a new game.");
            end = true;
            full = false;
        }

        //Checking for a draw
        else if (curGame.checkForDraw()) {
            screen.setMessage("No Winner. Tie Game!" + "\n" + "Press any button to start a new game.");
            end = true;
            full = false;
        }

        //Continuing the rotation of players

        //If the number of players has not been reached, move to next player
        if (whichPlayer < numPlayers - ONE && !full) {
            whichPlayer++;
            if (count != ZERO && !end){
                screen.setMessage("It is " + characters[whichPlayer] + "'s turn");
            }
        }
        //If the number of players has been reached, return to first player
        else if (whichPlayer == numPlayers - ONE && !full){
            whichPlayer = ZERO;
            if(!end)
                screen.setMessage("It is " + characters[whichPlayer] + "'s turn");
        }

    }

    //Function to create a new game
    private void newGame()
    {
        //Gets rid of previous screen and does the setup for a new screen and controller
        screen.dispose();
        GameSetupScreen screen = new GameSetupScreen();
        GameSetupController controller = new GameSetupController(screen);
        screen.registerObserver(controller);
    }
}
