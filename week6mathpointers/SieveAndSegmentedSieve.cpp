// CORRECT SOLUTION 
/**** Not working here due to for each loop ****/

#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<bool> sieveOFEratosthenes(int num){
    vector<bool> sieve(num + 1, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2 ; i <= sqrt(num) ; i++){
        if(sieve[i]){
            int j = i*i;
            while(j <= num){
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<bool> SegmentedSieve(int L, int R){
    vector<bool> segsieve = sieveOFEratosthenes(sqrt(R));
    vector<int> basePrimes;
    for(int i = 0 ; i < segsieve.size() ; i++){
        if(segsieve[i]) basePrimes.push_back(i);
    }
    vector<bool> finalPrimes(R - L + 1, true);
    if(L == 0 || L == 1) finalPrimes[L] = false;

    for(auto prime : basePrimes){
        int first_multiple = (L / prime) * prime;
        if(first_multiple < L) first_multiple += prime;
        int j = max(first_multiple, prime*prime);
        while(j <= R){
            finalPrimes[j - L] = false;
            j += prime;
        }
    }
    return finalPrimes;
}

int main()
{
    int num = 1;
    // vector<bool> ans = sieveOFEratosthenes(num);
    // for(int i = 0 ; i <= num ; i++){
    //     if(ans[i]) cout << i << " ";
    // }
    // cout << endl;

    int L = 110;
    int R = 130;
    vector<bool> ans = SegmentedSieve(L, R);
    for(int i = 0 ; i < ans.size() ; i++){
        if(ans[i]) cout << L + i << " ";
    }
    cout << endl;
    return 0;
}