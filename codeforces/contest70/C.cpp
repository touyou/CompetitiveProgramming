#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

/*
#include<cstdio>
#include<cstring>
int dp[102][102][26];
bool got[102][102][26];
int bonus[26][26];
char name[102];

int getDP(int len,int k,char c){
    int max = -1000000000;
    if(len+1 < k)   return max;
    if(got[len][k][c-'a'])  return dp[len][k][c-'a'];
    if(c == name[len]){
        for(char p = 'a';p<='z';++p){
            if(max < getDP(len-1,k,p) + bonus[p-'a'][c-'a']){
                max = getDP(len-1,k,p) + bonus[p-'a'][c-'a'];
            }
        }
    }
    else if(k>0){
        for(char p = 'a';p<='z';++p){
            if(max < getDP(len-1,k-1,p) + bonus[p-'a'][c-'a']){
                max = getDP(len-1,k-1,p) + bonus[p-'a'][c-'a'];
            }
        }
    }
    dp[len][k][c-'a'] = max;
    got[len][k][c-'a'] = 1;
    return max;
}

int main(){
    memset(got,0,sizeof got);
    memset(dp,0,sizeof dp);
    memset(bonus,0,sizeof bonus);
    for(int i=0;i<26;++i){
        got[0][1][i] = 1;
    }
    scanf("%s",name);
        got[0][0][name[0]-'a'] = 1;
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;++i){
        char a[4],b[4];
        scanf("%s%s",a,b);
        scanf("%d",&bonus[a[0]-'a'][b[0]-'a']);
    }
    int max = -1000000000;
    int len = strlen(name);
    for(int i=0;i<=k;++i){
        for(int c=0;c<26;++c){
            if(max < getDP(len-1,i,c+'a')){
                max = getDP(len-1,i,c+'a');
//              printf("%d %d %c %d\n",len-1,i,c+'a',max);
            }
        }
    }
    printf("%d\n",max);
    return 0;
}
*/
