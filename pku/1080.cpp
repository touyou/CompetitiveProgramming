#include <cstdio>
#include <iostream>
using namespace std;

int calc_score(string a, string b) {
	int res = 0;
	for (int i=0; i<a.length(); i++) {
		if (a[i] == b[i]) res += 5;
		else if (a[i] == 'A' && (b[i] == 'C' || b[i] == 'T')) res -= 1;
	}

int main() {
}

/*
-----------------+
 |  A  C  G  T  -|
-+---------------+
A|  5 -1 -2 -1 -3|
C| -1  5 -3 -2 -4|
G| -2 -3  5 -2 -2|
T| -1 -2 -2  5 -1|
-| -3 -4 -2 -1  *|
-----------------+

 A G T G A T G
 G T T A G
少ない方の好きな場所にSpaceを入れる
①　なるべくスペースはTと組み合わさるようにする
②　なるべく同じ数字同士が組み合わさるようにする
上の最適解は
 - G T T A - G
*/