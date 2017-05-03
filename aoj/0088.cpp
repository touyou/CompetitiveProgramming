#include <iostream>
#include <string>
using namespace std;
string ab[26] = {
"100101","10011010","0101","0001","110",
"01001","10011011","010000","0111","10011000",
"0110","00100","10011001","10011110","00101",
"111","10011111","1000","00110","00111",
"10011100","10011101","000010","10010010","10010011",
"10010000"};
string ctoi(char c) {
    if (c==' ') return "101";
    else if (c=='\'') return "000000";
    else if (c==',') return "000011";
    else if (c=='-') return "10010001";
    else if (c=='.') return "010001";
    else if (c=='?') return "000001";
    else if (c>='A'&&c<='Z') return ab[c-'A'];
}
char itoc(string num) {
    if (num=="00000") return 'A';
    if (num=="00001") return 'B';
    if (num=="00010") return 'C';
    if (num=="00011") return 'D';
    if (num=="00100") return 'E';
    if (num=="00101") return 'F';
    if (num=="00110") return 'G';
    if (num=="00111") return 'H';
    if (num=="01000") return 'I';
    if (num=="01001") return 'J';
    if (num=="01010") return 'K';
    if (num=="01011") return 'L';
    if (num=="01100") return 'M';
    if (num=="01101") return 'N';
    if (num=="01110") return 'O';
    if (num=="01111") return 'P';
    if (num=="10000") return 'Q';
    if (num=="10001") return 'R';
    if (num=="10010") return 'S';
    if (num=="10011") return 'T';
    if (num=="10100") return 'U';
    if (num=="10101") return 'V';
    if (num=="10110") return 'W';
    if (num=="10111") return 'X';
    if (num=="11000") return 'Y';
    if (num=="11001") return 'Z';
    if (num=="11010") return ' ';
    if (num=="11011") return '.';
    if (num=="11100") return ',';
    if (num=="11101") return '-';
    if (num=="11110") return '\'';
    if (num=="11111") return '?';
}
int main() {
    string str;
    while (getline(cin,str)) {
        string num="";
        for (int i=0; i<str.length(); i++) num+=ctoi(str[i]);
        int cnt=0;
        string temp="", res="";
        for (int i=0; i<num.length(); i++) {
            cnt++;
            temp+=num[i];
            if (cnt==5) {
                res+=itoc(temp);
                cnt=0;
                temp="";
            }
        }
        if (temp.length()>0) {
            while (temp.length()<5) {
                temp+='0';
            }
            res+=itoc(temp);
        }
        cout << res << endl;
    }
}
