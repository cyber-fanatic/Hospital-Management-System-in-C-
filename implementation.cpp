//========================classes implemantation=====================
#include<iostream>
#include<string>
#include"abstract.h"
#include"classes.h"
using namespace std;
//===============Person's implementation==============
Person::Person() {
	this->name = "Unknown";
	this->age = 0;
	this->gender = ' ';
}
//==============Doctor's implementation===================
Doctor::Doctor(){
	this->name = "Unknown";
	this->doctor_id = 0;
	this->gender = ' ';
	this->age = 0;
	this->experience = 0;
	this->speciality = "Unknown";
	this->salary = 0;
}
//parametrized constructor
Doctor::Doctor(int id, string n,int age, char d_gender, double expe, string speciality) {
	this->doctor_id = id;
	this->name = n;
	this->age = age;
	this->gender = d_gender;
	this->experience = expe;
	this->speciality = speciality;
}
//========input()=============
void Doctor::input()  {
	cout << "\n[+]=======================Welcome to Hospital Management System=========================[+]\n";
	cout << "Enter Doctor's id: " << '\n';
	cin >> doctor_id;
	cin.ignore();
	cout << "Enter Doctor's Name: "<< '\n';
	getline(cin, name);
	cout << "Enter Gender: " << '\n';
	cin >> gender;
	cout << "Enter Doctor's age: " << '\n';
	cin >> age;
	cout << "Enter Experience in years: " << '\n';
	cin >> experience;
	cin.ignore();
	cout << "Enter Doctor's Speciality: " << '\n';
	getline(cin, speciality);
	cout << "Enter Doctor's salary: ";
	cout << '\n';
	 
}
//=========setters==========
void Doctor::set_name(string n) {
	this->name = n;
}
void Doctor::set_age(int a) {
	 this->age = a;
}
void Doctor::set_gender(char g) {
	this->gender = g;
}
//=========getters=========
string Doctor::get_name() {
	return name;
}
int Doctor::get_age() {
	return age;
}
char Doctor::get_gender() {
	return gender;
}
void Doctor::set_salary(double salary) {
	this->salary = salary;
}
double Doctor::get_salary() {
	return salary;
}
//===========Display()===============
void Doctor::displayInfo() {
	cout << "\n=======Doctor's Information=======\n";
	cout << "Doctor's id: " << doctor_id << '\n';
	cout << "Doctor's Name: " << name<<'\n';
	cout << "Doctor's Age: " << age << '\n';
	cout << "Doctor's Gender: " << gender << '\n';
	cout << "Doctor has " << experience << " years of experience\n";
	cout << "Doctor's speciality: " << speciality << '\n';
	cout << "Doctor's salary is: " << salary << " pkr " << '\n';
}
//====Doctor destructor=====
Doctor::~Doctor(){};
//============================Patient class implementation===============
// =============default constructor=============
Patient::Patient() {
	this->patient_id = 0;
	this->disease = "Not specified yet";
	this->bill_amount = 0;
	this->weight = 0;
}
//============parametrized constructor================
Patient::Patient(int id, string n,char g,double weight,string disease, double bill) {
	this->patient_id = id;
	set_name(n);
	set_gender(g);
	this->weight = weight;
	this->gender = g;
	this->disease = disease;
	this->bill_amount = bill;
}
//=============setters==============
void Patient::set_patientid(int id) {
	this->patient_id = id;
}
void Patient::set_disease(string disease) {
	this->disease = disease;
}
void Patient::set_bamount(double amount) {
	this->bill_amount = amount;
}
void Patient::set_name(string n) {
	this->name = n;
}
void Patient::set_gender(char g) {
	this->gender = g;
}
void Patient::set_weight(double w) {
	this->weight = w;
}
//===========getters============
int Patient::get_patientid() {
	return patient_id;
}
string Patient::get_disease() {
	return disease;
}
double Patient::get_bill_amount() {
	return bill_amount;
}
string Patient::get_name() {
	return name;
}
char Patient::get_gender() {
	return gender;
}
double Patient::get_weight() {
	return weight;
}
//=============input()===========
void Patient::input() {
	cout << "\n[+]=======================Welcome to Hospital Management System=========================[+]\n";
	cout << "Enter patient id: ";
	cin >> patient_id;
	cout << '\n';
	cin.ignore();
	cout << "Enter Patient name: ";
	getline(cin, name);
	cout << '\n';
	cout << "Enter Patient age: ";
	cin >> age;
	cout << '\n';
	cout << "Enter Patient gender: ";
	cin >> gender;
	cout << '\n';
	cout << "Enter Weight of patient: ";
	cin >> weight;
	cout << '\n';
	cin.ignore();
	cout << "Enter Patient disease: ";
	getline(cin, disease);
	cout << '\n';
	cout << "Enter total bill amount: ";
	cin >> bill_amount;
}
//===============displauInfo()===========
void Patient::displayInfo() {
	cout << "\n==============Patient Information===============\n";
	cout << "Patient id: " << patient_id<<'\n';
	cout << "Patient Name: " << name<<'\n';
	cout << "Patient Age: " << age<<'\n';
	cout << "Patient gender: " << gender << '\n';
	cout << "Weight of patient : " << weight << " kg\n";
	cout << "Patient has disease: " << disease << '\n';
	 
	//=============== discount logic ===========
	if (bill_amount < 5000) {
		cout << "You have to pay: " << bill_amount << '\n';
	}
	else if (bill_amount>=500||bill_amount<7000) {   // 15% discount
		double discount;
		discount = bill_amount * (15.0 / 100);
		bill_amount = bill_amount - discount;
		cout << "Total payable amount after discount is : " << bill_amount << '\n';
	}
	else if (bill_amount>=700) {
		double discount;
		discount = bill_amount * (30.0 / 100);    //30% discount if amount is grater than equal to 7000 
		bill_amount = bill_amount - discount;
		cout << "Total payable amount after discount is : " << bill_amount << '\n';
	}
	else {
		cout << "No discount Avilble.\n";
	}
}
//================apply_discount()========
double Patient::apply_discount(double bill) {
	if (bill < 5000) {
		cout << "You have to pay: " << bill << '\n';
	}
	else if (bill >= 500 || bill < 7000) {   // 15% discount
		double discount;
		discount = bill * (15.0 / 100);
		bill = bill - discount;
		return bill;
	}
	else if (bill >= 700) {
		double discount;
		discount = bill * (30.0 / 100);    //30% discount if amount is grater than equal to 7000 
		bill = bill - discount;
		return bill;
	}
	else {
		cout << "No discount Avilble.\n";
	}
	return bill;
}
//======================AdmittedPatient class Implementation=======================
//default constructor
AdmittedPatient::AdmittedPatient() {
	this->room_num = 0;
	this->stay_duration = 0;
}
//============== Parametrized constructor ===============
AdmittedPatient::AdmittedPatient(int id, string n, int roomn, int stayd, string disease , double amount) {    //(id,name,roomn,stayd,disease,amount)
	this->set_patientid(id);
	this->name = n;
	this->room_num = roomn;
	this->stay_duration = stayd;
	this->set_disease(disease);
	this->set_bamount(amount);
}
//=================setters=================
void AdmittedPatient::set_room_num(int rn) {
	this->room_num = rn;
}
void AdmittedPatient::set_stay_duration(int stay_d) {
	this->stay_duration = stay_d;
}
//==============getters===========
int AdmittedPatient::get_room_num() {
	return room_num;
}
int AdmittedPatient::get_stay_duration() {
	return stay_duration;
}
 
