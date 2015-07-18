import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner data = new Scanner(System.in);
		int n = data.nextInt();
		int i;
		BigInteger zero = new BigInteger("0");
		BigInteger six = new BigInteger("6");

		BigInteger num;

		for(i=0; i<n; ++i){
			num = data.nextBigInteger();
			if((num.mod(six)).compareTo(zero) == 0){
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}
}
