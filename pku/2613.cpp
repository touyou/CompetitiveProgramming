/*
[-p! * s! * (r-s)!] / [r! * -q! *(p-q)!]
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long double ld;
int p, q, r, s;
int main() {
    while (scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF) {
        vector<int> prod, div;
        ld ret = 1.0;
        if(p-q<q) q = p-q;
        if(r-s<s) s = r-s;
        for(int i=0; i<q; i++){
            div.push_back(i+1);
            prod.push_back(p-i);
        }
        for(int i=0; i<s; i++){
            prod.push_back(i+1);
            div.push_back(r-i);
        }
        while(!prod.empty() || !div.empty()){
            if(!prod.empty() && (div.empty() || ret < 1e6)){
                ret *= (ld)prod.back();
                prod.pop_back();
            }
            else{
                ret /= (ld)div.back();
                div.pop_back();
            }
        }
        printf("%.5f\n",ret);
    }
}