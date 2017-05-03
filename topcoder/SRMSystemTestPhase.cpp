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
#define MOD 1000000007

class SRMSystemTestPhase {
public:
	int C (int n, int m) {
		int res=1;
		if (n == m) return res;
		for (int i=n; i>=n-m+1; i--) res *= i;
		for (int i=m; i>=1; i--) res /= i;
		return res;
	}
	int dfs(vector<string> des,int bef,int s,int res) {
		int cnt=0;
		int temp=res;
		for (int i=0; i<3; i++) if (des[s][i]=='Y') cnt++;
		if (des.size()-1==s) {
			if (cnt<=bef) {
				return (int)pow(3.0,(double)cnt);
			} else {
				int r=1;
				for (int i=0; i<cnt-bef; i++) r*=2;
				return (int)pow(3.0,(double)bef)*r;
			}
		}
		if (cnt <= bef) {
			for (int i=0; i<=cnt; i++) {
				res+=C(cnt,cnt-i)*(cnt-i)*2*dfs(des,i,s+1,temp)%MOD;
				printf("%d\n" ,res);
			}
		} else {
			for (int i=0; i<=bef; i++) {
				res+=C(cnt,cnt-i)*(cnt-i)*2*dfs(des,i,s+1,temp)%MOD;
			}
		}
		return res;
	}
   int countWays( vector <string> des ) {
		int res = 0;
		return dfs(des,3,0,res)%MOD;
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
			string description[]      = {"YYY"};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string description[]      = {"YNN",
 "NYN"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string description[]      = {"YNN",
 "NNN",
 "NNY"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string description[]      = {"NNN",
 "NNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string description[]      = {"YYY",
 "YNY",
 "NYY",
 "YYN",
 "YYY",
 "YNN"};
			int expected__            = 15176;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
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
