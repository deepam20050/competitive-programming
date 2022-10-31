#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int primes[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int ask (int x) {
  cout << x << endl;
  string s; cin >> s;
  return s == "yes";
}

void print (bool ok) {
  if (ok) {
    cout << "prime" << endl;
  } else {
    cout << "composite" << endl;
  }
  exit(0);
}

void test_case() {
  vector < bool > used(4);
  for (int i = 0; i < 4; ++i) {
    used[i] = ask(primes[i]);
  }
  if (count(all(used), true) >= 2) {
    print(0);
  } else if (count(all(used), true) == 0) {
    print(1);
  }
  for (int i = 0; i < 4; ++i) {
    if (used[i] && ask(primes[i] * primes[i])) {
      print(0);
    }
  }
  for (int i = 4; i < 19; ++i) {
    if (ask(primes[i])) {
      print(0);
    }
  }
  print(1);
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}