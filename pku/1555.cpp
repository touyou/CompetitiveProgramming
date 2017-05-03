#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

int main() 
{
    int n[9];
    while (scanf("%d", &n[0])!=EOF) {
        for (int i=1; i<9; i++) scanf("%d", &n[i]);
        bool first = true;
        string res = "";
        for (int i=0; i<8; i++) {
            if (n[i] == 0) continue;
            stringstream ss1;
            ss1 << 8-i;
            string xstr;
            if (i == 7) {
                xstr = "x";
            } else {
                xstr = "x^" + ss1.str();
            }
            if (first) {
                first = false;
                if (n[i] == -1) {
                    res += "-" + xstr;
                } 
                else if (n[i] == 1) {
                    res += xstr;
                } 
                else {
                    stringstream ss;
                    ss << n[i];
                    res += ss.str() + xstr;
                }
            }
            else {
                if (n[i] == -1) {
                    res += " - " + xstr;
                }
                else if (n[i] == 1) {
                    res += " + " + xstr;
                }
                else if (n[i] < 0) {
                    res += " - ";
                    stringstream ss;
                    ss << -n[i];
                    res += ss.str() + xstr;
                }
                else {
                    res += " + ";
                    stringstream ss;
                    ss << n[i];
                    res += ss.str() + xstr;
                }
            }
        }
		if (first) {
			stringstream ss;
			ss << n[8];
			res += ss.str();
		} else {
			if (n[8] < 0) {
				stringstream ss;
				ss << -n[8];
				res += " - " + ss.str();
			}
			else if (n[8] > 0) {
				stringstream ss;
				ss << n[8];
				res += " + " + ss.str();
			}
		}
        cout << res << endl;
    }
}
