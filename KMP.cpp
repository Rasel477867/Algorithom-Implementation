
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back
#define pf push_front
const ll mod=1e9+7;
using namespace std;
ll lps[1000005];
void Lps(string S)
{
    lps[0]=0;
    ll l=0,r,num;
    num=S.size();
    for(r=1; r<num; r++)
    {
        if(S[l]==S[r])
        {
            lps[r]=l+1;
            l++;
        }
        else
        {
            l--;
            if(l<0)
            {
                lps[r]=0;
                l=0;
            }
            else
            {
                while(l!=-1)
                {
                    l=lps[l];
                    if(S[l]==S[r])
                    {
                        lps[r]=l+1;
                        l++;
                        break;
                    }
                    else
                    {
                        l--;
                    }
                }
                if(l<0)
                {
                    lps[r]=0;
                    l=0;
                }
            }
        }
    }
    return ;
}
ll Kmp(string s,string p)
{
    ll ans=0,j=0,i=0;
    while(i<s.size())
    {
        if(p[j]==s[i])
        {
            ++i;
            j++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else
                ++i;
        }
        if(j==p.size())
        {
            ans++;
            j=0;
        }
    }

     return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,i,j;
    ll ans;
    string s,p;
    cin>>s>>p;
    Lps(p);
   ans=Kmp(s,p);
   cout<<ans<<endl;

    return 0;

}
