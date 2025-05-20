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
    ll n, x;
    cin >> n >> x;
    int ones = __builtin_popcountll(x);
    if (x == 0)
    {
        if (n % 2 == 0)
            cout << n << endl;
        else
        {
            if (n == 1)
                cout << -1 << endl;
            else
                cout << n - 1 + 4 << endl;
        }
        return;
    }
    if (x == 1)
    {
        if (n % 2 == 0)
            cout << n - 2 + 5 << endl;
        else
            cout << n << endl;
        return;
    }
    if (ones >= n)
        cout << x << endl;
    else
    {
        ll to_add;
        if (x % 2 == 0)
        {
            if ((n - ones) % 2 == 0)
            {
                to_add = (n - ones);
            }
            else
            {
                to_add = (n - ones) + 1;
            }
        }
        else
        {
            if ((n - ones) % 2 == 0)
            {
                to_add = (n - ones);
            }
            else
            {
                to_add = (n - ones) + 1;
            }
        }
        cout << x + to_add << endl;
    }
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