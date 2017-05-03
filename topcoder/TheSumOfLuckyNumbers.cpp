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

class TheSumOfLuckyNumbers {
public:
    vector<int> luck;
    int ten[7];
    void gen(int num, int x) {
        if (x==7) return;
        luck.push_back(num+4*ten[x]);
        luck.push_back(num+7*ten[x]);
        gen(num+4*ten[x],x+1);
        gen(num+7*ten[x],x+1);
        return;
    }
    vector <int> sum( int n ) {
        ten[0]=1;
        for (int i=1; i<7; i++) ten[i]=ten[i-1]*10;
        gen(0,0);
        sort(luck.begin(), luck.end());
        int x = luck.size()-1;
        for (;x>=0;x--) if (luck[x]<=n) break;
        // printf("%d\n",luck[x]);
        int cnt=n/luck[x];
        int sum=cnt*luck[x];
        vector<int> str(1,cnt);
        queue<pair<int, vector<int> > > que;
        while (sum>=0) {
            que.push(make_pair(sum, str));
            str[0]--; sum-=luck[x];
        }
        vector<int> res;
        int sv=0;
        while (!que.empty()) {
            int s=que.front().first;
            vector<int> st=que.front().second;
            que.pop();
            if (s==n) {
                int sz = 0;
                for (int i=0; i<st.size(); i++) sz+=st[i];
                if (res.empty()||sv>sz) {
                    res=st;
                    sv=sz;
                }
            }
            int pos=st.size();
            if (x<pos) continue;
            cnt=(n-s)/luck[x-pos];
            // printf("%d %d\n",cnt,luck[x-pos]);
            sum=s+cnt*luck[x-pos];
            st.push_back(cnt);
            while (sum>=s) {
                // printf("%d\n",sum);
                que.push(make_pair(sum, st));
                st[pos]--; sum-=luck[x-pos];
            }
        }
        vector<int> res2;
        for (int i=0; i<res.size(); i++) {
            // printf("%d %d\n",res[i],luck[x-i]);
            for (int j=0; j<res[i]; j++) res2.push_back(luck[x-i]);
        }
        sort(res2.begin(), res2.end());
        return res2;
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

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int n                     = 11;
			int expected__[]          = {4, 7 };

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int n                     = 12;
			int expected__[]          = {4, 4, 4 };

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int n                     = 13;
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int n                     = 100;
			int expected__[]          = {4, 4, 4, 44, 44 };

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheSumOfLuckyNumbers().sum(n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
