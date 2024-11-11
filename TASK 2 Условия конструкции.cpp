//Задание 1: Определение типа треугольника по сторонам

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "Равносторонний треугольник" << endl;
        } else if (a == b || b == c || a == c) {
            cout << "Равнобедренный треугольник" << endl;
        } else {
            cout << "Разносторонний треугольник" << endl;
        }
    } else {
        cout << "Не может быть треугольником" << endl;
    }
    return 0;
}


//Задание 2: Определение типа треугольника по углам

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        int max_side = a;
        if (b > max_side) max_side = b;
        if (c > max_side) max_side = c;

        int sum_squares = a * a + b * b + c * c - max_side * max_side;

        if (max_side * max_side == sum_squares) {
            cout << "Прямоугольный треугольник" << endl;
        } else if (max_side * max_side < sum_squares) {
            cout << "Остроугольный треугольник" << endl;
        } else {
            cout << "Тупоугольный треугольник" << endl;
        }
    } else {
        cout << "Не может быть треугольником" << endl;
    }
    return 0;
}


//Задание 3: Определение типа треугольника по координатам

#include <iostream>
using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double ab = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double ac = (xc - xa) * (xc - xa) + (yc - ya) * (yc - ya);
    double bc = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);

    if ((ab + ac > bc) && (ab + bc > ac) && (ac + bc > ab)) {
        double max_side = ab;
        if (ac > max_side) max_side = ac;
        if (bc > max_side) max_side = bc;

        double sum_squares = ab + ac + bc - max_side;

        if (max_side == sum_squares) {
            cout << "Прямоугольный треугольник" << endl;
        } else if (max_side < sum_squares) {
            cout << "Остроугольный треугольник" << endl;
        } else {
            cout << "Тупоугольный треугольник" << endl;
        }
    } else {
        cout << "Не может быть треугольником" << endl;
    }
    return 0;
}


//Задание 4: Проверка сторон на возможность образования треугольника

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    for (int x = 1; x < a; ++x) {
        for (int y = 1; y < b; ++y) {
            int z = a - x - y;
            if (z > 0 && b == y + z && c == x + z) {
                cout << "Могут быть сторонами треугольника" << endl;
                return 0;
            }
        }
    }
    cout << "Не могут быть сторонами треугольника" << endl;
    return 0;
}


//Задание 5: Определение типа четырехугольника

#include <iostream>
using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

    double ab = (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
    double bc = (xc - xb) * (xc - xb) + (yc - yb) * (yc - yb);
    double cd = (xd - xc) * (xd - xc) + (yd - yc) * (yd - yc);
    double da = (xa - xd) * (xa - xd) + (ya - yd) * (ya - yd);

    bool is_parallelogram = (ab == cd && bc == da);
    
    // Проверка прямоугольника
    bool is_rectangle = is_parallelogram && ((ab + bc) == (cd + da));

    // Проверка трапеции
    bool is_trapezium = (ab == cd || bc == da);

    if (is_rectangle) {
        cout << "Прямоугольник" << endl;
    } else if (is_parallelogram) {
        cout << "Параллелограмм" << endl;
    } else if (is_trapezium) {
        cout << "Трапеция" << endl;
    } else {
        cout << "Произвольный четырехугольник" << endl;
    }

    return 0;
}

//Задание 6: Проверка возможности прохождения кирпича через отверстие

#include <iostream>
using namespace std;

int main() {
    int a, b, c, r, s;
    cin >> a >> b >> c >> r >> s;

    int min_side = min(a, min(b, c));
    int mid_side = a + b + c - min_side - max(a, max(b, c));
    
    if ((min_side <= r && mid_side <= s) || (min_side <= s && mid_side <= r)) {
        cout << "Кирпич пройдет через отверстие" << endl;
    } else {
        cout << "Кирпич не пройдет через отверстие" << endl;
    }

    return 0;
}


//Задание 7: Проверка возможности шара пройти через ромбообразное отверстие

#include <iostream>
using namespace std;

int main() {
    double r, p, q;
    cin >> r >> p >> q;

    double half_p = p / 2.0;
    double half_q = q / 2.0;

    double max_radius_squared = half_p * half_p + half_q * half_q;

    if (r * r <= max_radius_squared) {
        cout << "Шар пройдет через отверстие" << endl;
    } else {
        cout << "Шар не пройдет через отверстие" << endl;
    }

    return 0;
}


//Задание 8: Проверка возможности упаковать посылку в коробку

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, R, S, T;
    cin >> A >> B >> C >> R >> S >> T;

    int box[3] = {A, B, C};
    int package[3] = {R, S, T};
    
    sort(box, box + 3);
    sort(package, package + 3);

    if (box[0] >= package[0] && box[1] >= package[1] && box[2] >= package[2]) {
        cout << "Посылка помещается в коробку" << endl;
    } else {
        cout << "Посылка не помещается в коробку" << endl;
    }

    return 0;
}


//Задание 9: Нахождение пар кратных чисел

#include <iostream>
using namespace std;

int main() {
    int k, l, m;
    cin >> k >> l >> m;

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

    return 0;
}


//Задание 10: Проверка делимости числа на 3 по сумме цифр

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    int sum_of_digits = 0;

    while (number > 0) {
        sum_of_digits += number % 10; // Получаем последнюю цифру
        number /= 10; // Убираем последнюю цифру
    }

    if (sum_of_digits % 3 == 0) {
        cout << "Число делится на 3" << endl;
    } else {
        cout << "Число не делится на 3" << endl;
    }

    return 0;
}
