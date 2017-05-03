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


class TheBlackJackDivOne {
public:
	int toInt(string card) {
		if (isdigit(card[0])) return card[0]-'0';
		else if (isalnum(card[0])) {
			if (card[0] == 'A') return 11;
			else return 10;
		}
	}
  double expected( vector <string> cards ) {
    double res = 0.0;
	vector<int> deck(13, 4);
	int done = 0;
	for (int i=0; i<cards.size(); i++) {
		done += toInt(cards[i]);
		deck[toInt(cards[i])-1]--;
	}
	if (done >= 21) return 0;
	int ue = 21 - done;
	vector<int> tmp;
	for (int i=0; i<13; i++)
		for (int j=0; j<deck[i]; j++) tmp.push_back(i+1);
    vector<int> ns(13, 0);
	int rcnt = 0;
	for (int i=0; i<tmp.size(); i++) {
		if (tmp[i] >= ue) {
			ns[0]++;
			rcnt++;
			continue;
		}
		for (int j=i+1; j<tmp.size(); j++) {
			int sum = tmp[i] + tmp[j];
			if (sum >= ue) {
				ns[1]++;
				rcnt++;
				continue;
			}
			int mai = 1;
			int x = 1;
			while (sum < ue) {
				mai++;
				sum += tmp[j+x];
				x++;
			}
			if (sum >= ue) {
				ns[mai]++;
				rcnt++;
			}
		}
	}
	for (int i=0; i<ns.size(); i++) {
		res += (double)(i+1) * ((double)ns[i] / (double)rcnt);
	}
	return res;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
	void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
	void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
	void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

// END CUT HERE
	
};


// BEGIN CUT HERE
int
main() {
  TheBlackJackDivOne ___test;
  ___test.run_test( -1 ); 
}
// END CUT HERE
