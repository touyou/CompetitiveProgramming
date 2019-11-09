#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 1e-9
#define PI 3.14159265358979

class RandomColoringDiv2 {
public:
   int getCount( int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2 ) {
        int cnt=0;
        for (int r=0; r<maxR; r++) {
            for (int g=0; g<maxG; g++) {
                for (int b=0; b<maxB; b++) {
                    if (abs(startR-r)>d2) continue;
                    if (abs(startG-g)>d2) continue;
                    if (abs(startB-b)>d2) continue;
                    if (abs(startR-r)<d1&&abs(startG-g)<d1&&abs(startB-b)<d1) continue;
                    cnt++;
                }
            }
        }
        return cnt;
   }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
