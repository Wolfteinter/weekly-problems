/*
Knowing the money of all the friends,we can get all the subarray that belongs with the rules, "the difference between the maximum and minimum (in terms of money) 
should be less then the maximum given, for that we can sort the friends in ascend order, and do the search, in this case i use the two pointer technique to find 
the limits of the friends that accomplish this request, starting with left pointer in 0 and the right one to,and the maximum sum of the value of friendship 
comparing the sums of all the element in [left, right] are less then the "d" limits,if accomplish then we can increment the right pointer and check if this 
subarray is the maximum, otherwise increment the left pointer, this works because, while we can move the right the left are in the limits if not then we need 
to move the limits, this algorithm runs in O(n ln n) because it needs to sort.

*/

#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int,long long int>& a,pair<long long int,long long int>& b) { 
    return a.first < b.first; 
}

int main(){
    long long int n,max_diff;
    long long int mi,si;
    cin >> n >> max_diff;
    pair<long long int,long long int> friends[n];
    for(int i = 0;i < n;i++){
        cin >> mi >> si;
        friends[i] = make_pair(mi, si);
    }
    sort(friends, friends + n, cmp);
    int left = 0;
    int right = 0;
    long long int score = INT_MIN;
    long long int suma = 0;
    while(left <= right){
        long long int minimum = friends[left].first;
        long long int maximum = friends[right].first;
        long long int diff = maximum - minimum;
        if(diff < max_diff){
            suma += friends[right].second;
            score = max(score, suma);
            right++;
        }
        else{
            suma -= friends[left].second;
            left++;
        }
        if(right == n)break;
        if(left == n)break;
    }
    cout<<score<<endl;
    return 0;
}
