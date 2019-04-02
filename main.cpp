#include <iostream>
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#define extended -32
#define upArrow 72
#define downArrow 80
#define homeKey 71
#define endKey 79
#define tap 9
#define ENTER 13
#define MenuArraySize 4
#define MenuWordsLength 41
#define NumberOfEmployees 3
#define currentPostionX 8
#define currentPostionY 4
int X=28;
int Y=4;
int flag=0;                         // flag check which string of menu will be colored
int checkcurrent=0;
int firstTimeDrawmenu=0;

struct employee{
char name[21];
int Code;
int age;
int Salary;
int Bouns;
int Deduct;
int NetSalary;
};
void gotoxy(int,int);
void DisplayText();
void DrawMenu(char[MenuArraySize][MenuWordsLength]);
void DisplayAttributes(int);
void FillEmployeeData(employee[],int,int);
void ShowEmployeeData(employee[],int ,int);

using namespace std;
int main()
{
char myarray[MenuArraySize][MenuWordsLength] ={{"NEW EMPLOYEE"},{"DISPLAY EMPLOYEE"},{"DISPLAY All EMPLOYEES"},{"EXIT"}};     //array of strings to define Menu items
int ExitFromMenu=0;                  // save current postioned colored
char key;
employee emp[NumberOfEmployees];
int employeeNumber;       //this variable used for employee to show or fill
do {
    if(firstTimeDrawmenu==0){
        DrawMenu(myarray);
        firstTimeDrawmenu++;
        }
    key=getch();
    if(key==extended)
        key=getch();
    switch((int)key){
        case tap:
        case downArrow:
            checkcurrent++;
            if(checkcurrent>MenuArraySize-1)
                checkcurrent=0;
            system("CLS");
            flag=0;
            DrawMenu(myarray);
            break;
        case upArrow:
            checkcurrent--;
            if(checkcurrent<0)
                checkcurrent=MenuArraySize-1;
            system("CLS");
            flag=0;
            DrawMenu(myarray);
            break;
        case homeKey:
            checkcurrent=0;
            flag=0;
            system("CLS");
            DrawMenu(myarray);
            break;
        case endKey:
            checkcurrent=MenuArraySize-1;
            flag=0;
            system("CLS");
            DrawMenu(myarray);
            break;
        case ENTER:
            system("CLS");

            gotoxy(X-14,Y);
            switch(checkcurrent){
                case 0:
                    cout<<"Enter Employee Number You Want to fill"<<endl;
                    cin>>employeeNumber;
                    FillEmployeeData(emp,NumberOfEmployees,employeeNumber);
                    break;
                case 1:
                    cout<<"Enter Employee Number You Want to Display"<<endl;
                    cin>>employeeNumber;
                    ShowEmployeeData(emp,NumberOfEmployees ,employeeNumber);
                    break;
                case 2:
                    ShowEmployeeData(emp,NumberOfEmployees,0);
                    break;
                case 3:
                    cout<<"Thank YOU :)"<<endl;
                    ExitFromMenu=1;
                    key=27;
                    break;
                default :
                    cout<<"press menu key only"<<endl<<"press menu Key to go back to menu"<<endl;
                }
            break;
       default :
            cout <<"Choose from a valid key"<<endl;
        }
    if(ExitFromMenu!=0)
    break;
      }
while(key !=27 );
return 0;
    }


void DisplayText(){
cout<<"use UP arrow , Down arrow , HOME key ,END key , tab key to Return\n "<<endl;
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void DrawMenu(char MenuArray[MenuArraySize][MenuWordsLength]){
    system("CLS");
    cout<<"use UP arrow , Down arrow , HOME key ,END key , tab key to navigate\n use ENTER key to select  "<<endl;
    for(int i=0;i<MenuArraySize;i++){
        gotoxy(X,Y++);
        if(flag++==checkcurrent)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x41);
        cout<<MenuArray[i]<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
    }
    X=28;
    Y=4;
    }
void DisplayAttributes(int checkDisplay){
    system("CLS");
    gotoxy(currentPostionX,currentPostionY);
     //display first row
    cout<<"Name:\t";
    gotoxy(currentPostionX+15,currentPostionY);
    cout<<"Code:\t";

     //display first row
    gotoxy(currentPostionX,currentPostionY+2);
    cout<<"Age:\t";
    gotoxy(currentPostionX+15,currentPostionY+2);

   if(checkDisplay==0){
    cout<<"Salary:\t";
 //display third row
    gotoxy(currentPostionX,currentPostionY+4);
    cout<<"Bouns:\t";
    gotoxy(currentPostionX+15,currentPostionY+4);
    cout<<"Deducted:\t";

   }
   else{

     cout<<"NetSalary:\t";
   }
   gotoxy(0,0);
    }
void FillEmployeeData(employee emp[],int size,int NumberOfEmployeeToFill)
{
system("CLS");
DisplayAttributes(0);
for(int i=0;i<size;i++){
    if(NumberOfEmployeeToFill == i+1){
        gotoxy(4,2);
        cout<<"*****Enter employee # "<<i+1<<" Data*****"<<endl;
        gotoxy(currentPostionX + strlen("Name:"),currentPostionY);
        cin>>emp[i].name;
        gotoxy(currentPostionX +15+ strlen("Code:"),currentPostionY);
        cin>>emp[i].Code;
        gotoxy(currentPostionX + strlen("Age:"),currentPostionY+2);
        cin>>emp[i].age;
        gotoxy(currentPostionX +15+ strlen("Salary:"),currentPostionY+2);
        cin>>emp[i].Salary;
        gotoxy(currentPostionX + strlen("Bouns:"),currentPostionY+4);
        cin>>emp[i].Bouns;
        gotoxy(currentPostionX +15+ strlen("Deducted:"),currentPostionY+4);
        cin>>emp[i].Deduct;
        gotoxy(currentPostionX,currentPostionY+6);
        cout<<" NEXT >>"<<endl;
        getch();
            }
        }
firstTimeDrawmenu=0;
flag=0;
}
void ShowEmployeeData(employee emp[],int size, int employeeNumber){
int temp=employeeNumber;
for(int i=0;i<size;i++){
    if(employeeNumber==0){
        temp=temp +1;
        }
    if(i+1 ==temp ){
        system("CLS");
        DisplayAttributes(1);
        cout<<"***** employee # "<<i+1<<" Data*****"<<endl;
        gotoxy(currentPostionX + strlen("Name:"),currentPostionY);
        cout<<emp[i].name;
        gotoxy(currentPostionX +15+ strlen("Code:"),currentPostionY);
        cout<<emp[i].Code;
        gotoxy(currentPostionX + strlen("Age:"),currentPostionY+2);
        cout<<emp[i].age;
        gotoxy(currentPostionX +15+ strlen("NetSalary:"),currentPostionY+2);
        emp[i].NetSalary=emp[i].Salary+ emp[i].Bouns - emp[i].Deduct;
        cout<<emp[i].NetSalary;
        gotoxy(currentPostionX,currentPostionY+6);
        cout<<" NEXT >>"<<endl;
        if(i<size);
            getch();
        }
 }
 firstTimeDrawmenu=0;
 flag=0;
}



