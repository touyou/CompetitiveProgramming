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
#include <fstream>
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

int main() {
	int v1,v2,ret;
	double sum=0;
	vector<int> l(10, 0);
	while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l[0],&l[1],&l[2],&l[3],&l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v1,&v2) != EOF) {
		sum = 0;
		for (int i=0; i<10; i++) {
			sum += l[i];
		}
		sum /= (v1+v2);
		sum *= v1;
		for (int i=0; i<10; i++) {
			sum -= l[i];
			if (sum <= 0) {
				ret = i+1;
				break;
			}
		}
		cout << ret << endl;
	}
	return 0;
}
