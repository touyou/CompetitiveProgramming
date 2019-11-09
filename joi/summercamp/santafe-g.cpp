#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unistd.h>
using namespace std;

// func and term
enum {IF_FOOD_AHEAD, PROG2, PROG3, RIGHT, LEFT, MOVE};
// vector
enum {U, R, D, L};
// gen mode
enum {FULL, GROW};
// variants
int n, e, cnt, foods[55][55], FOODS[55][55], ant[55][55];
string mp[55], MP[55];

class Tree {
};
