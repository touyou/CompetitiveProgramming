import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
	Scanner stdIn = new Scanner(System.in);
	int n, k;
	while (true) {
	    n=stdIn.nextInt(); k=stdIn.nextInt();
	    if (n==0&&k==0) break;
	    int[] num = new int[k];
	    for (int i=0; i<k; i++) num[i]=stdIn.nextInt();
	    Arrays.sort(num);
	    int cnt=0, j=0;
	    while (num[j]==0) { cnt++;j++; }
	    int[] dp = new int[n];
	    for (int i=j; i<k; i++) {
		if (i==j) dp[num[i]-1]=1;
		dp[num[i]-1]=dp[num[i]-2]+1;
	    }
	    int max=0;
	    boolean flag=false;
	    for (int i=0; i<n; i++) {
		
	    System.out.println();
	}
    }
}
