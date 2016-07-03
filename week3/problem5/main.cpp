#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int sum = n;

  int i = 1;
  while (sum > 0){

    if ((sum-i) >= 0){
      sum -= i;
      summands.push_back(i);
    }else{
      break;
    }
    i +=1;
  }

  if (sum !=0){
    summands[summands.size()-1] += (sum);
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;

  vector<int> summands = optimal_summands(n);

  std::cout << summands.size() << '\n';

  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
