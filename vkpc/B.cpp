#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
	set<string> need;
	int m, n;
	scanf("%d",&m);
	for (int i=0; i<m; i++) {
		string temp; cin >> temp;
		need.insert(temp);
	}
	scanf("%d",&n);
	int much=0;
	for (int i=0; i<n; i++) {
		string key, info; cin >> key >> info;
		string sub = key.substr(0,key.length()-1);
		if (need.find(sub)!=need.end()) much++;
	}
	if (much==need.size()) printf("yes\n");
	else printf("no\n");
}