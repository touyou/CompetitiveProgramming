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
#define PI 3.14159265358979

class P8XCoinChangeAnother {
public:
   vector<long long> solve( int N, long long coins_sum, long long coins_count ) {
    vector<ll> score(N), res(N, 0), nul;
    score[0]=1;
    for (int i=1; i<score.size(); i++) score[i] = score[i-1]*2;
    ll rim = coins_count, t = coins_sum;
    for (int i=N-1; i>=0; i--) {
        if (score[i]<=t) {
            ll temp = t / score[i];
            res[i] = min(temp, rim);
            rim -= res[i];
            t -= res[i]*score[i];
        }
    }
    if (rim!=0) {
        for (int i=N-1; i>0; i--) if (res[i]!=0) {
            ll x = min(rim, res[i]);
            res[i] -= x;
            res[i-1] += x*2;
            rim -= x;
            if (rim==0) break;
        }
        if (rim!=0) return nul;
        else return res;
    }
    else if (t!=0) return nul;
    else return res;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
			int N                     = 2;
			long long coins_sum       = 4;
			long long coins_count     = 3;
			long long expected__[]    = {2, 1};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			long long coins_sum       = 6;
			long long coins_count     = 3;
			long long expected__[]    = {0, 3, 0};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			long long coins_sum       = 8;
			long long coins_count     = 1;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			long long coins_sum       = 10000000000LL;
			long long coins_count     = 10000000000LL;
			long long expected__[]    = {10000000000LL};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			long long coins_sum       = ;
			long long coins_count     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			long long coins_sum       = ;
			long long coins_count     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			long long coins_sum       = ;
			long long coins_count     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
