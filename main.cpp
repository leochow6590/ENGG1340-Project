include <iostream>
include <string>
using namespace std;
int main(){
  string username, u, password, cpassword, p;
  if(username==NULL){
    cout<<"Please sign up before using the system"
    cout<<"Create your username: ";
    getline(cin, username);
    cout<<"Create your password: ";
    getline(cin, password);
    cout<<"Confirm your password: ";
    getline(cin, cpassword);
    while(password!=cpassword){
      cout<<"Please confirm your password by re-entering it";
      cout<<"Create your password: ";
      getline(cin, password);
      cout<<"Confirm your password: ";
      getline(cin, cpassword);
    }
  }
  else{
    cout<<"Username: ";
    getline(cin, u);
    cout<<"Password: ";
    getline(cin, p);
    while(u!=username or p!=password){
      cout<<"Invalid username or password!";
      cout<<"Username: ";
      getline(cin, u);
      cout<<"Password: ";
      getline(cin, p);
    }
    cout<<"Welcome back, ",username<<endl;
  }
}
