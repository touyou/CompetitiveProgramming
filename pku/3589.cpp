#include <iostream>
using namespace std;
int main() {
	int T;
	cin>>T;
	for (int ix=0; ix<T; ix++) {
		string X, Y;
		cin>>X>>Y;
		int A=0, B=0;
		for (int j=0; j<4; j++) {
			char temp = Y[j];
			for (int k=0; k<4; k++) {
				if (temp == X[k] && j == k) {
					A++;
					break;
				} else if (temp == X[k]) {
					B++;
					break;
				}
			}
		}
		cout<<A<<"A"<<B<<"B"<<endl;
	}
}
