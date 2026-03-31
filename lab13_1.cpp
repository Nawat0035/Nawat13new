#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);
void stat(const double A[], int N, double B[]) {
    int i;
    double sum = 0;
    double sum2 = 0;
    double product = 1;
    double harmosum = 0;
    double max = A[0];
    double min = A[0];

    for(i = 0; i < N; i++) {
        sum = sum + A[i];
        sum2 = sum2 + A[i] * A[i];
        product = product * A[i];
        harmosum = harmosum + 1 / A[i];
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    double mean = sum / N;

    B[0] = mean;                                  
    B[1] = sqrt (sum2 / N - mean * mean);          
    B[2] = pow(product, 1.0 / N);                 
    B[3] = N / harmosum;                             
    B[4] = max;                                    
    B[5] = min;                                  
}

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}