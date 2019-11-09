
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Trie {
	int value;
	Trie *next[0x100];
	Trie() { fill(next, next+0x100, (Trie*)0); }
};
void insert(char *t, Trie *r) {
	for (int i = 0; t[i]; ++i) {
		char c = t[i];
		if (!r->next[c]) r->next[c] = new Trie;
		r = r->next[c];
	}
}
bool find(char *t, Trie *r) {
	for (int i=0; i<strlen(t)-1; ++i) {
		char c = t[i];
		if (!r->next[c]) {
			return false;
		}
		r = r->next[c];
	}
	return true;
}
int main() {
	int m, n; scanf("%d%d\n",&m,&n);
	Trie tr;
	for (int i=0; i<m; i++) {
		char in[100];
		fgets(in,100,stdin);
		in[strlen(in)-1]=0;
		insert(in,&tr);
	}
	int res=0;
	for (int i=0; i<n; i++) {
		char in[100];
		fgets(in,100,stdin);
		in[strlen(in)]=0;
		if (find(in,&tr)) res++;
	}
	printf("%d\n",res);
}