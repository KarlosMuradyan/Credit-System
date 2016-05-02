#include <iostream>
#include <string.h>
using namespace std;

struct Client{
    char* name;
    char* surname;
    int  loan;
    int duration_month;
};
int search(Client[], int, char*);
void add(Client*,int&);

int admin()
{
    int n = 0, k = 0, p;
    Client list[100];
    while (k!=5)
    {
        cout << "1.add client, 2.search, 3.delete, 4.print, 5.end" << endl;
        cin >> k;
        switch (k)
        {
            case 1: add(list, n); break;
            case 2: cout << "Enter name of a person you search ";
            char temp[15];
            cin >> temp;
            p = search(list, n, temp);
            if (p == -1)
            cout << "There is no such person";
            else
            {
                Client x = list[p];
                cout << x.name << ' ' << x.surname << endl << " Loan Amount:" << x.loan <<endl<< " Duration in month:" << x.duration_month << 'n';
            }
            break;
            case 5: break;
            /*case 3:erase( &n); break;
            case 4: print(list, n); break;*/
            default:cout << "nermucel chisht hraman "; break;
        }
    }
    return 0;
}
int search(Client x[], int n, char* name){
    for (int i = 0; i < n; i++)
    if ((strcmp(x[i].name, name)==0))
    return i;
    return -1;
}
void add(Client* x, int &n){
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

void user(){
    
}

int main(){
    int c;
    string pass, passprint;
    pass = "1234";
    cout<< "Welcome to our program. If you are admin type 1, if you are user type 2: ";
    cin>>c;
    switch(c){
        case 1:
            cout<<"Input the password: ";
            cin>>passprint;
            if(passprint == pass){
                admin();
            }
            else{
                cout<<"The password is incorrect"<<endl;
            
            };
        break;
        
        case 2:user();
    }
}
