#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

class Player { //обьявление класса

private: //приватные поля
    int* hp;
    int* magic_power;
    int* stamina;
    double* magic_damage;
    double* physical_damage;

public: //публичные методы
    int method();
    int silamg();
    int silaph();
    void show();
    void set();
    void total(int h, int mp, int s, int md, int pd);
    Player(int h, int mp, int s, double md, double pd);            //конструктор с параметрами
    Player();                                                      //конструктор
    ~Player();                                                     //деструктор
    };

Player::Player(int h, int mp, int s, double md, double pd) {       //конструктор с параметрами
    hp = new int(h);                                               //динамическое выделение памяти для переменных
    magic_power = new int(mp);
    stamina = new int(s);
    magic_damage = new double  (md);
    physical_damage = new double (pd);
}

Player::Player() {                                                 //конструктор
    hp = new int(250);
    magic_power = new int(100);
    stamina = new int(30);
    magic_damage = new double(130);
    physical_damage = new double(50);
}

void Player::set() {                                               //метод меняющий значения 
    *hp *= 2;
    *magic_power *= 2;
    *stamina *= 2;
    *magic_damage *= 2;
    *physical_damage *= 2;
}

void Player::total(int h, int mp, int s, int md, int pd) {
    *hp = h, *magic_power = mp, *stamina = s, *magic_damage = md, *physical_damage = pd;                             //присваивание значений
};
int Player::method() {
    return (*hp * *magic_power) / *stamina + (*hp * *stamina) / *magic_power - (*stamina * *magic_power) / *hp;      //подсчет уровня песонажа
}
int Player::silamg() {
    return (*magic_damage * *magic_power) - *stamina;             //подсчет магического урона с бонусами
}
int Player::silaph() {
    return (*physical_damage * *stamina + *hp) - *magic_power;    //подсчет физического урона с бонусами
}

//просмотр
void Player::show() {
    cout << " Rating:" << method() << endl;
    cout << " Damage with bonuses:" << endl;
    cout << "Magical:" << silamg() << endl;
    cout << "Physical:" << silaph() << endl;
    cout << " Defauls stats:" << endl;
    cout << "Hp:" << *hp << endl;
    cout << "Stamina:" << *stamina << endl;
    cout << "Magic power:" << *magic_power << endl;

}

Player::~Player() {                                  //деконструктор
    cout << "Deleted" << endl;
    delete(hp, magic_power, stamina, magic_damage, physical_damage);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    int h, mp, s, md, pd;

    cout << "\n-------default constructor-------" << endl;
    Player a;                       //Вызов обычного конструктора
    a.show();                       //Отображение конструктора
    cout << "-------------------" << endl;

    cout << "\n-------default constructor after method-------" << endl;
    a.set();                        //Применение метода к конструктору
    a.show();                       //Отображение конструктора
    cout << "-------------------" << endl;
    
    cout << "\nEnter hp" << endl; cin >> h;
    cout << "Enter magic power" << endl; cin >> mp;
    cout << "Enter stamina" << endl; cin >> s;
    cout << "Enter madical damage" << endl; cin >> md;
    cout << "Enter Physical damage" << endl; cin >> pd;

    cout<<"\n-------constructor with parametrs-------"<< endl;
    Player b(h, mp, s, md, pd);     //Вызов конструктора с параметрами
    b.show();                       //Отображение конструктора
    cout << "-------------------" << endl;

    system("pause");
    return 0;
}

