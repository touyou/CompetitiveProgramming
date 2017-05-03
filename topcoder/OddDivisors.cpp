// BEGIN CUT HERE
// END CUT HERE
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
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

class OddDivisors {
   public:
   /*int f(int n) {
   	for (int i=n-1; i>=0; i-=2) {
   		if (n%i==0) return i;
   	}
   	return -1;
   }

   long long findSum(int N)
  {
	long long sum = 0;
	int harf = (int)(N/2), tmp;
	cout << harf << endl;
	vector<long long> dp(harf);
	fill(dp.begin(), dp.end(), -1);
	for (int i=0; i<harf; i++) {
		if (dp[i] == -1) {
			tmp = (i+1)*2;
			dp[i] = f(tmp);
			for (int j=i*2+1; j<harf; j *= 2 + 1) dp[j] = dp[i];
		}
	}
	for (int i=1; i<=N; i+=2) sum += i;
	for (int i=0; i<harf; i++) sum += dp[i];
	return sum;
  }*/
  long long sum(long long n) {
  	return n*(n+1);
  }
  long long findSum(int N) {
  	long long r = 0;
  	while (N) {
  		r += sum(N)/2 -sum(N/2);
  		N /= 2;
  	}
  	return r;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; long long Arg1 = 21LL; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 777; long long Arg1 = 201537LL; verify_case(2, Arg1, findSum(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
OddDivisors ___test;
___test.run_test(-1);
}
// END CUT HERE 
