Задание №1

#include <iostream>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

// Функция для редактирования книги
void editBook(Book &book) {
    std::cout << "Введите новое название книги: ";
    std::getline(std::cin, book.title);
    std::cout << "Введите нового автора: ";
    std::getline(std::cin, book.author);
    std::cout << "Введите новое издательство: ";
    std::getline(std::cin, book.publisher);
    std::cout << "Введите новый жанр: ";
    std::getline(std::cin, book.genre);
}

// Функция для печати всех книг
void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Книга " << i + 1 << ": \n";
        std::cout << " - Название: " << books[i].title << "\n";
        std::cout << " - Автор: " << books[i].author << "\n";
        std::cout << " - Издательство: " << books[i].publisher << "\n";
        std::cout << " - Жанр: " << books[i].genre << "\n";
    }
}

// Функция поиска книг по автору
void searchByAuthor(const Book books[], int size, const std::string &author) {
    std::cout << "Книги автора " << author << ":\n";
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            std::cout << " - " << books[i].title << "\n";
        }
    }
}

// Функция поиска книги по названию
void searchByTitle(const Book books[], int size, const std::string &title) {
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            std::cout << "Найдена книга:\n";
            std::cout << " - Название: " << books[i].title << "\n";
            std::cout << " - Автор: " << books[i].author << "\n";
            return;
        }
    }
    std::cout << "Книга не найдена.\n";
}

// Сравнение для сортировки по названию
bool compareByTitle(const Book &a, const Book &b) {
    return a.title < b.title;
}

// Сравнение для сортировки по автору
bool compareByAuthor(const Book &a, const Book &b) {
    return a.author < b.author;
}

// Сравнение для сортировки по издательству
bool compareByPublisher(const Book &a, const Book &b) {
    return a.publisher < b.publisher;
}

// Функция сортировки книг
void sortBooks(Book books[], int size, char criterion) {
    switch (criterion) {
        case 't':
            std::sort(books, books + size, compareByTitle);
            break;
        case 'a':
            std::sort(books, books + size, compareByAuthor);
            break;
        case 'p':
            std::sort(books, books + size, compareByPublisher);
            break;
        default:
            std::cout << "Неверный критерий сортировки.\n";
            break;
    }
}

// Главная функция
int main() {
    Book library[10] = {
        {"Война и мир", "Лев Толстой", "Эксмо", "Роман"},
        {"1984", "Джордж Оруэлл", "Аттикус", "Фантастика"},
        {"Убить пересмешника", "Харпер Ли", "АСТ", "Роман"},
        {"Гордость и предубеждение", "Джейн Остин", "Современник", "Роман"},
        {"Моби Дик", "Герман Мелвилл", "Азбука", "Приключения"},
        {"Ежевичный привкус", "Джулс Верн", "Иностранка", "Фантастика"},
    };

    int size = 6; // Измените это значение при необходимости
    char option;

    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Печать всех книг\n";
        std::cout << "2. Редактировать книгу\n";
        std::cout << "3. Поиск книг по автору\n";
        std::cout << "4. Поиск книги по названию\n";
        std::cout << "5. Сортировка по названию\n";
        std::cout << "6. Сортировка по автору\n";
        std::cout << "7. Сортировка по издательству\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> option;
        std::cin.ignore(); // Игнорируем символ новой строки после ввода

        switch (option) {
            case '1':
                printBooks(library, size);
                break;
            case '2': {
                int index;
                std::cout << "Введите номер книги для редактирования (1-" << size << "): ";
                std::cin >> index;
                std::cin.ignore();
                if (index >= 1 && index <= size) {
                    editBook(library[index - 1]);
                } else {
                    std::cout << "Неверный номер книги.\n";
                }
                break;
            }
            case '3': {
                std::string author;
                std::cout << "Введите имя автора: ";
                std::getline(std::cin, author);
                searchByAuthor(library, size, author);
                break;
            }
            case '4': {
                std::string title;
                std::cout << "Введите название книги: ";
                std::getline(std::cin, title);
                searchByTitle(library, size, title);
                break;
            }
            case '5':
                sortBooks(library, size, 't');
                std::cout << "Книги отсортированы по названию.\n";
                break;
            case '6':
                sortBooks(library, size, 'a');
                std::cout << "Книги отсортированы по автору.\n";
                break;
            case '7':
                sortBooks(library, size, 'p');
                std::cout << "Книги отсортированы по издательству.\n";
                break;
            case '0':
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверная опция. Попробуйте снова.\n";
        }
    } while (option != '0');

    return 0;
}












