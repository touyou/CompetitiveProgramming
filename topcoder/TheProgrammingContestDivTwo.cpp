// BEGIN CUT HERE
// PROBLEM STATEMENT
// Farmer John and Fox Brus are participating in a 
// programming contest as a team.
// 
// 
// The duration of the contest is T minutes and they are 
// given N tasks. Solutions can be submitted at any time 
// during the contest, including exactly T minutes after the 
// start of the contest. It takes them requiredTime[i] 
// minutes to solve the i-th task.
// 
// 
// The score in this contest is represented by two numbers, 
// solved and penalty. Initially both numbers are 0. If they 
// solve a task t minutes after the start of the contest, 
// solved increases by 1 and penalty increases by t. Two 
// scores are compared by solved first. If two scores have 
// different solved, the score with bigger solved is better. 
// If two scores have the same solved, the score with smaller 
// penalty is better.
// 
// 
// Return a vector <int> containing exactly two integers that 
// describes the best score they can get. The first integer 
// of the return value must represent solved and the second 
// integer must represent penalty.
// 
// DEFINITION
// Class:TheProgrammingContestDivTwo
// Method:find
// Parameters:int, vector <int>
// Returns:vector <int>
// Method signature:vector <int> find(int T, vector <int> 
// requiredTime)
// 
// 
// CONSTRAINTS
// -T will be between 1 and 100,000, inclusive.
// -requiredTime will contain between 1 and 50 elements, 
// inclusive.
// -Each element of requiredTime will be between 1 and 
// 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 74
// {47}
// 
// Returns: {1, 47 }
// 
// They can solve the task. solved will be 1 and penalty will 
// be 47.
// 
// 1)
// 74
// {4747}
// 
// Returns: {0, 0 }
// 
// They don't have time enough to solve the task.
// 
// 2)
// 47
// {8, 5}
// 
// Returns: {2, 18 }
// 
// The order is important. If they solve task 0 first and 
// task 1 second, solved will be 2 and penalty will be 21. If 
// they solve task 1 first and task 0 second, solved will be 
// 2 and penalty will be 18.
// 
// 3)
// 47
// {12, 3, 21, 6, 4, 13}
// 
// Returns: {5, 86 }
// 
// 
// 
// 4)
// 58
// {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8}
// 
// Returns: {10, 249 }
// 
// 
// 
// 5)
// 100000
// {100000}
// 
// Returns: {1, 100000 }
// 
// END CUT HERE
#line 100 "TheProgrammingContestDivTwo.cpp"
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

class TheProgrammingContestDivTwo {
	public:
	vector <int> find(int T, vector <int> requiredTime) {
		int s = 0, p = 0, time = 0;
		sort(requiredTime.begin(), requiredTime.end());
		for (int i = 0; i < requiredTime.size(); i++) {
			time += requiredTime[i];
			if (time <= T) {
				p+=time;
				s++;
			}
		}
		vector<int> ans;
		ans.push_back(s); ans.push_back(p);
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 74; int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 47 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 74; int Arr1[] = {4747}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arr1[] = {8, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 18 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {12, 3, 21, 6, 4, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 86 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 58; int Arr1[] = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 249 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arr1[] = {100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 100000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheProgrammingContestDivTwo __test;
	__test.run_test(-1);
}
// END CUT HERE
