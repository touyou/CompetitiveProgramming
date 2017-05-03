#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
	// "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
	int n; cin >> n;
	queue<string> can;
	can.push("Sheldon"); can.push("Leonard"); can.push("Penny"); can.push("Rajesh"); can.push("Howard");
	string tmp;
	for (int i=0; i<n; i++) {
		tmp = can.front();
		can.pop();
		can.push(tmp); can.push(tmp);
	}
	cout << tmp << endl;
}
