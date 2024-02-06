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

int main() {
    cout << "Fibonacci time analysis (recursive vs. non-recursive)\n";
    cout << "Integer\t\tFiboR(sec)\tMODFibR(sec)\tFiboNR(sec)\tFibo-value\n";

    vector<int> testValues = { 1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
    for (int n : testValues) {
        clock_t start, end;
        double timeFiboR, timeMODFibR, timeFiboNR;

        start = clock();
        FiboR(n);
        end = clock();
        timeFiboR = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        int fiboValue = MODFibR(n); 
        end = clock();
        timeMODFibR = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        FiboNR(n);
        end = clock();
        timeFiboNR = double(end - start) / CLOCKS_PER_SEC;

        cout << n << "\t\t"
            << timeFiboR << "\t\t"
            << timeMODFibR << "\t\t"
            << timeFiboNR << "\t\t"
            << fiboValue << "\n";
    }

    return 0;
}

// Recursive Fibonacci function
int FiboR(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return FiboR(n - 1) + FiboR(n - 2);
}

// Non-Recursive Fibonacci function
int FiboNR(int n) {
    const int max = 100;
    int F[max];
    F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

// Memoized Recursive Fibonacci function
int MODFibR(int n) {
    static vector<int> memo(100, -1); 
    if (n == 0 || n == 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = MODFibR(n - 1) + MODFibR(n - 2);
    return memo[n];
}
