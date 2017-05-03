// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Sometimes when computer programs have a limited number of 
// colors to use, they use a technique called dithering.  
// Dithering is when you use a pattern made up of different 
// colors such that when the colors are viewed together, they 
// appear like another color.  For example, you can use a 
// checkerboard pattern of black and white pixels to achieve 
// the illusion of gray.
// 
// 
// 
// You are writing a program to determine how much of the 
// screen is covered by a certain dithered color.  Given a 
// computer screen where each pixel has a certain color, and 
// a list of all the solid colors that make up the dithered 
// color, return the number of pixels on the screen that are 
// used to make up the dithered color.  Each pixel will be 
// represented by a character in screen.  Each character in 
// screen and in dithered will be an uppercase letter 
// ('A'-'Z') representing a color.
// 
// 
// 
// Assume that any pixel which is a color contained in 
// dithered is part of the dithered color.
// 
// 
// DEFINITION
// Class:ImageDithering
// Method:count
// Parameters:string, vector <string>
// Returns:int
// Method signature:int count(string dithered, vector 
// <string> screen)
// 
// 
// CONSTRAINTS
// -dithered will contain between 2 and 26 upper case letters 
// ('A'-'Z'), inclusive.
// -There will be no repeated characters in dithered.
// -screen will have between 1 and 50 elements, inclusive.
// -Each element of screen will contain between 1 and 50 
// upper case letters ('A'-'Z'), inclusive.
// -All elements of screen will contain the same number of 
// characters.
// 
// 
// EXAMPLES
// 
// 0)
// "BW"
// {"AAAAAAAA",
//  "ABWBWBWA",
//  "AWBWBWBA",
//  "ABWBWBWA",
//  "AWBWBWBA",
//  "AAAAAAAA"}
// 
// Returns: 24
// 
// Here, our dithered color could consist of black (B) and 
// white (W) pixels, composing a shade of gray.  In the 
// picture, there is a dithered gray square surrounded by 
// another color (A).
// 
// 1)
// "BW"
// {"BBBBBBBB",
//  "BBWBWBWB",
//  "BWBWBWBB",
//  "BBWBWBWB",
//  "BWBWBWBB",
//  "BBBBBBBB"}
// 
// Returns: 48
// 
// Here is the same picture, but with the outer color 
// replaced with black pixels.  Although in reality, the 
// outer pixels do not form a dithered color, your algorithm 
// should still assume they are part of the dithered pattern.
// 
// 2)
// "ACEGIKMOQSUWY"
// {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"}
// 
// Returns: 150
// 
// A picture of vertical stripes, every other stripe is 
// considered part of the dithered color.
// 
// 3)
// "CA"
// {"BBBBBBB",
//  "BBBBBBB",
//  "BBBBBBB"}
// 
// Returns: 0
// 
// The dithered color is not present.
// 
// 4)
// "DCBA"
// {"ACBD"}
// 
// Returns: 4
// 
// The order of the colors doesn't matter.
// 
// END CUT HERE
#line 118 "ImageDithering.cpp"
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

class ImageDithering {
	public:
	int count(string dithered, vector <string> screen) {
		int c=0;
		for (int i=0; i<dithered.length(); i++) {
			for (int j=0; j<screen.size(); j++) {
				for (int k=0; k<screen[j].length(); k++) {
					if (dithered[i] == screen[j][k])
					{
						c++;
					}
				}
			}
		}
		return c;
	}
};
