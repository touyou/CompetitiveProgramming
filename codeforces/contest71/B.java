import java.io.*;

public class B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] nums = br.readLine().split(" ");
		int n = Integer.parseInt(nums[0]); int k = Integer.parseInt(nums[1]); int t = Integer.parseInt(nums[2]);
		int max = n*k;
		int ans = (int)max*t/100;
		int view = 0;
		boolean count = true;
		for (int i = 0; i < n; i++) {
			if (i != 0) System.out.print(" ");
			view += k;
			if (view <= ans) {
				System.out.print(k);
			} else if (view > ans && count) {
				System.out.print(ans%k);
				count = false;
			} else {
				System.out.print(0);
			}
		}
		System.out.println();
	}
}
