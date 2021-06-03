package cpsc2150.extendedTicTacToe;

/**
 * Created by kplis on 4/5/2018.
 */
public class GameSetupController {
    private GameSetupScreen view;
    private int max_size = 20;
    private final int MEM_CUTOFF = 64;
    private IGameBoard Game;


    public GameSetupController(GameSetupScreen v)
    {
        view = v;
    }

    public void processButtonClick(int rows, int cols, int players, int numWin )
    {
        String errorMsg = "";
        if(rows < Game.minRows || rows > max_size)
        {
            errorMsg += "Rows must be between " +  Game.minRows + " and " + max_size;
        }

        if(cols < Game.minCols || cols > max_size)
        {
            errorMsg += "Columns must be between " +  Game.minCols + " and " + max_size;
        }

        if (numWin > rows)
        {
            errorMsg += "Can't have more to win than the number of rows";
        }
        if (numWin > rows)
         {
            errorMsg += "Can't have more to win than the number of Columns";
         }

        if(numWin < Game.minWin)
        {
            errorMsg += "Number to win must be at least " + Game.minWin;
        }

        if(!errorMsg.equals(""))
        {
            view.displayError(errorMsg);

        }
        else
        {
            view.closeScreen();
            IGameBoard model;
            if(rows * cols <= MEM_CUTOFF) {
                model = new GameBoard(rows, cols, numWin);
            }
            else
            {
                model = new GameBoardMem(rows, cols, numWin);
            }
            TicTacToeView tview = new TicTacToeView(rows, cols);
            TicTacToeController tcontroller = new TicTacToeController(model, tview, players);

            tview.registerObserver(tcontroller);
        }
    }
}
