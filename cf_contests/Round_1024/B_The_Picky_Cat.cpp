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
    ll n;
    ll upper = 0, lower = 0, upper_abs = 0, lower_abs = 0;
    cin >> n;
    vector<ll> a;
    ll x;
    cin >> x;
    ll check1 = x;
    ll check2 = -x;
    a.push_back(x);
    a.push_back(-x);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
        a.push_back(-x);
    }
    sort(a.begin(), a.end());

    // First check with original value
    auto it = lower_bound(a.begin(), a.end(), check1);
    if (it != a.end() && *it == check1)
    {
        // Find leftmost occurrence safely
        while (it != a.begin() && *(it - 1) == check1)
        {
            it--;
        }
        ll left = it - a.begin();

        // Find rightmost occurrence
        auto right_it = upper_bound(a.begin(), a.end(), check1);
        ll right = right_it - a.begin();

        ll greater = a.size() - right;
        ll less = left;

        if (n % 2 == 0)
        {
            if ((greater >= n / 2 && less >= n / 2 - 1) || (greater >= n / 2 - 1 && less >= n / 2))
            {
                cout << "YES" << endl;
                return;
            }
        }
        else
        {
            if (greater >= n / 2 && less >= n / 2)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    // Then check with negated value
    auto it2 = lower_bound(a.begin(), a.end(), check2);
    if (it2 != a.end() && *it2 == check2)
    {
        // Find leftmost occurrence safely
        while (it2 != a.begin() && *(it2 - 1) == check2)
        {
            it2--;
        }
        ll left = it2 - a.begin();

        // Find rightmost occurrence
        auto right_it2 = upper_bound(a.begin(), a.end(), check2);
        ll right = right_it2 - a.begin();

        ll greater = a.size() - right;
        ll less = left;

        if (n % 2 == 0)
        {
            if ((greater >= n / 2 && less >= n / 2 - 1) || (greater >= n / 2 - 1 && less >= n / 2))
            {
                cout << "YES" << endl;
                return;
            }
        }
        else
        {
            if (greater >= n / 2 && less >= n / 2)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
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