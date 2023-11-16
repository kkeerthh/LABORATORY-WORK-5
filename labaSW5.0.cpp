#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        throw "Incorrect input";
    }
}

void checkValidParams(int n) {
    if (n < 4) {
        throw "Input correct data";
    }
}

double calculate(double x, double b, double h, int n) {
    for (x; x <= b; x += h) {
        double y = 0;
        if (x < 0) {
            y = 0;
            for (int i = 1; i <= n - 1; i++) {
                double sum = 0;
                for (int j = 1; j <= n; j++) {
                    sum = sum + (x - i * i + j);
                }
                y += sum;
            }
        }
        else {
            double sum = 0;
            y = 0;
            for (int i = 0; i <= n - 1; i++) {
                sum = sum + (x - 1) / (i + 1);
            }
            y += sum;
        }
        return y;
    }
}

int main() {
    double x;
    double b;
    double h;
    int n;
    string filename;

    try {
        cout << "Input n>=4, n= " << endl;
        cin >> n;
        checkValidInput();
        checkValidParams(n);

        cout << "Input x= " << endl;
        cin >> x;
        checkValidInput();

        cout << "Input b= " << endl;
        cin >> b;
        checkValidInput();

        cout << "Input h= " << endl;
        cin >> h;
        checkValidInput();

        cout << "Enter filename to save results or type 'No' to skip: " << endl;
        cin >> filename;

        if (filename != "No") {
            ofstream fout(filename);

            fout << " x: " << x << endl;
            fout << " b: " << b << endl;
            fout << " h: " << h << endl;
            fout << " n: " << n << endl;

            cout << "x\tcalculate" << endl;
            for (x; x <= b; x += h) {
                double y = calculate(x, b, h, n);
                cout << x << "\t" << y << endl;
                fout << x << "\t" << y << endl;
            }

            fout.close();
            cout << "Results saved to file: " << filename << endl;
        }
        else {
            cout << "x\tcalculate" << endl;
            for (x; x <= b; x += h) {
                double y = calculate(x, b, h, n);
                cout << x << "\t" << y << endl;
            }
        }
    }
    catch (const char* ex) {
        cout << ex << endl;
        return -1;
    }
    catch (...) {
        cout << "Unknown error" << endl;
        return -2;
    }
    return 0;
}
