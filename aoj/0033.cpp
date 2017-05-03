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

bool solve(vector<int> data) {
	vector<int> B(1, 0), C(1, 0);
	int b=-1, c=-1;
	for (int i=0; i<10; i++) {
		if (b == -1) {
			B[0] = data[i];
			b++;
		} else if (B[b] > data[i]) {
			if (c == -1) {
				C[0] = data[i];
				c++;
			} else if (C[c] < data[i]) {
				C.push_back(data[i]);
				c++;
			} else {
				return false;
			}
		} else {
			B.push_back(data[i]);
			b++;
		}
	}
	return true;
}

int main() {
	int N; cin >> N;
	vector<int> data(10); bool b;
	for (int i=0; i<N; i++) {
		cin >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5] >> data[6] >> data[7] >> data[8] >> data[9];
		b = solve(data);
		if (b) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
