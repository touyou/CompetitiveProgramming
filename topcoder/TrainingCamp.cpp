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

class TrainingCamp {
public:
   vector <string> determineSolvers( vector <string> attendance, vector <string> problemTopics ) {
       int N = attendance.size(), M = attendance[0].length(), K = problemTopics.size();
       vector<string> res;
       for (int i = 0; i < N; i++) {
           string temp = "";
           for (int j = 0; j < K; j++) temp += 'X';
           for (int j = 0; j < M; j++) {
               for (int k = 0; k < K; k++) {
                   if (attendance[i][j] == '-' && problemTopics[k][j] == 'X')
                       temp[k] = '-';
               }
           }
           res.push_back(temp);
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
			string attendance[]       = {"XXX",
 "XXX",
 "XX-"};
			string problemTopics[]    = {"---",
 "XXX",
 "-XX",
 "XX-"};
			string expected__[]       = {"XXXX", "XXXX", "X--X" };

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string attendance[]       = {"-XXXX",
 "----X",
 "XXX--",
 "X-X-X"};
			string problemTopics[]    = {"X---X",
 "-X---",
 "XXX--",
 "--X--"};
			string expected__[]       = {"-X-X", "----", "-XXX", "X--X" };

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string attendance[]       = {"-----",
 "XXXXX"};
			string problemTopics[]    = {"XXXXX",
 "-----",
 "--X-X"};
			string expected__[]       = {"-X-", "XXX" };

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string attendance[]       = {"-",
 "X",
 "X",
 "-",
 "X"};
			string problemTopics[]    = {"-",
 "X"};
			string expected__[]       = {"X-", "XX", "XX", "X-", "XX" };

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string attendance[]       = {"X----X--X",
 "X--X-X---",
 "--X-X----",
 "XXXX-X-X-",
 "XXXX--XXX"};
			string problemTopics[]    = {"X----X-X-",
 "-----X---",
 "-X----X-X",
 "-X-X-X---",
 "-----X---",
 "X-------X"};
			string expected__[]       = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" };

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
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
