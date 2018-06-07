#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<iomanip.h>
#include<fstream.h>




void main()
	{
		
		start:
		

		int cho,ret;
		clrscr();
		cout<<"\n-------------------------------INDIAN_RAILWAYS----------------------------------";
		cout<<"________________________________________________________________________________";
		cout<<"_________________________________(Main_Menu)____________________________________";
		

			cout<<"\n\n1.Admin mode\t2.User mode\t3.Exit\n";
			cout<<"\nDefault password for Admin is '1234'";
			cout<<"\n___________________________________________";
			cout<<"\n\nEnter your choice in numeric form :  ";
			cin>>cho;
			


			switch(cho)
				{
					case 1:			//ret = database(); if(ret==0){goto start;} break;
					case 2:			//ret = user(); if(ret==0){goto start;} break;
					case 3:			exit(0);
					default:		cout<<"\n wrong choice"; getch(); goto start;

				}

		


		getch();
	}


	int database(){
		char password[20]="1234";
		char pass[20];
		tinfo a;
		ifstream fin;
		ofstream fout;
		int ch; char choice;
		clrscr();
		cout<<"\n-------------------------------INDIAN_RAILWAYS----------------------------------";
		cout<<"________________________________(ADMIN LOGIN)___________________________________";
		
	A:
		cout<<"\n\n\nEnter the administrator password to login:\t";
		gets(pass);
		if(strcmp(pass,password)!=0){
			cout<<"\n!!!	!!! 	!!! 	!!! 	!!!";
			cout<<"\n____________________________________";
			cout<<"\nYou have entered a wrong password !!!";
			B:
			cout<<"\n____________________________________";
			cout<<"\n\n Enter your choice : \n";
			cout<<"1: Try again\t2: Go to home page";
			cin>>ch;
			switch(ch)
			{
				case 1: goto A; 
				case 2: return 0;
				default: cout<<"\n wrong choice"; goto B;
			}
		}

		
	}