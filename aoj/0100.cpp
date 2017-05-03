#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int n;
	while (scanf("%d",&n)&&n!=0) {
		map<int, long long> sales;
		vector<int> log;
		long long prc, mnt;
		int num;
		for (int i=0; i<n; i++) {
			scanf("%d%lld%lld",&num,&prc,&mnt);
			if (!sales[num]) {
				log.push_back(num);
			}
			sales[num] += prc * mnt;
		}
		bool flag = true;
		for (int i=0; i<log.size(); i++) {
			if (sales[log[i]]>=1000000) {
				flag = false;
				printf("%d\n", log[i]);
			}
		}
		if (flag) printf("NA\n");
	}
}
