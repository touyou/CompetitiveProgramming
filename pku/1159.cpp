#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() 
{
    int N;
    cin>>N;
    string in,bef="",aft="";
    cin>>in;
    int res=0;
    for (int i=0; i<N/2; i++) bef+=in[i];
    for (int i=N-1; i>N-N/2; i--) aft+=in[i];
    for (int i=0; i<bef.length(); i++) if (bef[i]!=aft[i]) res++;
    if (N%2==0) res*=2;
    cout<<res<<endl;
}

