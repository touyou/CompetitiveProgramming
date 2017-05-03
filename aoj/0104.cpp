#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main() 
{
    int h,w;
    while (scanf("%d%d",&h,&w)) {
        if (h==0&&w==0) break;
        vector<string> map;
        for (int i=0; i<h; i++) {
            string in;
            cin>>in;
            map.push_back(in);
        }
        vector<vector<int> > went;
        for (int i=0; i<h; i++) {
            vector<int> num(w,0);
            went.push_back(num);
        }
        int ni=0, nj=0;
        bool flag=false;
        while (map[ni][nj]!='.') {
            if (went[ni][nj]==1) {
                flag=true;
                break;
            }
            went[ni][nj]++;
            if (map[ni][nj]=='>') {
                nj++;
            }
            else if (map[ni][nj]=='<') {
                nj--;
            }
            else if (map[ni][nj]=='^') {
                ni--;
            }
            else if (map[ni][nj]=='v') {
                ni++;
            }
        }
        if (flag) printf("LOOP\n");
        else printf("%d %d\n",nj,ni);
    }
}
