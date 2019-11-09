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

class CantorDust {
public:
    int occurrencesNumber(vector <string> pattern, int time) {
        int res;
        //‚±‚±‚ÉƒvƒƒOƒ‰ƒ€‚ð“ü—ÍI
	double len = pow(3,time);
	res = (int)(len/pattern.size())*(len/pattern[0].length());
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
        if ((Case == -1) || (Case == 6)) test_case_6();
        if ((Case == -1) || (Case == 7)) test_case_7();
        if ((Case == -1) || (Case == 8)) test_case_8();
        if ((Case == -1) || (Case == 9)) test_case_9();
        int i;
        cin >> i;
    }
    void verify_case(int Case, int Expected, int Received)
    {
        printf("Test Case #%d...", Case);
        if (Expected == Received)
            printf("PASSED\n");
        else
        {
            printf("FAILED\n");
            printf("\tExpected: \"%d\"\n" ,Expected);
            printf("\tReceived: \"%d\"\n" ,Received);
        }
    }

    void test_case_0() { string Arr0[] = {".X",".."};    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1;    verify_case(0, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 65; verify_case(2, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"X...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 262144; verify_case(4, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = { "....", "....", "...." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 385369800; verify_case(5, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_6() { string Arr0[] = { "...........................", "...........................", "...........................", "...........................", "...........................", "...........................", "..........................." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(6, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_7() { string Arr0[] = { ".......X.X...X.X........", "........................" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 186; verify_case(7, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_8() { string Arr0[] = { "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", ".X...X.X.........X.X...X.X.....................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", "...............................................", ".X...X.X.........X.X...X.X.....................", "..............................................." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 496; verify_case(8, Arg2, occurrencesNumber(Arg0, Arg1)); }
    void test_case_9() { string Arr0[] = { "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X..", ".......................", ".......................", ".......................", "X.X...X.X.........X.X..", ".......................", "X.X...X.X.........X.X.." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 4096; verify_case(9, Arg2, occurrencesNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CantorDust ___test;
    ___test.run_test(-1);
}
// END CUT HERE
