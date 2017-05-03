#include <iostream>
using namespace std;
int n, res;
string w;
int main() {
    cin>>n;
    res=0;
    for (int i=0; i<n; i++) {
        cin>>w;
        if (i==n-1) {
            if (w=="TAKAHASHIKUN."||w=="Takahashikun."||w=="takahashikun.") res++;
        } else if (w=="TAKAHASHIKUN"||w=="Takahashikun"||w=="takahashikun") res++;
    }
    cout<<res<<endl;
}