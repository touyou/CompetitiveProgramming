#!/usr/bin/env pike

int main() {
	int n;
	string num,init,fin;
	num = Stdio.stdin.gets();
	init = Stdio.stdin.gets();
	fin = Stdio.stdin.gets();
	sscanf(num,"%d",n);
	if(init[strlen(init)-1]=='/r') {
		init=init[0..strlen(init)-2];
	}
	if (fin[strlen(fin)-1]=='/r') {
		fin=fin[0..strlen(fin)-2];
	}
	int initlen=strlen(init), finlen=strlen(fin);
	int i;
	for (i=0; i<initlen&&i<finlen; i++)
		if (a[i]!=b[i])
			break;
	int q = initlen+finlen-i-i;
	if (q<=n) {
		write("Yes");
	} else {
		write("No");
	}
}

    int main(){
        int n;
        sscanf(Stdio.stdin->gets(),"%d",n);
        string a;
        a=Stdio.stdin->gets();
        if(a[strlen(a)-1]=='\r'){
            a=a[0..strlen(a)-2];
        }
        string b;
        b=Stdio.stdin->gets();
        if(b[strlen(b)-1]=='\r'){
            b=b[0..strlen(b)-2];
        }
        int as=strlen(a),bs=strlen(b);
        int i;
        for(i=0;i<as&&i<bs;i++)if(a[i]!=b[i])break;
        int q=as+bs-i-i;
        if(n<q)write("No");
        else write("Yes");
    }
