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
#define REP(i,a,n) for (int i=(a); i<(n); i++)

class Underprimes {
   public:
   int howMany(int A, int B)
  {
	int cnt=0;
	vector<int> prime(100,0);
	prime[0]=-1;prime[1]=-1;
	for (int i=2; i*i<100; i++) {
		if (prime[i]==0) {
			for (int j=i*i; j<100; j+=i) {
					prime[j]=-1;
			}
		}
	}
	for(int i=A; i<=B; i++) {
		int cnt2=0,num=i;
		while (num%2==0) {
			num/=2;
			cnt2++;
		}
		int save=num;
		for (int j=3; j*j<=save; j+=2) {
			while (num%j==0) {
				num/=j;
				cnt2++;
			}
		}
		if (num>1) cnt2++;
		if (prime[cnt2]==0) cnt++;
	}
	return cnt;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 105; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Underprimes ___test;
___test.run_test(-1);
}
// END CUT HERE 
