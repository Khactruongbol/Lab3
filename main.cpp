#include "Fraction.h"
int main()
{
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if (!fin) {
        cout << "khong tim thay file" << endl;
        return 1;
    }
    int n;
    fin >> n;
    Fraction* arr = new Fraction[n];
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
    fin.close();

    Fraction maxF = Fraction::maxFraction(arr, n);
    Fraction minF = Fraction::minFraction(arr, n);
    cout << minF << endl;
    cout << maxF << endl;
    delete[] arr;

    return 0;
}
