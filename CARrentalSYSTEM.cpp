#include<iostream>
#include<fstream>
#include<unistd.h>
#include<iomanip>
#include<ctime>
using namespace std;

class customer
{
	protected:
		string customer_name;
		int car_model;
		string car_number;
};
//RENT CLASS
//INHERITED CLASS FROM CUSTOMER CLASS i.e IT ACCES DATA OF CLASS CUSTOMER.
class rent:public customer
{
	private:
		//additional data of its own class
		int number_of_days;
		int rent_fee;
		char str[200]; //CHARACTER ARRAY IN WHICH TO STORE THE DATA WITH MAXIMUM NUMBER OF CHARACTER TO EXTRACT.
	public:
	    rent();
		void welcome();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount();
		void invoiceRecord();
			
};

//CONSTRUCTYOR 
rent::rent()
{
	number_of_days=0;
	rent_fee=0;
}

void rent::welcome()
{
      ifstream inputFile("welcome.txt");
	  //DISPLAYING WELCOME ASSCII IMAGE TEXT ON OUTPUT SCREEN 
	  if(!inputFile)
	  {
	  	cout<<"\n can't open file!";
	  }
	  char str[1000];
	  while(inputFile)
	  {
	  	inputFile.getline(str,1000);//READING TEXT FILE.
	  	if(inputFile)
	  	{
	  		cout<<str<<endl;
	  	   	
		}
      }
	  inputFile.close();
	  sleep(1);//function used for waiting screen for 1n seconds.
	  cout<<"\n\t\t\t\t starting the program...."<<endl;
	  sleep(1);
	  cout<<"\n\t\t\t\t loading..."<<endl;
	  sleep(1);
	  system("CLS");//clear screen.                            	
}

void rent::fileReader(char carFile[20])
{
	ifstream inputFile;
	inputFile.open(carFile);//displaying details of model a.
	if(!inputFile)
	{
		cout<<"\n OOPS!....File not found.";
	}
	while(inputFile)
	{
		inputFile.getline(str,200);
		if(inputFile)
		{
			cout<<str<<endl;
		}
	}
}

void rent::data()
{
	cout<<"\n\t\t\t Enter your name :";
	cin>>customer_name;
	cout<<endl;
	do
	{
		//choice for selecting car model.
		cout<<"\t\t\t -------------------------------------------------------------"<<endl;
		cout<<"\t\t\t -----------------choose a car from beloe option--------------"<<endl;
		cout<<"\t\t\t ------select the number of model while choosing car model----"<<endl;
		cout<<"\t\t\t1. TATA Punch 2024."<<endl;
	    cout<<"\t\t\t2. Suzuki Baleno 2024."<<endl;
		cout<<"\t\t\t3. Mahindra XUV7OO 2024."<<endl;
		cout<<endl;	
		cout<<"\t\t\t---------------------------------------------------------------"<<endl;
		cout<<"\n \t\t\tchoose the model you want to book:";
		cin>>car_model;
		cout<<endl;
		
	if (car_model >= 1 && car_model <= 3)
		{
		
		switch(car_model)
		{
			case 1:
				system("CLS");
			    cout<<"\n You have choose TATA Punch 2023 Model.";
			    fileReader("TATA.txt");
			    sleep(2);
			    break;
			
			case 2:
				system("CLS");
			    cout<<"\n You have choose Suzuki Baleno 2024 Model.";
			    fileReader("Suzuki.txt");
			    sleep(2);
			    break;
			    
			case 3:
				system("CLS");
			    cout<<"\n You have choose Mahindra XUV7OO 2024 Model.";
			    fileReader("Mahindra.txt");
			    sleep(2);
			    break;
			   
			   
			          
		}
		break;
	}else
	{
		cout<<"\n OOPS! invalid car Model! please try again."; 
	}
		
	}while(true);
	
	cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\n \t\t\t Please provide following information:";
	
	//getting user data related to rental systeme.
	cout<<"\n Please select car number:";
	cin>>car_number;
	cout<<"\n Number of days you want to rent the car:";
	cin>>number_of_days;
	cout<<endl;
	
	
}

void rent::invoiceAmount()
{
	sleep(1);
	system("CLS");
	cout<<"\n Calculating Rent..Please wait....";
	sleep(1);
	if(car_model==1)
	{
		rent_fee=number_of_days*150;//line24
	}
	if(car_model==2)
	{
		rent_fee=number_of_days*160;//line24
	}
	if(car_model==3)
	{
		rent_fee=number_of_days*300;//line24
	}
	
}

void rent::invoiceRecord(){
	time_t now = time(0);
    struct tm *local_time = localtime(&now);

    // Set the time zone to Indian Standard Time (IST)
   
    //chat gpt code for time zone.
   cout << "\n \t\t\t-------------CAR RENTAL - CUSTOMER INVOICE------------" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t | Invoice no.              |          #1001           |" << endl; // Automatically generated.
    cout << "\t\t\t | Customer Name.           |          " << setw(10) << customer_name << "      |" << endl;
    cout << "\t\t\t | Car Model                |          " << setw(10) << car_model << "      |" << endl;
    cout << "\t\t\t | Car No.                  |          " << setw(10) << car_number << "      |" << endl;
    cout << "\t\t\t | Number Of Days.          |          " << setw(10) << number_of_days << "      |" << endl; 
    cout << "\t\t\t | Rental Amount.           |          " << setw(10) << rent_fee << "      |" << endl; // Line 22

    // Calculate and display caution money (assuming a fixed amount for demonstration)
    float caution_money = 100; // Example: fixed caution money amount
    cout << "\t\t\t | Caution Money.           |          " << setw(10) << caution_money << "      |" << endl;

    // Calculate total rental amount including caution money
    float total_amount = rent_fee + caution_money;
    cout << "\t\t\t |_____________________________________________________|" << endl;
    cout << "\t\t\t | Total rental Amount.     |      R" << setw(6) << total_amount << "             |" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\n NOTE: THIS IS COMPUTER GENERATED INVOICE." << endl;



    
    system("PAUSE");
    system("CLS");
    fileReader("thankYou.txt");
    
}
int main()
{
	rent r;
	r.welcome();
	r.data();
	r.invoiceAmount();
	r.invoiceRecord();
	return 0;
}














