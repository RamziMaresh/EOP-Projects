#include "defs.h" // header file 
int main()
{
	int option;
    int L;
    char Return;
	system("CLS");
	do{
        cout << " // 1. Register (Get a ticket). <<"<<endl;
        cout << " // 2. Show available parking spot. <<"<<endl;
        cout << " // 3. Our Services avilable for vehicle. <<"<< endl;
	    cout << "\n\n\t>> Your option( !! enter 0 to exit !!):";
	    cin>>option;
        cin.ignore();
        if(option==0)
        exit(0);
        while(option !=1 && option !=2 && option !=3 && option !=4 ){
        cerr<<" \n>>Invalid choice ! please enter again: ";
        cin>>option;
        }
    switch(option){
    case 1: Display(); break; // call function Display
    case 2:
   	cout << ">>Enter your level : ";
	cin>>L;
    availableSpot(L); break;
    case 3: ShowServices();break;
    }
   
    cout<<"\n\n<<Do you want to return Main Menu again ?\n"
        <<">>Press Y for continue or any key to exit ! : ";
    cin>>Return;
    cout << endl;

    } while(Return=='Y'||Return=='y');
}


void Display()
{
	cout << "			--------------------------------------------------\n\n";
	cout << "				Welcome To " << name <<  " Parking Service\n" << endl;
	cout << "			--------------------------------------------------\n\n";
	Sleep(1 * 1000);
	cout << "\n" <<"  --- Please Select Vehicle Type : --- " << endl << endl // prompt user to select vehicle type.
	  <<setw (16) << left <<"\t\t\t Week-end\t\t\tWeek-Day\n" << endl
	  <<setw (16) << left << "  1. Car" << " per hour " <<"\t"<< veichle_price_end[0] <<" RM " << "\t\t" << " per hour" <<"\t" <<veichle_price_day[0] <<" RM " << endl
	  <<setw (16) << left << "  2. Motor Bike" << " per hour" <<"\t"<< veichle_price_end[1] << " RM " << "\t\t" << " per hour" <<"\t" <<veichle_price_day[1] <<" RM " << endl	
      <<setw (16) << left <<"                                  ==================================================\n\n";

      Sleep(2 * 1000);
	  cout << " -- Vehicle types : -- \n 1.Car\n 2.Motor Bike"<<"\n ** Your type vehicle ** : ";
	  cin >> *ptr_veh;
	  cout <<setw (16) << left << "============================\n";
	  
	  
	while (*ptr_veh > 2 || *ptr_veh < 1){ // just in case if someone enter more than 1 or 2
	
		Sleep(1 * 1000);
		cout << "Please Select A Valid Option: ";
		cin >>  *ptr_veh; 
	}
		get_weekend(); // call function 
		get_level(); // call function 
		get_hours(); // call function 
		getSpot(); //  call function
	   
}


void get_weekend(){
	
	Sleep(2 * 1000); // stop the program for 2 seconds.
	cout <<"\n --- Is it weekend or Not Y/N ---" << endl;
	cout <<" ** Your input ** : ";
	cin >> weekend;
    cout << "============================\n";

	while(weekend !='N' && weekend !='n' && weekend !='Y' && weekend !='y'){
	cout<< " --- invalid input , please enter Y or N!! --- " << endl;
	cin >> weekend;
    cout << "============================\n";
    }
}
	
void get_level(){    // function header  asking which level

 	Sleep(2 * 1000); // stop the program for 2 seconds.
 	cout << "\n --- Enter The Number Of Level (1 to 3) : --- " << endl;
 	cout <<" ** Number of level ** : ";
 	cin >> level;
 	cout << "============================\n";

    while(level>3 || level <1){   // condition if the user enter more the level three
    cout << " --- Invalid input !! Please Enter Level 1 , 2 or 3 --- " << endl;
    cin >> level;
    cout<< "============================\n";
    }
}
    
