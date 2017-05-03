#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;

int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};

vs dfs(int x, int y, vs map)
{
    map[x][y] = '@';
	int H = map.size();
    int W = map[0].size();
    for (int i=0; i<4; i++) {
            if (x+mx[i]<H&&x+mx[i]>=0&&
                y+my[i]<W&&y+my[i]>=0&&
                map[x+mx[i]][y+my[i]]=='.') {
                map = dfs(x+mx[i], y+my[i], map);
            }
    }
    return map;
}

int main()
{
    int W, H;
    while (scanf("%d%d",&W,&H)) {
        if (W==0&&H==0) break;
        vs map;
        int startx, starty;
        for (int i=0; i<H; i++) {
            string s;
            cin >> s;
            for (int j=0; j<W; j++) {
                if (s[j] == '@') {
                    startx = i;
                    starty = j;
                }
            }
            map.push_back(s);
        }
        map = dfs(startx, starty, map);
        int res = 0;
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++)
				if (map[i][j] == '@') res++;
		printf("%d\n", res);
    }
}
