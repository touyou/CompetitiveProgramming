// BEGIN CUT HERE
// PROBLEM STATEMENT
// Let's say you have a binary string such as the following:
// 
// 011100011
// 
// One way to encrypt this string is to add to each digit the 
// sum of its adjacent digits.  For example, the above string 
// would become:
// 
// 123210122
// 
// In particular, if P is the original string, and Q is the 
// encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for 
// all digit positions i.  Characters off the left and right 
// edges of the string are treated as zeroes.
// 
// An encrypted string given to you in this format can be 
// decoded as follows (using 123210122 as an example):
// 
// Assume P[0] = 0.
// Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P
// [1] = 1.
// Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we 
// know that P[2] = 1.
// Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we 
// know that P[3] = 1.
// Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 
// 0, P[7] = 1, and P[8] = 1.
// We check our work by noting that Q[8] = P[7] + P[8] = 1 + 
// 1 = 2.  Since this equation works out, we are finished, 
// and we have recovered one possible original string.
// 
// Now we repeat the process, assuming the opposite about P[0]:
// 
// Assume P[0] = 1.
// Because Q[0] = P[0] + P[1] = 1 + P[1] = 0, we know that P
// [1] = 0.
// Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we 
// know that P[2] = 1.
// Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 
// 3, which leads us to the conclusion that P[3] = 2.  
// However, this violates the fact that each character in the 
// original string must be '0' or '1'.  Therefore, there 
// exists no such original string P where the first digit is 
// '1'.
// 
// Note that this algorithm produces at most two decodings 
// for any given encrypted string.  There can never be more 
// than one possible way to decode a string once the first 
// binary digit is set.
// 
// Given a string message, containing the encrypted string, 
// return a vector <string> with exactly two elements.  The 
// first element should contain the decrypted string assuming 
// the first character is '0'; the second element should 
// assume the first character is '1'.  If one of the tests 
// fails, return the string "NONE" in its place.  For the 
// above example, you should return {"011100011", "NONE"}.
// 
// DEFINITION
// Class:BinaryCode
// Method:decode
// Parameters:string
// Returns:vector <string>
// Method signature:vector <string> decode(string message)
// 
// 
// CONSTRAINTS
// -message will contain between 1 and 50 characters, 
// inclusive.
// -Each character in message will be either '0', '1', '2', 
// or '3'.
// 
// 
// EXAMPLES
// 
// 0)
// "123210122"
// 
// Returns: { "011100011",  "NONE" }
// 
// The example from above.
// 
// 1)
// "11"
// 
// Returns: { "01",  "10" }
// 
// We know that one of the digits must be '1', and the other 
// must be '0'.  We return both cases.
// 
// 2)
// "22111"
// 
// Returns: { "NONE",  "11001" }
// 
// Since the first digit of the encrypted string is '2', the 
// first two digits of the original string must be '1'.  Our 
// test fails when we try to assume that P[0] = 0.
// 
// 3)
// "123210120"
// 
// Returns: { "NONE",  "NONE" }
// 
// This is the same as the first example, but the rightmost 
// digit has been changed to something inconsistent with the 
// rest of the original string.  No solutions are possible.
// 
// 4)
// "3"
// 
// Returns: { "NONE",  "NONE" }
// 
// 5)
// "12221112222221112221111111112221111"
// 
// Returns: { "01101001101101001101001001001101001",  
// "10110010110110010110010010010110010" }
// 
// END CUT HERE
#line 124 "BinaryCode.cpp"
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

/*class BinaryCode {
	public:
	vector <string> decode(string message) {
		vector<string> ans(2);
		vector<int> p0, p1;
		p0.push_back(0); p1.push_back(1);
		int i=0;
		while (true) {
			if (i == 0) {
				p0.push_back((int)message[i] - p0[0]);
			} else if (i != message.length()-1) {
				cout << (int)message[i]-p0[i]-p0[i-1] << endl;
				p0.push_back((int)message[i] - (p0[i]+p0[i-1]));
			}
			if (p0[i] != 0 && p0[i] != 1) {
				ans[0] = "NONE";
				break;
			} else if (i == message.length()-1) {
				ans[0] = "";
				for (int i = 0; i < message.length(); i++)
					ans[0] += (char)p0[i];
				break;
			}
			i++;
		}
		i=0;
		while (true) {
			if (i == 0) {
				p1.push_back((int)message[i] - p1[0]);
			} else if (i != message.length()-1) {
				p1.push_back((int)message[i] - (p1[i]+p1[i-1]));
			}
			if (p1[i] != 0 && p1[i] != 1) {
				ans[0] = "NONE";
				break;
			} else if (i == message.length()-1) {
				ans[0] = "";
				for (int i = 0; i < message.length(); i++)
					ans[0] += (char)p1[i];
				break;
			}
			i++;
		}
		return ans;
	}
};
*/
class BinaryCode {
	public:
	vector <string> decode(string message) {
		string s = message;
		int n = s.size(), i, a[99];
		vector<string> ret;
		ret.clear();
		a[0] = 0;
		for (a[1]=0;a[1]<2;a[1]++) {
			for (i=1;i<=n;i++) a[i+1] = s[i-1]-48-a[i]-a[i-1];
			string res = "";
			for (i=1;i<=n;i++) res += (char)(a[i]+48);
			for (i=1;i<=n;i++)
				if (a[i] < 0 || a[i] > 1) res = "NONE";
			if (a[n+1] != 0) res = "NONE";
			ret.push_back(res);
		}
		return ret;
	}
};
