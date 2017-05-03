// #include <cstdio>
// #include <algorithm>
// #include <stack>
// using namespace std;
// typedef long long ll;

// struct Rectangle { int height; int pos; };

// ll getLargestRectangle(int size, ll buff[]) {
//     stack<Rectangle> S;
//     ll maxv = 0;
//     buff[size] = 0;
    
//     for (int i=0; i<=size; i++) {
//         Rectangle rect;
//         rect.height = buff[i];
//         rect.pos = i;
//         if (S.empty()) {
//             S.push(rect);
//         } else {
//             if (S.top().height < rect.height) {
//                 S.push(rect);
//             } else if (S.top().height > rect.height) {
//                 int target = i;
//                 while (!S.empty() && S.top().height >= rect.height) {
//                     Rectangle pre = S.top(); S.pop();
//                     ll area = pre.height * (i - pre.pos);
//                     maxv = max(maxv, area);
//                     target = pre.pos;
//                 }
//                 rect.pos = target;
//                 S.push(rect);
//             }
//         }
//     }
//     return maxv;
// }

// int main() 
// {
//     int s;
//     ll buff[110001];
    
//     while (scanf("%d", &s)&&s!=0) {
//         for (int i=0; i<s; i++) scanf("%lld", &buff[i]);
//         printf("%lld\n", getLargestRectangle(s, buff));
//     }
// }

// pku 2559 (Largest Rectangle in a Histogram)
// O(n) algorithm
#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#define MAX 110000
typedef long long llong;

using namespace std;

struct Rectangle{ llong height;  int pos; };
 
llong getRectangleArea( int size, llong buffer[]){
    stack<Rectangle> S;
    llong maxv = 0;
    buffer[size] = 0;
    
    for ( int i = 0; i <= size; i++ ){
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if ( S.empty() ){
            S.push( rect );
        } else {
            if ( S.top().height < rect.height ){
                S.push( rect );
            } else if ( S.top().height > rect.height ) {
                int target = i;
                while ( !S.empty() && S.top().height >= rect.height){
                    Rectangle pre = S.top(); S.pop();
                    llong area = pre.height * (i - pre.pos);
                    maxv = max( maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
     }
    
    return maxv;
 }

main(){
    int size;
    llong buffer[MAX+1];
    
    while(1){
        scanf("%d", &size);
        if ( size == 0 ) break;
        for ( int i = 0; i < size; i++ ) scanf("%lld", &buffer[i]);
        cout << getRectangleArea( size, buffer ) << endl;
    }
}
