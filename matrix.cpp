#include <bits/stdc++.h>
#include <map>

#define INF -100000
using namespace std;

std::map<std::pair<int, int>, int> dp;

int walk(vector< vector<int> > &visited, vector < vector<int> > &A, int sum, int i, int j)
{
    int n = A.size();
    int m = A[0].size();

    if (i==n-1) {
      sum += A[i][j];
      int lsum=sum,rsum=sum;
      for(int k=j-1;k>=0;k--) {
        lsum += A[i][k];
        if (lsum > sum) {
          sum = lsum;
        }
      }
      rsum=sum;
      for (int k=j+1;k<=m-1;++k) {
        rsum += A[i][k];
        if (rsum > sum) {
          sum=rsum;
        }
      }

      /*
      int a = sum+lsum;
      int b = sum+rsum;
      int c = sum+lsum+rsum;
      return a > (b > c ? b : c) ? a : (b > c ? b : c);
      */
      return sum;
    }

#if 0
    std::map<std::pair<int, int>, int>::iterator it = dp.find(std::pair<int, int> (i,j));
    if (it != dp.end()) {
      return it->second;
    }
#endif
    int d=INF,r=INF,l=INF;
    int s = visited[i][j] == 0 ? A[i][j] : 0;

    if (j+1<A[0].size()) {
      if (i==n-1) {
        if (visited[i][j+1]<2) {
          visited[i][j]+=1;
          r = walk(visited,A, sum+s, i, j+1);
          visited[i][j]+=-1;
        }
      } else {
        if (visited[i][j+1]<2) {
          visited[i][j]+=1;
          r = walk(visited,A, sum+s, i, j+1);
          visited[i][j]+=-1;
        }
      }
    }
    if (i+1 < A.size() && visited[i+1][j]<2) {
      visited[i][j]+=1;
      d = walk(visited,A, sum+s, i+1, j);
      visited[i][j]+=-1;
    }
    if (j-1 >= 0) {
      if (i==n-1) {
        if (visited[i][j-1]<2) {
          visited[i][j]+=1;
          l = walk(visited,A, sum+s, i, j-1);
          visited[i][j]+=-1;
        }
      } else {
        if (visited[i][j-1]<2) {
          visited[i][j]+=1;
          l = walk(visited,A, sum+s, i, j-1);
          visited[i][j]+=-1;
        }
      }
    }

    int res = d>((l>r)?l:r)?d:(l>r?l:r);
    //dp[std::make_pair<int, int>(i,j)]=res;
    return res;
}

int clear(vector< vector<int> > &visited, int n, int m)
{
  for (int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      visited[i][j]=0;
    }
  }
  return 0;
}

int matrixLand(vector < vector<int> > A) {
    // Complete this function
    vector< vector<int> > visited(A.size(), vector<int>(A[0].size()));
    int max = INF;

    for (int j=0;j<A[0].size();++j) {
      clear(visited, A.size(), A[0].size());
      int ret=walk(visited,A,0,0,j);
      if (ret>max)
        max = ret;
    }
    return max;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector< vector<int> > A(n,vector<int>(m));
    for(int A_i = 0;A_i < n;A_i++){
       for(int A_j = 0;A_j < m;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = matrixLand(A);
    cout << result << endl;
    return 0;
}

