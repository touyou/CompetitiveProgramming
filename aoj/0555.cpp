#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string ring,str;
    int N,res=0;
    cin>>str>>N;
    for (int i=0; i<N; i++) {
        cin>>ring;
        bool flag=false;
        for (int j=0; j<10; j++) {
            int at=j;
            string tmp="";
            for (int k=0; k<str.length(); k++) {
                if (at==10) at=0;
                tmp+=ring[at];
                at++;
            }
            if (tmp==str) {
                flag=true;
                break;
            }
        }
        if (flag) res++;
    }
    cout<<res<<endl;
}

        
