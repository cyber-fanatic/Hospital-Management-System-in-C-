//========this file consists of all prototypes and datamembers==================
#pragma once
#include<iostream>
#include"abstract.h";
#include<string>
using namespace std;

//=================Doctor's class=================
class Doctor : virtual public Person {         //use virtual here for solving diamond problem
protected:
	int doctor_id;
	double experience;
	string speciality;
	double salary;
public:
	//default constructor
	Doctor();
	//getter setters
	void set_name(string n);
	string get_name();
	void set_age(int a) ;
	int get_age() ;
	void set_gender(char g);
	char get_gender();
	void set_salary(double salary);
	double get_salary();
	//parametrized constructor
	Doctor(int id, string n,int a, char d_gender, double expe, string speciality);

	//func prototypes
	void input() override;
	void displayInfo() override;
	~Doctor()override;
};

//==================================Patient class===========================
class Patient :public Person {
private:
	int patient_id;
	string disease;
	double bill_amount;
	double weight;
public:
	//=============default constructor==========
	Patient();
	//========parametrized constructor==========
	Patient(int id,string n,char g,double weight,string disease, double bill);
	//========setters========
	void set_patientid(int id);
	void set_disease(string disease);
	void set_bamount(double amount);
	void set_name(string n);
	void set_gender(char g);
	void set_weight(double w);
	//=======getters=========
	int get_patientid();
	string get_disease();
	double get_bill_amount();
	string get_name();
	char get_gender();
	double get_weight();
	//=============input============
	void input()override;
	//============display()========
	void displayInfo() override;
	//===============get_discount()=======
	double apply_discount(double bill);
};
//======================= AdmittedPatient class ===================
class AdmittedPatient :public Patient {
private:
	int room_num;
	int stay_duration;
public:
	double bill = 0;
	//default constructor
	AdmittedPatient();
	//============== Parametrized constructor ===============
	AdmittedPatient(int id,string n,int roomn, int stayd,string disease,double amount);
	////=============== copy constructor of admittedpatient========
	//AdmittedPatient(const Patient& obj);
	//==========setters==========
	void set_room_num(int rn);
	void set_stay_duration(int stay_d);
	//===============getters=============
	int get_room_num();
	int get_stay_duration();
	//===============input()=========
	void input() override;
	//=========displayInfo()==========
	void displayInfo() override;
	
};
//======================class Staff ==================

class Staff :virtual public Person {           //use virtual here for solving diamond problem
protected:
	int staff_id;
	string  designation;
	double salary;
public:
	//=========default constructor===========
	Staff();
	//================parametrized constructor==============
	Staff(int id, string n, string desig, double salary);
	// ===========Setter prototypes==========
	void set_staff_id(int id);
	void set_designation(string desig);
	void set_salary(double sal);

	// ================Getter prototypes==============
	int get_staff_id();
	string get_designation();
	double get_salary();

	// ==========Overriding virtual functions===========
	void input() override;
	void displayInfo() override;
	~Staff();
};

//========================= Surgeon class ========================
class Surgeon : public Doctor, public Staff {
private:
	int surgeries_performed;
	bool surgery_in_progress;

public:
	//============Default constructor============
	Surgeon();
	//================== parametrized constructor ===============
	Surgeon(int id, string n, string desig, double salary);
	// Setter Prototypes
	void set_surgeries_performed(int count);
	void set_surgery_in_progress(bool inProgress);

	// Getter Prototypes
	int get_surgeries_performed();
	bool get_surgery_in_progress();

	// Overridden input() and display()
	void input() override;
	void displayInfo() override;
	//surgeon destructor
	~Surgeon()override;
};
