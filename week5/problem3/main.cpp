#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int s1 = str1.size();
  int s2 = str2.size();

  vector<vector<int>>D(s1+1);
  for (int i=0; i< s1+1; i++){
    D[i].resize(s2+1);
  }

  for (size_t i = 0; i <= s1; ++i) {
    for (size_t j = 0; j <= s2; ++j) {
      if (i==0 && j==0){
        D[i][j]=0;
      }else if(i==0){
        D[i][j]=j;
      }else if (j==0){
        D[i][j]=i;
      }
    }
  }

  for (int j = 1; j <= s2; j++) {
    for (int i = 1; i <= s1; i++) {

      int insertion = D[i][j-1]+1;
      int deletion = D[i-1][j]+1;
      int match = D[i-1][j-1];
      int mismatch = D[i-1][j-1]+1;

      if (str1[i-1]==str2[j-1]){
          D[i][j] = std::min({insertion, deletion, match});
       }else{
          D[i][j] = std::min({insertion, deletion, mismatch});
      }

    }
  }


  for (size_t i = 0; i <= s1; ++i) {
    for (size_t j = 0; j <= s2; ++j) {
      printf("%d-", D[i][j]);
    }
    printf("\n");
  }
  printf("\n");



  return D[s1][s2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
