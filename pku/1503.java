import java.util.*;
import java.math.*;
import java.math.BigInteger.*;

class Main {
	public static void main(String[] args) {
		Scanner std = new Scanner(System.in);
		BigInteger N, sum;
		sum = new BigInteger("0");
		while (true) {
			N = std.nextBigInteger();
			if (N.compareTo(new BigInteger("0"))==0) break;
			sum = sum.add(N);
			// System.out.println(sum+" "+N);
		}
		System.out.println(sum);
	}
}