//finalprojectzi.cpp Final Project for C++
//Budget Buddy

#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>

//function prototypes
void newMonth();
void editExpenses();
void addExpenses ();
void displayMonth();
void displayAverages();

using namespace std;

int main() 

{
	cout<<"\t WELCOME TO BUDGET BUDDY!"<<endl<<endl;
	int menuOption=0;
	do //begin Loop
	{	
		//Display options and get user input
		cout<<" \t \t "<<"Main Menu"<<endl<<endl;
		cout<<"1: Start a New Month ***(New Users Start Here)***"<<endl;
		cout<<"2: Edit Expenses"<<endl;
		cout<<"3: Add Expenses to a Month"<<endl;
		cout<<"4: Display Overview Of Month"<<endl;
		cout<<"5: Display Averages and Totals"<<endl;
		cout<<"0: End Program"<<endl<<endl;
		cout<<"Enter Menu Option: ";
		cin>>menuOption;
		cout<<endl;
	
	
	//Call Appropriate Function
		if(menuOption==1)
			newMonth();
		
		else if (menuOption==2)
			editExpenses();
		
		else if (menuOption==3)
			addExpenses();
		
		else if (menuOption==4)
			displayMonth();
			
		else if (menuOption==5)
			displayAverages();
		
	}while(menuOption!=0); //end loop
	
	return 0;

}//end of main function

