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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

class TheEncryptionDivTwo {
   public:
   string encrypt(string message)
  {
	string res="a";
	map<char, char> trans;
	trans[message[0]] = 'a';
	char tmp = 'a';
	FOR(i,1,message.length()) {
		if (trans.count(message[i])==1) {
			res += trans[message[i]];
		} else {
			tmp++;
			res += tmp;
			trans[message[i]] = tmp;
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello"; string Arg1 = "abccd"; verify_case(0, Arg1, encrypt(Arg0)); }
	void test_case_1() { string Arg0 = "abcd"; string Arg1 = "abcd"; verify_case(1, Arg1, encrypt(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "abcdbefg"; verify_case(2, Arg1, encrypt(Arg0)); }
	void test_case_3() { string Arg0 = "encryption"; string Arg1 = "abcdefghib"; verify_case(3, Arg1, encrypt(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheEncryptionDivTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
