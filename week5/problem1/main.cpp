#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    // greedy solution
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> optimal_sequence2(int n) {
    // DP solution
    vector<int> sequence;

    if (n==0) {
        sequence.push_back(0);
        return sequence;
    }else if(n==1){
        sequence.push_back(1);
        return sequence;
    }

    // initiate optimal array
    vector<int>m(n+1,0);
    m[0] = 0;
    for (size_t i = 1; i < n+1; ++i) {
        m[i] = m[i-1]+1;

        if (i%2==0){
            if (i/2==1){
                m[i] = 1;
            }else{
                m[i] = std::min(m[i/2]+1, m[i]);
            }
        }
        if (i%3==0){
            if (i/3==1){
                m[i] = 1;
            }else{
                m[i] = std::min(m[i/3]+1, m[i]);
            }
        }
    }

    while (n >= 1){
        sequence.push_back(n);

        if (n==2 || n==3){
            sequence.push_back(1);
            break;
        }

        if (m[n]== m[n-1]+1) {
            n = n - 1;
        } else if (n % 2 == 0 && m[n]==m[n/2]+1) {
            n = n/2;
        } else if (n % 3 == 0 && m[n]==m[n/3]+1) {
            n = n/3;
        }
    }

    reverse(sequence.begin(), sequence.end());
    return sequence;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence2(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
