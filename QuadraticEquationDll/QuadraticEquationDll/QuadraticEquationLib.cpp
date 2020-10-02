#include "pch.h"
#include <cmath>
#include "QuadraticEquationLib.h"

int discriminant(int a, int b, int c) {
    return b * b - 4 * a * c;
}

double* quadraticEquation(int a, int b, int c) {
    double* arr = new double[2];
    int d = discriminant(a, b, c);
    if (d < 0) {
        arr[0] = (-b) / (2.0 * a);
        arr[1] = (sqrt(-d)) / (2.0 * a);
    }
    else {
        d == 0 ?
            (arr[0] = -b / (2 * a), arr[1] = NAN) :
            (arr[0] = (-b + sqrt(d)) / (2.0 * a),
                arr[1] = (-b - sqrt(d)) / (2.0 * a));
    }
    return arr;
}