#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m,n,k;

int a[101][100];

int solve()
{
   a[0][0] = m;

   for(int i=0;i<n;i++) {
       for (int j=0;j<n;++j) {
           if (i==0&&j==0)
               continue;
           if (i==j) {
               a[i][j] = a[i-1][j-1] + k;
           } else if (i > j) {
               a[i][j] = a[i-1][j]-1;
           } else {
               a[i][j] = a[i][j-1]-1;
           }
       }
   }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    cin >> n >> m >> k;

    solve();

    for(int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cout << a[i][j] << " ";
         }
        cout << std::endl;
    }
    return 0;
}

