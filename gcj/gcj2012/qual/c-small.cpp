#include <cstdio>
#include <set>
#include <map>
#include <sstream>
using namespace std;
typedef pair<int, int> P;
int main() {
    int t; scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        int a, b; scanf("%d%d",&a,&b);
        int x;
        string st, st2;
        set<P> res;
        for (int i=a; i<=b; i++) {
            stringstream s1; s1<<i; s1>>st;
            int len=st.length();
            if (len==1) continue;
            for (int j=0; j<len-1; j++) {
                char temp=st[0];
                for (int k=0; k<len-1; k++) st[k]=st[k+1];
                st[len-1]=temp;
                stringstream s2; s2<<st; s2>>x;
                if (i<x&&x<=b) {
                    res.insert(P(i,x));
                }
            }
        }
        printf("Case #%d: %d\n",ix,res.size());
    }
}