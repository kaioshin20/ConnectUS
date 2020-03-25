//////////////////////////////Header Files//////////////////////////////
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<iomanip.h>

using namespace std;

char eid[20]; //A global variable to store ID through which user has logged in

///////////////////Prototypes of all th functions used///////////////////
void frontpg();
void create();
void login();
void notiffr();
void notifm();
void sfr();
void messages();
void msgall();
void all();
void fr();

///////////////////////////////Classs Used///////////////////////////////
class id
{
 char id[20];
 char pass[20],name[30];
 char gender[7],address[50];
 public:
 void input()
 {
  gotoxy(20,6);
  cout<<"Enter ID - ";
  gets(id);
  gotoxy(20,8);
  cout<<"Enter password - ";
  gets(pass);
  gotoxy(20,10);
  cout<<"Enter name - ";
  gets(name);
  gotoxy(20,12);
  cout<<"Enter genger - ";
  gets(gender);
  gotoxy(20,14);
  cout<<"Enter address - ";
  gets(address);
 }
 void show()
 {
  cout<<"\n\t\t"<<name<<setw(30)<<id;
 }
 void profile()
 {
  cout<<"\n\t\tID : "<<id<<"\n\t\tPassword : "<<pass<<"\n\t\tName : "<<name<<"\n\t\tGender : "<<gender<<"\n\t\tAddress ; "<<address;
 }
 void profr()
 {
  cout<<"\n\t\tID : "<<id<<"\n\t\tName : "<<name<<"\n\t\tGender : "<<gender<<"\n\t\tAddress ; "<<address;
 }
 char* retid()
 {
  return id;
 }
 char* retpass()
 {
  return pass;
 }
};
class friends
{
 char fid[20];
 char yid[20];
 public:
 void input()
 {
  strcpy(yid,eid);
  cout<<"\n\n\tEnter ID to which you want to send friend request - ";
  gets(fid);
 }
 void showy()
 {
  cout<<"\t\t\t\t"<<yid;
 }
 void showf()
 {
  cout<<"\t\t\t\t"<<fid;
 }
 char* getyid()
 {
  return yid;
 }
 char* getfid()
 {
  return fid;
 }
};
class message
{
 char yid[20],fid[20],msg[80];
 public:
 void inputm()
 {
  strcpy(yid,eid);
  cout<<"\nEnter ID to which you want to send message - ";
  gets(fid);
  cout<<"\nEnter message - ";
  gets(msg);
 }
 void show()
 {
  cout<<"\nSent by : "<<yid;
  cout<<"\nMessage : \n"<<msg<<"\n";
 }
 void showmine()
 {
  cout<<"\nSent to : "<<fid;
  cout<<"\nMessage : \n"<<msg<<"\n";
 }
 void showy()
 {
  cout<<yid;
 }
 void showf()
 {
  cout<<fid;
 }
 char* getyid()
 {
  return yid;
 }
 char* getfid()
 {
  return fid;
 }
};

