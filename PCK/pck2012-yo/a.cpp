#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int v[10];
    for(int c=0;c<10;c++){
        scanf("%d",v+c);
    }
    int sum=0;
    for(int c=0;c<10;c++){
        sum += v[c];
    }
    printf("%d\n",sum);
    return 0;
}

