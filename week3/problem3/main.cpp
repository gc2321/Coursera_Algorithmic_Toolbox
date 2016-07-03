#include <iostream>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

long long min_dot_product(vector<int> a, vector<int> b) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    long long result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}



int main() {
    int number = 0;
    cin >> number;

    vector<int>va(number), vb(number);

    for(int i= 0; i< va.size(); i++){
        cin >>va[i];
    }

    for(int i= 0; i< vb.size(); i++){
        cin >>vb[i];
    }


    int start1 = clock();
    long long result1 = min_dot_product(va, vb);
    int stop1 = clock();

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;

    printf("The answer is %lld, computed in %lf ms.\n", result1, took1);

    return 0;
}
