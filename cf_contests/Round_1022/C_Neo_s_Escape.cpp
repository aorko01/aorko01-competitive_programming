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

class RangeMaximumQuery
{
private:
    std::vector<ll> arr;
    std::vector<std::vector<int>> st;
    std::vector<int> logTable;
    int n;

public:
    RangeMaximumQuery(const std::vector<ll> &input)
    {
        arr = input;
        n = arr.size();
        int K = std::log2(n) + 1;
        st.assign(n, std::vector<int>(K));
        logTable.assign(n + 1, 0);
        buildLogTable();
        buildSparseTable();
    }

    void buildLogTable()
    {
        for (int i = 2; i <= n; ++i)
            logTable[i] = logTable[i / 2] + 1;
    }

    void buildSparseTable()
    {
        int K = logTable[n] + 1;
        for (int i = 0; i < n; ++i)
            st[i][0] = i; // store index

        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) <= n; ++i)
            {
                int leftIdx = st[i][j - 1];
                int rightIdx = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
            }
        }
    }

    // Query returns index of maximum value in range [L, R]
    int query(int L, int R)
    {
        int len = R - L + 1;
        int k = logTable[len];
        int leftIdx = st[L][k];
        int rightIdx = st[R - (1 << k) + 1][k];
        return (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    RangeMaximumQuery rmq(a);
    ll i = 0, j = n - 1;
    ll count = 0;
    while (i < j)
    {
        count++;
        ll ind = rmq.query(i, j);
        if (abs(ind - i) > abs(ind - j))
        {
            i = ind + 1;
        }
        else
        {
            j = ind - 1;
        }
    }
    cout << count << endl;
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