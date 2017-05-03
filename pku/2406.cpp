#include <cstdio>

int main() 
{
    char in[10000];
    while (scanf("%s", in)) {
        if (in[0] == '.') break;
        if (sizeof(in) == 1) {
            printf("1\n");
            continue;
        }
        int i;
        char f = in[0];
        char key[10000];
        key[0] = in[0];
        for (i=1; i<sizeof(in); i++) {
            if (in[i] == f) break;
            key[i] = in[i];
        }
        if (i == sizeof(in)) {
            printf("1\n");
            continue;
        }
        // keyに不適合の場合加えていく
    }
}

