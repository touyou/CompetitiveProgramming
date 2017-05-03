#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define REP(i,n)  for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n);i>=0;i--) 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

class CreaterDetection {
public:
  vs res,names;
  vi xl,yt,xr,yb;
  map<string,string> ans;
  int processImage(string name, int W, int H, vi data) {
    vc lake(SZ(data));
    for (int i=0; i<SZ(data); i++) {
      if (data[i]<128) lake[i]='.';
      else lake[i]='w';
    }
    if (name[name.length()-1]=='f') {
      // A15's code---time limit:3m
      
    } else {
      // LRO's code---time limit:30s
      /* RESTRICTIONS
	 +any rectangles' edge is more than 25 and less than 200.(25<edge size≦200)
      */
      
    }
    return 0;
  }
  vs getCreaters() {
    // return result---time limit:30s
    REP(i,SZ(names)) {
      string ans = names[i]+" ";
      stringstream xls,yts,xrs,ybs;
      xls<<xl[i]; yts<<yt[i]; xrs<<xr[i]; ybs<<yb[i];
      ans += xls.str()+" "+yts.str()+" "+xrs.str()+" "+ybs.str();
      res.PB(ans);
    }
    return res;
  }
  int init() {
    // any initialization---time limit:30s
    return 0;
  }
};

////////// Tester用 //////////
int main() {
  CreaterDetection cd;
  printf("%d\n",cd.init());
  string name;
  int W,H,len;
  vs ret;
  while (true) {
    int cmd; scanf("%d",&cmd);
    if (cmd == 1) {
      cin>>name>>W>>H>>len;
      vi data(len);
      REP(i,len) scanf("%d",&data[i]);
      printf("%d\n",cd.processImage(name,W,H,data));
    } else {
      ret = getCreaters();
      printf("%d\n",SZ(ret));
      REP(i,SZ(ret)) printf("%d\n",ret[i]);
      break;
    }
  }
}
