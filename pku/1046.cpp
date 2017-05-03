#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
#define PB push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int dis(int r1, int g1, int b1, int r2, int g2, int b2) {
	return (int)sqrt(pow(r1-r2, 2)+pow(g1-g2, 2)+pow(b1-b2, 2));
}

int main() {
	vvi target, maps;
	for (int i=0; i<16; i++) {
		vi temp(3); scanf("%d %d %d",&temp[0],&temp[1],&temp[2]);
		target.PB(temp);
	}
	int r,g,b;
	while (cin>>r>>g>>b&&r!=-1&&g!=-1&&b!=-1) {
		int min = 1000000;
		int c;
		for (int i=0; i<16; i++) {
			int dist = dis(r,g,b,target[i][0],target[i][1],target[i][2]);
			if (dist < min) {
				min = dist;
				c = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,target[c][0],target[c][1],target[c][2]);
	}
}
