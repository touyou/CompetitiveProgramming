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

class ColorfulChocolates {
public:
    int maximumSpread( string chocolates, int maxSwaps ) {
        set<char> chara;
        int sz=chocolates.length();
        for (int i=0; i<sz; i++) chara.insert(chocolates[i]);
        int ans=0;
        set<char>::iterator it;
        for (it=chara.begin(); it!=chara.end(); it++) {
            vector<int> adr, kyori;
            for (int i=0; i<sz; i++) if (chocolates[i]==(*it)) adr.push_back(i);
            if (adr.size()==1) {
                ans=max(ans, 1);
                continue;
            }
            int ret=1;
            for (int i=0; i<adr.size(); i++) {
                int sum=0;
                int cnt=1;
                bool f1=true, f2=true;
                for (int j=1; i-j>=0||i+j<adr.size(); j++) {
                    int a=0, b=0;
                    if (i+j<adr.size()&&f1) a=adr[i+j]-adr[i]-j;
                    else f1=false;
                    if (i-j<adr.size()&&f2) b=adr[i]-adr[i-j]-j;
                    else f2=false;
                    if (a<b) {
                        sum+=a;
                        if (f1&&sum<=maxSwaps) ret=max(ret, ++cnt);
                        else {
                            sum-=a;
                            f1=false;
                        }
                        sum+=b;
                        if (f2&&sum<=maxSwaps) ret=max(ret, ++cnt);
                        else {
                            sum-=b;
                            f2=false;
                        }
                    } else {
                        sum+=b;
                        if (f2&&sum<=maxSwaps) ret=max(ret, ++cnt);
                        else {
                            sum-=b;
                            f2=false;
                        }
                        sum+=a;
                        if (f1&&sum<=maxSwaps) ret=max(ret, ++cnt);
                        else {
                            sum-=a;
                            f1=false;
                        }
                    }
                }
            }
            ans=max(ans, ret);
        }
        return ans;
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
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string chocolates         = "ABCDCBC";
			int maxSwaps              = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string chocolates         = "ABBABABBA";
			int maxSwaps              = 4;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string chocolates         = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int maxSwaps              = 77;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string chocolates         = ;
			int maxSwaps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
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
