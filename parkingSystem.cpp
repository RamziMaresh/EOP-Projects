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


