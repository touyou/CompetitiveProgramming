// PROBLEM STATEMENT
// Computers tend to store dates and times as single numbers 
// which represent the number of seconds or milliseconds 
// since a particular date.  Your task in this problem is to 
// write a method whatTime, which takes an int, seconds, 
// representing the number of seconds since midnight on some 
// day, and returns a string formatted as "<H>:<M>:<S>".  
// Here, <H> represents the number of complete hours since 
// midnight, <M> represents the number of complete minutes 
// since the last complete hour ended, and <S> represents the 
// number of seconds since the last complete minute ended.  
// Each of <H>, <M>, and <S> should be an integer, with no 
// extra leading 0's.  Thus, if seconds is 0, you should 
// return "0:0:0", while if seconds is 3661, you should 
// return "1:1:1".
// 
// DEFINITION
// Class:Time
// Method:whatTime
// Parameters:int
// Returns:string
// Method signature:string whatTime(int seconds)
// 
// 
// CONSTRAINTS
// -seconds will be between 0 and 24*60*60 - 1 = 86399, 
// inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 0
// 
// Returns: "0:0:0"
// 
// 1)
// 3661
// 
// Returns: "1:1:1"
// 
// 2)
// 5436
// 
// Returns: "1:30:36"
// 
// 3)
// 86399
// 
// Returns: "23:59:59"
// 
#line 53 "Time.cpp"
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

class Time {
	public:
	string whatTime(int seconds) {
		int h = 0, m = 0, s = 0;
		if (seconds >= 3600) h = seconds/3600;
		seconds -= h*3600;
		if (seconds >= 60) m = seconds/60;
		seconds -= m*60;
		s = seconds;
		stringstream ss; 
		ss << h << ":" << m << ":" << s;
		string time = ss.str();
		return time;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
