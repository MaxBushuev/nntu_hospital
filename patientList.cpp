#include "patientList.h"
#include <iostream>

using namespace std;

/**
 * @file patientList.cpp
 * @brief Реализация списка пациентов
 * 
 * @param name ФИО пациента
 * @param diagnosis Диагноз пациента
 * @param departament Отделение, в котором лежит пациент
 * @param days Дней госпитализации
 * @param date Дата, когда пациент был госпитализирован
 * @param temp Переменная типа Patient
 * @param size Размер patientList
 *
 */

patientList::patientList() {
    head = NULL;
    _size = 0;
}

patientList::~patientList() {
    while (head != NULL) {
        Patient *temp = head->next();
        delete head;
        head = temp;
    }
}


/**
 * @brief Метод, возвращающий размер списка пациентов 
 * 
 * @code
 * int patientList::size() {
    return _size;
   }
 * @endcode
 */ 
int patientList::size() {
    return _size;
}

/**
 * @brief Метод, добавляющий пациента в спсиок, и который принимает тип Patient
 * 
 * @code
 * void patientList::add(Patient* t){
    t->setNext(head);
    head = t;
    _size++;	
   }
 * @endcode
 */ 
void patientList::add(Patient* t){
    t->setNext(head);
    head = t;
    _size++;	
}

/**
 * @brief Метод, добавляющий пациента в список, и который принимает данные пациента
 * 
 * @code
 * void patientList::add(string name, string diagnosis, string departement, int days, string date) {
    Patient *temp = new Patient( name, diagnosis, departement, days, date);
    temp->setNext(head);
    head = temp;  
    _size++;
}
 * @endcode
 */

void patientList::add(string name, string diagnosis, string departement, int days, string date) {
    Patient *temp = new Patient( name, diagnosis, departement, days, date);
    temp->setNext(head);
    head = temp;  
    _size++;
}

/**
 * @brief Метод удаляющий первый элемент списка
 * 
 * @code
 * void patientList::popHead(){
    Patient* temp = head->next();
    delete head;
    head = temp;
    _size--;
    }
 * @endcode
 */ 
void patientList::popHead(){
    Patient* temp = head->next();
    delete head;
    head = temp;
    _size--;
}

/**
 * @brief Метод, который вывводит список на экран
 * 
 * @code
void patientList::printWhole(){
    Patient *temp = head;
    int i = 1;
    if(temp == NULL){
        cout << "No patients found";
    }else
    {
    while(temp != 0){
      cout << " Patient№" << i;
      cout << " Name: " << temp ->getName(); 
      cout << " |Dignosis: " + temp -> getDiagnosis();
      cout << " |Departament: " << temp -> getDepartment(); 
      cout << " |Hospital days: " + temp -> getDays();
      cout << " |Date of hospitalization: " + temp -> getDate() << endl;
      temp = temp -> next();
      i++;
    }
    }
}
 * @endcode
 */

void patientList::printWhole(){
    Patient *temp = head;
    int i = 1;
    if(temp == NULL){
        cout << "No patients found";
    }else
    {
    while(temp != 0){
      cout << " Patient№" << i;
      cout << " Name: " << temp ->getName(); 
      cout << " |Dignosis: " + temp -> getDiagnosis();
      cout << " |Departament: " << temp -> getDepartment(); 
      cout << " |Hospital days: " + temp -> getDays();
      cout << " |Date of hospitalization: " + temp -> getDate() << endl;
      temp = temp -> next();
      i++;
    }
    }
}

/**
 *@brief Метод, удаляющий выбранный пользователем, элемент из списка
 * 
 *@code 
void patientList::remove(int n) {
    Patient *temp = head;
     if (n == 0)
  {
     Patient* newHead = head->next();
     delete head;
     head = newHead;
     _size--;
     return;
  }else if (head == NULL || n > _size){
        cout << "Wrong number entered";
        return;
    }else{
    for (int i = 0; i < n - 1; i++)
         temp = temp->next();

    Patient* delEl = temp->next();
    temp->setNext(delEl->next());
    _size--;
    delete delEl;
  }
}
 *@endcode
 */

