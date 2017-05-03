#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(a) sort((a).begin(), (a).end())
#define PB push_back
#define MP make_pair
#define REP(i,n)  for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n);i>=0;i--) 
typedef vector<int> vi;
typedef vector<string> vs;

class QualityPolygons {
	public:
	vs choosePolygons(vi points, int sidesDiff, int radiiDiff) {
		/* 条件 */
		double minSD = 1-(double)sidesDiff/100, minRD = 1-(double)radiiDiff/100;
		vs res;	// 答え
		set<int> /*m,*/pp;	// 使った頂点
		int pnum=SZ(points)/2;	// 点の数
		bool flag=false;
		REP(i,pnum) pp.insert(i);
		/*
		方針：
			簡単のため、三角形のみで考える。
			条件を満たすように三重ループで貪欲法
		*/
		for (int k=0; k<pnum-2; k++) {
			double x1=points[k*2],y1=points[k*2+1];
//			if (m.find(k)==m.end()) {
			if (pp.find(k)!=pp.end()) {
				for(int i=k+1; i<pnum-1; i++) {
					double x2=points[i*2],y2=points[i*2+1];
//					if (m.find(i)==m.end()) {
					if (pp.find(i)!=pp.end()) {
						for (int j=i+1; j<pnum; j++) {
//							if (m.find(j)!=m.end()) continue;
							if (pp.find(j)==pp.end()) continue;
							double x3=points[j*2],y3=points[j*2+1];
							/* 各辺 */
							double l1=sqrt(pow(x1-x2,2)+pow(y1-y2,2)),l2=sqrt(pow(x1-x3,2)+pow(y1-y3,2)),l3=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
							double minL=min(l1,min(l2,l3));
							double maxL=max(l1,max(l2,l3));
							/* 三角形限定として、三角形の成立条件 */
							if (l1>=l2+l3||l2>=l1+l3||l3>=l1+l2) continue;
							
							double cX=(double)(x1+x2+x3)/3, cY=(double)(y1+y2+y3)/3;
							double minD=min(sqrt(pow(cX-x1,2)+pow(cY-y1,2)),min(sqrt(pow(cX-x2,2)+pow(cY-y2,2)),sqrt(pow(cX-x3,2)+pow(cY-y3,2))));
							double maxD=max(sqrt(pow(cX-x1,2)+pow(cY-y1,2)),max(sqrt(pow(cX-x2,2)+pow(cY-y2,2)),sqrt(pow(cX-x3,2)+pow(cY-y3,2))));
							/* 問題文中の条件 */
							if (minL/maxL<minSD||minD/maxD<minRD) continue;
							
							char str[255];
							sprintf(str,"%d %d %d",k,i,j);
							res.PB(str);
							/* 使った頂点をセットに追加 */
//							m.insert(k);m.insert(i);m.insert(j);
							/* 使った頂点を削除 */
							pp.erase(k);pp.erase(i);pp.erase(j);
							flag = true;
							break;		// kとiの重複を防ぐ
						}
					}
					/* kの重複を防ぐ */
					if (flag) break;
				}
			}
			flag=false;
		}
/*//	四角形を考慮する場合（暫定）
		set<int>::iterator it=pp.begin();
		while (it!=nums.end()) {
			int x1=points[(*it)*2],y1=points[(*it)*2+1];
			++it;
			while (it!=num.end()) {
				int x2=points[(*it)*2],y2=points[(*it)*2+1];
				++it;
				while (it!=nums.end()) {
					int x3=points[(*it)*2],y3=points[(*it)*2+1];
					++it;
					while (it!=nums.end()) {
						
					}
				}
			}
		}
*/
		return res;
	}
};

int main() {
	QualityPolygons qp;
	int N; scanf("%d",&N);
	vi points(N);
	REP(i,N) scanf("%d",&points[i]);
	int sidesDiff; scanf("%d",&sidesDiff);
	int radiiDiff; scanf("%d",&radiiDiff);
	vs ret = qp.choosePolygons(points,sidesDiff,radiiDiff);
	printf("%d\n",SZ(ret));
	REP(i,SZ(ret)) cout<<ret[i]<<endl;
	return 0;
}
