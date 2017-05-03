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

class BestView {
public:
    int numberOfBuildings( vector <int> heights ) {
        int sz=heights.size();
        int cnt[sz];
        fill(cnt, cnt+sz, 0);
        for (int i=0; i<sz; i++) {
            int mh=heights[i];
            for (int j=i+1; j<sz; j++) {
                if (mh<heights[i]) {
                    cnt[i]++;
                    mh=heights[i];
                } else if (mh==heights[i]) {
                    
            }
            mh=heights[i];
            for (int j=i-1; j>=0; j--) {
                if (mh<heights[i]) {
                    cnt[i]++;
                    mh=heights[i];
                } else if (mh==heights[i]) {
                    
        }
        int res=0;
        for (int i=0; i<sz; i++) res=max(res,cnt[i]);
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
			int heights[]             = {10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int heights[]             = {5,5,5,5};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int heights[]             = {1,2,7,3,2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int heights[]             = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int heights[]             = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int heights[]             = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
