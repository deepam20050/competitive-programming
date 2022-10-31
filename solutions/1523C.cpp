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
  int n; cin >> n;
  vector < int > stack;
  FOR(i, 0, n) {
    int x; cin >> x;
    if (x == 1) {
      stack.eb(x);
    } else {
      while (!stack.empty() && stack.back() != x - 1) stack.pop_back();
      stack.pop_back();
      stack.eb(x);
    }
    FOR(i, 0, sz(stack)) {
      if (i > 0) cout << ".";
      cout << stack[i];
    }
    cout << '\n';
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _tc; cin >> _tc;
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}