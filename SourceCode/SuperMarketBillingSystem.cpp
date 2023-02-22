/*
 * Developer's Name : Rishab.H
 * Administrator Email : admin@email.com
 * Administrator Password : rishab
 */

#include <iostream>
#include <fstream>

using namespace std ;

class shopping
{
	private :
		int pcode ;
		float price ;
		float dis ;
		string pname ;
		
	public :
		void menu() ;
		void administrator() ;
		void customer() ;
		void add() ;
		void edit() ;
		void rem() ;
		void list() ;
		void receipt() ;
} ;

void shopping :: menu()
{
	m :
	
	int choice ;
	string email ;
	string password ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\tSupermarket Main Menu - Rishab	\n" ;
	cout << "\n ---------------------------------------------------------------\n\n" ;
	
	cout << "\t1] Administrator\n\n" ;
	cout << "\t2] Customer\n\n" ;
	cout << "\t3] Exit\n\n" ;
	
	cout << "\t Please Enter your login option :\t" ;
	cin >> choice ;
	
	
	switch (choice)
	{
		case 1 :
			cout << "\n PLease login \n" ;
			cout << " Enter Email :\t" ;
			cin >> email ;
			cout << "\n Enter Password :\t" ;
			cin >> password ;
			
			if((email == "admin@email.com") && (password == "rishab"))
			{
				administrator() ;
			}
			
			else
			{
				cout << "\n------------------------------------------------------\n" ;
				cout << "\n\t\tInvalid Email or Password\n" ;
				cout << "\n------------------------------------------------------\n" ;
				goto m ;
			}
			break ;
			
		case 2 :
			customer() ;
			break ;
		
		case 3 :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n\t\tThank You !! - Rishab\n" ;
			cout << "\n------------------------------------------------------\n" ;
			exit(0) ;
			break ;
			
		default :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n	 Invalid Choice please select from the given choice	 \n" ;
			cout << "\n------------------------------------------------------\n" ;
			goto m ;
	}
}

void shopping :: administrator()
{
	m :
	
	int choice ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Administrator Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t1] Add the product" ;
	cout << "\n\t2] Modify the product" ;
	cout << "\n\t3] Delete the product" ;
	cout << "\n\t4] Back to Main Menu" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
	cin >> choice ;
	
	switch (choice)
	{
		case 1 :
			add() ;
			break ;
		
		case 2 :
			edit() ;
			break ;
			
		case 3 :
			rem() ;
			break ;
			
		case 4 :
			menu() ;
			break ;
		
		default :
			cout << "\n------------------------------------------------------\n" ;
			cout << "\n	 Invalid Choice please select from the given choice	 \n" ;
			cout << "\n------------------------------------------------------\n" ;
			goto m ;
	}
}


void shopping :: customer()
{
	m :
	
	int choice ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t	Customer Menu" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	
	cout << "\n\t1] Buy product" ;
	cout << "\n\t2] Go Back" ;
	
	cout << "\n\n Please Enter your choice :\t" ;
	cin >> choice ;

	switch (choice)
	{
		case 1 :
			receipt() ;
			break ;
		
		case 2 :
			menu() ;
			break ;
			
		default :
			cout << "\n\n\t------------------------------------------------------\n" ;
			cout << "\n\t  Invalid Choice please select from the given choice\n" ;
			cout << "\n\t------------------------------------------------------\n" ;
			goto m ;
	}
}


void shopping :: add()
{
	m :
	
	fstream data ;
	
	int c ;
	int token = 0 ;
	float p ;
	float d ;
	string n ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Add new product" ;
	cout << "\n\n ---------------------------------------------------------------\n" ;
	cout << "\n\t Product code of the product :\t" ;
	cin >> pcode ;
	cout << "\n\t Name of the product :\t" ;
	cin >> pname ;
	cout << "\n\t Price of the product :\t" ;
	cin >> price ;
	cout << "\n\t Discount of the product :\t" ;
	cin >> dis ;
	
	data.open("Stocks.txt", ios ::in) ; // open in read-mode
	
	if(! data)
	{
		data.open("Stocks.txt", ios :: app | ios :: out) ; //  open in append-mode
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
		data.close() ;
	}
	
	else
	{
		data >> c >> n >> p >> d ;
		
		while (! data.eof())
		{
			if (c == pcode)
			{
				token++ ;
			}
			
			data >> c >> n >> p >> d ;
		}
		
		data.close() ;
		
		if (token > 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "Product Code Repeated\nPlease try again with Unique Product Code" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
			goto m ;
		}
	
		else
		{
			data.open("Stocks.txt", ios :: app | ios :: out) ;
			data << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
			data.close() ;
		}
	
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t Recorded Inserted" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	menu() ;
}


void shopping :: edit()
{
	fstream data, data1 ;
	
	int pkey ;
	int token = 0 ;
	int c ;
	float p ;
	float d ;
	string n ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Modify the record" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	cout << "\t Product code :\t" ;
	cin >> pkey ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	if(! data)
	{
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tFile doesn't exist" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	else
	{
		data1.open("Stocks1.txt", ios :: app | ios :: out ) ;
		
		data >> pcode >> pname >> price >> dis ;
		
		while (! data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\n\t Product's new code :\t" ;
				cin >> c ;
				cout << "\n\t Name of the product :\t" ;
				cin >> n ;
				cout << "\n\t Discount :\t" ;
				cin >> d ;
				
				data1 << " " << c << " " << n << " " << p << " " << d << "\n" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				cout << "\t\t Record Updated" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				
				token++ ;
			}
			
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n" ;
			}
			
			data >> pcode >> pname >> price >> dis ;
		}
		
		data.close() ;
		data1.close() ;
		
		remove("Stocks.txt") ;
		rename("Stocks1.txt", "Stocks.txt") ;
		
		if (token == 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
		}
	}
	
	menu() ;
}


