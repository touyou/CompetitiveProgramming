#include <iostream>
using namespace std;

int flag=-1, stat=-1;
char len[9][10]={{'.','@','-','_','/',':','~','1'},
{'a','b','c','A','B','C','2'},
{'d','e','f','D','E','F','3'},
{'g','h','i','G','H','I','4'},
{'j','k','l','J','K','L','5'},
{'m','n','o','M','N','O','6'},
{'p','q','r','s','P','Q','R','S','7'},
{'t','u','v','T','U','V','8'},
{'w','x','y','z','W','X','Y','Z','9'}};
int upper[9] = {8,7,7,7,7,7,9,7,9};
string inp, ans="";

int main() {
    cin>>inp;
    for (int i=0; i<inp.length(); i++) {
        if (inp[i] == 'E') {
            ans.push_back(len[flag][stat]);
            flag = -1; stat = -1;
        } else {
            int temp = int(inp[i] - '0') - 1;
            if (stat != -1 && flag != temp) {
                ans.push_back(len[flag][stat]);
                flag = temp; stat = 0;
            } else {
                flag = temp; stat++;
                if (stat == upper[flag]) stat = 0;
            }
        }
    }
    cout<<ans<<endl;
}
