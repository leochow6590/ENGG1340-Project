#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"addrecord.h"
#include"menu.h"
using namespace std;

struct record{
  double amount;
  int day,month,year;
  string type,account,detail;
};

int addrecord(){
  ifstream fin;
  ofstream fout;
  record record1;
  double amount;
  int type,on=1;
  int day, month, year;
  string detail, account;
  cout<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;
  cout<<endl;
  cout<<"Please enter the information of your record."<<endl;
  cout<<"1. Income or 2. Expense (Enter the number.)"<<endl;
  cin>>type;
  while (on==1){
    switch (type)
    {
      case 0:
        menu();
        return 0;
      case 1:
        record1.type="Income";
        on=0;
        break;
      case 2:
        record1.type="Expense";
        on=0;
        break;
      default:
        cout<<"Invalid input! Please enter once more."<<endl;
        cin>>type;
    }
  }

  cout<<"What kind of ";
  cout<<(type==1?"income ":"expense ");
  cout<<"is that? (e.g. food, game, salary, etc.)"<<endl;
  cin.ignore();
  getline(cin, detail);
  if (detail=="0"){
    menu();
    return 0;
  }
  record1.detail=detail;

  cout<<"Please enter the account used. (e.g. cash, bank card, credit card, etc.)"<<endl;
  getline(cin, account);
  if (account=="0"){
    menu();
    return 0;
  }
  record1.account=account;

  cout<<"Please enter the amount: ";
  cin>>amount;
  if (amount==0){
    menu();
    return 0;
  }
  else
    record1.amount=amount;

  cout<<"Please enter the date in the form of DD MM YYYY. (e.g. 25 12 2019)"<<endl;
  on=1;
  cin>>day;
  cin>>month;
  cin>>year;
  if (day==0||month==0||year==0){
    menu();
    return 0;
  }
  while (on==1){
    if (day>31||day<1||month<1||month>12||year<2019){
      cout<<"Invalid input! Please enter once more."<<endl;
      cin>>day;
      cin>>month;
      cin>>year;
    }
    else{
      record1.day=day;
      record1.month=month;
      record1.year=year;
      on=0;
    }
  }

  fout.open("record.txt",ios::app);
  fout<<fixed<<setprecision(2)<<record1.amount<<endl;
  fout<<record1.day<<endl;
  fout<<record1.month<<endl;
  fout<<record1.year<<endl;
  fout<<record1.type<<endl;
  fout<<record1.detail<<endl;
  fout<<record1.account<<endl;
  fout.close();
  cout<<endl;
  cout<<"***The record has been added successfully :D***"<<endl;
  menu();
  return 0;
}
