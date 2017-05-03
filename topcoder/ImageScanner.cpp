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

// Library ImageToScan::scan(int n) -> string

class ImageScanner {
	public:
		vector <string> restore(int H, int W, int nb, int nLetter) {
			vector <string> res(H);
			int harf = H/2;
			res[harf] = ImageToScan::scan(harf);
			for (int i=0; i<W; i++)
				if (res[harf][i] == '1') nb--;

			int lnb = nb/(H-1);
			vector<int> bp(lnb);
			for (int i=0; i<H; i++) {
				if (H == harf) continue;
				for (int j=0; j<)
			}
			return res;
		}
};
