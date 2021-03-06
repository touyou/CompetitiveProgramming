#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;

class InfiniteSequence2
{
public:
    ll dp[1000001];
    ll dfs(ll n, int p, int q, int x, int y) 
        {
            if (n<=0) return 1;
            if (n<=1000000&&dp[n]!=0) return dp[n];
            ll res=dfs(n/p-x,p,q,x,y)+dfs(n/q-y,p,q,x,y);
            if (n<=1000000) dp[n]=res;
            return res;
        }
    long long calc(long long n, int p, int q, int x, int y)
    {
        ll res=dfs(n,p,q,x,y);
        return res;
    }

    // BEGIN CUT HERE
    void run_test(int Case)
    {
            if ((Case == -1) || (Case == 0)) test_case_0();
            if ((Case == -1) || (Case == 1)) test_case_1();
            if ((Case == -1) || (Case == 2)) test_case_2();
            if ((Case == -1) || (Case == 3)) test_case_3();
            if ((Case == -1) || (Case == 4)) test_case_4();
            if ((Case == -1) || (Case == 5)) test_case_5();
    }

private:
    void verify_case(int Case, long long Expected, long long Received) {
            printf("Test Case #%d...",Case);
            if (Expected == Received)
                    printf("PASSED\n");
            else {
                    printf("FAILED\n");
                    printf("\tExpected: \"%lld\"\n",Expected);
                    printf("\tReceived: \"%lld\"\n",Received);
            }
    }
    void test_case_0() { long long Arg0 = 10000000ll; int Arg1 = 2; int Arg2 = 3; int Arg3 = 10000000; int Arg4 = 10000000; long long Arg5 = 2ll; verify_case(0, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { long long Arg0 = 12ll; int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; int Arg4 = 0; long long Arg5 = 8ll; verify_case(1, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { long long Arg0 = 0ll; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1ll; verify_case(2, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { long long Arg0 = 123ll; int Arg1 = 45; int Arg2 = 67; int Arg3 = 8; int Arg4 = 9; long long Arg5 = 2ll; verify_case(3, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { long long Arg0 = 10000000000000ll; int Arg1 = 2; int Arg2 = 2; int Arg3 = 123; int Arg4 = 1234566; long long Arg5 = 54025419ll; verify_case(4, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_5() { long long Arg0 = 10000000000000ll; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 390012; long long Arg5 = 250626223ll; verify_case(5, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE
};

// BEGIN CUT HERE
int main() {
	InfiniteSequence2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
