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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<ll> nums(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    ll curr_sum = 0, max_segment = LLONG_MIN;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            curr_sum = max(curr_sum + nums[i], (ll)nums[i]);
            max_segment = max(max_segment, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        else
        {
            curr_sum = 0;
        }
    }

    if (max_segment > k)
    {
        cout << "No\n";
        return;
    }

    ll first_zero = -1;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            first_zero = i;
            break;
        }
    }

    if (first_zero == -1)
    {
        if (max_segment == k)
        {
            cout << "Yes\n";
            for (ll i = 0; i < n; ++i)
            {
                cout << nums[i] << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << "No\n";
        }
        return;
    }

    ll j = first_zero;
    ll left_sum = 0, left_max = LLONG_MIN;
    bool has_left = false;
    for (ll i = j - 1; i >= 0; --i)
    {
        if (s[i] == '0')
            break;
        left_sum += nums[i];
        left_max = max(left_max, left_sum);
        has_left = true;
    }

    ll L = has_left ? left_max : 0;

    ll right_sum = 0, right_max = LLONG_MIN;
    bool has_right = false;
    for (ll i = j + 1; i < n; ++i)
    {
        if (s[i] == '0')
            break;
        right_sum += nums[i];
        right_max = max(right_max, right_sum);
        has_right = true;
    }

    ll R = has_right ? right_max : 0;

    ll target;
    if (L >= 0 && R >= 0)
        target = k - L - R;
    else if (L >= 0)
        target = k - L;
    else if (R >= 0)
        target = k - R;
    else
        target = k;

    cout << "Yes\n";
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            cout << (i == j ? target : -1000000000000000000LL) << " ";
        }
        else
        {
            cout << nums[i] << " ";
        }
    }
    cout << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}