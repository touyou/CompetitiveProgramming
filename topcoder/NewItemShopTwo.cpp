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

class NewItemShopTwo {
public:
	vector<string> split(string str, char del) {
		vector<string> res;
		int cutAt;
		while ((cutAt = str.find_first_of(del)) != str.npos) {
			if (cutAt > 0) res.push_back(str.substr(0, cutAt));
			str = str.substr(cutAt + 1);
		}
		if (str.length() > 0) res.push_back(str);
		return res;
	}
	double getMaximum( vector <string> customers ) {
		vector<string> cst1, cst2;
		cst1 = split(customers[0], ' ');
		cst2 = split(customers[1], ' ');

		double res = 0.0;
		for (int i = 0; i < cst1.size(); i++) {
			const char *temp;
			*temp = cst1[i].c_str();
			int t1, c1, p1, t2, c2, p2;
			sscanf(temp, "%d%*c%d%*c%d", &t1, &c1, &p1);
			for (int j = 0; j < cst2.size(); j++) {
				*temp = cst2[j].c_str();
				sscanf(temp, "%d%*c%d%*c%d", &t2, &c2, &p2);
				int m = max(c1, c2);
				res += m * (double)(p1+p2) / 100;
			}
		}
		return res;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string customers[]        = { "8,1,80 16,100,11", "12,10,100" };
			double expected__         = 19.0;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string customers[]        = { "8,1,80 16,100,11", "12,10,90 13,30,5" };
			double expected__         = 19.4;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string customers[]        = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
			double expected__         = 90.0;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string customers[]        = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" };
			double expected__         = 95.0;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string customers[]        = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
;
			double expected__         = 3.0692999999999997;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string customers[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string customers[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string customers[]        = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = NewItemShopTwo().getMaximum(vector <string>(customers, customers + (sizeof customers / sizeof customers[0])));
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
