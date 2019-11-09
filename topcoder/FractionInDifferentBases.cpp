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
#define PI 3.1415926    



class FractionInDifferentBases {
public:
    ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
   long long getNumberOfGoodBases( long long P, long long Q, long long A, long long B ) {
        vector<int> isp(1000001,1);
        vector<ll> p;
        isp[0]=isp[1]=0;
        for (ll i=2; i<1000001; i++) {
            if (isp[i]) {
                p.push_back(i);
                for (ll j=i*2; j<1000001; j+=i) isp[j]=0;
            }
        }
        int sz=p.size();
        ll r=1, g=gcd(P,Q);
        Q/=g;
        for (int i=0; i<sz; i++) {
            if (Q%p[i]==0) {
                while (Q%p[i]==0) Q/=p[i];
                r*=p[i];
            }
        }
        r*=Q;
        return (B-A+1)-(B/r-(A-1)/r);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long P               = 1;
			long long Q               = 2;
			long long A               = 10;
			long long B               = 10;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long P               = 1;
			long long Q               = 9;
			long long A               = 9;
			long long B               = 10;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long P               = 5;
			long long Q               = 6;
			long long A               = 2;
			long long B               = 10;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long P               = 2662;
			long long Q               = 540;
			long long A               = 2;
			long long B               = 662;
			long long expected__      = 639;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long P               = 650720;
			long long Q               = 7032600;
			long long A               = 2012;
			long long B               = 2012540;
			long long expected__      = 2010495;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long P               = ;
			long long Q               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FractionInDifferentBases().getNumberOfGoodBases(P, Q, A, B);
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
