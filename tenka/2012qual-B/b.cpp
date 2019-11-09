#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
vector<string> word;
int main() {
  string str; cin>>str;
  bool flag=true;
  int mode=-1; // 0 camel 1 under
  string temp="";
  string first="";
  int ac=0;
  while (ac<str.length()&&str[ac]=='_') {
	first+="_";
	ac++;
  }
  if (ac==str.length()) {
	cout<<first<<endl;
	return 0;
  }
  int bc=str.length()-1;
  string last="";
  while (bc>=0&&str[bc]=='_') {
	last+="_";
	bc--;
  }
  //cout<<first<<" "<<last<<endl;
  int cnt=0;
  for (int i=ac; i<=bc; i++) {
	if (str[i]=='_') {
	  if (mode==0) flag=false;
	  if (cnt!=0) flag=false;
	  cnt++;
	  word.push_back(temp);
	  temp="";
	  word.push_back("_");
	  mode=1;
	} else if (temp=="") {
	  if (!('a'<=str[i]&&str[i]<='z')) flag=false;
	  temp+=str[i];
	  cnt=0;
	} else {
	  if ('A'<=str[i]&&str[i]<='Z') {
		if (mode==1) flag=false;
		word.push_back(temp);
		temp=""; temp+=str[i];
		mode=0;
		cnt=0;
	  } else {
		temp+=str[i];
		cnt=0;
	  }
	}
  }
  if (temp!="") word.push_back(temp);
  //for (int i=0; i<word.size(); i++) cout<<word[i]<<endl;
  if (!flag||mode==-1) cout<<str<<endl;
  else {
	if (mode==0) {
	  string ans="";
	  for (int i=0; i<word.size(); i++) {
		if (word[i]!="_") {
		  word[i][0]=tolower(word[i][0]);
		  ans+=word[i];
		  if (word.size()-1!=i) ans+="_";
		}
	  }
	  cout<<first<<ans<<last<<endl;
	} else if (mode==1) {
	  string ans="";
	  bool fst=true;
	  for (int i=0; i<word.size(); i++) {
		if (word[i]!="_") {
		  if (!fst) word[i][0]=toupper(word[i][0]);
		  fst=false;
		  ans+=word[i];
		}
	  }
	  cout<<first<<ans<<last<<endl;
	}
  }
}
