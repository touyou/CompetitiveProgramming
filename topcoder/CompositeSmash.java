// BEGIN CUT HERE
// PROBLEM STATEMENT
// Toastwoman wants to be a magical girl. As training, she wants to make a ball that contains an integer target.


Initially she has a ball that contains an integer N. She can smash a ball that contains a composite number (see notes for definition) and break it into two balls. Each new ball will also contain an integer. If she smashes a ball that contains a composite number x and it breaks into two balls that contain y and z, it satisfies y &ge 2, z &ge 2 and yz = x. For example, if she smashes a ball that contains 12, it breaks into 2 and 6 or 3 and 4. Toastwoman can control the ball she smashes, but she can't control the numbers in the two new balls when there are multiple pairs of (y, z) that satisfy the above conditions. She can apply the described ball smash operation arbitrary number of times, but she can't smash a ball that contains a non-composite number.


If she can always make a ball that contains target, return "Yes" (quotes for clarity). Otherwise, return "No" (quotes for clarity).


DEFINITION
Class:CompositeSmash
Method:thePossible
Parameters:int, int
Returns:String
Method signature:String thePossible(int N, int target)


NOTES
-A positive integer x is called a composite number if it has at least one divisor other than 1 and x. For example, 4 and 6 are composite numbers, while 1 and 5 are not composite numbers.


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-target will be between 2 and 100,000, inclusive.


EXAMPLES

0)
517
47

Returns: "Yes"

If?she?smashes?517,?it?breaks?into?11?and?47.

1)
8
4

Returns: "Yes"

If?she?smashes?8,?it?breaks?into?2?and?4.

2)
12
6

Returns: "No"

If?she?smashes?12?and?it?breaks?into?3?and?4,?she?can't?make?6.

3)
5
8

Returns: "No"



4)
100000
100000

Returns: "Yes"

She already has target.

5)
5858
2

Returns: "Yes"



6)
81461
2809

Returns: "No"



7)
65536
256

Returns: "No"

// END CUT HERE
import java.util.*;
public class CompositeSmash {
	public String thePossible(int N, int target) {
		
	}
	public static void main(String[] args) {
		CompositeSmash temp = new CompositeSmash();
		System.out.println(temp.thePossible(int N, int target));
	}
}
