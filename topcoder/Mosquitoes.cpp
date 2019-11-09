#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<double, int> pii;
typedef vector<int> vi;

#define EPS 1e-9
#define PI 3.14159265358979

class Mosquitoes {
public:
	int getMaximum( vector <int> xInit, vector <int> v, int R ) {
		int sz=xInit.size();
		if (sz==1) return 1;
		pii mos[sz];
		for (int i=0; i<sz; i++) {
			mos[i].first=(double)xInit[i];
			mos[i].second=v[i];
		}
		set<double> prop;
		for (int i=0; i<sz; i++) {
			for (int j=0; j<sz; j++) if (i!=j) {
				if (mos[i].first<mos[j].first) {
					double dis=mos[j].first-mos[i].first;
					double V=mos[j].second*(-1)+mos[i].first;
					if (V>0) prop.insert(dis/V);
				} else {
					double dis=mos[i].first-mos[j].first;
					double V=mos[i].second*(-1)+mos[j].second;
					if (V>0) prop.insert(dis/V);
				}
			}
		}
		int res=0;
		for (set<double>::iterator it=prop.begin(); it!=prop.end(); it++) {
			double state[sz];
			for (int i=0; i<sz; i++) state[i]=mos[i].first+mos[i].second*(*it);
			sort(state, state+sz);
			for (int i=0; i<sz; i++)
				res=max(res,upper_bound(state,state+sz,state[i]+2*R)-state-i);
		}
		double state[sz];
		for (int i=0; i<sz; i++) state[i]=mos[i].first;
		sort(state,state+sz);
		for (int i=0; i<sz; i++)
			res=max(res,upper_bound(state,state+sz,state[i]+2*R)-state-i);
		return res;
	}
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