void get_hours(){  // function header 
	
	Sleep(2 * 1000); // stop the program for 2 seconds.
	if(*ptr_veh == 1 || *ptr_veh == 2)   
	cout << "\n" << " --- How Many Hours you Want to Park : --- "  << endl;
	cout <<" ** Number of hours ** : ";
	cin >> hours;
	cout << "============================\n";
}


bool checkSpot(int lev,int s){
	
    switch(lev){	
    case 1:  return (*(level1+(s-1))) ;
    case 2:  return (*(level2+(s-1))) ;
    case 3:  return (*(level3+(s-1))) ;
    }
}
    
    
    
void getSpot(){ // get spot for parking 

		availableSpot(level);
		cout<<">>Enter your spot (1 to 25): ";
	    cin>>spot;
	    while(spot<1 || spot>25){ // allow to enter only from 1 to 25
            cout<<"<<Invalid Choice !\n>>>>Enter your spot (1 to 25):";
            cin>>spot;
        }
        while(checkSpot(level,spot)){ // function makes one spot for one parking 
            cout<<"<<Already Booked !\n>>Please Enter again : ";
            cin>>spot;
        }
	    bookSpot(level,spot,1);
		cin.ignore();
		showtik();  
	}
	
	
void bookSpot(int l,int s,bool t){ // Make array true/false for any new booking or paying

    switch(l){
    case 1 : (*(level1+(s-1))) = t;break;
    case 2 : (*(level2+(s-1))) =t;break;
    case 3 : (*(level3+(s-1)))= t;break;
    }
}
    
void ShowServices(){  // function select type of vehicle to display the types of services for each 
	
    cout <<" Type of Vehicle :" << endl
    	<<setw (16) << left << "  1. Car" << endl
		<<setw (16) << left << "  2. Motor Cycle" << endl;    	
	cin >> *ptr_veh;
    cout << "============================\n";
   	while ( *ptr_veh > 2 || *ptr_veh < 1){ // just in case if someone enter more than 1 or 2
	Sleep(1 * 1000);
	cout << "Please Select A Valid Option:  (exit 0)" ;
	cin >>  *ptr_veh; 
	exit(0);
	}
	if (*ptr_veh == 1)
    get_service_car();
	else if(*ptr_veh == 2)
    get_service_Motor();
}
    
void get_service_car(){ // Header function for car services 

 	char CarServOption;
    int CarServType;
    int servpay2;
    int u;
 	cout << endl;
 	Sleep(2 * 1000); // stop the program for 2 seconds.
 	cout <<" --- We Provide types of Servises For Cars---\n";
 	cout <<" --  Press Y to display the types of services  -- Y/N " << endl;
 	cin >> CarServOption;
 	
 	while(CarServOption!='N' && CarServOption !='n' && CarServOption !='Y' && CarServOption !='y'){
	Sleep(1 * 1000); // stop the program for 2 seconds.
	cout<< " --- invalid input , please enter Y or N!! --- " << endl;
	cin >> CarServOption;
    }
    
 	Sleep(2 * 1000); // stop the program for 2 seconds.
 	if( CarServOption =='Y'|| CarServOption =='y'){
 		cout << "\n --- Please Select Type of service: --- " << endl << endl // prompt user to select vehicle type.
    	<< setw(16) << left << " 1. Wash" << "RM " << CarServicePrice[0] << endl
    	<< setw(16) << left << " 2. Vacuum" << "RM " << CarServicePrice[1] << endl;
    	cout <<"\n ** Your  type of Service ** : ";
        cin >> CarServType;
        cout << " \n >> Services Created Successfully !!! " << endl;
        cout << "-----------------------------------------" <<endl;
        if(CarServType == 1)
        cout << "<<Type of Services : Waching  " << endl;
		else if (CarServType == 2)
		cout << "<<Type of Services : Vacuuming " << endl;
		Sleep(1 * 1000); // stop the program for 2 seconds.
		switch(CarServType){
 	    	case 1 : cout<< "<<Price: " << " 15 RM" << endl; break;
	    	case 2 : cout<< "<<Price: " << "10 RM" << endl; break;
    	}
    	
    	cout << "..Processing to pay ....." << endl;
        cout << "<<Enter the amount :"<< endl;
        cin >> servpay2;
        
        while(servpay2 <10 || servpay2 <15){
        cout <<" Pls enter the correct amount !!" << endl;
		cin >> servpay2;
	    }
		
        if( CarServType == 1)
        u = servpay2 - 15; // the process 
        else if(CarServType == 2)
        u = servpay2 - 10;
        cout << "// here is your change .." << u << endl;
        cout << "============================\n";
  
    }
}
    
