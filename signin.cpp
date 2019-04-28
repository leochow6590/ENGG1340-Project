#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"signin.h"
using namespace std;

//This file contains a function that allows user to sign up or sign in.//
//Whenever user access to the system, this function will be executed.//
//If it is the user's first access, user will be required to input a user name and a password, then confirm the password again.//
//Above inputted information will be stored in "acc.txt"//
//After the first access, user are required to sign in with the username and password that already inputted in the first access.//
//"acc.txt" will be read and the input from user will be compared with the content of "acc.txt".//
//User has to enter correct username and password in oder to sign in.//

int signin(){
  ifstream fin;
  ofstream fout;
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