////////////////////Definitions of the functions used////////////////////
void home()
{
 textcolor(10);
 clrscr();
 int ch=0;
 do
 {
  gotoxy(25,10);
  cout<<"1. Create Account";
  cout<<"\n\t\t\t2. Login";
  cout<<"\n\t\t\t3. Exit";
  cout<<"\n\n\n\t\t\tEnter your choice : ";
  cin>>ch;
  switch(ch)
  {
   case 1: create(); break;
   case 2: login(); break;
   case 3: exit(0);
   default: cout<<"Invalid choice";
  }
 }while(ch!=3);
 getch();
}
void main()
{
 frontpg();
 getch();
 home();
}
void create()
{
 textcolor(9);
 clrscr();
 id ida,nid;
 Again:
 ifstream fin;
 fin.open("ida.dat",ios::in|ios::binary);
 clrscr();
 nid.input();
 fin.seekg(0);
 while(fin.read((char*)&ida,sizeof(ida)))
 {
  if(strcmpi(ida.retid(),nid.retid())==0)
  {
   cout<<"\n\n\n\n\t\t\t\tThis ID already exists.\n\t\t\t\tPlease choose some other ID.";
   getch();
   fin.close();
   goto Again;
  }
 }
 fin.close();
 ofstream f1("f1.dat",ios::binary);
 fin.open("ida.dat",ios::in|ios::binary);
 while(fin.read((char*)&ida,sizeof(ida)))
 {
   f1.write((char*)&ida,sizeof(ida));
 }
 f1.write((char*)&nid,sizeof(nid));
 f1.close();
 fin.close();
 remove("ida.dat");
 rename("f1.dat","ida.dat");
 cout<<"\n\n\n\n\t\t\t\t\t\t\t\tID Made :)";
 getch();
 clrscr();
}
void notifme();
void login()
{
 textcolor(3);
 clrscr();
 int a=0;
 char n[20];
 id ida;
 char epass[20];
 page:
 fstream f;
 f.open("ida.dat",ios::in|ios::out|ios::app|ios::binary);
 textcolor(3);
 gotoxy(20,12);
 cout<<"Enter ID - ";
 gets(eid);
 gotoxy(20,16);
 cout<<"Enter Password - ";
 gets(epass);
 int ch,c=0;
 while(f.read((char*)&ida,sizeof(ida)))
 {
  if((strcmp(epass,ida.retpass())==0)&&(strcmp(eid,ida.retid())==0))
  {
   c++;
   textattr(2);
   cprintf("\n\n\n\nVALID");
   getch();
   do
   {
    textcolor(12);
    clrscr();
    cout<<"\n\n\t\t"<<eid;
    cout<<"\n\n\n\t1. Friend Requests\n\n\t2. Messages\n\n\t3. Profile\n\n\t4. Friends\n\n\t5. Send a friend request\n\n\t6. View all people\n\n\t7. Read messages\n\n\t8. Logout\n\n\n\tEnter Your choice : ";
    cin>>ch;
    switch(ch)
    {
     case 1: notiffr(); break;
     case 2: notifme(); break;
     case 3: clrscr(); gotoxy(25,10); ida.profile(); getch(); break;
     case 4: fr(); break;
     case 5: sfr(); break;
     case 6: all(); break;
     case 7: msgall(); break;
     case 8: home(); break;
     default:cout<<"\nInvalid choice";
    }
   }while(ch!=8);
   break;
  }
 }
 if(c==0)
 {
  a++;
  textattr(2);
  cprintf("\n\n\nINVALID");
  getch();
  clrscr();
 }
 if(c==0&&a<3)
 {
  goto page;
 }
 if(a==3)
 {
  textattr(4);
  gotoxy(28,13);
  cprintf("ACCESS DENIED");
  getch();
  clrscr();
 }
 f.close();
}
void all()
{
 textcolor(13);
 clrscr();
 cout<<"\n\n\t\t"<<eid;
 ifstream fin("ida.dat",ios::binary);
 id i;
 gotoxy(16,8);
 cout<<"NAME"<<setw(30)<<"ID";
 cout<<"\n\n";
 while(fin.read((char*)&i,sizeof(i)))
 {
  i.show();
  cout<<"\n";
 }
 fin.close();
 getch();
}
void fr()
{
 textcolor(14);
 clrscr();
 cout<<"\n\n\t\t"<<eid;
 friends f;
 int ch;
 char pid[20];
 ifstream fin("f.dat",ios::binary);
 cout<<"\n\n\n\n\n";
 while(fin.read((char*)&f,sizeof(f)))
 {
   f.showy();
   cout<<"\n";
 }
 getch();
 fin.close();
 clrscr();
 ifstream f1("ida.dat",ios::binary);
 id i;
 do
 {
  gotoxy(20,10);
  cout<<"1. Send Message";
  gotoxy(20,12);
  cout<<"2. Back";
  cin>>ch;
  clrscr();
  switch(ch)
  {
   case 1: messages(); break;
   case 2: break;
   default: cout<<"Invalid Choice";
  }
 }while(ch!=2);
 f1.close();
 clrscr();
}
void sfr()
{
 textcolor(13);
 clrscr();
 cout<<"\n\n\t\t\t"<<eid;
 fstream fout("friends.dat",ios::in|ios::app|ios::binary);
 friends f;
 char m[50];
 id i;
 int c=0;
 f.input();
 fout.write((char*)&f,sizeof(f));
 ifstream fin("ida.dat",ios::binary);
 fout.seekg(0);
 while(fin.read((char*)&i,sizeof(i)))
 {
  if(strcmpi(i.retid(),f.getfid())==0)
  {
   c++;
   cout<<"\n\n\t\tFriend request send";
  }
 }
 fin.seekg(0);
 fout.seekg(0);
 if(c==0)
 {
  ofstream f1("f1.dat",ios::binary);
  cout<<"\n\n\t\tInvalid ID";
  while(fout.read((char*)&f,sizeof(f)))
  {
   while(fin.read((char*)&i,sizeof(i)))
   {
    if(strcmpi(i.retid(),f.getfid())==0)
    {
     f1.write((char*)&f,sizeof(f));
    }
   }
   fin.seekg(0);
  }
  f1.close();
  fout.close();
  remove("friends.dat");
  rename("f1.dat","friends.dat");
 }
 fin.close();
 getch();
}
void addfriend()
{
 clrscr();
 ofstream fout("f.dat",ios::app|ios::binary);
 ifstream fin("friends.dat",ios::binary);
 friends f;
 while(fin.read((char*)&f,sizeof(f)))
 {
  if(strcmpi(eid,f.getfid())==0)
  {
   fout.write((char*)&f,sizeof(f));
  }
 }
 fout.close();
 fin.close();
 remove("friends.dat");
 cout<<"Friend added ";
 getch();
}
void readmsg()
{
 textcolor(13);
 clrscr();
 cout<<"\n\n\t\t\t"<<eid;
 ifstream fin("message.dat",ios::binary);
 ofstream fout("rmessage.dat",ios::app|ios::binary);
 message f;
 cout<<"\n\n";
 while(fin.read((char*)&f,sizeof(f)))
 {
  f.show();
  fout.write((char*)&f,sizeof(f));
 }
 fout.close();
 fin.seekg(0);
 ofstream f1("f2.dat",ios::binary);
 while(fin.read((char*)&f,sizeof(f)))
 {
  if(strcmpi(eid,f.getfid())==0)
  {
   f1.write((char*)&f,sizeof(f));
  }
 }
 f1.close();
 fin.close();
 remove("message.dat");
 rename("f2.dat","message.dat");
 getch();
}
void msgall()
{
 textcolor(10);
 clrscr();
 cout<<"\n\n\t\t\t"<<eid;
 message f;
 ifstream fin("rmessage.dat",ios::binary);
 cout<<"\n\n";
 while(fin.read((char*)&f,sizeof(f)));
 {
  if(strcmpi(eid,f.getfid())==0)
   f.show();
  if(strcmpi(eid,f.getyid())==0)
   f.showmine();
 }
 fin.close();
 getch();
}
void notifme()
{
 clrscr();
 int ch=0;
 ifstream fin("message.dat",ios::binary);
 message f;
 cout<<"\n\n";
 while(fin.read((char*)&f,sizeof(f)))
 {
  if(strcmpi(eid,f.getfid())==0)
  {
   cout<<"\t\tMessages";
   cout<<"\n\n\n\t1. Read\n\t2. Back";
   cin>>ch;
   switch(ch)
   {
    case 1: readmsg(); break;
    case 2: break;
    default:cout<<"Invalid Choice";
   }
   getch();
  }
 }
 fin.close();
}
void notiffr()
{
 clrscr();
 char a;
 ifstream fin("friends.dat",ios::binary);
 friends f;
 cout<<"\n\nFriend Requests - \n\n";
 while(fin.read((char*)&f,sizeof(f)))
 {
  if(strcmp(eid,f.getfid())==0)
  {
   f.showy();
   cout<<"\n\n";
  }
 }
 getch();
 fin.close();
 fin.open("friends.dat",ios::binary);
 ofstream f1("f1.dat",ios::binary);
 while(fin.read((char*)&f,sizeof(f)))
 {
  if(strcmpi(eid,f.getfid())==0)
  {
   int ch;
   gotoxy(20,10);
   cout<<"1. Add friend";
   gotoxy(20,12);
   cout<<"2. Back";
   cin>>ch;
   clrscr();
   switch(ch)
   {
    case 1: cout<<"\nFriend added"; addfriend(); break;
    case 2: break;
    default: cout<<"Invalid choice";
   }
  }
 }
 fin.close();
 getch();
}
void messages()
{
 ofstream fout("message.dat",ios::app|ios::binary);
 message f;
 id i;
 f.inputm();
 fout.write((char*)&f,sizeof(f));
 cout<<"Message Sent";
 fout.close();
}
void frontpg()
{
 randomize();
 textcolor(14);
 clrscr();
 gotoxy(20,50);
 cout<<"\n\n\n\t\t****************************************************\n";
 cout<<"\n\t\t\t\tWELCOME TO ";
 char n[]="#2@&*!p1v$z6shr#@%d";
 char a[]="ConnectUS";
 for(int j=0;a[j];j++)
 {
  for(int i=0;n[i];i++)
  {
   delay(30);
   textcolor(random(16));
   cout<<n[i];
   cout<<"\b";
  }
  textcolor(14);
  cout<<a[j];
 }
 cout<<"\n\t\t****************************************************";
 delay(100);
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     PRESS ANY KEY TO PROCEED .....";
 getch();
 textcolor(7);
 clrscr();
 gotoxy(35,12);
 cout<<"\n\n\n\n\n\n\n  Developed By - ";
 cout<<"\n  Rajat Cambo\n  XII-A | 23";
 getch();
}