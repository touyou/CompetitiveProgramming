import java.io.*;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[][] str = new String[n][];
		String[] ans = new String[n];
		for (int i = 0; i < n; i++)
			str[i] = br.readLine().split("");
		String s;
		for (int i = 0; i < n; i++) {
			if (str[i].length-1 <= 10) {
				s = "";
				for (int j = 1; j < str[i].length; j++) s += str[i][j];
				ans[i] = s;
			} else {
				String a = String.valueOf(str[i].length-3);
				ans[i] = str[i][1] + a + str[i][str[i].length-1];
			}
		}
		for (int i = 0; i < n; i++)
			System.out.println(ans[i]);
	}
}
