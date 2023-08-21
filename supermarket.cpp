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

void shopping :: menu()
{
    
    m:
    int choice;
    string email;
    string password;

    cout<<"\n\n\t\t\t\t########################################\n";
    cout<<"\t\t\t\t\t\t#                                      # \n";
    cout<<"\t\t\t\t\t\t#         BILLING SOFTWARE             #\n";
    cout<<"\t\t\t\t\t\t#                                      #\n";
    cout<<"\t\t\t\t\t\t########################################\n";
    cout<<"\t\t\t\t\t\t           | 1) Administrator|        \n";
    cout<<"\t\t\t\t\t\t           |_________________|        \n";
    cout<<"\t\t\t\t\t\t           | 2) Buyer        |        \n";
    cout<<"\t\t\t\t\t\t           |_________________|        \n";
    cout<<"\t\t\t\t\t\t           | 3) Exit         |        \n";
    cout<<"\t\t\t\t\t\t           |_________________|        \n";
    cout<<"\t\t\t\t\t\t            PLEASE SELECT :-          \n";
    cout<<"\n\t\t\t\t\t\t---------> "; cin>>choice;

    switch(choice)
    {
        case 1: 
            cout<<"\t\t\t\t\t\t______________________ \n";
            cout<<"\t\t\t\t\t\t     Please Login      \n";
            cout<<"\t\t\t\t\t\t______________________ \n";
            cout<<"\n\t\t\t\t\t\t***** Enter Email *****   \n";
            cout<<"\n\t\t\t\t\t\t----> ";cin>>email;
            cout<<"\n\t\t\t\t\t\t***** Password *******     \n";
            cout<<"\n\t\t\t\t\t\t----> ";cin>>password;

            if(email=="tarun@email.com" && password=="tarun123")
            {
                administrator();
            }
            else{
                cout<<"\n\t\t\t\t\t\t!!!!!INVALID EMAIL/PASSWORD!!!!!";
            }
            break;

        case 2:
            {
                buyer();
            }

        case 3: 
            {
                exit(0);
            }

        default:
            {
                cout<<"\n\t\t\t\t\t\t!!!!!PLEASE SELECT FROM THE GIVEN OPTIONS!!!!!";
            }

    }

    goto m;


}

void shopping :: administrator()
{
    
    m:
    int choice;
    cout<<"\n\t\t\t\t\t\t>>>>> ADMINISTATOR MENU <<<<<";
    cout<<"\n\t\t\t\t\t\t |____1) Add the Product_____|";
    cout<<"\n\t\t\t\t\t\t |___________________________|";
    cout<<"\n\t\t\t\t\t\t |____2) Modify the Product__|";
    cout<<"\n\t\t\t\t\t\t |___________________________|";
    cout<<"\n\t\t\t\t\t\t |____3) Delete the Product__|";
    cout<<"\n\t\t\t\t\t\t |___________________________|";
    cout<<"\n\t\t\t\t\t\t |____4) Back to Main Menu___|";

    cout<<"\n\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE :- ";
    cout<<"\n\t\t\t\t\t\t---------> ";cin>>choice;

    switch(choice)
    {
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
            cout<<"!!!!!INVALID CHOICE!!!!";
    }
    goto m;
}


void shopping :: buyer()
{
    
    m:
    int choice;
    cout<<"\n\t\t\t\t\t\t>>>>> BUYER MENU <<<<<";
    cout<<"\n\t\t\t\t\t\t|____1) Buy the Product__|";
    cout<<"\n\t\t\t\t\t\t|________________________|";
    cout<<"\n\t\t\t\t\t\t|____2) Go Back__________|";

    cout<<"\n\t\t\t\t PLEASE ENTER YOUR CHOICE :- ";
    cout<<"\n\t\t\t\t\t\t-------> ";cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;

        default:
            cout<<"\n\t\t\t\t\t\t!!!!!INVALID CHOICE!!!!!";

    }
    goto m;

}

void shopping :: add()
{
    
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t >>>>> Add new Product <<<<<";
    cout<<"\n\n\t\t\t\t Enter Product code  ";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>pcode;
    cout<<"\n\n\t\t\t\t Enter Poduct Name ";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>pname;
    cout<<"\n\n\t\t\t\t Enter Product Price ";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>price;
    cout<<"\n\n\t\t\t\t Enter Product Discount ";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>dis;

    data.open("database.txt",ios::in); //ios out for writing mode 

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t\t\t!!!!! RECORD INSERTED !!!!! ";
}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t\t\t>>>>> MODIFY THE RECORD<<<<< ";
    cout<<"\n\t\t\t\t\t Enter the Prodcut code : ";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>pkey;

    data.open("database.txt",ios::in);                  
    if(!data)
    {
        cout<<"\n\n!!!!! FILE DOESN'T EXIST !!!!! ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t\t\t\t Enter New Product Code :";
                cout<<"\n\t\t\t\t\t\t-----> ";cin>>c;
                cout<<"\n\t\t\t\t\t Enter New Product Name :";
                cout<<"\n\t\t\t\t\t\t-----> ";cin>>n;
                cout<<"\n\t\t\t\t\t Enter New Product Price :";
                cout<<"\n\t\t\t\t\t\t-----> ";cin>>p;
                cout<<"\n\t\t\t\t\t Enter New Product Discount :";
                cout<<"\n\t\t\t\t\t\t-----> ";cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t\t!!!!! RECORD EDITIED !!!!! ";
                token++;

            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\t\t\t\t\t\t!!!!! RECORD NOT FOUND !!!!!";
        }
    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t\t>>>>> DELETE PRODUCT <<<<<";
    cout<<"\n\n\t\t\t\t Enter the Product Code :";
    cout<<"\n\t\t\t\t\t\t-----> ";cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\t\t\t\t\tFile Doesnt Exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\t\t\t\t\t\t!!!!! PRODUCT DELETED SUCCESSFULLY !!!!! ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\t\t\t\t\t\t !!!!! Record not found !!!!! ";
        }
    }
}


void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n_________________________________________________________________________\n";
    cout<<"\t\tproNo\t\tName\t\tPrice\n";
    cout<<"____________________________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    
    fstream data;
    
    int arrc[100];
    int arrq[100];
    string choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total = 0;

    cout<<"\n\n\t\t\t>>>>>  ITEMS MENU  <<<<< ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n !!!!! EMPTY DATABASE !!!!!";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\t\t\t\t\t\t______________________________________\n";
        cout<<"\n\t\t\t\t\t\t|                                     | \n";
        cout<<"\n\t\t\t\t\t\t|      Please place the order         |\n";
        cout<<"\n\t\t\t\t\t\t|                                     |\n";
        cout<<"\n\t\t\t\t\t\t|_____________________________________|\n";  
        do
        {
            m:
            cout<<"\n\n\t\t\t\t Enter the Product code :";
            cout<<"\n\t\t\t\t\t\t-----> ";cin>>arrc[c];
            cout<<"\n\n\t\t\t\t Enter the Product quantity :";
            cout<<"\n\t\t\t\t\t\t-----> ";cin>>arrq[c]; 
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again! ";
                    goto m;
                }
            }

            c=c+1;
            cout<<"\n\n Do you want to buy another product ? If Yes then Press y else No : ";
            cin>>choice;

        }while(choice=="y");

        cout<<"\n\n\t\t\t____________RECEIPT_____________\n";
        cout<<"\nProduct NO\tProduct Name\tProduct Quantity\tprice\tAmount with discount\n";

        for(int i=0;i<=c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total = total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();

    }
    cout<<"\n\n_____________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main()
{
    shopping s;
    s.menu();

}

