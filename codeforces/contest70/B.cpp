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

int main() {
	int n; cin >> n;
	string s; int a;
	vector<string> ss; vector<int> aa;
	for (int i=0; i<n; i++) {
		cin >> s >> a;
		ss.push_back(s); 
		aa.push_back(a);
	}
	int m; cin >> m;
	int b;
	vector<int> bb;
	for (int i=0; i<n; i++) {
		cin >> b;
		bb.push_back(b);
	}
	string v; cin >> v;
	int my_score;
	
	for (int i=0; i<ss.size(); i++) {
		if (ss[i] == v) {
			my_score = aa[i];
		}
	}
	
	int min_r, max_r, temp;
	int min_s=100000000, max_s=0;
	if (n > m) {
		min_r = n;
		for (int i=0; i<m; i++) {
			temp = bb[i]+my_score;
			max_s = max(max_s, temp);
		}
		max_r = 0;
		for (int i=0; i<aa.size(); i++) {
			if (max_s < aa[i])
				max_r++;
		}
	} else if (n <= m) {
		for (int i=0; i<m; i++)
			min_s = min(min_s, bb[i]);
		min_s += my_score;
		for (int i=0; i<m; i++) {
			temp = bb[i]+my_score;
			max_s = max(max_s, temp);
		}
		min_r=n; max_r=0;
		for (int i=0; i<aa.size(); i++) {
			if (my_score == aa[i]) continue;
			if (min_s > aa.size()) n--;
		}
		for (int i=0; i<aa.size(); i++) {
			if (max_s < aa[i])
				max_r++;
		}
	}
	cout << max_r << " " << min_r << endl;
}
/*
#include <vector>
#include <cstring>
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
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define left asdleft

map<string,int> pts;
vector<pair<int,string> > src;
vector<int> bs;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
 
    int n;
    cin>>n;
    forn(i,n){
        char tmp[30];
        int p;
        scanf("\n%s%d",tmp,&p);
        pts[tmp]=p;
        src.pb(mp(-p,tmp));
    }
    bs.resize(n);
    bs.assign(n,0);
    int m;
    cin>>m;
    forn(i,m)
        cin>>bs[i];
    sort(all(bs));
    string vasya;
    cin>>vasya;
    int vp=pts[vasya];

    sort(all(src));
    forv(i,src)
        src[i].first*=-1;

    multiset<int> bset;

    int res1=0,res2=0;

    forv(i,bs)
        bset.insert(-bs[i]);
    bset.erase(bset.lower_bound(-bs.back()));
    for(int i=n-1;i>=0;--i){
        if(src[i].second==vasya)
            continue;
        int np=vp+bs.back()-src[i].first;
        if(src[i].second<vasya)
            --np;
        multiset<int>::iterator it=bset.lower_bound(-np);
        if(it==bset.end())
            break;
        bset.erase(it);
        ++res1;
    }
    res1=n-res1;

    bset.clear();
    forv(i,bs)
        bset.insert(bs[i]);
    bset.erase(bset.lower_bound(bs[0]));
    forn(i,n){
        if(src[i].second==vasya)
            continue;
        int np=-(src[i].first-(vp+bs[0]));
        if(src[i].second>vasya)
            ++np;
        multiset<int>::iterator it=bset.lower_bound(np);
        if(it==bset.end())
            break;
        bset.erase(it);
        ++res2;
    }
    ++res2;

    cout<<res1<<' '<<res2;

    return 0;
}
*/
