#include <bits/stdc++.h>
using namespace std;


int getMedian(const multiset<int>& data) {
  if (data.empty())
    return 0;

  const size_t n = data.size();
  int median = 0;

  auto iter = data.cbegin();
  advance(iter, n/2);

  if (n % 2 == 0) {
    const auto iter2 = iter--;
    median = int(*iter + *iter2) / 2;
  } else {
    median = *iter;
  }

  return median;
}


int main() {

  multiset<int> mset;

  int n;
  while (cin >> n) {
    mset.insert(n);
    cout << getMedian(mset) << endl;
  }
  


  return 0;
}
