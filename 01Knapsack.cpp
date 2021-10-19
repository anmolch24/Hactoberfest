#include<bits/stdc++.h>
using namespace std;

int t[102][1002];

int knapsack(vector<int>wt,vector<int>val,int W,int n)
{
    if(n==0 || W==0)
        return 0;

    if(t[n][W]!=-1)
        return t[n][W];

    if(wt[n-1]>W)
        return t[n][W]=knapsack(wt,val,W,n-1);

    else if(wt[n-1]<=W)
        return t[n][W]=max((val[n-1]+knapsack(wt,val,W-wt[n-1],n-1)), knapsack(wt,val,W,n-1));

}

int main()
{
    memset(t,-1,sizeof(t));
    vector<int>wt={1,3,4,5};
    vector<int>val={1,4,5,7};
    int W=7;
    int n=wt.size();

    cout<<knapsack(wt,val,W,n);
}
