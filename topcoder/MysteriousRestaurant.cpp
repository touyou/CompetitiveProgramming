#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;

class MysteriousRestaurant {
public:
   int maxDays( vector <string> prices, int budget ) {
	int res=0,sum=0;
	int num[prices.size()][prices[0].length()];
	for (int i=0; i<prices.size(); i++) for (int j=0; j<prices[0].size(); j++) {
		if (isalnum(prices[i][j])) num[i][j]=prices[i][j]-'0';
		else if (prices[i][j]>='A'&&prices[i][j]<='Z') num[i][j]=prices[i][j]-'A'+10;
		else num[i][j]=prices[i][j]-'a'+36;
	}
	vector<int> type(7,-1);
	for (int i=0; i<prices.size(); i++) {
		int min_n=62;
		if (i<7) {
			for (int j=0; j<prices[i].length(); j++) if (min_n>num[i][j]) {
				min_n=num[i][j];
				type[i]=j;
			}
			if (sum+min_n<=budget) {
				sum+=min_n;
				res++;
			} else {
				break;
			}
		} else {
			int copy=sum;
			for (int ix=i-7; ix>=0; ix-=7) copy-=num[ix][type[i%7]];
			int min_sum=1000000000;
			for (int j=0; j<prices[0].length(); j++) {
				int tsum=0;
				for (int ix=i; ix>=0; ix-=7) tsum+=num[ix][j];
				if (tsum<min_sum) {
					min_sum=tsum;
					type[i%7]=j;
				}
			}
			if (min_sum+copy<=budget) {
				sum=min_sum+copy;
				res++;
			} else {
				break;
			}
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
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
			int budget                = 13;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
			int budget                = 20;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string prices[]           = {"SRM", "512"};
			int budget                = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
			int budget                = 256;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
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
