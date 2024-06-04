#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

// Fungsi yang akan diintegrasikan
double f(double x)
{
    return 4.0 / (1 + x * x);
}

// Fungsi untuk menghitung integrasi menggunakan metode Simpson 1/3
double simpson13(double a, double b, int n)
{
    if (n % 2 != 0)
    {
        cout << "n harus genap." << endl;
        return -1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        sum += 4 * f(a + i * h);
    }

    for (int i = 2; i < n; i += 2)
    {
        sum += 2 * f(a + i * h);
    }

    return (h / 3) * sum;
}

int main()
{
    double a = 0.0;
    double b = 1.0;
    double pi = 3.14159265358979323846;

    cout << fixed << setprecision(20); // Set presisi tampilan hasil

    for (int n : {10, 100, 1000, 10000}) {
        auto start = chrono::high_resolution_clock::now();
        double result = simpson13(a, b, n);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;

        if (result != -1)
        {
            cout << "Nilai integral untuk n = " << n << " adalah: " << result;
            cout << " (waktu eksekusi: " << duration.count() << " detik)" << endl;
            cout << "Nilai galat untuk n = " << n << " adalah: " << pi - result << endl << endl;
        }
    }

    return 0;
}
