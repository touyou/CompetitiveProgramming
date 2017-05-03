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

class RotatingBot {
public:
   int minArea( vector <int> moves ) {
        int lx=0, rx=0, dy=0, uy=0;
        int nx=0, ny=0;
        int x=1, y=1;
        int sz=moves.size();
        // 0→ 1↑ 2← 3↓
        for (int i=0; i<sz; i++) {
            if (i%4==0) nx+=moves[i];
            else if (i%4==1) ny-=moves[i];
            else if (i%4==2) nx-=moves[i];
            else ny+=moves[i];
            lx=min(lx,nx); rx=max(rx,nx);
            dy=min(dy,ny); uy=max(uy,ny);
            if (i%2==0) x=max(x,moves[i]+1);
            else y=max(y,moves[i]+1);
        }
        bool flag=true;
        nx=ny=0;
        map<pii, bool> mp;
        mp[make_pair(nx,ny)]=true;
        cout<<lx<<" "<<rx<<endl;
        cout<<dy<<" "<<uy<<endl;
        for (int i=0; i<sz&&flag; i++) {
            if (i%4==0) {
                for (int j=nx+1; j<=nx+moves[i]; j++) {
                    if (mp.find(make_pair(j,ny))!=mp.end()) {
                        flag=false;
                        break;
                    }
                    mp[make_pair(j,ny)]=true;
                }
                nx+=moves[i];
                if (i!=sz-1&&nx<rx&&mp.find(make_pair(nx+1,ny))==mp.end()) flag=false;
            } else if (i%4==1) {
                for (int j=ny-1; j>=ny-moves[i]; j--) {
                    if (mp.find(make_pair(nx,j))!=mp.end()) {
                        flag=false;
                        break;
                    }
                    mp[make_pair(nx,j)]=true;
                }
                ny-=moves[i];
                if (i!=sz-1&&ny>dy&&mp.find(make_pair(nx,ny-1))==mp.end()) flag=false;
            } else if (i%4==2) {
                for (int j=nx-1; j>=nx-moves[i]; j--) {
                    if (mp.find(make_pair(j,ny))!=mp.end()) {
                        flag=false;
                        break;
                    }
                    mp[make_pair(j,ny)]=true;
                }
                nx-=moves[i];
                if (i!=sz-1&&nx>lx&&mp.find(make_pair(nx-1,ny))==mp.end()) flag=false;
            } else {
                for (int j=ny+1; j<=ny+moves[i]; j++) {
                    if (mp.find(make_pair(nx,j))!=mp.end()) {
                        flag=false;
                        break;
                    }
                    mp[make_pair(nx,j)]=true;
                }
                ny+=moves[i];
                if (i!=sz-1&&ny<uy&&mp.find(make_pair(nx,ny+1))==mp.end()) flag=false;
            }
        }
        if (flag) return x*y;
        else return -1;
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
			int moves[]               = {15};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int moves[]               = {3,10};
			int expected__            = 44;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int moves[]               = {1,1,1,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int moves[]               = {9,5,11,10,11,4,10};
			int expected__            = 132;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int expected__            = 420;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int moves[]               = {8,6,6,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int moves[]               = {8,6,6};
			int expected__            = 63;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int moves[]               = {5,4,5,3,3};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
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
