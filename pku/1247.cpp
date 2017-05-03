#include <cstdio>
#include <vector>
using namespace std;

int main() 
{
  int n;
  while (scanf("%d",&n)&&n!=0) 
    {
      vector<int> in(n);
      int sum=0;
      for (int i=0; i<n; i++) 
	{
	scanf("%d",&in[i]);
	sum+=in[i];
	}
      int i;
      for (i=1; i<=n; i++) 
	{
	  int rsum=0;
	  for (int j=0; j<i; j++) rsum+=in[j];
	  if (rsum==sum-rsum) break;
	}
      if (i==n+1) 
	{
	  printf("No equal partitioning.\n");
	}
      else 
	{
	  printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
	}    
    }
}
  
