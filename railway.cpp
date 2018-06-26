#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<iomanip.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<fstream.h>

struct tinfo{
	
	int tno;
	char tname[50];
	char bp[50];
	char dest[50];
	char arrival[50];
	char depart[50];
	int c1fare;
};

struct login{
	char id[20];
	char password[30];
};

struct reser{
	int tno;
	int pnr;
	int nosr;
	char bp[50];
	char dest[50];
	char tname[50];
	char pname[10][50];
	int age[10];
	char date[50];


};



int database();
int user();


void main()
{   
int gd,gm;
int i;
int maxx,midy,mxt;
int z,ch;
clrscr();
// initialize graphic mode
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
//max pixel in horizontal direction

maxx=getmaxx();
mxt=maxx-300;

// mid pixel in vertical direction

midy=getmaxy()/2;

A:
{
for(i=0;i<maxx;i=i+9)
{ // clears the screen
cleardevice();
 if(kbhit())
 { break;}
//______________________________text on the main screen
setcolor(GREEN);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
outtextxy(0,20,"____________Indian Railways_____________") ;
//________________________________________________________________
setcolor(YELLOW);
settextstyle(3,HORIZ_DIR,4);
outtextxy(mxt-i,100," PRESS ENTER ");
//________________________________________________________________
setcolor(WHITE);
settextstyle(3,HORIZ_DIR,2);
outtextxy(mxt-i,midy+135,"made by MAUSAM SHARMA");



  // makes a road
setcolor(5);
  line(0,midy+120,maxx,midy+120);
// draw a train
setcolor(YELLOW);
setfillstyle(SOLID_FILL,RED);
//train tyres specially designed by Mausam Sharma
 circle(i+25,midy+95,25);
 circle(i+25,midy+95,20);
 circle(i+80,midy+95,25);
 circle(i+80,midy+95,20);
 circle(i+127,midy+103,17);
 circle(i+127,midy+103,12);
 circle(i+166,midy+103,17);
 circle(i+166,midy+103,12);
//___________________________additional circles in tyres
circle(i+25,midy+95,3);
circle(i+80,midy+95,3);
circle(i+127,midy+103,2);
circle(i+166,midy+104,2);
// train body arcs
setcolor(RED);
arc(i+25,midy+87,0,160,27);
arc(i+80,midy+87,-10,180,27);
arc(i+127,midy+95,0,170,19);
arc(i+166,midy+95,0,180,19);
//train frame designed by Mausam Sharma
//tyres to above window
line(i+0,midy+75,i+0,midy+35);
line(i+0,midy+35,i+10,midy+35);
line(i+10,midy+35,i+10,midy-10);
line(i+10,midy-10,i+0,midy-10);
//______________________________ above window design
line(i+0,midy-10,i+10,midy-20);
line(i+10,midy-20,i+80,midy-20);
line(i+80,midy-20,i+90,midy-10);
line(i+90,midy-10,i+80,midy-10);
//______________________________  horizontal infront of window
line(i+80,midy-10,i+80,midy+35);
line(i+80,midy+35,i+190,midy+35);
//______________________________  front arc
arc(i+190,midy+60,270,90,25);
line(i+190,midy+85,i+230,midy+110);
line(i+230,midy+110,i+186,midy+110);
line(i+187,midy+110,i+186,midy+85);
line(i+186,midy+85,i+190,midy+85);
//____________________________________window
line(i+20,midy+35,i+70,midy+35);
line(i+70,midy+35,i+70,midy-10);
line(i+70,midy-10,i+20,midy-10);
line(i+20,midy-10,i+20,midy+35);
line(i+10,midy+35,i+80,midy+35);
line(i+10,midy-10,i+80,midy-10);
//__________________________________ chimney
arc(i+190,midy+35,120,180,15);
arc(i+130,midy+35,0,60,15);
line(i+137,midy+22,i+183,midy+22);
arc(i+130,midy+8,300,0,15);
arc(i+190,midy+8,180,240,15);
line(i+145,midy+8,i+175,midy+8);
line(i+145,midy+8,i+140,midy+3);
line(i+140,midy+3,i+180,midy+3);
line(i+180,midy+3,i+175,midy+8);
//__________________________________lighting
line(i+190,midy+35,i+190,midy+25);
line(i+190,midy+25,i+195,midy+25);
line(i+195,midy+25,i+195,midy+36);
arc(i+195,midy+25,270,180,6);
arc(i+100,midy+35,0,180,8);
arc(i+120,midy+35,0,180,8);
//_________________________________designing
line(i+0,midy+45,i+120,midy+45);
line(i+0,midy+50,i+120,midy+50);

line(i+120,midy+35,i+120,midy+78);
line(i+140,midy+35,i+140,midy+80);

line(i+150,midy+35,i+150,midy+83);
line(i+170,midy+35,i+170,midy+77);
//_________________________smoke clouds_____________________
setcolor(WHITE);
ellipse(30-i,130-i,40,260,10,15);
ellipse(55-i,120-i,365,175,20,15);
ellipse(92-i,127-i,340,170,20,25);
ellipse(98-i,146-i,220,70,20,15);
ellipse(56-i,151-i,145,355,30,15);

ellipse(125-i,190-i,40,285,5,10);
ellipse(140-i,183-i,365,175,12,7);
ellipse(162-i,187-i,340,170,10,15);
ellipse(167-i,196-i,220,70,10,12);
ellipse(145-i,205-i,145,355,22,8);

if(i>=90){ if(i==90){z=i;}
ellipse(z+125-i,z+190-i,40,285,5,10);
ellipse(z+140-i,z+183-i,365,175,12,7);
ellipse(z+162-i,z+187-i,340,170,10,15);
ellipse(z+167-i,z+196-i,220,70,10,12);
ellipse(z+145-i,z+205-i,145,355,22,8);  }


//____________________________________coloring
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(i+2,midy+95,YELLOW);
floodfill(i+102,midy+95,YELLOW);
floodfill(i+142,midy+103,YELLOW);
floodfill(i+181,midy+103,YELLOW);


setfillstyle(SOLID_FILL,BLUE);
floodfill(i+25,midy+95,YELLOW);
floodfill(i+80,midy+95,YELLOW);
floodfill(i+127,midy+103,YELLOW);
floodfill(i+166,midy+103,YELLOW);
//____________tyres done___________________________
setcolor(RED);
setfillstyle(SOLID_FILL,LIGHTRED);
floodfill(i+18,midy+30,RED);
floodfill(i+75,midy+30,RED);
setfillstyle(XHATCH_FILL,LIGHTBLUE);
floodfill(i+22,midy+30,RED);
//_____________________inner tyres_________________
setcolor(YELLOW);
setfillstyle(WIDE_DOT_FILL,BROWN);
floodfill(i+7,midy+95,YELLOW);
floodfill(i+62,midy+95,YELLOW);
floodfill(i+137,midy+103,YELLOW);
floodfill(i+156,midy+103,YELLOW);
//________________________engine below the chimney_____________
setcolor(RED);
setfillstyle(SOLID_FILL,GREEN);

floodfill(i+122,midy+57,RED);
floodfill(i+162,midy+57,RED);

setfillstyle(SOLID_FILL,BLUE);
floodfill(i+206,midy+103,RED);
floodfill(i+110,midy+47,RED);
floodfill(i+162,midy+7,RED);

setfillstyle(SOLID_FILL,LIGHTBLUE);
floodfill(i+162,midy+12,RED);
floodfill(i+162,midy+32,RED);

setfillstyle(SOLID_FILL,RED);
floodfill(i+110,midy+37,RED);
floodfill(i+145,midy+37,RED);
floodfill(i+185,midy+37,RED);
floodfill(i+110,midy+57,RED);
floodfill(i+145,midy+57,RED);
floodfill(i+60,midy-15,RED);

setfillstyle(SOLID_FILL,LIGHTRED);
floodfill(i+192,midy+32,RED);

setcolor(RED);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(i+195,midy+23,RED);
floodfill(i+100,midy+32,RED);
floodfill(i+120,midy+32,RED); delay(300); }
//_______________text indian railways___________________
}

closegraph();




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
					case 1:			ret = database(); if(ret==0){goto start;} break;
					case 2:			ret = user(); if(ret==0){goto start;} break;
					case 3:			exit(0);
					default:		cout<<"\n wrong choice"; getch(); goto start;

				}

		


		getch();
	}


	void cancell(){
		
		reser b,c;
		int ret,pnri,flag=0;
		ifstream f2;
		ofstream f3;
		potato:
		f2.open("p.txt",ios::in|ios::binary);
		f3.open("temp.txt",ios::out|ios::binary|ios::trunc);
		clrscr();
		cout<<"\n-------------------------------INDIAN__RAILWAYS---------------------------------";
		cout<<"_____________________________(Cancellation menu)________________________________";
		cout<<"\n\nEnter PNR number: ";
		cin>>pnri;
		

		while(f2.read((char *) & b,sizeof(b))){
			if(b.pnr!=pnri){
				c.tno=b.tno;
				c.pnr=b.pnr;
				c.nosr=b.nosr;
				strcpy(c.bp,b.bp);
				strcpy(c.dest,b.dest);
				strcpy(c.tname,b.tname);
				for(int j=0;j<c.nosr;j++){
					strcpy(c.pname[j],b.pname[j]);
					c.age[j] = b.age[j];
				}

				
				strcpy(c.date,b.date);

				
				

				f3.write((char *) &c,sizeof(c));
				

				}
			else{
				 flag=1;
				


			}



			}
			
			
			f2.close();
			f3.close();

			

			ret = remove("p.txt");
			ret = rename("temp.txt","p.txt");

			
			if(flag==1){cout<<"\n\t\t\t\t Ticket cancelled ";}
			else{cout<<"\n\t\t\t \tWrong PNR entered : "; getch();}

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
						goto aloo;

				case 4:	break;

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