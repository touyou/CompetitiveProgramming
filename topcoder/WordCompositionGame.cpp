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

class WordCompositionGame {
public:
    string score( vector <string> listA, vector <string> listB, vector <string> listC ) {
        map<string, int> gcnt;
        for (int i=0; i<listA.size(); i++) {
            if (gcnt.find(listA[i])!=gcnt.end()) gcnt[listA[i]]++;
            else gcnt[listA[i]]=1;
        }
        for (int i=0; i<listB.size(); i++) {
            if (gcnt.find(listB[i])!=gcnt.end()) gcnt[listB[i]]++;
            else gcnt[listB[i]]=1;
        }
        for (int i=0; i<listC.size(); i++) {
            if (gcnt.find(listC[i])!=gcnt.end()) gcnt[listC[i]]++;
            else gcnt[listC[i]]=1;
        }
        int A=0, B=0, C=0;
        for (int i=0; i<listA.size(); i++) {
            A+=4-gcnt[listA[i]];
        }
        for (int i=0; i<listB.size(); i++) {
            B+=4-gcnt[listB[i]];
        }
        for (int i=0; i<listC.size(); i++) {
            C+=4-gcnt[listC[i]];
        }
        stringstream sA, sB, sC;
        string scA, scB, scC;
        sA<<A; sA>>scA;
        sB<<B; sB>>scB;
        sC<<C; sC>>scC;
        return scA+"/"+scB+"/"+scC;
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
			string listA[]            = {"cat", "dog", "pig", "mouse"};
			string listB[]            = {"cat", "pig"};
			string listC[]            = {"dog", "cat"};
			string expected__         = "8/3/3";

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string listA[]            = {"mouse"};
			string listB[]            = {"cat", "pig"};
			string listC[]            = {"dog", "cat"};
			string expected__         = "3/5/5";

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string listA[]            = {"dog", "mouse"};
			string listB[]            = {"dog", "pig"};
			string listC[]            = {"dog", "cat"};
			string expected__         = "4/4/4";

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string listA[]            = {"bcdbb","aaccd","dacbc","bcbda","cdedc","bbaaa","aecae"};
			string listB[]            = {"bcdbb","ddacb","aaccd","adcab","edbee","aecae","bcbda"};
			string listC[]            = {"dcaab","aadbe","bbaaa","ebeec","eaecb","bcbba","aecae","adcab","bcbda"};
			string expected__         = "14/14/21";

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string listA[]            = ;
			string listB[]            = ;
			string listC[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string listA[]            = ;
			string listB[]            = ;
			string listC[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string listA[]            = ;
			string listB[]            = ;
			string listC[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WordCompositionGame().score(vector <string>(listA, listA + (sizeof listA / sizeof listA[0])), vector <string>(listB, listB + (sizeof listB / sizeof listB[0])), vector <string>(listC, listC + (sizeof listC / sizeof listC[0])));
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
