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

class CutSticks {
public:
    double maxKth(vector<int> sticks, int C, int K)
        {
            double top=1e9,btn=0;   // 1enで10^nを表す
            for (int i=0; i<100; i++) {  // 適当な定数回で探索を打ち切る
                ll count = 0;
                double mid=(top+btn)/2;
                ll cut = 0;
                for (int j=0; j<sticks.size(); j++) {
                    ll next = (ll)(sticks[j]/mid);
                    cut+=max((ll)0,(next-1));  // 0と比べるのはマイナスにならないように
                    count+=next;
                }
                count-=max((ll)0,cut-C);  // マイナスにならないように
                if (count>=K) btn=mid;
                else top=mid;
            }
            return btn;
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

	private:
		bool verify_check(double a, double b)
		{
			if ((b - (a - EPS)) * (b - (a + EPS)) <= 0) return true;
			if ((b - (a * (1 - EPS))) * (b - (a * (1 + EPS))) <= 0) return true;
			return false;
		}

		void verify_case(int Case, double Expected, double Received) {
			printf("Test Case #%d...",Case);
			if (verify_check(Expected, Received)) 
				printf("PASSED\n"); 
			else { 
				printf("FAILED\n"); 
				printf("\tExpected: \"%f(%e)\"\n",Expected,Expected);
				printf("\tReceived: \"%f(%e)\"\n",Received,Received);
			}
		}

		void test_case_0() { int Arg4[] =  { 5, 8 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 8.0; verify_case(0, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg4[] =  { 5, 8 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 5.0; verify_case(1, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg4[] =  { 5, 8 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1; int Arg2 = 3; double Arg3 = 4.0; verify_case(2, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg4[] =  { 1000000000, 1000000000, 1 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 2; int Arg2 = 5; double Arg3 = 1.0; verify_case(3, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg4[] =  { 76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 789; int Arg2 = 456; double Arg3 = 34.92; verify_case(4, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_5() { int Arg4[] =  { 757148, 167851001, 301413357, 336971125, 659598369, 160567226, 391749388, 4890852, 35766291, 26239573, 473038165, 597007, 3615545, 326051437, 392289611, 118341523, 170427799, 37215529, 675016434, 168544291, 683447134, 950090227, 82426873, 116752252, 194041605, 706221269, 69909135, 257655784, 84970744, 21417563, 37379061, 40873981, 8670529, 80835681, 436291073, 653352031, 106923811, 374079501, 466701607, 86546365, 247776868, 480572137, 222071041, 36629217, 366496749, 549646417, 278840199, 119255907, 33557677 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1000000000; int Arg2 = 1000000027; double Arg3 = 12.244373490330695; verify_case(5, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_6() { int Arg4[] =  { 513022019, 674849833, 885808907, 149415576, 79637949, 564425687, 106515274, 756240490, 23638555, 822705644, 859334360, 857565758, 304229475, 709484387, 665434174, 231165488, 236894955, 681336685, 708102424, 547573006, 965429614, 829886211, 620024471, 456926498, 649940286, 224250023, 607157213, 85961552, 177817310, 190036559, 140290145, 807903339, 215782534, 94324157, 540994540, 38818470, 206487473, 850179612, 834914928, 747074719, 170164076, 740662178, 305316996, 270621694, 84027923, 763561070, 11607333, 208278513, 568198237, 10104177 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1000000; int Arg2 = 500000; double Arg3 = 45585.74897814111; verify_case(6, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_7() { int Arg4[] =  { 1 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1000000000; int Arg2 = 1000000000; double Arg3 = 1.0000000000006078E-9; verify_case(7, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_8() { int Arg4[] =  { 3, 2, 1, 4, 3, 3, 2, 4, 1, 4, 4, 1, 1, 2, 5, 3, 5, 1, 3, 3, 4, 5, 2, 3, 4, 2, 3, 5, 1, 3, 5 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 6885; int Arg2 = 99; double Arg3 = 0.8; verify_case(8, Arg3, maxKth(Arg0, Arg1, Arg2)); }
		void test_case_9() { int Arg4[] =  { 1000000000, 1 }; vector<int> Arg0(Arg4, Arg4 + (sizeof(Arg4) / sizeof(Arg4[0]))); int Arg1 = 1000000000; int Arg2 = 2; double Arg3 = 5.0E8; verify_case(9, Arg3, maxKth(Arg0, Arg1, Arg2)); }


	// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	CutSticks ___test;
	___test.run_test(-1);
	// END CUT HERE
	return 0;
}
