#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string key, line;
int main() {
  cin>>key;
  getline(cin, line);
  getline(cin, line);
  for (int i=0; i<line.length(); i++) {
	if (line[i] == ' ') continue;
	if ('A' <= line[i] && line[i] <= 'Z') {
	  int k = line[i] - 'A';
	  line[i] = toupper(key[k]);
	} else if ('a' <= line[i] && line[i] <= 'z') {
	  int k = line[i] - 'a';
	  line[i] = key[k];
	}
  }
  cout<<line<<endl;
}
