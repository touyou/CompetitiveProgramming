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

class DiskSpace {
   public:
   int minDrives(vector <int> used, vector <int> total)
  {
	int sum = 0;
	for (int i=0; i<used.size(); i++)
		sum += total[i]-used[i];
	sort(total.begin(), total.end());
	int j = 0;
	for (int i=0; i<total.size(); i++) {
		// cout << sum << endl;
		sum -= total[i];
		if (sum < 0) {
			break;
		} else {
			j++;
		}
	}
	int res = total.size() - j;
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {300,525,110}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {350,600,115}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,200,200,199,200,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,200,200,200,200,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {750,800,850,900,950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {800,850,900,950,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,
 49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,
 50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 49; verify_case(3, Arg2, minDrives(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, minDrives(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
DiskSpace ___test;
___test.run_test(-1);
}
// END CUT HERE 
