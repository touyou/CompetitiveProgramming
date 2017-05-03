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

class PlayGame {
public:
   int saveCreatures( vector <int> you, vector <int> computer ) {
    sort(you.begin(), you.end(), greater<int>());
    sort(computer.begin(), computer.end(), greater<int>());
    int t=0, res=0;
    for (int i=0; i<you.size(); i++) {
        for (;t<computer.size();t++) {
            if (computer[t]<you[i]) {
                res += you[i];
                t++;
                break;
            }
        }
        if (t==computer.size()) break;
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
			int you[]                 = {5, 15, 100, 1, 5};
			int computer[]            = {5, 15, 100, 1, 5};
			int expected__            = 120;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int you[]                 = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
			int computer[]            = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int you[]                 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
			int computer[]            = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
			int expected__            = 99;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int you[]                 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
			int computer[]            = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int you[]                 = {651, 321, 106, 503, 227, 290, 915, 549, 660, 115, 491, 378, 495, 789, 507, 381, 685, 530, 603, 394, 7, 704, 101, 620, 859, 490, 744, 495, 379, 781, 550, 356, 950, 628, 177, 373, 132, 740, 946, 609, 29, 329, 57, 636, 132, 843, 860, 594, 718, 849};
			int computer[]            = {16, 127, 704, 614, 218, 67, 169, 621, 340, 319, 366, 658, 798, 803, 524, 608, 794, 896, 145, 627, 401, 253, 137, 851, 67, 426, 571, 302, 546, 225, 311, 111, 804, 135, 284, 784, 890, 786, 740, 612, 360, 852, 228, 859, 229, 249, 540, 979, 55, 82};
			int expected__            = 25084;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int you[]                 = ;
			int computer[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int you[]                 = ;
			int computer[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int you[]                 = ;
			int computer[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PlayGame().saveCreatures(vector <int>(you, you + (sizeof you / sizeof you[0])), vector <int>(computer, computer + (sizeof computer / sizeof computer[0])));
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