void get_service_Motor(){
	
	int MotorServType;
	int servpay1;
	const int MotorServicePrice = 10;       // The service provid it for motor bike only wash


	    Sleep(2 * 1000); // stop the program for 2 seconds.
	
 	    cout <<" -- We Provide  Servise For MotorCycle :\n";
 		cout << "-- Please Select Type of service:  " << endl << endl // prompt user to select vehicle type.
    	<< setw(16) << left << " 1. Wash" << "RM " << MotorServicePrice << endl;
    	cout <<" ** Your  type of Service ** : ";
        cin >> MotorServType;
        cout << " >> Services Created Successfully !!! " << endl;
        cout << "-----------------------------------------" <<endl;
        cout << "<<Type of Services : Waching  " << endl;
        cout << "<<Price: " << "10 RM" << endl;
        cout << "..Processing to pay ....." << endl;
        cout << "<<Enter the amount :"<< endl;
        cin >> servpay1;
        while(servpay1 <10){
        	cout<<" Pls enter the correct amount !!" << endl;
        	cin >> servpay1;
		}
        int l = servpay1 - MotorServicePrice; // the process 
        cout << "..here is your change .." << l << endl;
        cout << "============================\n";
}
    
void availableSpot(int level){ // Print the available spot diagram

    cout<<"\nAvailable Parking Spots on Level "<<level<<endl;
    cout<<"====================================="<<endl;
	switch(level){
     	case 1 : showMatrics(level1); break;
		case 2 : showMatrics(level2); break;
		case 3 : showMatrics(level3); break;
	}
}    

void showtik(){
	
	int t; //store the amount for change 
	cout <<endl;	
    cout<<" ** Create Ticket Successfully !!! "<< endl;
    Sleep(1 * 1000); // stop the program for one second.
	cout<<"\n--------------------------------------\n";
	cout << endl <<  "Here Is Your Receipt:" << endl;
	Sleep(1 * 1000); // stop the program for one second.
    srand(time(NULL));
	cout<<"<<Your ticket number : "<<rand() % 9999<<endl;
	calcdate(); // call function to generate service id, time, and date
	cout <<  endl << setw(15) << left <<  "<<Date " << ": " << week[s + 1] << ", " << mon_char[mon - 1] << " " << day + 1 << "th" << " " << year << endl;
	Sleep(1 * 1000); // stop the program for one second.
	switch( *ptr_veh){
 	case 1 : cout<< "<<Vehicle Type : " << "Car" << endl; break;
	case 2 : cout<< "<<Vehicle Type : " << "Motor Cycle" << endl; break;
    }
    Sleep(1 * 1000); // stop the program for one second.
	cout<< "<<Level number " << " : " <<level <<endl;
	Sleep(1 * 1000); // stop the program for one second.
	cout<< "<<Spot number  " << " : "  <<spot <<endl;
 	Sleep(1 * 1000); // stop the program for one second.
 	cout << "<<Number Of Hours " << " : "  << hours;
 	Sleep(1 * 1000); // stop the program for one second.
 	calctotal();  
    cout <<endl <<"<< Total " << ": " << total <<endl ;
   
    cout<<"\nEnter Your ammount (RM) : "; 
    cin >> t;
    while(t< total )
    {
    	cout <<"....  Pls Enter a Valid Price !!!" << endl;
    	 cin >> t;
	}
    int k = t-total;
    cout<<"Your Change is : "<< k <<endl;
    cout<<" Thank You !!"<<endl;
}
/*defs.h code*/
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

