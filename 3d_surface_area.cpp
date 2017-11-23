#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector < vector<int> > A) {
    // Complete this function
    int sa = 0;
    for (int i=0; i<A.size(); ++i) {
        for (int j=0;j<A[i].size();++j) {
            int h = A[i][j];
            int a = 2+4*h;
            //left
            int l = j-1;
            if (l>=0) {
                int lh = A[i][l];
                if (lh > h) {
                    a -= h;
                } else {
                    a -= lh;
                }
            }
            int r = j+1;
            if (r<A[i].size()) {
                int rh = A[i][r];
                if (rh > h) {
                    a -= h;
                } else {
                    a -= rh;
                }
            }
            int u = i-1;
            if (u>=0) {
                int uh = A[u][j];
                if (uh > h) {
                    a -= h;
                } else {
                    a -= uh;
                }
            }
            int d = i-1;
            if (d<A.size()) {
                int dh = A[d][j];
                if (dh > h) {
                    a -= h;
                } else {
                    a -= dh;
                }
            }
            sa+=a;
        }
    }
    return sa;
}

int main() {
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = surfaceArea(A);
    cout << result << endl;
    return 0;
}

