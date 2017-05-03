#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;

class PalindromeDecoding {
public:
   string decode( string code, vector <int> position, vector <int> length ) {
       for (int i=0; i<position.size(); i++) {
           string str = code.substr(position[i], length[i]);
           reverse(str.begin(), str.end());
           code.insert(position[i]+length[i], str);
       }
       return code;
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
			string code               = "ab";
			int position[]            = {0};
			int length[]              = {2};
			string expected__         = "abba";

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string code               = "Misip";
			int position[]            = {2,3,1,7};
			int length[]              = {1,1,2,2};
			string expected__         = "Mississippi";

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string code               = "XY";
			int position[]            = {0, 0, 0, 0};
			int length[]              = {2, 4, 8, 16};
			string expected__         = "XYYXXYYXXYYXXYYXXYYXXYYXXYYXXYYX";

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string code               = "TC206";
			int position[]            = {1,2,5};
			int length[]              = {1,1,1};
			string expected__         = "TCCC2006";

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string code               = "nodecoding";
			int position[]            = {};
			int length[]              = {};
			string expected__         = "nodecoding";

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string code               = ;
			int position[]            = ;
			int length[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string code               = ;
			int position[]            = ;
			int length[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string code               = ;
			int position[]            = ;
			int length[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PalindromeDecoding().decode(code, vector <int>(position, position + (sizeof position / sizeof position[0])), vector <int>(length, length + (sizeof length / sizeof length[0])));
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
