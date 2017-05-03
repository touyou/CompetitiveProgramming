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
static const double EPS = 1e-5;
typedef long long ll;


class BinaryFlips {
public:
    int minimalMoves(int A, int B, int K) {
        //ここが毎回呼び出されますので、答えを返す関数を作成してください。
	if (A==0) return 0;
        if (A+B<K) return -1;
        int minval=A,maxval=A;//0の枚数の最小値、最大値
        for (int i=0; i<=A+B;i++) {
            int nextminval, nextmaxval;
            // 可能な限り1をひっくり返す
            if (minval<=K&&maxval>=K) {
                if (minval%2==K%2) return i+1;//Kとの偶奇があえばすべて1にすることができる
                else nextminval=1;//それいがいは1枚0が残る
            }
            else nextminval=min(abs(K-minval),abs(K-maxval));
            if (minval<=(A+B-K)&&maxval>=(A+B-K)) {
                if ((A+B-maxval)%2==K%2) nextmaxval=A+B;
                else nextmaxval=A+B-1;
            }
            else nextmaxval=A+B-min(abs((A+B-K)-minval),abs((A+B-K)-maxval));
            maxval=nextmaxval;
            minval=nextminval;
        }
        return -1;
    }

//以下テスト用コードとなります。TopCoderに提出する際は、以下のEND CUT HEREまで削除して提出してください。
// BEGIN CUT HERE　1つ目
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); }
	private:
		void verify_case(int Case, int Expected, int Received) {
		printf("Test Case #%d...", Case);
		if (Expected == Received) 
			printf("PASSED\n"); 
		else { 
			printf("FAILED\n"); 
			printf("\tExpected: %d\n", Expected);
			printf("\tReceived: %d\n", Received); } }
		void test_case_0(){ int Arg0 = 3; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_1()  { int Arg0 = 4; int Arg1 = 0; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; verify_case(2, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = -1; verify_case(3, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 578; int Arg3 = 174; verify_case(4, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; verify_case(5, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_6() { int Arg0 = 4; int Arg1 = 44; int Arg2 = 50; int Arg3 = -1; verify_case(6, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_7() { int Arg0 = 99200; int Arg1 = 0; int Arg2 = 99101; int Arg3 = 1004; verify_case(7, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_8() { int Arg0 = 99999; int Arg1 = 100000; int Arg2 = 50000; int Arg3 = -1; verify_case(8, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
		void test_case_9() { int Arg0 = 1; int Arg1 = 99999; int Arg2 = 99999; int Arg3 = 99999; verify_case(9, Arg3, minimalMoves(Arg0, Arg1, Arg2)); }
// END CUT HERE　1つ目

};

// BEGIN CUT HERE　2つ目
int main() {
BinaryFlips ___test;
___test.run_test(-1);
}
// END CUT HERE　2つ目
