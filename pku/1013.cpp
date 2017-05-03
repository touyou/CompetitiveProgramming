#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n; scanf("%d",&n);
  for (int i=0; i<n; i++) {
    set<char> ok;
    vector<string> lig,hev;
    for (int j=0; j<3; j++) {
      string left, right, cond;
      cin>>left>>right>>cond;
      if (cond=="even") {
	for (int k=0; k<4; k++) ok.insert(left[k]);
	for (int k=0; k<4; k++) ok.insert(right[k]);
      } else if (cond=="up") {
	lig.push_back(right);
	hev.push_back(left);
      } else {
	lig.push_back(left);
	hev.push_back(right);
      }
    }
    char res;
    bool flag=true;
    if (!ok.empty()) {
      for (int i=0; i<lig.size(); i++) {
	for (int j=0; j<4; j++) {
	  if (ok.count(lig[i][j])==0) {
	    res = lig[i][j];
	  }
	}
      }
      for (int i=0; i<hev.size(); i++) {
	for (int j=0; j<4; j++) {
	  if (ok.count(hev[i][j])==0) {
	    res = hev[i][j];
	    flag=false;
	  }
	}
      }
    }
    if (flag) {
      printf("%c is the counterfeit coin and it is light.\n",res);
    } else {
      printf("%c is the counterfeit coin and it is heavy.\n",res);
    }
  }
}
