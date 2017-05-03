#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int w, q;
int there[101];
int main() {
    while (scanf("%d%d",&w,&q)) {
        if (!w&&!q) break;
        memset(there, -1, sizeof(there));
        for (int i=0; i<q; i++) {
            char c; cin>>c;
            if (c=='s') {
                int id, cw; scanf("%d%d",&id,&cw);
                int b=-1;
                for (int j=0; j<w; j++) {
                    if (there[j]!=-1) continue;
                    int cnt=0, temp=j;
                    while (j<w&&there[j]==-1) {
                        j++; cnt++;
                    }
                    if (cnt>=cw) {
                        b=temp;
                        for (int k=b; k<b+cw; k++) there[k]=id;
                        break;
                    }
                }
                if (b==-1) puts("impossible");
                else printf("%d\n",b);
            } else {
                int id; scanf("%d",&id);
                for (int j=0; j<w; j++) if (there[j]==id) there[j]=-1;
            }
        }
        puts("END");
    }
}
