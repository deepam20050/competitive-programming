// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int MOD = 1e9 + 7;
const int N = 5005;

char arr[N][3];
int n;
int dp[N][N];

int add (int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}

int f (int i, int j) {
  if (j < 0) return 0;
  if (i == n - 1) {
    return 1;
  }
  int &r = dp[i][j];
  if (r != -1) {
    return r;
  } 
  r = 0;
  if (arr[i][0] == 's') {
    r = add(f(i, j - 1), f(i + 1, j));
  } else {
    r = f(i + 1, j + 1);
  }
  return r;
}

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%s", arr + i);
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, 0));
  return 0;
}
