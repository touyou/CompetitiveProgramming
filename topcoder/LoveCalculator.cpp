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

class LoveCalculator {
public:
    void count(int *cnt, string name) {
        fill(cnt, cnt+4, 0);
        for (int i=0; i<name.length(); i++) {
            if (name[i]=='L') cnt[0]++;
            if (name[i]=='O') cnt[1]++;
            if (name[i]=='V') cnt[2]++;
            if (name[i]=='E') cnt[3]++;
        }
    }
    string findBoy( string girl, vector <string> boys ) {
        int cnt[4];
        count(cnt, girl);
        int mp=-1;
        string res="";
        sort(boys.begin(), boys.end());
        for (int i=0; i<boys.size(); i++) {
            int temp[4];
            count(temp, boys[i]);
            for (int j=0; j<4; j++) temp[j]+=cnt[j];
            int r=((temp[0]+temp[1])*(temp[0]+temp[2])*(temp[0]+temp[3])*(temp[1]+temp[2])*(temp[1]+temp[3])*(temp[2]+temp[3]))%100;
            if (mp<r) {
                mp=r;
                res=boys[i];
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
			string girl               = "LOVE";
			string boys[]             = {"JACOB","FRANK","DANO"};
			string expected__         = "FRANK";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string girl               = "JANE";
			string boys[]             = {"THOMAS","MICHAEL","INDY","LIU"};
			string expected__         = "INDY";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string girl               = "LILLY";
			string boys[]             = {"PIERRE"};
			string expected__         = "PIERRE";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string girl               = "MERYLOV";
			string boys[]             = {"JOHN","DAVE","STEVE","JOHN","DAVE"};
			string expected__         = "DAVE";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string girl               = "LLOL";
			string boys[]             = {"BVERON","CVERON","AVERON","DVERON"};
			string expected__         = "AVERON";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string girl               = "VELYLEOCEVE";
			string boys[]             = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"};
			string expected__         = "VLOLUVCBLLQVESWHEEKC";

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string girl               = ;
			string boys[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string girl               = ;
			string boys[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string girl               = ;
			string boys[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LoveCalculator().findBoy(girl, vector <string>(boys, boys + (sizeof boys / sizeof boys[0])));
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
