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


class BifidSortMachine {
public:
  int countMoves( vector <int> a ) {
    set<int> doubt;
	for (int i=0; i<a.size()-1; i++) {
		vector<int> tmp;
		int d = 0;
		for (int j=i+1; j<a.size(); j++) {
			if (a[i]>a[j]&&doubt.find(a[j])==doubt.end()) {
				tmp.push_back(a[j]);
			} else if (a[i]>a[j]) {
				d++;
			}
		}
		if (!tmp.empty()) {
			if (tmp.size() == a.size()-1-i-d) {
				doubt.insert(a[i]);
			} else {
				for (int j=0; j<tmp.size(); j++) doubt.insert(tmp[j]);
			}
		}
	}
	return doubt.size();
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,12,25,7,15,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {1000,-1000,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {1, -10, -1, -8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, countMoves(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  BifidSortMachine ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
