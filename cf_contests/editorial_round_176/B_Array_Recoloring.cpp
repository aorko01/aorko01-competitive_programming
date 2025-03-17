#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n);
        
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        vl b=a;
        sort(a.begin(), a.end(), greater<ll>());
        if(k==1)
        {
            if(a[0]==b[0] || a[0]==b[n-1])
            {
                cout<<a[0]+a[1]<<endl;
            }
            else
            {
                cout<<a[0]+max(b[0],b[n-1])<<endl;
            }
            continue;
        }
        ll ans = 0;
        for (ll i = 0; i <= k; i++)
            ans += a[i];
        cout << ans << endl;
    }
}