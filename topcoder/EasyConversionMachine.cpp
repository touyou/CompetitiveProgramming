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

class EasyConversionMachine {
public:
   string isItPossible( string originalWord, string finalWord, int k ) {
        int cnt=0, len=originalWord.length();
        for (int i=0; i<len; i++) {
            if (originalWord[i]!=finalWord[i]) cnt++;
        }
        if (cnt<=k&&(k-cnt)%2==0) return "POSSIBLE";
        else return "IMPOSSIBLE";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string originalWord       = "aababba";
			string finalWord          = "bbbbbbb";
			int k                     = 2;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string originalWord       = "aabb";
			string finalWord          = "aabb";
			int k                     = 1;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string originalWord       = "aaaaabaa";
			string finalWord          = "bbbbbabb";
			int k                     = 8;
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string originalWord       = "aaa";
			string finalWord          = "bab";
			int k                     = 4;
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string originalWord       = "aababbabaa";
			string finalWord          = "abbbbaabab";
			int k                     = 9;
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string originalWord       = ;
			string finalWord          = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyConversionMachine().isItPossible(originalWord, finalWord, k);
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
