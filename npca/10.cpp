#include <cstdio>
int n, m, b[100000];
int done[100000];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    int res=0;
    int cnt=0;
    while (cnt<n) {
        for (int i=0; i<n; i++) {

