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
	int n, m, k; cin >> n >> m >> k;
	set<int> log; log.clear();
	int a, b, p=n;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		if (log.count(a) != 0 && log.count(b))
			continue;
		p--;
		log.insert(a); log.insert(b);
	}
	int ans;
	if (p-k-1 <= 0) {
		ans = 0;
	} else {
		ans = p-k-1;
	}
	cout << ans << endl;
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)

// BEGIN CUT HERE
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef vector<string> VS;

#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define INF  ((int)1e9+7)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)

//ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

int n, m, k, t;
int w;

vector<vector<int> > G((int)1e6+7);

bool o[((int)1e6+7)];

int slots;

void dfs(int a)
{
        o[a] = 1;
        slots++;
        for(int i = 0; i < G[a].size(); i++)
        {
                int y = G[a][i];
                if (!o[y]) dfs(y);
        }
}

int main()
{
        w = 0;
        scanf ("%d %d %d", &n, &m, &k);
        
        for(int i = 0; i < m; i++)
        {
                int b1, b2;
                scanf("%d %d", &b1, &b2);
                b1--; b2--;
                G[b1].push_back(b2);
                G[b2].push_back(b1);
        }
        
        int lssp = 0;
        int tv = 0;
        int SL = 2;
        for(int i = 0; i < n; i++)
        {
                slots=0;
                if (!o[i]) 
                {
                        dfs(i);
                        lssp++;
                }
                
                if (G[i].size() == 0) tv++;
                
                if (slots>2) SL+=min(k-2, slots-2);
        }
        
        int tun =0; int dro = 0;
        if (lssp == tv || k==1)
        {
                //tun += lssp/2;
                dro += (n-1)/2;
        }else
        {
                //int kolka = lssp-tv;
                //tun += kolka - 1;
                //tun += min(SL, tv);
                tv -= min(tv, SL);
                if (tv>0)
                {
                        dro++;
                        tun += tv/2;
                        dro += (tv-1)/2;
                }
        }
        
        //printf("SL = %d, lssp = %d, tv = %d\n", SL, lssp, tv);
        
        w = dro;
        
        printf("%d", w);
        return 0;
}
*/
