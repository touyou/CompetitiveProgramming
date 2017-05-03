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
int main() {
    int a, b, c;
    int w[21][21][21];
    for (int i=0; i<21; i++) for (int j=0; j<21; j++) w[0][i][j]=1;
    for (int i=0; i<21; i++) for (int j=0; j<21; j++) w[i][0][j]=1;
    for (int i=0; i<21; i++) for (int j=0; j<21; j++) w[i][j][0]=1;
    for (int i=1; i<21; i++) for (int j=1; j<21; j++) for (int k=1; k<21; k++) {
        if (i<j&&j<k) w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
        else w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
    }
    while (scanf("%d%d%d",&a,&b,&c)!=EOF) {
        if (a==-1&&b==-1&&c==-1) break;
        int res;
        if (a<=0||b<=0||c<=0) res=1;
        else if (a>20||b>20||c>20) res=w[20][20][20];
        else res=w[a][b][c];
        printf("w(%d, %d, %d) = %d\n",a,b,c,res);
    }
}
