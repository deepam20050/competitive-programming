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


string s;
int n;
vector < int > pz;

bool f (int K) {
  if (sz(pz) <= K+2) return true;
  FOR(i, 0, sz(pz) - K - 1) {
    int L = pz[i] + 1, R = pz[i+K+1] - 1;
    int numOnesLeft = R-L+1 - K;
    if (L > R) numOnesLeft = 0;
    int numOnes = n - sz(pz) + 2;
    int numOnesRem = numOnes - numOnesLeft;
    if (numOnesRem <= K) return true;
  }
  return false;
}

void solveTestCase () {
  cin >> s;
  n = sz(s);
  pz.clear();
  pz.eb(-1);
  FOR(i, 0, n) {
    if (s[i] == '0') {
      pz.eb(i);
    }
  }
  pz.eb(n);
  int l = 0, r = n;
  FOR(i, 0, 20) {
    int midx = l + r >> 1;
    if (f(midx)) {
      r = midx;
    } else {
      l = midx;
    }
  }
  cout << r << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _tc; cin >> _tc; 
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}