#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <ctime>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 1e-9
#define PI 3.14159265358979

class MonstersValley {
public:
   int minimumPrice( vector<long long> dread, vector <int> price ) {
       ll dp[100][200];
       int pos[100][200];
       memset(dp, 0, sizeof(dp));
       memset(pos, 0, sizeof(pos));
       pos[0][0]=1;
       int n=dread.size();
       
       for (int i=0; i<n; i++) {
           for (int j=0; j<110; j++) {
               if (pos[i][j]) {
                   dp[i+1][j+price[i]] = max(dp[i+1][j+price[i]], dp[i][j]+dread[i]);
                   pos[i+1][j+price[i]] = 1;
                   if (dread[i]<=dp[i][j]) {
                       dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
                       pos[i+1][j] = 1;
                   }
               }
           }
       }
       
       for (int i=0; i<110; i++) if (pos[n][i]==1) return i;
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
			long long dread[]         = {8, 5, 10};
			int price[]               = {1, 1, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long dread[]         = {1, 2, 4, 1000000000};
			int price[]               = {1, 1, 1, 2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long dread[]         = {200, 107, 105, 206, 307, 400};
			int price[]               = {1, 2, 1, 1, 1, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long dread[]         = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
			int price[]               = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long dread[]         = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long dread[]         = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long dread[]         = ;
			int price[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MonstersValley().minimumPrice(vector<long long>(dread, dread + (sizeof dread / sizeof dread[0])), vector <int>(price, price + (sizeof price / sizeof price[0])));
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
