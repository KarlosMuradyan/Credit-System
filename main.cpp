#include <iostream>
#include <string.h>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <utility>


using namespace std;

struct Client{
    string name;
    string surname;
    int  loan;
    int duration_month;
};
int search(Client[], int, char*);
void add(Client [],int&);



std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}

void read(Client list[]){
    int i;
    string line;
    ifstream info ("new.txt");         //open a file
    if(info.is_open()){                //checking the open status of file
        i=0;
        while(!info.eof()){            //checking if we reached to the end of a file
            getline(info, line);       
            auto person_info_array = explode(line, '|');
            
            // string str(person_info_array[0].begin(), person_info_array[0].end());
            // list[i].name = str;
            // list[i].surname = person_info_array[1];
            // list[i].loan = stoi(person_info_array[2]);
            // list[i].duration_month = stoi(person_info_array[3]);
            i++;
        }
    }
    else{
        cout<<"false"<<endl;
    }
    info.close();
    
}



int admin()
{
    
    int n=0, k = 0, p;
    Client list[100];
    while (k!=5)
    {
        
        read(list);
        cout<<"Here is the name: "<<list[1].name<<endl;
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
    if (x[i].name == name)
    return i;
    return -1;
}
void add(Client x[], int &n){
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
    
    ofstream info("new.txt", ios_base::app);   //opening file for adding new info
    info<<x[n].name<<" | ";
    info<<x[n].surname<<" | ";
    info<<x[n].loan<<" | ";
    info<<x[n].duration_month<<endl;
    info.close();
    
    n++;
}

void user(){
    
}

int main(){
    int c;
    string passprint;
    cout<< "Welcome to our program. If you are admin type 1, if you are user type 2: ";
    cin>>c;
    switch(c){
        case 1:
            cout<<"Input the password: ";
            cin>>passprint;
            if(passprint == "1234"){
                admin();
            }
            else{
                cout<<"The password is incorrect"<<endl;
            
            };
        break;
        
        case 2:user();
    }
}
