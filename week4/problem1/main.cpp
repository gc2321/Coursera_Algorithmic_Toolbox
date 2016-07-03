#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int begin, int end, int x) {
  //int left = 0, right = (int)a.size();
  int first = begin;
  int last = end;

  if (first > last){
    return -1;
  }

  int mid = first + ((last - first)/2);

  if (x == a[mid]) {
    return mid;
  } else if (x < a[mid]){
    return binary_search(a, first, mid-1, x);
  } else if (x > a[mid]){
    return binary_search(a, mid+1, last, x);
  }

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << linear_search(a, b[i]) << ' ';
  }

  printf("\n");

  // int left = 0, right = (int)a.size();
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, 0, (int)a.size(), b[i]) << ' ';
  }
}
