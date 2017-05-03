#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int main() {
	int n, k;
	while (scanf("%d%d",&n,&k)) {
		if (n==0&&k==0) break;
		vector<string> str(n);
		for (int i=0; i<n; i++) cin>>str[i];
		set<string> res;
		if (k==2) {
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					if (i!=j) res.insert(str[i]+str[j]);
		}
		if (k==3) {
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					for (int k=0; k<n; k++)
						if (i!=j&&i!=k&&j!=k) res.insert(str[i]+str[j]+str[k]);
		}
		if (k==4) {
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					for (int k=0; k<n; k++)
						for (int l=0; l<n; l++)
							if (i!=j&&i!=k&&i!=l&&
								j!=k&&j!=l&&k!=l) res.insert(str[i]+str[j]+str[k]+str[l]);
		}
		printf("%d\n",res.size());
	}
}