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
#define inf INT_MAX/2
class VolumeDiscount {
public:
    int bestDeal( vector <string> priceList, int quantity ) {
        int sz=priceList.size(), q=quantity;
        int w[sz], p[sz];
        int dp[sz+1][q+1];
        // init
        for (int i=0; i<sz; i++) {
            fill(dp[i],dp[i]+q+1,inf);
            int j; string x="";
            for (j=0; j<priceList[i].length(); j++) {
                if (priceList[i][j]==' ') {
                    stringstream ss;
                    ss<<x; ss>>w[i]; x=""; j++;
                    break;
                }
                x+=priceList[i][j];
            }
            for (;j<priceList[i].length();j++) {
                x+=priceList[i][j];
            }
            stringstream ss;
            ss<<x; ss>>p[i];
        }
        fill(dp[sz],dp[sz]+q+1,inf);
        // end;
        dp[0][0]=0;
        for (int i=0; i<sz; i++) {
            for (int j=0; j<=q; j++) {
                if (j<w[i]) {
                    dp[i+1][j]=min(dp[i][j],p[i]);
                } else {
                    dp[i+1][j]=min(dp[i][j],dp[i+1][j-w[i]]+p[i]);
                }
            }
        }
        return dp[sz][q];
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
			string priceList[]        = {"1 10", "5 45"};
			int quantity              = 10;
			int expected__            = 90;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string priceList[]        = {"1 8", "5 45"};
			int quantity              = 10;
			int expected__            = 80;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string priceList[]        = {"99 913", "97 173", "50 464", "80 565"} 	;
			int quantity              = 18;
			int expected__            = 173;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string priceList[]        = {"2 272","1 166","10 993"};
			int quantity              = 81;
			int expected__            = 8110;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string priceList[]        = ;
			int quantity              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string priceList[]        = ;
			int quantity              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string priceList[]        = ;
			int quantity              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeDiscount().bestDeal(vector <string>(priceList, priceList + (sizeof priceList / sizeof priceList[0])), quantity);
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
