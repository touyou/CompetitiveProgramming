// #include <cstdio>

// char map[10][10];

// int main() {
	// for (int i=0; i<10; i++) scanf("%s", map[i]);
	// bool flag = true;
	// for (int i=0; i<10; i++) {
		// for (int j=0; j<10; j++) {
			// if (map[i][j] == '1') {
				// if (i==0||i==9||j==0||j==9) {
					// flag = false;
					// break;
				// }
				// int cnt = 1;
				// for (int k=j+1; k<10; k++) {
					// if (map[i][k] == '1') {
						// cnt++;
						// if (map[i+1][k] == '1') flag = false;
					// }
					// if (!flag) break;
					// if (cnt > 4) break;
				// }
				// if (cnt > 4) {
					// flag = false;
					// break;
				// }
				// if (cnt == 1) {
					// for (int k=i+1; k<10; k++) {
						// if (map[k][j] == '1') {
							// cnt++;
							// if (map[k][j+1] == '1' ||
								// map[k][j-1] == '1') flag = false;
						// }
						// if (!flag) break;
						// if (cnt > 4) break;
					// }
					// if (cnt > 4) {
						// flag = false;
						// break;
					// }
				// } else if (map[i+1][j] == '1') {
					// flag = false;
					// break;
				// }
			// }
		// }
		// if (!flag) break;
	// }
	// if (flag) printf("correct\n");
	// else printf("incorrect\n");
// }

// /*
// 座標に0,9が入っていたら→false
// 横に1があったら→その方向にカウント→5以上でfalse
		// →縦を見てそこに1がある→false
// */