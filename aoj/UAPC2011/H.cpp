#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vl;
int main() {
	int n;
	while (cin>>n&&n!=0) {
		ll s = n*(n+1)/2;
		vl odd, even;
		for (int i=0; i<s; i++) {
			ll tmp; cin>>tmp;
			if (tmp%2==0) {
				even.push_back(tmp);
			} else {
				odd.push_back(tmp);
			}
		}
		sort(even.begin(),even.end());
		sort(odd.begin(),odd.end());
		long double g = sqrt(even[0]/(long double)odd[0]*even[1]);
		vl res(n);
		for (int i=0; i<n; i++) {
			res[i] = even[i]/(ll)(g+1e-8);
		}
		cout<<(ll)(g+1e-8)<<endl;
		for (int i=0; i<n; i++) {
			if (i!=0) cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
}
