// Sean Szumlanski
// ====================================
// ConstrainedTopoSort: TestCase05.java
// ====================================
// A brief test case to help ensure you've implemented the difficultyRating()
// and hoursSpent() methods correctly.


import java.io.*;
import java.util.*;

public class TestCase05
{
	private static void failwhale()
	{
		System.out.println("fail whale :(");
		System.exit(0);
	}

	public static void main(String [] args)
	{
		double difficulty = ConstrainedTopoSort.difficultyRating();
		if (difficulty < 1.0 || difficulty > 5.0) failwhale();

		double hours = ConstrainedTopoSort.hoursSpent();
		if (hours <= 0.0) failwhale();

		System.out.println("Hooray!");
	}
}
