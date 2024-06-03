#include <iostream>
#include <vector>
#include <algorithm> //для использования сортировки
#include <locale.h> //подключение библиотеки для задач связанных из локализацией
using namespace std;   

// Функция для вычисления размера предмета как произведение длины и ширины (так как предметы прямоугольные)
int calculateItemSize(int length, int width) {
    return length * width;
}


// Рекурсивная функция для проверки возможности равномерного распределения предметов по обеим веревкам так, чтобы веревка снова стала занятой полностью
bool canBalance(int ropeLength, const vector<pair<int, int>>& items, int index = 0, int leftSum = 0, int rightSum = 0) {

    // pair для хранения размеров предметов в виде длины и ширины
    // вектор items содержит пары <length, width> для каждого предмета
    
    // Базовый случай: если веревка полностью занята (после каждого перемещения предмета)
    if (leftSum == rightSum && leftSum + rightSum == 2 * ropeLength) {
        return true;    // если все условия выполняются (предметы могут быть равномерно распределены по обеим веревкам веревки)
    }


    // Базовый случай: если веревка не занята и предметы закончились
    if (index == items.size()) {    // если индекс текущего предмета равен размеру вектора предметов - все предметы были рассмотрены, но веревка не занята
        return false;   // функция возвращает false
    }


    // Попытка перевесить предмет на левой веревке
    if (canBalance(ropeLength, items, index + 1, leftSum + calculateItemSize(items[index].first, items[index].second), rightSum)) {

        // ropeLength - длина веревки
        // items - вектор размеров предметов
        // index + 1 - следующий индекс предмета в векторе, переходим к следующему предмету
        // leftSum + calculateItemSize(items[index].first, items[index].second) - сумма размеров предметов на левой части веревки после добавления текущего предмета
        // аргументы items[index].first и items[index].second - 
            // для текущего предмета (предмета с индексом index в векторе items)
            // длина и ширина извлекаются из пары <length, width> и передаются в функцию calculateItemSize.
        // rightSum - сумма размеров предметов на правой части веревки без изменений

        return true;    // веревка может быть перевешена и предметы могут быть равномерно распределены по обеим веревкам
    }

    // Попытка перевесить предмет на правой веревке
    if (canBalance(ropeLength, items, index + 1, leftSum, rightSum + calculateItemSize(items[index].first, items[index].second))) {

        // ropeLength - длина веревки
        // items - вектор размеров предметов
        // index + 1 - следующий индекс предмета в векторе, переходим к следующему предмету
        // leftSum - сумма размеров предметов на левой части веревки без изменений
        //  rightSum +  calculateItemSize(items[index].first, items[index].second) - сумма размеров предметов на правой части веревки после добавления текущего предмета
        // аргументы items[index].first и items[index].second - 
            // для текущего предмета (предмета с индексом index в векторе items)
            // длина и ширина извлекаются из пары <length, width> и передаются в функцию calculateItemSize.

        return true;    // веревка может быть перевешена и предметы могут быть равномерно распределены по обеим веревкам
    }


    // Если предмет нельзя перевесить ни на одной веревке и равномерное распределение не удается
    return canBalance(ropeLength, items, index + 1, leftSum, rightSum); // пытается перевесить предмет на одной из частей веревки, не влияя на сумму размеров предметов

    // ropeLength - длина веревки
    // items - вектор размеров предметов
    // index + 1 - следующий индекс предмета в векторе, переходим к следующему предмету
    // leftSum - сумма размеров предметов на левой части веревки без изменений
    // rightSum - сумма размеров предметов на правой части веревки без изменений
}



int main() {
    setlocale(LC_ALL, "rus");  
//{ {6, 2}, {2, 2}, {2, 5} }

    int ropeLength = 15;
    vector<pair<int, int>> items = { {6, 2}, {2, 2}, {2, 5} }; // предметы заданы как длина и ширина и их количество(количество элементов в векторе)

    // Сортируем предметы по убыванию размера, чтобы начать с самых больших
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return calculateItemSize(a.first, a.second) > calculateItemSize(b.first, b.second);
        });

    // items.begin() и items.end() указывают на диапазон, который должен быть отсортирован - от начала вектора до конца
    // [](const pair<int, int>& a, const pair<int, int>& b) - лямбда-функция, которая определяет критерий сортировки (a и b, которые являются элементами вектора items)
    // return calculateItemSize(a.first, a.second) > calculateItemSize(b.first, b.second) - тело лямбда-функции, которая сравнивает размеры двух предметов a и b
    // sort - сортирует элементы вектора items в соответствии с данным критерием, что означает, что самые большие предметы будут расположены в начале вектора

    // Добавляем украденный предмет
    pair<int, int> stolenItem = { 3, 2 }; // предмет украденный
    items.push_back(stolenItem);

    // Удаляем украденный предмет из вектора предметов
    items.erase(remove(items.begin(), items.end(), stolenItem), items.end());

    // Проверяем, можно ли перевесить веревку и выводим результат
    if (canBalance(ropeLength, items)) {
        cout << "Да, веревку можно уравновесить." << endl;

   

    }
    else {
        cout << "Нет, веревку нельзя уравновесить." << endl;


    }


    return 0;
}
