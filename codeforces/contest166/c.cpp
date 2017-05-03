#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define inf 1000000000
using namespace std;
int n, x;
int array[500];
int main() {
    scanf("%d%d",&n,&x);
    vector<int> pos;
    for (int i=0; i<n; i++) {
        scanf("%d",&array[i]);
    }
    sort(array,array+n);
    for (int i=0; i<n; i++) if (x==array[i]) pos.push_back(i+1);
    if (pos.size()==0) {
        if (x>array[n-1]) {
            printf("%d\n",n+1);
        } else if (x<array[0]&&n==1) {
            puts("1");
        } else if (x<array[0]) {
            printf("%d\n",n+1);
        } else {
            for (int i=1; i<n; i++) {
                if (array[i-1]<x&&x<array[i]) {
                    int l=i, r=n-i;
                    if (r<=l) {
                        printf("%d\n",abs(l-r)+1);
                    } else {
                        printf("%d\n",r-l);
                    }
                    break;
                }
            }
       }
    } else {
        int res=inf;
        for (int i=0; i<pos.size(); i++) {
            int c1=n-pos[i], c2=pos[i]-1;
            if (-1<c1-c2&&c1-c2<=1) res=min(res,0);
            else {
                if (c1<=c2) {
                    res=min(res,c2-c1);
                } else {
                    res=min(res,c1-c2-1);
                }
            }
        }
        printf("%d\n",res);
    }
}
