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

class NumericalPerfectionLevel {
   public:
   int isprime(long long n) {
   	if (n<2) return 0;
   	if (n==2) return 1;
   	for (long long i=2;i*i<=n;i++) {
   		if (n%i==0) return 0;
   	}
   	return 1;
   }
   int getLevel(long long N)
  {
	//long double res = (long double)N;
	if (isprime(N)) return 0;
	int cnt=0;
	/*while (res>=2.0) {
		res=sqrt(sqrt(res));
		if (res>=2.0) cnt++;
	}*/
	for (long long i=2; i*i<=N; i++) {
		while (N%i==0) {
			N/=i;
			cnt++;
		}
	}
	if (N!=1) cnt++;
	int ans=0;
	while (cnt/4>0) {
		cnt/=4;
		ans++;
	}
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arg1 = 0; verify_case(0, Arg1, getLevel(Arg0)); }
	void test_case_1() { long long Arg0 = 144LL; int Arg1 = 1; verify_case(1, Arg1, getLevel(Arg0)); }
	void test_case_2() { long long Arg0 = 1152LL; int Arg1 = 1; verify_case(2, Arg1, getLevel(Arg0)); }
	void test_case_3() { long long Arg0 = 1679616LL; int Arg1 = 2; verify_case(3, Arg1, getLevel(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
NumericalPerfectionLevel ___test;
___test.run_test(-1);
}
// END CUT HERE 
