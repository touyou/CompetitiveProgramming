#include <cstdio>
#include <vector>
using namespace std;
int main() 
{
    int n;
    float high;
    vector<int> num(6,0);
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%f",&high);
        if (high<165.0) {
            num[0]++;
        }
        else if (high<170.0) {
            num[1]++;
        }
        else if (high<175.0) {
            num[2]++;
        }
        else if (high<180.0) {
            num[3]++;
        }
        else if (high<185.0) {
            num[4]++;
        }
        else {
            num[5]++;
        }
    }
    for (int i=1; i<=6; i++) {
        printf("%d:",i);
        for (int j=0; j<num[i-1]; j++) printf("*");
        printf("\n");
    }
}

