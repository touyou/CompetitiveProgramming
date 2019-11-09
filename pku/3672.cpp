#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int M, T, U, F, D;
	scanf("%d%d%d%d%d\n",&M,&T,&U,&F,&D);
	char path[T];
	int dist[T];
	for (int i=0; i<T; i++) scanf("%c\n",&path[i]);
	for (int i=0; i<T; i++) {
		if (path[i]=='u'||path[i]=='d') dist[i]=U+D;
		if (path[i]=='f') dist[i]=F*2;
	}
	int res, sum=0;
	for (res=0; res<T; res++) {
		if ((sum+=dist[res])>M) break;
	}
	printf("%d\n", res);
}