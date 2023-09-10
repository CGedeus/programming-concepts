//Carson Gedeus
//SneakyQueens Assignment

import java.util.*;
import java.io.*;
import java.awt.Point;

public class SneakyQueens
{
	public static final int num_alphabet = 26;

	public static boolean allTheQueensAreSafe(ArrayList<String> coordinateStrings, int boardSize) {

		Map<Integer, Integer> chessBoard = new HashMap<>(boardSize);
		Map<Point, Integer> hashPoint = new HashMap<>(boardSize);
		Map<Point, Integer> slashPoint = new HashMap<>(boardSize);
		String split_string;
		int _123;
		int abc_;
		int hash_value;
		boolean retval = true;

		for(int i = 0; i < coordinateStrings.size(); i++) {

			split_string = coordinateStrings.get(i).split("^[a-zA-Z]$+|\\d+")[0];
			_123 = Integer.parseInt(coordinateStrings.get(i).split("\\D+")[1]);				// abc [123]
			abc_ = converterMethod(split_string);											// [abc] 123

			if(chessBoard.containsKey(_123) || chessBoard.containsValue(abc_)) {
				retval = false;
			} else {
				chessBoard.put(_123, abc_);													// [y=x]
			}

			hash_value = (boardSize - abc_) - _123 + boardSize;								// 1. (boardSize - x) - y + boardSize
			if(hashPoint.containsValue(hash_value)) {										// 2. [(x,y)=hash]
				retval = false;
			} else {
				hashPoint.put(new Point(abc_,_123), hash_value);
			}

			hash_value = abc_ - _123 + boardSize;											// 1. x - y + boardSize
			if(slashPoint.containsValue(hash_value)) {										// 2. [(x,y)=hash]
				retval = false;
			} else {
				slashPoint.put(new Point(abc_,_123), hash_value);
			}
		}

		return retval;
	}

	public static int converterMethod(String column_conversion) {

		char [] to_char = column_conversion.toCharArray();
		int length_of_array = to_char.length-1;
		int stored_int = 0;
		
		for(int i = 0; i < column_conversion.length(); i++) {
			stored_int += (Math.abs(96 - to_char[i])) * Math.pow(num_alphabet, length_of_array);
			length_of_array--;
		}
		return stored_int;
	}
	
	public static double difficultyRating() {
		return 3.00;
	}
	
	public static double hoursSpent() {
		return 10.00;
	}
}