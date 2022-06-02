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

void solveTestCase () {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int pos_first = s.find_first_of('1');
  int pos_last = s.find_last_of('1');
  int ones = count(all(s), '1');
  int add = 0;
  if (ones > 0 && n - 1 - pos_last <= k) {
    k -= n - 1 - pos_last;
    --ones;
    ++add;
  }
  if (ones > 0 && pos_first <= k) {
    k -= pos_first;
    --ones;
    add += 10;
  }
  cout << 11 * ones + add << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _tc; cin >> _tc;
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}