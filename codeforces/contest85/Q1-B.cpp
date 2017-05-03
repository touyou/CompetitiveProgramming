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
	string str; getline(cin, str);
	int dot=0;
	for (int i=0; i<str.length(); i++) {
		if (str[i]==',') {
			str.insert(i+1, " ");
		} else if (str[i]==' '&&i-1>=0&&str[i-1]==' ') {
			str.erase(i, 1);
		} else if (dot!=3&&str[i]=='.') {
			dot++;
		} else if (dot==3&&str[i]=='.') {
			str.insert(i, " ");
			dot=0;
		}
		cout << str[i] << endl;
	}
	cout << str << endl;
}
