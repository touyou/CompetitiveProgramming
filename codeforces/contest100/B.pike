#! /usr/bin/env pike

int main() {
	string num = Stdio.stdin.gets();
	string in = Stdio.stdin.gets();
	int n;
	sscanf(num,"%d",n);
	array(string) ary = in / ",";
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		sscanf(ary[i],"%d",a);
		for (int j = 0; j < i; j++) {
			sscanf(ary[j], "%d",b);
			if (b % a != 0&&a%b!=0) {
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		write("FRIENDS\n");
	} else {
		write("NOT FRIENDS\n");
	}
}
