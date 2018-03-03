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