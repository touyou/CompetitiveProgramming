/*sample->AC system test->WA*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

const string p[9] = {"\',.!?","abcABC","defDEF","ghiGHI","jklJKL","mnoMNO","pqrsPQRS","tuvTUV","wxyzWXYZ"};

int parse(char t) {
	switch(t) {
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}

int ad(int c, int n) {
	int t = c%p[n-1].length()-1;
	if (t==-1) t=p[n-1].length()-1;
}

int main() {
	string in;
	while (cin >> in) {
		int c=0, n=0;
		string res="";
		for (int i=0; i<in.length();i++) {
			if (in[i]=='0'&&n!=0) {
				res += p[n-1][ad(c,n)];
				c=0;
				n=0;
			} else if (in[i]=='0'&&n==0) {
				res += " ";
			} else if (c==0) {
				n = parse(in[i]);
				c++;
			} else if (parse(in[i])!=n) {
				res += p[n-1][ad(c,n)];
				c=1;
				n=parse(in[i]);
			} else {
				c++;
			}
		}
		res += p[n-1][ad(c,n)];
		cout << res << endl;
	}
}
