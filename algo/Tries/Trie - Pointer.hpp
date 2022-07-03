const int LN = 30;

struct Node {
  Node *bit[2];
  Node () {
    bit[0] = bit[1] = nullptr;
  }
};

Node *trie = new Node();

void insert (int x) {
  Node *curr = trie;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (curr->bit[b] == nullptr) {
      curr->bit[b] = new Node();
    }
    curr = curr->bit[b];
  }
}

int query (int x) {
  int ret = 0;
  Node *curr = trie;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (curr->bit[b ^ 1]) {
      ret |= 1 << i;
      curr = curr->bit[b ^ 1];
    } else {
      curr = curr->bit[b];
    }
  }
  return ret;
}
