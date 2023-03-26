#include <iostream>
#include <string>

using namespace std;

class Game {
public:
    int number;
    int number2;

    Game(int a, int b) {
        number = a;
        number2 = b;
    }

    void check(int a, int b) {
        try {
            if (a != b) {
                throw -1;
            }
            cout << "Правильно!" << endl;
        }

        catch (int a) {
                cout << a << "--" << b << endl;
                cout << "Неправильно!" << endl;
                cout << "Вы ввели-" << number2 << endl;
        }
    }

    void show1() {
        cout << "Число которое нужно написать-" << number << endl;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int b;
    cin >> a;
    cout << "sadas" << endl;
    cin >> b;
    Game ped(a, b);
    ped.check(a,b);
    ped.show1();
}
