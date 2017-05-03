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
	int T,N;
	cin >> T;
	for (int i=1; i<=T; i++) {
		cin >> N;
		vector<int> pos;
		vector<char> lob;
		char clo;
		int btn, ans=0, op=1, bp=1, ol=0, bl=0, wait, move, stay;
		for (int j=0; j<N; j++) {
			cin >> clo >> btn;
			lob.push_back(clo);
			pos.push_back(btn);
		}
		for (int j=0; j<N; j++) {
			if (lob[j] == 'O') {
				wait = ans-ol;
				move = abs(pos[j]-op);
				stay = wait-move;
				if (stay>=0) ans += 1;
				else ans += move+1-wait;
				ol = ans;
				op = pos[j];
			} else {
				wait = ans-bl;
				move = abs(pos[j]-bp);
				stay = wait-move;
				if (stay>=0) ans += 1;
				else ans += move+1-wait;
				bl = ans;
				bp = pos[j];
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	} 
}
