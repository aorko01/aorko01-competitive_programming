#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll compute_min(ll x, ll n, ll m)
{
    while (x > 0 && m > 0)
    {
        if (x % 2 == 0)
            x /= 2;
        else
        {
            if (x == 1)
                break;
            x = (x + 1) / 2;
        }
        m--;
    }
    while (x > 0 && n > 0)
    {
        x /= 2;
        n--;
    }
    return x;
}

ll compute_max(ll x, ll n, ll m)
{
    while (x > 0 && n > 0)
    {
        x /= 2;
        n--;
    }
    while (x > 0 && m > 0)
    {
        if (x % 2 == 0)
            x /= 2;
        else
        {
            if (x == 1)
                break;
            x = (x + 1) / 2;
        }
        m--;
    }
    return x;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, n, m;
        cin >> x >> n >> m;
        cout << compute_min(x, n, m) << " " << compute_max(x, n, m) << endl;
    }
    return 0;
}
