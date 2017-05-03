public class FoxPlayingGame {
	public double theMax(int nA, int nB, int paramA, int paramB) {
		double scoreA = paramA / 1000.0;
		double scoreB = paramB / 1000.0;
		double ans = 0.0;
		double resultA = scoreA*nA; double resultB = Math.pow(scoreB, nB);
		if ((resultA > 0 || resultB > 0) && (resultA < 0 || resultB < 0)) {
			ans = resultA*resultB; 
		} else if ((nB % 2 != 0 || scoreB < 0 || scoreA > 0) && (nB % 2 == 0 || scoreB < 0 || scoreA < 0)) {
			ans *= scoreB;
			for (int i = 0; i < nA; i++) ans += scoreA;
			for (int i = 0; i < nB-1; i++) ans *= scoreB;
		} else {
			ans = resultA;
		}
		return ans;
	}
}
