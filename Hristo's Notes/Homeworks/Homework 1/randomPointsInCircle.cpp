#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589
 
// Return a random double between 0 & 1
double uniform()
{
    return (double)rand() / RAND_MAX;
}
 
// Function to find the N random points on
// the given circle
vector<pair<double, double> > randPoint(int r, int x, int y, int n)
{
    // Result vector
    vector<pair<double, double> > res;
 
    for (int i = 0; i < n; i++) {
 
        // Get Angle in radians
        double theta = 2 * PI * uniform();
 
        // Get length from center
        double len = sqrt(uniform()) * r;
 
        // Add point to results.
        res.push_back({ x + len * cos(theta), y + len * sin(theta) });
    }
 
    // Return the N points
    return res;
}
 
// Function to display the content of
// the vector A
void printVector(vector<pair<double, double> > A)
{
 
    // Iterate over A
    for (pair<double, double> P : A) {
        // Print the N random points stored
        printf("(%.2lf, %.2lf)\n", P.first, P.second);
    }
}
 
// Програма, която генерира N на брой случайни точки в кръг.
int main()
{
    // Given dimensions
    int R = 4; // Радиус
    int X = 0, Y = 0; // Център на кръга
    int N = 15; // Брой точки
 
    // Function Call
    printVector(randPoint(R, X, Y, N));
    return 0;
}