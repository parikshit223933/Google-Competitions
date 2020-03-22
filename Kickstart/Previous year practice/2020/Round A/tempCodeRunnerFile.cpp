#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll maximum_houses(ll *arr, ll n, ll b, ll **dp)
{
    if(n==0||b<=0)
    {
        return 0;
    }
    if(dp[n][b]>0)
    {
        return dp[n][b];
    }
    ll ans;
    if(arr[0]<=b)
    {
        ll option1=1+maximum_houses(arr+1, n-1, b-arr[0], dp);
        ll option2=maximum_houses(arr+1, n-1, b, dp);
        ans= max(option1, option2);
    }
    else
    {
        ans= maximum_houses(arr+1, n-1, b, dp);
    }
    dp[n][b]=ans;
    return ans;
    
}
int main()
{
    ll t;
    cin>>t;
    for(ll test_case=1; test_case<=t; test_case++)
    {
        ll n, b;
        cin>>n>>b;
        ll *arr=new ll [n];
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll **dp=new ll *[n+1];
        for(ll i=0; i<n+1; i++)
        {
            dp[i]=new ll[b+1];
            for(int j=0; j<=b; j++)
            {
                dp[i][j]=0;
            } 
        }
        cout<<"Case "<<"#"<<test_case<<": "<<maximum_houses(arr, n, b, dp)<<endl;
    }
    return 0;
}