#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	while (getline(cin,str)&&str!="#") {
		for (int i=0; i<str.length(); i++) {
			if (str[i]==' ') {
				str[i]='%';
				str.insert(i+1,"20");
			} else if (str[i]=='!') {
				str[i]='%';
				str.insert(i+1,"21");
			} else if (str[i]=='$') {
				str[i]='%';
				str.insert(i+1,"24");
			} else if (str[i]=='%') {
				str[i]='%';
				str.insert(i+1,"25");
			} else if (str[i]=='(') {
				str[i]='%';
				str.insert(i+1,"28");
			} else if (str[i]==')') {
				str[i]='%';
				str.insert(i+1,"29");
			} else if (str[i]=='*') {
				str[i]='%';
				str.insert(i+1,"2a");
			} else {
				continue;
			}
			i+=2;
		}
		cout<<str<<endl;
	}
}
