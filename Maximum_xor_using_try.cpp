
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
struct TrieNode{
    int value;
    TrieNode *child[2];
    TrieNode(){
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

class tro{
public:
    void insert(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr  = pre_xor & (1<<i);
            if(temp->child[curr]==NULL){
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->value=pre_xor;
    }
    int query(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr = pre_xor & (1<<i);
            if(temp->child[1-curr] != NULL){
                temp = temp->child[1-curr];
            }else if(temp->child[curr] != NULL){
                temp = temp->child[curr];

            }
        }
        return pre_xor^(temp->value);
    }
    int maxSubarrayXOR(int N, int arr[]){
        TrieNode *root = new TrieNode();
        insert(root,0);
        int result = INT_MIN,pre_xor=0;
        for(int i=0;i<N;i++){
            pre_xor= pre_xor^arr[i];
            insert(root,pre_xor);
            result = max(result,query(root,pre_xor));
        }
        return result;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,i,j;

    int n;cin>>n;
            int arr[n];
            for (int i=1; i<=n; i++ )
            {
                int x;
                cin >> arr[i-1];
            }
            tro an;
            cout<<an.maxSubarrayXOR(n,arr)<<endl;




return 0;

}
