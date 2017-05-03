#include "grader.h"
#include "honest.h"
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int ans[100000], is[100000];
map<int, int> cnt;
void identify(int N) {
  for (int i=0; i<N; i++) {
    ans[i]=question(2,i,0);
    if (cnt.find(ans[i])!=cnt.end()) cnt[ans[i]]++;
    else cnt[ans[i]]=1;
  }
  int res=-1;
  for (int i=0; i<N; i++) {
    if (cnt[ans[i]]==ans[i]&&(res==-1||res==ans[i])) res=ans[i];
    else if (cnt[ans[i]]==ans[i]) {
        res=-2;
        break;
    }
  }
  if (res==-1) {
    impossible();
  } else if (res==-2) {
    memset(is, -1, sizeof(is));
    for (int i=0; i<N; i++) {
        if (cnt[ans[i]]!=ans[i]) continue;
        if (is[i]==-1) {
            is[i]=question(0,i,0);
        } else {
            int tmp=question(0,i,0);
            if (is[i]!=tmp) cnt[ans[i]]=-1;
        }
    }
    for (int i=0; i<N; i++) {
        if (cnt[ans[i]]==ans[i]&&(res==-2||res==ans[i])) res=ans[i];
        else if (cnt[ans[i]]==ans[i]) {
            res=-2;
            break;
        }
    }
    if (res==-2) impossible();
    else {
        for (int i=0; i<N; i++) {
            if (ans[i]==res) answer(i,1);
            else answer(i,0);
        }
    }
  } else {
    for (int i=0; i<N; i++) {
        if (res==ans[i]) answer(i,1);
        else answer(i,0);
    }
  }
}