//********function details********
void newMonth()
{
	//Add a new month as txt file to be edited and potentially referenced back to
	double curBalance=0.0;
	int month=0;
	string year="";
	string fileNameMonthYearFV=""; 
	string expense = "";
	double dollarAmount=0.0;
	char fixedVaried=' ';
	char newExpense =' ';
	//declare Arrays
	string monthName[12]={"January","February","March","April", "May","June","July","August","September","October","November","December"};
	
	
	char titheSave=' ';
	double titheSaveAmount=0.0;
	double titheSaveRate=0.0;
		 
		
	//Establish File Name
	
	
	
	cout<<"Are these your Fixed Expenses or Varying Expenses(F for Fixed or V for Varying)(0 to end)?";
	cin>>fixedVaried;
	cout<<endl;
	
	fixedVaried=toupper(fixedVaried);
	
	while(fixedVaried!='0')
	{
		if(fixedVaried=='F')
		{
			fileNameMonthYearFV="fixedExpenses.txt";
			//Writes File to Sequential Access file
					
			ofstream outMonthYear;
			outMonthYear.open(fileNameMonthYearFV);
			
			//Verify Opened
			
			if (outMonthYear.is_open())
			{
				//Get expense name and Dollar Amount
				cout<<"Enter Expense Name as One Word(-1 to stop): ";
				cin>>expense;
			
				do   //begin Loop
				{
					cout<<"Enter Dollar Amount:$ ";
					cin>>dollarAmount;
					cin.ignore(100, '\n');
					cout<<endl;

					//write to txt file
					outMonthYear<<expense<<'#'<<dollarAmount;
					cout<<"Would you like to enter another expense(Y or N)?";
					cin>>newExpense;
					newExpense=toupper(newExpense);
					if(newExpense=='Y')
					{
					outMonthYear<<endl;
					cout<<"Enter Expense Name as One Word(-1 to stop): ";
					cin>>expense;
					}else if(newExpense=='N')
					{
						expense="-1";
					}else {
						cout<<"Invalid Input(Y or N)";
						cin>>newExpense;
						newExpense=toupper(newExpense);
					}
					
				}while(expense!="-1"); //end loop
				
				outMonthYear.close();
				
			
				}//end while
				
				cout<<endl<<"You've Entered Fixed Expenses!"<<endl<<endl;
				expense="-1";
				fixedVaried='0';
				
		}
	
		else if (fixedVaried=='V')
		{
			//Get Variable from user
			cout<<"Enter Current Balance:$ ";
			cin>>curBalance;
			cout<<endl<<endl;
			
			//get optional variable info
			cout<<"Would you like to calculate a Percentage of"<<endl;
			cout<<"your balance or income to go towards tithes"<<endl;
			cout<<"or saving?(Y or N): ";
			cin>>titheSave;
			titheSave=toupper(titheSave);
			
			if(titheSave=='Y')
			{
				cout<<"Enter Percentage(1-100): ";
				cin>>titheSaveRate;
				//calculate percent
				titheSaveAmount=curBalance * (titheSaveRate/100);
				//display expense and amount
				cout<<endl<<"***Recommended amount to add as an Expense:$ "<<titheSaveAmount<<endl<<endl;
			}
			else if(titheSave=='N')
			{
				cout<<"No Problem!"<<endl<<endl;
			}
			else
			{
				cout<<"Invalid Input (Y or N): ";
				cin>>titheSave;
			}
			
			//enter month year and Fixed 
			//Display error message if not valid
			//This names the txt file
			cout<<"Enter Month (1-12)(-1 to return to main menu): ";
			cin>>month;
			cout<<endl;

			while (month!=-1)
			{
				if (month<=12 && month>=1)
				{
					cout<<"Enter 2 Digit Year(Example 2016 = 16): ";
					cin>>year;
					cout<<endl;
				
					while(year.length()!=2)
					{
						cout<<"Invalid Length. Enter 2 Digit Year";
						cin>>year;
						cout<<endl;
					}
					
					fileNameMonthYearFV=monthName[month-1];
					fileNameMonthYearFV+=year;
					fileNameMonthYearFV+=fixedVaried;
					fileNameMonthYearFV+=".txt";
				
				}
				else if(month!=-1)
				{
					cout<<"Invalid Month"<<endl;
				}//end if
				
				//Writes File to Sequential Access file
				ofstream outMonthYear;
				outMonthYear.open(fileNameMonthYearFV);
		
				//Verify Opened
		
				if (outMonthYear.is_open())
				{
					outMonthYear<<"Balance"<<'#'<<curBalance<<endl;
					
					//Get expense name and Dollar Amount
					cout<<"Enter Expense Name as One Word(-1 to stop): ";
					cin>>expense;
				
					do   //begin Loop
					{
						
						cout<<"Enter Dollar Amount:$ ";
						cin>>dollarAmount;
						cin.ignore(100, '\n');
						cout<<endl;
						
						outMonthYear<<expense<<'#'<<dollarAmount;
						cout<<"Would you like to enter another expense(Y or N)?";
						cin>>newExpense;
						newExpense=toupper(newExpense);
						
						if(newExpense=='Y')
						{
						outMonthYear<<endl;
						cout<<"Enter Expense Name as One Word(-1 to stop): ";
						cin>>expense;
						
						}else if(newExpense=='N')
						{
							expense="-1";
							
						}else 
						{
							cout<<"Invalid Expense Name"<<endl;
							cout<<"Enter New Expense(-1 to stop): ";
							cin>>expense;
						}

					}while(expense!="-1"); //end loop

					outMonthYear.close();
				
				}//end if
			
				cout<<"Enter Month (1-12)(-1 to return to main menu): ";
				cin>>month;
				cout<<endl;
			
			}//end while
			fixedVaried='0';
		}//end if
	
		else 
		{
			cout<<"Invalid Expense Type"<<endl;
			cout<<"Enter Fixed or Varying (F or V)(0 to end)";
			cin>>fixedVaried;
			fixedVaried=toupper(fixedVaried);
			cout<<endl;
		}//end if
	}//end while
}//End of newMonth Function	

void editExpenses()
{
	char continueYN =' ';
	
	cout<<"\t *****WARNING******"<<endl;
	cout<<"*By editing a month you will lose all previous data*"<<endl;
	cout<<"You may return to the Main Menu and review"<<endl;
	cout<<"Would you like to continue?(Y or N)";
	cin>>continueYN;
	continueYN=toupper(continueYN);
	cout<<endl;
	
	if (continueYN=='Y')
	
		newMonth();
		
	else if(continueYN!='N')
	{
		cout<<"Invalid Selection"<<endl;
		cout<<"Would you like to Continue?(Y or N)";
		cin>>continueYN;
		continueYN=toupper(continueYN);
	}
	
	//returns to main menu
}//end of editExpenses Function


