#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str1[4001], str2[4001];
int main() {
    while (scanf("%s%s",&str1,&str2)!=EOF) {
        int res=0;
        for (int off=-1*(int)strlen(str1); off<=(int)strlen(str2); off++) {
            int len=0;
            for (int i=max(off,0); i<min(strlen(str1)+off,strlen(str2)); i++) {
                if (str1[i-off]==str2[i]) {
                    len++;
                    res=max(res,len);
                } else {
                    len=0;
                }
            }
        }
        printf("%d\n",res);
    }
}
