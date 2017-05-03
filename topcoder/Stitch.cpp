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

class Stitch {
public:
    vector <string> stitch( vector <string> A, vector <string> B, int overlap ) {
        int spos=A[0].length()-overlap;
        vector<string> res(A.size(), "");
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<spos; j++) res[i]+=A[i][j];
            for (int j=spos; j<A[i].length(); j++) {
                int x=j-spos;
                char rc=(char)((((overlap-x)*(int)A[i][j]+((x+1)*(int)B[i][x]))+overlap) / (overlap+1));
                if ((((overlap-x)*(int)A[i][j]+((x+1)*(int)B[i][x]))+overlap)%(overlap+1)<(overlap+2)/2-1) rc--;
                res[i]+=rc;
            }
            for (int j=overlap; j<B[i].length(); j++) {
                res[i]+=B[i][j];
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
			string A[]                = {"AAAAAA"};
			string B[]                = {"JJJJJ"};
			int overlap               = 4;
			string expected__[]       = { "AACEFHJ" };

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string A[]                = {"14ABCD",
 "25EFGH",
 "36IJKL"};
			string B[]                = {"ABCD14",
 "EFGH25",
 "IJKL36"};
			int overlap               = 4;
			string expected__[]       = { "14ABCD14",  "25EFGH25",  "36IJKL36" };

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string A[]                = {" 32ygfd",
 "3uh53G:",
 ")O83gh3"};
			string B[]                = {"hsd$*(PH",
 "3G:$)(*P",
 "gh86$PBB"};
			int overlap               = 3;
			string expected__[]       = { " 32ygmd$*(PH",  "3uh53G:$)(*P",  ")O83gh76$PBB" };

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string A[]                = {"A"};
			string B[]                = {"A"};
			int overlap               = 0;
			string expected__[]       = { "AA" };

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string A[]                = ;
			string B[]                = ;
			int overlap               = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string A[]                = ;
			string B[]                = ;
			int overlap               = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string A[]                = ;
			string B[]                = ;
			int overlap               = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = Stitch().stitch(vector <string>(A, A + (sizeof A / sizeof A[0])), vector <string>(B, B + (sizeof B / sizeof B[0])), overlap);
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
