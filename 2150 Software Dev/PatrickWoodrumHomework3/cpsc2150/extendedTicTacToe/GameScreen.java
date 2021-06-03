package cpsc2150.extendedTicTacToe;

import java.util.Scanner;

public class GameScreen {
    public static void main(String [] args) {

        //Create all variables needed in the program
        final int minRows = 3;
        final int maxRows = 100;
        final int minColumns = 3;
        final int maxColumns = 100;
        final int minWin = 3;
        final int maxWin = 25;
        final int choiceONE = 1;
        final int choiceTWO = 2;
        int rowNum, columnNum, winRows;
        boolean play = true;
        boolean win = false;
        boolean draw = false;
        char player1 = 'X';
        char player2 = 'O';
        int rowInput, colInput, endGame;
        int playerNum = 1;
        BoardPosition pos;
        Scanner read = new Scanner(System.in);

        //While the players wish to play the game
        while (play) {

            do {
                System.out.println("How many rows?");
                rowNum = read.nextInt();

                if (rowNum < minRows) {
                    System.out.println("Must have at least 3 rows.");
                }
                else if (rowNum > maxRows) {
                    System.out.println("Can have at most 100 rows.");
                }
            }while(rowNum < minRows || rowNum > maxRows);

            do {
                System.out.println("How many columns?");
                columnNum = read.nextInt();

                if (columnNum < minColumns) {
                    System.out.println("Must have at least 3 columns.");
                }
                else if (columnNum > maxColumns){
                    System.out.println("Can have at most 100 columns.");
                }
            }while(columnNum < minColumns || columnNum > maxColumns);

            do {
                System.out.println("How many in a row to win?");
                winRows = read.nextInt();

                if (winRows < minWin) {
                    System.out.println("Must have at least 3 in a row to win.");
                }
                else if (winRows > maxWin) {
                    System.out.println("Can have at most 25 in a row to win.");
                }
            } while(winRows < minWin || winRows > maxWin);

            //Create new gameboard on each new game
            GameBoard board = new GameBoard(rowNum, columnNum, winRows);
            System.out.println(board.toString());
            win = false;
            draw = false;

            //While there is neither a win nor a draw, continue with the game
            while (!win && !draw) {
                //If it is player 1's turn (X)
                if (playerNum == choiceONE) {
                    //User input for row and column
                    System.out.println("Player X please enter your ROW");
                    rowInput = read.nextInt();
                    System.out.println("Player X please enter your COLUMN");
                    colInput = read.nextInt();

                        if (rowInput > rowNum - 1 || rowInput < 0) {
                            while (rowInput > rowNum - 1 || rowInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player X please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player X please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }
                        if (colInput > columnNum - 1 || colInput < 0) {
                            while (colInput > columnNum - 1 || colInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player X please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player X please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }

                    pos = new BoardPosition(rowInput, colInput);

                    //Check the position on the board that the user wishes to place at
                    while (!board.checkSpace(pos)) {
                        System.out.println("Player X please enter your ROW");
                        rowInput = read.nextInt();
                        System.out.println("Player X please enter your COLUMN");
                        colInput = read.nextInt();

                        if (rowInput > rowNum - 1 || rowInput < 0) {
                            while (rowInput > rowNum - 1 || rowInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player X please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player X please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }
                        if (colInput > columnNum - 1 || colInput < 0) {
                            while (colInput > columnNum - 1 || colInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player X please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player X please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }

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
                else if (playerNum == choiceTWO) {
                    //User input for row and column
                    System.out.println("Player O please enter your ROW");
                    rowInput = read.nextInt();
                    System.out.println("Player O please enter your COLUMN");
                    colInput = read.nextInt();

                    if (rowInput > rowNum - 1 || rowInput < 0) {
                        while (rowInput > rowNum - 1 || rowInput < 0) {
                            System.out.println("That space is unavailable, please pick again");
                            //User input for row and column
                            System.out.println("Player O please enter your ROW");
                            rowInput = read.nextInt();
                            System.out.println("Player O please enter your COLUMN");
                            colInput = read.nextInt();
                        }
                    }
                    if (colInput > columnNum - 1 || colInput < 0) {
                        while (colInput > columnNum - 1 || colInput < 0) {
                            System.out.println("That space is unavailable, please pick again");
                            //User input for row and column
                            System.out.println("Player O please enter your ROW");
                            rowInput = read.nextInt();
                            System.out.println("Player O please enter your COLUMN");
                            colInput = read.nextInt();
                        }
                    }

                    pos = new BoardPosition(rowInput, colInput);

                    //Check the position on the board that the user wishes to place at
                    while (!board.checkSpace(pos)) {
                        System.out.println("Player O please enter your ROW");
                        rowInput = read.nextInt();
                        System.out.println("Player O please enter your COLUMN");
                        colInput = read.nextInt();

                        if (rowInput > rowNum - 1 || rowInput < 0) {
                            while (rowInput > rowNum - 1 || rowInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player O please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player O please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }
                        if (colInput > columnNum - 1 || colInput < 0) {
                            while (colInput > columnNum - 1 || colInput < 0) {
                                System.out.println("That space is unavailable, please pick again");
                                //User input for row and column
                                System.out.println("Player O please enter your ROW");
                                rowInput = read.nextInt();
                                System.out.println("Player O please enter your COLUMN");
                                colInput = read.nextInt();
                            }
                        }

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
            if (endGame < choiceONE || endGame > choiceTWO) {
                while (endGame < choiceONE || endGame > choiceTWO) {
                    System.out.println("Invalid input, please try again.");
                    System.out.println("Would you like to play again?");
                    System.out.println("Enter 1 to play again");
                    System.out.println("Enter 2 to exit the game");
                    endGame = read.nextInt();
                }
            }

            if (endGame == choiceONE) {
                play = true;
            }
            else if (endGame == choiceTWO) {
                play = false;
            }
        }
    }
}
