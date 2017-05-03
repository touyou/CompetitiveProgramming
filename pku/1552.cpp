#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int in;
    while (scanf("%d",&in)) {
        if (in == -1) break;
        vector<int> num;
        num.push_back(in);
        while (scanf("%d",&in)) {
            if (in == 0) break;
            num.push_back(in);
        }
        sort(num.begin(), num.end());
        int cnt = 0;
        for (int i=0; i<num.size()-1; i++) {
            int temp = num[i];
            for (int j=i+1; j<num.size(); j++) {
                if (temp*2 == num[j]) {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
