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

class TheBrickTowerMediumDivTwo {
public:
  vector <int> find( vector <int> heights ) {
	vector<P> perm;
	int n = heights.size();
	for (int i=0; i<n; i++) {
	  perm.push_back(P(i,heights[i]));
	}
	sort(perm.begin(), perm.end());
	vector<int> res;
	int ans = INT_MAX;
	do {
	  int temp = 0;
	  for (int i=0; i<n-1; i++) {
		temp += max(perm[i].second, perm[i+1].second);
	  }
	  if (temp < ans) {
		res.resize(0);
		ans=temp;
		for (int i=0; i<n; i++) {
		  res.push_back(perm[i].first);
		}
	  }
	} while(next_permutation(perm.begin(), perm.end()));
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
			int heights[]             = {4, 7, 5};
			int expected__[]          = {0, 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int heights[]             = {4, 4, 4, 4, 4, 4, 4};
			int expected__[]          = {0, 1, 2, 3, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int heights[]             = {2, 3, 3, 2};
			int expected__[]          = {0, 3, 1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int heights[]             = {13, 32, 38, 25, 43, 47, 6};
			int expected__[]          = {0, 6, 3, 1, 2, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int heights[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int heights[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int heights[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivTwo().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
