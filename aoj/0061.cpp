#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef map<int, int> INTMAP;
int search(vector<int> vec, int n) {
	for (int i=0; i<vec.size(); i++) {
		if (vec[i] == n) return i+1;
	}
	return 0;
}
int main() {
	INTMAP nums;
	vector<int> pts;
	int num, pt;
	while (scanf("%d%*c%d", &num, &pt)) {
		if (num == 0 && pt == 0) break;
		nums.insert(INTMAP::value_type(num, pt));
		if (search(pts,pt) == 0) pts.push_back(pt);
	}
	sort(pts.begin(), pts.end());
	reverse(pts.begin(), pts.end());
	while (scanf("%d", &num) != EOF) {
		printf("%d\n", search(pts, nums[num]));
	}
}
