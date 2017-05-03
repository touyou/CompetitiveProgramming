#include <iostream>

using namespace std;

int main() {
	double weight;
	while (cin >> weight) {
		if (weight <= 48.0) cout << "light fly" << endl;
		else if (weight <= 51.0) cout << "fly" << endl;
		else if (weight <= 54.0) cout << "bantam" << endl;
		else if (weight <= 57.0) cout << "feather" << endl;
		else if (weight <= 60.0) cout << "light" << endl;
		else if (weight <= 64.0) cout << "light welter" << endl;
		else if (weight <= 69.0) cout << "welter" << endl;
		else if (weight <= 75.0) cout << "light middle" << endl;
		else if (weight <= 81.0) cout << "middle" << endl;
		else if (weight <= 91.0) cout << "light heavy" << endl;
		else cout << "heavy" << endl;
	}
}
