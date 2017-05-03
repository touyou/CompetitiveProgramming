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

class Over9000Rocks {
public:
    // lower<=X<=upper
    int sz;
    vector<P> res;
    vector<int> low, up;
    bool used[15];
    void dfs(int l, int u, int cnt) {
        if (cnt==sz) {
            if (l>9000||u>9000) res.push_back(P(l,u));
            return;
        }
        for (int i=0; i<sz; i++) {
            if (!used[i]) {
                used[i]=true;
                dfs(l+low[i],u+up[i],cnt+1);
                dfs(l,u,cnt+1);
                used[i]=false;
            }
        }
    }
    int countPossibilities( vector <int> lowerBound, vector <int> upperBound ) {
        low=lowerBound; up=upperBound;
        sz=low.size();
        memset(used, 0, sizeof(used));
        // dfs(0,0,0);
        for (int i=0; i<(1<<sz); i++) {
            int l=0, u=0;
            for (int j=0; j<sz; j++) {
                if (i>>j&1) {
                    l+=low[j];
                    u+=up[j];
                }
            }
            if (l>9000||u>9000) res.push_back(P(l,u));
        }
        sort(res.begin(), res.end());
        vector<P> r;
        int px=-1;
        for (int i=0; i<res.size(); i++) {
            if (px==-1) {
                r.push_back(res[i]);
                px=0;
            } else {
                P p=r[px];
                if (p.first<=res[i].first&&res[i].first<=p.second) {
                    r[px].second=max(p.second,res[i].second);
                } else {
                    r.push_back(res[i]);
                    px++;
                }
            }
        }
        int res=0;
        for (int i=0; i<r.size(); i++) {
            if (r[i].first<=9000) res+=r[i].second-9000;
            else res+=r[i].second-r[i].first+1;
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
			int lowerBound[]          = {9000};
			int upperBound[]          = {9001};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int lowerBound[]          = {9000, 1, 10};
			int upperBound[]          = {9000, 2, 20};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int lowerBound[]          = {1001, 2001, 3001, 3001};
			int upperBound[]          = {1003, 2003, 3003, 3003};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int lowerBound[]          = {9000,90000,1,10};
			int upperBound[]          = {9000,90000,3,15};
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int lowerBound[]          = {1,1,1,1,1,1};
			int upperBound[]          = {3,4,5,6,7,8};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int lowerBound[]          = ;
			int upperBound[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Over9000Rocks().countPossibilities(vector <int>(lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int>(upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
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
