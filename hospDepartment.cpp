#include "hospDepartment.hpp"
#include <fstream>
using namespace std;
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
string hospDepartment::getName(){
	return _name;
}
int hospDepartment::getDoctors(){
	return _doctors;
}
void hospDepartment::setDoctors(int doctors){
	_doctors = doctors;
}
int hospDepartment::getPlaceNumber(){
	return _placeNumber;
}
void hospDepartment::setPlaceNumber(int placeNumber){
	_placeNumber = placeNumber;
}
int hospDepartment::getCanTake(){
	return _canTake;
}
void hospDepartment::setCanTake(int canTake){
	_canTake = canTake;
}
void hospDepartment::add_list(Patient* temp){
	_list.add(temp);
	_canTake--;
}
void hospDepartment::add_in_hospital(Patient* temp){
	_in_hospital.add(temp);
	_placeNumber--;
}
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
void hospDepartment::search(string name, string diagnosis, string date){
	_list.search(name, diagnosis, _name, 0, date);
	_in_hospital.search(name, diagnosis, _name, M, date);
}
void hospDepartment::printList(){
	_list.printWhole();
}
void hospDepartment::print_in_hospital(){
	_in_hospital.printWhole();
}
void hospDepartment::discharm(int n){
	_in_hospital.remove(n);
	_placeNumber++;
}
