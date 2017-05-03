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

class MatchString {
public:
    int placeWords( string matchString, vector <string> matchWords ) {
	  vector<int> ismatch[50];
	  int n = matchString.length();
	  memset(ismatch, 0, sizeof(ismatch));
	  bool flag=true;
	  for (int i=0; i<n; i++) {
		bool flag2=false;
		for (int j=0; j<matchWords[i].length(); j++) {
		  if (matchString[i]==matchWords[i][j]) {
			flag2=true;
			ismatch[i].push_back(j);
		  }
		}
		if (!flag2) flag=false;
	  }
	  // puts("ok");
	  if (!flag) return -1;
	  int res = INT_MAX / 2;
	  for (int l=0; l<n; l++) {
		for (int i=0; i<ismatch[l].size(); i++) {
		  int adr = ismatch[l][i];
		  int temp = 0;
		  bool flag = true;
		  for (int j=0; j<n; j++) {
			if (l==j) continue;
			int mins = INT_MAX / 2;
			for (int k=0; k<ismatch[j].size(); k++) {
			  if (adr < ismatch[j][k]) break; 
			  mins = min(mins, abs(ismatch[j][k]-adr));
			}
			if (mins==INT_MAX/2) {
			  flag = false;
			  break;
			}
			temp += mins;
		  }
		  if (flag) res = min(res, temp);
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
			string matchString        = "TOP";
			string matchWords[]       = {"TIK", 
 "PPPO", 
 "OP"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string matchString        = "EEA";
			string matchWords[]       = {"GEGA", 
 "TOPCODER", 
 "TEST"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string matchString        = "AB";
			string matchWords[]       = {"ABA", 
 "ABAB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string matchString        = "FIND";
			string matchWords[]       = {"VERYFAST", 
 "OPINION", 
 "SPENDING", 
 "ODD"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string matchString        = "TOP";
			string matchWords[]       = {"OUTTHERE", 
 "FROM", 
 "NOPQRSTU"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string matchString        = ;
			string matchWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string matchString        = ;
			string matchWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string matchString        = ;
			string matchWords[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatchString().placeWords(matchString, vector <string>(matchWords, matchWords + (sizeof matchWords / sizeof matchWords[0])));
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
