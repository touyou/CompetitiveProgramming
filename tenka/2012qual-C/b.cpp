#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string s;
vector<string> card;
set<string> roy[4];
int main() {
  cin>>s;
  for (int i=0; i<s.length(); i++) {
	string temp = "";
	temp += s[i];
	if (s[i+1]=='1') {
	  temp += "1";
	  temp += "0";
	  card.push_back(temp);
	  i+=2;
	} else {
	  temp += s[i+1];
	  card.push_back(temp);
	  i+=1;
	}
  }

  //  for (int i=0; i<card.size(); i++) cout<<card[i]<<endl;

  int i;
  int flag=-1;
  for (i=0; i<card.size(); i++) {
	// cout<<card[i]<<endl;
	if (card[i][1]=='1'||card[i][1]=='J'||
		card[i][1]=='Q'||card[i][1]=='K'||card[i][1]=='A') {
	  // cout<<card[i]<<endl;
	  if (card[i][0]=='S') {
		roy[0].insert(card[i]);
		if (roy[0].size()==5) { flag=0; break; }
	  } else if (card[i][0]=='H') {
		roy[1].insert(card[i]);
		if (roy[1].size()==5) { flag=1; break; }
	  } else if (card[i][0]=='D') {
		roy[2].insert(card[i]);
		if (roy[2].size()==5) { flag=2; break; }
	  } else {
		roy[3].insert(card[i]);
		if (roy[3].size()==5) { flag=3; break; }
	  }
	
	}
  }
  if (i==4) {
	puts("0");
  } else {
	for (int j=0; j<=i; j++) {
	  int f2;
	  if (card[j][0]=='S') f2=0;
	  else if (card[j][0]=='H') f2=1;
	  else if (card[j][0]=='D') f2=2;
	  else f2=3;
	  if (flag!=f2) {
		cout<<card[j];
	  }
	}
	cout<<endl;
  }
}
