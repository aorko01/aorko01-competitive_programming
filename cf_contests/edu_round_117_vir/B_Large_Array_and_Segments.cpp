#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    cin >> a[0];
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> b[i];
        a[i] = a[i - 1] + b[i];
    }

    // Handle case when x < a[n-1]
    if (x < a[n - 1])
    {
        auto it = lower_bound(a.begin(), a.end(), x);
        int size = it - a.begin();
        ll sum = a[size];
        ll single_count = n;
        for (ll i = 1; i <= size; i++)
        {
            if (i > 0 && size + i < n)
            {
                ll check = sum - b[i - 1] + b[size + i];
                if (check <= x)
                {
                    single_count--;
                }
            }
        }
        cout << single_count * k << endl;
        return;
    }

    // Original case for x >= a[n-1]
    ll mod_x = x % a[n - 1];
    if (mod_x == 0 && a[n - 1] > 0)
        mod_x = a[n - 1]; // Handle when x is a multiple of a[n-1]

    auto it = lower_bound(a.begin(), a.end(), mod_x);
    int size = it - a.begin();
    ll sum = (x / a[n - 1]) * a[n - 1];
    if (mod_x > 0)
        sum += a[size];

    ll single_count = n;
    for (ll i = 1; i < n - size; i++)
    {
        if (i > 0 && size + i < n)
        {
            ll check = sum - b[i - 1] + b[size + i];
            if (check <= x)
            {
                single_count--;
            }
        }
    }
    cout << single_count * (k - (x / a[n - 1])) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}