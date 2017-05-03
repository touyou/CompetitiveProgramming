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
const double EPS = 1e-9;
typedef long long ll;

class LeastMajorityMultiple {
public:
/*
    int gcd(int a, int b)
        {
            return b != 0 ? gcd(b, a%b) : a;
        }
    int lcm(int a, int b)
        {
            return a * b / gcd(a, b);
        }
    int cnt(vector<int> num, int n, int m)
        {
            int x = lcm(num[n], num[m]), res = 0;
            vector<int> no;
            for (int i = 0; i < 5; i++) if (i != n && i != m) no.push_back(i);
            if (x % num[no[0]] == 0) res++;
            if (x % num[no[1]] == 0) res++;
            if (x % num[no[2]] == 0) res++;
            return res;
        }
    int leastMajorityMultiple( int a, int b, int c, int d, int e ) {
        int res = 1000000000;
        vector<int> num(5);
        num[0] = a;
        num[1] = b;
        num[2] = c;
        num[3] = d;
        num[4] = e;
        sort(num.begin(), num.end());

        for (int i = 4; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                int temp = cnt(num, i, j);
                int temp2 = lcm(num[i], num[j]);
                if (0 < temp && res > temp2) {
                    res = temp2;
                }
            }
        }
        return res;
    }
*/
    int leastMajorityMultiple(int a, int b, int c, int d, int e)
        {
            int i;
            for (i = 1;; i++) {
                int k = 0;
                k += i%a == 0;
                k += i%b == 0;
                k += i%c == 0;
                k += i%d == 0;
                k += i%e == 0;
                if (k >= 3) break;
            }
            return i;
        }  
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int a                     = 1;
			int b                     = 2;
			int c                     = 3;
			int d                     = 4;
			int e                     = 5;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 30;
			int b                     = 42;
			int c                     = 70;
			int d                     = 35;
			int e                     = 90;
			int expected__            = 210;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 30;
			int b                     = 45;
			int c                     = 23;
			int d                     = 26;
			int e                     = 56;
			int expected__            = 1170;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 3;
			int b                     = 14;
			int c                     = 15;
			int d                     = 92;
			int e                     = 65;
			int expected__            = 195;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int e                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int e                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			int e                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LeastMajorityMultiple().leastMajorityMultiple(a, b, c, d, e);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
