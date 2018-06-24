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

	
	void can(){
		int ch;
				
		A:		
		clrscr();
		cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
		cout<<"___________________________(Cancellation main menu)_____________________________";
		cout<<"\n\t\t1.Cancel\n\t\t2.Return to the User Login Menu\n";
		cout<<"\nEnter your choice:";
		cin>>ch;
		

		switch(ch)
			{
				case 1:
					cancell();
					break;

				case 2: break;
				default: cout<<"\n\t\t\t\tWrong choice "; getch(); goto A;
					}
				

				getch();

	}

	void enquiry(){

				ifstream fin; char choice;
				fin.open("rail.txt",ios::in|ios::out|ios::binary);
				tinfo a;
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
	}

	void displaypassdetail()
			{
				fstream f;
				reser b;
				f.open("p.txt",ios::in|ios::out|ios::binary);
				f.seekg(0); int i,count=0; char choice;
				
				while(f.read((char *) & b,sizeof(b)))
					{clrscr();
					cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
					cout<<"___________________________(Passenger detail menu)______________________________";
					cout<<"________________________________________________________________________________";
					cout<<"\nTrain Details :";
					cout<<"\n\n\t\tTrain No: \t\t"<<b.tno; cout<<"\n\t\tPNR number: \t\t"<<b.pnr;
					cout<<"\n\t\tDate :  \t\t"<<b.date<<"\n\t\tTrain name: \t\t"<<b.tname;
					cout<<"\n\t\tBoarding station: \t"<<b.bp<<"\n\t\tDestination: \t\t"<<b.dest;
					
					cout<<"\n\nPassengers : ";
					for(i=0;i<b.nosr;i++){
						cout<<"\n\t\tAge: "<<b.age[i]<<"\t\tName: "<<b.pname[i];
					}
					
					cout<<"\n\n_______________________________Record Number "<<++count<<"_________________________________";
					getch();
					cout<<"\n\nDo you want to see more records?\n";
					cout<<"y-for Yes\nn-for No\n";
					cin>>choice;
					if(choice=='n'||choice=='N')
						{break;}



					}
				
				f.close();
				getch();
			}

 void reserve(){

		int ch,i,flag=0;
		
		tinfo a;
		reser b;
		fstream f1,f2;
		f1.open("rail.txt",ios::in|ios::out|ios::binary);
		f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
		f1.seekg(0);
		f2.seekg(0);
		A:
		clrscr();
		cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
		cout<<"___________________________(Reservation main menu)______________________________";
		cout<<"________________________________________________________________________________";
		cout<<"\nEnter details for reservation  :	";
		cout<<"\n\n\t\tTrain number: \t\t";
		cin>>b.tno;
		
		B:
		cout<<"\t\tNo of seats required: \t";cin>>b.nosr; if(b.nosr>10){cout<<"\n No of seats should be >= 10"; goto B;}
		cout<<"\n";
		for(i=0;i<b.nosr;i++){
			cout<<"\t\tPassenger Name : \t"; gets(b.pname[i]);
			cout<<"\t\tPassenger Age : \t";	cin>>b.age[i];
		}
		cout<<"\n\t\tDate of journey : \t";
		gets(b.date);

		while(f1.read((char *) &a,sizeof(a))){

			if(a.tno==b.tno){

					randomize();
					b.pnr=random(10000);
					strcpy(b.tname,a.tname);
					strcpy(b.bp,a.bp);
					strcpy(b.dest,a.dest);
					f2.write((char *) & b,sizeof(b));
					cout<<"\n\n\t\t--------------Your ticket is reserved-----------\n";
					getch();
					clrscr();
					cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
					cout<<"___________________________(Reservation main menu)______________________________";
					cout<<"Ticket details  :	________________________________________________________";
					cout<<"\n\n\t\tTrain No: \t\t"<<b.tno; cout<<"\n\t\tPNR number: \t\t"<<b.pnr;
					cout<<"\n\t\tDate :  \t\t"<<b.date<<"\n\t\tTrain name: \t\t"<<b.tname;
					cout<<"\n\t\tBoarding station: \t"<<b.bp<<"\n\t\tDestination: \t\t"<<b.dest;
					
					cout<<"\n\nPassengers : ";
					for(i=0;i<b.nosr;i++){
						cout<<"\n\t\tAge: "<<b.age[i]<<"\t\tName: "<<b.pname[i];
					}

					cout<<"\n________________________________________________________________________________";getch(); flag=1; break;




			}
			else{
				flag=0;
			}



		}

		if(flag==0){
			cout<<"\n\n\t\tWrong train number entered: \n\t\tTicket not reserved: "; getch();
		}
		f1.close();
		f2.close();

		getch();
	}




  int user(){
		login b;
		int ch,flag=0;
		ifstream fin;
		fin.open("id.txt",ios::in|ios::binary);
		
		char pass[30];
		char iden[20];

		userlog:
		fin.seekg(0);
		clrscr();
		cout<<"\n-------------------------------INDIAN_RAILWAYS----------------------------------";
		cout<<"_________________________________(User LOGIN)___________________________________";
		cout<<"\n\n \tEnter your Id : \t"; gets(iden);
		cout<<"\n\tEnter password : \t"; gets(pass);
		while(fin.read((char *) & b,sizeof(b))){

			if((strcmp(b.id,iden)==0)&&(strcmp(b.password,pass)==0)){
				
				couch:

				clrscr(); flag=0;
				printf("                                                   designed by:   Mausam Sharma ");
   				printf("\n");
   				cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
				cout<<"_______________________________(USER LOGIN MENU)________________________________";
				cout<<"________________________________________________________________________________";
				cout<<"\n\n1.Reserve tickets\n2.Cancel tickets\n3.Enquiry\n4.Get ticket details\n5.Return to the main menu\n\n";
				cout<<"Enter your choice: ";
				cin>>ch;
				switch(ch){

					case 1: reserve(); goto couch;
					case 2: can(); goto couch;
					case 3: enquiry(); goto couch;
					case 4: displaypassdetail(); goto couch;
					case 5: return 0;
					default: cout<<"\n wrong choice entered !!!   Enter again "; getch(); goto couch;

				}


			}

			else{
				
				flag=1;
			}

		}

		if(flag){
			cout<<"\n Enter correct UserID and password !!!"; 

				B:
				cout<<"\n____________________________________";
				cout<<"\n\n Enter your choice : \n\n";
				cout<<"1: Try again\t2: Go to home page";
				cin>>ch;
				switch(ch)
				{
					case 1: goto userlog; 
					case 2: return 0;
					default: cout<<"\n wrong choice"; goto B;
				}
		}
		fin.close();
	}

	void manage(){
		int ch;
		ifstream fin;
		ofstream fout;
		char choice;
		login b;
	aloo:
		clrscr();
		cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
		cout<<"___________________________( User Management Menu )_____________________________";
		cout<<"________________________________________________________________________________";
			cout<<"\n\n1.Create UserID Database\n2.Add a user\n";
			cout<<"3.Display details\n4.Return to Admin Login menu\n";
			cout<<"\nEnter your choice: "; cin>>ch; 
			switch(ch){
				case 1:	
						fout.open("id.txt",ios::out|ios::binary);
						do{
						clrscr();
						printf("                                                   designed by:   Mausam Sharma ");
   						printf("\n");
   						printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   						cout<<"___________________________( User Management Menu )_____________________________";
						cout<<"________________________________________________________________________________";
						cout<<"\n\n\n\tEnter the ID for new user: \t\t";
						gets(b.id);
						cout<<"\n\tEnter password for this user: \t\t";
						gets(b.password);
						fout.write((char *) & b,sizeof(b));
						cout<<"________________________________________________________________________________";
						cout<<"\n\nDo you want to add one more user?\n";
						cout<<"y-for Yes\nn-for No\n";
						cin>>choice;
						}while(choice=='y'||choice=='Y');

						fout.close();
						goto aloo;

				case 2:
						fout.open("id.txt",ios::out|ios::binary|ios::app);
						clrscr();
						printf("                                                   designed by:   Mausam Sharma ");
   						printf("\n");
   						printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   						cout<<"___________________________( User Management Menu )_____________________________";
						cout<<"________________________________________________________________________________";
						cout<<"\n\n\n\tEnter the ID for new user: \t\t";
						gets(b.id);
						cout<<"\n\tEnter password for this user: \t\t";
						gets(b.password);
						fout.write((char *) & b,sizeof(b));
						cout<<"________________________________________________________________________________";
						cout<<"\n record for the user saved \n";

						getch();
						fout.close();
						goto aloo;

				case 3:
						fin.open("id.txt",ios::in|ios::binary);
						fin.seekg(0); int count=0;
						while(fin.read((char *) & b,sizeof(b)))
							{
								clrscr();
								printf("                                                   designed by:   Mausam Sharma ");
   								printf("\n");
   								printf("-------------------------------INDIAN__RAILWAYS---------------------------------");
   								cout<<"___________________________( User Management Menu )_____________________________";
								cout<<"________________________________________________________________________________";
								cout<<"\n\n\n\t\tUser ID : \t\t"; puts(b.id);
								cout<<"\n\t\tPassword : \t\t"; puts(b.password);
								
								cout<<"\n\n_______________________________Record Number "<<++count<<"_________________________________";
								cout<<"\n\nDo you want to see more records?\n";
								cout<<"y-for Yes\nn-for No\n";
								cin>>choice;
								if(choice=='n'||choice=='N')
									{goto aloo;}
							}
						fin.close();

				default : cout<<"\n wrong choice opted !!! 		 Choose again "; goto aloo;



			}


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