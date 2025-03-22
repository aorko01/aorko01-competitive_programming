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
        string s;
        cin >> s;
        ll i = 0, j = s.size() - 1;
        bool need = false, palindrome = true;

        if (n == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        while (i < j)
        {
            if (s[i] > s[j])
            {
                palindrome = false;
                need = true;
                break;
            }
            else if (s[i] < s[j])
            {
                palindrome = false;
                break;
            }
            i++;
            j--;
        }

        if (palindrome)
        {
            bool allSame = true;
            for (int i = 1; i < n; i++)
            {
                if (s[i] != s[i - 1])
                {
                    allSame = false;
                    break;
                }
            }

            if (allSame)
            {
                cout << "NO" << endl;
            }
            else
            {
                if (k > 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else
        {
            if (!need)
                cout << "YES" << endl;
            else if (need && k > 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
