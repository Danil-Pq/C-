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





Задание №4


#include <iostream>
#include <vector>
#include <string>

struct Movie {
    std::string title; // название
    std::string director; // режиссер
    std::string genre; // жанр
    double rating; // рейтинг популярности
    double price; // цена диска
};

// Функция для добавления нового фильма
void addMovie(std::vector<Movie> &movies, const Movie &movie) {
    movies.push_back(movie);
}

// Функция для поиска по названию
void searchByTitle(const std::vector<Movie> &movies, const std::string &title) {
    for (const auto &movie : movies) {
        if (movie.title == title) {
            std::cout << "Найден фильм: " << movie.title << ", жанр: " << movie.genre
                      << ", режиссер: " << movie.director << ", рейтинг: " << movie.rating
                      << ", цена: " << movie.price << '\n';
        }
    }
}

// Функция для поиска по жанру
void searchByGenre(const std::vector<Movie> &movies, const std::string &genre) {
    for (const auto &movie : movies) {
        if (movie.genre == genre) {
            std::cout << "Найден фильм в жанре " << genre << ": " << movie.title << '\n';
        }
    }
}

// Функция для поиска по режиссеру
void searchByDirector(const std::vector<Movie> &movies, const std::string &director) {
    for (const auto &movie : movies) {
        if (movie.director == director) {
            std::cout << "Найден фильм режиссера " << director << ": " << movie.title << '\n';
        }
    }
}

// Функция для нахождения самого популярного фильма в жанре
Movie findMostPopularInGenre(const std::vector<Movie> &movies, const std::string &genre) {
    Movie mostPopular;
    double maxRating = -1;
    for (const auto &movie : movies) {
        if (movie.genre == genre && movie.rating > maxRating) {
            maxRating = movie.rating;
            mostPopular = movie;
        }
    }
    return mostPopular;
}

// Основная функция
int main() {
    std::vector<Movie> movies;

    addMovie(movies, {"Унесенные духами", "Хаяо Миядзаки", "Анимация", 9.5, 300});
    addMovie(movies, {"Пятая стихия", "Люк Бессон", "Экшн", 8.5, 250});
    addMovie(movies, {"Человек-паук", "Сэм Рэйми", "Экшн", 9.0, 500});
    
    

    searchByTitle(movies, "Унесенные духами");
    searchByGenre(movies, "Экшн");
    searchByDirector(movies, "Хаяо Миядзаки");
    findMostPopularInGenre(movies, "Экшн");
    
    Movie mostPopular = findMostPopularInGenre(movies, "Экшн");
    std::cout << "Самый популярный фильм в жанре Экшн: " << mostPopular.title << " с рейтингом " << mostPopular.rating << '\n';

    return 0;
}


Вывод:
Найден фильм: Унесенные духами, жанр: Анимация, режиссер: Хаяо Миядзаки, рейтинг: 9.5, цена: 300
Найден фильм в жанре Экшн: Пятая стихия
Найден фильм в жанре Экшн: Человек-паук
Найден фильм режиссера Хаяо Миядзаки: Унесенные духами
Самый популярный фильм в жанре Экшн: Человек-паук с рейтингом 9
