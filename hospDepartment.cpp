#include "hospDepartment.hpp"
#include <fstream>
using namespace std;

/**
 * @brief Реализация работы больничного отделения
 * 
 * @param name Название отделения
 * @param doctors Количество докторов в отделении
 * @param maxPlaceNumber Максимальное количество пациентов в отделении
 * @param canTake Количество пациентов, которое может принять отделение 
 * @param placeNumber Количество занятых мест в отделении
 * @param s_temp Введенная строка пользателем для дальнейшего использования
 * @param i_temp Введенное число пользателем для дальнейшего использования
 * @param temp Переменная типа Patient 
 * @param file_in_hospital Файл для хранения списка пациентов в отделении  
 * @param file_patient Файл для хранения общего списка пациентов
 * 
 */ 


hospDepartment::hospDepartment(){
	_name = "";
	_doctors = 0;
	_maxPlaceNumber = 0;
	_canTake = 0;
	_placeNumber = 0;
}

hospDepartment::hospDepartment(string name, int doctors, int placeNumber){
	_name = name;
	_doctors = doctors;
	_placeNumber = placeNumber;
	_canTake = _doctors * N;
}

/**
 * @return Название отделения
 */

string hospDepartment::getName(){
	return _name;
}

/**
 * @return Количество докторов
 */ 

int hospDepartment::getDoctors(){
	return _doctors;
}

/**
 * @brief Метод, который меняет количество докторов в отделении
 * 
 * @code
 * void hospDepartment::setDoctors(int doctors){
		_doctors = doctors;
	}	
 * @endcode 
 */ 

void hospDepartment::setDoctors(int doctors){
	_doctors = doctors;
}

/**
 * @return Количество занятых мест в отделении
 */ 

int hospDepartment::getPlaceNumber(){
	return _placeNumber;
}

/**
 * @brief Метод, который меняет количество занятых мест в отделении
 * 
 * @code
 * void hospDepartment::setPlaceNumber(int placeNumber){
		_placeNumber = placeNumber;
	}
 * @endcode
 */ 

void hospDepartment::setPlaceNumber(int placeNumber){
	_placeNumber = placeNumber;
}

/**
 * @return Количество пациентов, которых можно принять
 */ 

int hospDepartment::getCanTake(){
	return _canTake;
}

/**
 * @brief Метод, который меняет количество пациентов, которых можно принять
 * 
 * @code
 * void hospDepartment::setCanTake(int canTake){
		_canTake = canTake;
	}
 * 
 * @endcode 
 */

void hospDepartment::setCanTake(int canTake){
	_canTake = canTake;
}

/**
 * @brief Метод, который добавляет пациента(Patient) в общий список пациентов(patientList)
 * 
 * @code
 * void hospDepartment::add_list(Patient* temp){
		_list.add(temp);
		_canTake--;
	}
 * @endcode
 * 
 */ 

void hospDepartment::add_list(Patient* temp){
	_list.add(temp);
	_canTake--;
}

/**
 * @brief Метод, который добавляет пациента(Patient) в список отделения(hospDepartment)
 * 
 * @code
 * void hospDepartment::add_in_hospital(Patient* temp){
		_in_hospital.add(temp);
		_placeNumber--;
	}
 * @endcode
 * 
 */

void hospDepartment::add_in_hospital(Patient* temp){
	_in_hospital.add(temp);
	_placeNumber--;
}

/**
 * @brief Метод для чтения данных из файла
 * 
 * @code
 void hospDepartment::readFromFile(string file_patient, string file_in_hospital){
	ifstream patient;
	ifstream in_hospital;
	patient.open(file_patient);
	in_hospital.open(file_in_hospital);
	int i_temp;
	string s_temp;
	Patient* t = new Patient;
	while(!patient.eof()){
		patient >> s_temp;
		t->setName(s_temp);
		patient >> s_temp;
		t->setDiagnosis(s_temp);
		patient >> i_temp;
		t->setDays(i_temp);
		patient >> s_temp;
		t->setDepartment(s_temp);
		patient >> s_temp;
		t->setDate(s_temp);

		if(t->getDepartment() == _name)
			_list.add(t);
	}
	if(_list.size()>=0)
		_list.popHead();
	patient.close();
	while(!in_hospital.eof()){
		in_hospital >> s_temp;
		t->setName(s_temp);
		in_hospital >> s_temp;
		t->setDiagnosis(s_temp);
		in_hospital >> i_temp;
		t->setDays(i_temp);
		in_hospital >> s_temp;
		t->setDepartment(s_temp);
		in_hospital >> s_temp;
		t->setDate(s_temp);
		
		if(t->getDepartment() == _name){
			_in_hospital.add(t);
			_placeNumber--;
		}
	}
	if(_in_hospital.size()>=0)
		_in_hospital.popHead();
	in_hospital.close();
}
 * @endcode
 */

