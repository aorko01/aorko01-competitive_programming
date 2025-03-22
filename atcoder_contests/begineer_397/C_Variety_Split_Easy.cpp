#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vl visited(n+1,0),suml(n,0),sumr(n,0);
    ll curr=0;
    for(ll i=0;i<n;i++)
    {
        if(!visited[a[i]])
        {
            curr++;
        }
        visited[a[i]]=1;
        suml[i]=curr;
    }
    visited.assign(n+1,0);
    curr=0;
    for(ll i=n-1;i>=0;i--)
    {
        if(!visited[a[i]])
        {
            curr++;
        }
        visited[a[i]]=1;
        sumr[i]=curr;
    }
    ll ans=INT_MIN;
    for(ll i=0;i<n-1;i++)
    {
        ans=max(ans,suml[i]+sumr[i+1]);
    }
    cout<<ans<<endl;
}