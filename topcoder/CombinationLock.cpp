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


class CombinationLock {
public:
  double degreesTurned( vector <int> combo, int size, int start ) {
    double result = 0.0;
    int N = combo.size();
    int npos = start, rot;
    double unit = 360.0 / (double)size;
    for (int i=0; i<combo.size(); i++) {
        if (i % 2 == 0) {
            rot = combo[i] - npos;
            if (rot < 0) rot += size;
        } else {
            rot = npos - combo[i];
            if (rot < 0) rot += size;
        }
        result += (double)N * 360 + (double)rot * unit;
//        cout << rot << " " << N << endl;
        N--;
        npos = combo[i];
    }
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,20,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 6; double Arg3 = 2556.0; verify_case(0, Arg3, degreesTurned(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,50,99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 65; double Arg3 = 2642.4; verify_case(1, Arg3, degreesTurned(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; double Arg3 = 79344.0; verify_case(2, Arg3, degreesTurned(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {64,93,87,3,22,53,64,53,11,90,11,59,30,6,11,17,72,0,38,55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 97; int Arg2 = 26; double Arg3 = 79166.59793814432; verify_case(3, Arg3, degreesTurned(Arg0, Arg1, Arg2)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  CombinationLock ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