void shopping :: rem()
{
	fstream data, data1 ;
	
	int pkey ;
	int token = 0 ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t Delete Product" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	
	list() ;
	
	cout << "\t Product code :\t" ;
	cin >> pkey ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	if (! data)
	{
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t File Not Found !" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
	}
	
	else
	{
		data1.open("Stocks1.txt", ios :: app | ios :: out) ;
		data >> pcode >> pname >> price >> dis ;
		
		while (! data.eof())
		{
			if(pcode == pkey)
			{
				cout << "\n ---------------------------------------------------------------\n\n" ;
				cout << "\t\t Product Deleted Successfully" ;
				cout << "\n\n ---------------------------------------------------------------\n\n" ;
				token ++ ;
			}
			
			else
			{
				data1 << " " << pcode << " " << price << " " << dis << "\n";
			}
			
			data >> pcode >> pname >> price >> dis ;
		}
		
		data.close() ;
		data1.close() ;
		
		remove("Stocks.txt") ;
		rename("Stocks1.txt", "Stocks.txt") ;
		
		if (token == 0)
		{
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t\t Record Not Found !" ;
			cout << "\n\n ---------------------------------------------------------------\n\n" ;
		}
	}
	
	menu() ;
}


void shopping :: list()
{
	fstream data ;
	
	data.open("Stocks.txt", ios :: in) ;
	
	cout << "\n\n___________________________________________________________\n" ;
	cout << "ProNo\t\tName\t\tPrice\n" ;
	cout << "\n\n___________________________________________________________\n" ;
	
	data >> pcode >> pname >> price >> dis ;
	
	while(! data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n" ;
		data >> pcode >> pname >> price >> dis ;
	}
	
	data.close() ;
}


void shopping :: receipt()
{
	m :
		
	fstream data ;
	
	int arrc [100] ; // array of codes
	int arrq [100] ; // array of quantity
	char choice ;
	int c = 0 ;
	float amount  = 0 ;
	float dis = 0 ;
	float total = 0 ;
	
	cout << "\n ---------------------------------------------------------------\n\n" ;
	cout << "\t\t RECEIPT" ;
	cout << "\n\n ---------------------------------------------------------------\n\n" ;
	data.open("Stocks.txt", ios :: in) ;
	
	if(! data)
	{
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\t Empty File !" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
		//data.close() ;
	}
	
	else
	{	
	
		data.close() ;	
		list() ;
		
		cout << "\n ---------------------------------------------------------------\n\n" ;
		cout << "\t\tPlace Your Orders" ;
		cout << "\n\n ---------------------------------------------------------------\n\n" ;
		
		do
		{
			cout << "\n\nEnter Product code :\t" ;
			cin >> arrc[c] ;
			cout << "\n\nEnter the Product Quantity :\t" ;
			cin >> arrq[c] ;
			cout << "\n" ;
			
			for(int i = 0 ; i < c ; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n ---------------------------------------------------------------\n\n" ;
					cout << "\t\t Duplicate Product Code. Please try again !" ;
					cout << "\n\n ---------------------------------------------------------------\n\n" ;
					goto m ;
				}
			}
			
			c++ ;
			
			cout << "\n ---------------------------------------------------------------\n\n" ;
			cout << "\t Do you want to buy another product ?\n\t Press 'y' if yes, else 'n' for no :\t" ;
			cin >> choice ;
			//cout << c ;
		}
		while(choice == 'y' || choice == 'Y') ;
		
		cout << "\n\n\t\t\t_________________________RECEIPT_________________________\n" ;
		cout << "\nProduct No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount With Discount\n" ;
		cout << "\n\t____________________________________________________________________________________\n\n" ;
		
		// c=0 ;
		//cout << c ;
		for(int i = 0 ; i < c ; i++)
		{
			//cout << "Testing 1" ;
			data.open("Stocks.txt", ios :: in) ;
			data >> pcode >> pname >> price >> dis ;
			//cout << "Testing 2" ;
			//cout << pcode ;
			while(! data.eof())
			{
				//cout <<"Testing 4" ;
				if(pcode == arrc[i])
				{
					//cout << "Testing 7" ;
					amount = price * arrq[i] ;
					dis = amount - (amount * dis / 100) ;
					total += dis ;
					
					//cout<<"Testing 3 " ;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis ;
				}
				
				//cout <<"Testing 5" ;
				data >> pcode >> pname >> price >> dis ;
				
				data.close() ;
			}
		}
		
		//cout<<"Testing 6" ;
		//data.close() ;
	}
	
	cout << "\n\t____________________________________________________________________________________\n\n" ;
	cout << "\n Total Amount :\t" << total ;
	cout << "\n\n\t____________________________________________________________________________________\n\n" ; 
	cout << "\n\t------------------------------------------------------\n" ;
	cout << "\n\t\tThanks for Shopping us !! - Rishab\n" ;
	cout << "\n\t------------------------------------------------------\n" ;
	
	cout << "\n\n========================================================================================================================\n\n" ;

	menu() ;
}

int main()
{
	shopping rishab ;
	
	rishab.menu() ;

	return 0 ;
}
