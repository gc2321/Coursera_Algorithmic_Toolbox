#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int size) {
/* Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times
 * (and hence there is at most one such element).
 */
    // find the majority element
    int count = 1;
    int maj_index = 0;

    for (int i=0; i< a.size(); i++){
        if (a[maj_index] == a[i]){
            count ++;
        }else{
            count --;
        }
        if (count==0){
            maj_index = i;
            count = 1;
        }
    }

    // count the majority element
    count = 0;
    for (int i=0; i< a.size(); i++){
        if (a[i] == a[maj_index]){
            count ++;
        }
    }
    if (count > size/2){
        return 1;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, a.size()) != -1) << '\n';
}
