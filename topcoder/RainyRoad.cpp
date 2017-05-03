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

class RainyRoad {
public:
	bool dfs(vector<string> road, int x, int y, int N) {
		if (x==0&&y==N-1) return true;
		int dx[] = {-1,-1,0,1,1};
		int dy[] = {0,1,1,0,1};
		road[x][y]='-';
		for (int i=0; i<5; i++) {
			int nx=x+dx[i], ny=y+dy[i];
			if (nx>=0&&nx<2&&ny>=0&&ny<N&&road[nx][ny]=='.') {
				if (dfs(road, nx, ny, N)) return true;
			}
		}
		return false;
	}
   string isReachable( vector <string> road ) {
	int N = road[0].length();
	int y = 0;
	for (int i=0; i<N; i++) {
		if (road[0][i]=='.'&&road[1][i]=='.') {
			y++;
			if (y==N) return "YES";
		} else {
			if (road[0][y]=='W') y--;
			break;
		}
	}
	if (dfs(road, 0, y, N)) return "YES";
	else return "NO";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string road[]             = {".W.."
,"...."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string road[]             = {".W.."
,"..W."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string road[]             = {".W..W.."
,"...WWW."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string road[]             = {".."
,"WW"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string road[]             = {".WWWW."
,"WWWWWW"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string road[]             = {".W.W.W."
,"W.W.W.W"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string road[]             = {".............................................W."
,".............................................W."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string road[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RainyRoad().isReachable(vector <string>(road, road + (sizeof road / sizeof road[0])));
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