//Adds expense to txt file instead of changes entirely
void addExpenses()
{
	//declare variables
	int month=0;
	string year="";
	string fileNameMonthYearFV=""; 
	string expense = "";
	double dollarAmount=0.0;
	char fixedVaried=' ';
	char titheSave=' ';
	double titheSaveAmount=0.0;
	double titheSaveRate=0.0;
	double curBalance=0.0;
	
	//declare Arrays
	string monthName[12]={"January","February","March","April", "May","June","July","August","September","October","November","December"};
	//string monthNum[12]={"1","2","3","4","5","6","7","8","9","10","11","12"};
	
	
	
	//Establish File Name
	//enter month year and Fixed 
	//Display error message if not valid
	
	cout<<"Are these your Fixed Expenses or Varying Expenses(F for Fixed or V for Varying)(-1 to end)?";
	cin>>fixedVaried;
	cout<<endl;
	
	fixedVaried=toupper(fixedVaried);
	
	cout<<"Enter Month (1-12)(-1 to return to main menu): ";
	cin>>month;
	cout<<endl;
		
	while (month!=-1)
	{
		if (month<=12 && month>=1)
		{
			
			if(fixedVaried=='F')
			{
				fileNameMonthYearFV="fixedExpenses.txt";
				
			
			}else if (fixedVaried=='V')
			{
				fileNameMonthYearFV+=fixedVaried;
				fileNameMonthYearFV+=".txt";

			
				cout<<"Enter 2 Digit Year(Example 2016 = 16): ";
				cin>>year;
				cout<<endl;
			
				while(year.length()!=2)
				{
					cout<<"Invalid Length. Enter 2 Digit Year";
					cin>>year;
					cout<<endl;
				}

				fileNameMonthYearFV=monthName[month-1];
			
				fileNameMonthYearFV+=year;
			
			
			}
			
			else 
			{
				cout<<"Invalid Expense Type"<<endl;
				cout<<"Enter Fixed or Varying (F or V)";
				cin>>fixedVaried;
				cout<<endl;			
			}
		}
		
		else if(month!=-1)
		{
			cout<<"Invalid Month"<<endl;
		}//end if
		
		ofstream outMonthYear;
		outMonthYear.open(fileNameMonthYearFV, ios::app);
		
		if (outMonthYear.is_open())
			{
				//Get expense name and Dollar Amount
				cout<<"Enter Expense Name as One Word(-1 to stop): ";
				cin>>expense;
				
				do   //begin Loop
				{
					cout<<endl;
					cout<<"Enter Dollar Amount:$ ";
					cin>>dollarAmount;
					cin.ignore(100, '\n');

					//write to txt file
					outMonthYear<<endl<<expense<<'#'<<dollarAmount;
					
					//Get expense name and Dollar Amount
					cout<<"Enter Expense Name as One Word(-1 to stop): ";
					cin>>expense;
				}while(expense!="-1"); //end loop
			
			outMonthYear.close();
			
			}//end if
			cout<<"Enter Month (1-12)(-1 to return to main menu): ";
			cin>>month;
			cout<<endl;
			
	}//end while
}//end of addExpenses Function

