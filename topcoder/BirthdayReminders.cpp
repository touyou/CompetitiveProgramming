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

class BirthdayReminders {
public:
   vector <string> remind( vector <string> friendNames, vector <int> birthDates, int currentDate, vector <string> occasions, vector <int> days, int k ) {

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
			string friendNames[]      = {"John", "Jack", "Bill"};
			int birthDates[]          = {50, 100, 150};
			int currentDate           = 500;
			string occasions[]        = {"birthday", "decimal birthday", "binary birthday"};
			int days[]                = {365, 1000, 512};
			int k                     = 10;
			string expected__[]       = {"515. Bill birthday (1)", "562. John binary birthday (1)", "612. Jack binary birthday (1)", "662. Bill binary birthday (1)", "780. John birthday (2)", "830. Jack birthday (2)", "880. Bill birthday (2)", "1050. John decimal birthday (1)", "1074. John binary birthday (2)", "1100. Jack decimal birthday (1)" };

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string friendNames[]      = {"Zero", "Two", "Three"};
			int birthDates[]          = {0, 2, 3};
			int currentDate           = 24;
			string occasions[]        = {"threeday", "twoday"};
			int days[]                = {3,2};
			int k                     = 10;
			string expected__[]       = {"24. Zero threeday (8)", "24. Three threeday (7)", "24. Zero twoday (12)", "24. Two twoday (11)", "25. Three twoday (11)", "26. Two threeday (8)", "26. Zero twoday (13)", "26. Two twoday (12)", "27. Zero threeday (9)", "27. Three threeday (8)" };

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string friendNames[]      = {"Jessica Alba", "Angelina Jolie", "Paris Hilton", "Britney Spears"};
			int birthDates[]          = {4135, 1980, 4065, 4353};
			int currentDate           = 14091;
			string occasions[]        = {"Venus year", "Earth year", "Mars year", "Jupiter year", "Saturn year"};
			int days[]                = {225, 365, 687, 4332, 10760};
			int k                     = 20;
			string expected__[]       = {"14130. Angelina Jolie Venus year (54)", "14190. Paris Hilton Venus year (45)", "14208. Britney Spears Earth year (27)", "14253. Britney Spears Venus year (44)", "14260. Jessica Alba Venus year (45)", "14285. Paris Hilton Earth year (28)", "14346. Angelina Jolie Mars year (18)", "14355. Angelina Jolie Venus year (55)", "14355. Jessica Alba Earth year (28)", "14370. Paris Hilton Mars year (15)", "14390. Angelina Jolie Earth year (34)", "14415. Paris Hilton Venus year (46)", "14440. Jessica Alba Mars year (15)", "14478. Britney Spears Venus year (45)", "14485. Jessica Alba Venus year (46)", "14573. Britney Spears Earth year (28)", "14580. Angelina Jolie Venus year (56)", "14640. Paris Hilton Venus year (47)", "14650. Paris Hilton Earth year (29)", "14658. Britney Spears Mars year (15)" };

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string friendNames[]      = ;
			int birthDates[]          = ;
			int currentDate           = ;
			string occasions[]        = ;
			int days[]                = ;
			int k                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			string friendNames[]      = ;
			int birthDates[]          = ;
			int currentDate           = ;
			string occasions[]        = ;
			int days[]                = ;
			int k                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string friendNames[]      = ;
			int birthDates[]          = ;
			int currentDate           = ;
			string occasions[]        = ;
			int days[]                = ;
			int k                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthdayReminders().remind(vector <string>(friendNames, friendNames + (sizeof friendNames / sizeof friendNames[0])), vector <int>(birthDates, birthDates + (sizeof birthDates / sizeof birthDates[0])), currentDate, vector <string>(occasions, occasions + (sizeof occasions / sizeof occasions[0])), vector <int>(days, days + (sizeof days / sizeof days[0])), k);
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
