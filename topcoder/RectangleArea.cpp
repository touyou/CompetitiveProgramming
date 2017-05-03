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

class RectangleArea {
   public:
   int minimumQueries(vector <string> known)
  {
	int ans = 0, c = 0, N = known[0].length(), M = known.size();
	string tmp = "";
	for (int i=0; i<N; i++) tmp += 'Y';
	vector <string> good(M, tmp);
	if (known == good) return ans;
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			c = 0;
			if (known[i][j] == 'N') {
				if (i-1 >= 0 && j-1 >= 0 && known[i-1][j-1] == 'Y') c++;
				if (i-1 >= 0 && known[i-1][j] == 'Y') c++;
				if (i-1 >= 0 && j+1 < N && known[i-1][j+1] == 'Y') c++;
				if (j-1 >= 0 && known[i][j-1] == 'Y') c++;
				if (j+1 < N && known[i][j+1] == 'Y') c++;
				if (i+1 < M && j-1 >= 0 && known[i+1][j-1] == 'Y') c++;
				if (i+1 < M && known[i+1][j] == 'Y') c++;
				if (i+1 < M && j+1 < N && known[i+1][j+1] == 'Y') c++;
				if (c >= ) {
					known[i][j] = 'Y';
					if (i-1 >= 0 && j-1 >= 0 && known[i-1][j-1] != 'Y') known[i-1][j-1] = 'Y';
					if (i-1 >= 0 && known[i-1][j] != 'Y') known[i-1][j] = 'Y';
					if (i-1 >= 0 && j+1 < N && known[i-1][j+1] != 'Y') known[i-1][j+1] = 'Y';
					if (j-1 >= 0 && known[i][j-1] != 'Y') known[i][j-1] = 'Y';
					if (j+1 < N && known[i][j+1] != 'Y') known[i][j+1] = 'Y';
					if (i+1 < M && j-1 >= 0 && known[i+1][j-1] != 'Y') known[i+1][j-1] = 'Y';
					if (i+1 < M && known[i+1][j] != 'Y') known[i+1][j] = 'Y';
					if (i+1 < M && j+1 < N && known[i+1][j+1] != 'Y') known[i+1][j+1] = 'Y';
				} else {
					ans++;
					known[i][j] = 'Y';
				}
			}
		}
	}
	for (int i=0; i<M; i++) cout << known[i] << endl;
	return ans;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minimumQueries(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNY",
 "NYN",
 "YNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumQueries(Arg0)); }
	void test_case_2() { string Arr0[] = {"YY",
 "YY",
 "YY",
 "YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimumQueries(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minimumQueries(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minimumQueries(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
RectangleArea ___test;
___test.run_test(-1);
}
// END CUT HERE 
