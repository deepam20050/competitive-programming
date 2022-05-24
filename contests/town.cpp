#include"bits/stdc++.h"
using namespace std;

const int N = 505;
using lli = long long;

map < lli, bool > dp[N][N];
lli arr[N];
int n;
int m;

inline bool f (int i, int j, lli s) {
  if (j < 0) {
    return 0;
  }
  if (i == n + 1) {
    return 1;
  }
  if (dp[i][j].count(s)) {
    return dp[i][j][s];
  }
  dp[i][j][s] = 0;
  if (arr[i] > s) {
    dp[i][j][s] |= f(i + 1, j, arr[i]);
  }
  // if (s > 0 && i + 2 <= n + 1) {
  //   dp[i][j][s] |= f(i + 2, j - 1, s + arr[i] + arr[i + 1]);
  // }
  // if (i + 3 <= n + 1) {
  //   lli x = arr[i] + arr[i + 1] + arr[i + 2];
  //   // if (x > s) {
  //     dp[i][j][s] |= f(i + 3, j - 1, x);
  //   // }
  // }
  for (int k = i + 2; k <= n; k += 2) {
    lli x = 0;
    for (int z = i; z <= k; ++z) {
      x += arr[z];
    }
    if (x > s) {
      dp[i][j][s] |= f(k + 1, j - (k - i >> 1), x);
    }
  }
  return dp[i][j][s];
}

int Possibility (int N, int M, vector<long long> A) {
   n = N;
   m = M;
   for (int i = 0; i <= n; ++i) {
     for (int j = 0; j <= m; ++j) {
       dp[i][j].clear();
     }
   }
   for (int i = 0; i < n; ++i) {
     arr[i + 1] = A[i];
   }
   return f(1, m, 0);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<long long> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
          cin >> A[i_A];
        }

        int out_;
        out_ = Possibility(N, M, A);
        cout << out_;
        cout << "\n";
    }
}
