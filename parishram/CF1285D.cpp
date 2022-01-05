// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

vector < int > arr;
int n;
int ans = 1 << 30;

void solve (const vector < int > &v, int x, int bit) {
  if (bit == -1) {;
    ans = min(ans, x);
    return;
  }
  vector < int > zero, one;
  for (auto &i : v) {
    if (i >> bit & 1) one.eb(i);
    else zero.eb(i);
  }
  if (zero.empty() || one.empty()) {
    solve(v, x, bit - 1);
    return;
  }
  solve(zero, x ^ (1 << bit), bit - 1);
  solve(one, x ^ (1 << bit), bit - 1);
} 

int main () {
  scanf("%d", &n);
  arr.resize(n);
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    arr[i] = x;
  }
  solve(arr, 0, 30);
  printf("%d\n", ans);
  return 0;
}