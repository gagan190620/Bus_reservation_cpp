#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;
int main()
{
    
  FILE *fp, *ft;
  char another, choice;
  struct student
  {
      char first_name[50],last_name[50];
      char course[100];
      int section;
  };
  struct student e;
  char xfirst_name[50],xlast_name[50];
  long int recsize;
  fp=fopen("users.txt","rb+");
  if(fp==NULL)
  {
      fp=fopen("users.txt","wb+");
      if(fp==NULL)
      {
          puts("Cannot open file");
          return 0;
      }
  }
  recsize=sizeof(e);
  while(1)
  {
      
      system("cls");
      cout<<"\n\n*********STUDENT DATABASE MANAGEMENT SYSTEM*********\n\n";
      cout<<"1.Add records";
      cout<<"\n2.List records";
      cout<<"\n3.Modify record";
      cout<<"\n4.Delete record";
      cout<<"\n5.Exit";
      cout<<"\n\nSelect your choice...\n";
      fflush(stdin);
      
      choice=getchar();
      
      switch(choice)
      {
          case '1':fseek(fp,0,SEEK_END);
          another='Y';
          while(another=='Y'||another=='y')
          {
              system("cls");
              cout<<"Enter First name:  ";
              cin>>e.first_name;
              cout<<"Enter Last name:  ";
              cin>>e.last_name;
              cout<<"Enter the course:  ";
              cin>>e.course;
              cout<<"Enter section:  ";
              cin>>e.section;
              fwrite(&e,recsize,1,fp);
              cout<<"\nAdd another record (Y/N)";
              fflush(stdin);
              another=getchar();
          }
          break;
          case '2':
          system("cls");
          rewind(fp);
          cout<<"-------View records in database--------\n\n";
          cout<<"\n\n";
          while(fread(&e,recsize,1,fp)==1)
          {
              cout<<e.first_name<<setw(10)<<e.last_name<<endl;
              cout<<e.course<<setw(10)<<e.section<<endl;
          }
          system("pause");
          break;
          case '3':
          system("cls");
          another='Y';
          while(another=='Y'||another=='y')
          {
              cout<<"Enter last name of student: ";
              cin>>xlast_name;
              rewind(fp);
              while(fread(&e,recsize,1,fp)==1)
              {
                  if(strcmp(e.last_name,xlast_name)==0)
                  {
                      cout<<"Enter New First name:  ";
                      cin>>e.first_name;
                      cout<<"Enter New Last name:  ";
                      cin>>e.last_name;
                      cout<<"Enter the course:  ";
                      cin>>e.course;
                      cout<<"Enter section:  ";
                      cin>>e.section;
                      fseek(fp,- recsize,SEEK_CUR);
                      fwrite(&e,recsize,1,fp);
                      break;
                  }
                  else
                  cout<<"RECORD NOT FOUND!!!";
              }
              cout<<"Modify another record(Y/N)";
              fflush(stdin);
              another=getchar();
          }
          break;
          case '4':
          system("cls");
          another='Y';
          while(another=='Y'||another=='y')
          {
              cout<<"Enter last name of student to delete:  ";
              cin>>xlast_name;
              ft=fopen("temp.dat","wb");
              rewind(fp);
              while(fread(&e,recsize,1,fp)==1)
              {
                  if(strcmp(e.last_name,xlast_name)!=0)
                  {
                      fwrite(&e,recsize,1,ft);
                  }
                  fclose(fp);
                  fclose(ft);
                  remove("users.txt");
                  rename("temp.dat","users.txt");
                  fp=fopen("users.txt","rb+");
                  cout<<"Delete another record(Y/N)";
                  fflush(stdin);
                  another=getchar();
          }
          break;
          case '5': 
          fclose(fp);
          cout<<"THANK YOU...";
          exit(0);
    }
  }
  system("pause");
 return 0;
} 
}