//====================input()================
void AdmittedPatient::input() {
	Patient::input();
	cout << '\n';
	cout << "Enter Room Number of patient: ";
	cin >> room_num;
	cout << '\n';
	cout << "Enter Stay Duration of Patient: ";
	cin >> stay_duration;
	cout << '\n';
}
//==============displayInfo()========
void AdmittedPatient::displayInfo() {
	Patient::displayInfo();
	cout << "Room number of Patient " << name << " is :" << room_num << '\n';
	cout << "Stay duration of patient " << name << " in hospital is " << stay_duration << " days\n";
}

//====================Staff implementation=========================
//============default constructor=============
Staff::Staff() {
	this->staff_id = 0;
	this->designation = "Unknown";
	this->salary = 0;
}
//==============parametrized constructor==========
Staff::Staff(int id,string n,string desig,double salary) {    
	this->staff_id = id;
	this->name = n;	 
	this->designation = desig;
	this->salary = salary;
}
// =============setters============
void Staff::set_staff_id(int id) {
	this->staff_id = id;
}

void Staff::set_designation(string desig) {
	this->designation = desig;
}

void Staff::set_salary(double sal) {
	this->salary = sal;
}

// Getter Definitions
int Staff::get_staff_id() {
	return staff_id;
}

string Staff::get_designation() {
	return designation;
}

