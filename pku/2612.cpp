#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};
int main() {
	int n; scanf("%d",&n);
	vector<string> mine(n), num(n);
	for (int i=0; i<n; i++) cin>>mine[i];
	for (int i=0; i<n; i++) cin>>num[i];
	bool touched = false;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (num[i][j]=='x') {
				int cnt=0;
				for (int k=0; k<8; k++) {
					if (j+dx[k]>=0&&j+dx[k]<n&&i+dy[k]>=0&&i+dy[k]<n&&mine[i+dy[k]][j+dx[k]]=='*') cnt++;
				}
				num[i][j]=(char)(cnt+48);
				if (mine[i][j]=='*') touched=true;
			}
		}
	}
	if (touched) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (mine[i][j]=='*') num[i][j] = '*';
			}
		}
	}
	for (int i=0; i<n; i++) cout<<num[i]<<endl;
}
