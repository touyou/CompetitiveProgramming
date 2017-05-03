#include <cstdio>
#include <algorithm>
using namespace std;
int n, fsum;
int perm[10];
int nex[10][10]={
{1,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0},
{1,2,1,0,0,0,0,0,0,0},
{1,3,3,1,0,0,0,0,0,0},
{1,4,6,4,1,0,0,0,0,0},
{1,5,10,10,5,1,0,0,0,0},
{1,6,15,20,15,6,1,0,0,0},
{1,7,21,35,35,21,7,1,0,0},
{1,8,28,56,70,56,28,8,1,0},
{1,9,36,84,126,126,84,36,9,1}};
int main() {
    scanf("%d%d",&n,&fsum);
    for (int i=0; i<n; i++) {
        perm[i]=i+1;
    }
    do {
        int sum=0;
        for (int i=0; i<n; i++) {
            sum+=perm[i]*nex[n-1][i];
        }
        if (sum==fsum) {
            for (int i=0; i<n; i++) {
                printf("%d%c",perm[i],i==n-1?'\n':' ');
            }
            break;
        }
    } while (next_permutation(perm, perm+n));
}
