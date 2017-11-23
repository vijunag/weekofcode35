#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXCOST 1000000000

static inline int countNum(unsigned long long num)
{
    int count_4=0;
    int count_7=0;
    
    while (num) {
        int digit = num%10;
        num/=10;
        if (digit == 4) {
          count_4++;
        } else if (digit == 7) {
          count_7++;
        } else {
          return -1;
        }
    }
   
    if (count_4==count_7) {
      return count_4;
    } else {
      return -1;  
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    cin >> T;
    unsigned long long min = MAXCOST;
    std::string ms;
    while (T--) {
        unsigned long long c;
        std::string s;
        cin >> s >> c;
        int cnt=countNum(c);
        if (cnt>0&&c<min) {
            ms = s;
            min = c;
        } 
    } 
    if (min == MAXCOST) {
      cout<< -1<<std::endl;
    } else {
      cout<<ms<<std::endl;
    }
    return 0;
}

