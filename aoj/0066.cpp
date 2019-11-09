#include <iostream>
using namespace std;
int main() {
	string str;
	char map[3][3];
	while (cin>>str) {
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++) map[i][j] = str[i*3+j];
		char res = 'd';
		for (int i=0; i<3; i++)
			if (map[i][0]==map[i][1]&&map[i][1]==map[i][2]&&map[i][0]!='s')
				res = map[i][0];
		for (int i=0; i<3; i++) 
			if (map[0][i]==map[1][i]&&map[1][i]==map[2][i]&&map[0][i]!='s')
				res = map[0][i];
		if ((map[0][0]==map[1][1]&&map[1][1]==map[2][2]&&map[0][0]!='s')||
				(map[0][2]==map[1][1]&&map[1][1]==map[2][0]&&map[0][2]!='s'))
			res = map[1][1];
		cout << res << endl;
	}
}
