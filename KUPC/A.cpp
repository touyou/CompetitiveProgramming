#include <cstdio>
#include <algorithm>
using namespace std;
int main() 
{
    char input[300];
    scanf("%s",input);
    int k=0,u=0,p=0,c=0;
    for (int i=0; i<sizeof(input); i++) {
        if (input[i] == 'K') k++;
        else if (input[i] == 'U') u++;
        else if (input[i] == 'P') p++;
        else if (input[i] == 'C') c++;
    }
    int res = min(k,min(u,min(p,c)));
    printf("%d\n",res);
}

