#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
int toInt(string s)
{
    stringstream ss;
    ss.str(s);
    int res;
    ss >> res;
    return res;
}

string toString(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int main()
{
    int N; cin >> N;
    string num1, num2, res;
    int n1, n2, sum;
    for (int ix=0; ix<N; ix++) {
        cin >> num1 >> num2;
        reverse(ALL(num1));
        reverse(ALL(num2));
        n1 = toInt(num1);
        n2 = toInt(num2);
        sum = n1 + n2;
        res = toString(sum);
        reverse(ALL(res));
        cout << toInt(res) << endl;
    }
}
