#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

const int BitSize = sizeof(int) * 8; // 整数型のビットサイズを算出
string binary(int x) {
	int bit = 1, i;
	string ans;

	for (i = 0; i < BitSize; i++) {
		if (x & bit)
			ans += '1';
		else
			ans += '0';
		bit <<= 1;
	}
//	reverse(ans.begin(), ans.end());
	return ans;
}

string bplus(string a, string b) {
	string ans="";
	for (int i=0; i<BitSize; i++) {
		int t = (a[i]-48)+(b[i]-48);
		if (t==2) t=0;
		ans += (t+48);
	}
	return ans;
}

int main() {
	int T; cin >> T;
	int N;
	for (int i=1; i<=T; i++) {
		int ans=0,loop=-1;
		cin >> N;
		vector<int> num(N);
		for (int j=0; j<N; j++) cin >> num[j];
		sort(num.begin(), num.end());
		reverse(num.begin(), num.end());
		for (int k=0; k<N; k++) {
			for (int l=0; k+l<N-1; l++) {
				string tmp="00000000000000000000000000000000";
				string sum="00000000000000000000000000000000";
				int temp=0;
				for (int j=0; j<k; j++) {
					sum = bplus(binary(num[j]),sum);
				}
				for (int j=k; j<=k+l; j++) {
					tmp = bplus(binary(num[j]),tmp);
					temp += num[j];
				}
				for (int j=k+l+1; j<N; j++) {
					sum = bplus(binary(num[j]),sum);
				}
				if (tmp == sum) {
					loop = k;
					ans = max(temp,ans);
				}
			}
			if (loop!=-1) break;
		}
		if (loop!=-1) {
			cout << "Case #" << i << ": " << ans << endl;
		} else {
			cout << "Case #" << i << ": NO" << endl;
		}
	}
}
