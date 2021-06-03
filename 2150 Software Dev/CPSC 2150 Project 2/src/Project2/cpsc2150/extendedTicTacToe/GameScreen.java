package cpsc2150.extendedTicTacToe;

import java.util.Scanner;

public class GameScreen {
    public static void main(String [] args) {

        //Play variable true/false updated at end
        boolean play = true;

        //While the players wish to play the game
        while (play) {

            //Create all variables needed in the program
            boolean win = false;
            boolean draw = false;
            char player1 = 'X';
            char player2 = 'O';
            int rowInput, colInput;
            int endGame;
            int playerNum = 1;
            BoardPosition pos;
            Scanner read = new Scanner(System.in);

            //Create new gameboard on each new game
            GameBoard board = new GameBoard(8,8,5);
            System.out.println(board.toString());

            //While there is neither a win nor a draw, continue with the game
            while (!win && !draw) {
                //If it is player 1's turn (X)
                if (playerNum == 1) {
                    //User input for row and column
                    System.out.println("Player X please enter your ROW");
                    rowInput = read.nextInt();
                    System.out.println("Player X please enter your COLUMN");
                    colInput = read.nextInt();
                    pos = new BoardPosition(rowInput, colInput);

                    //Check the position on the board that the user wishes to place at
                    while (!board.checkSpace(pos)) {
                        System.out.println("Player X please enter your ROW");
                        rowInput = read.nextInt();
                        System.out.println("Player X please enter your COLUMN");
                        colInput = read.nextInt();
                        pos = new BoardPosition(rowInput, colInput);
                    }

                    //When the space is available, place the marker
                    board.placeMarker(pos, player1);

                    //Update the draw true/false
                    draw = board.checkForDraw();

                    //Update the win true/false
                    win = board.checkForWinner(pos);
                    //If there is a winner on this round
                    if (board.checkForWinner(pos)) {
                        System.out.println("Player X wins!");
                    }

                    //Print the board in its current state
                    System.out.println(board.toString());

                    //Update to next player
                    playerNum++;
                }
                else if (playerNum == 2) {
                    //User input for row and column
                    System.out.println("Player O please enter your ROW");
                    rowInput = read.nextInt();
                    System.out.println("Player O please enter your COLUMN");
                    colInput = read.nextInt();
                    pos = new BoardPosition(rowInput, colInput);

                    //Check the position on the board that the user wishes to place at
                    while (!board.checkSpace(pos)) {
                        System.out.println("Player O please enter your ROW");
                        rowInput = read.nextInt();
                        System.out.println("Player O please enter your COLUMN");
                        colInput = read.nextInt();
                        pos = new BoardPosition(rowInput, colInput);
                    }

                    //When the space is available, place the marker
                    board.placeMarker(pos, player2);

                    //Update the draw true/false
                    draw = board.checkForDraw();

                    //Update the win true/false
                    win = board.checkForWinner(pos);
                    //If there is a winner on this round
                    if (board.checkForWinner(pos)) {
                        System.out.println("Player O wins!");
                    }

                    //Print the board in its current state
                    System.out.println(board.toString());

                    //Update to next player
                    playerNum--;
                }
            }

            //When the game is won or drawn, ask to play again
            System.out.println("Would you like to play again?");
            System.out.println("Enter 1 to play again");
            System.out.println("Enter 2 to exit the game");
            endGame = read.nextInt();

            //Input check
            if (endGame < 1 || endGame > 2) {
                while (endGame < 1 || endGame > 2) {
                    System.out.println("Invalid input, please try again.");
                    System.out.println("Would you like to play again?");
                    System.out.println("Enter 1 to play again");
                    System.out.println("Enter 2 to exit the game");
                    endGame = read.nextInt();
                }
            }

            if (endGame == 1) {
                play = true;
            }
            else if (endGame == 2) {
                play = false;
            }
        }
    }
}
