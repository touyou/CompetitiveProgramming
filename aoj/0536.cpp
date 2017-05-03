//#include <cstdio>
//#include <vector>
//#include <map>
//using namespace std;
//typedef pair<int, int> P;
//typedef vector<P> vi;
//#define f first
//#define s second
//#define pb push_back
//#define sz(x) x.size()
//void shuffle(int x, int y, vi &c) {
//    int cnt=0, i;
//    int sz=sz(c);
//    vi temp1, temp2, temp3;
//    for (i=0; i<sz; i++) {
//        int s=c[i].f, e=c[i].s;
//        if (cnt+e-s+1>=x) {
//            temp1.pb(P(s,s+x-cnt-1));
//            break;
//        }
//        temp1.pb(c[i]); 
//        cnt+=e-s+1;
//    }
//    if (cnt+c[i].s-c[i].f+1>=y) {
//        temp2.pb(P(c[i].f+x-cnt,c[i].f+y-cnt-1));
//        temp3.pb(P(c[i].f+y-cnt,c[i].s));
//        for (i+=1;i<sz; i++) temp3.pb(c[i]);
//    } else {
//        temp2.pb(P(c[i].f+x-cnt,c[i].s));
//        cnt+=c[i].s-c[i].f+1;
//        int a=++i;
//        for (;i<sz; i++) {
//            int s=c[i].f, e=c[i].s;
//            if (cnt+e-s+1>=y) {
//                temp2.pb(P(s,s+y-cnt-1));
//                break;
//            }
//            temp2.pb(c[i]);
//            cnt+=e-s+1;
//        }
//        if (cnt+c[i].s-c[i].f+1!=y) temp3.pb(P(c[i].f+y-cnt,c[i].s));
//        for (i+=1; i<sz; i++) temp3.pb(c[i]);
//    }
///*
//    for (i=0; i<sz(temp1); i++) printf("%d %d\n",temp1[i].f,temp1[i].s);
//    puts("");
//    for (i=0; i<sz(temp2); i++) printf("%d %d\n",temp2[i].f,temp2[i].s);
//    puts("");
//    for (i=0; i<sz(temp3); i++) printf("%d %d\n",temp3[i].f,temp3[i].s);
//    puts("");
//*/
//    for (i=0; i<sz(temp3); i++) c.pb(temp3[i]);
//    for (i=0; i<sz(temp2); i++) c.pb(temp2[i]);
//    for (i=0; i<sz(temp1); i++) c.pb(temp1[i]);
//    temp1.clear(); temp2.clear(); temp3.clear();
//}

//int main() {
//    int n, m, p, q, r;
//    while (scanf("%d",&n)) {
//        if (!n) break;
//        scanf("%d%d%d%d",&m,&p,&q,&r);
//        vi c(1,P(1,n));
//        for (int i=0; i<m; i++) {
//            int x, y; scanf("%d%d",&x,&y);
//            shuffle(x,y,c);
//        }
//        int cnt=0, res=0;
//        for (int i=0; i<sz(c); i++) {
//            int s=c[i].f, e=c[i].s;
////            printf("%d %d\n",s,e);
//            if (cnt+e-s+1>=p&&q>=cnt) {
//                int m=max(s+p-cnt-1,s), M=min(s+q-cnt-1,e);
////                printf("%d %d\n",m,M);
//                if (r>=m&&r<=M) res+=r-m+1;
//                else if (r>=M) res+=M-m+1;
//            }
//            cnt+=e-s+1;
//        }
//        printf("%d\n",res);
//    }
//}
#include <iostream>
#include <deque>
using namespace std;

class Card{
public:
  int f,t;

  Card(int from,int to){
    f = from;
    t = to;
  }
};

int n,m,p,q,r;
deque<Card> d; //カードの山

//山の1枚目からx枚目までを取り出して戻り値として返す
deque<Card> removeCard(int x){
  deque<Card> res;

  while(1){
    Card tmp = d.front(); d.pop_front();
    x -= tmp.t - tmp.f + 1;

    if(x <= 0){
      if(x != 0){
        d.push_front(Card(tmp.t + x + 1, tmp.t));
        tmp.t += x;
      }
      res.push_back(tmp);
      break;
    }
    res.push_back(tmp);
  }
  return res;
}

//シャッフル用関数
void shuffle(int x,int y){
  deque<Card> A = removeCard(x);
  deque<Card> B = removeCard(y-x);
  for(int i=0;i<B.size();i++) d.push_back(B[i]);
  for(int i=0;i<A.size();i++) d.push_back(A[i]);
}

int main(void){
  while(cin>>n,n){
    cin>>m>>p>>q>>r;
    d.clear();
    d.push_back(Card(1,n));

    while(m--){
      int x,y;
      cin>>x>>y;
      shuffle(x,y);
    }

    int ans = 0;
    removeCard(p-1); //上の(p-1)枚を取り出しておく
    deque<Card> rem = removeCard(q-p+1); //(p-q+1)枚取り出せば, p枚目からq枚目を取り出したことになる
    for(int i=0;i<rem.size();i++){
      if(rem[i].f <= r){
        ans += r - rem[i].f - (rem[i].t < r ? r-rem[i].t : 0) + 1;
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
