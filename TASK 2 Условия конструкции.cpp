#include <iostream>

using namespace std;

// Задание 1: Треугольник
bool isTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

string triangleType(double a, double b, double c) {
    if (a == b && b == c) {
        return "Равносторонний";
    } else if (a == b  a == c  b == c) {
        return "Равнобедренный";
    } else {
        return "Разносторонний";
    }
}

// Задание 2: Тип треугольника по сторонам
string triangleTypeBySides(double a, double b, double c) {
    // Используем квадратные уравнения для проверки углов
    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    if (a2 + b2 == c2  a2 + c2 == b2  b2 + c2 == a2) {
        return "Прямоугольный";
    } else if (a2 + b2 < c2  a2 + c2 < b2  b2 + c2 < a2) {
        return "Тупоугольный";
    } else {
        return "Остроугольный";
    }
}

// Задание 3: Тип треугольника по координатам
string triangleTypeByCoordinates(double xa, double ya, double xb, double yb, double xc, double yc) {
    // Вычисление квадратов расстояний между точками
    double ab2 = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double bc2 = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    double ac2 = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);

    return triangleTypeBySides(sqrt(ab2), sqrt(bc2), sqrt(ac2));
}

// Задание 4: Проверка на треугольник по формуле
bool isTriangleByFormula(double a, double b, double c) {
    // Решение системы уравнений
    double x = (a + c - b) / 2;
    double y = (a + b - c) / 2;
    double z = (b + c - a) / 2;

    return (x > 0) && (y > 0) && (z > 0);
}

// Задание 5: Тип четырехугольника
string quadrilateralType(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) {
    // Вычисление квадратов расстояний между точками
    double ab2 = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double bc2 = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    double cd2 = (xd - xc) * (xd - xc) + (yd - yc) * (yd - yc);
    double da2 = (xa - xd) * (xa - xd) + (ya - yd) * (ya - yd);

    double ac2 = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);
    double bd2 = (xd - xb) * (xd - xb) + (yd - yb) * (yd - yb);

    // Проверка на прямоугольник
    if (abs(ab2 + bc2 - ac2) < 0.001 &&
        abs(bc2 + cd2 - bd2) < 0.001 &&
        abs(cd2 + da2 - ac2) < 0.001 &&
        abs(da2 + ab2 - bd2) < 0.001) {
        return "Прямоугольник";
    }

    // Проверка на параллелограмм
    if (abs(ab2 - cd2) < 0.001 && abs(bc2 - da2) < 0.001) {
        return "Параллелограмм";
    }

    // Проверка на трапецию
    if ((abs(ab2 - cd2) < 0.001 || abs(bc2 - da2) < 0.001) &&
        !(abs(ab2 - cd2) < 0.001 && abs(bc2 - da2) < 0.001)) {
        return "Трапеция";
    }

    return "Произвольный четырехугольник";
}

// Задание 6: Кирпич в отверстие
bool brickFitsHole(double a, double b, double c, double r, double s) {
    return (a <= r && b <= s)  (a <= s && b <= r) 
           (b <= r && c <= s)  (b <= s && c <= r) 
           (a <= r && c <= s) || (a <= s && c <= r);
}

// Задание 7: Шар в ромбообразное отверстие
// Используем неравенство треугольника для диагоналей ромба
bool ballFitsRhombusHole(double r, double p, double q) {
    return 2 * r <= p + q;
}

// Задание 8: Посылка в коробку
bool boxFitsPackage(double A, double B, double C, double R, double S, double T) {
    return (R <= A && S <= B && T <= C) ||
           (R <= A && S <= C && T <= B) ||
           (R <= B && S <= A && T <= C) ||
           (R <= B && S <= C && T <= A) ||
           (R <= C && S <= A && T <= B) ||
           (R <= C && S <= B && T <= A);
}

