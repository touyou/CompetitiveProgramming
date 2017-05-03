#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
struct worker {
  string ts, te;
  int ns, ne;
  bool operator< (worker& w) {
	return ns<w.ns;
  }
};
int n;
int in[2160];
worker w[15];
bool use[15];
int main() {
  scanf("%d",&n);
  for (int i=0; i<n; i++) {
	cin>>w[i].ts>>w[i].te;
	w[i].ns=(w[i].ts[0]-'0')*600+(w[i].ts[1]-'0')*60+(w[i].ts[3]-'0')*10+(w[i].ts[4]-'0');
	w[i].ne=(w[i].te[0]-'0')*600+(w[i].te[1]-'0')*60+(w[i].te[3]-'0')*10+(w[i].te[4]-'0');
  }
  sort(w, w+n);
  for (int i=0; i<n; i++) {
	if (w[i].flag) {
	  for (int j=w[i].ns; j<2160; j+=1440) in[j]++;
	  for (int j=w[i].ne; j<2160; j+=1440) in[j]--;
	}
  }
  int res=1;
  for (int i=0; i<2160; i++) {
	if (in[i]>0) {
	  printf("%d %d %d\n",in[i],i,res);
	  for (int j=0; in[i]>0&&j<res; j++) {
		if (!use[j]) {
		  use[j]=true;
		  in[i]--;
		}
	  }
	  if (in[i]==0) continue;
	  int temp=res;
	  for (res=temp+1; res<temp+in[i]; res++) {
		use[res]=true;
	  }
	} else if (in[i]<0) {
	  printf("%d %d %d\n",in[i],i,res);
	  for (int j=0; in[i]<0&&j<res; j++) {
		if (use[j]) {
		  use[j]=false;
		  in[i]++;
		}
	  }
	}
  }
  printf("%d\n",res);
}
