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

class SafeRemoval {
public:
  bool used[55];
  vector<int> s;
  int dfs(int cnt, int sum, int k, int sz) {
	if (cnt==k) return sum;
	int ret=-1;
	for (int i=0; i<sz; i++) {
	  if (used[i]) continue;
	  if ((sum-s[i])%4==0) continue;
	  used[i]=true;
	  ret=max(ret, dfs(cnt+1,sum-s[i],k,sz));
	  used[i]=false;
	}
	return ret;
  }
  int removeThem( vector <int> seq, int k ) {
	int sum = 0 , sz = seq.size();
	for (int i=0; i<sz; i++) sum += seq[i];
	memset(used, 0, sizeof(used));
	sort(seq.begin(), seq.end());
	for (int i=0; i<sz; i++) s.push_back(seq[i]);
	int res=dfs(0,sum,k,sz);
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
			int seq[]                 = {3, 8, 4};
			int k                     = 1;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {1,1,1,1,1,1};
			int k                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1,6,1,10,1,2,7,11};
			int k                     = 6;
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {1,1,1,1,1,1,1,1,7};
			int k                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int seq[]                 = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeRemoval().removeThem(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])), k);
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
