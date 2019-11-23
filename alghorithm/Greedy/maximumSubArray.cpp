#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;

pair< pair<ll, ll>, ll> findMaxCrossSub(ll low, ll high, ll *arr)
{
    ll leftSum, rightSum, sum, mid, maxLeft, maxRight;
    
    leftSum = rightSum = INT_MIN;
    mid = low + high >> 1;
    sum = 0;
    for(int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }    
    }
    sum = 0;
    for(int i = mid + 1; i < high; i++)
    {
        sum += arr[i];
        if(sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }    
    }    
    return ( make_pair( make_pair(maxLeft, maxRight), leftSum + rightSum) );

}    
pair< pair<ll, ll>,ll> findMaximumSub(ll low, ll high, ll *arr)
{
    if(high - low == 1)
        return make_pair( make_pair(low, high), arr[low]);
    else
    {
        int mid = low + high >> 1;
        pair< pair<ll, ll>, ll> left, right ,cross;
        left = findMaximumSub(low, mid, arr);
        right = findMaximumSub(mid, high,arr);
        cross = findMaxCrossSub(low, high,arr);
        if(left.second > right.second && left.second > cross.second)
            return left;
        else if(right.second > cross.second)
            return right;
        else
            return cross;
    }    

}    
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    pair< pair<ll,ll>, ll > ans = findMaximumSub(0,n,arr);
    cout<<"Maximum Sum "<<ans.second;
    return 0;

}    

