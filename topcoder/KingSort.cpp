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
typedef map<string, vector<pair<int, string> > > mp;
#define PI 3.14159265358979

class KingSort {
public:
    int conv(string num) {
        int res=0;
        for (int i=0; i<num.length(); i++) {
            if (num[i]=='I') res++;
            else if (i&&num[i-1]=='I'&&num[i]=='V') res+=3;
            else if (num[i]=='V') res+=5;
            else if (i&&num[i-1]=='I'&&num[i]=='X') res+=8;
            else if (num[i]=='X') res+=10;
            else if (i&&num[i-1]=='X'&&num[i]=='L') res+=30;
            else if (num[i]=='L') res+=50;
        }
        return res;
    }
   vector <string> getSortedList( vector <string> kings ) {
       // I, II, III, IV, V, VI, VII, VIII, IX, X
       // XX, XXX, XL, L
       sort(kings.begin(), kings.end());
       mp ks;
       for (int i=0; i<kings.size(); i++) {
           string name="", num=""; int j;
           for (j=0; j<kings[i].length(); j++) {
               if (kings[i][j]==' ') break;
               name += kings[i][j];
           }
           for (j+=1; j<kings[i].length(); j++) {
               num += kings[i][j];
           }
           ks[name].push_back(make_pair(conv(num), num));
       }
       vector<string> res;
       for (mp::iterator it=ks.begin(); it!=ks.end(); it++) {
           sort((*it).second.begin(), (*it).second.end());
           for (int i=0; i<(*it).second.size(); i++) {
               string r="";
               r+=(*it).first;
               r+=" ";
               r+=(*it).second[i].second;
               res.push_back(r);
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
			string kings[]            = {"Louis IX", "Louis VIII"};
			string expected__[]       = {"Louis VIII", "Louis IX" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string kings[]            = {"Louis IX", "Philippe II"};
			string expected__[]       = {"Louis IX", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string kings[]            = {"Richard III", "Richard I", "Richard II"};
			string expected__[]       = {"Richard I", "Richard II", "Richard III" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string kings[]            = {"John X", "John I", "John L", "John V"};
			string expected__[]       = {"John I", "John V", "John X", "John L" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string kings[]            = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
			string expected__[]       = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string kings[]            = {"Philippe II", "Philip II"};
			string expected__[]       = {"Philip II", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
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
