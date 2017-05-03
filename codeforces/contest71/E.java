import java.io.*;
import java.util.*;

public class E {
	public String[] atoms = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zu","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
		"Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",};
	public static int linearSearch(String key) {
		int i;
		for (i = 0; i < 100; i++) {
			if (atoms[i].equals(key))
				return i+1;
		}
		return -1;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] ary1 = br.readLine().split(" ");
		int n = ary1[0]; int k = ary1[1];
		String[] ary2 = br.readLine().split(" "); String[] ary3 = br.readLine().split(" ");
		int[] ary4 = new int[n]; int[] ary5 = new int[k];
		for (int i = 0; i < n; i++)
			ary4[i] = linearSearch(ary2[i]);
		for (int i = 0; i < k; i++)
			ary5[i] = linearSearch(ary3[i]);
		int[][] ary6 = new int[k];
		int sum = 0;
/*		for (int i = 0; i < k; i++) {

		}*/
		System.out.println("NO");
	}
}
