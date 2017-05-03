import java.io.*;

public class A {
	public static int solve(int n) {
		int sum = 0;
		if (n == 1) {
			sum = 1;
		} else {
			sum = solve(n-1)*3;
		}
		return sum;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int ans = solve(n);
		System.out.println(ans);
	}
}