void hospDepartment::readFromFile(string file_patient, string file_in_hospital){
	ifstream patient;
	ifstream in_hospital;
	patient.open(file_patient);
	in_hospital.open(file_in_hospital);
	int i_temp;
	string s_temp;
	Patient* t = new Patient;
	while(!patient.eof()){
		patient >> s_temp;
		t->setName(s_temp);
		patient >> s_temp;
		t->setDiagnosis(s_temp);
		patient >> i_temp;
		t->setDays(i_temp);
		patient >> s_temp;
		t->setDepartment(s_temp);
		patient >> s_temp;
		t->setDate(s_temp);

		if(t->getDepartment() == _name)
			_list.add(t);
	}
	if(_list.size()>=0)
		_list.popHead();
	patient.close();
	while(!in_hospital.eof()){
		in_hospital >> s_temp;
		t->setName(s_temp);
		in_hospital >> s_temp;
		t->setDiagnosis(s_temp);
		in_hospital >> i_temp;
		t->setDays(i_temp);
		in_hospital >> s_temp;
		t->setDepartment(s_temp);
		in_hospital >> s_temp;
		t->setDate(s_temp);
		
		if(t->getDepartment() == _name){
			_in_hospital.add(t);
			_placeNumber--;
		}
	}
	if(_in_hospital.size()>=0)
		_in_hospital.popHead();
	in_hospital.close();
}

/**
 * @brief Метод для записи данных в файл
 * 
 * @code
 * void hospDepartment::writeToFile(string file_patient, string file_in_hospital){
	ofstream patient;
	ofstream in_hospital;
	patient.open(file_patient);
	in_hospital.open(file_in_hospital);
	Patient* t = _list.head;
	while(t!=NULL){
		patient << t->getName() << endl;
		patient << t->getDiagnosis() << endl;
		patient << t->getDepartment() << endl;
		patient << t->getDays() << endl;
		patient << t->getDate() << endl;
		t = t->next();
	}
	patient.close();
	t = _in_hospital.head;
	while(t!=NULL){
		in_hospital << t->getName() << endl;
		in_hospital << t->getDiagnosis() << endl;
		in_hospital << t->getDepartment() << endl;
		in_hospital << t->getDays() << endl;
		in_hospital << t->getDate() << endl;
		t = t->next();
	}
	in_hospital.close();
}
 * @endcode
 */ 

void hospDepartment::writeToFile(string file_patient, string file_in_hospital){
	ofstream patient;
	ofstream in_hospital;
	patient.open(file_patient);
	in_hospital.open(file_in_hospital);
	Patient* t = _list.head;
	while(t!=NULL){
		patient << t->getName() << endl;
		patient << t->getDiagnosis() << endl;
		patient << t->getDepartment() << endl;
		patient << t->getDays() << endl;
		patient << t->getDate() << endl;
		t = t->next();
	}
	patient.close();
	t = _in_hospital.head;
	while(t!=NULL){
		in_hospital << t->getName() << endl;
		in_hospital << t->getDiagnosis() << endl;
		in_hospital << t->getDepartment() << endl;
		in_hospital << t->getDays() << endl;
		in_hospital << t->getDate() << endl;
		t = t->next();
	}
	in_hospital.close();
}

/**
 * @brief Метод посика пациентов в общем списке и в списке отделения
 * 
 * @code
 * void hospDepartment::search(string name, string diagnosis, string date){
		_list.search(name, diagnosis, _name, 0, date);
		_in_hospital.search(name, diagnosis, _name, M, date);
	}
 * @endcode
 * 
 */ 

void hospDepartment::search(string name, string diagnosis, string date){
	_list.search(name, diagnosis, _name, 0, date);
	_in_hospital.search(name, diagnosis, _name, M, date);
}

/**
 * @brief Метод, который выводит общий список пациентов
 * 
 * @code
 * void hospDepartment::printList(){
		_list.printWhole();
	}
 * @endcode
 */ 

void hospDepartment::printList(){
	_list.printWhole();
}

/**
 * @brief Метод, который выводит список пациентов в отделении
 * 
 * @code
 * void hospDepartment::print_in_hospital(){
		_in_hospital.printWhole();
	}
 * @endcode
 */ 
void hospDepartment::print_in_hospital(){
	_in_hospital.printWhole();
}

/**
 * @brief Метод, который удаляет выбранного пациента из списка отделения
 * 
 * @code
 * void hospDepartment::discharm(int n){
		_in_hospital.remove(n);
		_placeNumber++;
	}
 * @endcode
 */ 

void hospDepartment::discharm(int n){
	_in_hospital.remove(n);
	_placeNumber++;
}
