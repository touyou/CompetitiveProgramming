#include <cstdio>
using namespace std;
int main() 
{
    int total=0, tmp;
    for (int i=0; i<4; i++) {
        scanf("%d",&tmp);
        total+=tmp;
    }
    printf("%d\n%d\n",total/60,total%60);
}

    
