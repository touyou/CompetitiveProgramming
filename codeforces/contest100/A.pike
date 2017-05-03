#! /usr/bin/env pike

int main() {
	int n, k, n1, i = 0;
	string in = Stdio.stdin.gets();
	sscanf(in, "%d%d%d",n,k,n1); 
	while (n1 * i < n)
		i++;
	if (i * i <= k)
		write("YES\n");
	else
		write("NO\n");
}
