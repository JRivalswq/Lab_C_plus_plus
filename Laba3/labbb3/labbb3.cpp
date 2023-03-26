#include <iostream>
#include <conio.h>
#include <cstring>
#include <math.h>
using namespace std;
class Predmet { //обьявление класса для одного предмета

public:
    int ID, weight;
    char name[256];
};

class Inventory {
    Predmet* x;     //указатель на массив класса Predmet
    int mas_lenght; //размер массива  
public:
    Inventory(int size);  //конструктор с параметрами
    ~Inventory();         //деструктор
    void show();          //метод для вывода
};

Inventory::~Inventory() {   //деструктор
    cout << "Deleted" << endl;
    free(x);
}

Inventory::Inventory(int size) { //конструктор с параметрами
    mas_lenght = size;
    x = new Predmet[size];   //создание массива класса Predmet
    cout << "Item characteristics" << endl;
    for (int i = 0; i < size; i++) { //цикл для ввода значений
        cout << "Enter ID: " << i + 1 << endl;
        cin >> x[i].ID;
        cout << "Enter Name: ";
        cin >> x[i].name;
        x[i].weight = rand() % 100 + 1;
    }
}


void Inventory::show() {  //метод вывода
    for (int i = 0; i < mas_lenght; i++) {
        if (x[i].weight < 90 && x[i].weight > 30) {
            cout << "------------" << endl;;
            cout << "Item id:" << x[i].ID << endl;
            cout << "Item name:" << x[i].name << endl;
            cout << "Weight:" << x[i].weight << endl;
            cout << "------------" << endl;;
        }
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    int h;
    cout << "Enter amount of items" << endl;
    cin >> h;
    Inventory item(h); //создание обьекта item класса Inventory с пмарамаетром
    item.show();
    system("pause");
    return 0;
}

