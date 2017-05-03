#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#define inf INT_MAX/2
using namespace std;
struct edge { int to, cost; };
int d[100];
vector<edge> G[100];

