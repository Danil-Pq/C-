Задание №1














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
