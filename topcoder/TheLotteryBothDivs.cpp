// BEGIN CUT HERE
// PROBLEM STATEMENT
// Farmer John wants to buy a lottery ticket. Before he buys 
// a ticket, Fox Brus decided to calculate the probability 
// that John will get a prize.
// 
// 
// There are 1,000,000,000 types of lottery tickets. They are 
// numbered "000000000" to "999999999" (they may have leading 
// zeroes). Each type of ticket has an equal probability of 
// being bought by John. You are given a vector <string> 
// goodSuffixes. If the number written on John's ticket has 
// at least one element of goodSuffixes as a suffix, he will 
// get a prize.
// 
// 
// Return the probability that John will get a prize.
// 
// DEFINITION
// Class:TheLotteryBothDivs
// Method:find
// Parameters:vector <string>
// Returns:double
// Method signature:double find(vector <string> goodSuffixes)
// 
// 
// NOTES
// -The returned value must have an absolute or relative 
// error less than 1e-9.
// -A suffix of a string is obtained by removing zero or more 
// contiguous characters from the beginning of the string.
// 
// 
// CONSTRAINTS
// -goodSuffixes will contain between 1 and 50 elements, 
// inclusive.
// -Each element of goodSuffixes will contain between 1 and 9 
// characters, inclusive.
// -Each character in goodSuffixes will be a digit ('0'-'9').
// 
// 
// EXAMPLES
// 
// 0)
// {"4"}
// 
// Returns: 0.1
// 
// John will get a prize if the last digit is '4'. It happens 
// with probability 0.1.
// 
// 1)
// {"4", "7"}
// 
// Returns: 0.2
// 
// 
// 
// 2)
// {"47", "47"}
// 
// Returns: 0.01
// 
// goodSuffixes may contain duplicate elements.
// 
// 3)
// {"47", "58", "4747", "502"}
// 
// Returns: 0.021
// 
// 
// 
// 4)
// {"8542861", "1954", "6", "523", "000000000", "5426", "8"}
// 
// Returns: 0.201100101
// 
// 
// 
// END CUT HERE
#line 82 "TheLotteryBothDivs.cpp"
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

class TheLotteryBothDivs {
	public:
	vector<string> sorts(vector<string> str) {
		string temp;
		for (int i=0; i<str.size(); i++) {
			for (int j=i; j<str.size(); j++) {
				if (str[i].size() > str[j].size()) {
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
				}
			}
		}
		return str;
	}
	double find(vector <string> goodSuffixes) {
		goodSuffixes = sorts(goodSuffixes);
		double p=0; int size=0; bool ok = true; int ten = 1; 
		vector<int> sizes; vector<string> old; string temp;
		for (int i=0; i<goodSuffixes.size(); i++) {
			size = goodSuffixes[i].size();
			cout << size << ":" << goodSuffixes[i] << endl;
			if (i != 0) {
				for (int j=0; j<sizes.size(); j++) {
					temp = "";
					for (int k=size-sizes[j]; k<size; k++) temp+= goodSuffixes[i][k];
					if (temp == old[j]) {
						ok = false;
						break;
					}
				}
			}
			if(ok) {
				for (int j=0; j<size; j++) ten *= 10;
				p += (double)1/ten;
				cout << p << endl;
			}
			old.push_back(goodSuffixes[i]); sizes.push_back(size);
			ok = true; ten = 1;
		}
		return p;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheLotteryBothDivs __test;
	__test.run_test(-1);
}
// END CUT HERE
