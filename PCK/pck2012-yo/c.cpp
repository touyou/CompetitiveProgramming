#include <cstdio>
#include <vector>

using namespace std;

int main(void){
    for(;;){
        int n;
        int len;
        scanf("%d",&n);
        if(n==0){
            break;
        }
        len = n+1;
        vector<int> vec(len,0);
        for(int i=0;i<len;i++){
            int buf;
            scanf("%d",&buf);
            vec[i]=buf;
        }
        if((vec[1]-vec[0])*2 != vec[2]-vec[0] && (vec[1]-vec[0])*3 != vec[3]-vec[0]){
            if(vec[2]-vec[1] != vec[3]-vec[2]){
                printf("%d\n",vec[1]);
            }else{
                printf("%d\n",vec[0]);
            }
            continue;
        }
        if(vec[1]-vec[0] != vec[2]-vec[1]){
            printf("%d\n",vec[1]);
            continue;
        }
        for(int i=0;i<n;i++){
            if(vec[i+1] - vec[i] != vec[1]-vec[0]){
                printf("%d\n",vec[i+1]);
                break;
            }
        }
    }
    return 0;
}

