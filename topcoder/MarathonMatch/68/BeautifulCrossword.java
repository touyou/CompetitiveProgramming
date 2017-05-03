import java.util.*;
public class BeautifulCrossword {
	/* calculate score */
	public double calcScore(int N, String[] cross, int[] weights) {
	/**
	*	Score-----
	*
	*	AAH..
	*	A....
	*	HELLO
	*	E....
	*	D.... → (11/25*weights[0]+5*5/25*weights[1]+1/3*weights[3]+1/11*weights[4])/(weights[0]+weights[1]+weights[2]+weights[3])
	*/
		double score = A(N, cross)*weights[0]+B(N, cross)*weights[1]+C(N, cross)*weights[2]+D(N, cross)*weights[3];
		score /= (weights[0]+weights[1]+weights[2]+weights[3]);
		return score;
	}
	/* score A */
	public int A(int N, String[] cross) {
		int all = N*N;		// N*N
		int sum = N*N;		// subtract the number of empty cells from it
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ('.' == cross[i].charAt(j)) sum--;
			}
		}
		return sum/all;
	}
	/* score B */
	public int B(int N, String[] cross) {
		int all = N*N;		// N*N
		int row = N; int column = N;		// substract the number of rows/column filling by empty cells from it
		int j;
		for (int i = 0; i < N; i++) {		// rows
			j = 0;
			while (j < N) {
				if ('.' != cross[i].charAt(j)) break;
				j++;
			}
			if (j == N) row--;
		}
		for (int i = 0; i < N; i++) {		// columns
			j = 0;
			while (j < N) {
				if ('.' != cross[j].charAt(i)) break;
				j++;
			}
			if (j == N) column--;
		}
		return row*column/all;
	}
	/* score C */
	public double C(int N, String[] cross) {
		double e = N/8;
		double score = 0;
		int value = 0;
		int j;
		for (int i = (int)e; i > 0; i--) {
			// (i, j), (j, i), (N-i-1, j), (j, N-i-1), (i, N-j-1), (N-j-1, i), (N-i-1, N-j-1) and (N-j-1, N-i-1)
			j = i+1;
			if ('.' == cross[i].charAt(j)) value++;
			if ('.' == cross[j].charAt(i)) value++; 
			if ('.' == cross[N-i-1].charAt(j)) value++; 
			if ('.' == cross[j].charAt(N-i-1)) value++; 
			if ('.' == cross[i].charAt(N-j-1)) value++; 
			if ('.' == cross[N-j-1].charAt(i)) value++; 
			if ('.' == cross[N-i-1].charAt(N-j-1)) value++; 
			if ('.' == cross[N-j-1].charAt(N-i-1)) value++;
			if (value == 0 || value == 8) score += 1.0;
			else if (value == 1 || value == 7) score += 0.5;
			else if (value == 2 || value == 6) score += 0.1;
		}
		return score;
	}
	/* score D */
	public int D(int N, String[] cross) {
		int word = N*N;		// N*N
		for (int i = 0; i < N; i++) {		// word cells
			for (int j = 0; j < N; j++) {
				if ('.' == cross[i].charAt(j)) word--;
			}
		}
		int closs = 0;
		for (int i = 0; i < N; i++) {		// clossing words
			for (int j = 0; j < N; j++) {
				if ('.' != cross[i].charAt(j)) {
					if (i == 0) {
						if ('.' != cross[1].charAt(j)) closs++;
					} else if (i == N-1) {
						if ('.' != cross[N-2].charAt(j)) closs++;
					} else if (j == 0) {
						if ('.' != cross[i].charAt(1)) closs++;
					} else if (j == N-1) {
						if ('.' != cross[i].charAt(N-2)) closs++;
					} else {
						int count = 0;
						if ('.' != cross[i-1].charAt(j)) count++;
						if ('.' != cross[i+1].charAt(j)) count++;
						if ('.' != cross[i].charAt(j-1)) count++;
						if ('.' != cross[i].charAt(j+1)) count++;
						if (count >= 2) closs++;
					}
				}
			}
		}
		return closs/word;
	}
	
	public void length_sort(String[] words) {
		for (int i=0; i<words.length; i++) {
			for (int j=i+1; j<words.length; j++) {
				if (words[i].length() < words[j].length()) {
					String temp = words[i];
					words[i] = words[j];
					words[j] = temp;
				}
			}
		}
	}
	
	public String[] gcross(int N, String[] words) {
		Random rand = new Random();
		length_sort(words);
		String[] cross = new String[N]; int i;
		while (true) {
			i = rand.nextInt(N);
			if (words[i].length() <= N && N-i < 4) {
				cross[0] = words[i];
				break;
			} else if (words[i].length() < N) {
				for (int j=N; j>=0; j--) {
					if (words[j].length() < N-i) {
						cross[0] += words[i]+'.'+words[j];
						if (N > cross[0].length()) {
							for (int s=0; s<N-cross[0].length(); s++)
								cross[0] += '.';
						}
					}
				}
			}
		}
		for (int j=0; j<cross[0].length(); j++) {
			for (int k=0; k<words.length; k++) {
				if (words[k].charAt(0) == cross[0].charAt(j)) {
					for (int l=0; l<j-1; l++) {
						for (int m=1; m<N; m++)
							cross[m] += '.';
					}
					int at=1;
					for (int n=1; n<words[k].length(); n++) {
						cross[at] += words[k].charAt(n);
						at++;
					}
					j++;
				}
			}
		}
		return cross;
	}
	
	public String[] generateCrossword(int N, String[] words, int[] weights) {
		/** calc(N,cross,weights)	--- individual score
		*	double highscore		--- highscore
		*	String[] cross			--- crossword pattern
		*	int site				--- words address
		*	String[] good			--- best crossword and return it
		*/
		Random rand = new Random();
		String[] cross = new String[N];	String[] good = new String[N];
		double highscore = 0; double score;
		int count = 0;
		while (count < 100) {
			cross = (String[])gcross(N, words).clone();
			for (int i=0; i<N; i++) {
				if (cross[i].length() != N) {
					for (int j=0; j<N-cross[i].length(); j++)
						cross[i] += '.';
				}
			}
			score = calcScore(N,cross,weights);
			if (count == 0) {
				highscore = score;
				good = (String[])cross.clone();
			} else if (highscore < score) {
				highscore = score;
				good = (String[])cross.clone();
			}
			count++; 
		}
		/*
		good = {"BORER.BOTAS",
				"R......V...",
				"A....C.E..N",
				"S.F..O.R..E",
				"H.U..C..T.W",
				"..STACKER..",
				"..E..O..A..",
				"S.L..I..Y.U",
				"I..INDEX..M",
				"M.........P",
				"AHED..SINUS",}
		*/
		return good;
	}
}
