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

int main() {
	string str; cin >> str;
	string tmp=str;
	sort(str.begin(), str.end());
	char s = str[0];
	int c = 1;
	for (int i=1; i<str.length(); i++) {
		if (s==str[i]&&c%2==1) {
			str.erase(i-1,2);
			i-=2;
			c++;
		} else if (s==str[i]) {
			c++;
		} else if (s!=str[i]) {
			s=str[i];
			c=1;
		}
	}
	string ans="";
	for (int i=0; i<tmp.length(); i++) {
		for (int j=0; j<str.length(); j++) {
			if (tmp[i]==str[j]) {
				ans+=tmp[i];
				str.erase(j,1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
