#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s[n];
        ll a[n][m];
        vector<ll> row(n, -1), col(m, -1);
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
            for (ll j = 0; j < m; j++)
            {
                a[i][j] = s[i][j] - '0';
                if(row[i]==-1 && a[i][j]==0)
                {
                    row[i] = j;
                }
                if(col[j]==-1 && a[i][j]==0)
                {
                    col[j] = i;
                }
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(a[i][j]==1 && (row[i]!=-1&&row[i]<=j) && (col[j]!=-1&&col[j]<=i) )
                {
                    cout<<"NO"<<endl;
                    goto end;
                }
            }
        }
        cout<<"YES"<<endl;
        end:;
    }
}

