// #include <cstdio>
// #include <algorithm>
// using namespace std;

// int main() {
	// int ma, gre, geo, dp, gra, ot;
	// while (scanf("%d%d%d%d%d%d",&ma,&gre,&geo,&dp,&gra,&ot)) {
		// if (ma==0&&gre==0&&geo==0&&
			// dp==0&&gra==0&&geo==0) break;
		// int res = 0;
		// if (ma > dp&&ma>0&&dp>0) {
			// int cnt = min(ma / 2, dp);
			// ma -= cnt*2;
			// dp -= cnt;
			// res += cnt;
		// } else if (ma < dp&&ma>0&&dp>0) {
			// int cnt = min(dp / 2, ma);
			// ma -= cnt;
			// dp -= cnt*2;
			// res += cnt;
		// } else if (ma>0&&dp>0) {
			// int cnt = (ma+dp) / 3;
			// ma -= cnt*3;
			// if (ma < 0) dp += ma;
			// res += cnt;
		// }
		// if (gre > gra&&gre>0&&gra>0) {
			// int cnt = min(gre / 2, gra);
			// gre -= cnt*2;
			// gra -= cnt;
			// res += cnt;
		// } else if (gre<gra&&gre>0&&gra>0) {
			// int cnt = min(gra / 2, gre);
			// gre -= cnt;
			// gra -= cnt*2;
			// res += cnt;
		// } else if (gre>0&&gra>0) {
			// int cnt = (gre+gra) / 3;
			// gre -= cnt*3;
			// if (gre < 0) gra += gre;
			// res += cnt;
		// }
		// if (geo > ot&&geo>0&&ot>0) {
			// int cnt = min(geo / 2, ot);
			// geo -= cnt*2;
			// ot -= cnt;
			// res += cnt;
		// } else if (geo<ot&&geo>0&&ot>0) {
			// int cnt = min(ot / 2, geo);
			// geo -= cnt;
			// ot -= cnt*2;
			// res += cnt;
		// } else if (geo>0&&ot>0) {
			// int cnt = (geo+ot) / 3;
			// geo -= cnt*3;
			// if (geo < 0) ot += geo;
			// res += cnt;
		// }
		// if (ma+dp>0&&gre+gra>0&&geo+ot>0)
			// res += min(ma+dp, min(gre+gra, geo+ot));
		// printf("%d\n", res);
	// }
// }