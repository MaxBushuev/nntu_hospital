include "Patient.hpp"
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
Patient* Patient::getNext(){
	return _next;
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
string Patient::getDate()(
	return _date;
}	
Patient* Patient::next(){
	return _next;	
}
ostream& operator<< (ostream &out, Patient &patient){
        out << "Name: " << patient._name << endl;
        out << "diagnosis: " << patient._diagnosis << endl;
        out << "department:" << patient._department << endl;
        out << "days: " << patient._days << endl;
        out << "date: " << patiant._date << endl;
        return out;
}
istream& operator>> (istream &in, Patient &patient){
        cout << "Name: ";
        in >> patient._name;
        cout << "diagnosis: ";
        in >> patient._diagnosis;
        cout << "department: ";
        in >> patient._department;
        cout << "days: ";
        in >> patient._days;
        cout << "date: ";
        in >> patient._date;
        return in;
}
fstream& operator<< (ofstream &fout, Patient &patient){
        fout << patient._name << endl;
        fout << patient._diagnosis << endl;
        fout << patient._department << endl;
        fout << patient._days << endl;
        fout << patient._date << endl;
        return fout;
}
ifstream& operator>> (ifstream &fin, Patient &patient){
        fin >> patient._name;
        fin >> patient._diagnosis;
        fin >> patient._department;
        fin >> patient._days;
        fin >> patient._date;
        return fin;
}

