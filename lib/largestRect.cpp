#include <algorithm>
#include <stack>
using namespace std;

struct Rectangle { int height; int pos; };

int getLargestRectangle(int size, int buff[]) {
	stack<Rectangle> S;
	int maxv = 0;
	buff[size] = 0;
	
	for (int i=0; i<=size; i++) {
		Rectangle rect;
		rect.height = buff[i];
		rect.pos = i;
		if (S.empty()) {
			S.push(rect);
		} else {
			if (S.top().height < rect.height) {
				S.push(rect);
			} else if (S.top().height > rect.height) {
				int target = i;
				while (!S.empty() && S.top().height >= rect.height) {
					Rectangle pre = S.top(); S.pop();
					int area = pre.height * (i-pre.pos);
					maxv = max(maxv, area);
					target = pre.pos;
				}
				rect.pos = target;
				S.push(rect);
			}
		}
	}
	return maxv;
}
