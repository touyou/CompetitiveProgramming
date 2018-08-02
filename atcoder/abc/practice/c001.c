#include <stdio.h>
#include <math.h>

char* forecast(int deg, int wp) {
    if (wp == 0) return "C";
    if (deg >= 113 && deg <= 337) {
        return "NNE";
    } else if (deg >= 338 && deg <= 562) {
        return "NE";
    } else if (deg >= 553 && deg <= 787) {
        return "ENE";
    } else if (deg >= 788 && deg <= 1012) {
        return "E";
    } else if (deg >= 1013 && deg <= 1237) {
        return "ESE";
    } else if (deg >= 1238 && deg <= 1462) {
        return "SE";
    } else if (deg >= 1463 && deg <= 1687) {
        return "SSE";
    } else if (deg >= 1688 && deg <= 1912) {
        return "S";
    } else if (deg >= 1913 && deg <= 2137) {
        return "SSW";
    } else if (deg >= 2138 && deg <= 2362) {
        return "SW";
    } else if (deg >= 2363 && deg <= 2587) {
        return "WSW";
    } else if (deg >= 2588 && deg <= 2812) {
        return "W";
    } else if (deg >= 2813 && deg <= 3037) {
        return "WNW";
    } else if (deg >= 3038 && deg <= 3262) {
        return "NW";
    } else if (deg >= 3263 && deg <= 3487) {
        return "NNW";
    } else {
        return "N";
    }
}

int main() {
    int deg, dis;
    scanf("%d%d", &deg, &dis);
    int wp;
    double wv = round((double)dis / 6.0) / 10.0;
    if (wv <= 0.2) {
        wp = 0;
    } else if (wv >= 0.3 && wv <= 1.5) {
        wp = 1;
    } else if (wv >= 1.6 && wv <= 3.3) {
        wp = 2;
    } else if (wv >= 3.4 && wv <= 5.4) {
        wp = 3;
    } else if (wv >= 5.5 && wv <= 7.9) {
        wp = 4;
    } else if (wv >= 8.0 && wv <= 10.7) {
        wp = 5;
    } else if (wv >= 10.8 && wv <= 13.8) {
        wp = 6;
    } else if (wv >= 13.9 && wv <= 17.1) {
        wp = 7;
    } else if (wv >= 17.2 && wv <= 20.7) {
        wp = 8;
    } else if (wv >= 20.8 && wv <= 24.4) {
        wp = 9;
    } else if (wv >= 24.5 && wv <= 28.4) {
        wp = 10;
    } else if (wv >= 28.5 && wv <= 32.6) {
        wp = 11;
    } else {
        wp = 12;
    }
    printf("%s %d\n", forecast(deg, wp), wp);
    return 0;
}
