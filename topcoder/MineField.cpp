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

class MineField {
public:
   vector <string> getMineField( string mineLocations ) {
		vector<string> map;
		for (int i=0; i<9; i++) map.push_back("000000000");
		for (int i=0; i<mineLocations.length(); i++) {
			if (mineLocations[i] == '(') {
				string temp = "";
				int x, y;
				for (i+=1;;i++) {
					if (mineLocations[i]==',') break;
					temp += mineLocations[i];
				}
				stringstream ss;
				ss << temp; ss >> x;
				temp = "";
				for (i+=1;;i++) {
					if (mineLocations[i]==')') break;
					temp += mineLocations[i];
				}
				stringstream s2;
				s2 << temp; s2 >> y;
				map[x][y] = 'M';
			}
		}
		int dx[] = {-1,0,1};
		int dy[] = {-1,0,1};
		for (int i=0; i<map.size(); i++) {
			for (int j=0; j<9; j++) {
				if (map[i][j]=='M') continue;
				int cnt = 0;
				for (int k=0; k<3; k++) for (int l=0; l<3; l++) {
					if (k == 1 && l == 1) continue;
					int nx = dx[k]+i, ny = dy[l]+j;
					if (nx < 9 && nx >= 0 && ny < 9 && ny >= 0 && map[nx][ny] == 'M')
						cnt++;
				}
				map[i][j] = cnt + '0';
			}
		}
		return map;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string mineLocations      = "(0,0)(1,0)(2,0)(3,0)(4,0)";
			string expected__[]       = { "M20000000",  "M30000000",  "M30000000",  "M30000000",  "M20000000",  "110000000",  "000000000",  "000000000",  "000000000" };

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string mineLocations      = "(0,0)(0,8)(8,0)(8,8)";
			string expected__[]       = { "M1000001M",  "110000011",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "110000011",  "M1000001M" };

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string mineLocations      = "(3,2)(3,3)(3,4)(4,2)(4,4)(5,2)(5,3)(5,4)(7,4)(6,7)";
			string expected__[]       = { "000000000",  "000000000",  "012321000",  "02MMM2000",  "03M8M3000",  "02MMM2111",  "0124321M1",  "0001M1111",  "000111000" };

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string mineLocations      = "";
			string expected__[]       = { "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000" };

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string mineLocations      = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string mineLocations      = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string mineLocations      = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = MineField().getMineField(mineLocations);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
