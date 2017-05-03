#include <cstdio>
using namespace std;
int main() {
	char str;
	bool flag=true;
	while (scanf("%c",&str)!=EOF) {
		if (flag&&str=='"') {
			printf("``");
			flag = false;
		} else if (!flag&&str=='"') {
			printf("\'\'");
			flag = true;
		} else {
			printf("%c",str);
		}
	}
}
