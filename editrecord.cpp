#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"editrecord.h"
#include"menu.h"
using namespace std;

struct record{
  double amount;
  int day,month,year;
  string type,account,detail;
};

int editrecord(){
  ifstream fin;
  ofstream fout;
  string amount1, day1, month1, year1, type1, detail1, account1;
  double amount;
  int type;
  int day, month, year;
  string detail, account;
  record record1;
  ofstream temp;
  int i=0,j,on=1;
  fin.open("record.txt");
  if(fin.fail()){  //if "record.txt" does not exist, it means no record was added previously so nothing can be edited
    cout<<"No previous record."<<endl;
    menu();
    return 0;
  }
  cout<<setw(23)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
  cout<<endl;
  while (getline(fin, amount1)){  //show all the records which were added previously
    i++;
    getline(fin, day1);
    getline(fin, month1);
    getline(fin, year1);
    getline(fin, type1);
    getline(fin, detail1);
    getline(fin, account1);
    cout<<setw(3)<<i;
    cout<<setw(20)<<amount1;
    cout<<setw(20)<<day1+"/"+month1+"/"+year1;
    cout<<setw(20)<<type1;
    cout<<setw(20)<<detail1;
    cout<<setw(20)<<account1<<endl;
  }
  cout<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;  //just in case the user misclick and come into this function
  cout<<endl;
  cout<<"Which record would you want to edit?"<<endl;
  cin>>j;
  cout<<endl;
  if (j==0){
    menu();    //back to menu by entering "0"
    return 0;
  }
  else{
    while (j>i||j<1){
      cout<<"Invalid input! Please enter once more."<<endl;  //re-input if there is no record with the chosen number
      cin>>j;
    }
  }
  cout<<"Please enter the information of your record."<<endl;  //update the information of the record
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
  fin.close();
  fin.open("record.txt");
  temp.open("temp.txt");  //the records which do not need to be edited are directly being output into "temp.txt", while the edited record will be outputed based on the information filled in during the run of this function
  for (int l=1;l<=i;l++){
    if (l!=j){
      getline(fin, amount1);
      getline(fin, day1);
      getline(fin, month1);
      getline(fin, year1);
      getline(fin, type1);
      getline(fin, detail1);
      getline(fin, account1);
      temp<<amount1<<endl;
      temp<<day1<<endl;
      temp<<month1<<endl;
      temp<<year1<<endl;
      temp<<type1<<endl;
      temp<<detail1<<endl;
      temp<<account1<<endl;
      }
    else{
      temp<<fixed<<setprecision(2)<<record1.amount<<endl;
      temp<<record1.day<<endl;
      temp<<record1.month<<endl;
      temp<<record1.year<<endl;
      temp<<record1.type<<endl;
      temp<<record1.detail<<endl;
      temp<<record1.account<<endl;
    }

  }
  temp.close();
  fin.close();
  remove("record.txt");
  rename("temp.txt","record.txt");  //turn "temp.txt" into "record.txt"
  cout<<endl;
  cout<<"***The record has been edited successfully! :D***"<<endl;
  cout<<endl;
  menu();
  return 0;
}
