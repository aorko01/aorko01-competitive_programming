#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll count = 0;
        if (n % 2 != 0)
        {
            n -= k;
            count++;
        }
        double x =0;
        if(n!=0)
        x = n * (1.0) / min(k - 1, n);
        count += ceil(x);
        cout << count << endl;
    }
}