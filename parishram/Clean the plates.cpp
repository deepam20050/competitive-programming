#include "bits/stdc++.h"
using namespace std;

class CleanPlates {
public:
  // DO NOT read from stdin or write to stdout.
  // Input is given as the function arguments.
  // Output is taken as the function return value.
  static const int M = 505;
  static const int N = 402;
  static int dp[N][N];
  int cleanPlates(std::vector<int> plates) {
    int n = (int)plates.size();
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        vector < int > same;
        for (int k = i; k <= j; ++k) {
          if (plates[i] == plates[k]) {
            same.emplace_back(k);
          }
        }
        dp[i][j] = 1 + dp[i + 1][j];
        int curr = 0;
        for (int k = 1; k < (int)same.size(); ++k) {
          curr += dp[same[k - 1] + 1][same[k] - 1];
          dp[i][j] = max(dp[i][j], curr + (k + 1) * (k + 1) + dp[same[k] + 1][j]);
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  vector < int > plates(n);
  for (auto &e : plates) {
    cin >> e;
  }
  CleanPlates solve;
  cout << solve.cleanPlates(plates) << '\n';
  return 0;
}