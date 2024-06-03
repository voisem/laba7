#include <iostream>
#include <vector> 
#include <string> 

using namespace std; 

string getKthPermutation(int n, int k, vector<int>& numbers) { // Объявление функции getKthPermutation с параметрами n, k и numbers
    if (n == 1) { 
        return to_string(numbers[0]); // Возвращаем строковое представление первого элемента вектора numbers
    }

    int fact = 1; 
    for (int i = 1; i <= n - 1; ++i) { // Цикл для вычисления факториала
        fact *= i; // Умножение fact на i
    }

    int index = (k - 1) / fact; // Вычисление индекса
    int number = numbers[index]; // Получение числа по индексу
    numbers.erase(numbers.begin() + index); // Удаление элемента из вектора

    return to_string(number) + getKthPermutation(n - 1, k - index * fact, numbers); // Рекурсивный вызов функции с новыми параметрами
}

int main() { 
    setlocale(LC_ALL, "ru"); 
    int n, k; // Объявление переменных n и k
    cout << "Введите n: "; 
    cin >> n; 
    cout << "Введите k: ";
    cin >> k; 

    vector<int> numbers(n); // Создание вектора numbers размером n
    for (int i = 0; i < n; ++i) { // Цикл для заполнения вектора числами от 1 до n
        numbers[i] = i + 1;
    }

    cout << "Выход: " << getKthPermutation(n, k, numbers) << endl; // Вывод результата работы функции getKthPermutation
    return 0; 
}
