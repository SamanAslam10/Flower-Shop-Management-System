#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//................... functions prototypes
void welcomepage(); // displays at start
void header(); // includes name of flowershop
int login(); // separates admin loginn from user 
void signup(); // user signup
void saveINTOfile(); // saves user information into file
bool signin(); // read info from file and check whether user's credentials are correct
void adminsignup(); // admin signup
void adminsaveINTOfile(); // saves admin information into file
bool adminlogin();// read info from file and check whether admin's credentials are correct
string getField(string record, int field);
void clearscreen();//clears the console
//.......admin functions start
char adminmenu();// displays admin menu and return option
void viewproducts(); // displays available products
void addnewproducts();// admin adds new products
void editprice();// admin edits price of a product
void viewstock();// admin views stock
void editstock();// admin edits stock
void addstock();// admin adds stock
void addflowersales();// admin adds sales info
void saleshistory();// admin views sales history
void vieworders();// admin views orders
//.................users functions start 
char usermenu();// displays user menu
void availabletypes();// displays products
void boquettypes();// displays boquet types
void placeorder();// takes order from user
void viewcart();// read info from file and lets user see order
void checkout();// confirms info and order
void help();// guidence for user
void aboutus();// info about shop
void feedback();// takes users feedback and rating
//...................prototypes end

//..................main start
main()
{
    system("cls");
    welcomepage();
    cout<<endl;
    int role = login();
    if(role == 1)
    {
        char a = ' ';
        while(true)
        {
            header();
            cout<<endl<<endl;
            a = adminmenu();
            if(a == '1')
            {
                //View Products
                viewproducts();
                cout<<endl;
                boquettypes();
            }
            if(a == '2')
            {
                //Add new product
                addnewproducts();
            }
            if(a == '3')
            {
                //Edit Price
                editprice();
            }
            if(a == '4')
            {
                //check stock
                viewstock();
            }
            if(a == '5')
            {
                //add stock
                addstock();
            }            
            if(a == '6')
            {
                //Edit stock
                editstock();
            }
            if(a == '7')
            {
                //Enter Sales
                addflowersales();
            }
            if(a == '8')
            {
                //sales history
                saleshistory();
            }
            if(a == '9')
            {
                //View Orders
                vieworders();
            }
            if(a == '0')
            {
                //Logout
                break;
                clearscreen();
            }
            clearscreen();
        }
    }// End of admin menu
    if(role == 2)
    {
        char a = ' ';
        while(true)
        {
            header();
            cout<<endl<<endl;
            a = usermenu();
            if(a == '1')
            {   
                //available types
                availabletypes();
            }
            if(a == '2')
            {
                //place order 
                placeorder();
            }
            if(a == '3')
            {
                //view cart
                viewcart();
            }
            if(a == '4')
            {
                //checkout
                checkout();
            }
            if(a == '5')
            {
                //Help
                help();
            }
            if(a == '6')
            {
                //aboutus
                aboutus();
            }
            if(a == '7')
            {
                //feedback;
                feedback();
            }
            if(a == '8')
            {
                //exit
                break;
            }
            clearscreen();
        }
        
    }
    if(role != 1 && role != 2) 
    {
        cout << "Login failed or invalid input. Exiting program." << endl;
    }
}
//...................main end

