#include "patientList.h"
#include <iostream>

using namespace std;

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

int patientList::size() {
    return _size;
}
void patientList::add(Patient* t){
    t->setNext(head);
    head = t;
    _size++;	
}
void patientList::add(string name, string diagnosis, string departement, int days, string date) {
    Patient *temp = new Patient( name, diagnosis, departement, days, date);
    temp->setNext(head);
    head = temp;  
    _size++;
}
void patientList::popHead(){
    Patient* temp = head->next();
    delete head;
    head = temp;
    _size--;
}
void patientList::printWhole(){
    setlocale(LC_ALL, "rus");
    Patient *temp = head;
    int i = 1;
    if(temp == NULL){
        cout << "Пациентов не найдено";
    }else
    {
    while(temp != 0){
      cout << " Билет№" << i;
      cout << " ФИО: " << temp ->getName(); 
      cout << " |Диагноз: " + temp -> getDiagnosis();
      cout << " |Отделение: " << temp -> getDepartment(); 
      cout << " |Дней госпитализации: " + temp -> getDays();
      cout << " |Дата госпитализации: " + temp -> getDate() << endl;
      temp = temp -> next();
      i++;
    }
    }
}


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
        cout << "Неправильно введен номер";
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

void patientList::search(string name, string diagnosis, string departement, int days, string date){
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

    void patientList::changed(int n){
        Patient *temp = head;
         string name;
           string diagnosis;
           string departement;
           int days;
           string date;

        for (int i = 0; i < n ; i++)
            temp = temp->next();

        
		cout << "Введите новое ФИО: ";
        cin >> name;
		cout << "Введите новый диагноз: ";
		cin >> diagnosis; 
    	cout << "Введите новое отделение: ";
    	cin >> departement;
    	cout << "Введите новое кол-во дней госпиталицзации: ";
    	cin >> days;
    	cout << "Введите новое дата: ";
    	cin >> date;

        temp -> setName(name);
        temp -> setDiagnosis(diagnosis);
        temp -> setDepartment(departement);
        temp -> setDays(days);
        temp -> setDate(date);
        } 
