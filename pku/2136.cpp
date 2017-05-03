// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;
// int main() 
// {
//     vector<int> hist(26, 0);
//     string in;
//     int m = 0;
//     for (int ix=0; ix<4; ix++) {
//         getline(cin, in);
//         for (int i=0; i<in.length(); i++) {
//             if (isalnum(in[i])) {
//                 hist[in[i]-'A']++;
//                 if (hist[in[i]-'A'] > m) m = hist[in[i]-'A'];
//             }
//         }
//     }
//     for (int i=m; i>0; i--) {
//         int white = 0;
//         for (int j=0; j<26; j++) {
//             if (hist[j] < i) white++;
//             else {
//                 for (int k=0; k<white; k++) {
//                     if (!(white - j == 0 && k == 0)) cout << ' ';
//                     cout << ' ';
//                 }
//                 if (j) cout << " *";
//                 else cout << '*';
//                 white = 0;
//             }
//         }
//         cout << endl;
//     }
//     for (int i=0; i<25; i++) {
//         char ab = i + 'A';
//         cout << ab << " ";
//     }
//     cout << "Z" << endl;
// }

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()


void solve(string &in){
  int cnt[26]={0};
  int rmax=0;
  rep(i,in.size())if (isupper(in[i]))cnt[in[i]-'A']++;
  rep(i,26)rmax=max(rmax,cnt[i]);

  
  for(int i=rmax;i>0;i--){
    int whitenum = 0;
    rep(j,26){
      if (cnt[j] < i)whitenum++;
      else {
	rep(k,whitenum){
	  if (!(whitenum - j ==0 && k == 0))cout << ' ';
	  cout << ' ';
	}
	if (j)cout << " *";
	else cout << '*';
	whitenum = 0;
      }
    }
    cout << endl;
  }

  rep(i,26){
    if (i)cout << ' ';
    cout << (char)('A' + i);
  }
  cout << endl;
}

main(){
  string in,tmp;
  while(getline(cin,tmp))in+=tmp;
  solve(in);
}
