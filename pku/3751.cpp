#include <cstdio>
int main() {
	int T,y,mon,d,h,m,s;
	scanf("%d",&T);
	for (int i=0; i<T; i++) {
		scanf("%d/%d/%d-%d:%d:%d",&y,&mon,&d,&h,&m,&s);
		bool am = true;
		if (h>=12 && h<24) {
			am = false;
			if (h != 12) h -= 12;
		} else if (h == 0) {
			h = 12;
		}
		if (am) {
			printf("%02d/%02d/%4d-%02d:%02d:%02dam\n",mon,d,y,h,m,s);
		} else {
			printf("%02d/%02d/%4d-%02d:%02d:%02dpm\n",mon,d,y,h,m,s);
		}
	}
}	
