#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string haiku;
    while (getline(cin, haiku)) {
        if (haiku == "e/o/i") break;
        int i = 0;
        int cnt = 0;
        bool flag = true;
        for (; i < haiku.length(); i++) {
            if (haiku[i] == '/') break;
            if ((haiku[i] == 'a' || haiku[i] == 'e'
                 || haiku[i] == 'i' || haiku[i] == 'o'
                 || haiku[i] == 'u' || haiku[i] == 'y') && flag) {
                cnt++;
                flag = false;
            }
            else {
                flag = true;
            }
        }
        if (cnt != 5) {
            printf("1\n");
            continue;
        }
        cnt = 0; i++; flag = true;
        for (; i <haiku.length(); i++) {
            if (haiku[i] == '/') break;
            if ((haiku[i] == 'a' || haiku[i] == 'e'
                 || haiku[i] == 'i' || haiku[i] == 'o'
                 || haiku[i] == 'u' || haiku[i] == 'y') && flag) {
                cnt++;
                flag = false;
            }
            else {
                flag = true;
            }
        }
        if (cnt != 7) {
            printf("2\n");
            continue;
        }
        cnt = 0; i++; flag = true;
        for (; i < haiku.length(); i++) {
            if ((haiku[i] == 'a' || haiku[i] == 'e'
                 || haiku[i] == 'i' || haiku[i] == 'o'
                 || haiku[i] == 'u' || haiku[i] == 'y') && flag) {
                cnt++;
                flag = false;
            }
            else {
                flag = true;
            }
        }
        if (cnt != 5) {
            printf("3\n");
            continue;
        }
        printf("Y\n");
    }
}

