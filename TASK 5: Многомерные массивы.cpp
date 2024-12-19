Задание 1

#include <iostream>
#include <vector>

void fillSpiralMatrix(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int m, n;
    std::cout << "Введите количество строк (m): ";
    std::cin >> m;
    std::cout << "Введите количество столбцов (n): ";
    std::cin >> n;

    fillSpiralMatrix(m, n);
    return 0;
}



Задание 2 

#include <iostream>
#include <vector>

int josephus(int n, int k) {
    if (n == 1)
        return 0; // Возвращаем 0 для 1 человека
    return (josephus(n - 1, k) + k) % n;
}

int findSurvivor(int n) {
    for (int k = 2; ; ++k) {
        if (josephus(n, k) == 0) { // Если выживает первый человек
            return k;
        }
    }
}

int main() {
    int n;
    std::cout << "Введите количество человек (n): ";
    std::cin >> n;

    int survivor = josephus(n, 2) + 1; // +1 для преобразования в 1-индекс
    int k = findSurvivor(n);

    std::cout << "Позиция выжившего при k=2: " << survivor << std::endl;
    std::cout << "k для первого выжившего: " << k << std::endl;

    return 0;
}
