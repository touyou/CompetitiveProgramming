package SRM500;

import java.util.*;

class SRMCards {
	public int maxTurns(int[] cards) {
		Arrays.sort(cards);
		int res = 0;
		for (int i = 0; i < cards.length; i++) {
			if (i + 1 < cards.length && cards[i+1] == cards[i] + 1)
				i++;
			res++;
		}
		return res;
	}
}
