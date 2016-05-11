#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

struct Client{
	char* name;
	char* surname;
	int  loan;
	int duration_loan;
};

int search_client(Client[], int, char*);
void add_client(Client*,int&);
void erase(Client*,int&);
void copy(Client*, int);

int admin(){
	int n = 0, command = 0, search_command;
	Client clients_list[100];

	while (command!=5){
		cout << "1.add client, 2.search, 3.delete, 4.print, 5.end" << endl;
		cin >> command;
		switch (command){
		case 1: add_client(clients_list, n); break;
		case 2: cout << "Enter name of a person you search ";
	                char temp[15];
	                cin >> temp;
	                search_command = search_client(clients_list, n, temp);
	                if (search_command == -1){
	        		cout << "There is no such person";
	                }
		 	else{
	        		Client x = clients_list[search_command];
	                	cout << x.name << ' ' << x.surname << ' ' << x.loan << ' ' << x.duration_loan << ' ' << endl;
	                }break;
           	case 3: cout << "Enter the name of the client you want to delete" << endl;
           		int k;
           		void erase(Client *x,int & k); break;
           	case 4: copy(clients_list, n); break;
           	case 5: break;
	        default:cout << " incorrect command"; break;
	        }
	}
    return 0;
}

int search_client(Client x[], int n, char* name){
        for (int i = 0; i < n; i++){
	        if ((strcmp(x[i].name, name)==0)){
	    		return i;
	        }return -1;
        }
}

void add_client(Client* x, int &n){
    x[n].name = new char[15];
    x[n].surname= new char[15];
    cout << "Name: ";
    cin >> x[n].name;
    cout << "Surname: ";
    cin >> x[n].surname;
    cout << "amount_of_loan: ";
    cin >> x[n].loan;
    cout << "loan_duration: ";
    cin >> x[n].duration_loan;
    n++;
}
void erase(Client* x, int & n){
	char temp[15];
	cin >> temp;
	int p;
	p = search(Client* x, int & n, temp[15]);
	if (p == -1){
		cout<<"There is no such person\n";
		return;
	}
	for (int i = p; i < n - 1; i++){
		strcpy_s(x[i].name,strlen(x[i].name)+1, x[i + 1].name);
		strcpy_s(x[i].surname, strlen(x[i].surname)+1, x[i + 1].surname);
		strcpy_s(x[i].loan, x[i + 1].loan);
		x[i].duration_loan = x[i+1].duration_loan;
	}
	n--;
}
void copy(Client* x, int n){
	for (int i = 0; i < n; i++){
		cout << x[i].name << '\t' << x[i].surname << '\t' << x[i].loan << '\t' << x[i].duration_loan << '\n';
	}
}

int main(){
	int a;
	string password;
	string name;
	string surname;
	struct person1{
        string name = "Armen";
        string surname = "Avetisyan";
        string loan = "200 AMD";
        string duration = "1year";
	};

	cout<< "Welcome to our program. If you are admin type  1, if you are user type  2: ";
	cin>>a;
	switch(a){
		case 1:
			cout<<"Input the password: ";
			cin>>password;
			if(password == "1234"){
				admin();
			}
			else{
				cout<<"The password is incorrect"<<endl;
			};break;
        case 2:
            cout << "Enter your name and surname,please" << endl;
            cin>> name >> surname;
            if((name == person1.name) && (surname == person1.surname)){
                cout << "Here is the information about your credit" << endl;
                cout << "Name: " <<person1.name << endl;
                cout << "Surname: "<< person1.surname << endl;
                cout << "Money: "<<person1.loan << endl;
                cout << "Duration of your credit: " <<person1.duration<< endl;
            }
            else{
                cout << "There is no such a person in the system!"
            }break;
	}
}
