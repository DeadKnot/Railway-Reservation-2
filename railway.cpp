#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<iomanip.h>
#include<fstream.h>

class login
			{
				public:
					char id[15];
					char pass[50];
					char *password;
						void getid()
							{
								cout<<"Enter your id:";gets(id);
								password=getpass("Enter your password:");
								
								strcpy(pass,password);
								
							}

						void displayid()
							{
								cout<<"Id:";puts(id);
								cout<<"Password:";puts(pass);
							}
			};


void main()
	{
		clrscr();
		int ch;

		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		do
		{
			cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
			cout<<"1.Admin mode\n2.User mode\n3.Exit\n";
			cout<<"Enter your choice:";
			cin>>ch;
			cout<<endl;


			switch(ch)
				{
					case 1:			database(); break;
					case 2:			user(); break;
					case 3:			exit(0);

				}

		}while(ch<=3);


		getch();
	}