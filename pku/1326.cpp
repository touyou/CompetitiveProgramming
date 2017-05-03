#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    string t1,t2;
    int mile;
    char cs;
    while (cin>>t1&&t1!="#") {
        int mileage=0;
        cin>>t2>>mile>>cs;
        if (cs=='B') {
            if (mile%2==0) mileage+=mile*1.5;
            else mileage+=mile*1.5+1;
        }
        else if (cs=='F') {
            mileage+=mile*2;
        }
        else if (cs=='Y') {
            if (mile<=500) mile=500;
            mileage+=mile;
        }
        while (cin>>t1&&t1!="0") {
            cin>>t2>>mile>>cs;
            if (cs=='B') {
                if (mile%2==0) mileage+=mile*1.5;
                else mileage+=mile*1.5+1;
            }
            else if (cs=='F') {
                mileage+=mile*2;
            }
            else if (cs=='Y') {
                if (mile<=500) mile=500;
                mileage+=mile;
            }
        }
        printf("%d\n",mileage);
    }
}