double Staff::get_salary() {
	return salary;
}

// Overridden Methods
void Staff::input() {
	cout << "\n[+]=======================Welcome to Hospital Management System=========================[+]\n";
	cout << '\n';
	cout << "Enter Employee Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter Age: ";
	cin >> age;

	cout << "Enter Gender (M/F): ";
	cin >> gender;

	cout << '\n';
	cout << "Enter Employee ID: ";
	cin >> staff_id;
	cin.ignore();

	cout << "Enter Designation: ";
	getline(cin, designation);

	cout << "Enter Salary: ";
	cin >> salary;
	cout << '\n';
}

void Staff::displayInfo() {
	cout << "\n============= Staff Details =============\n";
	cout << "Employee ID: " << staff_id << '\n';
	cout << "Employee Name: " << name << '\n';
	cout << "Employee Age: " << age << '\n';
	cout << "Employee Gender: " << gender << '\n';
	cout << "Employee Designation: " << designation << '\n';
	cout << "Employee Salary: " << salary <<" pkr " << '\n';
	cout << '\n';
}
//=========staff Destructor===========
Staff::~Staff() {};

//=========================class Surgeon========================== use designation from Staff and experience from doctor
//=========default constructor==============
Surgeon::Surgeon() {
	this->surgeries_performed = 0;
	this->surgery_in_progress = false;
	this->Staff::salary = 0;
}
//==========parametrized constructor=========
Surgeon::Surgeon(int id, string n, string desig, double salary) {      
	this->staff_id = id;
	this->name = n;
	this->designation = desig;
	this->Staff::salary = salary;
	this->surgeries_performed = 0;
}
//===========setters========
void Surgeon::set_surgeries_performed(int s) {
	this->surgeries_performed = s;
}

void Surgeon::set_surgery_in_progress(bool status) {
	this->surgery_in_progress = status;
}
//========getters=============
int Surgeon::get_surgeries_performed() {
	return surgeries_performed;
}

bool Surgeon::get_surgery_in_progress() {
	return surgery_in_progress;
}
//================overrding input()===================
void Surgeon::input() {
	cout << "\n[+]=======================Welcome to Hospital Management System=========================[+]\n";
	cout << "\n============= Enter Surgeon Details =============\n";
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter Age: ";
	cin >> age;

	cout << "Enter Gender (M/F): ";
	cin >> gender;

	cout << "Enter Specialization: ";
	cin.ignore();
	getline(cin, speciality);      //speciality from Doctor class

	cout << "Enter Experience in (years): ";
	cin >> experience;

	cout << "Enter Staff ID: ";
	cin >> staff_id;

	cout << "Enter Designation: ";
	cin.ignore();
	getline(cin, designation);     //use designation from Staff class

	cout << "Enter Salary: ";
	cin >> Staff::salary;

	cout << "Enter Surgeries Performed: ";
	cin >> surgeries_performed;

	cout << "Is Surgery in Progress? (1 = Yes / 0 = No): ";
	cin >> surgery_in_progress;

	cout << '\n';
}
//==================overriding displayInfo()===================
void Surgeon::displayInfo() {
	cout << "\n============== Surgeon Information =================\n";
	cout << "Surgeon Name: " << name << '\n';
	cout << "Surgeon Age: " << age << '\n';
	cout << "Gender: " << gender << '\n';
	cout << "Surgeon Specialization: " << Doctor::speciality << '\n';
	cout << "SurgeonExperience: " << experience << " years\n";
	cout << "Staff ID: " << staff_id << '\n';
	cout << "Designation: " << designation << '\n';
	cout << "Salary: " << Staff::salary <<" pkr " << '\n';
	cout << "Surgeries Performed: " << surgeries_performed << '\n';
	if (surgery_in_progress==true) {
		cout << "Surgrey in progress: Yes\n";
	}
	else {
		cout << "Surgrey in progress: No\n";
	}
	cout << '\n';
}
//=============surgeon destructor=================
Surgeon::~Surgeon() {};



//=============================main()=====================
int main() {



	
	 //here in main put the code step by  step write in new.cpp


}
