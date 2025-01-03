Задание №1
  
#include <iostream>
#include <vector>

std::vector<int> removeDuplicates(const std::vector<int>& nums) {
    std::vector<int> unique;

    for (int num : nums) {
        // Проверяем, есть ли элемент уже в векторе уникальных
        if (std::find(unique.begin(), unique.end(), num) == unique.end()) {
            unique.push_back(num);
        }
    }
    return unique;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> unique = removeDuplicates(nums);

    for (int num : unique) {
        std::cout << num << " ";
    }

    return 0;
}


Вывод: 1 2 3 4 5  


Задание №2

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> array_l {1, 4, 7};
    std::vector<int> array_r {2, 5, 9};

    std::vector<int> result;
    
    int p_l = 0;
    int p_r = 0;
    
    while (p_l < array_l.size() && p_r < array_r.size()) {
        if (array_l[p_l] < array_r[p_r]) {
            result.push_back(array_l[p_l]);
            p_l++;
        } else {
            result.push_back(array_r[p_r]);
            p_r++;   
        }
    }
    
    while (p_l < array_l.size()) {
        result.push_back(array_l[p_l]);
        p_l++;
    }
    
    while (p_r < array_r.size()) {
        result.push_back(array_r[p_r]);
        p_r++;
    }
    
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << ' ';
    }
}

Вывод: 1 2 4 5 7 9 


  

Задание 3


#include <iostream>
#include <string>
#include <vector>

int main () {
    std::vector<int> array{10, 100, -50, 5, 10, -10, 11, 100, 20};
    
    int max_sum = 0;
    int cur_sum = 0;
    
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < 0) {
            if (cur_sum > max_sum){
                std::swap(cur_sum, max_sum);
            }
            cur_sum = 0;
            continue;
        }
        else {
            cur_sum = cur_sum + array [i];
        }
    }
    std::cout << cur_sum << ' ';
}

Вывод: 131 
  

Задание 4


#include <iostream>
#include <vector>

void rearrangeEvenOdd(std::vector<int>& nums) {
    std::vector<int> evens;
    std::vector<int> odds;

    for (int num : nums) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }

    evens.insert(evens.end(), odds.begin(), odds.end());
    nums = evens; // Обновляем исходный вектор
}

int main() {
    std::vector<int> nums = {2, 3, 4, 5, 7, 8, 9};
    rearrangeEvenOdd(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}

Вывод:2 4 8 3 5 7 9 