//...................functions
void welcomepage()
{
    cout<<"Welcome To :"<<endl;
    header();
    cout<<endl;
    cout<<"We offer : "<<endl;
    cout << "******************"<<endl;
    cout << "*     FLOWERS    *"<<endl;
    cout << "******************"<<endl;
}
void header()
{
  cout<<"     A Flower Shop Management System     "<<endl;
  cout<<"  *************************************  "<<endl;
  cout<<"*            LILLY BLOOMS               *"<<endl;
  cout<<"  *************************************  "<<endl; 
  cout<<"   'where every bloom tells a story'     "<<endl;
}
//...........start of login functions
int login()
{   
    string login;
    cout<<"Login as 'admin' or 'user' : ";
    cin>>login;
    if(login == "admin" || login == "Admin")
    {   
        int user;
        cout<<"SignIn(enter 1) or SignUp(enter 2) : ";
        cin>>user;
        if(user == 1)
        {
            if(adminlogin())
            {
                return 1;
            }
        }
        else if(user == 2)
        {
            //signUp
            adminsignup();
            adminsaveINTOfile();
            system("cls");
            cout<<"Now Signin : "<<endl;
            if(adminlogin())
            {
                return 1;
            }
        }
       
    } 
    else if(login == "user" || login == "User")
    {
        int user;
        cout<<"SignIn(enter 1) or SignUp(enter 2) : ";
        cin>>user;
        if(user == 1)
        {
            //signIn
            if(signin())
            {
                return 2;
            }
        }
        else if(user == 2)
        {
            //signUp
            signup();
            saveINTOfile();
            system("cls");
            cout<<"Now Signin : "<<endl;
            if(signin())
            {
                return 2;
            }
        }
    }
}
void signup()
{
    string usernameA[100];
    string passwordA[100];
    string roleA[100];
    int count = 0;
    cout<<"SignUp"<<endl;
    cout<<"Enter username : ";
    cin>>usernameA[count];
    cout<<"Enter password : ";
    cin>>passwordA[count];
    cout<<"Enter role : ";
    cin>>roleA[count];

    count ++ ;
}
void saveINTOfile()
{
    string usernameA[100];
    string passwordA[100];
    string roleA[100];
    int count = 0;
    string line;
    fstream write;
    write.open("loginIDs.txt",ios::app);
    for(int i = 0 ; i < count ; i ++)
    {
        line = usernameA[i] + "," + passwordA[i] + "," + roleA[i];
        write<<line<<endl;
    }
    write.close();
}
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for(int x = 0; x < record.length(); x++)
    {
    if(record[x] == ',')
{
commaCount = commaCount + 1;
}
    else if(commaCount == field)
    {
    item = item + record[x];
    }
}
    return item;
}
bool signin()
{
    string name , password , role;
    cout<<"Enter username : ";
    cin>>name;
    cout<<"Enter password : ";
    cin>>password;
    cout<<"Enter role : ";
    cin>>role;

    string record;
    fstream data;
    data.open("loginIDs.txt", ios::in);
    bool found = false;
    while(getline(data, record))
    {
        string fileusername = getField(record, 1);
        string filepassword = getField(record, 2);
        string filerole = getField(record, 3);
        if(name == fileusername && password == filepassword && role == filerole )
        {
            found = true;
            break;
        }
    }
    data.close();
    if(found)
    {
        return true;
    }
    else
    {
        cout<<"Credentials doesn't match! Try again or SignUP"<<endl;
        return false;
    }
}
bool adminlogin()
{
    string name , password , role;
    cout<<"Enter username : ";
    cin>>name;
    cout<<"Enter password : ";
    cin>>password;
    cout<<"Enter role : ";
    cin>>role;

    string record;
    fstream data;
    data.open("adminlogin.txt", ios::in);
    bool found = false;
    while(getline(data, record))
    {
        string fileusername = getField(record, 1);
        string filepassword = getField(record, 2);
        string filerole = getField(record, 3);
        if(name == fileusername && password == filepassword && role == filerole )
        {
            found = true;
            break;
        }
    }
    data.close();
    if(found)
    {
        return true;
    }
    else
    {
        cout<<"Credentials doesn't match! Try again or SignUP"<<endl;
        return false;
    }
}
void adminsignup()
{   
    string usernameA[100];
    string passwordA[100];
    string roleA[100];
    int count = 0;
    cout<<"SignUp"<<endl;
    cout<<"Enter username : ";
    cin>>usernameA[count];
    cout<<"Enter password : ";
    cin>>passwordA[count];
    cout<<"Enter role : ";
    cin>>roleA[count];

    count ++ ;
}
void adminsaveINTOfile()
{   
    string usernameA[100];
    string passwordA[100];
    string roleA[100];
    int count = 0;
    string line;
    fstream write;
    write.open("adminlogin.txt",ios::app);
    for(int i = 0 ; i < count ; i ++)
    {
        line = usernameA[i] + "," + passwordA[i] + "," + roleA[i];
        write<<line<<endl;
    }
    write.close();
}
//.....end of login functions
//.....Start of Admin Functions
char adminmenu() 
{
    cout<<" <ADMIN MENU> "<<endl<<endl;
    cout<<"1. View products "<<endl;
    cout<<"2. Add new product"<<endl;
    cout<<"3. Edit Price "<<endl;
    cout<<"4. Check Stock"<<endl;
    cout<<"5. Add Stock"<<endl;
    cout<<"6. Edit Stock"<<endl;
    cout<<"7. Enter Sales"<<endl;
    cout<<"8. View Sales History"<<endl;
    cout<<"9. View Orders"<<endl;
    cout<<"0. Logout"<<endl;
    cout<<endl<<endl;

    char option;
    cout<<"Choose Option : ";
    cin>>option;
    return option;
}
void viewproducts()
{
    cout<<"****************"<<endl;
    cout<<"*   PRODUCTS   *"<<endl;
    cout<<"****************"<<endl;
    string flowername[100];
    float flowerprice[100];
    int productcount = 0;
    string record;
    fstream read;
    cout<<"Product"<<"\t"<<"\t"<<"Price"<<endl;
    read.open("product.txt",ios::in);
    while(getline(read,record))
    {
        flowername[productcount] = getField(record, 1);
        flowerprice[productcount] = stof(getField(record, 2));
        productcount++;
    }
    read.close();
    string choice;
    cout<<"Sort products by price (Yes / No) : ";
    cin>>choice;
    if(choice == "yes" || choice == "Yes" || choice == "YES")
    {
        for(int i = 0 ; i < productcount - 1 ; i ++ )
        {
            for(int j = i + 1 ; j < productcount ; j ++)
            {
                if(flowerprice[i] > flowerprice[j])
                {
                    swap(flowerprice[i], flowerprice[j]);
                    swap(flowername[i], flowername[j]);
                }
            }
        }
        for(int i = 0 ; i <= productcount ; i ++)
        {
            cout<<"Product"<<"\t"<<"\t"<<"Price"<<endl;
            cout<<flowername[i]<<"\t"<<"\t"<<flowerprice[i]<<"\n";  
        }
    }
    if(choice == "NO" || choice == "no" || choice == "No")
    {
        for(int i = 0 ; i <= productcount ; i ++)
        {
            cout<<"Product"<<"\t"<<"\t"<<"Price"<<endl;
            cout<<flowername[i]<<"\t"<<"\t"<<flowerprice[i]<<"\n";  
        }
    }
}
void addnewproducts()
{   
    string name;
    float price;
    cout<<"Enter the name of new product : ";
    cin>>name;
    cout<<"Enter the price of new product : ";
    cin>>price;

    string line;
    fstream write;
    write.open("product.txt",ios::out | ios::app);
    line = name + "," + to_string(price);
    write<<line<<"\n";
    write.close();
}
void editprice()
{
    string name;
    cout<<"Enter the name of flower you want to change the price of : ";
    cin>>name;

    float newprice;
    cout<<"Enter new price : ";
    cin>>newprice;

    string flowername[100];
    float flowerprice[100];
    int productcount = 0;

    string record;
    fstream read;
    read.open("product.txt",ios::in );
    while(getline(read,record))
    {
        string filename = getField(record, 1);                                                                                                                                                                                                                                                                                                                                               
        float fileprice = stof(getField(record, 2));
        flowername[productcount] = filename;
        if(name == filename)
        {
            flowerprice[productcount] = newprice;
        }
        else
        {
            flowerprice[productcount] = fileprice;
        }
        productcount ++ ;
    }
    read.close();

    string line;
    fstream write;
    write.open("product.txt",ios::out);
    for(int i = 0 ; i < productcount ; i ++)
    {
        line = flowername[i] + "," + to_string(flowerprice[i]);
        write << line <<"\n"; 
    }
    write.close();
}
void viewstock()
{   
    string flowernames[100];
    int flowerstock[100];
    int stockcount = 0;
    string record;
    fstream read;
    cout<<"Product"<<"\t"<<"\t"<<"Stock"<<endl;
    read.open("stock.txt",ios::in);
    while(getline(read,record))
    {
        flowernames[stockcount] = getField(record, 1);
        flowerstock[stockcount] = stoi(getField(record, 2));
        cout<<flowernames[stockcount]<<"\t"<<"\t"<<flowerstock[stockcount]<<"\n";
        stockcount ++;
    }
    read.close();
}
void addstock()
{
    string name;
    int stock;
    cout<<"Enter the name product : ";
    cin>>name;
    cout<<"Enter the stock : ";
    cin>>stock;

    string line;
    fstream write;
    write.open("stock.txt",ios::out | ios::app);
    line = name + "," + to_string(stock);
    write<<line<<"\n";
    write.close();
}
void editstock()
{
    string name;
    cout<<"Enter the name of flower : ";
    cin>>name;

    int stock;
    cout<<"Enter stock quantity : ";
    cin>>stock;

    string flowername[100];
    int flowerstock[100] ;
    int stockcount = 0;

    string record;
    fstream read;
    read.open("stock.txt",ios::in );
    while(getline(read,record))
    {
        string filename = getField(record, 1);
        int filestock = stoi(getField(record, 2));
        flowername[stockcount] = filename;
        if(name == filename)
        {
            flowerstock[stockcount] = stock;
        }
        else
        {
            flowerstock[stockcount] = filestock;
        }
        stockcount ++ ;
    }
    read.close();

    string line;
    fstream write;
    write.open("stock.txt",ios::out);
    for(int i = 0 ; i < stockcount ; i ++)
    {
        line = flowername[i] + "," + to_string(flowerstock[i]);
        write << line <<"\n";
    }
    write.close();
}
void addflowersales()
{
    int n , o=0;
    cout<<"How many sales you want to add : ";
    cin>>n;
    string flowernames[100];
    int flowersales[100];

    for(int i = 0 ; i < n ; i ++ )
    {
        cout<<"Enter the name of flower : ";
        cin>>flowernames[i];
        cout<<"Enter the sales : ";
        cin>>flowersales[i];
    }

    string line;
    fstream write;
    write.open("sales.txt",ios::out);
    while(o < n)
    {
        line = flowernames[o] + "," + to_string(flowersales[o]);
        write<<line<<"\n";
        o ++;
    }
    write.close();
}
void saleshistory()
{
    string flowername[100];
    int flowersales[100];
    int salescount = 0;
    string record;
    fstream read;
    read.open("sales.txt",ios::in);
    cout<<"Product"<<"\t"<<"\t"<<"Sales"<<endl;
    while(getline(read,record))
    {
        flowername[salescount] = getField(record,1);
        flowersales[salescount] = stoi(getField(record,2));
        cout<<flowername[salescount]<<"\t"<<"\t"<<flowersales[salescount]<<endl;
        salescount ++;
    }
    read.close();
}
void vieworders()
{
    string username;
    float usercontact;
    string useraddress;
    string ordername;
    int orderquantity;
    int o = 1;
    string record;
    fstream read;
    read.open("orders.txt",ios::in);
    while(getline(read,record))
    {
        username = getField(record , 1);
        usercontact = stof(getField(record , 2));
        useraddress = getField(record , 3);
        ordername = getField(record , 4);
        orderquantity = stoi(getField(record , 5));

        cout<<"Order # "<<o<<endl;
        cout<<"Product name :"<< ordername<<endl;    
        cout<<"Quantity : "<<orderquantity<<endl;
        cout<<endl<<endl;
        cout<<"User INFORMATION : "<<endl;
        cout<<"Name: "<<username<<endl;
        cout<<"Contact no: "<<usercontact<<endl;
        cout<<"Address: "<<useraddress<<endl;
        o ++;
    }
    read.close();
}
// End of Admin functions
void clearscreen()
{
    cout<<"Press any key to continue : "<<endl;
    getch();
    system("CLS");
}
//start of User functions
char usermenu()
{
    cout<<"***************"<<endl;
    cout<<"*   WELCOME   *"<<endl;
    cout<<"***************"<<endl;
    cout<<"1. Available types"<<endl;
    cout<<"2. Place Order"<<endl;
    cout<<"3. View Cart"<<endl;
    cout<<"4. Checkout"<<endl;
    cout<<"5. Help"<<endl;
    cout<<"6. About us"<<endl;
    cout<<"7. Feedback/Rating"<<endl;
    cout<<"8. Exit"<<endl;

    char option;
    cout<<"Enter your option : ";
    cin>>option;

    return option;
}
void availabletypes()
{
    cout<<"****************"<<endl;
    cout<<"*   PRODUCTS   *"<<endl;
    cout<<"****************"<<endl;
    int option;
    cout<<"What would you like to explore : "<<endl;
    cout<<"1. Avaialable Flower types "<<endl;
    cout<<"2. Boquet Options "<<endl;
    cout<<"your option : ";
    cin>>option;
    system("cls");
    if(option == 1)
    {
        // types
        viewproducts();
        clearscreen();
    }
    if(option == 2)
    {
        // Boquet
        boquettypes();
    }
}
void boquettypes()
{
    const int boquets = 3;
    string boquetsnames[boquets] = {"Small bouquet" , "Medium bouquet" ,"Large bouquet"};
    float boquetprices[boquets] = {4000 , 5000 , 7000 } ;
    cout<<"****************"<<endl;
    cout<<"*   BOUQUETS   *"<<endl;
    cout<<"****************"<<endl;
    cout<<"TYPE"<<"\t"<<"\t"<<"Price"<<endl;
    for(int i = 0 ; i < boquets ; i ++)
    {
        cout<<boquetsnames[i]<<"\t"<<boquetprices[i]<<endl;
    }
}
void placeorder()
{   
    string username;
    float usercontact;
    string useraddress;
    string ordername;
    int orderquantity; 

    cout<<"*************"<<endl;
    cout<<"*   ORDER   *"<<endl;
    cout<<"*************"<<endl<<endl;
    
    cout<<"Product name : ";
    cin>>ordername;    
    cout<<"Quantity : ";
    cin>>orderquantity;
    cout<<endl<<endl;
    cout<<"YOUR INFORMATION : "<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Contact no: ";
    cin>>usercontact;
    cout<<"Address: ";
    cin>>useraddress;

    string line;
    fstream write;
    write.open("orders.txt",ios::out);
    line = username + "," + to_string(usercontact) + "," + useraddress + "," + ordername + "," + to_string(orderquantity);
    write<<line<<"\n";
    write.close();
}
void viewcart()
{
    cout<<"************"<<endl;
    cout<<"*   CART   *"<<endl;
    cout<<"************"<<endl;

    string ordername;
    int orderquantity;
    int o = 1;
    string record;
    fstream read;
    read.open("orders.txt",ios::in);
    while(getline(read,record))
    {
        ordername = getField(record , 4);
        orderquantity = stoi(getField(record , 5));

        cout<<"Order # "<<o<<endl;
        cout<<"Product name :"<< ordername<<endl;    
        cout<<"Quantity : "<<orderquantity<<endl;
        o ++;
    }
    read.close();
}
void checkout()
{
    cout<<"****************"<<endl;
    cout<<"*   CHECKOUT   *"<<endl;
    cout<<"****************"<<endl;
    string username;
    float usercontact;
    string useraddress;
    string ordername;
    int orderquantity;
    float price;
    int o = 1;
    string record;
    fstream read;
    read.open("orders.txt",ios::in);
    while(getline(read,record))
    {
        username = getField(record , 1);
        usercontact = stof(getField(record , 2));
        useraddress = getField(record , 3);
        ordername = getField(record , 4);
        orderquantity = stoi(getField(record , 5));
    }
    read.close();

    cout<<"YOUR INFORMATION : "<<endl;
    cout<<"Name: "<<username<<endl;
    cout<<"Contact no: "<<usercontact<<endl;
    cout<<"Address: "<<useraddress<<endl<<endl;
    cout<<"Order Summary : "<<endl;

     string flowername[100];
    float flowerprices[100];
    int count = 0;
    read.open("product.txt",ios::in );
    while( getline(read,record))
    {
        flowername[count] = getField(record, 1);
        flowerprices[count] = stof(getField(record, 2));
        count ++ ;
    }
    read.close();

    for(int i = 0 ; i < count ; i ++)
    {
        if(flowername[i]== ordername)
        {
            price = flowerprices[i];
        }
    }
    cout<<ordername<<"\t"<<"\t"<<orderquantity<<endl;
    int total = total + (orderquantity * price);

    cout<<"Grand Total : "<<total<<" Rs."<<endl;
    int confirm;
    cout<<"Press 1 to Confirm order : ";
    cin>>confirm;
    if(confirm == 1)
    {
        cout<<"Order Confirmed!"<<endl;
    }
    else
    {
        cout<<"Some Problem with order confirmation. Try Again!"<<endl;
    }
}
void help() 
{
    string line;
    fstream read;
    read.open("help.txt",ios::in);
    while(getline(read , line))
    {
        cout<<line<<"\n";
    }
    read.close();
}
void aboutus()
{
    string line;
    fstream read;
    read.open("aboutus.txt",ios::in);
    while(getline(read , line))
    {
        cout<<line<<"\n";
    }
    read.close();
}
void feedback()
{
    int rate;
    string feedback;
    cout<<"****************"<<endl;
    cout<<"*   FEEDBACK   *"<<endl;
    cout<<"****************"<<endl;
    cout<<"We value your feedback!"<<endl;
    cout<<"Please rate your experience (1 to 10): ";
    cin>>rate;
    cout<<"Please enter any additional comments or suggestions(use hypens_ for space): ";
    cin>>feedback;
    cout<<"Thank you for your feedback!"<<endl;
}//End of User Functions
//...................functions end         