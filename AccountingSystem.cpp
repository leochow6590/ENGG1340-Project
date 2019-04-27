#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

ifstream fin;
ofstream fout;
int choice;

struct record{
  double amount;
  int day,month,year;
  string type,account,detail;
};

int signin(){
  string username, u, password, cpassword, p;
  fin.open("acc.txt");
  if(fin.fail()){
    cout<<"Please sign up before using the system"<<endl;
    cout<<"Create your username: ";
    getline(cin, username);
    cout<<"Create your password: ";
    getline(cin, password);
    cout<<"Confirm your password: ";
    getline(cin, cpassword);
    while(password!=cpassword){
      cout<<"Please confirm your password by re-entering it"<<endl;
      cout<<"Create your password: ";
      getline(cin, password);
      cout<<"Confirm your password: ";


      getline(cin, cpassword);
    }
    fout.open("acc.txt");
    fout<<username<<endl;
    fout<<password<<endl;
    fout.close();
  }
  else{
    cout<<"Username: ";
    getline(cin, u);
    cout<<"Password: ";
    getline(cin, p);
    getline(fin, username);
    getline(fin, password);
    fin.close();
    while(u!=username or p!=password){
      cout<<"Invalid username or password!"<<endl;
      cout<<"Username: ";
      getline(cin, u);
      cout<<"Password: ";
      getline(cin, p);
    }
    cout<<endl;
    cout<<"Welcome back, "<<username<<"! :D"<<endl;
    cout<<endl;
  }
  return 0;
}

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
  cin>>choice;
  return choice;
}

int addrecord(){
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
  return 0;
}

int editrecord(){
  string amount1, day1, month1, year1, type1, detail1, account1;
  double amount;
  int type;
  int day, month, year;
  string detail, account;
  record record1;
  ofstream temp;
  int i=0,j,on=1;
  fin.open("record.txt");
  if(fin.fail()){
    cout<<"No previous record."<<endl;
    menu();
    return 0;
  }
  cout<<setw(23)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
  cout<<endl;
  while (getline(fin, amount1)){
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
  cout<<"If you want to return to menu, enter 0."<<endl;
  cout<<endl;
  cout<<"Which record would you want to edit?"<<endl;
  cin>>j;
  cout<<endl;
  if (j==0){
    menu();
    return 0;
  }
  else{
    while (j>i||j<1){
      cout<<"Invalid input! Please enter once more."<<endl;
      cin>>j;
    }
  }
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
  fin.close();
  fin.open("record.txt");
  temp.open("temp.txt");
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
  rename("temp.txt","record.txt");
  return 0;
}

