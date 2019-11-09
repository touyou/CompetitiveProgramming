#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,s;
	while (scanf("%d",&n)&&n!=0) {
		vector<int> log;
		int sum=0,num=0;
		for (int i=0; i<n; i++) {
			scanf("%d",&s);
			sum+=s;
			num++;
			log.push_back(s);
		}
		sort(log.begin(), log.end());
		sum-=log[0]+log[log.size()-1];
		num-=2;
		int res=sum/num;
		printf("%d\n",res);
	}
}
