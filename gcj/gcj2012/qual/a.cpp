#include <iostream>
#include <map>
using namespace std;
map<char, char> mp;
int main() {
    mp['a']='y'; mp['b']='h'; mp['c']='e'; mp['d']='s'; mp['e']='o';
    mp['f']='c'; mp['g']='v'; mp['h']='x'; mp['i']='d'; mp['j']='u';
    mp['k']='i'; mp['l']='g'; mp['n']='b'; mp['m']='l'; mp['o']='k';
    mp['p']='r'; mp['q']='z'; mp['r']='t'; mp['s']='n'; mp['t']='w';
    mp['u']='j'; mp['v']='p'; mp['w']='f'; mp['x']='m'; mp['y']='a';
    mp['z']='q';
    int t; scanf("%d",&t);
    string str;
    getline(cin, str);
    for (int ix=1; ix<=t; ix++) {
        getline(cin, str);
        for (int i=0; i<str.length(); i++) {
            if (str[i]==' ') continue;
            str[i]=mp[str[i]];
        }
        cout<<"Case #"<<ix<<": "<<str<<endl;
    }
}