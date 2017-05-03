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

class ConnectingAirports {
public:
    bool check(vector<int> _capA, vector<int> _capU) 
        {
            int i,j;
            vector<int> capA=_capA;
            vector<int> capU=_capU;
            sort(capA.begin(),capA.end());
            for (i=0;i<capA.size();i++) {
                sort(capU.begin(),capU.end());
                reverse(capU.begin(), capU.end());
                for (j=0;j<capA[i];j++)capU[j]--;
            }
            for(i=0;i<capU.size();i++) if(capU[i]!=0)return false;
            return true;
        }
    
    vector <string> getSchedule( vector <int> capacityA, vector <int> capacityU ) {
        vector<string> res(capacityA.size()),null;
        for (int i=0; i<capacityA.size(); i++) if (capacityA[i]>capacityU.size()) return null;
        for (int i=0; i<capacityA.size(); i++) {
           res[i]="";
           for (int j=capacityU.size()-1;j>=0;j--) {
               if (capacityA[i]==0||capacityU[j]==0) {
                   res[i]="0"+res[i];
                   continue;
               }
               capacityU[j]--;
               capacityA[i]--;
               if (check(capacityA,capacityU)) {
                   res[i]="1"+res[i];
               }
               else {
                   capacityU[j]++;
                   capacityA[i]++;
                   res[i]="0"+res[i];
                   continue;
               }
           }
           if (capacityA[i]!=0) return null;
        } 
        for(int j=0;j<capacityU.size();j++) if(capacityU[j]!=0) return null;
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
			int capacityA[]           = {1,2,3};
			int capacityU[]           = {3,1,2};
			string expected__[]       = {"100", "101", "111" };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int capacityA[]           = {3,2,1,1};
			int capacityU[]           = {1,3,1,2};
			string expected__[]       = {"0111", "0101", "0100", "1000" };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int capacityA[]           = {1,2,3,4};
			int capacityU[]           = {5,6,7,8};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int capacityA[]           = {47,47};
			int capacityU[]           = {47,40,7};
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int capacityA[]           = {5,5};
			int capacityU[]           = {1,1,2,1,1,1,1,1,1};
			string expected__[]       = {"001001111", "111110000" };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int capacityA[]           = {0,0,0,0};
			int capacityU[]           = {0,0,0,0,0,0};
			string expected__[]       = {"000000", "000000", "000000", "000000" };

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int capacityA[]           = ;
			int capacityU[]           = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int capacityA[]           = ;
			int capacityU[]           = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int capacityA[]           = ;
			int capacityU[]           = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ConnectingAirports().getSchedule(vector <int>(capacityA, capacityA + (sizeof capacityA / sizeof capacityA[0])), vector <int>(capacityU, capacityU + (sizeof capacityU / sizeof capacityU[0])));
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
