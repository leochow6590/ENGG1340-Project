#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"setbudget.h"
#include"menu.h"
using namespace std;

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
