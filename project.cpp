#include<iostream>
#include<fstream>
#include<conio.h>
#include <bits/stdc++.h>
#include<cstring>
#include<cstdio>
#include<stdio.h>
using namespace std;
class User{
	private:
		string Mname,Cname,Uname;
	int x;
	public:
		User(string name,int n){
			Uname=name;		
			x=n;
			assign();
		}
		
	void	assign()
		{
			if(x==1)
			{
				Customername();
			}
			else if(x==2)
			{
				Managername();
			}
		}
	string Customername(){
	Cname=Uname;
	return Cname;
	}
	string Managername(){
	Mname=Uname;
	return Mname;
	}
	void feedback()
	{
		cout<<"Customer give the feedback";
		cout<<"\nManager view the feedback";
	}
	
};
class Customer:public User{
	private:
		int opt;
		public:
			
			Customer(string name):User(name,1)
			{entry();	}
			void entry(){
				cout<<"\nHello Mr/Ms "<<Customername();
				display();
			}
			void display(){
			do{
			cout<<endl<<"Press"<<endl;
			cout<<"1.View Order/invoice"<<endl; 
			cout<<"2.Give FeedBack"<<endl; 
			cout<<"3.Exit"<<endl;
			cout<<"-->";
			cin>>opt;}
			while(opt!=1 && opt!=2 && opt!=3);
			switch(opt)
			{
				case 1:
					{
				viewOrder();
					display();
					break;}
				case 2:
					feedback();
					display();
					break;
				case 3:
					exit(0);
					break;
				default:
					cout<<"Invalid option";
					display();
					break;
			}}
			void viewOrder()
			{
					fstream Cbill;
					string C1;
					C1=Customername()+".txt";
					Cbill.open(C1,ios::in);
					if (!Cbill)
					{
						cout<<"You have not ordered yet";
					}
					else{
					string line;
					while(!Cbill.eof())
					{
						getline(Cbill,line);
						cout<<line<<endl;
					}}
					Cbill.close();
			}
			void feedback()
			{
				char feedback[100];
	int a,b,c,d,e,i,f;
	cout<<"Please enter your feedback : ";
	cout<<"\nRate the following question";
	cout<<"\nPlease press \n4->Excellent\n3->Good\n2->Fair\n1->poor";
	cout<<"\nQuality of food : ";
	cin>>a;
	cout<<"Portion size : ";
	cin>>b;
	cout<<"Ease of ordering : ";
	cin>>c;
	cout<<"Service : ";
	cin>>d;
	cout<<"Cleanliness : ";
	cin>>e;
	cout<<"Overall Value : ";
	cin>>f;
	cout<<"Do you want to give any suggestions : ";
	cin.getline(feedback,100);
	fstream file;
	file.open("feedback_1.text",ios::out | ios::app);
	if (!file)
	{
		cout<<"File not created";
	}
	else
	{
		cout<<"File created successfully!";
		file<<"FEEDBACK from "<<Customername();
		file<<"\nQuality of food  : ";
    	for(i=0;i<a;i++)
    	{
    		file<<"*";
		}
    	file<<"\nPortion size     : ";
	    for(i=0;i<b;i++)
    	{
    		file<<"*";
		}
    	file<<"\nEase of ordering : ";
    	for(i=0;i<c;i++)
    	{
    		file<<"*";
		}
    	file<<"\nService          : ";
    	for(i=0;i<d;i++)
    	{
    		file<<"*";
		}
    	file<<"\nCleanliness      : ";
    	for(i=0;i<e;i++)
    	{
    		file<<"*";
		}
    	file<<"\nOverall Value    : ";
    	for(i=0;i<f;i++)
    	{
    		file<<"*";
		}
		fflush(stdin);
    	cout<<"\nSuggestions      : ";
	 	file<<feedback<<endl;
		file.close();
	}
}
};
class Reservation
{
	private:
		int table[5][3];
		int res;
		int Res_no[5][3];
		int y;
	public:
		Reservation()
		{
			int k,l,m=1;
			for(k=1;k<5;k++)
			{
				for(l=1;l<3;l++)
				{
					table[k][l]=0;
				}
			}
			for(k=1;k<5;k++)
			{
				for(l=1;l<3;l++)
				{
					Res_no[k][l]=m;
					m++;
				}
			}
		}
		int reservation()
		{
			system("cls");
			int i,j,count;
			cout<<"How many seats table do you want to reserve?\n-->";
		    cin>>res;
		    count=0;
		    for(i=1;i<5;i++)
		    {
		    	for(j=1;j<3;j++)
		    	{
		    		if(((res/2)<i)||((res/2==4)&&(i==4)))
		    		{
		    			if(table[i][j]==0)
		    			{
		    				table[i][j]=1;
		    				count=1;
		    				break;
						}
					}
				}
				if(count==1)
				{
					cout<<"\nYour table has been reserved!";
					cout<<"\n_____________";
					cout<<"\nYour Reserved table number is : "<<Res_no[i][j];
					cout<<"\n_____________";
					y=1;
					break;
				}
			}
			if(count==0)
			{
				cout<<"\nSorry! Your table cannot be reserved!";
				y=2;
			}
			cout<<"\nEnter any key to continue!";
			getch();
			return y;
		}
		int Reservation_chart()
		{
			system("cls");
			int i,j;
			for(i=0;i<10;i++)
			{
			    cout<<"*";
			}
			cout<<"Restaurant Reservation System  ";
			
			for(i=0;i<10;i++)
			{
			    cout<<"*";
			}
			
			cout<<endl<<"\n\n\t\tTABLES\t     Table no.1\t    Table no.2\n";
			for(i=1;i<5;i++)
			{
				cout<<"\n"<<i<<"-"<<setw(10)<<i*2<<"-seats table";
				for(j=1;j<3;j++)
				{
				    cout<<" || ";
					if(table[i][j]==1)
					cout<<"  Reserved  ";
					if(table[i][j]==0)
					cout<<"Not Reserved";
					else if(table[i][j]>1)
					cout<<"Wrong input";
				}
				cout<<"\n           _______________\n";
			}
			cout<<"\nEnter any key to continue!";
			getch();
		}
		int Cancel_Reservation()
		{
			system("cls");
		    int Can_res,i,j,count=0;
		    cout<<"Enter the table number you want to cancel reservation for :  ";
		    cin>>Can_res;
		    for(i=1;i<5;i++)
		    {
		    	for(j=1;j<3;j++)
		    	{
		    		if(Can_res==Res_no[i][j])
		    		{
		    			table[i][j]=0;
		    			count=1;
		    			break;
					}
				}
				if(count==1)
				{
					cout<<"The reservation of table number "<<Res_no[i][j]<<"\nHas been canceled successfully";
					break;
				}
			}
			cout<<"\nEnter any key to continue!";
			getch();
		}
};
struct menu{
	string menuItemC;
	double menuP;
	string menuN;
};
class Order{
private:
string MenuItemCode;
string ch;
int choice;
int quantity;
static int count; //bill
static int i;
string order[30];
int quan[100];
double p[100];
double total;
double discount;
double save;
const double gst;
double add;

struct menu menuList[16]={{"11",120,"Chicken Biryani"},
						{"12",10,"Naan"},
						{"13",350,"Chicken Handi"},
						{"14",50,"Kheer"},
						{"21",120,"Chicken Manchurian "},
						{"22",100,"Chicken Chowmein "},
						{"23",60,"Fried Rice"},
						{"24",50,"Bean Buns"},
						{"31",500,"Chicken Pizza"},
						{"32",400,"Alfredo Pasta"},
						{"33",600,"Lasagna"},
						{"34",100,"Gelato scoop"},
						{"41",50,"Coke"},
						{"42",30,"7up"},
						{"43",40,"Water"},
						{"44",40,"Juice"},
						};
																
float price;
protected:
	double totalf;
public:
Order():gst(0.05)
{

}
void getMenu(){

cout << "\n\t**MENU**\nWe offer different cuisines.\nPress: "<<endl;
cout << " 1 for Indian \n 2 for Chinese \n 3 for Italian \n 4 for Drinks \n 5.Deals \n-->";
cin >> choice;
int f=1;
do{
	string line;
switch (choice)
{
	
case 1:{
		ifstream file;
		file.open("India.txt");
		if(!file)
		cout<<"FILE NOT FOUND";
		else{
		while(!file.eof())
		{
			getline(file,line);
			cout<<line<<endl;
		}
		file.close();}
       f=1;
       order_place();
       break;}
       
       case 2:{
		ifstream file;
		file.open("China.txt");
		if(!file)
		cout<<"FILE NOT FOUND";
		else{
		
		while(!file.eof())
		{
			getline(file,line);
			cout<<line<<endl;
		}
		file.close();}
          f=1;
          order_place();
          break;}
       
       case 3:{
       	ifstream file;
		file.open("Italy.txt");
		if(!file)
		cout<<"FILE NOT FOUND";
		else{
		
		while(!file.eof())
		{
			getline(file,line);
			cout<<line<<endl;
		}
		file.close();}
          f=1;
          order_place();
          break;}
       
       case 4:
       	{
       		 	ifstream file;
		file.open("Drinks.txt");
		if(!file)
		cout<<"FILE NOT FOUND";
		else{
		
		while(!file.eof())
		{
			getline(file,line);
			cout<<line<<endl;
		}
		file.close();}
		
       f=1;
        order_place();
       break;}
       case 5:{
       		fstream deals;
       		deals.open("deals.txt", ios::in);
		char ch;
		while(deals>>noskipws>>ch)
        cout<<ch;
		deals.close();
       f=1;
       getMenu();
       break;}

		default:
		cout<<"Invalid choice"<<endl;
		f=0;
		break;}

		}while(f!=1);
}

void order_place()
{
int yn;
ch=to_string(choice);
do
{
cout << "Enter details of menu item you want to order: " << endl<<"1.Code: ";
cin >> MenuItemCode;
MenuItemCode=ch+MenuItemCode;
cout << "2.Quantity: ";
cin >> quantity;

checkPrice();
cout << "Do you want to order more items? \nPress \n1.Yes \n2.No:\n--> " << endl;
cin >> yn;
}while (yn==1);

//diff cusine
int opt;
while(1)
{
do{
cout << "\nDo you want to order from another cusines?: " << endl;
cout << "Press\n1.Yes\n2.No\n-->" << endl;
cin >> opt;
}while(opt!=1 && opt!=2);

if(opt==1)
{
getMenu();
}
else 
{
if(MenuItemCode=="11"||MenuItemCode=="12"||MenuItemCode=="13"||MenuItemCode=="14"){
	discount=0.05; }
	else
	discount=0;
cout << "\t\t\t\t**Your order has been placed.**" << endl;
bill();
break;
}
}
}
void checkPrice()
{
	
		for(int j=0;j<15;j++)
	    { 	
			if(MenuItemCode==menuList[j].menuItemC)	
    		{
    			order[i] = menuList[j].menuN;
    			quan[i]=quantity;
    			p[i]=menuList[j].menuP;
    			cout<<order[i]; //check
    			total=menuList[j].menuP*quantity+total;
    			i++;
    		break;}
}

}
void bill()
{
	cout<<"\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
  
   if (total>=1000)
   {
   	discount =0.30;
   }
   save=total*(discount);
   add=(total-save)*gst;
   totalf=total+add-save;
   float cash;
   fstream bill;
   bill.open("bill.txt",ios::out);
   if(!bill)
   {
   	cout<<"File not created";
   }
   else
   {
   	cout<<"File created successfully";
   	count++;
   

						cout << "\n\t\t\t\t ================================================"<<endl;
						cout <<  "\t\t\t\t                      Invoice"<<endl;
						cout <<   "\t\t\t\t ================================================"<<endl;
						cout << endl;
						cout << endl;
						int x=rand();
						
						cout << "\t\t\t\t  Bill No : "<<x<<"\t\tOrder : "<<count<<endl;
						cout << endl;
						cout << endl;
						cout<<"\t\t\t\t\t  Item name \t\tQuantity \t\tPrice"<<endl<<endl;
						for(int j=0; j<i; j++){	

						cout <<"\t\t\t\t\t  "<< order[j] << "\t\t"<<quan[j]<<"\t\t"<<p[j]<<endl;}
						if(discount==0.05)
							cout<<"\n\t\t\t\t  You Availed DEAL 1 discount\n"<<endl<<endl; 
							
						else if (discount==0.30)
						
							cout<<"\n\t\t\t\t  You Availed Deal 2 discount"<<endl<<endl; 
							
						cout<<"\n\t\t\t\t  YOUR TOTAL BILL IS Rs."<<total<<endl;
						cout<<"\t\t\t\t  Discount Availed   Rs."<<save<<endl;
						cout<<"\t\t\t\t  5% GST             Rs."<<add<<endl;
                        cout<<"\t\t\t\t  YOUR TOTAL BILL IS Rs."<<totalf<<endl;
                        cout<<"\n\t\t\t\t  Total cash given: ";
						cin>>cash;
						cout<<"\n\t\t\t\t  Total cash repaid: "<<cash-totalf;
						cout <<"\n\t\t\t\t ================================================"<<endl;

						//FILE//
                        bill << "\n\t\t\t\t ================================================"<<endl;
						bill <<   "\t\t\t\t                      Invoice"<<endl;
						bill <<    "\t\t\t\t ================================================"<<endl;
						bill << endl;
						bill << endl;

						bill << "\t\t\t\t  Bill No : "<<x<<"\t\tOrder : "<<count<<endl;
						bill << endl;
						bill << endl;
						bill<<"\t\t\t\t  Item name \tQuantity \tPrice"<<endl<<endl;
						for(int j=0; j<i; j++){	

						bill <<"\t\t\t\t  "<< order[j] << "\t"<<quan[j]<<"\t"<<p[j]<<endl;}
						if(discount==0.05)
							bill<<"\n\t\t\t\t  You Availed DEAL 1 discount\n"<<endl<<endl; 
							
						else if (discount==0.30)
						
						bill<<"\n\t\t\t\t  You Availed Deal 2 discount"<<endl<<endl; 
							
						bill<<"\n\t\t\t\t  YOUR TOTAL BILL IS Rs."<<total<<endl;
						bill<<"\t\t\t\t  Discount Availed   Rs."<<save<<endl;
						bill<<"\t\t\t\t  GST                Rs."<<add<<endl;
                        bill<<"\t\t\t\t  YOUR TOTAL BILL IS Rs."<<totalf<<endl;
		

}
bill.close();
}

};
int Order::count=0;
int Order::i=0;
class Manager:public User,public Reservation,public Order{
	private:
		int opt,ch,y;
		string id;
		string pass;
		string CN;
		public:
			Manager(string name):User(name,2)
			{	login();
			}
		void login()
		{
			cout<<"\t**LOGIN DETAILS**";
			fflush(stdin);
			cout<<"\nUser ID: ";
			getline(cin,id);
			cout<<"Password: ";
			fflush(stdin);
			getline(cin,pass);
			if(id=="JK1234" && pass=="123d3") //rest common uname;
			{
				
				cout<<"\n\t**Hello Mr/Ms "<<Managername()<<"**"<<endl;
				display();
			}
			else{
				do{
				cout<<"1.login again"<<endl<<"2.Exit\n-->";
				cin>>opt;}
				while(opt!=1 && opt!=2);
				if(opt==1)
				{
					login();
				}
				else 
				exit(0);
			}

		}
		void display()
		{
			do{
			cout<<endl<<"Press"<<endl;
			cout<<"1.Customer Service"<<endl;
			cout<<"2.Reservation Details"<<endl;
			cout<<"3.Bill Record/Profit"<<endl;//filing
			cout<<"4.View Deals"<<endl; 
			cout<<"5.View Menu"<<endl;
			cout<<"6.View FeedBack"<<endl; 
			cout<<"7.Exit"<<endl;
			cout<<"-->";
			cin>>opt;}
			while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5 &&opt!=6 && opt!=7);
			switch(opt)
			{
				case 1:
					{
						fflush(stdin);
						cout<<"Customer Name: ";
						getline(cin,CN);
						cout<<"\n\n";
						CustomerService();
					
						string CN1;
						char b[]="bill.txt";
							CN1=CN+".txt";
					 int n;
					 n=CN1.length();
    				char CN2[n + 1];
 
    				// copying the contents of the
   						 // string to char array
   					 strcpy(CN2, CN1.c_str());
   					
 					rename(b,CN2);
					
 					fstream Mbill;
 					Mbill.open("Bill Record.txt",ios::app);
			
	
						if(!Mbill)
						{
							cout<<"File not created";
						}
						else{
							//cout<<"File created";
						Mbill<<"Customer Name:"<<CN<<endl<<"Bill: Rs:"<<totalf<<endl<<"******"<<endl<<endl;
						Mbill.close();
						}
					
						display();
						break;
					}
				case 2:
				{
					Rmenu();
					display();
					break;
					}
		
				case 3:
					{
					ifstream Mbill;
					Mbill.open("Bill Record.txt",ios::in);
					if (!Mbill)
					{
						cout<<"No file found";
					}
					else{
					string line;
					cout<<"\n\t**BILL RECORD**\n";
					while(!Mbill.eof())
					{
						getline(Mbill,line);
						cout<<line<<endl;
						//bill>>ch;
					}}
					Mbill.close();
					display();
					break;	
					}
				case 4:
					{
					viewDeals();
					display();
						break;
					}
				case 5:
					{
						string line;
						ifstream file;
						file.open("India.txt");
						if(!file)
						{
							cout<<"NOT FOUND";
						}
						else{
							while(!file.eof())
							{
								getline(file,line);
								cout<<line<<endl;
							}
						}
						file.close();
						file.open("China.txt");
						if(!file)
						{
							cout<<"NOT FOUND";
						}
						else{
							while(!file.eof())
							{
								getline(file,line);
								cout<<line<<endl;
							}
						}
						file.close();
						file.open("Italy.txt");
						if(!file)
						{
							cout<<"NOT FOUND";
						}
						else{
							while(!file.eof())
							{
								getline(file,line);
								cout<<line<<endl;
							}
						}
						file.close();
						file.open("Drinks.txt");
						if(!file)
						{
							cout<<"NOT FOUND";
						}
						else{
							while(!file.eof())
							{
								getline(file,line);
								cout<<line<<endl;
							}
						}
						file.close();
						display();
						break;
					}
				case 6:
					{
						feedback();
						display();
						break;
					}
				case 7:
					{
						exit(0);
						break;
					}
				default:
					cout<<"Invalid option";
					break;
			}}
	void CustomerService()
	{
			cout<"\n\t\t\t**Wecome to Customer Service**";
    		cout<<"\nPress";
    		cout<<"\n1-> Dine Inn";
    		cout<<"\n2-> Take Away\n-->";
    		cin>>opt;
    		if(opt==1)
    		{
    		y=reservation();
    		if(y==1)
			takeorder();
				
			}
			else if(opt==2)
    		{
    			takeorder();
			}
			else 
    		{
    			cout<<"\nWrong input";
    			CustomerService();
			}

	}
	void takeorder()
	{
		getMenu();
	}
						
	void Rmenu(){
		do{
					cout<<"\n1-Reserve a table";
					cout<<"\n2-Cancel a reservation of table";
					cout<<"\n3-View Reservation chart";
					cout<<"\n4-return to main menu";
					cout<<"\nPlease enter a number from the given list\n-->";
					cin>>ch;
					}while(ch!=1 && ch!=2 &&ch!=3 &&ch!=4);
					switch(ch)
					{
						case 1:
							reservation();
							Rmenu();
							break;
						case 2:
						    Cancel_Reservation();
						    Rmenu();
						    break;
						case 3:
						    Reservation_chart();
							Rmenu();	
							break;		
						case 4:
							display();
							break;
					}}
	void viewDeals()
	{
		ifstream deals;
		deals.open("Deals.txt");
		if (!deals)
		cout << "Deal File not found";
		
		
		char ch;
		while(deals>>noskipws>>ch)
        cout<<ch;
		deals.close();
	}
		
		void feedback(){
		
		fstream file;
	file.open("feedback_1.text",ios::in);
	if (!file)
	{
		cout<<"No such file";
	}
	else
	{
		char ch;
		while(!file.eof())
		{
			string line;
			getline(file,line);
			cout<<line<<"\n";
		}
	}
	file.close();
}

};

int main()
{
	string name;
	int opt;
	do{
	cout<<"Press\n1.Manager\n2.Customer\n-->";
	cin>>opt;}
	while(opt!=1 && opt !=2);
	
	switch(opt)
	{
		case 1:
			{fflush(stdin);
			cout<<"\t**MANAGER**\n";
			cout<<"Enter your Username:";
			getline(cin,name);
			Manager M(name);
			break;}
		case 2:
			{fflush(stdin);
			cout<<"\t**Customer**\n";
			cout<<"Enter your name:";
			getline(cin,name);
			Customer M(name);
			break;}
		default:
			{cout<<"Invalid Option";
			break;}
			
	}
}
