import java.math.*;
import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner std = new Scanner(System.in);
		BigDecimal R;
		int n;
		while (std.hasNext()) {
			R=std.nextBigDecimal();
			n=std.nextInt();
			System.out.println(R.pow(n).toPlainString().replaceAll("^0|\\.?0*$",""));
		}
	}
}
