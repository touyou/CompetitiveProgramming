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
typedef pair<int, int> P;
typedef vector<int> vi;
typedef long long ll;
#define EPS 1e-9
#define PI 3.14159265358979

class MagicalGirl {
public:
    double maxExpectation( int M, vector <int> day, vector <int> win, vector <int> gain ) {
        int N=day.size();
        pair<int, P> witch[N];
        for (int i=0; i<N; i++) {
            witch[i]=make_pair(day[i],P(win[i],gain[i]));
        }
        sort(witch, witch+N);
        double dp[N+1][2];
        for (int i=0; i<=N; i++) {
            dp[i][0]=dp[i][1]=0;
        }
        dp[0][0]=dp[0][1]=M;
        for (int i=1; i<=N; i++) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            // gonyo gonyo
            // pi pikachu
            // hoge hoge
        }
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
			int M                     = 2;
			int day[]                 = {1};
			int win[]                 = {75};
			int gain[]                = {1};
			double expected__         = 2.5;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int M                     = 10;
			int day[]                 = {5,5,5,5};
			int win[]                 = {100,100,100,100};
			int gain[]                = {1,1,1,1};
			double expected__         = 14.0;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int M                     = 10;
			int day[]                 = {5,5,5,5,5};
			int win[]                 = {40,80,60,20,0};
			int gain[]                = {10,10,10,10,10};
			double expected__         = 13.0;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int M                     = 2;
			int day[]                 = {2};
			int win[]                 = {100};
			int gain[]                = {2};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int M                     = 20;
			int day[]                 = {2,13,8,7,9,4,6,21};
			int win[]                 = {18,83,75,23,45,23,10,98};
			int gain[]                = {10,9,8,10,7,16,13,20};
			double expected__         = 35.908;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int M                     = 11;
			int day[]                 = {10,20,30,40,50,60,70,80,90};
			int win[]                 = {100,100,100,100,100,100,100,100,100};
			int gain[]                = {10,10,10,10,10,10,10,10,10};
			double expected__         = 101.0;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int M                     = 100000;
			int day[]                 = {1000000};
			int win[]                 = {100};
			int gain[]                = {100000};
			double expected__         = 100000.0;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int M                     = ;
			int day[]                 = ;
			int win[]                 = ;
			int gain[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int M                     = ;
			int day[]                 = ;
			int win[]                 = ;
			int gain[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int M                     = ;
			int day[]                 = ;
			int win[]                 = ;
			int gain[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicalGirl().maxExpectation(M, vector <int>(day, day + (sizeof day / sizeof day[0])), vector <int>(win, win + (sizeof win / sizeof win[0])), vector <int>(gain, gain + (sizeof gain / sizeof gain[0])));
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
