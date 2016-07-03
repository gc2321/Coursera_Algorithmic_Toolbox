#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    // pivot
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

std::pair<int,int> partition3(vector<int> &a, int l, int r) {
    // pivot

    // x is the privot
    int x = a[l];

    // p marks the end of 'equal to' segment
    int p = 1;

    // j marks the end of 'lesser than' segment
    int j = l;

    // i marks the leading end of 'unchecked' segment
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            j++;
            swap(a[i], a[j]);
        }else if (a[i]==x){
            j++;
            swap(a[i], a[j]);
            swap(a[j], a[p]);
            p++;
        }

        for (size_t k = 0; k < a.size(); ++k) {
            //std::cout << a[k] << ' ';
        }
        //printf("\n");
    }

    // 'equal to' segment start with j-p-1 and j
    std::pair<int, int>m;
    m.first = j-p+1;
    m.second = j;
    //printf("m.first is %d, m.second is %d\n",m.first, m.second );

    for (int i=0; i<=(p-1); i++){
        swap(a[i], a[j]);
        j--;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        //std::cout << a[i] << ' ';
    }
    //printf("\n");
    //printf("m.first is %d, m.second is %d\n",m.first, m.second );

    //return j;
    return m;
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    //random pivot to ensure average running time is O(n log n)
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    int m = partition2(a, l, r);

    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    //random pivot to ensure average running time is O(n log n)
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);


    std::pair<int, int>m = partition3(a, l, r);

    randomized_quick_sort(a, l, m.first - 1);
    randomized_quick_sort(a, m.second + 1, r);
}


int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    //randomized_quick_sort(a, 0, a.size() - 1);
    randomized_quick_sort3(a, 0, a.size() - 1);

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
