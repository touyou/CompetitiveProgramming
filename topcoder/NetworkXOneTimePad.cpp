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


class NetworkXOneTimePad {
public:
	string sxor(string a, string b) {
		string res = "";
		for (int i=0; i<a.length(); i++) {
			if (a[i] == b[i]) res += '0';
			else res += '1';
		}
		return res;
	}
  int crack( vector <string> plaintexts, vector <string> ciphertexts ) {
		set<string> keys;
		for (int i=0; i<plaintexts.size(); i++) {
			for (int j=0; j<ciphertexts.size(); j++) {
				string key = sxor(plaintexts[i], ciphertexts[j]);
				bool flag = true;
				for (int k=0; k<ciphertexts.size(); k++) {
					if (find(plaintexts.begin(), plaintexts.end(), sxor(ciphertexts[k], key))==plaintexts.end()) {
						flag = false;
						break;
					}
				}
				if (flag) keys.insert(key);
			}
		}
		return keys.size();
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "111", "010", "101", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"011", "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  NetworkXOneTimePad ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
