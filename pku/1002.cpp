/*#include <vector>
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
#include <fstream>
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
// 310-1010
// 487-3279
// 888-4567
// ABC->2,DEF->3,GHI->4,JKL->5,MNO->6,PRS->7,TUV->8,WXY->9
// QZ->*
/*string solve(string tmp) {
	for (int j=0; j<tmp.length(); j++) {
		if (tmp[j] == '-' || tmp[j] == 'Q' || tmp[j] == 'Z') {
			tmp[j] = '\0';
		} else if (tmp[j] == 'A' || tmp[j] == 'B' || tmp[j] == 'C') {
			tmp[j] = '2';
		} else if (tmp[j] == 'D' || tmp[j] == 'E' || tmp[j] == 'F') {
			tmp[j] = '3';
		} else if (tmp[j] == 'G' || tmp[j] == 'H' || tmp[j] == 'I') {
			tmp[j] = '4';
		} else if (tmp[j] == 'J' || tmp[j] == 'K' || tmp[j] == 'L') {
			tmp[j] = '5';
		} else if (tmp[j] == 'M' || tmp[j] == 'N' || tmp[j] == 'O') {
			tmp[j] = '6';
		} else if (tmp[j] == 'P' || tmp[j] == 'R' || tmp[j] == 'S') {
			tmp[j] = '7';
		} else if (tmp[j] == 'T' || tmp[j] == 'U' || tmp[j] == 'V') {
			tmp[j] = '8';
		} else if (tmp[j] == 'W' || tmp[j] == 'X' || tmp[j] == 'Y') {
			tmp[j] = '9';
		}
	}
	return tmp;
}

string solve(string str)
{
	int ret;
	
	for (string::iterator it = str.begin(); it != str.end(); it++){
		// アルファベットだった場合は数字に置き換え
		if (isalpha(*it)){
			switch (*it){
			  case 'A': case 'B': case 'C': ret = 0; break;
			  case 'D': case 'E': case 'F': ret = 1; break;
			  case 'G': case 'H': case 'I': ret = 2; break;
			  case 'J': case 'K': case 'L': ret = 3; break;
			  case 'M': case 'N': case 'O': ret = 4; break;
			  case 'P': case 'R': case 'S': ret = 5; break;
			  case 'T': case 'U': case 'V': ret = 6; break;
			  case 'W': case 'X': case 'Y': ret = 7; break;
			}
			(*it) = (char)(ret + '2');
		}
		
		// 一旦ハイフンを全て削除する
		if ((*it) == '-'){
			it = str.erase(it);
			it--;
		}
	}
	
	// ハイフンを追加
	str.insert(3,"-");
	
	return (str);
}


int main() {
	int n; cin >> n;
	bool overlap = false;
	map<string, int> phone;
	string str;
	for (int i=0; i<n; i++) {
		cin >> str;
		if (phone.empty() || phone.count(solve(str))) {
			phone.insert(pair<string, int> (solve(str), 1));
		} else {
			phone[solve(str)]++;
		}
	}
	for (map<string, int>::iterator it = phone.begin(); it != phone.end(); it++) {
		if (1 < (*it).second) {
			cout << (*it).first << " " << (*it).second << endl;
			overlap = true;
		}
	}
	if (!overlap) {
		cout << "No duplicates." << endl;
	}
	return 0;
}*/
#include <iostream>
#include <map>
#include <string>
int main(){
        using namespace std;
        int i, j, c, sz, n;
        string s;
        char r[9];
        map<string, int> m;
        cin>>n;
        for(i=0;i<n;i++){
                c=0;
                cin>>s;
                for(j=0,sz=s.size();j<sz;j++){
                        if(47<s[j]&&s[j]<58){r[c]=s[j];c++;continue;}
                        if(64<s[j]&&s[j]<81){r[c]=(s[j]-65)/3+50;c++;continue;}
                        if(81<s[j]&&s[j]<90){r[c]=(s[j]-66)/3+50;c++;continue;}
                }
                r[c]=0;
                m[r]++;
        }
        map<string, int>::iterator it = m.begin();
        while(it != m.end()){
                if(1 < (*it).second){
                        n = 0;
                        s=(*it).first;s.insert(3,"-");
                        cout<<s<<" "<<(*it).second<<endl;
                }
                ++it;
        }
        if(n) cout<<"No duplicates.";
}
