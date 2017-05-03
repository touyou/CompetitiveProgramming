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

class XorTravelingSalesman {
public:
  int dp[55][5555];
  int maxProfit( vector <int> cityValues, vector <string> roads ) {
    // 現在の価値 : p
    // 街の価値 : x
    // 次の価値 : p ^ x
    // 街はなんどでも通って良い、行ける価値と街、DP？
    // i-th element j-th character -> iからj
    vector<int> road[50];
    int c = cityValues.size();
    for (int i=0; i<c; i++) {
      for (int j=0; j<c; j++) {
        if (roads[i][j]=='Y') road[i].push_back(j);
      }
    }
    memset(dp, 0, sizeof(dp));
    int res = 0;
    queue<P> que;
    que.push(P(0,cityValues[0]));
    dp[0][cityValues[0]] = 1;
    while (!que.empty()) {
      P p = que.front(); que.pop();
      int npos = p.first;
      int val = p.second;
      for (int i=0; i<road[npos].size(); i++) {
        int j = road[npos][i];
        int nval = val ^ cityValues[j];
        if (dp[j][nval]) continue;
        dp[j][nval] = 1;
        que.push(P(j,nval));
      }
    }
    for (int i=0; i<c; i++) {
      for (int j=0; j<3333; j++) {
        if (dp[i][j]) res = max(res, j);
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
			int cityValues[]          = {0, 7, 11, 5, 2};
			string roads[]            = {"NYNYY",
 "YNYNN",
 "NYNNN",
 "YNNNN",
 "YNNNN"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int cityValues[]          = {556};
			string roads[]            = {"N"};
			int expected__            = 556;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int cityValues[]          = {0, 4, 8, 32, 512};
			string roads[]            = {"NYYYY",
 "YNNNN",
 "YNNNN",
 "YNNNN",
 "YNNNN"};
			int expected__            = 556;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int cityValues[]          = {37, 1, 19, 64, 42, 41, 64, 64, 54, 16, 256, 36, 64, 2, 4, 2, 62, 29, 58, 64, 1, 32, 16, 256, 17, 2, 17, 4, 1, 64, 21, 8, 256, 63, 3, 1, 43, 15, 8, 39, 41, 8, 16, 8, 16, 256, 64, 512, 45, 64};
			string roads[]            = {"NNNNNNYYYYNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNYYNNNYYNN",
 "NNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNNYNYNNNNNNYNNNNNNNNNNYNNNNNNNNNNN",
 "NNYNNNYNNNNNNNNYNNYNNNYYNNNYNYNNNNYNNNNNNNNYNNNNNN",
 "YNYNNYNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNYNN",
 "YNNYNNYNYNYYNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNNNNNNN",
 "YNNNNNNYNNNNNNNNNNNNNNYNYNNNNNNNNNNYYYNNNNNNNYNNNY",
 "YNNNNNNNNNNNNNNNNYNYNYNYYNNNYNNNNYNNNNNNNNNNNNNNNY",
 "NNNNNNNYNNNNYNNNNNNNNYYNNNYYNNNNYNYYNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNYNNNNYYNNNYNNYYNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNYNNNNNYNNNNYNNNNNNNNNNYNYNNYNYNNNYNYNNNN",
 "NNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNNYNN",
 "NNNNNNNNNNNYNNNNNYNYNNYYNNNNNYNNNNNNNNNYNNYNNYNNNN",
 "NNNNYYYNNNNNNYNNNYYNNYNNNYNYYNNNNNNNNNYYYNNYNNYNYN",
 "NYNNNNNNNNNNYNNNNNNNYNNNYYNNNYNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYYNNNNNNYNNNYNNNNNYNNYNYYNNNNYNNNYNN",
 "NNNYYYNNNNNNNNNYNNNNNYNYNYNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNYNNNNNNYNYYYNNNNNNNNNNNYNNYNNNNNYNNN",
 "NNNNYNNNNNNYNNNNYNNNNYNNNYYNNNYNNNYNNNNNNNNNNYNYNY",
 "NNNNNNNNNYYNYNNYNNYYYNYNNNNNNNNYNYNNNNNNNNNNYNNNNN",
 "NNNNNYNNYNYNNNYNNYNNNYNNNNNNNNNNNYNNYNYNNYNNNNNNNN",
 "NNNNNYNNNYNNNNYNNNYYNNNNNNNNNNNNNNNNNNNNNNYNNNYNNN",
 "NYNNNNNNYYNYNNNNYNNYNNNNNNNNNNYNNNNNNYNNNYNNYNNNNN",
 "NNNNNNNNNNNNNYNYYNYYYNNNNNNYNNNNNNNNNNNYYNNNNNNNYN",
 "NNNNNNNNNNYNNNNNNYNNYNNNNNNNNYNNNNYNNNNNNYYNNNNYNN",
 "NNNNYYNNNNYYNNNYNNNNNNNNNYNNNYYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNYNNNNNNNNNNNNNYNNNNYNNNNNNNNYNNYNYN",
 "NNNNNYNNNNNNNNYNYNNNNNNNNNYYYNNNNNNNNYNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNNNYNNYNNNNNYNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNYNYNNNNYNNNNNNNNNYNNNYNNNYYNNNNNYNNNYNNN",
 "NNNNNNNNNYNNNNNNNNNNNYYNNNNNNNYNNNNNNNYNNYNNNNNNNN",
 "NNNNNYNYNNYNYNNNYNYNYNNNNNYNYNNNNNNYYNYNYNYNNNNNYN",
 "YNNNNNYNYNYNNNNNNYNNNNNNNNNNNNNNYNYNNNNNYNNYNNNYNN",
 "NNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNYNYNNNNNNYNNNNNNYN",
 "NNNNNNNYYNNNYNNNNYNYNNNNYNNNNYNNNNNNNNNNNYNNNNYNNN",
 "NNNNYNNNNNNNNYNYNYNNNNYNNNNNNNNNNYYNNNNYNNNNNNNNNY",
 "NNNNNNNNNNNNYNYYNNNNNNNNNYNNNNNNNNNNNNYNNNNNYNYYNN",
 "NNNNNNNNNNNNNNNYNNNYNNNNNYNNNNNNNNYYNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNYNYNYNNNNNNYNNYYNNNNNNNNNNNN",
 "NYNNNNNNNNNYNNYNNNNNNNNYNNYNNYNYYNYNNNNNNNNNYNNNNN",
 "NNNNNYNNNNNNYNNYNYNNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNY",
 "NNNNNNYNNNNYNNNNNNNNNYNNYNNNNNNNNNNNNNNYNNYNNYNNNY",
 "NNNNNNNNYNNNYNYNNNNNYNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNYNNNYNNNYNNNNYNNNYNNNNYNYNNNNNNNNNN",
 "NYNNNNYNNNNNNYNNNYNNYNNNNNYNNNNNNNNYNNNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNNNNNNNNNYNNYNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNYYNNNNNNNNNNYNNNNNNNNNYNNNNNNNYNNNNYYNNNNN"};
			int expected__            = 895;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int cityValues[]          = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int cityValues[]          = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int cityValues[]          = ;
			string roads[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = XorTravelingSalesman().maxProfit(vector <int>(cityValues, cityValues + (sizeof cityValues / sizeof cityValues[0])), vector <string>(roads, roads + (sizeof roads / sizeof roads[0])));
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
