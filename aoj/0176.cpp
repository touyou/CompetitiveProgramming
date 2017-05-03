#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
string color[] = {"black", "blue", "lime", "aqua",
    "red", "fuchsia", "yellow", "white"};
int nums[][3] = {{0,0,0}, {0,0,255}, {0,255,0}, {0,255,255},
    {255,0,0}, {255,0,255}, {255,255,0}, {255,255,255}};

int convert(string str) {
    int res = 0;
    if ('0'<=str[0]&&str[0]<='9') {
        res += (str[0]-'0') * 16;
    } else if ('a'<=str[0]&&str[0]<='f') {
        res += (str[0]-'a'+10) * 16;
    }
    if ('0'<=str[1]&&str[1]<='9') {
        res += (str[1]-'0');
    } else if ('a'<=str[1]&&str[1]<='f') {
        res += (str[1]-'a'+10);
    }
    return res;
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "0") break;
        double d = 10000000.0;
        string res;
        int r = convert(str.substr(1,2)), g = convert(str.substr(3,2)), b = convert(str.substr(5,2));
        for (int i=0; i<8; i++) {
            double tmp = sqrt(pow(r-nums[i][0], 2)+pow(g-nums[i][1], 2)+pow(b-nums[i][2], 2));
            if (tmp < d) {
                d = tmp;
                res = color[i];
            }
        }
        cout << res << endl;
    }
}
