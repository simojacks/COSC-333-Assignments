#include <iostream>
#include <chrono> // For measuring runtime
using namespace std;
using namespace std::chrono;

// Recursive Fibonacci function
unsigned long long fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci function
unsigned long long fibonacciIterative(int n) {
    if (n <= 1) {
        return n;
    }
    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;

    // Input from user
    cout << "Enter a positive integer (n): ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 1;
    }

    // Measure runtime for recursive Fibonacci
    auto startRecursive = high_resolution_clock::now();
    unsigned long long resultRecursive = fibonacciRecursive(n);
    auto stopRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<microseconds>(stopRecursive - startRecursive);

    // Measure runtime for iterative Fibonacci
    auto startIterative = high_resolution_clock::now();
    unsigned long long resultIterative = fibonacciIterative(n);
    auto stopIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<microseconds>(stopIterative - startIterative);

    // Output results and runtime
    cout << "Fibonacci (Recursive) of " << n << " is " << resultRecursive << endl;
    cout << "Time taken (Recursive): " << durationRecursive.count() << " microseconds" << endl;

    cout << "Fibonacci (Iterative) of " << n << " is " << resultIterative << endl;
    cout << "Time taken (Iterative): " << durationIterative.count() << " microseconds" << endl;

    return 0;
}