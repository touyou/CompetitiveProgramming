public class p2 {
	public static int fib(int n) {
		int ans = 0;
		if (n == 1) ans += 1;
		else if (n == 2) ans += 2;
		else ans += fib(n-1)+fib(n-2);
		return ans;
	}

	public static void main(String[] args) {
		int count = 0;
		for (int i = 0; i < 1000; i++) {
			if (fib(i) > 1000) {
				break;
			}
			count++;
		}
		System.out.println(count);
	}
}
