#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	vector<int> over;
	int num;
	float w, h;
	while (scanf("%d,%f,%f",&num,&w,&h)!=EOF) {
		double bmi = w/pow(h,2);
		if (bmi>=25) over.push_back(num);
	}
	if (over.empty()) {
		printf("該当なし\n");
	} else {
		for (int i=0; i<over.size(); i++) printf("%d\n",over[i]);
	}
}
