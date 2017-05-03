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

class CasketOfStarEasy {
public:
    int sz;
    bool used[10];
    vector<int> w;
    int dfs(int pos, int res) {
        used[pos]=true;
        int x=w.size()-1, y=0;
        for (int i=pos+1; i<sz; i++) if (!used[i]) {
            x=i;
            break;
        }
        for (int i=pos-1; i>=0; i--) if (!used[i]) {
            y=i;
            break;
        }
        res+=w[x]*w[y];
        //////////////
        bool end=true;
        for (int i=0; i<sz; i++) if (!used[i]) end=false;
        if (end) {
            used[pos]=false;
            return res;
        }
        //////////////
        int temp=res;
        for (int i=1; i<sz-1; i++) {
            if (!used[i]) res=max(res,dfs(i,temp));
        }
        used[pos]=false;
        return res;
    }
    int maxEnergy( vector <int> weight ) {
        sz=weight.size();
        w=weight;
        fill(used, used+sz, false);
        used[0]=used[sz-1]=true;
        int res=0;
        for (int i=1; i<sz-1; i++) {
            res=max(res, dfs(i,0));
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
			int weight[]              = {1,2,3,4};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int weight[]              = {100,2,1,3,100};
			int expected__            = 10400;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int weight[]              = {2,2,7,6,90,5,9};
			int expected__            = 1818;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int weight[]              = {477,744,474,777,447,747,777,474};
			int expected__            = 2937051;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int weight[]              = {1,1,1,1,1,1,1,1,1,1};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int weight[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int weight[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int weight[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CasketOfStarEasy().maxEnergy(vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
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
