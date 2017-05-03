// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp
// Appendixを参考にする
#include <bits/stdc++.h>
using namespace std;
int n, cur;
string str;
int expression();
int factor();
int digit() {
    assert(isdigit(str[cur]));
    int n = str[cur] - '0';
    cur++;
    return n;
}
int number() {
    int n = digit();
    while (cur < str.size() && isdigit(str[cur])) n = n * 10 + digit();
    return n;
}
int factor() {
    if (str[cur] != '(') return number();
    cur++;
    int n = expression();
    assert(str[cur] == ')');
    cur++;
    return n;
}
int term() {
    int a = factor();
    while (cur < str.size() && (str[cur] == '*' || str[cur] == '/')) {
        char op = str[cur++];
        int b = factor();
        if (op == '*') a *= b;
        else a /= b;
    }
    return a;
}
int expression() {
    int a = term();
    while (cur < str.size() && (str[cur] == '+' || str[cur] == '-')) {
        char op = str[cur++];
        int b = term();
        if (op == '+') a += b;
        else a -= b;
    }
    return a;
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        cur = 0;
        cin >> str;
        str.resize(str.size() - 1);
        printf("%d\n", expression());
    }
}
