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

class RotatedClock {
public:
	string toStr(int n) {
		stringstream ss;
		ss << n;
		return ss.str();
	}
	string getEarliest( int hourHand, int minuteHand ) {
		string res = "";
		// 短針の角度から分を計算する
		int hdeg = hourHand % 30;
		int min = hdeg * 2;
		// 正しい角度とのズレ
		int maydeg = min * 6;
		int dis = abs(minuteHand - maydeg);
		// 基準は必ず12時から30度の倍数の位置なのでそれ以外は不可能
		if (dis % 30 != 0) return res;
		// 基準は0時から何時間ズレているか
		int cer = 0 - (minuteHand - maydeg) / 30;
		if (cer < 0) cer += 12;
		if (cer >= 12) cer -= 12;
		// 基準より時間を計算
		cer += hourHand / 30;
		if (cer >= 12) cer -= 12;
		if (cer < 0) cer -=12;

		string hstr, mstr;
		hstr = toStr(cer);
		mstr = toStr(min);
		if (hstr.length() == 1) hstr = '0' + hstr;
		if (mstr.length() == 1) mstr = '0' + mstr;
		res += hstr + ':' + mstr;
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
			int hourHand              = 70;
			int minuteHand            = 300;
			string expected__         = "08:20";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int hourHand              = 90;
			int minuteHand            = 120;
			string expected__         = "11:00";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int hourHand              = 240;
			int minuteHand            = 36;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int hourHand              = 19;
			int minuteHand            = 19;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int hourHand              = 1;
			int minuteHand            = 12;
			string expected__         = "00:02";

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
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
