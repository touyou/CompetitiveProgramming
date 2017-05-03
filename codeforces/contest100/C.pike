#! /usr/bin/env pike

int main() {
	string a = Stdio.stdin.gets();
	string b = Stdio.stdin.gets();
	a = reverse(a, 0, sizeof(a)-1);
	b = reverse(b, 0, sizeof(b)-1);
	int len,long,flag;
	if (sizeof(a) < sizeof(b)) {
		len = sizeof(a);
		long = sizeof(b);
		flag=0;
	} else {
		len = sizeof(b);
		long = sizeof(a);
		flag=1;
	}
	string res = "";
	int amari = 0;
	for (int i = 0; i < len; i++) {
		int temp = amari + (a[i]-'0') + (b[i]-'0');
		if (temp >= 10) {
			amari = 1;
			temp -= 10;
		} else {
			amari = 0;
		}
		res += temp;
	}
	if (flag==0) {
		for (int i=len; i<long; i++) {
			int temp = amari+(b[i]-'0');
			if (temp>=10) {
				amari=1;
				temp-=10;
			} else {
				amari=0;
			}
			res+=temp;
		}
	} else {
		for (int i=len; i<long; i++) {
			int temp = amari+(a[i]-'0');
			if (temp>=10) {
				amari=1;
				temp-=10;
			} else {
				amari=0;
			}
			res+=temp;
		}
	}
	if (amari != 0) res += amari;
	res = reverse(res, 0, sizeof(res)-1);
	write(res + "\n");
}
