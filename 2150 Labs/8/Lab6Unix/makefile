default: cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/StringQueueApp.java
		javac -Xlint cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/StringQueueApp.java

runInt: cpsc2150/MyQueue/QueueApp.class
		java cpsc2150.MyQueue.QueueApp

runString: cpsc2150/MyQueue/StringQueueApp.class
		java cpsc2150.MyQueue.StringQueueApp

test: cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/StringQueueApp.java cpsc2150/MyQueue/TestArrayQueue.java cpsc2150/MyQueue/TestListQueue.java
		javac -Xlint -cp .:/usr/share/java/junit4.jar cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/StringQueueApp.java cpsc2150/MyQueue/TestArrayQueue.java cpsc2150/MyQueue/TestListQueue.java


testArr: cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/StringQueueApp.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestArrayQueue

testList: cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/StringQueueApp.java
	java -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestListQueue

clean:
		rm -f cpsc2150/MyQueue/*.class
