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

class FloorBoards
{
public:
    int layout(vector<string> room)
    {
        //答えをreturnするとテストできます！
		return 0;
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
    }
	void verify_case(int Case, int Expected, int Received) {
		printf("Test Case #%d...",Case);
		if (Expected == Received)
			printf("PASSED\n");
		else {
			printf("FAILED\n");
			printf("\tExpected: \"%d\"\n",Expected);
			printf("\tReceived: \"%d\"\n",Received); } }

    void test_case_0()
    {
        string Arg[] ={"....."
,"....."
,"....."
,"....."
,"....."};
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 5; verify_case(0, Arg1, layout(Arg0));
    }
    void test_case_1()
    {
        string Arg[] ={"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"};
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 7; verify_case(1, Arg1, layout(Arg0));
    }
    void test_case_2()
    {
        string Arg[] ={"####"
,"####"
,"####"
,"####"};
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 0; verify_case(2, Arg1, layout(Arg0));
    }
    void test_case_3()
    {
        string Arg[] ={"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"};
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 9; verify_case(3, Arg1, layout(Arg0));
    }
    void test_case_4()
    {
        string Arg[] ={".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."};
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 9; verify_case(4, Arg1, layout(Arg0));
    }

    void test_case_5()
    {
        string Arg[] = { ".#.#.#.#.#", "#.#.#.#.#.", ".#.#...#.#", "#.#.#.#.#.", ".#.#.#.#.#", "#...#.#.#.", ".#.#.#...#", "#.#.#.#.#.", ".#.#.#.#.#", "#.#...#.#." };
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 46; verify_case(5, Arg1, layout(Arg0));
    }

	void test_case_6()
    {
        string Arg[] = { "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", "..........", ".........." };
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 10; verify_case(6, Arg1, layout(Arg0));
    }

    void test_case_7()
    {
        string Arg[] = { "......#..#", "..###.....", "......#.#.", "#..#.#...#", "..##..##..", "#.........", ".#.#.###..", "..##.#.#..", ".........#", ".....#..##" };
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 23; verify_case(7, Arg1, layout(Arg0));
    }

    void test_case_8()
    {
        string Arg[] = { "..........", "..#.......", "..........", "#......#..", "...#...#..", "...#......", "#.........", "....#.....", "#.........", ".....#...." };
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 17; verify_case(8, Arg1, layout(Arg0));
    }

    void test_case_9()
    {
        string Arg[] = { "#.#####.#", "#.......#", "#.#.#.#.#", "....#....", "###.#.###", "....#....", "#.#.#.#.#", "#.......#", "#.#####.#" };
        vector <string> Arg0(Arg, Arg + (sizeof(Arg) / sizeof(Arg[0]))); int Arg1 = 12; verify_case(8, Arg1, layout(Arg0));
    }

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	FloorBoards ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
