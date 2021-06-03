default: cpsc2150/extendedTicTacToe/AbsGameBoard.java cpsc2150/extendedTicTacToe/BoardPosition.java cpsc2150/extendedTicTacToe/GameScreen.java cpsc2150/extendedTicTacToe/IGameBoard.java cpsc2150/extendedTicTacToe/GameBoard.java cpsc2150/extendedTicTacToe/GameBoardMem.java
		javac -Xlint cpsc2150/extendedTicTacToe/GameScreen.java

run: cpsc2150/extendedTicTacToe/GameScreen.class
		java cpsc2150.extendedTicTacToe.GameScreen

testGB: cpsc2150/extendedTicTacToe/AbsGameBoard.java cpsc2150/extendedTicTacToe/BoardPosition.java cpsc2150/extendedTicTacToe/GameScreen.java cpsc2150/extendedTicTacToe/IGameBoard.java cpsc2150/extendedTicTacToe/GameBoard.java cpsc2150/extendedTicTacToe/GameBoardMem.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.extendedTicTacToe.TestGameBoard

testGBmem: cpsc2150/extendedTicTacToe/AbsGameBoard.java cpsc2150/extendedTicTacToe/BoardPosition.java cpsc2150/extendedTicTacToe/GameScreen.java cpsc2150/extendedTicTacToe/IGameBoard.java cpsc2150/extendedTicTacToe/GameBoard.java cpsc2150/extendedTicTacToe/GameBoardMem.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.extendedTicTacToe.TestGameBoardMem

clean:
		rm -f cpsc2150/extendedTicTacToe/*.class
