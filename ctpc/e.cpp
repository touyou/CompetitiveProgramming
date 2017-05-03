#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef map<string,int> MP;
int main() {
   int n; scanf("%d",&n);
   MP hash;
   for (int i=0; i<n; i++) {
      string s; cin>>s;
      cnt[s]=0;
      hash[s]=i;
   }
   int m; scanf("%d",&m);
   for (int i=0; i<m; i++) {
      string a,b; cin>>a>>b;
      cnt[a]++;
      cnt[b]++;
   }
   for (MP::iterator it=cnt.begin(); it!=cnt.end(); it++) {
      if ((*it).second%2!=0) {
         puts("No");
         return 0;
      }
   }
   puts("Yes");
}
