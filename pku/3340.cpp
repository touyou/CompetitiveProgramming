#include <csdio>
#include <iostream>
using namespace std;
typedef long long ll;
string w, x;
ll dfs(int pos, bool flag) {
    if (flag&&w[pos]!='?'&&w[pos]>x[pos]) flag=false;
    else if (flag&&w[pos]!='?'&&w[pos]<x[pos]) return 0;
    
}
int main() {
    while (cin>>w) {
        if (w=="#") break;
        cin>>x;        
        cout<<dfs(0,true)<<endl;
    }
}