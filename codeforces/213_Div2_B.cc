#include <iostream>

using namespace std;

inline int len(int l, int r) {
  return r - l + 1;
}

int FindLongestSeg(int* a, int n) {
  if (n <= 2) return n;
  bool in_seg = false;
  int max = 0, l = 2;
  for (int i = 2; i < n; ++i) {
    if (!in_seg) l = i;
    if (in_seg && a[i] != a[i - 1] + a[i - 2]) in_seg = false;
    if (!in_seg && a[i] == a[i - 1] + a[i - 2]) in_seg = true;
    if (in_seg) max = (len(l, i) > max) ? len(l, i) : max;
  }
  return max + 2;
}

int main() {
  int n;
  int a[100000 + 10];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << FindLongestSeg(a, n) << endl;
  return 0;
}
