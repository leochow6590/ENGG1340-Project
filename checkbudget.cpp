#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"checkbudget.h"
#include"menu.h"
using namespace std;

//This file is a function that check weather the monthly expense exceeds the monthly budget.//
//No input is required in this function.//
//This function will automatically check everytime the system is started or quited.//
//If the expense exceeds the budget, an alert will appear whnever the user signed in or quited.//

int checkbudget(){
  ifstream fin;
  ofstream fout;
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
