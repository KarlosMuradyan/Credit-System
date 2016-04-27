#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;



struct bloknot {
	char anun[10];
	char azganun[15];
	int tariq;
	int heraxos;
	bool ser;
};
int voronel(bloknot[], int);
int admin()
{
	const int n = 100;
	int k, m = 0;
	bloknot cucak[n];
	cout << "mutqagreq 1 avelacnelu hamar" << endl;
	cout << "mutqagreq 2 jnjelu hamar " << endl;
	cout << "mutqagreq 3 voronelu " << endl;
	cout << "mutqagreq 4 tpelu hamar " << endl;
	cout << "mutqagreq 5 avartelu hamar " << endl;
	int t = 0;
	do
	{
		cin >> k;
		switch (k){
		case 1: //mutq
			cin >> cucak[m].anun >> cucak[m].azganun >> cucak[m].tariq >> cucak[m].heraxos >> cucak[m].ser;
			m++;
			break;
		case 2:  cout << "mutq areq ayn anun@ vor@ uzum eq jnjel" << endl;
			 t = voronel(cucak, n);
			if (t >= 0)
			{
				for (int i = t; i < n - 1; i++)
					cucak[i] = cucak[i + 1];
			}

			else cout << "aydpisi anun chka" << endl;
			break;
		case 3:
			cout << "mutq areq ayn anun@ vor@ uzum eq gtnel" << endl;
				 t = voronel(cucak, n);
				if (t >= 0)
					cout << "aydpisi anun ka " << cucak[t].anun << '\t' << cucak[t].azganun << '\t' << cucak[t].tariq << '\t' << cucak[t].heraxos << '\t' << cucak[t].ser;
				else cout << "aydpisi anun chka" << endl;
				break;
			case 4 : 
				for (int i = 0; i < m; i++)
					cout << cucak[i].anun << '\t' << cucak[i].azganun << '\t' << cucak[i].tariq << '\t' << cucak[i].heraxos << '\t' << cucak[i].ser << '\t';
				break;
		}
	} while (k != 5);
	cout << "asxatanqi avart" << endl;

	return 0;
}
int voronel(bloknot cucak[], int n)
{
	char s[50]; int q = 0;
	cin >> s;
	for (int i = 0; i <= n - 1; i++)
	if (s==cucak[i].anun == 0)
		return  i;
	return -1;
}

int user()
    {
        cout<<"Choose the action:"<<endl;
        
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
                cout << "mutqagreq 1 avelacnelu hamar" << endl;
	            cout << "mutqagreq 2 jnjelu hamar " << endl;
	            cout << "mutqagreq 3 voronelu " << endl;
            	cout << "mutqagreq 4 tpelu hamar " << endl;
            	cout << "mutqagreq 5 avartelu hamar " << endl;
             };
            break;
                
        case 2:user();
    }
}
