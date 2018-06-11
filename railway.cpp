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

		else{
Admin:
		clrscr();
		cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
		cout<<"______________________________(ADMIN LOGIN MENU)________________________________";
		cout<<"________________________________________________________________________________";
					cout<<"\n\n1.Create detail data base\n2.Add details\n";
					cout<<"3.Display details\n4.User management\n";
					cout<<"5.Display passenger details\n6.Return to main menu\n\n";
					cout<<"Enter your choice: \n"; cin>>ch;
					switch(ch){
						
							case 1:
								
								fout.open("rail.txt",ios::out|ios::binary);
							
								do
								{	clrscr();
									printf("                                                   designed by:   Mausam Sharma ");
   									printf("\n");
   									printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   									printf("_______________________________( Admin__Panel )_________________________________");
									cout<<"\nEnter details of train : ";
									cout<<"\n________________________________________________________________________________";
									cout<<"\n\n\t\tTrain Number : \t\t\t";
									cin>>a.tno;
									cout<<"\t\tTrain Name : \t\t\t";
									gets(a.tname);									
									cout<<"\n\t\tBoarding station : \t\t";
									gets(a.bp);
									cout<<"\t\tDestination station: \t\t";
									gets(a.dest);
									cout<<"\n\t\tArrival time : \t\t\t";
									gets(a.arrival);
									cout<<"\t\tReaching time : \t\t";
									gets(a.depart);
									cout<<"\t\tFare per seat : \t\t";
									cin>>a.c1fare;
									cout<<"________________________________________________________________________________";
									fout.write((char*)&a,sizeof(a));
									cout<<"\nDo you want to add one more record?\n";
									cout<<"y-for Yes\nn-for No\n";
									cin>>choice;
							
								}while(choice=='y'||choice=='Y');
							
								fout.close();
								break;

							case 2:
								clrscr();
								
								fout.open("rail.txt",ios::out|ios::app|ios::binary);

									printf("                                                   designed by:   Mausam Sharma ");
   									printf("\n");
   									printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   									printf("_______________________________( Admin__Panel )_________________________________");
									cout<<"\nEnter details of train : ";
									cout<<"\n________________________________________________________________________________";
									cout<<"\n\n\t\tTrain Number : \t\t\t";
									cin>>a.tno;
									cout<<"\t\tTrain Name : \t\t\t";
									gets(a.tname);									
									cout<<"\n\t\tBoarding station : \t\t";
									gets(a.bp);
									cout<<"\t\tDestination station: \t\t";
									gets(a.dest);
									cout<<"\n\t\tArrival time : \t\t\t";
									gets(a.arrival);
									cout<<"\t\tReaching time : \t\t";
									gets(a.depart);
									
									cout<<"\t\tFare per seat : \t\t";
									cin>>a.c1fare;
									cout<<"________________________________________________________________________________";
									fout.write((char*)&a,sizeof(a));
									cout<<"\n Records saved for this train !!!"; getch();
								fout.close();
								break;

							case 3:
								clrscr();
								
		
								fin.open("rail.txt",ios::in|ios::binary);
								fin.seekg(0); int count=0;
								while(fin.read((char*)&a,sizeof(a)))
									{	clrscr();
										printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   										printf("_______________________________( Admin__Panel )_________________________________");
										printf("\n_______________________________ Train_Database _________________________________");
										
										cout<<"\n\t\tTrain number : \t\t\t"<<a.tno;
										cout<<"\n\t\tTrain name : \t\t\t"<<a.tname;
										
										cout<<"\n\n\t\tBoarding point : \t\t"<<a.bp;
										cout<<"\n\t\tDestination point : \t\t"<<a.dest;
										
										cout<<"\n\n\t\tStart time of journey: \t\t"<<a.arrival;
										cout<<"\n\t\tEnd time of journey : \t\t"<<a.depart;
										
										
										cout<<"\n\n\t\tFare of seat: \t\t\t"<<a.c1fare;
										
										cout<<"\n\n_______________________________Record Number "<<++count<<"_________________________________";
										cout<<"\n\nDo you want to see more records?\n";
										cout<<"y-for Yes\nn-for No\n";
										cin>>choice;
										if(choice=='n'||choice=='N')
										 {break;}
										
									}
								fin.close();
								getch();
								break;

							case 4: manage(); break;

							case 5: displaypassdetail();	break;

							case 6: return 0;
							default: 
								cout<<"\n wrong choice !!!\t Enter again";
					}
					goto Admin;

		}

	
	}