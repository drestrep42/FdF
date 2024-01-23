#include <stdio.h>
#include <math.h>

int main() {
    // Assuming x, y, z, and alpha are given values
    double x, y, z, alpha;

    // Get input values for x, y, z, and alpha
    printf("Enter the values for x, y, z, and alpha:\n");
    scanf("%lf %lf %lf %lf", &x, &y, &z, &alpha);

    // Convert alpha to radians as cos() and sin() functions in C use radians
    alpha = alpha * M_PI / 180.0;

    // Calculate u and v based on the provided equations
    double u = x * cos(alpha) + y * cos(alpha + 120.0 * M_PI / 180.0) + z * cos(alpha - 120.0 * M_PI / 180.0);
    double v = x * sin(alpha) + y * sin(alpha + 120.0 * M_PI / 180.0) + z * sin(alpha - 120.0 * M_PI / 180.0);

    // Display the results
    printf("u = %.2lf\n", u);
    printf("v = %.2lf\n", v);

    return 0;
}

