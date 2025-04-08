#include <iostream>
#include <chrono> // Include the chrono library for time measurement
using namespace std;
using namespace std::chrono; // Use the chrono namespace

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;

    // Input from user
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        // Start measuring time
        auto start = high_resolution_clock::now();

        // Calculate the factorial
        unsigned long long result = factorial(number);

        // Stop measuring time
        auto stop = high_resolution_clock::now();

        // Calculate the duration
        auto duration = duration_cast<microseconds>(stop - start);

        // Display the result and runtime
        cout << "Factorial of " << number << " is " << result << endl;
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}