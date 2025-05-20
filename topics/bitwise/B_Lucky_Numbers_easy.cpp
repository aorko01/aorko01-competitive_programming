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
#define sza(x) ((long long)x.size())
#define all(a) (a).begin(), (a).end()

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string s;
    cin >> s;
    ll check = stoll(s);
    ll n = s.size();
    if (n % 2 == 1)
        n++;
    for (ll i = 0; i < (1LL << (n + 1)); i++)
    {
        string t = "";
        ll one_count = __builtin_popcountll(i);
        if (one_count != n / 2)
            continue;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1LL << j))
            {
                t += '7';
            }
            else
            {
                t += '4';
            }
        }
        reverse(t.begin(), t.end());
        if (stoll(t) >= check)
        {
            cout << t << "\n";
            return;
        }
    }
    n += 2;
    for (ll i = 1; i <= n; i++)
    {
        if (i <= n / 2)
            cout << '4';
        else
            cout << '7';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
