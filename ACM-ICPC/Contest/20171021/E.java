import java.util.*;
import java.io.*;

public class E {
	private static  Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String line;

		while (!(line = sc.nextLine()).equals(".")) {
			line = line.substring(0, line.length() - 1);
			String[] arrayA = line.split(", ");
			boolean[] posWords = new boolean[arrayA.length];
			int words = 0, numbers = 0;
			Map<String, String> map = new HashMap<String, String>();

			for (int i = 0; i < arrayA.length; ++i){
				if (isWord(arrayA[i])) {
					posWords[i] = true;
					++words;
					map.put(toLower(arrayA[i]), arrayA[i]);
				} else {
					posWords[i] = false;
					++numbers;
				}
			}

			int[] arrayNumbers = new int[numbers]; 
			int pn = 0;
			String[] arrayWords = new String[words]; 
			int pw = 0;

			for (int i = 0; i < arrayA.length; ++i){
				if (isWord(arrayA[i])){
					arrayWords[pw++] = toLower(arrayA[i]);
				} else {
					arrayNumbers[pn++] = Integer.parseInt(arrayA[i]);
				}
			}

			Arrays.sort(arrayNumbers); 
			pn = 0;
			Arrays.sort(arrayWords); 
			pw = 0;

			for (int i = 0; i < posWords.length; ++i) {
				if (i > 0) {
					System.out.print(", ");
				}

				if (posWords[i]) {
					System.out.print(map.get(arrayWords[pw++]));
				} else {
					System.out.print(arrayNumbers[pn++]);
				}
			}
			System.out.println(".");
		}
	}

	private static boolean isWord(String s) {
		char c = s.charAt(0);

		if ((c >= 'a' && c <= 'z') ||
		    (c >= 'A' && c <= 'Z')) {
			return true;
		}
		return false;
	}
	
	private static String toLower(String s) {
		String t = "";
		char c;

		for (int i = 0; i < s.length(); ++i) {
			c = s.charAt(i);

			if (c >= 'A' && c <= 'Z') {
				c = ((char)(c-'A'+'a'));
			}
			t += c;
		}
		return t;
	}
}
