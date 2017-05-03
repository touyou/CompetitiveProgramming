#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
/* null
 * one pair
 * two pair
 * three card
 * straight
 * full house
 * four card
 * */
int main() {
	vector<int> cards(5);
	while (scanf("%d,%d,%d,%d,%d",&cards[0],&cards[1],&cards[2],
				&cards[3],&cards[4])!=EOF) {
		vector<int> cnt(13, 0);
		for (int i=0; i<5; i++) cnt[cards[i]-1]++;
		int two = 0, three = 0, four = 0;
		for (int i=0; i<13; i++) {
			if (cnt[i] == 2) two++;
			if (cnt[i] == 3) three++;
			if (cnt[i] == 4) four++;
		}
		if (four == 1) {
			printf("four card\n");
			continue;
		} else if (two == 1 && three == 1) {
			printf("full house\n");
			continue;
		} else if (three == 1) {
			printf("three card\n");
			continue;
		} else if (two == 2) {
			printf("two pair\n");
			continue;
		} else if (two == 1) {
			printf("one pair\n");
			continue;
		}
		int c = 0;
		bool flag = false;
		for (int i=0; i<9; i++) {
			if (cnt[i] == 1) {
				if (cnt[i+1]==1&&cnt[i+2]==1&&cnt[i+3]==1&&
						cnt[i+4]==1) {
					flag = true;
					break;
				}
			}
		}
		if (flag||
				(cnt[9]==1&&cnt[10]==1&&cnt[11]==1&&cnt[12]==1&&cnt[0]==1)) {
			printf("straight\n");
		} else {
			printf("null\n");
		}
	}	
}
