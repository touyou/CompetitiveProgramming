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

class FavouriteDigits {
public:
   long long findNext( long long N, int dg1, int cnt1, int dg2, int cnt2 ) {
        if (dg1==0&&dg2==0) return N;
        ll temp=N;
        int keta=0;
        while (temp>0) {
            temp/=10; keta++;
        }
        if (cnt1+cnt2>keta) {
            ll res=0;
            if (dg1>dg2) {
                if (cnt2!=0) {
                    res+=dg2; cnt2--;
                }
                while (cnt2>0) {
                    res*=10;
                    res+=dg2;
                }
                while (cnt1>0) {
                    res*=10;
                    dg1;
                }
            } else {
                if (cnt1!=0) {
                    res+=dg1; cnt1--;
                }
                while (cnt1>0) {
                    res*=10;
                    res+=dg1;
                }
                while (cnt2>0) {
                    res*=10;
                    dg2;
                }
            }
            return res;
        } else {
            ll res=0;
            if (dg1>dg2) {
                if (cnt2!=0) {
                    res+=dg2; cnt2--;
                }
                while (cnt2>0) {
                    res*=10;
                    res+=dg2;
                }
                while (cnt1>0) {
                    res*=10;
                    dg1;
                }
            } else {
                if (cnt1!=0) {
                    res+=dg1; cnt1--;
                }
                while (cnt1>0) {
                    res*=10;
                    res+=dg1;
                }
                while (cnt2>0) {
                    res*=10;
                    dg2;
                }
            }
            ll temp=N;
            int c1=0, c2=0;
            for (int i=0; i<keta; i++) {
                int x=temp%10;
                if (x==dg1) c1++;
                if (x==dg2) c2++;
                temp=(temp-x)/10;
            }
            if (c1==cnt1&&c2==cnt2) res=N;
            else {
                
        }
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
			long long N               = 47;
			int digit1                = 1;
			int count1                = 0;
			int digit2                = 2;
			int count2                = 0;
			long long expected__      = 47;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long N               = 47;
			int digit1                = 5;
			int count1                = 0;
			int digit2                = 9;
			int count2                = 1;
			long long expected__      = 49;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long N               = 47;
			int digit1                = 5;
			int count1                = 0;
			int digit2                = 3;
			int count2                = 1;
			long long expected__      = 53;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long N               = 47;
			int digit1                = 2;
			int count1                = 1;
			int digit2                = 0;
			int count2                = 2;
			long long expected__      = 200;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long N               = 123456789012345LL;
			int digit1                = 1;
			int count1                = 2;
			int digit2                = 2;
			int count2                = 4;
			long long expected__      = 123456789012422LL;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			long long N               = 92;
			int digit1                = 1;
			int count1                = 1;
			int digit2                = 0;
			int count2                = 0;
			long long expected__      = 100;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long N               = ;
			int digit1                = ;
			int count1                = ;
			int digit2                = ;
			int count2                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long N               = ;
			int digit1                = ;
			int count1                = ;
			int digit2                = ;
			int count2                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long N               = ;
			int digit1                = ;
			int count1                = ;
			int digit2                = ;
			int count2                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
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
