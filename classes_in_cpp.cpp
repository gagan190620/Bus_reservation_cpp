#include <iostream>
using namespace std;
class sec
{
    private:
        int seconds;
        int hh,mm,ss;
    public:
        void putime(void);
        void contime(void);
        void getime(void);
};
void sec::putime(void)
{
    cout << "Enter time in (HH:MM:SS): " << endl;
    cout << "HH:  ";          
    cin >> hh;
    cout << "MM:  ";          
    cin >> mm;
    cout << "SS:  ";          
    cin >> ss;
}
void sec::contime(void)
{
    seconds = hh*3600 + mm*60 + ss;
}
void sec::getime(void)
{
    cout << "Time in total seconds: " << seconds;
}
 int main()
{
    cout<<"Heyy!! Wanna convert time in to seconds???\n";
    cout<<"I have solution...\n";
    sec T; 
    T.putime();
    T.contime();
    cout<<"\nYour time in seconds is...\n";
    T.getime();
     
    return 0;
}
