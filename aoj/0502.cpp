#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tmp[6];
	int n;
	while (cin >> n && n != 0) {
		int dice[] = {1,2,3,4,5,6};
		string vec;
		int ans=1;
		for (int i=0; i<n; i++) {
			cin >> vec;
			if (vec=="North") {
				tmp[0] = dice[1]; tmp[1] = dice[5]; tmp[2] = dice[2]; // 123456->263415
				tmp[3] = dice[3]; tmp[4] = dice[0]; tmp[5] = dice[4];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			} else if (vec=="East") {
				tmp[0] = dice[3]; tmp[1] = dice[1]; tmp[2] = dice[0]; // 123456->421653
				tmp[3] = dice[5]; tmp[4] = dice[4]; tmp[5] = dice[2];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			} else if (vec=="West") {
				tmp[0] = dice[2]; tmp[1] = dice[1]; tmp[2] = dice[5]; // 123456->326154
				tmp[3] = dice[0]; tmp[4] = dice[4]; tmp[5] = dice[3];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			} else if (vec=="South") {
				tmp[0] = dice[4]; tmp[1] = dice[0]; tmp[2] = dice[2]; // 123456->513462
				tmp[3] = dice[3]; tmp[4] = dice[5]; tmp[5] = dice[1];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			} else if (vec=="Left") {
				tmp[0] = dice[0]; tmp[1] = dice[3]; tmp[2] = dice[1]; // 123456->142536
				tmp[3] = dice[4]; tmp[4] = dice[2]; tmp[5] = dice[5];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			} else if (vec=="Right") {
				tmp[0] = dice[0]; tmp[1] = dice[2]; tmp[2] = dice[4]; // 123456->135246
				tmp[3] = dice[1]; tmp[4] = dice[3]; tmp[5] = dice[5];
				for (int j=0; j<6; j++) {
					dice[j] = tmp[j];
				}
				ans += dice[0];
			}
		}
		cout << ans << endl;
	}
}
