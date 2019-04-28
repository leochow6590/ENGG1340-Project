#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"viewrecord.h"
#include"menu.h"
using namespace std;

//This file contains a function that can display previous financial record.//
//When user chose "3" in the menu, this fuction will execute.//
//This function will read "record.txt".//
//Then sort the content by amount, date, type, detail and account.//
//Then display all the record.//
//If user wants to view the record by date, type, detail or account, they can input 1, 2, 3, 4 respectively.//
//The function will sort the record accordingly.//
//Otherwise, user can input "0" to return to main menu.//

int viewrecord(){
  ifstream fin;
  ofstream fout;
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
