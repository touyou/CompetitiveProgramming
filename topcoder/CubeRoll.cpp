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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

class CubeRoll {
   public:
   int getMinimumSteps(int initPos, int goalPos, vector <int> holePos)
  {
	SORT(holePos);
	REP(i,SZ(holePos)) {
		if ((initPos<goalPos&&holePos[i]>initPos&&holePos[i]<goalPos)||(initPos>goalPos&&holePos[i]<initPos&&holePos[i]>goalPos)) return -1;
	}
	stringstream ss; ss << sqrt(abs(goalPos-initPos));
	string temp = ss.str();
	if (find(ALL(temp), '.')==temp.end()) return 1;
	int dis = abs(goalPos-initPos);
	if ((dis-6)%8==0) return 3;
	else return 2;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CubeRoll ___test;
___test.run_test(-1);
}
// END CUT HERE 
