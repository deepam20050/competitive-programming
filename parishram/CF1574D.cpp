#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 12;

int n;
vector < int > v[N];

void print (const vector < int > &vv) {
  for (auto &e : vv) {
    printf("%d ", e + 1);
  }
  exit(0);
}

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    int c; scanf("%d", &c);
    v[i].resize(c);
    for (auto &e : v[i]) {
      scanf("%d", &e);
    }
  }
  int m; scanf("%d", &m);
  vector < vector < int > > bad;
  FOR(i, 0, m) {
    vector < int > tmp(n);
    for (auto &e : tmp) {
      scanf("%d", &e);
      --e;
    }
    bad.eb(tmp);
  }
  sort(all(bad));
  vector < int > ans(n);
  FOR(i, 0, n) {
    ans[i] = sz(v[i]) - 1;
  }
  if (!binary_search(all(bad), ans)) {
    print(ans);
  }
  int mx = 0;
  FOR(i, 0, m) {
    auto vec = bad[i];
    int sum = 0;
    FOR(j, 0, n) {
      sum += v[j][vec[j]];
    }
    FOR(j, 0, n) {
      if (vec[j] == 0) continue;
      --vec[j];
      if (!binary_search(all(bad), vec) &&  sum - v[j][vec[j] + 1] + v[j][vec[j]] > mx) {
        mx = sum - v[j][vec[j] + 1] + v[j][vec[j]];
        ans = vec;
      }
      ++vec[j];
    }
  }
  print(ans);
  return 0;
}
