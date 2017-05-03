#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;
int solve(int s) {
    string num;
    stringstream ss;
    ss<<s*s;
    num=ss.str();
    if (num.length()<8) {
        while (num.length()<8) num="0"+num;
    }
    string res="";
    for (int i=2; i<6; i++) res+=num[i];
    stringstream ss2;
    ss2<<res;
    ss2>>s;
    return s;
}
int main() {
    int n,s;
    scanf("%d",&n);
    for (int ix=1; ix<=n; ix++) {
        scanf("%d",&s);
        printf("Case %d:\n",ix);
        for (int i=0; i<10; i++) {
            s=solve(s);
            printf("%d\n",s);
        }
    }
}
