#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
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

// TLE
class NetworkXMessageRecovery {
public:
  string recover( vector <string> messages ) {
    string result = "";
	/* messagesが全て部分文字列となっている文字列
	 * 辞書順最小のものを探す
	 * 下手にソートを使うとexample2がだめ
	 * 辞書順に小さいものを取っていく
	 * ただしそれが他の文字列の後尾にあったらダメ
	 * */
	while (!messages.empty()) {
		sort(messages.begin(), messages.end());
		for (int i=0; i<messages.size(); i++) {
			char temp = messages[i][0];
			bool flag = true;
			for (int j=0; j<result.length(); j++) if (result[j] == temp) {
				flag = false;
				break;
			}
			if (flag) {
				messages[i].erase(1);
				continue;
			}
			for (int j=0; j<messages.size(); j++) {
				if (j == i) continue;
				for (int k=1; k<messages[j].length(); k++) {
					if (messages[j][k] == temp) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) {
				messages[i].erase(1);
				result += temp;
				break;
			}
		}
	}
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acd", "bce"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcde"; verify_case(0, Arg1, recover(Arg0)); }
	void test_case_1() { string Arr0[] = {"ed", "dc", "cb", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "edcba"; verify_case(1, Arg1, recover(Arg0)); }
	void test_case_2() { string Arr0[] = {"Fox", "Ciel", "FoxCiel"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "FoxCiel"; verify_case(2, Arg1, recover(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Aa"; verify_case(3, Arg1, recover(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  NetworkXMessageRecovery ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