void patientList::remove(int n) {
    Patient *temp = head;
     if (n == 0)
  {
     Patient* newHead = head->next();
     delete head;
     head = newHead;
     _size--;
     return;
  }else if (head == NULL || n > _size){
        cout << "Wrong number entered";
        return;
    }else{
    for (int i = 0; i < n - 1; i++)
         temp = temp->next();

    Patient* delEl = temp->next();
    temp->setNext(delEl->next());
    _size--;
    delete delEl;
  }
}

/**
 * @brief Метод поиска пациентов в списке
 * 
 * @code
 * void patientList::search(string name, string diagnosis, string departement, int days, string date){
        setlocale(LC_ALL, "rus");
        Patient *temp = head;
        int i = 1;
        int prov = 0;
        while(temp != NULL){
           string name1 = temp-> getName();
           string diagnosis1 = temp -> getDiagnosis();
           string departement1 = temp -> getDepartment();
           int days1 = temp -> getDays();
           string date1 = temp -> getDate();
            if(days == days1 || name1 == name || diagnosis == diagnosis1 || date == date1 ){
                cout << " Пациент№ " << i;
                cout << " ФИО: " << name1; 
                cout << " |Диагноз:" + diagnosis1;
                cout << " |Отделение: " << departement1; 
                cout << " |Дней в больнице: " + days1;
                cout << " |Дата госпитализации : " + date1 << endl;
                prov = 1;
            } 
            temp = temp -> next();
            i++;
        }
         if(prov == 0)
             cout << "Пациентов не найдено не найдено" << endl;
    }
 * @endcode
 */

void patientList::search(string name, string diagnosis, string departement, int days, string date){

        Patient *temp = head;
        int i = 1;
        int prov = 0;
        while(temp != NULL){
           string name1 = temp-> getName();
           string diagnosis1 = temp -> getDiagnosis();
           string departement1 = temp -> getDepartment();
           int days1 = temp -> getDays();
           string date1 = temp -> getDate();
            if(days == days1 || name1 == name || diagnosis == diagnosis1 || date == date1 ){
                cout << " Patient№ " << i;
                cout << " Name: " << name1; 
                cout << " |Diagnosis:" + diagnosis1;
                cout << " |Departement: " << departement1; 
                cout << " |No patients found: " + days1;
                cout << " |Date of hospitalization: " + date1 << endl;
                prov = 1;
            } 
            temp = temp -> next();
            i++;
        }
         if(prov == 0)
             cout << "No patients found" << endl;
    }

/**
 * @brief Метод, позволяющий редактировать данные пациента
 * 
 *@code 
  void patientList::changed(int n){
        Patient *temp = head;
         string name;
           string diagnosis;
           string departement;
           int days;
           string date;

        for (int i = 0; i < n ; i++)
            temp = temp->next();

        
		cout << "Enter your new full name: ";
        cin >> name;
		cout << "Enter a new diagnosis: ";
		cin >> diagnosis; 
    	cout << "Enter a new branch: ";
    	cin >> departement;
    	cout << "Enter the new number of days of hospitalization: ";
    	cin >> days;
    	cout << "Enter a new date: ";
    	cin >> date;

        temp -> setName(name);
        temp -> setDiagnosis(diagnosis);
        temp -> setDepartment(departement);
        temp -> setDays(days);
        temp -> setDate(date);
        } 
 *@endcode 
 */

    void patientList::changed(int n){
        Patient *temp = head;
         string name;
           string diagnosis;
           string departement;
           int days;
           string date;

        for (int i = 0; i < n ; i++)
            temp = temp->next();

        
		cout << "Enter your new full name: ";
        cin >> name;
		cout << "Enter a new diagnosis: ";
		cin >> diagnosis; 
    	cout << "Enter a new branch: ";
    	cin >> departement;
    	cout << "Enter the new number of days of hospitalization: ";
    	cin >> days;
    	cout << "Enter a new date: ";
    	cin >> date;

        temp -> setName(name);
        temp -> setDiagnosis(diagnosis);
        temp -> setDepartment(departement);
        temp -> setDays(days);
        temp -> setDate(date);
        } 
