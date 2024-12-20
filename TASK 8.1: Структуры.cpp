Задание №2


#include <iostream>
#include <cmath>

struct Point {
    double x; // Координата X
    double y; // Координата Y
};

// Функция для вычисления расстояния между двумя точками
double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    Point point1 = {3.0, 4.0};
    Point point2 = {0.0, 0.0};

    std::cout << "Расстояние между точками: " << distance(point1, point2) << '\n';

    return 0;
}
