#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sza(x) ((int)(x).size())

const int MAX_N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int computeGCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = computeGCD(g, a[i]);
    }

    bool all_same = all_of(all(a), [&](int x) { return x == g; });
    if (all_same) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    bool first_grouped = false;
    for (int i = 0; i < n; i++) {
        if (!first_grouped && a[i] != g) {
            cout << 1 << " ";
            first_grouped = true;
        } else {
            cout << 2 << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
