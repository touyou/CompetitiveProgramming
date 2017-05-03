#include <cstdio>
#include <vector>
using namespace std;
vector<int> G[10];
int main() {
    G[0].push_back(1);
    for (int i=1; i<=5; i++) G[i].push_back(i-1); G[i].push_back(i+1);
    G[6].push_back(7); G[7].push_back(8); G[8].push_back(9); G[9].push_back(5);
    
}
