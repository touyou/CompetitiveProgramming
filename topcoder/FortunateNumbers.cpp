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

class FortunateNumbers {
public:
	string toStr(int n) {
		stringstream ss;
		ss << n;
		return ss.str();
	}
	bool fort(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '5' && s[i] != '8') return false;
		}
		return true;
	}
   int getFortunate( vector <int> a, vector <int> b, vector <int> c ) {
		vector<int> isnum;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				for (int k = 0; k < c.size(); k++) {
					int sum = a[i] + b[j] + c[k];
					if (fort(toStr(sum))) {
						if (isnum.empty()) {
							isnum.push_back(sum);
						} else {
							bool flag = true;
							for (int p = 0; p < isnum.size(); p++) {
								if (isnum[p] == sum) {
									flag = false;
									break;
								}
							}
							if (flag) isnum.push_back(sum);
						}
					}
				}
			}
		}
		return isnum.size();
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
			int a[]                   = { 1, 10, 100 };
			int b[]                   = { 3, 53 };
			int c[]                   = { 4, 54 };
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = { 47 };
			int b[]                   = { 500 };
			int c[]                   = { 33 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = { 100, 1, 10, 100, 1, 1 };
			int b[]                   = { 3, 53, 53, 53, 53, 53, 53 };
			int c[]                   = { 4, 54, 4, 54, 4, 54 };
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = { 500, 800 };
			int b[]                   = { 50, 80 };
			int c[]                   = { 5, 8 };
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = { 30000, 26264 };
			int b[]                   = { 30000, 29294 };
			int c[]                   = { 30000, 29594 };
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
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
