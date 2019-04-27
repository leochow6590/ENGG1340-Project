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

int viewrecord(){
  string amount, day, month, year, type, detail, account, search, sday, smonth, syear;
  int option,i=0;
  fin.open("record.txt");
  if(fin.fail()){
    cout<<"No previous record."<<endl;
    menu();
    return 0;
  }
  cout<<endl;
  cout<<setw(23)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
  cout<<endl;
  while (getline(fin, amount)){
    i++;
    getline(fin, day);
    getline(fin, month);
    getline(fin, year);
    getline(fin, type);
    getline(fin, detail);
    getline(fin, account);
    cout<<setw(3)<<i;
    cout<<setw(20)<<amount;
    cout<<setw(20)<<day+"/"+month+"/"+year;
    cout<<setw(20)<<type;
    cout<<setw(20)<<detail;
    cout<<setw(20)<<account<<endl;
  }
  fin.close();
  cout<<"If you want to view previous record by 1)date, 2)type, 3)detail and 4)account, please enter the corresponding number."<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;
  cin>>option;
  while(option!=0){
    if(option==1){
      cout<<endl;
      cout<<"Please enter the date in the form of DD MM YYYY. (e.g. 25 12 2019)"<<endl;
      cin>>sday>>smonth>>syear;
      cout<<endl;
      cout<<setw(20)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
      cout<<endl;
      fin.open("record.txt");
      i=0;
      while (getline(fin, amount)){
        getline(fin, day);
        getline(fin, month);
        getline(fin, year);
        getline(fin, type);
        getline(fin, detail);
        getline(fin, account);
        if(sday==day && smonth==month && syear==year){
          i++;
          cout<<setw(3)<<i;
          cout<<setw(20)<<amount;
          cout<<setw(20)<<day+"/"+month+"/"+year;
          cout<<setw(20)<<type;
          cout<<setw(20)<<detail;
          cout<<setw(20)<<account<<endl;
        }
      }
      fin.close();
    }
    if(option==2){
      cout<<endl;
      cout<<"Please enter the type of record. (Income/Expense)"<<endl;
      cin>>search;
      while(search!="Income" && search!="Expense"){
        cout<<"Invalid input! Please enter once more."<<endl;
        cin>>search;
      }
      cout<<setw(20)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
      cout<<endl;
      fin.open("record.txt");
      i=0;
      while (getline(fin, amount)){
        getline(fin, day);
        getline(fin, month);
        getline(fin, year);
        getline(fin, type);
        getline(fin, detail);
        getline(fin, account);
        if(search==type){
          i++;
          cout<<setw(3)<<i;
          cout<<setw(20)<<amount;
          cout<<setw(20)<<day+"/"+month+"/"+year;
          cout<<setw(20)<<type;
          cout<<setw(20)<<detail;
          cout<<setw(20)<<account<<endl;
        }
      }
      fin.close();
    }
    if(option==3){
      cout<<endl;
      cout<<"Please enter the detail of record. (e.g. food, game, salary, etc.)"<<endl;
      cin.ignore();
      getline(cin, search);
      cout<<setw(20)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
      cout<<endl;
      fin.open("record.txt");
      i=0;
      while (getline(fin, amount)){
        getline(fin, day);
        getline(fin, month);
        getline(fin, year);
        getline(fin, type);
        getline(fin, detail);
        getline(fin, account);
        if(search==detail){
          i++;
          cout<<setw(3)<<i;
          cout<<setw(20)<<amount;
          cout<<setw(20)<<day+"/"+month+"/"+year;
          cout<<setw(20)<<type;
          cout<<setw(20)<<detail;
          cout<<setw(20)<<account<<endl;
        }
      }
      fin.close();
    }
    if(option==4){
      cout<<endl;
      cout<<"Please enter the account you want to see."<<endl;
      cin.ignore();
      getline(cin, search);
      cout<<setw(20)<<"Amount"<<setw(20)<<"Date"<<setw(20)<<"Type"<<setw(20)<<"Detail"<<setw(20)<<"Account"<<endl;
      cout<<endl;
      fin.open("record.txt");
      i=0;
      while (getline(fin, amount)){
        getline(fin, day);
        getline(fin, month);
        getline(fin, year);
        getline(fin, type);
        getline(fin, detail);
        getline(fin, account);
        if(search==account){
          i++;
          cout<<setw(3)<<i;
          cout<<setw(20)<<amount;
          cout<<setw(20)<<day+"/"+month+"/"+year;
          cout<<setw(20)<<type;
          cout<<setw(20)<<detail;
          cout<<setw(20)<<account<<endl;
        }
      }
      fin.close();
    }
    cout<<endl;
    cout<<"If you want to view previous record by 1)date, 2)type, 3)detail and 4)account, please enter the corresponding number."<<endl;
    cout<<"If you want to return to menu, enter 0."<<endl;
    cin>>option;
  }
  cout<<endl;
  menu();
  return 0;
}

