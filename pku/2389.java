import java.math.*;
import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner std = new Scanner(System.in);
		BigInteger R, S;
		R = std.nextBigInteger();
		S = std.nextBigInteger();
		System.out.println(R.multiply(S));
	}
}
