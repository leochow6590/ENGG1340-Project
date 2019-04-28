#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"menu.h"
using namespace std;

int menu(){
  cout<<endl;
  cout<<"What do you want to do now?"<<endl;
  cout<<"1. Add new record of income/expenses."<<endl;
  cout<<"2. Edit previous records."<<endl;
  cout<<"3. View previous records."<<endl;
  cout<<"4. View statistical financial report."<<endl;
  cout<<"5. Budget setting"<<endl;
  cout<<"0. Quit"<<endl;
  cout<<"Please enter your choice: ";
  return 0;
}
