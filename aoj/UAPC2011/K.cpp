#include <iostream>
using namespace std;
int main() {
	int r,c;
	while (cin>>r>>c&&r!=0&&c!=0) {
		if (r%2==0||c%2==0) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}
