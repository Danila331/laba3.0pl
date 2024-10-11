#include <iostream>
#include <math.h>
using namespace std;

int deferent(int a[], int n) {
    int sum1, sum2, allsum, medium;
    sum1 = 0;
    sum2 = 0;
    allsum = 0;
    for (int i = 0; i < n; i++) {
        allsum  += a[i];
    }
    medium = allsum / 2;
    for (int i = n - 1; i >= 0; i--) {
        if ((sum1 + a[i]) <= medium) {
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
    }
    return abs(sum1 - sum2);
}

int main(void) {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << deferent(a, n) << std::endl;
    return 0;
}