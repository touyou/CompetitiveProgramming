#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
typedef vector<int> vi;

const int w[] = {9,8,7,6,5,4,3,2,1,0};

int main() {
	int in;
	while (cin>>in) {
		vi used;
		REP(i,10) {
			int weight = pow(2,w[i]);
			if (weight<=in) {
				in -= weight;
				used.push_back(weight);
			}
		}
		sort(used.begin(),used.end());
		REP(i,used.size()) {
			if(i!=0) cout<<" ";
			cout<<used[i];
		}
		cout<<endl;
	}
}
