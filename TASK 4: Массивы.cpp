#include <iostream>
#include <limits>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 4;
    int array[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int sum = 0, minElement = numeric_limits<int>::max(), maxElement = numeric_limits<int>::min();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
            if (array[i][j] < minElement) minElement = array[i][j];
            if (array[i][j] > maxElement) maxElement = array[i][j];
        }
    }

    double average = static_cast<double>(sum) / (rows * cols);

    cout << "Сумма: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl;

    return 0;
}

 Вывод:
Сумма: 56
Среднее арифметическое: 4.66667
Минимальный элемент: 0
Максимальный элемент: 12
