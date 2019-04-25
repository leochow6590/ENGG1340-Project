#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
  string username, u, password, cpassword, p;
  ifstream fin1;
  fin1.open("acc.txt");
  if(fin1.fail()){
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
    ofstream fout1;
    fout1.open("acc.txt");
    fout1<<username<<endl;
    fout1<<password<<endl;
    fout1.close();
  }
  else{
    cout<<"Username: ";
    getline(cin, u);
    cout<<"Password: ";
    getline(cin, p);
    getline(fin1, username);
    getline(fin1, password);
    fin1.close();
    while(u!=username or p!=password){
      cout<<"Invalid username or password!"<<endl;
      cout<<"Username: ";
      getline(cin, u);
      cout<<"Password: ";
      getline(cin, p);
    }
    cout<<"Welcome back, "<<username<<endl;
  }
}
