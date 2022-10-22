#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pname;
		int pcode;
		float price;
		float dis;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};
void shopping:: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t-------------------------\n";
    cout<<"\t\t\t                         \n";
    cout<<"\t\t\t  supermarket main menu  \n";
    cout<<"\t\t\t                         \n";
    cout<<"\t\t\t                         \n";
	cout<<"\t\t\t-------------------------\n";
	cout<<"\t\t\t 1)     Administrator    \n";
	cout<<"\t\t\t                         \n";
	cout<<"\t\t\t 2)     Buyer            \n";
	cout<<"\t\t\t                         \n";
	cout<<"\t\t\t 3)     Exit             \n";
	cout<<"\t\t\t                         \n";
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t please login \n";
			cout<<"\t\t\t Enter Email   \n";
			cin>>email;
			cout<<"\t\t\t password   \n";
			cin>>password;
			
			if(email=="202rajeshkr@gmail.com"  &&  password=="202rajeshkr")
			{
				administrator();
					
			}
			else
			{
				cout<<"Invalid email/password";
				
			}
			break;
   
	
	   case 2:
		{
		  buyer();	
		}
	case 3:
	{
		exit(0);
	}	
	default :
		{
			cout<<"Please select from the given option";
			
		}	
	
	
}
goto m;
}

void shopping :: administrator()
{
//	m:
	int choice;
	cout<<"\n\n\n\n\t\t administrator menu        ";
	cout<<"\n\t\t\t|______1) Add the product______";
	cout<<"\t\t\t\t|                            \n";
	cout<<"\n\t\t\t|______2)modifythe product_____";
	cout<<"\t\t\t\t|                            \n";
	cout<<"\n\t\t\t|______3)delete the product____";
	cout<<"\t\t\t\t|                            \n";
	cout<<"\n\t\t\t|______4)back to main menu_____";
	cout<<"\t\t\t\t|                            \n";
	
	cout<<"\n\n\n\t please enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
		    edit();
			break;
			
		case 3:
		    rem();
			break;
		case 4:
		    menu();
			break;
			
			default:
			     cout<<"I nvalid choicee!";			
	}
	//goto m;
}

	
void shopping :: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t Buyer   \n";
	cout<<"\t\t\t_____________\n";
	cout<<"                   \n";
	
	cout<<"\t\t\t1) Buy product \n";
	cout<<"\t\t\t_____________\n";
	cout<<"                   \n";
	
	cout<<"\t\t\t2) Go back  \n";
	cout<<"Enter your choice \n";
	
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
			case 2:
				menu();
				break;
				
				default :
					cout<<"invalid choice";
					
			
	}
   // goto m;	
}

void shopping :: add()
{ 
m:
	fstream data;
	int c;
	float p;
	int token =0;
	float d;
	string n;
	
	cout<<"\n\n\n\t\t Add new product ";
	cout<<"\n\n\t product code of the product";
	cin>>pcode;
	cout<"\n\n\n\tname  of the product ";
	cin>>pname;
	
	cout<"\n\n\n\t price  of the product ";
	cin>>price;
	 cout<"\n\n\n\t Discount of the product ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		if(token==1)
	goto m;
	else{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
		
	
	}	
	 cout<<"\n\n\n\t\t Record insserted !";
	}
	
void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token =0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t  modify the record";
	cout<<"\n\t\t  product code ";
	cin>>pkey;
	
	
	data.open("databsae.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File doesn't Exist";
		
	}
	else{
			data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\n\t product new code :";
				cin>>c;
				cout<<"\n\n\t name of the product :";
				cin>>n;
				cout<<"\n\n\t price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<< " "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\n\t record edited ";
				token++;
				
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
			
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n record Not found sorry!";
		}
	}
}
	
void shopping :: rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product ";
	cout<"\n\n product code ";
	cin>>pkey;
	data.open("database.txt");
	if(!data)
	{
		cout<<"file doesnt Exit ";
	}
	else{
			data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\n product Deleted Succesfully";
				token++;
			}
			else
			{
					data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n record not found ";
		}
	}
}


void shopping :: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n__________________________________\n";
	cout<<"\n\nProNo\t\tName\t\tprice\n ";
	cout<<"\n\n____________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price;
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping :: receipt()
{
	m:
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount =0;
	float dis=0;
	float total =0;
	
	cout<<"\n\n\n\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout<<"\t\t\t-------------------------\n";
        cout<<"\t\t\t                         \n";
        cout<<"\t\t\t  please place the order \n";
        cout<<"\t\t\t                         \n";
         cout<<"\t\t\t                         \n";
	    cout<<"\t\t\t-------------------------\n";
		do
		{
			cout<<"\n\n Enter product code ";
			cin>>arrc[c];
			cout<<"\n\n Enter thr product Quantity :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. please try again ";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then please click";
			
			cin>>choice;
		}
		while(choice == 'y');
		cout<<"\nproduct No\t product name\t _________________";\
		cout<<"\nproduct no\t product name\t Product Quantity\tprice_______";
		
		for(int i=0; i<c;i++)
		{
				
		data.open("database.txt",ios::in);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
				if(pcode==arrc[i])
				{
					amount =price*arrq[i];
					dis=amount-(amount*dis/100);
					total = total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<price<<amount<<dis;
					
				}
				data>>pcode>>pname>>price>>dis;
			}
			
		}
		data.close();
	}
	cout<<"\n\n_______________________________________________";
	cout<<"\n Total Amount : "<<total;
	
	
}
int main()
{
	shopping s;
	s.menu();
}

	
	
	
	
	
	
	
	
