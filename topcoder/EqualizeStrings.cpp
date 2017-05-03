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

class EqualizeStrings {
public:
   string getEq( string s, string t ) {
     string res="";
     for (int i=0; i<s.length(); i++) {
       char tmp='z'; int div=100;
       for (char c='a'; c<='z'; c++) {
	 int sdiv = min(abs(s[i]-c),26-abs(s[i]-c));
	 int tdiv = min(abs(t[i]-c),26-abs(t[i]-c));
	 if (sdiv+tdiv<div) {
	     //   printf("%d %d\n",sdiv,tdiv);
	     tmp=c;
	   div = sdiv+tdiv;
	 }
       }
       res+=tmp;
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
			string s                  = "cat";
			string t                  = "dog";
			string expected__         = "caa";

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "abcdefghijklmnopqrstuvwxyz";
			string t                  = "bcdefghijklmnopqrstuvwxyza";
			string expected__         = "abcdefghijklmnopqrstuvwxya";

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "programmingcompetitionsrule";
			string t                  = "programmingcompetitionsrule";
			string expected__         = "programmingcompetitionsrule";

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "topcoderopen";
			string t                  = "onlinerounds";
			string expected__         = "onlcndaoondn";

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			string t                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EqualizeStrings().getEq(s, t);
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
