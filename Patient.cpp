#include "Patient.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Patient::Patient(){
		_name = "";
		_diagnosis = "";
		_department = "";
		_days = 0;
		_date = "";
		_next = NULL;
}
Patient::Patient(string name, string diagnosis, string department, int days, string date){
	_name = name;
	_diagnosis = diagnosis;
	_department = department;
	_days = days;
	_date = date;
	_next = NULL;
}
void Patient::setName(string name){
	_name = name;
}
void Patient::setDiagnosis(string diagnosis){
	_diagnosis = diagnosis;
}
void Patient::setDepartment(string department){
	_department = department;
}
void Patient::setDays(int days){
	_days = days;
}
void Patient::setDate(string date){
	_date = date;
}
void Patient::setNext(Patient* next){
	_next = next;
}
void Patient::print(){
        cout << "Name: " << _name << endl;
        cout << "diagnosis: " << _diagnosis << endl;
        cout << "department:" << _department << endl;
        cout << "days:" << _days << endl;
        cout << "date: " << _date << endl;
}
string Patient::getName(){
	return _name;
}
string Patient::getDiagnosis(){
	return _diagnosis;
}
string Patient::getDepartment(){
	return _department;
}
int Patient::getDays(){
	return _days;
}
string Patient::getDate(){
	return _date;
}	
Patient* Patient::next(){
	return _next;	
}
