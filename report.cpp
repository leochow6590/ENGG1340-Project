#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"report.h"
#include"menu.h"
using namespace std;

int report(){
  ifstream fin;
  ofstream fout;
  double tic=0,tep=0,ratio,kindofic1[100],kindofep1[100];
  //tic & tep mean total income & total expense
  //the two arrays record how much was spent in/ earned from each items
  for (int z=0;z<100;z++){
    kindofic1[z]=0;
    kindofep1[z]=0;
  }  //installing the arrays
  string bmonth, byear, amount, day, month, year, type, detail, account, kindofic[100],kindofep[100];
  //the two arrays are the names of each items of income/ expense
  int choice,ic=0,ep=0;  //ic and ep are the number of items of income and expense
  fin.open("record.txt");
  if(fin.fail()){
    cout<<"No previous record!"<<endl;
    return 0;
  }  //if "record.txt" does not exist, no report can be shown
  cout<<endl;
  cout<<"If you want to return to menu, enter 0."<<endl;  //in case user misclicked and came into this function
  cout<<endl;
  cout<<"Please enter the month and year in the form of MM YYYY. (e.g. 12 2019)"<<endl;  //let the user fill in the month which the user want to have a report on
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
  }  //calculating the total expense and income of that specific month
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
  cout<<(ratio<1?"Looks like you are managing your financial status pretty well! You have saved ":"You have to pay more attention to your financial status because you have lost ");
  cout<<diff;
  cout<<(ratio<1?" dollars this month! :D":" dollars this month :(")<<endl;  //Financial deficit and financial surplus result in different comments
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
      }  //if the array is empty, the item will definitely be a new item
      else{
        for (int z=0;z<ep;z++){
          if (kindofep[z]==detail){
            kindofep1[z]+=stod(amount);
            break;
          }  //to search whether the item currently exist in the array
          if(z==ep-1){
            kindofep[ep]=detail;
            kindofep1[ep]+=stod(amount);
            ep++;
            break;
          }  //if the item does not exist in the array, a new item appear in the array
        }
      }
    }
    //same with income below
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
    string mostep=kindofep[0];  //to find which item the user spend most money on
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
  menu();
  return 0;
}
