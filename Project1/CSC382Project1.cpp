/**
 * Project: Fibonacci Time Analysis
 * Author: Artem Guz
 * Date: 02-05-2024
 * Course: CSC382
 */
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int FiboR(int n);
int FiboNR(int n);
int MODFibR(int n);
int MODFibR_Helper(int n, vector<int>& memo);
double measureTime(int (*func)(int), int n);\

int main() {
    cout << "Fibonacci time analysis (recursive vs. non-recursive)\n";
    cout << "Integer\t\tFiboR(sec)\tMODFibR\t\tFiboNR(sec)\tFibo-value\n";

    vector<int> testValues = { 1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
    for (int n : testValues) {
        double timeFiboR = measureTime(FiboR, n);
        double timeMODFibR = measureTime(MODFibR, n);
        double timeFiboNR = measureTime(FiboNR, n);
        int fiboValue = FiboNR(n); // Using FiboNR to get the Fibonacci number (efficient for larger n)

        cout << n << "\t\t"
            << timeFiboR << "\t\t"
            << timeMODFibR << "\t\t"
            << timeFiboNR << "\t\t"
            << fiboValue << "\n";
    }
    return 0;
}

int FiboR(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return FiboR(n - 1) + FiboR(n - 2);
}

int FiboNR(int n) {
    if (n == 0) return 0;
    vector<int> F(n + 1);
    F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

int MODFibR(int n) {
    vector<int> memo(n + 1, -1);
    return MODFibR_Helper(n, memo);
}

int MODFibR_Helper(int n, vector<int>& memo) {
    if (n == 0 || n == 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    else {
        memo[n] = MODFibR_Helper(n - 1, memo) + MODFibR_Helper(n - 2, memo);
        return memo[n];
    }
}

double measureTime(int (*func)(int), int n) {
    clock_t start = clock();
    func(n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