int setbudget(){
  double budget;
  int sbchoice;
  string bmonth, byear;
  cout<<endl;
  cout<<"You may set a monthly budget here."<<endl;
  cout<<"Once your monthly expense exceeds your budget, you will receive an alert whenever you start and quit the system."<<endl;
  cout<<"If you want to continue, enter 1."<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;
  cin>>sbchoice;
  while(sbchoice!=1 && sbchoice!=0){
    cout<<"Invalid input!"<<endl;
    cout<<"Please enter again."<<endl;
    cin>>sbchoice;
  }
  if(sbchoice==0){
    menu();
    return 0;
  }
  else{
    cout<<endl;
    cout<<"Please enter the month and year in the form of MM YYYY. (e.g. 12 2019)"<<endl;
    cin>>bmonth>>byear;
    cout<<"Please enter the budget."<<endl;
    cin>>budget;
    fout.open("budget.txt");
    fout<<bmonth<<endl;
    fout<<byear<<endl;
    fout<<fixed<<setprecision(2)<<budget<<endl;
    fout.close();
    menu();
  }
  return 0;
}

int checkbudget(){
  ifstream fbudget;
  double budget, totalexpense=0;
  string bmonth, byear, amount, day, month, year, type, detail, account;
  fbudget.open("budget.txt");
  if(fbudget.fail()){
    return 0;
  }
  fin.open("record.txt");
  if(fin.fail()){
    return 0;
  }
  fbudget>>bmonth>>byear>>budget;
  while (getline(fin, amount)){
    getline(fin, day);
    getline(fin, month);
    getline(fin, year);
    getline(fin, type);
    getline(fin, detail);
    getline(fin, account);
    if(bmonth==month && byear==year && type=="Expense"){
      totalexpense+=stod(amount);
    }
  }
  if(totalexpense>budget){
    cout<<"Your expense ("<<fixed<<setprecision(2)<<totalexpense<<") in "<<bmonth+"/"+byear<<" exceeded your budget ("<<fixed<<setprecision(2)<<budget<<") !!!"<<endl;
    cout<<"Please start managing your financial status now!!!"<<endl;
  }
  fin.close();
  fbudget.close();
  return 0;
}

