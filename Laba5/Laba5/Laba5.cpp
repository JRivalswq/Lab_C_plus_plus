#include <iostream>
#include <string>

using namespace std;

class Server_answer {
public:
	string info;
	void operator=(Server_answer& str) {
		for (int i = 0; i < str.info.length(); i++) {
			if (str.info[i]>=65 && str.info[i]<=90){
				str.info[i] = 0;
				this->info = str.info;
			}
		}
	}
	void show() {
		cout << info << endl;
	}
	void interface() {
		
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Server_answer s1, s2;
	cout << "\nВведите строку для отправки на сервер" << endl;
	getline(cin, s1.info);
	cin.clear();
	cout << "\nСтрока" << endl;
	s1.show();
	s2 = s1;
	cout << "\nСтрока без читеров" << endl;
	s2.show();
}

