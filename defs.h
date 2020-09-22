#include <iostream> // standard library
#include <iomanip> // output manipulation library
#include <cstring> // C library (for strcpy)
#include <cstdlib> // standard library.
#include <ctime>  // time library
#include<stdio.h>
#include<time.h>  
#include <cmath>   // calculate
#include <windows.h> // for Sleep() function
#include<stdlib.h>
using namespace std;


int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days each month has.
char week[7][10], mon_char[12][20];


// define and initialize 3 array of size 25 and declare all element to be 0
bool level1[25] = {0};
bool level2[25] = {0};
bool level3[25] = {0};

// define and initialize 3 pointers that store the address of the first element of each array 
bool *pointer1 = &level1[0];
bool *pointer2 = &level2[0];
bool *pointer3 = &level3[0];


// constant for prices vehicle 
const int veichle_price_day[2] = {3, 2}; // price per hour in week_day
const int veichle_price_end[2] = {4, 3}; // price per hour in week-end

// constant for servicse 
const int CarServicePrice[2] ={15,10};   //  The services prices first wash second vacuum for cars

char name[]= "Alsalamah";  // The name of our parking 
int vehicle_type;
int serv_id, day, year, s, mon;
int *ptr_veh = &vehicle_type;
char weekend, Yes, yes, No, no;
int hours,total =0, level, spot;



// the functions and their jobs

void Display();  // for registration and get tickit 
void get_weekend(); // ask users if weekend 
void get_level();   // display which level from three 
void get_hours(); // display num of hours 
void ShowServices(); // display the process to shoe types of services 
void get_service_car();  // display types of services  provid for cars
void get_service_Motor(); // Display types of services provid for Motor Cycle
void getSpot(); // display the spots from 25 
void bookSpot(int,int,bool); 
void showMatrics (bool[]); // show scheme of the the parking num
void availableSpot(int); // display the avilible spots
void showtik(); // function for show ticket
void calcdate(); // display the process for date
double calctotal();

//
  
void calcdate(){
	
	// copy week days to week array
	strcpy(week[0], "Sun") ;
	strcpy(week[1], "Mon") ;
	strcpy(week[2], "Tue") ;
	strcpy(week[3], "Wed") ;
	strcpy(week[4], "Thu") ;
	strcpy(week[5], "Fri") ;
	strcpy(week[6], "Sat") ;
	srand(time(NULL)); // set run time to null so you get a different number each time you run the function.
	serv_id = 1 + rand() % (1 - 1000 + 1); // generate a number between 1 and 1000.
	time_t t = time(NULL); // set the time to null so it will read the right system data everytime you run the program.
	struct tm tm = *localtime(&t); // a structure to get the local date
	day = tm.tm_mday - 1; // get real day.
	year = tm.tm_year + 1900; // get real year.
	mon = tm.tm_mon + 1; // get real month.
	// transform day from int to real day name
	for (int i = 0 ; i < mon - 1 ; i++){
		s = s + month[i] ;
	}
	s = s + (day + year + (year / 4) - 2) ; // some random algorithm that just works (don't ask how please)
	s = s % 7 ;
	// change month from int to real month
	strcpy(mon_char[0], "January");
	strcpy(mon_char[1], "February");
	strcpy(mon_char[2], "March");
	strcpy(mon_char[3], "April");
	strcpy(mon_char[4], "May");
	strcpy(mon_char[5], "June");
	strcpy(mon_char[6], "July");
	strcpy(mon_char[7], "August");
	strcpy(mon_char[8], "September");
	strcpy(mon_char[9], "October");
	strcpy(mon_char[10], "November");
	strcpy(mon_char[11], "December");
	
}

void showMatrics(bool x[] ){ // Function to print diagram
    int av=0,nv=0;
	int count = 1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){

			if(x[count-1]){
					cout<<setw(5)<<"# "<<setw(2)<<count++;
					nv++;
				}
			else {
				cout <<setw(5)<< "* "<<setw(2)<<count++;
				av++;
			}
		}
		cout << endl;
	}
	cout <<"\n# = Parked : "<< nv <<" .\n* = Available : "<< av <<endl<<endl;
}


double  calctotal() // show how to calculate the total money to be paid 
	{

	double rate;

    switch(*ptr_veh){

    	case 1 : if(weekend == 'Y' || weekend == 'y') {
			rate = 4;	}
		 else{
	     	 rate = 3 ;
	     	 }  break;
		case 2 : if(weekend == 'Y' || weekend == 'y') {
			rate = 3;	}
		 else{
	     	 rate = 2;
	     	 }  break;
    
	}
	    total = hours * rate ; // The process to show total
}
