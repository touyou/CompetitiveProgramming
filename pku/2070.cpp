#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	float sp;
	int we, st;
	while (scanf("%f%d%d", &sp, &we, &st)) {
		if (sp == 0 && we == 0 && st == 0) break;
		vector<string> ans;
		if (sp <= 4.5 && we >= 150 && st >= 200) {
			ans.push_back("Wide Receiver");
		}
		if (sp <= 6.0 && we >= 300 && st >= 500) {
			ans.push_back("Lineman");
		}
		if (sp <= 5.0 && we >= 200 && st >= 300) {
			ans.push_back("Quarterback");
		}
		if (ans.size() == 0) {
			printf("No positions\n");
		} else {
			for (int i=0; i<ans.size()-1; i++) cout << ans[i] << " ";
			cout << ans[ans.size()-1] << endl;
		}
	}
}