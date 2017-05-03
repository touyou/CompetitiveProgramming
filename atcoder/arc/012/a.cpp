#include <iostream>
#include <cstdio>
using namespace std;
string st;
int main() {
    cin>>st;
    if (st=="Monday") puts("5");
    else if (st=="Tuesday") puts("4");
    else if (st=="Wednesday") puts("3");
    else if (st=="Thursday") puts("2");
    else if (st=="Friday") puts("1");
    else puts("0");
}