#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int t; scanf("%d",&t);
    for (int ix=0; ix<t; ix++) {
        string str; cin>>str;
        string res="", temp="";
        res+=str[0];
        int pos=0;
        for (int i=1; i<str.length(); i++) {
            if (str[i]!='-'&&str[i]!='>'&&str[i]!='<') {
                if (temp=="->") {
                    pos++;
                    if (res.length()==pos) res+=str[i];
                    else if (res[pos]!=str[i]) {
                        res+='x';
                        for (int j=res.length()-1; j>pos; j--) {
                            res[j]=res[j-1];
                        }
                        res[pos]=str[i];
                    }
                } else {
                    pos--;
                    if (pos==-1) {
                        res=str[i]+res;
                        pos=0;
                    } else if (res[pos]!=str[i]) {
                        res='x'+res;
                        for (int j=0; j<pos; j++) {
                            res[j]=res[j+1];
                        }
                        res[pos]=str[i];
                    }
                }
                temp="";
            } else temp+=str[i];
        }
        cout<<res<<endl;
    }
}