// Задание 9: Кратно ли числа
void findMultiples(int k, int l, int m) {
    if (k % l == 0) {
        cout << k << " кратно " << l << endl;
    }
if (k % m == 0) {
        cout << k << " кратно " << m << endl;
    }
    if (l % k == 0) {
        cout << l << " кратно " << k << endl;
    }
    if (l % m == 0) {
        cout << l << " кратно " << m << endl;
    }
    if (m % k == 0) {
        cout << m << " кратно " << k << endl;
    }
    if (m % l == 0) {
        cout << m << " кратно " << l << endl;
    }
}

// Задание 10: Делимость на 3
bool isDivisibleBy3(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum % 3 == 0;
}

int main() {
    // Задание 1
    double a1, b1, c1;
    cout << "Введите стороны треугольника: ";
    cin >> a1 >> b1 >> c1;

    if (isTriangle(a1, b1, c1)) {
        cout << "Это треугольник типа: " << triangleType(a1, b1, c1) << endl;
    } else {
        cout << "Это не треугольник" << endl;
    }

    // Задание 2
    double a2, b2, c2;
    cout << "Введите стороны треугольника: ";
    cin >> a2 >> b2 >> c2;

    cout << "Тип треугольника: " << triangleTypeBySides(a2, b2, c2) << endl;

    // Задание 3
    double xa, ya, xb, yb, xc, yc;
    cout << "Введите координаты вершин треугольника: ";
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << "Тип треугольника: " << triangleTypeByCoordinates(xa, ya, xb, yb, xc, yc) << endl;

    // Задание 4
    double a4, b4, c4;
    cout << "Введите стороны треугольника: ";
    cin >> a4 >> b4 >> c4;

    if (isTriangleByFormula(a4, b4, c4)) {
        cout << "Это треугольник" << endl;
    } else {
        cout << "Это не треугольник" << endl;
    }

    // Задание 5
    double xa5, ya5, xb5, yb5, xc5, yc5, xd5, yd5;
    cout << "Введите координаты вершин четырехугольника: ";
    cin >> xa5 >> ya5 >> xb5 >> yb5 >> xc5 >> yc5 >> xd5 >> yd5;

    cout << "Тип четырехугольника: " << quadrilateralType(xa5, ya5, xb5, yb5, xc5, yc5, xd5, yd5) << endl;

    // Задание 6
    double a6, b6, c6, r6, s6;
    cout << "Введите размеры кирпича (a, b, c) и отверстия (r, s): ";
    cin >> a6 >> b6 >> c6 >> r6 >> s6;

    if (brickFitsHole(a6, b6, c6, r6, s6)) {
        cout << "Кирпич проходит через отверстие" << endl;
    } else {
        cout << "Кирпич не проходит через отверстие" << endl;
    }

    // Задание 7
    double r7, p7, q7;
    cout << "Введите радиус шара (r) и диагонали ромба (p, q): ";
    cin >> r7 >> p7 >> q7;

    if (ballFitsRhombusHole(r7, p7, q7)) {
        cout << "Шар проходит через отверстие" << endl;
    } else {
        cout << "Шар не проходит через отверстие" << endl;
    }

    // Задание 8
    double A8, B8, C8, R8, S8, T8;
    cout << "Введите размеры коробки (A, B, C) и посылки (R, S, T): ";
    cin >> A8 >> B8 >> C8 >> R8 >> S8 >> T8;

    if (boxFitsPackage(A8, B8, C8, R8, S8, T8)) {
        cout << "Посылка помещается в коробку" << endl;
    } else {
        cout << "Посылка не помещается в коробку" << endl;
    }

    // Задание 9
    int k9, l9, m9;
    cout << "Введите три целых числа: ";
    cin >> k9 >> l9 >> m9;

    findMultiples(k9, l9, m9);

    // Задание 10
    int number10;
    cout << "Введите трехзначное число: ";
    cin >> number10;

    if (isDivisibleBy3(number10)) {
        cout << "Число делится на 3" << endl;
    } else {
        cout << "Число не делится на 3" << endl;
    }

    return 0;
}
