#include "hospDepartment.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * @file main.cpp
 * @brief Основной метод
 *
 * В основном методе вызывается меню.
 * Меню содержит 9 пунктов:
 * - 1.Add new patient
 * - 2.Search for a patient
 * - 3.Discharm a patient
 * - 4.Change number of doctors in department
 * - 5.Print, how many patients can we take today
 * - 6.Print patients by day
 * - 7.Print patients in hospital
 * - 8.Write to files
 * - 9.Exit
 * 
 * Пользователь вводит нужный ему номер пункта.
 * Затем этот номер попадает в оператор switch и выполняется фунция соответсвующая этому номеру.
 * @code
 * switch(action){
 * 		case 1:
 * 			...
 * 		break;
 * 		case 2:
 * 			...
 * 		break;
 * 		.....
 * 		case 9:
 * 			...
 * 		break;
 * }
 * @endcode
 * 
 * Так повторяется, пока пользователь не введет 9.
 * 
 * @param curDate Сеогдняшняя дата
 * @param flag False, когда пользователь решает выйти
 * @param surgery Хирургическое отделение
 * @param infection Инцфекционное отделение
 * @param cardio Кардиологическое отделение
 * @param action Номер нужного пункта меню
 * @param s_temp Введенная строка пользателем для дальнейшего использования
 * @param i_temp Введенное число пользателем для дальнейшего использования
 * @param temp Переменная типа Patient
 */


/**
 * Проверка на правильность введеных аргументов:
 * @code
 * if(argc != 3){
		cout << "Incorrect number of arguments" << endl;
		return -1;
	}
 * @endcode
 */


int main(int argc, char* argv[]){

	if(argc != 3){
		cout << "Incorrect number of arguments" << endl;
		return -1;
	}
	string curDate;
	cout << "Enter current date in format DD.MM.YYYY: ";
	cin >> curDate;
	hospDepartment surgery("surgery", 15, 20);
	hospDepartment infection("infection", 20, 30);
	hospDepartment cardio("cardio", 10, 20);
	surgery.readFromFile(argv[1], argv[2]);
	infection.readFromFile(argv[1], argv[2]);
	cardio.readFromFile(argv[1], argv[2]);
	bool flag = true;
	while(flag){
		cout << "Choose, what to do:" << endl;
		cout << "1.Add new patient" << endl;
		cout << "2.Search for a patient" << endl;
		cout << "3.Discharm a patient" << endl;
		cout << "4.Change number of doctors in department" << endl;
		cout << "5.Print, how many patients can we take today" << endl;
		cout << "6.Print patients by day" << endl;
		cout << "7.Print patients in hospital" << endl;
		cout << "8.Write to files" << endl;
		cout << "9.Exit" << endl;
		int action;
		cin >> action;
		int i_temp;
		string s_temp;
		Patient* temp = new Patient;
		switch(action){
			case 1:
				cout << "Name: ";
				cin >> s_temp;
				temp->setName(s_temp);
				cout << "Diagnosis: ";
				cin >> s_temp;
				temp->setDiagnosis(s_temp);
				cout << "Department: ";
			       	cin >> s_temp;
				temp->setDepartment(s_temp);
				temp->setDate(curDate);
				if(s_temp == "surgery" && surgery.getPlaceNumber() > 0){
					cout << "Needs hospitalization?(y/n): ";
					cin >> s_temp;
					if(s_temp == "y"){
						temp->setDays(M);
						surgery.add_in_hospital(temp);
					}
					surgery.add_list(temp);
				}
				else if(s_temp == "infection" && infection.getPlaceNumber() > 0){
					cout << "Needs hospitalization?(y/n): ";
					cin >> s_temp;
					if(s_temp == "y"){
						temp->setDays(M);
						infection.add_in_hospital(temp);
					}
					infection.add_list(temp);
				}
				else if(s_temp == "cardio" && cardio.getPlaceNumber() > 0){
					cout << "Needs hospitalization?(y/n): ";
					cin >> s_temp;
					if(s_temp == "y"){
						temp->setDays(M);
						cardio.add_in_hospital(temp);
					}
					cardio.add_list(temp);
				}
				else
					cout << "No more places or incorrect name of depatment" << endl;
				break;
			case 2:
				cout << "Type '-' to skip" << endl;
				cout << "Name: ";
				cin >> s_temp;
				temp->setName(s_temp);
				cout << "Diagnosis: ";
				cin >> s_temp;
				temp->setDiagnosis(s_temp);
				cout << "Date: ";
				cin >> s_temp;
				temp->setDate(s_temp);
				cout << "Department: ";
			       	cin >> s_temp;
				temp->setDepartment(s_temp);
				temp->setDate(curDate);
				if(s_temp == "surgery"){
					surgery.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
				}
				else if(s_temp == "infection"){
					infection.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
				}
				else if(s_temp == "cardio"){
					cardio.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
				}
				else if(s_temp == "-"){
					surgery.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
					infection.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
					cardio.search(temp->getName(), temp->getDiagnosis(), temp->getDate());
				}
				else
					cout << "Incorrect department" << endl;
				break;
			case 3:
				cout << "Department: ";
				cin >> s_temp;
				cout << "Select a patient to discharm" << endl;
				if(s_temp == "surgery"){
					surgery.print_in_hospital();
					cin >> i_temp;
					surgery.discharm(i_temp);
				}
				else if(s_temp == "infection"){
					infection.print_in_hospital();
					cin >> i_temp;
					infection.discharm(i_temp);
				}
				else if(s_temp == "cardio"){
					cardio.print_in_hospital();
					cin >> i_temp;
					cardio.discharm(i_temp);
				}
				break;
			case 4:	
				cout << "Department: ";
				cin >> s_temp;
				cout << "New number of doctors: ";
				cin >> i_temp;
				if(s_temp == "surgery"){
					surgery.setDoctors(i_temp);
				}
				else if(s_temp == "infection"){	
					infection.setDoctors(i_temp);
				}
				else if(s_temp == "cardio"){
					surgery.setDoctors(i_temp);
				}
				break;
			case 5:
				cout << "Today we can take " << surgery.getCanTake()+infection.getCanTake()+cardio.getCanTake()<< " patients at whole";
				cout << surgery.getCanTake() << " in surgeon department" << endl;
				cout << infection.getCanTake() << " in infection department" << endl;
				cout << cardio.getCanTake() << " in cardio department" << endl;
				break;
			case 6:
				cout << "Date(DD.MM.YYYY): ";
				cin >> s_temp;
				surgery.search("-", "-", s_temp);	
				infection.search("-", "-", s_temp);
				cardio.search("-", "-", s_temp);
				break;
			case 7:
				surgery.print_in_hospital();
				infection.print_in_hospital();
				cardio.print_in_hospital();
				break;
			case 8:
				surgery.writeToFile(argv[1], argv[2]);
				infection.writeToFile(argv[1], argv[2]);
				cardio.writeToFile(argv[1], argv[2]);
				break;
			case 9:
				flag = false;
				break;
		}
	}
	return 0;
}
