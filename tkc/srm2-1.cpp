#include <cstdio>
#include <cstring>
int main() {
	char in[5];
	scanf("%s",in);
	int num=1, res=-1;
	for (int i=0;;i++) {
		num *= 2;
		char str[10];
		sprintf(str,"%d",num);
		if (strlen(str)>9) break;
		bool flag = true;
		for (int j=0; j<strlen(in); j++) if (str[j]!=in[j]) flag=false;
		if (flag) {
			res=num;
			break;
		}
	}
	printf("%d\n", res);
}