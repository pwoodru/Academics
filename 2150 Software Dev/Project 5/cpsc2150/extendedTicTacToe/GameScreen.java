package cpsc2150.extendedTicTacToe;

import java.util.*;

public class GameScreen {
    public static void main(String [] args) {

        //Create all variables needed in the program
        final int maxRows = 100;
        final int maxColumns = 100;
        final int minV = 3;
        final int minWin = 3;
        final int maxWin = 25;
        int rowNum, columnNum, winRows;
        boolean play = true;
        int rowInput, colInput;
        String endGame;
        BoardPosition pos;
        Scanner read = new Scanner(System.in);
        String gameType = "";
        String playerChar;
        List<Character> user = new ArrayList();
        int playerNUM;
        final int minPlayer = 2;
        final int maxPlayer = 10;
        boolean foundWinner;

        //While the players wish to play the game
        while (play) {

            //Ask how many players and what characters they want to use
            do {
                System.out.println("How many players?");
                playerNUM = read.nextInt();

                //Min player check
                if(playerNUM < minPlayer){
                    System.out.println("Must be at least 2 players");
                }
                //Max player check
                else if(playerNUM > maxPlayer){
                    System.out.println("Must be 10 players or fewer.");
                }

            } while(playerNUM < minPlayer || playerNUM > maxPlayer);

            //Enter characters for each player
            for(int i = 0; i < playerNUM; i++) {
                System.out.print("Enter the character to represent player ");
                System.out.println(i + 1);
                playerChar = read.next();
                char temp = playerChar.charAt(0);
                temp = Character.toUpperCase(temp);
                //Check that the character is not already taken
                for (int j = 0; j < user.size(); j++) {
                    while (user.get(j) == temp) {
                        System.out.println(temp + " is already taken as a player token!");
                        System.out.print("Enter the character to represent player ");
                        System.out.println(i + 1);
                        playerChar = read.next();
                        temp = playerChar.charAt(0);
                        temp = Character.toUpperCase(temp);
                    }
                }
                user.add(temp);
            }

            //Row amount for game
            do {
                System.out.println("How many rows?");
                rowNum = read.nextInt();

                //Minimum row check
                if (rowNum < minV) {
                    System.out.println("Must have at least 3 rows.");
                }
                //Maximum row check
                else if (rowNum > maxRows) {
                    System.out.println("Can have at most 100 rows.");
                }
            }while(rowNum < minV || rowNum > maxRows);

            //Column amount for game
            do {
                System.out.println("How many columns?");
                columnNum = read.nextInt();

                //Minimum column check
                if (columnNum < minV) {
                    System.out.println("Must have at least 3 columns.");
                }
                //Maximum column check
                else if (columnNum > maxColumns){
                    System.out.println("Can have at most 100 columns.");
                }
            }while(columnNum < minV || columnNum > maxColumns);

            //Win amount check
            do {
                System.out.println("How many in a row to win?");
                winRows = read.nextInt();

                //Minimum amount to win check
                if (winRows < minWin || winRows > rowNum || winRows > columnNum) {
                    System.out.println("Must have at least 3 in a row to win.");
                }
                //Maximum amount to win check
                else if (winRows > maxWin) {
                    System.out.println("Can have at most 25 in a row to win.");
                }
            } while(winRows < minWin || winRows > maxWin);

            //Create new gameboard on each new game, asking if they want a fast or efficient game
            IGameBoard board;
            System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m)?");
            gameType = read.next();

            while (!gameType.equals("F") && !gameType.equals("f") && !gameType.equals("M") && !gameType.equals("m")) {
                System.out.println("Please enter F or M");
                System.out.println("Would you like a Fast Game (F/f) or a Memory Efficient Game (M/m)?");
                gameType = read.next();
            }

            if (gameType.equals("F") || gameType.equals("f")) {
                board = new GameBoard(rowNum, columnNum, winRows);
            }
            else {
                board = new GameBoardMem(rowNum, columnNum, winRows);
            }

            //While there is neither a win nor a draw, continue with the game
            while (true) {
                foundWinner = false;

                //Loop for amount of players in game
                for(int i = 0; i < playerNUM ; i++) {
                    //Print board at beginning of each turn
                    System.out.println(board.toString());

                    //Ask for row input
                    System.out.println("Player " + user.get(i) + " please enter your ROW");
                    rowInput = read.nextInt();

                    System.out.println("Player " + user.get(i) + " please enter your COLUMN");
                    colInput = read.nextInt();

                    //Row input, Column input and input check
                    if(colInput < minV || colInput > columnNum || rowInput < minV || rowInput > rowNum) {
                        do {
                            System.out.println("That space is unavailable, please pick again");

                            System.out.println("Player " + user.get(i) + " please enter your ROW");
                            rowInput = read.nextInt();

                            System.out.println("Player " + user.get(i) + " please enter your COLUMN");
                            colInput = read.nextInt();
                        } while (colInput < minV || colInput > columnNum || rowInput < minV || rowInput > rowNum);
                    }

                    //New BoardPosition to check against
                    BoardPosition notOpen = new BoardPosition(rowInput, colInput);

                    //If the space is taken by another token already, re-enter row and column
                    if(!board.checkSpace(notOpen)) {
                        do {
                            System.out.println("Space is occupied. Please select a different ROW and COLUMN");
                            System.out.println("Player " + user.get(i) + " please enter your ROW");
                            rowInput = read.nextInt();

                            System.out.println("Player " + user.get(i) + " please enter your COLUMN");
                            colInput = read.nextInt();

                            //Row input, Column input and input check again
                            if(colInput < minV || colInput > columnNum || rowInput < minV || rowInput > rowNum) {
                                do {
                                    System.out.println("That space is unavailable, please pick again");

                                    System.out.println("Player " + user.get(i) + " please enter your ROW");
                                    rowInput = read.nextInt();

                                    System.out.println("Player " + user.get(i) + " please enter your COLUMN");
                                    colInput = read.nextInt();
                                } while (colInput < minV || colInput > columnNum || rowInput < minV || rowInput > rowNum);
                            }

                        } while (board.checkSpace(notOpen));
                    }

                    //Once input has been validated, create new position and place on the board
                    pos = new BoardPosition(rowInput, colInput);
                    board.placeMarker(pos, user.get(i));

                    //Check that the previous spot met/did not meet the win conditions
                    if (board.checkForWinner(pos)) {
                        System.out.println(board.toString());
                        System.out.println("Player " + user.get(i) + " wins!");
                        foundWinner = true;
                        break;
                    }

                    //Check that the previous spot met/did not meet the draw conditions
                    if (board.checkForDraw()) {
                        System.out.println(board.toString());
                        System.out.println("No Winner. Tie Game!");
                        foundWinner = true;
                        break;
                    }
                }

                //If a winner is found, end the loop
                if (foundWinner) {
                    break;
                }
            }

            //When the game is won or drawn, ask to play again
            System.out.println("Would you like to play again? Y/N");
            endGame = read.next();

            //Input check
            if (!endGame.equals("Y") && !endGame.equals("n") && !endGame.equals("y") && !endGame.equals("n")) {
                while (!endGame.equals("Y") && !endGame.equals("n") && !endGame.equals("y") && !endGame.equals("n")) {
                    System.out.println("Invalid input, please try again.");
                    System.out.println("Would you like to play again? Y/N");
                    endGame = read.next();
                }
            }

            //Restart the game or end the program based on user input
            if (endGame.equals("Y") || endGame.equals("y")) {
                play = true;
            }
            else if (endGame.equals("N") || endGame.equals("n")) {
                System.exit(0);
            }
        }
    }
}
