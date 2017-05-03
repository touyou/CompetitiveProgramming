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
#define PI 3.14159265358979

class StandInLine {
public:
   vector <int> reconstruct( vector <int> left ) {
    vector<P> sold(left.size());
    vi res(left.size());
    for (int i=0; i<left.size(); i++) {
        sold[i].first=left[i];
        sold[i].second=i+1;
    }
    sort(sold.begin(), sold.end());
    for (int i=0; i<left.size(); i++) {
        int cnt=0;
        for (int j=i; j>=0; j--) if (sold[i].second<sold[j].second) cnt++;
        if (sold[i].first > cnt) {
            swap(sold[i], sold[i+1]);
            i--;
        } else if (sold[i].first < cnt) {
            swap(sold[i], sold[i-1]);
            i-=2;
        }
    }
    for (int i=0; i<left.size(); i++) res[i]=sold[i].second;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int left[]                = {2, 1, 1, 0 };
			int expected__[]          = {4, 2, 1, 3 };

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int left[]                = {0, 0, 0, 0, 0 };
			int expected__[]          = {1, 2, 3, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int left[]                = {5, 4, 3, 2, 1, 0 };
			int expected__[]          = {6, 5, 4, 3, 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int left[]                = {6, 1, 1, 1, 2, 0, 0 };
			int expected__[]          = {6, 2, 3, 4, 7, 5, 1 };

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int left[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int left[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int left[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StandInLine().reconstruct(vector <int>(left, left + (sizeof left / sizeof left[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