void displayMonth()
{
	//declare variables
	int month=0;
	string year="";
	string fileNameMonthYearFV=""; 
	string expense = "";
	char fixedVaried=' ';
	double amount=0.0;
	double totAmount=0.0;
	double curBalance=0.0;
	double totBalance=0.0;
	string balanceName="";
	//declare Arrays
	string monthName[12]={"January","February","March","April", "May","June","July","August","September","October","November","December"};
	//string monthNum[12]={"1","2","3","4","5","6","7","8","9","10","11","12"};
	

	cout<<"******NOTE******"<<endl;
	cout<<"You can review both Fixed and Varied Expenses"<<endl;
	cout<<"If you want to review them together, go to Main Menu"<<endl;
	cout<<"and select option 5"<<endl<<endl<<endl;;
	//get Fixed or Varied
	cout<<"Would you like to view your Fixed Expenses or Varying Expenses(F for Fixed or V for Varying)(-1 to end)?";
	cin>>fixedVaried;
	cout<<endl;
	
	fixedVaried=toupper(fixedVaried);
	
	do
	{
	if(fixedVaried=='F')
	{
		fileNameMonthYearFV="fixedExpenses.txt";
		
		ifstream inFixedExpenses;
		inFixedExpenses.open(fileNameMonthYearFV, ios::in);
		
		
		if(inFixedExpenses.is_open())
		{
	
			cout<<"EXPENSES"<<endl;
			cout<<"Name \t \t \t Expense"<<endl;
		
			while(!inFixedExpenses.eof())
			{
				getline(inFixedExpenses,expense,'#');
				inFixedExpenses>>amount;
				totAmount+=amount;
			
				if(expense.length()<=7)
				{
					cout<<expense<<" \t \t \t "<<amount;
				}
					
				else if (expense.length()<=14)
				{
					cout<<expense<<" \t \t "<<amount;
				}
					
				else if (expense.length()<=21)
				{
					cout<<expense<<" \t "<<amount;
				}
				else if (expense=="\n")
				{
					cout<<"error";
				}
				
			}//end while
			
				
			cout<<endl<<endl<<"Total Expenses:$\t"<<totAmount<<endl;
			totAmount=0;
			

			inFixedExpenses.close();
		}
			fixedVaried='0';
		
		}else if (fixedVaried=='V')
		{

				//Establish File Name
				//enter month year and Fixed 
				//Display error message if not valid
				//This is determined by the user
			cout<<"Enter Month (1-12)(-1 to return to main menu): ";
			cin>>month;
			cout<<endl;
				
			while (month!=-1)
			{
				if (month<=12 && month>=1)
				{
					cout<<"Enter 2 Digit Year(Example 2016 = 16): ";
					cin>>year;
					cout<<endl;
					
				
					
					while(year.length()!=2)
					{
						cout<<"Invalid Length. Enter 2 Digit Year";
						cin>>year;
						cout<<endl;
					}
					
					fileNameMonthYearFV=monthName[month-1];
					fileNameMonthYearFV+=year;
					
					fileNameMonthYearFV+=fixedVaried;
					fileNameMonthYearFV+=".txt"; 
					
					ifstream inMonthYear;
					inMonthYear.open(fileNameMonthYearFV, ios::in);
					
					if(inMonthYear.is_open())
					{
								getline(inMonthYear,balanceName, '#');
								inMonthYear>>curBalance;
								
							while(!inMonthYear.eof())
							{
								getline (inMonthYear, expense, '#');
								inMonthYear>>amount;
								
									if(expense.length()<=7)
									{
										cout<<expense<<" \t \t \t "<<amount;
									}
										
									else if (expense.length()<=14)
									{
										cout<<expense<<" \t \t "<<amount;
									}
										
									else if (expense.length()<=21)
									{
										cout<<expense<<" \t "<<amount;
									}
									else if (expense=="\n")
									{
										cout<<"error";
									}										
									//end if
									
									totAmount+= amount;
									
		
							}//end while
					
							cout<<endl<<endl<<"Total Expenses:$\t"<<totAmount<<endl<<endl;
							cout<<"Enter New Month(-1 to End): ";
							cin>>month;
							totAmount=0;
							
							
							inMonthYear.close();
							
					}//end if
					
				}else if(month!=-1)
				{
					cout<<"Invalid Month"<<endl;
					cout<<"Enter New Month: ";
					cin>>month;

				}
				
				}//end while
				
			
			
		}else
		{
			cout<<"Invalid Expense Type"<<endl;
			cout<<"Enter Fixed or Varying (F or V): ";
			cin>>fixedVaried;
			fixedVaried=toupper(fixedVaried);
			cout<<endl;
		}//end if
		
	}while(month!=-1);
}//end displayMonth function


