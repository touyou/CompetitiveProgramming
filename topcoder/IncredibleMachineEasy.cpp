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
const double EPS=1e-9;
class IncredibleMachineEasy {
   public:
   double gravitationalAcceleration(vector <int> height, int T)
  {
  	/* time^2 = height1/0.5/g+height2/0.5/g+...
  	   time^2 = 2(height1+height2+...+heightn)/g
  	*/
  	double sum=0;
	for(int i=0; i<height.size(); i++) sum+=sqrt(height[i]);
	sum*=sum;
	return 2*sum/(T*T);
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {16,23,85,3,35,72,96,88,2,14,63}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; double Arg2 = 9.803799620759717; verify_case(0, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; double Arg2 = 26.73924541044107; verify_case(1, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 7.111111111111111; verify_case(2, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,3,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; double Arg2 = 0.7192306901503684; verify_case(3, Arg2, gravitationalAcceleration(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
IncredibleMachineEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
