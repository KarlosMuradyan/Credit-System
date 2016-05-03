#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Client{
	char* name;
	char* surname;
	int  loan;
	int duration_month;
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
	                	cout << x.name << ' ' << x.surname << ' ' << x.loan << ' ' << x.duration_month << ' ' << endl;
	                }break;
           	case 3: cout << "Enter the name of the client you want to delete" << endl;
           		int k;
           		erase(Client* ,int & k); break;
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
    cin >> x[n].duration_month;
    n++;
}
void erase(Client* x, int & n){
	char temp[15];
	cin >> temp;
	int p = search(x, n, temp);
	if (p == -1){
		cout<<"There is no such person\n";
		return;
	}
}
	for (int i = p; i < n - 1; i++){
		strcpy_s(x[i].name,strlen(x[i].name)+1, x[i + 1].name);
		strcpy_s(x[i].surname, strlen(x[i].surname)+1, x[i + 1].surname);
		strcpy_s(x[i].loan, x[i + 1].loan);
		x[i].loan_duration = x[i+1].duration_loan;
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
			};
		break;
	}
}
