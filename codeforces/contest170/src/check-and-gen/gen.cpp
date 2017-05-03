#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const double EPS = 1E-8;

int main(int argc, char* argv[])
{
    registerGen(argc, argv);

    int w = rnd.next(10, 100);
    int h = rnd.next(10, 100);
    int n = rnd.next(5, 100);

    cout << w << " " << h << endl << n << endl;

    forn(i, n)
    {
        int w_i, h_i;

        while (true)
        { 
            double expRatio = rnd.next(1.0, 10.0);
            if (rnd.next(2) == 0)
                expRatio = 1.0 / expRatio;

            if (rnd.next(2) == 0)
            {
                w_i = rnd.next(1, w);
                h_i = int(w_i * expRatio + 0.5);
            }
            else
            {
                h_i = rnd.next(1, h);
                w_i = int(h_i * expRatio + 0.5);
            }

            if (w_i * 10 < w || w_i < 1 || w_i > w)
                continue;
            if (h_i * 10 < h || h_i < 1 || h_i > h)
                continue;

            double ratio = double(w_i) / double(h_i);
            if (ratio + EPS < 0.1 || ratio > 10.0 + EPS)
                continue;

            if (h_i == w_i)
                continue;

            break;
        }

        cout << w_i << " " << h_i << endl;
    }

    return 0;
}