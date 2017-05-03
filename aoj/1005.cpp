#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main() {
	int n;
	while (scanf("%d", &n)&&n!=0) {
		vi stu(n*n);
		for (int i=0; i<n*n; i++) scanf("%d", &stu[i]);
		vi row(n,1000000), col(n,0);
		for (int i=0; i<n; i++) {
			for (int j=i*n; j<(i+1)*n; j++) row[i] = min(row[i], stu[j]);
		}
		for (int i=0; i<n; i++) {
			for (int j=i; j<n*n; j+=n) col[i] = max(col[i], stu[j]); 
		}
		int res = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (row[i]==col[j]) res = row[i];
			}
		}
		printf("%d\n",res);
	}
}
