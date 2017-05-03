#include <cstdio>
#include <iostream>
using namespace std;
int dx=0, dy=0;
int x, y;
string W;
string c[10];
int main() {
    cin>>y>>x>>W;
    if (W=="R") dy=1;
    if (W=="L") dy=-1;
    if (W=="U") dx=-1;
    if (W=="D") dx=1;
    if (W=="RU") {
        dx=-1; dy=1;
    }
    if (W=="RD") {
        dx=1; dy=1;
    }
    if (W=="LU") {
        dx=-1; dy=-1;
    }
    if (W=="LD") {
        dx=1; dy=-1;
    }
    for (int i=0; i<9; i++) cin>>c[i];
    string res="";
    x--; y--;
    while (res.length()<4) {
        res.push_back(c[x][y]);
        x+=dx; y+=dy;
        if (x<0||x>8) {x-=2*dx; dx*=-1;}
        if (y<0||y>8) {y-=2*dy; dy*=-1;}
    }
    cout<<res<<endl;
}