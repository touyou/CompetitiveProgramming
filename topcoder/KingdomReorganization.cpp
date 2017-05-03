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
struct edge {
    int u, v, cost;
    bool operator<(const edge& e1)const{
        return cost<e1.cost;
    }
    edge(int _u, int _v, int _cost) {
        u=_u;
        v=_v;
        cost=_cost;
    }
};
class KingdomReorganization {
public:
    int par[50];
    int rank[50];
    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x) {
        if (par[x]==x) {
            return x;
        } else {
            return par[x]=find(par[x]);
        }
    }
    void unite(int x, int y) {
        x=find(x);
        y=find(y);
        if (x==y) return;
        if (rank[x]<rank[y]) {
            par[x]=y;
        } else {
            par[y]=x;
            if (rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y) {
        return find(x)==find(y);
    }
    int getCost( vector <string> kingdom, vector <string> build, vector <string> destroy ) {
        int sz=kingdom.size(), len=kingdom[0].length();
        int res=0;
        init(sz);
        vector<edge> es;
        for (int i=0; i<sz; i++) {
            for (int j=i+1; j<len; j++) {
                 if (kingdom[i][j]=='1')
                    es.push_back(edge(i,j,destroy[i][j]-'A'));
                 }
            }
        }
        sort(es.begin(), es.end());
        int mindes[50];
        memset(mindes, 0, sizeof(mindes));
        for (int i=0; i<es.size(); i++) {
            edge e = es[i];
            if (same(e.u,e.v)) {
                mindes[find(e.u)]=min(mindes[find(e.u)],e.cost);
            }
        }
        for (int i=0; i<50; i++) res+=mindes[i];
        es.clear();
        for (int i=0; i<sz; i++) {
            for (int j=i+1; j<len; j++) {
                es.push_back(edge(i,j,build[i][j]));
            }
        }
        sort(es.begin(), es.end());
        init(sz);
        for (int i=0; i<es.size(); i++) {
            edge e = es[i];
            if (!same(e.u, e.v)) {
                unite(e.u,e.v);
                if (kingdom[e.u][e.v]=='0') res+=e.cost;
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
			string kingdom[]          = {"000","000","000"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string kingdom[]          = {"011","101","110"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string kingdom[]          = {"011000","101000","110000","000011","000101","000110"};
			string build[]            = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			string destroy[]          = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string kingdom[]          = {"0"};
			string build[]            = {"A"};
			string destroy[]          = {"A"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string kingdom[]          = {"0001","0001","0001","1110"};
			string build[]            = {"AfOj","fAcC","OcAP","jCPA"};
			string destroy[]          = {"AWFH","WAxU","FxAV","HUVA"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string kingdom[]          = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
			string build[]            = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
			string destroy[]          = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
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
