#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char vowel[] = {'a','e','i','o','u'};
void solve(vector<char> ch, int c, int l, int npos, string ns) {
	ns += ch[npos];
	if (++npos == c+1) return;
	if (ns.length() == l) {
		for (int i=0; i<ns.length(); i++) {
			if (ns[i]==vowel[0]||ns[i]==vowel[1]||ns[i]==vowel[2]||
				ns[i]==vowel[3]||ns[i]==vowel[4]) {
				cout<<ns<<endl;
				return;
			}
		}
	}
	for (int i=npos; i<c; i++) {
		solve(ch,c,l,i,ns);
	}
}
int main() {
	int l, c;
	scanf("%d%d",&l,&c);
	vector<char> ch(c);
	for (int i=0; i<c; i++) cin>>ch[i];
	sort(ch.begin(), ch.end());
	string ns = "";
	for (int i=0; i<c; i++) {
		solve(ch, c, l, i, ns);
	}
}