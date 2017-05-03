 /*
Write a program which prints the central coordinate (px, py) and the radius r of a circumscribed circle of a triangle which is constructed by three points (x1, y1)(x2, y2)(x3, y3) on the plane surface.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

 /*
http://zo3kirin3.net/?p=297
http://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q104383420
http://www.nn.iij4u.or.jp/~hsat/misc/math/centre/circumcentre.html
 */

int main() {
	int n; cin >> n;
	// x,yが座標のリスト、x2,y2が座標の二乗のリスト
	vector<double> x(3), y(3), x2(3), y2(3);
	
	for (int p=0; p<n; p++) {
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
		for (int i=0; i<3; i++) {
			x2[i] = x[i]*x[i];
			y2[i] = y[i]*y[i];
		}
		
		// 各辺の長さを求める。三平方の定理を利用
		double a, b, c, a2, b2, c2;
		a2 = abs((x[2]-x[1])*(x[2]-x[1]) + (y[2]-y[1])*(y[2]-y[1]));
		b2 = abs((x[0]-x[2])*(x[0]-x[2]) + (y[0]-y[2])*(y[0]-y[2]));        
		c2 = abs((x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]));
		a = sqrt(a2); b = sqrt(b2); c = sqrt(c2);
		
		// 面積。ヘロンの公式を利用。
		double s, S2;
		s = (a+b+c) / 2;
		S2 = s * (s-a) * (s-b) * (s-c);
		
		// 外心を求める。公式はWebページを参照←ベクトルやってないから説明できない…
		double px, py;
		px = (a2*(b2+c2-a2)*x[0] + b2*(c2+a2-b2)*x[1] + c2*(a2+b2-c2)*x[2]) / (16 * S2);
		py = (a2*(b2+c2-a2)*y[0] + b2*(c2+a2-b2)*y[1] + c2*(a2+b2-c2)*y[2]) / (16 * S2);
        
		// 出力。整形して出力する。半径は直線の方程式で。
		cout << setprecision(3) << fixed << px << " " << py << " " << sqrt(abs((px-x[0])*(px-x[0])+(py-y[0])*(py-y[0]))) << endl;
    }
	
	return 0;
}
