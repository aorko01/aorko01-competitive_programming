#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a pair (x, y) exists such that x^3 - y^3 = N
void findPair(long long N) {
    for (long long d = 1; d * d * d <= N; d++) {
        if (N % d != 0) continue; // d must be a divisor of N

        long long k = N / d; // Compute k = N / d
        // Now solve for y: 3y^2 + 3dy + (d^2 - k) = 0
        long long discriminant = 9 * d * d - 12 * (d * d - k);

        // Check if the discriminant is a perfect square
        if (discriminant < 0) continue; // No real solution
        long long sqrt_discriminant = sqrt(discriminant);
        if (sqrt_discriminant * sqrt_discriminant != discriminant) continue; // Not a perfect square

        // Solve for y: y = [-3d ± sqrt(discriminant)] / 6
        long long numerator = -3 * d + sqrt_discriminant;
        if (numerator % 6 != 0) continue; // y must be an integer
        long long y = numerator / 6;

        if (y <= 0) continue; // y must be a positive integer

        // Compute x = y + d
        long long x = y + d;

        // Output the pair (x, y)
        cout << x << " " << y << endl;
        return;
    }

    cout << -1 << endl;
}

int main() {
    long long N;
    cin >> N; 
    findPair(N); 
    return 0;
}