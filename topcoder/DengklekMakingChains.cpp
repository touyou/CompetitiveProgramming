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

class DengklekMakingChains {
public:
    int maxBeauty( vector <string> chains ) {
        int res=0, maxr=0, maxl=0;
        vector<string> reserve;
        vector<int> num;
        for (int i=0; i<chains.size(); i++) {
            if (chains[i][0]!='.'&&chains[i][1]!='.'&&chains[i][2]!='.') {
                res+=(chains[i][0]-'0')+(chains[i][1]-'0')+(chains[i][2]-'0');
            } else if (chains[i][0]=='.'&&chains[i][2]!='.') {
                int sum=chains[i][2]-'0';
                if (chains[i][1]!='.') sum+=chains[i][1]-'0';
                maxl=max(maxl,sum);
            } else if (chains[i][2]=='.'&&chains[i][0]!='.') {
                int sum=chains[i][0]-'0';
                if (chains[i][1]!='.') sum+=chains[i][1]-'0';
                maxr=max(maxr,sum);
            } else if (chains[i][0]!='.'&&chains[i][2]!='.') {
                reserve.push_back(chains[i]);
            } else if (chains[i][1]!='.') {
                num.push_back(chains[i][1]-'0');
            }
        }
        int res2=0;
        if (num.size()!=0) {
            sort(num.begin(), num.end());
            res2=num[num.size()-1];
        }
        for (int i=0; i<reserve.size(); i++) {
            int l=reserve[i][2]-'0';
            int r=reserve[i][0]-'0';
            if (maxl<l&&maxr>=r) maxl=l;
            else if (maxl>=l&&maxr<r) maxr=r;
            else if (maxl<l&&maxr<r) {
                if (l-maxl>r-maxr) maxl=l;
                else if (l-maxl<r-maxr) maxr=r;
                else if (l<r) maxr=r;
                else maxl=l;
            }
        }
        return max(res+maxl+maxr,res2);
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
			string chains[]           = {".15", "7..", "402", "..3"};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string chains[]           = {"..1", "7..", "567", "24.", "8..", "234"};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string chains[]           = {"...", "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string chains[]           = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string chains[]           = {"..1", "3..", "2..", ".7."};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string chains[]           = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
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
