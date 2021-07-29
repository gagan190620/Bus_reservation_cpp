#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>

using namespace std;
class a
{
    char busn[5],driver[10],arrival[10],depart[5],from[10],to[10],seat[8][4][10];
    public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);

}
bus[10];
static int p=0;
void vline(char ch)
{
    for(int i=80;i>0;i--)
    {
      cout<<ch;
    }

}
void a::install()
{
    cout<<"\nEnter bus number:\t";
    cin>>bus[p].busn;
    cout<<"\nEnter driver's name:\t";
    cin>>bus[p].driver;
    cout<<"\nArrival time:\t";
    cin>>bus[p].arrival;
    cout<<"\nDeparture:\t";
    cin>>bus[p].depart;
    cout<<"From:\t";
    cin>>bus[p].from;
    cout<<"To:\t";
    cin>>bus[p].to;
    cout<<endl;
    bus[p].empty();
    p++;
}
void a::allotment()
{
   int seat;
   char number[5];
   top:
   cout<<"Bus number: ";
   cin>>number;
   int n;
   for(n=0;n<=p;n++)
   {
       if(strcmp(bus[n].busn,number)==0)
       break;
   }
   while(n<=p)
   {
       cout<<"\nSeat number: ";
       cin>>seat;
       if(seat>32)
       {
           cout<<"Sorry!! There are only 32 seats available in this bus.";
       }
       else
       {
           if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
           {
               cout<<"Enter passenger's name: ";
               cin>>bus[n].seat[seat/4][(seat%4)-1];
               break;
           }
           else
           {
               cout<<"Seat is already reserved.\n";
           }
       }

   }
   if(n>p)
   {
       cout<<"Enter correct bus no.\n";
       goto top;//using goto statement and calling label top
   }
}
void a::empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void a::show()
{
    int n;
    char number[5];
    cout<<"Bus number: ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busn,number))
        break;
    }
    while(n<=p)
    {
        vline('*');
        cout<<"Bus number: "<<bus[n].busn<<"\n Driver: "<<bus[n].driver<<"\nArrival time: "
        <<bus[n].arrival<<"\nFrom: "<<bus[n].from<<"\n To: "<<bus[n].to;
        vline('*');
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                cout<<"\nThe seat number: "<<(a-1)<<"  is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
    {
        cout<<"Enter orrect bus number: ";
    }
}
void a::position(int i)
{
    int s=0;p=0;
    for(int i=0;i<8;i++)
    {
        cout<<endl;
        for(int j=0;j<4;j++)
        {
            s++;
            if(strcmp(bus[1].seat[i][j],"Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[1].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[1].seat[i][j];
            }
        }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in bus number "<<bus[1].busn;
}

void a::avail()
{
    for(int i=0;i<8;i++)
    {
        vline('*');
        cout<<"Bus number: "<<bus[i].busn<<"\n Driver: "<<bus[i].driver<<"\nArrival time: "
        <<bus[i].arrival<<"\nFrom: "<<bus[i].from<<"\n To: "<<bus[i].to;
        vline('*');
        vline('_');
    }
}

int main()
{
    system("cls");
    int u;
    while(1)
    {
        cout<<"\n\n\n*************************************\n\n";
        cout<<"****************1.INSTALL*******************\n\n"
       <<"****************2.Reservation*******************\n\n"
       <<"****************3.Show*******************\n\n"
       <<"****************4.Buses Available*******************\n\n"
       <<"****************5.Exit*******************\n\n";
       cout<<"Enter your choice: ";
       cin>>u;
       switch(u)
       {
           case 1: bus[p].install();
           break;
           case 2: bus[p].allotment();
           break;
           case 3: bus[p].show();
           break;
           case 4: bus[p].avail();
           break;
           case 5: exit(0);
       }
    }
    return 0;
}
