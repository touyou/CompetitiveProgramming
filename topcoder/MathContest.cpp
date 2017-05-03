// BEGIN CUT HERE
// END CUT HERE
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

class MathContest {
   public:
   int countBlack(string ballSequence, int repetitions)
  {
	int res=0;
	vector <string> balls(repetitions, ballSequence);
	string tmp = "";
	for (int i=0; i<balls.size(); i++) {
		for (int j=0; j<balls[i].length(); j++) {
			tmp = "";
			if (balls[i][j] == 'B') {
				balls[i][j] = ' ';
				for (int k=0; k<balls.size(); k++) {
					for (int l=0; l<balls[k].length(); l++) {
						if (balls[k][l] == 'W') {
							tmp += 'B';
						} else if (balls[k][l] == 'B'){
							tmp += 'W';
						}
					}
					balls[k] = tmp;
				}
				res++;
			} else {
				for (int k=0; k<balls.size(); k++) {
					for (int l=0; l<balls[k].length(); l++) {
						if (balls[k][l] == 'W') {
							tmp += 'W';
						} else if (balls[k][l] == 'B'){
							tmp += 'B';
						}
					}
					reverse(tmp.begin(), tmp.end());
					balls[k] = tmp;
				}
			}
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBWWB"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BBB"; int Arg1 = 10; int Arg2 = 1; verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BW"; int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, countBlack(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
MathContest ___test;
___test.run_test(-1);
}
// END CUT HERE 
