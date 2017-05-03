#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<bool> vb;

vb makeTable() {
	vb p(10001, true);
	p[1]=false;
	for(int i=4;i<=10000;i+=2)p[i]=false;
	for(int i=3;i<=10000;i+=2){
		if(p[i]){
			for(int j=i*2;j<=10000;j+=i)p[j]=false;
		}
	}
	return p;
}

int main() {
	vb table = makeTable();
	int N;
	while (cin >> N) {
		int cnt=0;
		for(int i=1;i<=N;i++){
			if(table[i]&&table[N-i+1]) cnt++;
		}
		cout << cnt << endl;
	}
}
