#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        vector<string> s(x);
        
        for (ll i = 0; i < x; i++)
        {
            cin >> s[i]; // Directly store strings in vector
        }

        vector<ll> row(x, 0), col(y, 0);

        for (ll i = 0; i < x; i++)
        {
            for (ll j = 0; j < y; j++)
            {
                if (s[i][j] == '1')
                {
                    row[i] ^= 1; 
                    col[j] ^= 1; 
                }
            }
        }

        ll r = 0, c = 0;
        for (ll i = 0; i < x; i++)
        {
            if (row[i] == 1)
                r++;
        }
        for (ll i = 0; i < y; i++)
        {
            if (col[i] == 1)
                c++;
        }

        cout << max(r, c) << endl; 
    }
    return 0;
}
