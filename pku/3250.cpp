#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
int n;
int main() {
    scanf("%d",&n);
    stack<ll> st;
    ll res=0;
    for (int i=0; i<n; i++) {
        ll h;
        scanf("%lld",&h);
        while (!st.empty()&&st.top()<=h) st.pop();
        res+=st.size();
        st.push(h);
    }
    printf("%lld\n",res);
}
