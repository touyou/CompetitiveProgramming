#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int> cow(N);
    int sum = 0, res;
    for (int i = 0; i < N; i++) {
        scanf("%d", &cow[i]);
        sum += cow[i];
    }
    sort(cow.begin(), cow.end());
    printf("%d\n", cow[N/2]);
}
