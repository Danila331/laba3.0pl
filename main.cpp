#include <iostream>
#include <math.h>
using namespace std;

int deferent(int a[], int n) {
    if (n == 1) {
        return a[0];
    }
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

void run_test(int test_case_number, int input[], int n, int expected_output) {
    int result = deferent(input, n);
    if (result == expected_output) {
        cout << "Test case " << test_case_number << " passed." << endl;
    } else {
        cout << "Test case " << test_case_number << " failed. Expected: " << expected_output << ", but got: " << result << endl;
    }
}

void run_all_tests() {
    int test1[] = {5};
    run_test(1, test1, 1, 5);

    int test2[] = {5, 5};
    run_test(2, test2, 2, 0);

    int test3[] = {3, 8};
    run_test(3, test3, 2, 5);

    int test4[] = {2, 2, 2};
    run_test(4, test4, 3, 2);

    int test5[] = {1, 2, 3};
    run_test(5, test5, 3, 0);

    int test6[] = {1, 2, 3, 4};
    run_test(6, test6, 4, 0);

    int test7[] = {100000000, 1, 1, 1};
    run_test(7, test7, 4, 99999997);

    int test8[] = {1, 3, 2, 4, 5};
    run_test(8, test8, 5, 1);

    int test9[] = {5, 5, 5, 5};
    run_test(9, test9, 4, 0);

    int test10[] = {100, 1, 1};
    run_test(10, test10, 3, 98);
}

int main(void) {
    run_all_tests();
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << deferent(a, n) << std::endl;
    return 0;
}