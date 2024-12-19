Задание №1
#include <iostream>
#include <vector>

void addColumn(std::vector<std::vector<int>>& matrix, const std::vector<int>& newColumn, int position) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, newColumn[i]);
    }
}

int main() {
    int m, n;
    std::cout << "Введите количество строк: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> newColumn(m);
    std::cout << "Введите новый столбец:\n";
    for (int i = 0; i < m; ++i) {
        std::cin >> newColumn[i];
    }

    int position;
    std::cout << "Введите позицию для добавления нового столбца: ";
    std::cin >> position;

    addColumn(matrix, newColumn, position);

    std::cout << "Матрица после добавления столбца:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



Ввод:
Введите количество строк: 2
Введите количество столбцов: 2
Введите элементы матрицы:
1
2
3
4
Введите новый столбец:
5
6
Введите позицию для добавления нового столбца: 2
Вывод:
Матрица после добавления столбца:
1 2 5 
3 4 6 



Задание №2

#include <iostream>
#include <vector>

void removeColumn(std::vector<std::vector<int>>& matrix, int position) {
    for (auto& row : matrix) {
        row.erase(row.begin() + position);
    }
}

int main() {

    int m, n;
    std::cout << "Введите количество строк: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::cout << "Введите элементы матрицы: \n";
    for (auto& row : matrix) {
        for (auto& val : row) {
            std::cin >> val;
        }
    }

    int position;
    std::cout << "Введите позицию для удаления столбца: ";
    std::cin >> position;

    removeColumn(matrix, position);

    std::cout << "Матрица после удаления столбца: \n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


Ввод:
Введите количество строк: 2
Введите количество столбцов: 3
Введите элементы матрицы: 
1 2 3 4 5 6 
Введите позицию для удаления столбца: 2
Вывод:
Матрица после удаления столбца: 
1 2 
4 5 
