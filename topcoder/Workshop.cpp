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

class Workshop {
   public:
   bool ok(int a, int b, int c) {
   	if (a+b <= c) return false;
   	if (a+c <= b) return false;
   	if (b+c <= a) return false;
   	return true;
   }
   int pictureFrames(vector <int> pieces)
  {
  	int res = 0;
  	sort(pieces.begin(), pieces.end());
  	if (pieces.size() < 3) return 0;
	for (int i=0; i<pieces.size()-2; i++) {
		for (int j=i+1; j<pieces.size()-1; j++) {
			for (int k=j+1; k<pieces.size(); k++) {
				if (ok(pieces[i],pieces[j],pieces[k])) { 
					res++;
				}
			}
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, pictureFrames(Arg0)); }
	void test_case_1() { int Arr0[] = {8,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, pictureFrames(Arg0)); }
	void test_case_2() { int Arr0[] = {4,23,76,22,87,3,1,99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, pictureFrames(Arg0)); }
	void test_case_3() { int Arr0[] = {10000,9999,9998,9997,9996,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 43; verify_case(3, Arg1, pictureFrames(Arg0)); }
	void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, pictureFrames(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Workshop ___test;
___test.run_test(-1);
}
// END CUT HERE 
