#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;
int main() {
	int n; scanf("%d",&n);
	for (int i=0; i<n; i++) {
		string str;
		cin>>str;
		for (int j=0; j<str.length(); j++) {
			if ('A'<=str[j]&&str[j]<='Z') str[j] = tolower(str[j]);
		}
		cout<<str<<endl;
	}
}