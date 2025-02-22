#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password; //for login purpose

    cout<<"\t\t\t\t_________________________________________\n";
    cout<<"\t\t\t\t                                         \n";
    cout<<"\t\t\t\t        SUPERMARKET MAIN MENU            \n";
    cout<<"\t\t\t\t_________________________________________\n";
    cout<<"\t\t\t\t                                         \n";
    cout<<"\t\t\t\t|   1)Administrator   |"<<endl;
    cout<<"\t\t\t\t|                     |"<<endl;
    cout<<"\t\t\t\t|   2)Buyer           |"<<endl;
    cout<<"\t\t\t\t|                     |"<<endl;
    cout<<"\t\t\t\t|   3)Exit            |"<<endl;
    cout<<"\t\t\t\t|                     |"<<endl;
    cout<<"\n\t\t\t please select!!!";
    cin>>choice;

    switch(choice){
    case 1:
        {
            cout<<"\t\t\t please login "<<endl;
            cout<<"\t\t\t Enter Email  "<<endl;
            cin>>email;
            cout<<"\t\t\t password     "<<endl;
            cin>>password;

            if(email=="sekhar@email.com" && password=="sekhar@2004"){
                administrator();
            }
            else{
                cout<<"Invalid Email/Password";
            }
            break;
        }


    case 2:
        {
            buyer();
        }

    case 3:
        {
            exit(0);
        }

    dedault:
        {
            cout<<"please from the given Options";
        }
    }

    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modift the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    cout<<"\n\t\t\t|                            |";

    cout<<"\n\n\t please enter your choice ";
    cin>>choice;

    switch(choice){
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout<<"Invalid choice!!";
    }
    goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"/t/t/t Buyer \n";
    cout<<"\t\t\t_____________ \n";
    cout<<"                    \n";
    cout<<"\t\t\t1) Buy product\n";
    cout<<"                    \n";
    cout<<"\t\t\t2) Go back    \n";
    cout<<"                    \n";

    cin>>choice;
    switch(choice){
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout<<"Invalid choice!!";
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on product ";
    cin>>dis;


    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1){
            goto m;
        }
        else{
            data.open("database.txt",ios::app | ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }

    cout<<"\n\n\t\t Record inserted !";
}


void shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Modify the record";
    cout<<"\n\n\t Product code ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile doesn't exist!";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t product new code:";
                cin>>c;
                cout<<"\n\n\t Name of the product : ";
                cin>>n;
                cout<<"\n\n\t\t price:";
                cin>>p;
                cout<<"\n\n\t\t Discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        remove("database1.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
    }
}


void shopping :: rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Deleted product";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        remove("database1.txt");

        if(token==0){
            cout<<"\n\n Record not found";
        }
    }
}

void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________________\n";
    cout<<"proNo\t\tName\t\tPrice"<<endl;
    cout<<"\n\n|_______________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
    cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;
    }
    data.close();
}


void shopping ::receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n________________________________________\n";
        cout<<"\n|                                       \n";
        cout<<"\n         Please place the order         \n";
        cout<<"\n|                                       \n";
        cout<<"\n________________________________________\n";

        do{
             m:
            cout<<"\n\nEnter the Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the Product Quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t___________________RECEIPT_____________________\n";
        cout<<"\nProductNo\tProduct Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_________________________________________________";
    cout<<"\n Total Amount : " <<total;
}


int main(){
    shopping s;
    s.menu();
}
