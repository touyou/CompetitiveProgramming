import java.io.*;

public class B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] string = br.readLine().split(" ");
		int count = 0;
		for (int i = 0; i< string.length; i++) {
			String st = string[i];
			if ('?' == st.charAt(st.length()-1) && st.length() <= n) count++;
			else if ('!' == st.charAt(st.length()-1) && st.length() <= n) count++;
			else if ('.' == st.charAt(st.length()-1) && st.length() <= n) count++;
		}
		if (count == 0) System.out.println("Impossible");
		else System.out.println(count);
	}
}
