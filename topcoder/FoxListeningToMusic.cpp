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

class FoxListeningToMusic {
   public:
   vector <double> getProbabilities(vector <int> length, int T)
  {
	vector<double> ans(length.size(), 0.0);
	for (int i=0; i<length.size(); i++) {
		double sum = length[i];
		int c=1;
		for (int j=i; j<length.size(); i++) {
			if (sum >= T+0.5) {
				ans[j] += 1/pow(length.size(), c);
				break;
			}
			sum += length[j];
			c++;
		}
	}
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arr2[] = {0.25, 0.75 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 10, 100, 1000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arr2[] = {0.2, 0.2, 0.2, 0.2, 0.2 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 8, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.1875, 0.3125, 0.1875, 0.3125 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; double Arr2[] = {0.9990234375, 9.765625E-4 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getProbabilities(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {58, 47, 36, 25, 14, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arr2[] = {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getProbabilities(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FoxListeningToMusic ___test;
___test.run_test(-1);
}
// END CUT HERE 