int report(){
  double tic=0,tep=0,ratio,kindofic1[100],kindofep1[100]; //total income & total expense
  for (int z=0;z<100;z++){
    kindofic1[z]=0;
    kindofep1[z]=0;
  }
  string bmonth, byear, amount, day, month, year, type, detail, account, kindofic[100],kindofep[100];
  int choice,ic=0,ep=0;
  fin.open("record.txt");
  if(fin.fail()){
    cout<<"No previous record!"<<endl;
    return 0;
  }
  cout<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;
  cout<<endl;
  cout<<"Please enter the month and year in the form of MM YYYY. (e.g. 12 2019)"<<endl;
  cin>>bmonth;
  if (bmonth=="0"){
    fin.close();
    menu();
    return 0;
  }
  cin>>byear;
  while (getline(fin, amount)){
    getline(fin, day);
    getline(fin, month);
    getline(fin, year);
    getline(fin, type);
    getline(fin, detail);
    getline(fin, account);
    if(bmonth==month && byear==year && type=="Expense"){
      tep+=stod(amount);
    }
    else if(bmonth==month && byear==year && type=="Income"){
      tic+=stod(amount);
    }
  }
  ratio=tep/tic;
  cout<<endl;
  cout<<"Here is your monthly financial report."<<endl;
  cout<<setw(15)<<"Income"<<setw(15)<<"Expense"<<setw(31)<<"Income to Expense ratio"<<endl;
  cout<<fixed;
  cout<<setprecision(2)<<setw(15)<<tic<<setw(15)<<tep<<setw(27)<<"1:"<<ratio<<endl;
  fin.close();
  cout<<endl;
  double diff=tic-tep;
  if (diff<0)
    diff=-diff;
  cout<<(ratio<1?"Looks like you are managing your financial status pretty well! You have saved ":"You have to pay more attention to your financial status because you have lost ")<<endl;
  cout<<diff;
  cout<<(ratio<1?" dollars this month! :D":" dollars this month :(")<<endl;
  cout<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;
  cout<<"If you want to have a further understanding of your financial status, enter 1."<<endl;
  cin>>choice;
  while(choice!=1 && choice!=0){
    cout<<"Invalid input!"<<endl;
    cout<<"Please enter again."<<endl;
    cin>>choice;
  }
  if(choice==0){
    menu();
    return 0;
  }
  else{
    fin.open("record.txt");
    while (getline(fin, amount)){
    getline(fin, day);
    getline(fin, month);
    getline(fin, year);
    getline(fin, type);
    getline(fin, detail);
    getline(fin, account);
    if(bmonth==month && byear==year && type=="Expense"){
      if (ep==0){
        kindofep[0]=detail;
        kindofep1[0]+=stod(amount);
        ep++;
      }
      else{
        for (int z=0;z<ep;z++){
          if (kindofep[z]==detail){
            kindofep1[z]+=stod(amount);
            break;
          }
          if(z==ep-1){
            kindofep[ep]=detail;
            kindofep1[ep]+=stod(amount);
            ep++;
            break;
          }
        }
      }
    }
    else if(bmonth==month && byear==year && type=="Income"){
      if (ic==0){
        kindofic[0]=detail;
        kindofic1[0]+=stod(amount);
        ic++;
      }
      else{
        for (int z=0;z<ic;z++){
          if (kindofic[z]==detail){
            kindofic1[z]+=stod(amount);
            break;
          }
          if(z==ic-1){
            kindofic[ic]=detail;
            kindofic1[ic]+=stod(amount);
            ic++;
            break;
          }
        }
      }
    }
  }
    cout<<endl;
    cout<<setw(15)<<"Kind of Expense"<<setw(15)<<"Percentage"<<setw(30)<<"Kind of Income"<<setw(15)<<"Percentage"<<endl;
    int big=ep;
    string mostep=kindofep[0];
    double mostep1=kindofep1[0];
    if (ic>ep)
      big=ic;
    for (int z=0;z<big;z++){
      if (kindofep1[z]>mostep1){
        mostep1=kindofep1[z];
        mostep=kindofep[z];
        }
      if (kindofep1[z]==0)
        cout<<setw(15)<<kindofep[z]<<setw(15)<<kindofep[z]<<setw(30)<<kindofic[z]<<setw(15)<<kindofic1[z]*100/tic<<endl;
      else if (kindofic1[z]==0)
        cout<<setw(15)<<kindofep[z]<<setw(15)<<kindofep1[z]*100/tep<<setw(30)<<kindofic[z]<<setw(15)<<kindofic[z]<<endl;
      else 
        cout<<setw(15)<<kindofep[z]<<setw(15)<<kindofep1[z]*100/tep<<setw(30)<<kindofic[z]<<setw(15)<<kindofic1[z]*100/tic<<endl;
    }
    cout<<endl;
    cout<<"Looks like you spent most of your money on "<<mostep<<", perhaps reducing expense on this item can save you more money!"<<endl;
    fin.close();
  }
  
  return 0;
}

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
