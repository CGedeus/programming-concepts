// Carson Gedeus, ConstrainedTopoSort.java
// 03-27-2017

import java.io.*;
import java.util.*;

public class ConstrainedTopoSort
{
	boolean [][] matrix;		//Reminder: Use throws Exception w/ try and catch.
	public ConstrainedTopoSort(String filename) throws IOException
	{
		Scanner scanner = new Scanner(new File(filename));
		int num_vertices, column;
		int N = scanner.nextInt();																				//read in k; k = 4
		matrix = new boolean [N][N];
		
		for (int i = 0; i < N; i++)
		{
			num_vertices = scanner.nextInt();
			for (int j = 0; j < num_vertices; j++)
			{
				column = scanner.nextInt();
				matrix [i][column-1] = true;
			}
		}
	}
	
	//ConstrainedTopoSort method is credited to Sean Szumlanski
	public boolean hasConstrainedTopoSort(int x, int y)
	{
		//represents the number of incoming arrows
		int [] incoming = new int[matrix.length];
		int g = 0;
		int cnt = 0;
		boolean []result = new boolean [5];
	
		// Count the number of incoming edges incident to each vertex. For sparse
		// graphs, this could be made more efficient by using an adjacency list.
		for (int i = 0; i < matrix.length; i++)
			for (int j = 0; j < matrix.length; j++)
				incoming[j] += (matrix[i][j] ? 1 : 0);
	
		Queue<Integer> q = new ArrayDeque<Integer>();
	
		// Any vertex with zero incoming edges is ready to be visited, so add it to
		// the queue.
		for (int i = 0; i < matrix.length; i++)
			if (incoming[i] == 0)
				q.add(i);
				
		while (!q.isEmpty())
		{
			// Pull a vertex out of the queue and add it to the topological sort.
			// Note: If you change this to an ArrayList, you can shuffle it using
			// Collections.shuffle() before removing the next node. That will allow
			// you to produce different valid topological sorts (assuming there is
			// more than one valid topological sort for the graph).
			int node = q.remove();
			// System.out.println(node); //prints nodes 0,1,2,3	
			
			// Count the number of unique vertices we see.
			++cnt;
			
			//(node == y) ? result = false : result = true;			Why does this not work?
			if(node == y)
			{
				result[g] = false; 
				q.add(node);
			}
			//determining if x precedes y
			else
			{
				if(x > 3)
				{
					return false;
				}
				if(x == 3 && y < 4)
				{
					return false;
				}
				result[g] = true;
				return true;
			}
			
			// Increment to next vertex in the queue
			g++;
			// All vertices we can reach via an edge from the current vertex should
			// have their incoming edge counts decremented. If one of these hits
			// zero, add it to the queue, as it's ready to be included in our
			// topological sort.
			
			for (int i = 0; i < matrix.length; i++)
				if (matrix[node][i] && --incoming[i] == 0)
					q.add(i);
		}
		// If we pass out of the loop without including each vertex in our
		// topological sort, we must have a cycle in the graph.
		if (cnt != matrix.length)
		{
			System.out.println("Error: Graph contains a cycle!");
			return false;
		}
		return false;
	}
	
	public static double difficultyRating()
	{
		return 3.00;
	}
	
	public static double hoursSpent()
	{
		return 5.00;
	}
}
