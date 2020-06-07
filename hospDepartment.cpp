#include "hospDepartment.hpp"
#include <fstream>
using namespace std;
hospDepartment::hospDeparment(){
	_name = "";
	_maxDoctors = 0;
	_availableDoctors = 0;
	_maxPlaceNumber = 0;
	_placeNumber = 0;
}
string hospDepartment::getName(){
	return _name;
}
int hospDepartment::getMaxAvailableDoctors(){
	return _maxAvailableDoctors;
}
int hospDepartment::hospDepartment::getAvailableDoctors(){
	return _availableDoctors;
}
void hospDepartment::setMaxAlailableDoctors(int maxAvailableDoctors){
	_maxAvailableDoctors = maxAvailableDoctors;
}
int hospDepartment::getMaxPlaceNumber(){
	return _maxPlaceNumber;
}
void hospDepartment::setMaxPlaceNumber(int maxPlaceNumber){
	_maxPlaceNumber = maxPlaceNumber;
}
int hospDepartment::getPlaceNumber(){
	return _placeNumber;
}
void hospDepartment::setPlaceNumber(intPlaceNumber){
	_placeNumber = placeNumber;
}
void hospDepartment::readFromFile(string file_patient, string file_in_hospital){
	ifstream patient;
	ofstream in_hospital;
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

		_list.add(t);
	}
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

		_in_hospital.add(t);
	}
	_in_hospital.popHead();
	in_hospital.close();
}
void hospDepartment::writeToFile(string file_patient, string file_in_hospital){
	ofstream patient;
	ofstream in_hospital;
	patient.open(file_
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
void hospDepartment::printList(){
	_list.printWhole();
}
void hospDepartment::print_in_hospital(){
	_in_hospital.printWhole();
}
