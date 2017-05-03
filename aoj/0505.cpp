#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n,m,num;
	while (scanf("%d %d",&n,&m) && n != 0 && m != 0) {
		pair<int, int> place[m];
		for (int i=0; i<m; i++) {
			place[i].first = 0;
			place[i].second = i+1;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				scanf("%d",&num);
				if (num == 1) place[j].first++;
			}
		}
		for (int i=0; i<m-1; i++) {
			for (int j=m-1; j>i; j--) {
				if (place[j].first>place[j-1].first) {
					swap(place[j], place[j-1]);
				}
			}
		}
		for (int i=0; i<m; i++) {
			if (i!=0) printf(" ");
			printf("%d",place[i].second);
		}
		printf("\n");
	}
}
