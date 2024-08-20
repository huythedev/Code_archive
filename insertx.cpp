#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,A[10000],x,j,t;
	freopen("INSERTX.INP","r",stdin);
	freopen("INSERTX.OUT","w",stdout);
	cin>>N>>x;
	//cout<<N<<" "<<x<<endl;
	for (int i = 1 ; i <= N ; i++)
    {
		cin >> A[i];
		//cout << A[i]<<" ";
	}
	for (int i=1;i<=N;i++)
	{

		if(x==A[i])
		  {
			cout<<"-1";
			return 0;
		  }
	}
	N=N+1;
	A[N]=x;
	sort(A,A+(N+1));
	for (int i = 1 ; i <= N ; i++)
	{
		cout << A[i]<<" ";
	}
}
