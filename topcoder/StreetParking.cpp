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

	/*
1.	It is not directly in front of a private driveway. => D*
2.	It is not directly in front of a bus stop. => B*
3.	It is not 5 meters before a bus stop. => -B
4.	It is not 10 meters before a bus stop. => --B
5.	It is not directly in front of a side-street. => S*
6.	It is not 5 meters before a side-street. => -S
7.	It is not 5 meters after a side-street. => S-
	*/

class StreetParking {
   public:
   int freeParks(string street)
  {
  	int count = 0;
  	int i;
  	// -D--B---DS-----B-----S-B--------------B-B-S----DB-
	for (i=0; i<street.length(); i++) {
		if (street[i] == '-') {
			if (street[i+1] == 'B') {
				continue;
			} else if (street[i+2] == 'B') {
				continue;
			} else if (street[i+1] == 'S') {
				continue;
			} else {
				count++;
			}
		} else if (street[i] == 'S') {
			if (street[i+1] == '-') {
				i++;
			}
		}
	}
	return count;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---B--S-D--S--"; int Arg1 = 4; verify_case(0, Arg1, freeParks(Arg0)); }
	void test_case_1() { string Arg0 = "DDBDDBDDBDD"; int Arg1 = 0; verify_case(1, Arg1, freeParks(Arg0)); }
	void test_case_2() { string Arg0 = "--S--S--S--S--"; int Arg1 = 2; verify_case(2, Arg1, freeParks(Arg0)); }
	void test_case_3() { string Arg0 = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"; int Arg1 = 14; verify_case(3, Arg1, freeParks(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
StreetParking ___test;
___test.run_test(-1);
}
// END CUT HERE 
