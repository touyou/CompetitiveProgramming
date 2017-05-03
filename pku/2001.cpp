#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct Trie {
    int val;
    Trie *next[0x100];
    Trie(int n) {
        val=n;
        fill(next, next+0x100, (Trie*)0);
    }
};
void insert(Trie *t, char *s) {
    if (*s=='\0') return;
    if (t->next[*s]==NULL) {
        t->next[*s]=new Trie(1);
    } else {
        t->next[*s]->val++;
    }
    insert(t->next[*s], s+1);
}
int solve(Trie *t, char *s, int sz) {
    if (*(s+sz)=='\0') return sz;
    if (t->next[*(s+sz)]->val<2) return sz+1;
    return solve(t->next[*(s+sz)],s,sz+1);
}
int main() {
    char s[1020][30];
    int n=0;
    Trie t(1);
    while (scanf("%s",s[n])!=EOF) {
        insert(&t,s[n]); n++;
    }
    for (int i=0; i<n; i++) {
        int cnt=solve(&t,s[i],0);
        printf("%s ",s[i]);
        for (int j=0; j<cnt; j++) cout<<s[i][j];
        cout<<endl;
    }
}