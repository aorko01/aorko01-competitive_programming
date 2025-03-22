#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> findZeroBlocks(const vector<int>& arr) {
    vector<pair<int, int>> zeroBlocks;
    int n = arr.size();
    int start = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (start == -1) {
                start = i;  
            }
        } else {
            if (start != -1) {
                zeroBlocks.push_back({start, i - 1});
                start = -1;  
            }
        }
    }
    
    if (start != -1) {
        zeroBlocks.push_back({start, n - 1});
    }

    return zeroBlocks;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        bool all_zero = true;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != 0)
                all_zero = false;
        }
        if (all_zero)
        {
            cout << 3 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            vector<pair<int, int>> zeroBlocks = findZeroBlocks(vector<int>(a, a + n));
            ll to_subtract = 0;
            if (zeroBlocks.size() == 0)
            {
                cout<<1<<endl;
                cout << 1 << " " << n << endl;
            }
            else
            {
                cout << zeroBlocks.size()+1 << endl;
                for (auto block : zeroBlocks)
                {
                    if(block.first == block.second)
                        {
                            if(block.first == 0)
                            {
                                cout<<1<<" "<<2<<endl;
                            }
                            else if(block.first == n-1)
                            {
                                cout<<n-1-to_subtract<<" "<<n-to_subtract<<endl;
                            }
                            else
                            {
                                cout<<block.first-to_subtract<<" "<<block.first+1-to_subtract<<endl;
                            }
                            to_subtract += 1;
                        }
                        else
                        {
                            cout<<block.first+1-to_subtract<<" "<<block.second+1-to_subtract<<endl;
                            to_subtract += block.second - block.first ;
                        }
                }
                cout<<1<<" "<<n-to_subtract<<endl;
            }
        }
    }
}
