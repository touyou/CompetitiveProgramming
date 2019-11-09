#include <stdio.h>

int main(){
    int n,x,y,z,i,min,max,a[10];
    char s[10][256];
    while(1){
        scanf("%d",&n);
        if(n<0)break;
        min=0;max=0;
        for(i=0;i<n;i++){
            scanf("%d %d %d %s",&x,&y,&z,s[i]);
            a[i]=x*y*z;
            if(a[min]>a[i])min=i;
            else if(a[max]<a[i])max=i;
        }
        printf("%s took clay from %s.\n",s[max],s[min]);
    }
    return 0;
}
