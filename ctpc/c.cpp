#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
int n; scanf("%d",&n);
string str; getline(cin,str);
int tw=0,rt=0;
for (int i=0; i<n; i++) {
getline(cin,str);
int len=str.length();
if (1>len||140<len) continue;
if (str[0]=='@') rt++;
else tw++;
}
if (rt+tw==0) {
puts("Tweet:NA Reply:NA");
return 0;
}
int r1=0,r2=0;
if (tw) r1=tw*100/(tw+rt);
if (rt) r2=rt*100/(tw+rt);
printf("Tweet:%d Reply:%d\n",r1,r2);
}