--- Меню ---
1. Печать всех книг
2. Редактировать книгу
3. Поиск книг по автору
4. Поиск кни�и по названию
5. Сортировка по названию
6. Сортировк� по автору
7. Сортировка по издательству
0. Выход
Вы�ерите опцию: 1
Книга 1: 
 - Название: Война и мир
 - Автор: Лев Толстой
 - Издательство: Эксмо
 - Ж�нр: Роман
Книга 2: 
 - Название: 1984
 - Автор: Джордж Оруэлл
 - Издательство: Аттикус
 - Жанр: Фантастика
Книга 3: 
 - Название: Убить пересмешника
 - Автор: Харпер Ли
 - Издательство: АСТ
 - Жанр: Роман
Книга 4: 
 - Назва�ие: Гордость и предубеждение
 - Автор: Джейн Остин
 - Издательство: Современник
 - Жанр: Роман
Книга 5: 
 - Название: Моби Дик
 - Автор: Герман Мелвилл
 - Издательство: Азбука
 - Жанр: Приключения
Книга 6: 
 - Название: Ежевичный привкус
 - Автор: Джулс Верн
 - Издательство: Иностранка
 - Жанр: Фантастика

--- Меню ---
1. Печать всех книг
2. Редактировать книгу
3. Поиск книг по автору
4. Поиск книги по названию
5. Сортировка по назв�нию
6. Сортировка по автору
7. Сортировка по издател�ству
0. Выход
Выберите опцию: 


    
Задание №2


#include <iostream>

struct WashingMachine {
    std::string brand;
    std::string color;
    double width;
    double length;
    double height;
    double power;
    int spinSpeed;
    int heatingTemperature;

    void printDetails() {
        std::cout << "Стиральная машинка:\n";
        std::cout << " - Фирма: " << brand << "\n";
        std::cout << " - Цвет: " << color << "\n";
        std::cout << " - Размеры (Ш x Д x В): " << width << " x " << length << " x " << height << "\n";
        std::cout << " - Мощность: " << power << "\n";
        std::cout << " - Скорость отжима: " << spinSpeed << "\n";
        std::cout << " - Температура нагрева: " << heatingTemperature << "\n";
    }
};

int main() {
    WashingMachine wm = {"Bosch", "Белый", 60.0, 60.0, 85.0, 2300, 1400, 90};
    wm.printDetails();
    return 0;
}



Задание №3


#include <iostream>

struct Iron {
    std::string brand;
    std::string model;
    std::string color;
    int minTemperature;
    int maxTemperature;
    bool steamFunction;
    int power;

    void printDetails() {
        std::cout << "Утюг:\n";
        std::cout << " - Фирма: " << brand << "\n";
        std::cout << " - Модель: " << model << "\n";
        std::cout << " - Цвет: " << color << "\n";
        std::cout << " - Минимальная температура: " << minTemperature << "\n";
        std::cout << " - Максимальная температура: " << maxTemperature << "\n";
        std::cout << " - Подача пара: " << (steamFunction ? "Да" : "Нет") << "\n";
        std::cout << " - Мощность: " << power << "\n";
    }
};

int main() {
    Iron iron = {"Philips", "GC4537/86", "Синий", 120, 240, true, 2400};
    iron.printDetails();
    return 0;
}


Задание №4

  
#include <iostream>

struct Boiler {
    std::string brand;
    std::string color;
    double power;
    double volume;
    int heatingTemperature;

    void printDetails() {
        std::cout << "Бойлер:\n";
        std::cout << " - Фирма: " << brand << "\n";
        std::cout << " - Цвет: " << color << "\n";
        std::cout << " - Мощность: " << power << "\n";
        std::cout << " - Объем: " << volume << "\n";
        std::cout << " - Температура нагрева: " << heatingTemperature << "\n";
    }
};

int main() {
    Boiler boiler = {"Ariston", "Белый", 3000, 100, 75};
    boiler.printDetails();
    return 0;
}



Задание №5


#include <iostream>

struct Animal {
    std::string name;
    std::string species;
    std::string nickname;

    void fillData() {
        std::cout << "Введите название животного: ";
        std::getline(std::cin, name);
        std::cout << "Введите класс животного: ";
        std::getline(std::cin, species);
        std::cout << "Введите кличку животного: ";
        std::getline(std::cin, nickname);
    }

    void printDetails() const {
        std::cout << "Животное:\n";
        std::cout << " - Название: " << name << "\n";
        std::cout << " - Класс: " << species << "\n";
        std::cout << " - Кличка: " << nickname << "\n";
    }

    void makeSound() const {
        std::cout << "Животное издает звук!\n";
    }
};

int main() {
    Animal animal;
    animal.fillData();
    animal.printDetails();
    animal.makeSound();
    return 0;
}
