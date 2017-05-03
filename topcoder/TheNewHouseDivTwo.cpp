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

class TheNewHouseDivTwo {
   public:
   bool ok(vi x, vi y, int xp, int yp) {
   	bool flag=false;
   	REP(i,SZ(x)) {
   		if (x[i]==xp) {
   			int yy = y[i];
   			FOR(j,i+1,SZ(x)) {
   				if (x[j]==xp) {
   					if ((yy<yp&&y[j]>yp)||(yy>yp&&y[j]<yp)) {
   						flag=true;
   						break;
   					}
   				}
   			}
   		}
   	}
   	if (flag) {
   		flag = false;
   		REP(i,SZ(y)) {
   			if (y[i]==yp) {
   				int xx = x[i];
   				FOR(j,i+1,SZ(y)) {
   					if (y[j]==yp) {
   						if ((xx<xp&&x[j]>xp)||(xx>xp&&x[j]<xp)) {
   							flag=true;
   							break;
   						}
   					}
   				}
   			}
   		}
   	}
   	return flag;
   }
   int count(vector <int> x, vector <int> y)
  {
	vi xres, yres, xm, ym;
	REP(i,SZ(x)) {
		if (find(xm.begin(),xm.end(),x[i])==xm.end()) xm.PB(x[i]);
		else if (find(xm.begin(),xm.end(),x[i])!=xm.end()) xres.PB(x[i]);
	}
	REP(i,SZ(y)) {
		if (find(ym.begin(),ym.end(),y[i])==ym.end()) ym.PB(y[i]);
		else if (find(ym.begin(),ym.end(),y[i])!=ym.end()) yres.PB(y[i]);
	}
	SORT(yres); SORT(xres);
	vi::iterator end_it = unique(ALL(xres)); xres.erase(end_it, xres.end());
	end_it = unique(ALL(yres)); yres.erase(end_it, yres.end());
	int res=0;
	FOR(i,0,SZ(xres)) {
		FOR(j,0,SZ(yres)) {
			if (ok(x,y,xres[i],yres[j])) res++;
		}
	}
	return res;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 5, 0, 8, -3, 5, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, -4, 2, 1, 1, 11, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 7, 3, 4, 9, 3, 7, 1, 1, 6, 1, 6, 1, 9, 7, 9, 4, 9, 1, 4, 7, 1, 2, 5, 3, 8, 7, 7, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 8, 9, 4, 3, 4, 1, 4, 1, 7, 8, 1, 1, 1, 4, 7, 1, 9, 4, 9, 1, 4, 1, 1, 1, 2, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TheNewHouseDivTwo ___test;
___test.run_test(-1);
}
// END CUT HERE 
