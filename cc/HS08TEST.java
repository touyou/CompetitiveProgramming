import java.util.*;

class atm {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int x = stdIn.nextInt();
		double y = stdIn.nextDouble();
		double tmp = y-x-0.5;
		if (y-x >= 0.5 && x%5 == 0) {
			System.out.printf("%.2f\n",tmp);
		} else {
			System.out.printf("%.2f\n",y);
		}
	}
}
