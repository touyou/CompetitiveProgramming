#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
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
typedef pair<int, int> P;
typedef vector<int> vi;
typedef long long ll;
#define PI 3.14159265358979

class PlatypusPaternity {
public:
    int maxFamily( vector <string> female, vector <string> male, vector <string> sibling ) {
        int fs=female.size(), ms=male.size(), ss=sibling.size(), clen=female[0].length();
        int res=0;
        for (int i=0; i<fs; i++) {
            for (int j=0; j<ms; j++) {
                for (int k=0; k<ss; k++) {
                    int cnt=0;
                    bool flag=true;
                    for (int l=0; l<clen; l++) {
                        if (female[i][l]==male[j][l]&&male[j][l]==sibling[k][l]&&female[i][l]=='Y') {
                            cnt++;
                        } else if (sibling[k][l]=='Y'&&(female[i][l]=='N'||male[j][l]=='N')) {
                            flag=false;
                        }
                    }
                    if (flag&&cnt!=0) cnt+=2;
                    res=max(res,cnt);
                }
            }
        }
        return res;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
