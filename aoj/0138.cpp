#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
struct P {
double first;
int second;
};
class great {
public:
    bool operator()(const P& a, const P& b) {
        return a.first<b.first;
    }
};
P team1[8], team2[8], team3[8];
P amari[18];
int main() {
    for (int i=0; i<8; i++)
        scanf("%d%lf",&team1[i].second,&team1[i].first);
    for (int i=0; i<8; i++)
        scanf("%d%lf",&team2[i].second,&team2[i].first);
    for (int i=0; i<8; i++)
        scanf("%d%lf",&team3[i].second,&team3[i].first);
    sort(team1, team1+8, great());
    sort(team2, team2+8, great());
    sort(team3, team3+8, great());
    for (int i=2; i<8; i++) amari[i-2]=team1[i];
    for (int i=2; i<8; i++) amari[i+4]=team2[i];
    for (int i=2; i<8; i++) amari[i+10]=team3[i];
    sort(amari, amari+18, great());
    printf("%d %.2lf\n%d %.2lf\n",team1[0].second,team1[0].first,
                                  team1[1].second,team1[1].first);
    printf("%d %.2lf\n%d %.2lf\n",team2[0].second,team2[0].first,
                                  team2[1].second,team2[1].first);
    printf("%d %.2lf\n%d %.2lf\n",team3[0].second,team3[0].first,
                                  team3[1].second,team3[1].first);
    printf("%d %.2lf\n%d %.2lf\n",amari[0].second,amari[0].first,
                                  amari[1].second,amari[1].first);
}
