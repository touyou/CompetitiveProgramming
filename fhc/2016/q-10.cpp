#include <bits/stdc++.h>
using namespace std;
int t, n;
long long ans;
int x[2000], y[2000];

long long calc(int n) {
    return (long long)n*(n-1)/2;
}

int main() {
    cin >> t;
    for (int c=1; c <= t; c++) {
        cin >> n;
        for (int i=0; i<n; i++) cin>>x[i]>>y[i];
        vector<double> dist[2000];
        ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                double d = sqrt((double)(x[i]-x[j])*(x[i]-x[j]) +
                        (y[i]-y[j])*(y[i]-y[j]));
                dist[i].push_back(d);
                dist[j].push_back(d);
            }
            sort(dist[i].begin(), dist[i].end());
        }
        for (int i=0; i<n; i++) {
            vector<pair<double, int> > count;
            double bef = dist[i][0];
            int p = 0;
            count.push_back(make_pair(bef, 1));
            for (int j=1; j<dist[i].size(); j++) {
                if (bef == dist[i][j]) {
                    count[p].second++;
                    if (j == dist[i].size()-1)
                        ans += calc(count[p].second);
                } else {
                    bef = dist[i][j];
                    count.push_back(make_pair(bef, 1));
                    ans += calc(count[p].second);
                    // cout<<i<<" "<<p<<" "<<count[p].second<<endl;
                    p++;
                }
            }
        }
        printf("Case #%d: %lld\n", c, ans);
    }
}
