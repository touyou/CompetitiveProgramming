#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

vector<int> parse_int(char *);
void year_to_maya(vector<int> v);
void maya_to_year(vector<int> v);

long long table[] = {0,31,59,90,120,151,181,212,243,273,304,334};

int main(){
    char buf[128];
    for(;;){
        scanf("%s",buf);
        vector<int> v = parse_int(buf);
        if(strcmp(buf,"#") == 0){
            break;
        }
        if(v.size() == 3){
            year_to_maya(v);
        }else if(v.size() == 5){
            maya_to_year(v);
        }
    }
    return 0;
}

vector<int> parse_int(char *str){
    int len;
    int bef = 0;
    vector<int> ret;
    for(int len=0;str[len] != 0;len++){
        if(str[len] == '.'){
            str[len] = '\0';
            int i;
            sscanf(str+bef,"%d",&i);
            ret.push_back(i);
            bef = len + 1;
        }
    }
    str[len] = '\0';
    int i;
    sscanf(str+bef,"%d",&i);
    ret.push_back(i);
    return ret;
}

const long long maya_begin_year = 2012;
const long long maya_begin_month = 12;
const long long maya_begin_date = 21;

void year_to_maya(vector<int> v){
    long long years = v[0] - maya_begin_year;
    long long leaps = ((years - 0) / 4 - (years - 12) / 100 + (years - 12) / 400);
    long long day_in_year = table[v[1]-1] + v[2];
    long long kin = years * 365 + leaps + day_in_year - 355;
    long long bacton = kin / (20*20*18*20) % 13;
    long long katon = kin / (20*18*20) % 20;
    long long ton = kin / (20 * 18) % 20;
    long long winal = kin / (20) % 18;
    kin %= 20;
    printf("%lld.%lld.%lld.%lld.%lld\n",bacton,katon,ton,winal,kin);
}

void maya_to_year(vector<int> v){
    long long kin = v[0] * (20*20*18*20) + v[1] * (20*18*20) + v[2] * (18*20) + v[3] * 20 + v[4];
    long long year400 = kin / (400 * 365 + 97);
    long long year = year400 * 400;
    kin -= year400 * (400 * 365 + 97);
    long long year100 = kin / ( 100 *365 + 24);
    year += year100 * 100;
    kin -= year100 * (100 * 365 + 24);
    long long year4 = kin / ( 4 * 365 + 1);
    year += year4 * (4);
    kin -= year4 * (4 * 365 + 1);
    if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0){

    }
}

