#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<int>pos;
int n;
bool check(int i,int size,int num)
{
	if(num>=n)
	 return true;
	if(i==size-1){
		return check(pos[num+1],size-1,num+1);
	}
	else{
		int flag=1;
		for(int j=i; j<size-1; j++){
			if(arr[j+1]-arr[j]!=1){
				flag=0;
				break;
			}
		}
		if(flag==0)
		 return false;
		return check(pos[arr[size-1]+1],size-1,arr[size-1]+1);
		
	}
	
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		arr.resize(n);
		pos.resize(n+2);
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
			pos[arr[i]]=i;
		}
		pos[n+1]=-1;
		bool ans=check(pos[1],n,1);
		if(ans)
		 cout<<"Yes\n";
		else
		 cout<<"No\n";
		arr.clear();
		pos.clear();
	}
	return 0;
}
