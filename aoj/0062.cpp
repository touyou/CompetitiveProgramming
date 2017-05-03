#include <iostream>
using namespace std;
int main() {
	int top[10];
	char temp;
	while (cin>>temp) {
		top[0] = temp - '0';
		for (int i=1; i<10; i++) {
			cin>>temp;
			top[i] = temp - '0';
		}
		for (int i=10; i>0; i--) {
			for (int j=0; j+1<i; j++) {
				top[j] = (top[j] + top[j+1]) % 10;
			}
		}
		cout<<top[0]<<endl;
	}
}
