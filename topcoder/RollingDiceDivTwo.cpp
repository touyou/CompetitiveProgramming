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

class RollingDiceDivTwo {
public:
    int minimumFaces( vector <string> rolls ) {
        int res=0;
        for (int i=0; i<rolls.size(); i++) {
            sort(rolls[i].begin(), rolls[i].end());
        }
        int mins[50];
        fill(mins, mins+50, 0);
        for (int i=0; i<rolls[0].length(); i++) {
            for (int j=0; j<rolls.size(); j++) {
                mins[i]=max(mins[i], rolls[j][i]-'0');
            }
            res+=mins[i];
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
			string rolls[]            = {"137", "364", "115", "724"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string rolls[]            = {"1112", "1111", "1211", "1111"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string rolls[]            = {"24412", "56316", "66666", "45625"};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string rolls[]            = {"931", "821", "156", "512", "129", "358", "555"};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string rolls[]            = {"3", "7", "4", "2", "4"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string rolls[]            = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"};
			int expected__            = 176;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string rolls[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string rolls[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string rolls[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RollingDiceDivTwo().minimumFaces(vector <string>(rolls, rolls + (sizeof rolls / sizeof rolls[0])));
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
