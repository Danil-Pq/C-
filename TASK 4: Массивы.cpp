Задание №1
    
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




Задание №2

#include <iostream>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 4;
    int array[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int rowSums[rows] = {0};
    int colSums[cols] = {0};
    int totalSum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSums[i] += array[i][j];
            colSums[j] += array[i][j];
            totalSum += array[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << "| " << rowSums[i] << endl;
    }
    
    cout << "--------------------" << endl;
    
    for (int j = 0; j < cols; ++j) {
        cout << colSums[j] << " ";
    }
    
    cout << "| " << totalSum << endl;

    return 0;
}

 Вывод:
3 5 6 7 | 21
12 1 1 1 | 15
0 7 12 1 | 20
--------------------
15 13 19 9 | 56

    
Задание №3

#include <iostream>
using namespace std;

int main() {
    const int rows = 5;
    const int cols1 = 10;
    const int cols2 = 5;
    
    int array1[rows][cols1];
    int array2[rows][cols2];

    // Заполнение первого массива случайными числами от 0 до 50
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols1; ++j) {
            array1[i][j] = rand() % 51; // Здесь используется rand(), но без включения библиотеки
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }

    // Заполнение второго массива по заданному принципу
    for (int i = 0; i < rows; ++i) {
        array2[i][0] = array1[i][0] + array1[i][1];
        array2[i][1] = array1[i][2] + array1[i][3];
        array2[i][2] = array1[i][4] + array1[i][5];
        array2[i][3] = array1[i][6] + array1[i][7];
        array2[i][4] = array1[i][8] + array1[i][9];
    }

    cout << "Второй массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

 Вывод:
10 49 9 34 32 37 37 48 45 19 
5 31 20 19 29 22 45 30 40 31 
35 8 36 39 14 5 8 4 31 28 
17 15 27 0 23 33 37 10 4 31 
3 9 36 23 2 40 20 47 44 9 
Второй массив:
59 43 69 85 64 
36 39 51 75 71 
43 75 19 12 59 
32 27 56 47 35 
12 59 42 67 53 



Задание №4

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int size = 5;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    insertionSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

 Вывод:
Отсортированный массив: -96 -1 0 4607 1600677166 



Задание №6


#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        int pivotIndex = i + 1;
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}


int main() {
  std::vector<int> numbers = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    int n = numbers.size();
    quickSort(numbers, 0, n - 1);
  std::cout << "Отсортированный массив: ";
  for(int num : numbers) {
        std::cout << num << " ";
  }
    std::cout << std::endl;
    return 0;
}


 Вывод:Отсортированный массив: 1 2 3 4 5 6 7 8 9 














    
