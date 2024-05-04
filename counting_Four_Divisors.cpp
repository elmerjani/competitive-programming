#include <bits/stdc++.h>
using namespace std;

    vector<int> sieve(int n){
        vector<bool> is_prime(n+1,true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(is_prime[i]){
                for(int j=i*i;j<=n;j+=i)is_prime[j]=false;
            }
        }
        vector<int> primes;
        for(int i=0;i<=n;i++){
            if(is_prime[i])primes.push_back(i);
        }
        return primes;
    }
int sumFourDivisors(vector<int>& nums) {
        int maxn=0;
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
            if(x>maxn)maxn=x;
        }
        int count=0;
        vector<int> primes=sieve(maxn/2);
        int n=primes.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(primes[i]*primes[j])==mp.end())continue;
                
                count+=(mp[primes[i]*primes[j]]*(1+primes[i]+primes[j]+primes[i]*primes[j]));
            }
            
        }
        return count;
    }

    int main(  ){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        cout<<sumFourDivisors(nums)<<endl;
        return 0;
    }