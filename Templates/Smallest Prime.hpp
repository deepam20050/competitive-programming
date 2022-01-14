const int ${1:limit name} = ${2:limit};

int sp[$1];
bitset < $1 > vis_prime;

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 2; i < $1; i += 2) sp[i] = 2;
  for (int i = 3; i < $1; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * $1; j += 2) {
        if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
      }
    }
}