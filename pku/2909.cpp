#include <cstdio>
int main()
{
	int n;
	int prime[50001];
	for(int i = 0; i <= 50000; i++)
		prime[i] = 1;
	prime[0] = 0; prime[1] = 0;
	for(int i = 2; i <= 50000; i++){
		if(!prime[i]) continue;
		for(int j = i + i; j <= 50000; j += i)
			prime[j] = 0;
	}
	while(scanf("%d\n", &n)&&n!=0){
		int cnt = 0;
		for(int i = 2; i <= n / 2; i++)
			if(prime[i] && prime[n - i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

