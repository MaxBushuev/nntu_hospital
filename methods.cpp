#include <iostream>
#include "methods.h"
#include "patientList.h"

using namespace std;

void search(patientList list){
        int days;
	    string name;
	    string departament;
        string diagnosis;
        string date;
    	cout << "1.Search by hospital days" << endl;
		cout << "2.Search by date of hospitalization" << endl;
		cout << "3.Search by full name" << endl;
		cout << "4.Search by Department" << endl;
		cout << "5.Search by diagnosis" << endl;
		cout << ">";
		int variant = getVariant(5);
		switch(variant){
		case 1:
			cout << "Enter the number of days of hospitalization: ";
			days = getVariant();
			list.search("","","",days,"");
			break;
		case 2:
			cout << "Enter the date of hospitalization: ";
			cin >> date;
			list.search("","","",-1, date);
			break;
		case 3:
			cout << "Enter your full name: ";
			cin >> name;
			list.search(name,"","",-1,"");
			break;
		case 4:
			cout << "Enter the branch name ";
			cin >> departament;
			list.search("","",departament,-1,"");
			break;
		case 5:
			cout << "Enter a diagnosis: ";
			cin >> diagnosis;
			list.search("",diagnosis,"",-1,"");
			break;
    }
}

int getVariant(int count) {
    int variant;
    string s; // строка для считывания введённых данных
    cin >> s; // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "Неправильно введено число. Повторите попытку: "; // выводим сообщение об ошибке
        cin >> s; // считываем строку повторно
    }
    return variant;
}
int getVariant() { 
    string answer; // строка для чтения
    int n; // итоговое целое число

    cin >> answer;
    // пока не будет считано целое число
    while (sscanf(answer.c_str(), "%d", &n) != 1) {
        cout << ("Неправильно введено число. Повторите попытку: "); // выводим сообщение об ошибке
        cin >>answer; // и заново считываем строку
    }

    return n; // возвращаем корректное целое число
}
