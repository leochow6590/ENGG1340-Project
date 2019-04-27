#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"menu.h"
#include"addrecord.h"
#include"checkbudget.h"
#include"editrecord.h"
#include"setbudget.h"
#include"signin.h"
#include"viewrecord.h"
#include"report.h"
using namespace std;

ifstream fin;
ofstream fout;
int choice;

struct record{
  double amount;
  int day,month,year;
  string type,account,detail;
};

int main(){
  int budget;
  string bmonth, byear;
  signin();
  cout<<"*********************************"<<endl;
  cout<<"*Welcome to Financial Assistant!*"<<endl;
  cout<<"*********************************"<<endl;
  checkbudget();
  choice=menu();
  cout<<endl;
  while (choice!=0){
    switch(choice)
    {
      case 1:
        addrecord();
        break;
      case 2:
        editrecord();
        break;
      case 3:
        viewrecord();
        break;
      case 4:
        report();
        break;
      case 5:
        setbudget();
        break;
      //default:
    }
  }
  checkbudget();
  return 0;
}
