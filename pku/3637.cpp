#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        int n;
        scanf("%d",&n);
        vector<int> doll(n);
        for (int i=0; i<n; i++) scanf("%d",&doll[i]);
        sort(doll.begin(), doll.end());
        if (doll.size()<3) {
            printf("0\n");
            continue;
        }
        reverse(doll.begin(), doll.end());
        int res=0;
        for (int i=2; i<doll.size(); i+=3) res+=doll[i];
        printf("%d\n",res);
    }
}

