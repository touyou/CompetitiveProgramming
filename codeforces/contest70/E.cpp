#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

/*
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <memory.h>
using namespace std; 

const int inf = 1000*1000*1000; 
#define CL(x,a) memset(x,a,sizeof(x)); 
#define ALL(v) (v).begin(),(v).end() 
#define PII pair<int,int> 
#define PDI pair<double,int> 
#define MP(a,b) make_pair(a,b) 
#define FOR(i,n) for(int i=0;i<n;i++) 
typedef long long LL; 
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef vector< vector<PII > > vvpii; 

int n;
LL ar[100009],x;
set<LL> st;
bool isPrime(LL x)
{
        if (x % 2 == 0)
                return 0;
        for (LL i = 3; i*i <= x; i+=2)
        {
                if (x % i == 0)
                        return 0;
        }
        return 1;
}
int main() 
{ 
        scanf("%d%I64d",&n,&x);
        if (x == 2)
        {
                printf("0\n");
                return 0;
        }

        LL Min = inf;
        Min *= Min;
        for (int i=0;i<n;i++)
        {
                scanf("%I64d",&ar[i]);
                if (ar[i] == 1)
                {
                        printf("1\n");
                        return 0;
                }
                Min = min(ar[i],Min);
                st.insert(ar[i]);
        }
        if (Min > 2)
        {
                printf("-1");
                return 0;
        }
        int C = 1;
        for (int i=3;i<x;i+=2)
        {
                if (!isPrime(i))
                        continue;
                if (st.find(i) == st.end())
                {
                        printf("-1");
                        return 0;
                }
                C++; 
        }
        printf("%d",C);
        return 0; 
}
*/
