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
        vector<ll> a(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<ll> prefix(m + 1, 0);
        for (ll i = 0; i < m; i++)
        {
            prefix[i + 1] = prefix[i] + (a[i] >= 1); 
        }

        ll total = 0;

        for (ll k = 1; k < n; k++)
        {
            ll valid_colors_first = m - (lower_bound(a.begin(), a.end(), k) - a.begin());

            ll valid_colors_second = m - (lower_bound(a.begin(), a.end(), n - k) - a.begin());

            ll same_color = m - (lower_bound(a.begin(), a.end(), max(k, n - k)) - a.begin());

            ll ways = valid_colors_first * valid_colors_second - same_color;
            total += ways;
        }

        cout << total << endl;
    }

    return 0;
}