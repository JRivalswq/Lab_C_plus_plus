#include <iostream>
#include <conio.h>
#include <cstring>
#include <math.h>
using namespace std;

class Arena {
public:
    int nad,pod;
    int n;
    int** mass;
    Arena(int a);
    ~Arena();
    void menu();
    void random();
    friend void show(Arena&);
    friend void run(Arena&);
    friend void enter(Arena&);
};

Arena::~Arena() {                        //деструктор
    for (int i = 0; i < n; i++) {
        free(mass[i]);
    }
    free(mass);
}

Arena::Arena(int a) {                       //создание массива
    this->n = a;
     mass = new int*[n];
    for (int i = 0; i < n; i++) {
        mass[i] = new int[n];
    }
}

void Arena::random(){                       //заполнение массва рандомными числами   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mass[i][j] = rand() % 1001;
        }
    }
}

void enter(Arena& obj) {                    //ручной ввод значений массива

    for (int i = 0; i < obj.n; i++) {
        for (int j = 0; j < obj.n; j++) {
            cout << "Enter" << "--" << endl;
            cin >> obj.mass[i][j];
        }
    }
}

void run(Arena& ru) {                      //метод считающий своих и вражеские войска
    for (int i = 0; i < ru.n; ++i) {
        for (int j = 0; j < ru.n; ++j) {
            if (i < j) {
                ru.nad += ru.mass[i][j];
            }
        }
    }
    cout << "\n\n Own troops:" << ru.nad << endl;

    for (int i = 0; i < ru.n; ++i){
        for (int j = 0; j < ru.n; ++j){
            if (i > j){ 
                ru.pod += ru.mass[i][j];
                
            }
        }
    }
    cout << "\n Enemy troops:" << ru.pod << endl;
}

void show(Arena& obj){                      //вывод
    cout << "\nBattleground:" << endl;
    for (int i = 0; i < obj.n; i++) {
        cout << endl;
        for (int j = 0; j < obj.n; j++) {
            cout << " " << obj.mass[i][j];
        }
    }
}

void menu(Arena& R) {                               //menu
    while (1) {
        cout << "\n1-Random entry\n2-Manual entry\n3-Exit" << endl;
        switch (_getch()) {
        default:
            cout << "You left the program" << endl;
            return;
            break;

        case '1':
            system("cls");
            R.random();
            cout << "Fillef by random" << endl;
            show(R);
            run(R);
            break;


        case '2':
            system("cls");
            enter(R);
            show(R);
            run(R);
            break;
            
        }
    }
    return;
}



int main()
{
    setlocale(LC_ALL, "ru");
    int h;
    cout << "Enter the scale" << endl;
    cin >> h;
    Arena field(h);
    menu(field);
    system("pause");
    return 0;
}

