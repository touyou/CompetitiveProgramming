#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n;
    while (cin>>n&&n!=0) {
        string str;
        cin >> str;
        vector<string> map(str.length()/n, "");
        for (int i=0; i<str.length()/n; i++) {
            if (i % 2 == 0) {
                for (int j=i*n; j<i*n+n; j++) map[i] += str[j];
            }
            else {
                for (int j=(i+1)*n-1; j>=i*n; j--) map[i] += str[j];
            }
        }
        string res = "";
        for (int i=0; i<n; i++) for (int j=0; j<map.size(); j++)
                                    res += map[j][i];
        cout << res << endl;
    }
}

