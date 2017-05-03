// include
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
// define
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
// int <-> string
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
// typedef
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
// const
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main() {
	int T; cin >> T;
	for (int t=1; t<T+1; t++) {
		int N, M; cin >> N >> M;
		vector<string> str(N);
		for (int i=0; i<N; i++) {
			string tmp; cin >> tmp;
			SORT(tmp);
			str[i] = tmp;
		}
		int bm=11, p=0;
		vector<string> as;
		for (int i=0; i<M; i++) {
			string key; cin >> key;
			string ans;
			int m = 11;
			for (int j=0; j<N; j++) {
				int score = 0, w=0;
				for (int k=0; k<26; k++) {
					if (key[k] != str[i][w]) {
						score++;
					} else if (key[k] == str[i][w]) {
						while (key[k] == str[i][w]) w++;
					}
					if (w > SZ(str[i])) break;
				}
				if (m > score) {
					m = score;
					ans = str[i];
				}
			}
			as.push_back(str[i]);
		}
		cout << "Case #" << t << ": ";
		for (int i=0; i<M; i++) {
			if (i!=0) cout << " ";
			cout << str[i];
		}
		cout << endl;
	}
}
