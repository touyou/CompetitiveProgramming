import java.util.*;
import java.io.*;
class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int R,n;
		for (;stdIn.hasNext();) {
			R=stdIn.nextInt(); n=stdIn.nextInt();
			if (R==-1&&n==-1) break;
			int x[] = new int[n];
			for (int i=0; i<n; i++) {
				x[i]=stdIn.nextInt();
			}
			Arrays.sort(x);
			int npos=x[0];
			int res=0,i=1;
			while (i<n) {
				if (npos+R<x[i]) { 
					npos=x[i];
					System.out.println(npos);
					res++;
				}
				i++;
			}
			System.out.println(res);
		}
	}
}
