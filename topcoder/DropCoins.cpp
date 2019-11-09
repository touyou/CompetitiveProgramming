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

class DropCoins {
public:
	int dfs(vector<vi> maps, int jo, int ka, int le, int ri, int bs, int sum, int K, int res, char flag) {
		if (sum==K) return res;
		if (sum<K) return -1;
		int temp = INT_MAX, sub=0;
		if (flag=='a') {
			jo++; ka++;
			if (jo>=bs) return res;
			if (jo>=0) {
				for (int i=0; i<bs; i++) {
					if (maps[jo][i]) {
						maps[jo][i]=0;
						sub++;
					}
				}
			}
		} else if (flag=='b') {	
			jo--; ka--;
			if (ka<0) return res;
			if (ka<bs) {
				for (int i=0; i<bs; i++) {
					if (maps[ka][i]) {
						maps[ka][i]=0;
						sub++;
					}
				}
			}
		} else if (flag=='c') {
			le++; ri++;
			if (le>=bs) return res;
			if (le>=0) {
				for (int i=0; i<bs; i++) {
					if (maps[i][le]) {
						maps[i][le]=0;
						sub++;
					}
				}
			}
		} else if (flag=='d') {
			le--; ri--;
			if (ri<0) return res;
			if (ri<bs) {
				for (int i=0; i<bs; i++) {
					if (maps[i][ri]) {
						maps[i][ri]=0;
						sub++;
					}
				}
			}
		}
		char flags[] = {'a','b','c','d'};
		for (int i=0; i<4; i++) {
			int tres = dfs(maps,jo,ka,le,ri,bs,sum-sub,K,res+1,flags[i]);
			if (tres!=-1) res=min(res,tres);
		}
		if (temp==INT_MAX) return -1;
		else return temp;
	}
	
	int getMinimum( vector <string> board, int K ) {
		int bs = board.size(), sum = 0;
		vector<vi> maps(bs, vi(bs));
		for (int i=0; i<bs; i++) for (int j=0; j<bs; j++) {
			if (board[i][j]=='.') maps[i][j]=0;
			else maps[i][j]=1;
			sum += maps[i][j];
		}
		int jo=-1,ka=bs,le=-1,ri=bs;
		char flags[] = {'a','b','c','d'};
		int res = INT_MAX;
		for (int i=0; i<4; i++) {
			int tres = dfs(maps,jo,ka,le,ri,bs,sum,K,0,flags[i]);
			if (tres!=-1) res=min(res,tres);
		}
		if (res==INT_MAX) return -1;
		else return res;
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
			string board[]            = {".o.."
,"oooo"
,"..o."}
;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"...."
,".oo."
,".oo."
,"...."}
;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
