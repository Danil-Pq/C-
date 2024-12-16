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
#include <vector>

std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    size_t i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    std::vector<int> arr1 = {1, 3, 5};
    std::vector<int> arr2 = {2, 4, 6};
    std::vector<int> merged = mergeSortedArrays(arr1, arr2);

    for (int num : merged) {
        std::cout << num << " ";
    }

    return 0;
}

Вывод: 1 2 3 4 5 6  



Задание 3


#include <iostream>
#include <vector>

int maxSubArraySum(const std::vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        if (current_sum + nums[i] > nums[i]) {
            current_sum += nums[i];
        } else {
            current_sum = nums[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSubArraySum(nums);
    std::cout << max_sum ;

    return 0;
}


Вывод: 6

  

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
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    rearrangeEvenOdd(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}
 
Вывод: 2 4 6 1 3 5  


