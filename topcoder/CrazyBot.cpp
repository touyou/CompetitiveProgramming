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
#define EPS 1e-9

class CrazyBot {
public:
    double ep,wp,sp,np;
    double field[29][29];
    bool cnt[29][29];
    bool isin(int x, int y) {
        return x>=0&&x<29&&y>=0&&y<29;
    }
    void dfs(int n, int x, int y, double befp, int deg) {
        if (cnt[x][y]) return;
        cnt[x][y]=true;
        double p=0.0;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        if (deg==0) p=befp*ep;
        else if (deg==1) p=befp*wp;
        else if (deg==2) p=befp*sp;
        else if (deg==3) p=befp*np;
        if (--n==0) field[x][y]+=p;
        else {
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (isin(nx,ny)) dfs(n,nx,ny,p,i);
            }
        }
        cnt[x][y]=false;
        return;
    }
    double getProbability( int n, int east, int west, int south, int north ) {
        ep=east/100.0; wp=west/100.0; sp=south/100.0; np=north/100.0;
        // printf("%.2f %.2f %.2f %.2f\n",ep,wp,sp,np);
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        if (n==1) return 1.0;
        for (int i=0; i<29; i++) for (int j=0; j<29; j++) {
            cnt[i][j]=false;
            field[i][j]=0.0;
        }
        cnt[14][14]=true;
        for (int i=0; i<4; i++) {
            int nx=14+dx[i],ny=14+dy[i];
            if (isin(nx,ny)) dfs(n,nx,ny,1.0,i);
        }
        double res=0.0;
        for (int i=0; i<29; i++) for (int j=0; j<29; j++) {
            res+=field[i][j];
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int n                     = 1;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 0.75;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int east                  = 50;
			int west                  = 0;
			int south                 = 0;
			int north                 = 50;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 14;
			int east                  = 50;
			int west                  = 50;
			int south                 = 0;
			int north                 = 0;
			double expected__         = 1.220703125E-4;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 14;
			int east                  = 25;
			int west                  = 25;
			int south                 = 25;
			int north                 = 25;
			double expected__         = 0.008845493197441101;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int east                  = ;
			int west                  = ;
			int south                 = ;
			int north                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CrazyBot().getProbability(n, east, west, south, north);
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
