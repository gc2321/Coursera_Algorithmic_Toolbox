#include <iostream>
#include <vector>

using std::vector;

// knapsack without repetition

int optimal_weight(int W, const vector<int> &w) {
  //greedy solution
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}
int optimal_weight2(int total_weight, const vector<int> &w) {
  //DP solution

  vector<vector<int>>value(total_weight+1);
  for (int i=0; i< total_weight+1; i++){
    value[i].resize(w.size()+1);
  }

  // from 1 to nth item
  for (int n = 1; n <= w.size(); n++) {
    // from weight = 0 to weight = total_weight
    for (int wt = 1; wt <= total_weight; wt++) {
      // value for not taking ith item
       value[wt][n] = value[wt][n-1];

      if (w[n-1] <= wt){
            value[wt][n] = std::max(value[wt][n], w[n-1]+value[wt-w[n-1]][n-1]);
      }

    }

  }


  for (size_t i = 0; i <= total_weight; ++i) {
    for (size_t j = 0; j <= w.size(); ++j) {
      printf("%d-", value[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return value[total_weight][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight2(W, w) << '\n';
}
