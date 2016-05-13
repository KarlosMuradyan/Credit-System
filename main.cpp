#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
#include <cassert>
#include <string.h>

//using namespace std;

struct Client{
    std::string name;
    std::string surname;
    int  loan;
    int duration_month;
    int monthly_payment;
    int monthly_percentage;
    std::string password;
};
int search(Client[], int, char*);
void add(Client [],int&);
void print(Client [], int);
void erase(Client [],int&);



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

int read(Client list[]){
    int i;
    std::string line;
    std::ifstream info ("new.txt");         //open a file
    if(info.is_open()){                //checking the open status of file
        i=0;
        //while (!info.eof()) { //checking if we reached to the end of a file
        while ( getline(info, line)) { //checking if we reached to the end of a file
            auto person_info_array = explode(line, '|');
            if (5 > person_info_array.size()) {
                std::cout << "No any information in the text file yet. Firstly, please add clients." << std::endl;
                break;
            }
            else{
            // string str(person_info_array[0].begin(), person_info_array[0].end());
                list[i].name = person_info_array[0];
                list[i].surname = person_info_array[1];
                list[i].password = person_info_array[2];
                list[i].loan = stoi(person_info_array[3]);
                list[i].duration_month = stoi(person_info_array[4]);
                i++;
            }
        }
    }
    else{
        std::cout<<"false"<<std::endl;
    }
    info.close();
    return i;
}



int admin()
{
    
    int n=0, k = 0, status_of_search;
    Client list[100];
    while (k!=5)
    {
        
        n = read(list);
        std::cout << "1.add client, 2.search, 3.delete, 4.print, 5.end" << std::endl;
        std::cin >> k;
        switch (k)
        {
            case 1: add(list, n); break;
            case 2: std::cout << "Enter name of a person you search ";
                char temp[15];
                std::cin >> temp;
                search(list, n, temp);break;
            case 3:erase( list, n); break;
            case 4: print(list, n); break;
            case 5: break;
            default: std::cout << "Enter right command"; break;
        }
    }
    return 0;
}
int search(Client x[], int n, char* name){
      bool temp=false;
    	for (int i = 0; i < n; i++)
        if (x[i].name == name)
        {
           temp=true;
            std::cout << "Name Surname:"<<x[i].name <<' '<< x[i].surname <<std::endl <<"Your password is: "<<x[i].password<<std::endl<< "Loan Amount:" << x[i].loan <<std::endl<<"Duration in month:" << x[i].duration_month <<std::endl<<"Your monthly payment is: "<<x[i].monthly_payment<<" AMD"<<std::endl<<"Your monthly percentage is: "<<x[i].monthly_percentage<<"%"<<std::endl;
        }
        if (!temp) 
        std::cout<<"There is no such person\n";
    return 0;
 
}
void add(Client x[], int &n){
    x[n].name = new char[15];
    x[n].surname= new char[15];  
    
    std::cout << "Name: ";
    std::cin >> x[n].name;
    std::cout << "Surname: ";
    std::cin >> x[n].surname;
    std::cout<<"Password: ";
    std::cin>>x[n].password;
    std::cout << "amount_of_loan: ";
    std::cin >> x[n].loan;
    std::cout << "loan_duration: ";
    std::cin >> x[n].duration_month;
    
    
    std::ofstream info("new.txt", std::ios_base::app);   //opening file for adding new info
    info<<x[n].name<<"|";
    info<<x[n].surname<<"|";
    info<<x[n].password<<"|";
    info<<x[n].loan<<"|";
    info<<x[n].duration_month<<std::endl;
    info.close();
    
    n++;
}
void print(Client x[], int n){
	for (int i = 0; i < n; i++){
		std::cout << x[i].name << '\t' << x[i].surname << '\t'<<x[i].password<< '\t'<< x[i].loan << '\t' << x[i].duration_month << '\n';
	}
}
void erase(Client x[], int &n){
    char temp[15];
	std::cin >> temp;
    int p = search(x, n, temp);
	if (p == -1){
		std::cout<<"There is no such person\n";
	}
	else{
	    for (int i=p;i<n-1;i++)
	    {
	        x[i].name=x[i+1].name;
	        x[i].surname=x[i+1].surname;
	        x[i].password=x[i+1].password;
	        x[i].loan=x[i + 1].loan;
	        x[i].duration_month=x[i + 1].duration_month;
	    }
	   n--;
    }
    
    std::ofstream info("new.txt");   //opening file for adding new info
    for(int i=0; i<n; i++){
        
        info<<x[i].name<<"|";
        info<<x[i].surname<<"|";
        info<<x[i].password<<"|";
        info<<x[i].loan<<"|";
        info<<x[i].duration_month<<std::endl;
       
    }
     info.close();
}
void user(){
    
}

int main(){
    int c;
    std::string passprint;
    std::cout<< "Welcome to our program. If you are admin type 1, if you are user type 2: ";
    std::cin>>c;
    switch(c){
        case 1:
            std::cout<<"Input the password: ";
            std::cin>>passprint;
            if(passprint == "1234"){
                admin();
            }
            else{
                std::cout<<"The password is incorrect"<<std::endl;
            
            };
        break;
        
        case 2:user()
        ;
    }
}
