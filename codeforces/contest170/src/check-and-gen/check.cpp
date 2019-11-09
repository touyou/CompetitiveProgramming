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

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const long double SCALE = 10;
const long double EPS = 1E-10;

int w, h, n;
vector<int> wi, hi;

bool same(long double a, long double b)
{
    return fabsl(a - b) < EPS;
}

int roundScaled(long double d, TResult error)
{
    if (d < 0 || d > 1E9 / SCALE)
        quitf(error, "Number is out of range: %.10lf", double(d));

    return int(d * SCALE + 0.5);
}

bool isRound(long double d, TResult error)
{
    return same(d * SCALE, roundScaled(d, error));
}

int readAnswer(InStream& in, TResult error)
{
    vector<int> lx, rx, by, ty, t;

    forn(i, n)
    {
        long double x1 = in.readDouble();
        long double y1 = in.readDouble();
        long double x2 = in.readDouble();
        long double y2 = in.readDouble();
        
        if (same(x1, -1) && same(y1, -1) && same(x2, -1) && same(y2, -1))
        {
            lx.push_back(-1);
            by.push_back(-1);
            rx.push_back(-1);
            ty.push_back(-1);
            t.push_back(-1);
            continue;
        }

        if (x1 > x2)
            swap(x1, x2);

        if (y1 > y2)
            swap(y1, y2);

        if (!isRound(x1, error) || !isRound(y1, error) || !isRound(x2, error) || !isRound(y2, error))
            quitf(error, "Coordinates of the rectangle #%d have invalid precision", i + 1);

        int _x1 = roundScaled(x1, error);
        int _y1 = roundScaled(y1, error);
        int _x2 = roundScaled(x2, error);
        int _y2 = roundScaled(y2, error);

        lx.push_back(_x1);
        by.push_back(_y1);
        rx.push_back(_x2);
        ty.push_back(_y2);

        if (_x1 < 0 || _x1 > w || _y1 < 0 || _y1 > h
                || _x2 < 0 || _x2 > w || _y2 < 0 || _y2 > h)
            quitf(error, "Coordinates of the rectangle #%d are out of range", i + 1);

        if (_x1 == _x2 || _y1 == _y2)
            quitf(error, "Rectangle #%d has zero size", i + 1);

        long double scale = (x2 - x1) / (y2 - y1);
        long double expScale = (long double)(wi[i]) / (long double)(hi[i]);

        int dx, dy;

        if (same(expScale, scale))
        {
            dx = _x2 - _x1;
            dy = _y2 - _y1;
            t.push_back(0);
        }
        else
        {
            scale = 1.0 / scale;
            if (!same(expScale, scale))
                quitf(error, "Rectangle #%d is not scaled", i + 1);

            dx = _y2 - _y1;
            dy = _x2 - _x1;
            t.push_back(1);
        }

        if (dx > 2 * wi[i] || dx * 10 < wi[i])
            quitf(error, "Rectangle #%d illegal scale (width)", i + 1);

        if (dy > 2 * hi[i] || dy * 10 < hi[i])
            quitf(error, "Rectangle #%d illegal scale (height)", i + 1);
    }

    int score = 0;

    forn(i, n)
        forn(j, i)
        {
            if (t[i] == -1 || t[j] == -1)
                continue;

            int x1 = max(lx[i], lx[j]);
            int x2 = min(rx[i], rx[j]);
            
            int y1 = max(by[i], by[j]);
            int y2 = min(ty[i], ty[j]);

            if (x1 < x2 && y1 < y2)
                quitf(error, "Rectangles #%d and #%d are intersect", i + 1, j + 1);

            if (x1 < x2 && y1 == y2)
                score += (t[i] == t[j] ? -1 : 1) * (x2 - x1);
            
            if (y1 < y2 && x1 == x2)
                score += (t[i] == t[j] ? -1 : 1) * (y2 - y1);
        }

    return score;
}

int main(int argc, char* argv[])
{
    setName("VK Cup 2012 Wild-card Round 2: Rectangles");

    if (argc != 3 && argc != 4)
        quitf(_fail, "argc != 3 && argc != 4");

    char* _argv[] = {argv[0], argv[1], argv[2], argv[2]};
    registerTestlibCmd(4, _argv);

    w = roundScaled(inf.readInt(), _fail);
    h = roundScaled(inf.readInt(), _fail);
    n = inf.readInt();

    wi = hi = vector<int>(n);

    forn(i, n)
    {
        wi[i] = roundScaled(inf.readInt(), _fail);
        hi[i] = roundScaled(inf.readInt(), _fail);
    }

    long double pa = readAnswer(ouf, _wa) / SCALE;

    quitp(pa, "w=%.0lf, h=%.0lf, n=%d",
        double(w / SCALE), double(h / SCALE), n);
}
