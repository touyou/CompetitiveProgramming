#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N, Z, M; scanf("%d%d%d",&N,&Z,&M);
    int board[N];
    fill (board, board+N, 0);
    for (int i=0; i<M; i++) {
        int j; scanf("%d",&j);
        board[j-1]=1;
    }
    /*
    Z - 1 ≡ K * x (mod N)
    */
    
