// 4 Вариант 

#include <iostream>
#include <conio.h>

using namespace std;

template <class T >
class Array
{
    T* mass;
    int size;
public:
    void info() {
        cout << " -----------------------------------------------------" << endl;
        cout << " Исходный массив: ";
        for (int i = 0; i < size; i++) {
            cout << mass[i] << " ";
        }cout << endl;
    };

    Array(int s) {

        size = s;
        mass = new T[size];
        for (int i = 0; i < size; i++) {
            cout << " Введите " << i + 1 << " элемент массива: ";
            cin >> mass[i];
            cout << endl;
        }
    };

    void run();
};

template<>
void Array<int>::run() {
    int sum = 0;
    int sred = 0;
    cout << " Обработанный массив: ";
    for (int i = 0; i < size; i++) {
        sum += mass[i];
        sred = sum / size;
    }
    cout <<sred << endl;
    cout << " -----------------------------------------------------" << endl;
}

template<>
void Array<double>::run() {
    double sum = 0;
    cout << " Сумма всех элементов: ";
    for (int i = 0; i < size; i++) {
        sum += mass[i];
    }
    cout << sum << endl;
    cout << " -----------------------------------------------------" << endl;
}
template<>
void Array<char>::run() {
    cout << " Обработанный массив: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << mass[i] << " ";
    }cout << endl;
    cout << " -----------------------------------------------------" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int z;
    cout << "" << endl;

        cout << " Введите количество элементов массива: ";
        cin >> n;
        cout << "Выберете нужний тип данных: 1-int 2-double 3-char" << endl;
        cin >> z;

        if (z == 1) {
            cout << " ---------------Массив типа int--------------------" << endl;
            Array<int> m1(n);
            m1.info();
            m1.run();
        }
        if (z == 2) {
            cout << " ---------------Массив типа double--------------------" << endl;
            Array<double> m2(n);
            m2.info();
            m2.run();
        }

        if (z == 3) {
            cout << " ---------------Массив типа char--------------------" << endl;
            Array<char> m3(n);
            m3.info();
            m3.run();
        }
        cout << " -----------------------------------------------------" << endl;


    return 0;
}
