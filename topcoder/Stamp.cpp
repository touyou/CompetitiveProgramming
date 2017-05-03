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

class Stamp {
public:
    string dc;
    vector<P> vc;
    int sc, pc, code[50];
    int getMinimumCost( string desiredColor, int stampCost, int pushCost ) {
        int n = desiredColor.length();
        dc = desiredColor;
        sc = stampCost; pc = pushCost;

        bool flag = false;
        for (int i=0; i<n; i++) {
            if (dc[i] == 'R') code[i] = 0;
            else if (dc[i] == 'G') code[i] = 1;
            else if (dc[i] == 'B') code[i] = 2;
            else {
                code[i] = -1;
                flag = true;
            }
        }

        vec.push_back(P(code[0], 1));
        int mcost = INT_MAX;
        for (int i=1; i<n; i++) {
            if (vec[vec.size()-1].first==code[i])
                vec[vec.size()-1].second++;
            else {
                mcost = min(mcost, vec[vec.size()-1].second);
                vec.push_back(P(code[i], 1));
            }
        }
        int res = INT_MAX;
        if (flag) {
            deque<P> deq;
            for (int i=0; i<vec.size(); i++) deq.push_back(vec[i]);
            while (deq.size()>1&&deq[0].first==-1) {
                deq[1].second += deq[0].second;
                deq.pop_front();
            }
            while (deq.size()>1&&deq[deq.size()-1].first==-1) {
                deq[deq.size()-1].second += deq[deq.size()-2].second;
                deq.pop_back();
            }
            for (int i=1; i<=n; i++) {
                int cnt = 0;
                for (int j=0; j<deq.size(); j++) {
                    if (deq[j].first!=-1) {
                        cnt += deq[j].second / i;
                        int x = i - deq[j].second % i;
                        deq[j].second = x;
                    }
                }
                vector<P> vec2;
                vec2.push_back(P(deq[0].first==-1, deq[0].second));
                for (int j=1; j<deq.size(); j++) {
                    if (vec2[vec2.size()-1] == (deq[j].first==-1))
                        vec2[vec2.size()-1] += deq[j].second;
                    else
                        vec2.push_back(P(deq[j].first==-1, deq[j].second));
                }
                vec2.
            }
            return res;
        } else {
            for (int i=1; i<=mcost; i++) {
                int cost = i * sc;
                for (int j=0; j<vec.size(); j++) {
                    cost += ((vec[j].second+i-1)/i * pc);
                }
                res = min(res, cost);
            }
            return res;
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
			string desiredColor       = "RRGGBB";
			int stampCost             = 1;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string desiredColor       = "R**GB*";
			int stampCost             = 1;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string desiredColor       = "BRRB";
			int stampCost             = 2;
			int pushCost              = 7;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string desiredColor       = "R*RR*GG";
			int stampCost             = 10;
			int pushCost              = 58;
			int expected__            = 204;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string desiredColor       = "*B**B**B*BB*G*BBB**B**B*";
			int stampCost             = 5;
			int pushCost              = 2;
			int expected__            = 33;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string desiredColor       = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
			int stampCost             = 7;
			int pushCost              = 1;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
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
