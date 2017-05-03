#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
string s;
bool ispal(int a, int b) {
    int len=s.length();
    for (int i=a, j=a+b-1; i<a+b; i++, j--) {
        if (s[i]!=s[j]) return false;
    }
    return true;
}
ll pals[2000][2001];
ll dp[2000];
int main() {
    cin>>s;
    int len=s.length();
    for (int i=0; i<len; i++) {
        for (int j=1; j<=len-i; j++) {
            if (j==1||ispal(i,j)) pals[i][j]=1;
        }
    }
    pals[0][len]=0;
    dp[len-1]=1;
    for (int i=len-2; i>=0; i--) {
        ll sum=0;
        for (int j=1; j<=len-i; j++) {
            sum+=pals[i][j];
        }
        dp[i]=dp[i+1]+sum;
    }
    ll res=0;
    for (int i=0; i<len; i++) {
        for (int j=1; j<=len-i; j++) {
            if (pals[i][j]) {
                res+=dp[i+j];
            }
        }
    }
    cout<<res<<endl;
}
