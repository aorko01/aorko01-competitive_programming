#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll added=0;
    for(int i=0;i<s.size();i++)
    {
        if((i+1+added)%2==0)
        {
            if(s[i]=='i')
            {
                added++;
            }
        }
        else
        {
            if(s[i]=='o')
            {
                added++;
            }
        }
    }
    if((added+s.size())%2!=0)
    added++;
    cout<<added<<endl;
}