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

class Snowflakes {
public:
    vector <string> flareOut( vector <string> snowflake ) {
        int sz=snowflake.size();
        vector<string> half(sz);
        vector<string> qual(sz,"");
        vector<string> res(sz*2);
        for (int i=0; i<sz; i++) {
            for (int j=0; j<snowflake[i].length(); j++) qual[i]+=snowflake[i][j];
            for (int j=i+1; j<sz; j++) qual[i]+=snowflake[j][i];
        }
        for (int i=0; i<sz; i++) {
            string rev=qual[i];
            reverse(rev.begin(),rev.end());
            half[i]=rev+qual[i];
        }
        for (int i=0; i<sz; i++) {
            res[i]=half[sz-1-i];
        }
        for (int i=sz; i<sz*2; i++) {
            res[i]=half[i-sz];
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string snowflake[]        = {".",
 "..",
 "*.*"};
			string expected__[]       = {"*.**.*", "......", "*....*", "*....*", "......", "*.**.*" };

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string snowflake[]        = {"*",
 "..",
 ".*.",
 ".**.",
 ".*.**"};
			string expected__[]       = {"**.*..*.**", "*.**..**.*", ".*.*..*.*.", "***....***", "....**....", "....**....", "***....***", ".*.*..*.*.", "*.**..**.*", "**.*..*.**" };

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string snowflake[]        = {".",
 "..",
 "***"};
			string expected__[]       = {"******", "*....*", "*....*", "*....*", "*....*", "******" };

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string snowflake[]        = {"*",
 ".*",
 "***"};
			string expected__[]       = {"******", "**..**", "*.**.*", "*.**.*", "**..**", "******" };

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string snowflake[]        = {".",
 "..",
 "***",
 "...."};
			string expected__[]       = {"........", ".******.", ".*....*.", ".*....*.", ".*....*.", ".*....*.", ".******.", "........" };

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string snowflake[]        = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string snowflake[]        = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string snowflake[]        = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Snowflakes().flareOut(vector <string>(snowflake, snowflake + (sizeof snowflake / sizeof snowflake[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
