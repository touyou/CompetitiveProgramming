#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int q;
string str;
string b[16]={"0000","0001","0010","0011","0100","0101","0110","0111",
    "1000","1001","1010","1011","1100","1101","1110","1111"};
double inte[24];
double syo[7];
int main() {
    inte[0]=1; syo[0]=0.5;
    for (int i=1; i<24; i++) inte[i]=inte[i-1]*2;
    for (int i=1; i<7; i++) syo[i]=syo[i-1]*0.5;
    scanf("%d",&q);
    for (int x=0; x<q; x++) {
        cin>>str;
        string bit="";
        for (int i=0; i<str.length(); i++) {
            if ('0'<=str[i]&&str[i]<='9') {
                bit+=b[str[i]-'0'];
            } else if ('a'<=str[i]&&str[i]<='f') {
                bit+=b[str[i]-'a'+10];
            }
        }
        // cout<<bit<<endl;
        double res = 0.0;
        for (int i=1; i<25; i++) {
            if (bit[i]=='1') {
                res += inte[24-i];
            }
        }
        int kiri=0;
        for (int i=25; i<32; i++) {
            if (bit[i]=='1') {
                kiri=i-24;
                res += syo[i-25];
            }
        }
        if (bit[0]=='1') res *= (-1.0);
        if (kiri<2) printf("%.1f\n",res);
        else if (kiri==2) printf("%.2f\n",res);
        else if (kiri==3) printf("%.3f\n",res);
        else if (kiri==4) printf("%.4f\n",res);
        else if (kiri==5) printf("%.5f\n",res);
        else if (kiri==6) printf("%.6f\n",res);
        else if (kiri==7) printf("%.7f\n",res);
    }
}