//Function to Calculate and Display totals and averages
void displayAverages()
{
	//declare variables
	int month=0;
	string year="";
	string fileNameMonthYearFV=""; 
	string expense = "";
	char fixedVaried=' ';
	double amount=0.0;
	double totAmount=0.0;
	double accTotal=0.0;
	double avgExpense=0.0;
	double avgRemain=0.0;
	int counter=0;
	double curBalance=0.0;
	double totBalance=0.0;
	double remBal=0.0;
	double totRemBal=0.0;
	double accTotBal=0.0;
	char includeFixed=' ';
	string balanceName="";
	
	
	//declare Arrays
	string monthName[12]={"January","February","March","April", "May","June","July","August","September","October","November","December"};
	//string monthNum[12]={"1","2","3","4","5","6","7","8","9","10","11","12"};
	 
	cout<<"You will need to look up a month to start your average."<<endl;
	cout<<"You will need to add additional months after that."<<endl;
	cout<<"***Note***"<<endl;
	
	//Establish File Name
	
		//enter month year and Fixed 
		//Display error message if not valid
		cout<<"Enter Month (1-12)(-1 to return to end months added): ";
		cin>>month;
		cout<<endl;
		
	while (month!=-1)
	{
		if (month<=12 && month>=1)
		{
			cout<<"Enter 2 Digit Year(Example 2016 = 16): ";
			cin>>year;
			cout<<endl;
			
			
			
			while(year.length()!=2)
			{
				cout<<"Invalid Length. Enter 2 Digit Year";
				cin>>year;
				cout<<endl;
			}
			
			cout<<"Would you like to include your Fixed Expenses? ";
			cin>>includeFixed;
			includeFixed=toupper(includeFixed);
			
							
		}
		else if(month!=-1)
		{
			cout<<"Invalid Month"<<endl;
			cout<<"Enter New Month(1-12): ";
			cin>>month;
		}//end if
		
		if(includeFixed=='Y')
		{
			ifstream inFixedExpenses;
			inFixedExpenses.open("fixedExpenses.txt", ios::in);
			
			if(inFixedExpenses.is_open())
			{
				cout<<"FIXED EXPENSES"<<endl;
				cout<<"Name \t \t \t Expense"<<endl;

				while(!inFixedExpenses.eof())
				{
					getline(inFixedExpenses, expense, '#');
					inFixedExpenses>>amount;
					
					if(expense.length() <=7)
						
						cout<<expense<<" \t \t \t "<<amount;
							
					else if (expense.length()<=14)
								
						cout<<expense<<" \t \t "<<amount;
								
					else if (expense.length()<=21)
								
						cout<<expense<<" \t "<<amount;
							
					else 

						cout<<expense<<amount;
								
					//end if
							
					totAmount+=amount;
								
				}//end while
			
				inFixedExpenses.close();

			}else
			{
				cout<<"Fixed Unable to Open"<<endl;
			}
		}
			
		
			cout<<endl<<"VARIED EXPENSES"<<endl;
			
			fixedVaried='V';
			
			fileNameMonthYearFV=monthName[month-1];
			fileNameMonthYearFV+=year;
			fileNameMonthYearFV+=fixedVaried;
			fileNameMonthYearFV+=".txt";

			
			ifstream inMonthYear;
			inMonthYear.open(fileNameMonthYearFV, ios::in);
		
			if(inMonthYear.is_open())
			{
				getline(inMonthYear,balanceName, '#');
				inMonthYear>>curBalance;
				
				while(!inMonthYear.eof())
				{
					getline (inMonthYear, expense, '#');
					inMonthYear>>amount;
					
						if(expense.length()<=7)
						{
							cout<<expense<<" \t \t \t "<<amount;
						}
							
						else if (expense.length()<=14)
						{
							cout<<expense<<" \t \t "<<amount;
						}
							
						else if (expense.length()<=21)
						{
							cout<<expense<<" \t "<<amount;
						}
						else if (expense=="\n")
						{
							cout<<"error";
						}										
						//end if
						
						totAmount+= amount;
						

				}//end while						
					inMonthYear.close();
					remBal=curBalance-totAmount;
					cout<<endl<<"Total Expense:$ \t "<<totAmount;
					cout<<endl<<"Total Balance:$ \t "<<curBalance;
					cout<<endl<<"Remaing:$ \t\t "<<remBal;			
			}else
			{
				cout<<"File could not open"<<endl;
				counter-=1;
			}// end if
			
				cout<<endl<<endl;
	
		//enter month year and Fixed 
		//Display error message if not valid
		cout<<"Enter Month (1-12)(-1 to end Months and Calculate Total and Average): ";
		cin>>month;
		cout<<endl;
	
		//calculate averages and totals	
		totBalance+=curBalance;
		accTotal+=totAmount;
		totRemBal+=remBal;
		counter+=1;
		totAmount=0;
	}
	//calculate and display averages and totals
	
	avgExpense=accTotal/counter;
	avgRemain=totRemBal/counter;
	accTotBal=totBalance-accTotal;
	
	//display totals
	cout<<"Average Expenses Per Month:$ "<<avgExpense<<endl;
	cout<<fixed<<setprecision(2);
	cout<<"Average Remaining Per Month:$ "<<avgRemain<<endl<<endl;
	cout<<fixed<<setprecision(2);
	cout<<endl<<"Accumulative Total Expenses:$ "<<accTotal<<endl;
	cout<<"Your Balance Before Expenses:$ "<<totBalance<<endl;
	cout<<"Your total Remaining Balance:$ "<<totRemBal<<endl<<endl;
}//End display averages fuction
