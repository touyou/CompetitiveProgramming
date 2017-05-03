import java.util.Scanner;

public class BinaryCode {
	static String[] decode(String message) {
		// Encrypted string decode. ex. 123210122->011100011
		String[] ans ={"NONE", "NONE"};
		return ans;
	}

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		System.out.print("Test String: "); String n = stdIn.next();
		String[] putout = decode(n);
		System.out.print("Result:");
		System.out.println("{"+putout[0]+", "+putout[1]+"}");
	}
}
