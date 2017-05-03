#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
int main() 
{
  string tmp;
  while (getline(cin,tmp)) 
    {
      if (tmp=="START"||tmp=="END") continue;
      if (tmp=="ENDOFINPUT") break;
      for (int i=0; i<tmp.length(); i++) 
	{
	  if (isalpha(tmp[i]))
	    {
	      tmp[i]+='V'-'A';
	      if (tmp[i]>'Z') tmp[i]-=26;
	    }
	}
      cout<<tmp<<endl;
    }
}

