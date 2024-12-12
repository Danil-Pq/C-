Задание №1
  
  #include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size] = {1, 2, 3, 2, 4, 1, 5, 3, 6, 4};
    int unique[size];
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i) {
        bool found = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[i] == unique[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique[uniqueCount++] = arr[i];
        }
    }

    cout << "Массив уникальных элементов: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << unique[i] << " ";
    }
    cout <<  '\n';

    return 0;
}

Вывод:
Массив уникальных элементов: 1 2 3 4 5 6 


  
Задание №2

#include <iostream>
using namespace std;

int main() {
    const int size1 = 5;
    const int size2 = 5;
    int arr1[size1] = {1, 3, 5, 7, 9};
    int arr2[size2] = {2, 4, 6, 8, 10};
    int merged[size1 + size2];
    
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    cout << "Объединенный отсортированный массив: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << merged[i] << " ";
    }
    cout << '\n';

    return 0;
}

Вывод:
Объединенный отсортированный массив: 1 2 3 4 5 6 7 8 9 10 



  
Задание №3

#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size] = {-2, 1, -3, 4, -1, 2, 1, -5, 4, -3};
    
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < size; ++i) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << "Максимальная сумма непрерывного подмассива: " << maxSum << '\n';

    return 0;
}


Вывод:
Максимальная сумма непрерывного подмассива: 6



 
Задание №4

#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size] = {3, 1, 4, 2, 5, 7, 6, 8, 9, 0};
    
    int left = 0;
    int right = size - 1;

    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) left++;
        while (arr[right] % 2 != 0 && left < right) right--;

        if (left < right) {
            // Обмен значениями
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    cout << "Массив с четными числами перед нечетными: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

Вывод:
Массив с четными числами перед нечетными: 0 8 4 2 6 7 5 1 9 3 
