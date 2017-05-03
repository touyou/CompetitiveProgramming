#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 1000
using namespace std;
struct rect 
{
    int height, pos;
};

int solve(int size, int buff[]) 
{
    stack<rect> S;
    int maxv = 0;
    buff[size] = 0;
    for (int i=0; i<=size; i++) {
        rect r;
        r.height = buff[i];
        r.pos = i;
        if (S.empty()) {
            S.push(r);
        }
        else {
            if (S.top().height < r.height) {
                S.push(r);
            }
            else if (S.top().height > r.height) {
                int target = i;
                while (!S.empty() && S.top().height >= r.height) {
                    rect pre = S.top();
                    S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                r.pos = target;
                S.push(r);
            }
        }
    }
    return maxv;
}

int M, N;
char buff[MAX][MAX];
int T[MAX][MAX];

int solve2() 
{
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            T[i][j] = 0;
        }
    }
    for (int j=0; j<N; j++) {
        int seq = 0;
        for (int i=0; i<M; i++) {
            if (buff[i][j] == 'R') {
                seq = T[i][j] = 0;
            }
            else {
                T[i][j] = ++seq;
            }
        }
    }
    
    int maxv = 0;
    for (int i=0; i<M; i++) {
        maxv = max(maxv, solve(N, T[i]));
    }
    
    return maxv;
}

int main() 
{
    int t;
    scanf("%d", &t);
    for (int ix=0; ix<t; ix++) {
        scanf("%d%d", &M, &N);
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                cin >> buff[i][j];
            }
        }
        printf("%d\n", solve2()*3);
    }
}
