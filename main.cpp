#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
#include <cassert>
#include <string.h>

struct Client{
    std::string name;
    std::string surname;
    int  loan;
    int duration_month;
    int monthly_payment;
    int monthly_percentage;
    std::string password;
};
int search(Client[],int,  int, char*);
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
                list[i].monthly_payment = stoi(person_info_array[5]);
                list[i].monthly_percentage = stoi(person_info_array[6]);
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
            case 2:  
                {std::cout << "Enter name of a person you search ";
                char temp[15];
                std::cin >> temp;
                int ind = 0;
                ind = search(list, ind, n, temp);
                while(ind !=-1){
                     std::cout << "Name Surname:"<<list[ind].name <<' '<< list[ind].surname <<std::endl <<"Your password is: "<<list[ind].password<<std::endl<< "Loan Amount:" <<list[ind].loan <<std::endl<<"Duration in month:" << list[ind].duration_month <<std::endl<<"Your monthly payment is: "<<list[ind].monthly_payment<<" AMD"<<std::endl<<"Your monthly percentage is: "<<list[ind].monthly_percentage<<"%"<<std::endl;
                    //  if(ind < n-1){
                         ind = search(list, ind+1, n, temp);
                    //  }
                    //  std::cout<<ind;
                }
                break;
                }
            case 3:erase( list, n); break;
            case 4: print(list, n); break;
            case 5: break;
            default: std::cout << "Enter right command"; break;
        }
    }
    return 0;
}
int search(Client x[],int s, int n, char* name){
        bool res = false;
    	for (int i = s; i < n; i++){
            if (x[i].name == name)
            {
                
                res = true;
                return i;
            }
            
    	}
    	if(res == false){
                return -1;
        }
 
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
    std::cout << "amount_of_loan_AMD: ";
    std::cin >> x[n].loan;
    std::cout << "loan_duration_month: ";
    std::cin >> x[n].duration_month;
    x[n].monthly_payment=x[n].loan/x[n].duration_month;
    std::cout<<"Your monthly payment is: ";
    std::cout <<x[n].monthly_payment<<"AMD "<<std::endl;
    x[n].monthly_percentage=5+x[n].duration_month/12;
    std::cout<<"Your monthly percentage is: ";
    std::cout<< x[n].monthly_percentage<<"%"<<std::endl;

    
    
    std::ofstream info("new.txt", std::ios_base::app);   //opening file for adding new info
    info<<x[n].name<<"|";
    info<<x[n].surname<<"|";
    info<<x[n].password<<"|";
    info<<x[n].loan<<"|";
    info<<x[n].duration_month<<"|";
    info<<x[n].monthly_payment<<"|";
    info<<x[n].monthly_percentage<<std::endl;
    info.close();
    
    n++;
}
void print(Client x[], int n){
	for (int i = 0; i < n; i++){
		std::cout << x[i].name << '\t' << x[i].surname << '\t'<<x[i].password<< '\t'<< x[i].loan <<" AMD"<< '\t' << x[i].duration_month<<"months"<<'\t' << x[i].monthly_payment<<" AMD"<<'\t'<< x[i].monthly_percentage<<" %"<<'\n';
	}
}
void erase(Client x[], int &n){
    char temp[15];
	std::cin >> temp;
    int p = search(x,0, n, temp);
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
	        x[i].monthly_payment=x[i+1].monthly_payment;
            x[i].monthly_percentage=x[i+1].monthly_percentage;
	    }
	   n--;
    }
    
    std::ofstream info("new.txt");   //opening file for adding new info
    for(int i=0; i<n; i++){
        
        info<<x[i].name<<"|";
        info<<x[i].surname<<"|";
        info<<x[i].password<<"|";
        info<<x[i].loan<<"|";
        info<<x[i].duration_month<<"|";
        info<<x[i].monthly_payment<<"|";
        info<<x[i].monthly_percentage<<std::endl;

       
    }
     info.close();
}

void user(){
    Client x[100];
    int n;
    n = read(x);
    std::string u_name, u_surn, u_pass;
    std::cout<<"Please insert your name: ";
    std::cin>>u_name;
    for(int i=0; i<n; i++){
        if(u_name == x[i].name){
            std::cout<<"Please insert your surname: ";
            std::cin>>u_surn;
                if(u_surn == x[i].surname){
                    std::cout<<"Please insert your password: ";
                    std::cin>>u_pass;
                    if(u_pass == x[i].password){
                        int choice;
                        while(choice !=3){
                            std::cout<<"1.See the information  2.Create a Request  3.Log out"<<std::endl;
                            std::cin>>choice;
                            switch(choice){
                                case 1:
                                    	std::cout << x[i].name << '\t' << x[i].surname << '\t'<<x[i].password<< '\t'<< x[i].loan <<" AMD"<< '\t' << x[i].duration_month<<"months"<<'\t' << x[i].monthly_payment<<" AMD"<<'\t'<< x[i].monthly_percentage<<" %"<<'\n';
                                        break;
                                case 2:
                                    int tp;
                                    std::cout<<"What you want to do: 1.Expand the loan   2.Extend the duration"<<std::endl;
                                    std::cin>>tp;
                                    if(tp == 1 || tp==2 ){
                                        
                                        std::string message;
                                        std::cout<<"Please insert your request:"<<std::endl;
                                        std::cin>>message;
                                        std::cout<<"Your Request has been sent. Please wait for responce. "<<std::endl;
                                    }
                                    else{
                                        std::cout<<"You need to either print 1 or 2."<<std::endl;
                                    }
                                    break;
                                case 3: break;    
                                default:
                                    break;
                            }
                        }
                    }
                    else{
                        std::cout<<"The password is not correct. "<<std::endl;
                    }
                }
                else{
                    std::cout<<"There is no such person with your written name and surname in our data base. "<<std::endl;
                }
        }
        else if(i==n-1){
            std::cout<<"There is no person with your name."<<std::endl;
        }
    }
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
        
        case 2:
        	user();
        	break;
        
        default:
        	break;
    }
}
