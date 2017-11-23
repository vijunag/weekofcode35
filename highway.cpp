/*Author: Vijay Nag
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef unsigned long long ll;

#define MOD 1000000009
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) {
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2;
   }
    return result;
}

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

ll solve(ll n, ll k)
{
  ll sum = 0;

  for(ll i=1;i<n-1;++i) {
    ll s = fast_exp((n-i), k);
    sum=(sum+s)%MOD;
  }
  return sum;
}

int main(int argc, char **argv)
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  cin >> T;
  while(T--) {
    ll n,k;
    cin >> n >> k;
    cout << solve(n,k);
  }
  return 0;
}

