public class FoxProgression {
	public int theCount(int[] seq) {
		boolean bol1 = false;
		boolean bol2 = true;
		boolean bol3 = true;
		int tmp = 0;
		if (seq.length == 1) {
			bol1 = true;
		} else if (seq.length == 2) {
			if (seq[0] >= seq[1]) {
				bol3 = false;
			}
		} else {
			for (int i = 0; i < seq.length-1; i++) {
				if (i != 0 && tmp != seq[i+1]-seq[i]) {
					bol2 = false;
					break;
				}
				tmp = seq[i+1]-seq[i];
			}
			for (int i = 0; i < seq.length-1; i++) {
				if (i != 0 && tmp != seq[i+1]/seq[i]) {
					bol3 = false;
					break;
				} else if (seq[1]<seq[0])  {
					bol3 = false;
					break;
				}
				tmp = seq[i+1]/seq[i];
			}
		}
		int ans = 0;
		if (bol2) {
			ans++;
		}
		if (bol3) {
			ans++;
		}
		if (bol1) {
			ans = -1;
		}
		return ans;
	}
}
