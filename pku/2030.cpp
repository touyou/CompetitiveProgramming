#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int w,h;
int dx[2]={-1,0};
int dy[2]={0,-1};
string mat[70];
string dp[70][70];
int main() {
    while (scanf("%d%d",&w,&h)){
        if (!w&&!h) break;
        for (int i=0; i<70; i++) for (int j=0; j<70; j++) dp[i][j]="";
        for (int i=0; i<h; i++) cin>>mat[i];
        bool bef=false;
        if ('0'<mat[0][0]&&mat[0][0]<='9') {
            bef=true;
            dp[0][0]=mat[0][0];
        }
        for (int i=1; i<w; i++) {
            if (bef&&'0'<=mat[0][i]&&mat[0][i]<='9') {
                dp[0][i]=dp[0][i-1]+mat[0][i];
            } else if ('0'<mat[0][i]&&mat[0][i]<='9') {
                dp[0][i]=mat[0][i];
                bef=true;
            } else if (mat[0][i]!='0') {
                bef=false;
            }
        }
        for (int i=1; i<h; i++) {
            for (int j=0; j<w; j++) {
                if ('0'<=mat[i][j]&&mat[i][j]<='9') {
                    for (int k=0; k<2; k++) {
                        int nx=i+dx[k], ny=j+dy[k];
                        if (nx>=0&&nx<h&&ny>=0&&ny<w) {
                            int len=dp[i][j].length(), len2=dp[nx][ny].length()+1;
                            if (len<len2&&len2!=1) dp[i][j]=dp[nx][ny]+mat[i][j];
                            else if (len==len2&&dp[i][j]<dp[nx][ny]+mat[i][j]) {
                                dp[i][j]=dp[nx][ny]+mat[i][j];
                            }
                        }
                    }
                    if (dp[i][j].length()==0&&mat[i][j]!='0') dp[i][j]=mat[i][j];
                }
            }
        }
        int rlen=0;
        string rstr;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (rlen<dp[i][j].length()) {
                    rlen=dp[i][j].length();
                    rstr=dp[i][j];
                } else if (rlen==dp[i][j].length()&&rstr<dp[i][j]) {
                    rstr=dp[i][j];
                }
            }
        }
        cout<<rstr<<endl;
    }
}
