#! /usr/bin/env pike

int main() {
	int n, k;
	string words, nums, ns, ks;
	ns = Stdio.stdin.gets();
	words = Stdio.stdin.gets();
	ks = Stdio.stdin.gets();
	nums = Stdio.stdin.gets();
	sscanf(ns,"%d",n);
	sscanf(ks,"%d",ks);
	array(string) word = words/" ";
	array(string) num = nums/" ";
	
	for (int i=0; i<k; i++) {
		int temp;
		sscanf(num[i],"%d",temp);
		for (int j=temp-1; j<n; j+=temp) {
			if (word[j]=="off") word[j]="on";
			else word[j]="off";
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (i != 0) write(" ");
		write(word[i]);
	}
	write("\n");
}
