#include <cstdio>
int a[14];
int main() {
	int k;
	bool first=false;
	while (scanf("%d",&k)) {
		if (!k) break;
		if (first) puts("");
		for (int i=0; i<k; i++) scanf("%d",&a[i]);
		for (int i=0; i<k; i++) {
			for (int j=i+1; j<k; j++) {
				for (int l=j+1; l<k; l++) {
					for (int r=l+1; r<k; r++) {
						for (int n=r+1; n<k; n++) {
							for (int m=n+1; m<k; m++) {
								printf("%d %d %d %d %d %d\n",a[i],a[j],a[l],a[r],a[n],a[m]);
							}
						}
					}
				}
			}
		}
		first=true;
	}
}
