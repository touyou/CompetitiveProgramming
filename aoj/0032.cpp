#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool rect(int a, int b, int c) {
	return pow(c,2)==pow(b,2)+pow(a,2);
}

int main() {
	int fs, ss, di, rec=0, loz=0;
	while (scanf("%d,%d,%d",&fs,&ss,&di)!=EOF) {
		if (fs!=ss&&rect(fs,ss,di)) rec++;
		else if (!rect(fs,ss,di)&&fs==ss) loz++;
	}
	cout << rec << endl;
	cout << loz << endl;
}
