Задание №1
    

#include <iostream>

struct Rectangle {
    int x; // координата x
    int y; // координата y
    int width; // ширина
    int height; // высота
};

// Функция для перемещения прямоугольника
void moveRectangle(Rectangle &rect, int dx, int dy) {
    rect.x += dx;
    rect.y += dy;
}

// Функция для изменения размера прямоугольника
void resizeRectangle(Rectangle &rect, int newWidth, int newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

// Функция для печати информации о прямоугольнике
void printRectangle(const Rectangle &rect) {
    std::cout << "Прямоугольник: (" << rect.x << ", " << rect.y << "), ширина: "  << rect.width << ", высота: " << rect.height << '\n';
}

int main() {
    Rectangle rect = {0, 0, 10, 5};
    printRectangle(rect);

    moveRectangle(rect, 5, 3);
    printRectangle(rect);

    resizeRectangle(rect, 20, 10);
    printRectangle(rect);

    return 0;
}



Задание №2


#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

// Функция для вычисления расстояния между двумя точками
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    Point point1 = {0, 0};
    Point point2 = {3, 4};

    std::cout << "Расстояние между точками: " << distance(point1, point2) <<  '\n';

    return 0;
}



Задание №3

#include <iostream>

struct Fraction {
    int numerator; // числитель
    int denominator; // знаменатель
};

// Функция для расчета НОД
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для сокращения дроби
void reduceFraction(Fraction &frac) {
    int common_gcd = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= common_gcd;
    frac.denominator /= common_gcd;
}

// Арифметические операции
Fraction addFractions(const Fraction &frac1, const Fraction &frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    reduceFraction(result);
    return result;
}

int main() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};

    Fraction result = addFractions(frac1, frac2);
    std::cout << "Сумма: " << result.numerator << "/" << result.denominator << '\n';

    return 0;
}

