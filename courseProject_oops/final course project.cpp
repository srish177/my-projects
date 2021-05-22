//ONLINE SHOPPING MANAGEMENT SYSTEM
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>

using namespace std;

//global variable
int static Count=0;

//class department
class department
{
  public:
    int id;
    string name;
    string categoriess;

    //default constructors
    department(){}

    //function to get department details
    void getdepartment(department *d)
    {
     ifstream fin;
     fin.open("department.txt");
     for(int i=0;i<2;i++)
     {
         fin>>d[i].id;
         fin>>d[i].name;
         fin>>d[i].categoriess;
    }
       fin.close();
    }

    //function to display department details
    void display2()
    {
     cout<<"Department id: "<<id<<endl;
     cout<<"Department name: "<<name<<endl;
     cout<<"Categories: "<<categoriess<<endl;
    }
};

//class categories
class categories
{
   public:
       string productName;
       int id;
       float price;
       string department;
       int quantity;
       //default constructors
       categories(){}
       virtual void display()=0;

};

//class clothing which is publicly inherited from the class categories
class clothing:public categories
{
public:
    string dom;
    string  type;
    string company;
    //default constructors
    clothing(){}

};

//class men which is publicly inherited from class clothing
class men: public clothing
{
    public:
    string sizee;
    //default constructors
    men(){}

    //function to display details of men category
     void display()
    {
     cout<<"product id: "<<id<<endl;
     cout<<"Product name: "<<productName<<endl;
     cout<<"Department: "<<department<<endl;
     cout<<"Price: "<<price<<endl;
     cout<<"Type: "<<type<<endl;
     cout<<"Size: "<<sizee<<endl;
     cout<<"Company: "<<company<<endl;
     cout<<"Date of manufacture: "<<dom<<endl;
     cout<<endl;
    }

    //function to get details of men category
   void getproduct(men *m)
   {
     ifstream fin;
     fin.open("men.txt");
     for(int i=0;i<10;i++)
     {
         fin>>m[i].id;
         fin>>m[i].productName;
         fin>>m[i].department;
         fin>>m[i].price;
         fin>>m[i].type;
         fin>>m[i].sizee;
         fin>>m[i].company;
         fin>>m[i].dom;
     }
     fin.close();
   }

 //function to add products from men category to the cart
    int add_to_cart(men *m)
   {
     int n,q;
     men c;
     int i;
     cout<<"Enter the Product id: "<<endl;
     cin>>n;
     cout<<"Enter the quantity: "<<endl;
     cin>>q;
    for(int i=0;i<10;i++)
    {
        if(n==m[i].id)
           {c=m[i];
            c.quantity=q;
            Count++;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);
    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
   return i;
  }

};

//class women which is publicly inherited from class clothing
class women: public clothing
{
    public:
    string sizee;
    int i;

    //default constructor
    women(){}

    //function to display details of women category
     void display()
    {
     cout<<"product id: "<<id<<endl;
     cout<<"Product name: "<<productName<<endl;
     cout<<"Department: "<<department<<endl;
     cout<<"Price: "<<price<<endl;
     cout<<"Type: "<<type<<endl;
     cout<<"Size: "<<sizee<<endl;
     cout<<"Company: "<<company<<endl;
     cout<<"Date of manufacture: "<<dom<<endl;
     cout<<endl;
    }

    //function to get details of women category
    void getproduct(women *w)
   {
     ifstream fin;
     fin.open("women.txt");
     for(int i=0;i<10;i++)
     {
         fin>>w[i].id;
         fin>>w[i].productName;
         fin>>w[i].department;
         fin>>w[i].price;
         fin>>w[i].type;
         fin>>w[i].sizee;
         fin>>w[i].company;
         fin>>w[i].dom;
     }
     fin.close();
 }

 //function to add products from women category to the cart
int add_to_cart(women *w)
{
    int n,q;
    women c;
    cout<<"Enter the Product id: "<<endl;
    cin>>n;
    cout<<"Enter the quantity: "<<endl;
    cin>>q;
    for(int i=0;i<10;i++)
    {
        if(n==w[i].id)
           {
               c=w[i];
               c.quantity=q;
               Count++;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    return i;
}
};

//class kid which is publicly inherited from class clothing
class kid: public clothing
{
    public:
    string sizee;
    int i;

    //default constructor
    kid(){}

    //function to display details of kid category
     void display()
    {
     cout<<"product id: "<<id<<endl;
     cout<<"Product name: "<<productName<<endl;
     cout<<"Department: "<<department<<endl;
     cout<<"Price: "<<price<<endl;
     cout<<"Type: "<<type<<endl;
     cout<<"Size: "<<sizee<<endl;
     cout<<"Company: "<<company<<endl;
     cout<<"Date of manufacture: "<<dom<<endl;
     cout<<endl;
    }

    //function to get details of kid category
 void getproduct(kid *k)
 {
     ifstream fin;
     fin.open("kid.txt");
     for(int i=0;i<10;i++)
     {
         fin>>k[i].id;
         fin>>k[i].productName;
         fin>>k[i].department;
         fin>>k[i].price;
         fin>>k[i].type;
         fin>>k[i].sizee;
         fin>>k[i].company;
         fin>>k[i].dom;
     }
     fin.close();
 }

//function to add products from kids category to the cart
int add_to_cart(kid *k)
{
    int n,q;
    kid c;
    cout<<"Enter the Product id: "<<endl;
    cin>>n;
    cout<<"Enter the quantity: "<<endl;
    cin>>q;
    for(int i=0;i<10;i++)
    {
        if(n==k[i].id)
           {
               c=k[i];
               c.quantity=q;
               Count++;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    return i;
}
};

//class electronics which is publicly inherited from class categories
class electronics:public categories
{
public:
    string dom;
    string  type;
    string company;
    //default constructor
    electronics(){}
    void display()=0;
};

//class home appliances which is publicly inherited from class electronics
class homeappliances: public electronics
{
public:
    int gvalidity;
    int i;
    //default constructor
    homeappliances(){}

    //function to display details of home appliance category
     void display()
    {
     cout<<"product id: "<<id<<endl;
     cout<<"Product name: "<<productName<<endl;
     cout<<"Department: "<<department<<endl;
     cout<<"Price: "<<price<<endl;
     cout<<"Type: "<<type<<endl;
     cout<<"Warrenty "<<gvalidity<<endl;
     cout<<"Company: "<<company<<endl;
     cout<<"Date of manufacture: "<<dom<<endl;
     cout<<endl;
    }

    //function to get details of home appliances category
 void getproduct(homeappliances *h)
 {
     ifstream fin;
     fin.open("homeappliances.txt");
     for(int i=0;i<10;i++)
     {
         fin>>h[i].id;
         fin>>h[i].productName;
         fin>>h[i].department;
         fin>>h[i].price;
         fin>>h[i].type;
         fin>>h[i].gvalidity;
         fin>>h[i].company;
         fin>>h[i].dom;
     }
     fin.close();
 }

 //function to add products from home appliances category to the cart
int add_to_cart(homeappliances *h)
{
    int n,q;
    homeappliances c;
    cout<<"Enter the Product id: "<<endl;
    cin>>n;
    cout<<"Enter the quantity: "<<endl;
    cin>>q;
    for(int i=0;i<10;i++)
    {
        if(n==h[i].id)
           {
               c=h[i];
               c.quantity=q;
               Count++;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    return i;
}
};

//class gadgets which is publicly inherited from class electronics
class gadgets: public electronics
{
public:
    int gvalidity;
    int i;
    //default constructor
    gadgets(){}

    //function to display details of gadgets category
     void display()
    {
     cout<<"product id: "<<id<<endl;
     cout<<"Product name: "<<productName<<endl;
     cout<<"Department: "<<department<<endl;
     cout<<"Price: "<<price<<endl;
     cout<<"Type: "<<type<<endl;
     cout<<"Warrenty "<<gvalidity<<endl;
     cout<<"Company: "<<company<<endl;
     cout<<"Date of manufacture: "<<dom<<endl;
     cout<<endl;
    }

    //function to get details of gadgets category
 void getproduct(gadgets *g)
 {
     ifstream fin;
     fin.open("gadgets.txt");
     for(int i=0;i<10;i++)
     {
         fin>>g[i].id;
         fin>>g[i].productName;
         fin>>g[i].department;
         fin>>g[i].price;
         fin>>g[i].type;
         fin>>g[i].gvalidity;
         fin>>g[i].company;
         fin>>g[i].dom;
     }
     fin.close();
 }

 //function to add products from gadgets category to the cart
int add_to_cart(gadgets *g)
{
    int n,q;
    gadgets c;
    cout<<"Enter the Product id: "<<endl;
    cin>>n;
    cout<<"Enter the quantity: "<<endl;
    cin>>q;
    for(int i=0;i<10;i++)
    {
        if(n==g[i].id)
           {
               c=g[i];
               c.quantity=q;
               Count++;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    return i;
}
};

//class product
class product
{
public:
    //default constructor
    product(){}
    int n;
    //function to print details of a specific category
    void print(men *m, women *w, kid *k,homeappliances *h, gadgets *g )
    {
    mainmenu:
        cout<<"press any key to continue shopping\n";
        getch();
        system("cls");
    cout<<"Enter your choice among the categories"<<endl;
    cout<<"\t\t1.Men\n\t\t2.Women\n\t\t3.Kid\n\t\t4.Home Appliances\n\t\t5.Gadgets\n\t\t6.All\n\t\t7.To Go Back To Main Menu\n\n";
    cin>>n;
    switch(n)
    {
        case 1:cout<<"MEN COLLECTION\n"<<endl;
            for(int i=0;i<10;i++)
            {
            m[i].display();
            }
            cout<<"Press any key to continue shopping"<<endl;
            goto mainmenu;
        break;

        case 2: cout<<"WOMEN COLLECTION\n"<<endl;
        for(int i=0;i<10;i++)
            {
                w[i].display();
            }
            cout<<"Press any key to continue shopping"<<endl;
            goto mainmenu;
        break;

        case 3: cout<<"KID COLLECTION\n"<<endl;
         for(int i=0;i<10;i++)
            {
                k[i].display();
            }
            cout<<"Press any key to continue shopping"<<endl;
            goto mainmenu;
        break;

        case 4: cout<<"HOME APPLIANCES COLLECTION\n"<<endl;
        for(int i=0;i<10;i++)
            {
                h[i].display();
            }
            cout<<"Press any key to continue shopping"<<endl;
            goto mainmenu;
        break;

        case 5: cout<<"GADGETS COLLECTION\n"<<endl;
        for(int i=0;i<10;i++)
        {
            g[i].display();
        }
        cout<<"Press any key to continue shopping"<<endl;
        goto mainmenu;
        break;

        case 6: cout<<"PRODUCTS AVAILABLE HERE ARE:\n\n";
        cout<<"MEN COLLECTION\n"<<endl;
         for(int i=0;i<10;i++)
            {
            m[i].display();
            }
            cout<<"WOMEN COLLECTION\n"<<endl;
             for(int i=0;i<10;i++)
            {
                w[i].display();
            }
            cout<<"KID COLLECTION\n"<<endl;
             for(int i=0;i<10;i++)
            {
                k[i].display();
            }
            cout<<"HOME APPLIANCES COLLECTION\n"<<endl;
            for(int i=0;i<10;i++)
            {
                h[i].display();
            }
            cout<<"GADGETS COLLECTION\n"<<endl;
            for(int i=0;i<10;i++)
            {
            g[i].display();
            }
            cout<<"Press any key to continue shopping"<<endl;
            goto mainmenu;
            break;

        default:
            break;
    }
    }
};

//class order details
class order_details
{
public:
    int j;
    int n,q;
    int pricee=0;
    int ooo;
    int price1=0;
    int price2=0;
    int price3=0;
    int price4=0;
    int cho;

    //default constructor
     order_details(){}

     //function to calculate price
     void cal_price(men *m,women *wo,kid *ki,homeappliances *h, gadgets *g)
     {

           mainn:

                cout<<"\n\nWhich item do you want to order\n\t\t1.Men\n\t\t2.Women\n\t\t3Kid\n\t\t4.Home Appliances\n\t\t5.Gadgets\n\t\t6.None\n\n\n";
                cin>>cho;
                if(cho==1)
                  {
                    int n,q;
                    men c;
                    int i;
                    cout<<"Enter the Product id: "<<endl;
                    cin>>n;
                    cout<<"Enter the quantity: "<<endl;
                    cin>>q;
                   for(int i=0;i<10;i++)
                    {
                       if(n==m[i].id)
                        {
                          c=m[i];
                          c.quantity=q;
                          Count++;
                         pricee=pricee+c.price;
                        }
                    }
                 cout<<c.quantity<<" "<<c.productName<<endl;
                 cout<<"count :"<<Count<<endl;
                 cout<<"total price: "<<pricee;
                 fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

               {
                   f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
               }
               goto mainn;
            }


         else if(cho==2)
         {
             int n,q;
             women c;
             cout<<"Enter the Product id: "<<endl;
             //cout<<"  ";
             cin>>n;
             cout<<"Enter the quantity: "<<endl;
             // cout<<"  ";
             cin>>q;
           for(int i=0;i<10;i++)
           {
            if(n==wo[i].id)
           {
            c=wo[i];
            c.quantity=q;
            Count++;
            price1=price1+c.price;
           }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    cout<<"total price: "<<price1;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
      goto mainn;
       }


         else if(cho==3)
         {
               int n,q;
               kid c;
               cout<<"Enter the Product id: "<<endl;
               cin>>n;
               cout<<"Enter the quantity: "<<endl;
               cin>>q;
               for(int i=0;i<10;i++)
                {
                    if(n==ki[i].id)
                       {
                           c=ki[i];
                           c.quantity=q;
                        Count++;
                        price2=price2+c.price;
                       }
    }
    cout<<c.quantity<<" "<<c.productName<<endl;
    cout<<Count<<endl;
    cout<<"total price: "<<price2;
    fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    goto mainn;
}


         else if(cho==4)
         {
              int n,q;
              homeappliances c;
                cout<<"Enter the Product id: "<<endl;
                cin>>n;
                cout<<"Enter the quantity: "<<endl;
                cin>>q;
                for(int i=0;i<10;i++)
                {
                    if(n==h[i].id)
                       {c=h[i];
                        c.quantity=q;
                        Count++;
                        price3=price3+c.price;
                       }
                }
                cout<<c.quantity<<" "<<c.productName<<endl;
                cout<<Count<<endl;
                cout<<"total price: "<<price3;
                fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    goto mainn;
         }


          else if(cho==5)
         {
              int n,q;
                gadgets c;
                cout<<"Enter the Product id: "<<endl;
                cin>>n;
                cout<<"Enter the quantity: "<<endl;
                cin>>q;
                for(int i=0;i<10;i++)
                {
                    if(n==g[i].id)
                       {c=g[i];
                        c.quantity=q;
                        Count++;
                        price4=price4+c.price;
                       }
                }
                cout<<c.quantity<<" "<<c.productName<<endl;
                cout<<Count<<endl;
                cout<<"total price: "<<price4;
                fstream f("shoppingcart.txt",ios::in|ios::out|ios::app);

    {
    f<<c.id<<" "<<c.productName<<" "<<c.department<<" "<<c.price<<" "<<c.type<<" "<<c.quantity<<endl;
    }
    goto mainn;

    }

     else
        {
            cout<<"There is no item ordered further\n\n";
        }
    }
};

//class shipping info
class shipping_info
{
public:
    string shipping_add;
    string shipping_type;
    int shipping_cost;
    string shipping_region;
    //default constructor
    shipping_info(){}

    //function to get shipping details
    void getdata()
    {
        cout<<"enter shipping address: ";
        cin>>shipping_add;
        cout<<"enter shipping type: ";
        cin>>shipping_type;
         cout<<"enter shipping region: ";
        cin>>shipping_region;
    }

    //function to print shipping details
    void putdata()
    {
        cout<<"\n\nshipping address:"<<shipping_add;
        cout<<"\nshipping type:"<<shipping_type;
        cout<<"\nregion:"<<shipping_region;
    }
};

//class orders
class orders
{
public:
    int hi;
    shipping_info s;
    order_details ord;
     int p_ch;
    string card_name;
    string card_no;
    int exp_month,con_ch;
    int exp_year,CVV,OTP,COD_ch,o_c;

    //function to display order details
   void show(men *m,women *wo,kid *ki,homeappliances *h, gadgets *g)
    {
        Count =0;
        ord.cal_price(m,wo,ki,h,g);
        if(Count>0)
        {
            s.getdata();
            s.putdata();
        }
    }

    //function for payment
    void pay()
    {
        cout<<"\n\nmodes of payment\n\n";
        cout<<"\n\n1-Net banking\n2-EMI\n3-COD\n";
        cout<<"\nEnter your choice\n";
        cin>>hi;

        if(hi==1)
        {
        cout<<"You have chosen net banking mode\n";
        cout<<"enter the name on the card\n";
        cin>>card_name;
        cout<<"enter the card number\n";
        cin>>card_no;
        cout<<"enter the expiry month of the card\n";
        cin>>exp_month;
        cout<<"enter the expiry year of the card\n";
        cin>>exp_year;
        cout<<"enter CVV of your card\n";
        cin>>CVV;
        cout<<"Now you have landed on the bank confirmation page\n";
        cout<<"enter the OTP provided by the bank sent to your mobile";
        cin>>OTP;
        cout<<"press 1 to confirm order";
        cin>>o_c;

        if(o_c==1)
          {
            cout<<"order is confirmed!! Happy shopping!!!";
          }
        }

        else if(hi==2)
        {

        }

        else if(hi==3)
        {
            printf("Contact details of your agent\n");
            printf("Name: Chatur Ramalingam\n");
            printf("Phone-Number- 9191234523\n");
        }
    }

};


//class user
class user
{
protected:
    char username[50];
    char password[50];
public:
    //function for customer login
    void clogin(char un[],char pw[])
    {
        ifstream fs("clogin.txt",ios::in);
       for(int i=0;i<2;i++)
        {
          fs>>username>>password;
          int n;

          if (strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
          {
            cout<<"  Welcome to customer"<<" "<<username<<endl;
            cout<<"  Press any key to continue shopping"<<endl;
            break;
          }

          else
          {
              //exception handling
              try
            {
              if(strcmp(un,this->username)!=0)
               {
                   n=1;
               }
              if(strcmp(pw,this->password)!=0)
               {
                   n=2;
               }
               if(strcmp(un,this->username)!=0 && strcmp(pw,this->password)!=0)
               {
                   n=0;
               }

               throw n;
            }

            catch(...)
            {if(n==1)
             cout<<" enter correct the username"<<endl;
             if(n==2)
             cout<<" enter correct password "<<endl;
             if(n==0)
             cout<<" enter correct username and password\n";
             exit(0);

            }
          }
          }
        fs.close();

    }

    //function for administrator login
    void alogin(char un[],char pw[])
    {
        int n;
        ifstream fs("alogin.txt",ios::in);

        while(!fs.eof())
        {
          fs>>username>>password;

          if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
          {
            cout<<"  Welcome to administrator"<<" "<<username<<endl;
            break;
           }

           else
           {
               //exception handling
              try
            {
              if(strcmp(un,this->username)!=0)
               {
                   n=1;
               }
              if(strcmp(pw,this->password)!=0)
               {
                   n=2;
               }
               if(strcmp(un,this->username)!=0 && strcmp(pw,this->password)!=0)
               {
                   n=0;
               }

               throw n;

            }

            catch(...)
            {if(n==1)
             cout<<"  enter correct the username"<<endl;
             if(n==2)
             cout<<"  enter correct password "<<endl;
             if(n==0)
             cout<<" enter correct username and password\n";
             break;
            }
           }
          }
        fs.close();
    }
};


//class customer which is publicly inherited from class user
class customer:public user
{
protected:
    char c_name[20];
    char c_address[200];
    char c_email[100];
    long int c_phoneno;
    char name[50];
    char pkey[50];

public:
    void register1()
    {
       ofstream fs("customer.txt",ios::app);
       cout<<"  enter your name"<<endl;
       cout<<"  ";
       cin>>c_name;
       cout<<"  enter your address"<<endl;
       cout<<"  ";
       cin>>c_address;
       cout<<"  enter your email-id"<<endl;
       cout<<"  ";
       cin>>c_email;
       cout<<"  enter your phone number"<<endl;
       cout<<"  ";
       cin>>c_phoneno;
       fs<<endl<<c_name<<" "<<c_address<<" "<<c_email<<" "<<c_phoneno<<" ";
       fs.close();

       ofstream sf("clogin.txt",ios::app);
       cout<<"  enter the username you wish to keep"<<endl;
       cout<<"  ";
       cin>>name;
       cout<<"  enter the password you wish to keep"<<endl;
    cout<<"  ";
       cin>>pkey;
       sf<<endl<<name<<" "<<pkey<<" ";
       sf.close();

       cout<<"  Thank you"<<c_name<<"! your account has been created"<<endl;
       cout<<"  ENJOY SHOPPING*"<<endl;
    }
};

//class administrator which is publicly inherited from class user
class administrator:public user
{
protected:
    char a_name[20];
    char email[100];
public:
    void createcategory()
    {
        int c_id;
        int d_id;
        char c_name[50];
        string c_desc;

        ofstream a("category.txt",ios::app);
        cout<<"enter id for the new category"<<endl;
        cin>>c_id;
        cout<<"enter department id for the new category"<<endl;
        cin>>d_id;
        cout<<"enter category name"<<endl;
        cin>>c_name;
        cout<<"enter description for the new category"<<endl;
        cin>>c_desc;
        a<<endl<<c_id<<" "<<d_id<<" "<<c_name<<" "<<c_desc<<" ";
        a.close();

        cout<<c_name<<"category has been created"<<endl;
    }

};

//class customerService
class customerService
{
public:
    void help()
    {
        cout<<"\n\nNeed help?"<<endl;
        cout<<"Please get in touch and we will be happy to help you"<<endl;
        cout<<"\nCONTACT US"<<endl;
        cout<<"\nEmail us at - oss_admin@gmail.com"<<endl;
        cout<<"\tWe will get back to you in 48 hours"<<endl;
        cout<<"\nCall me back - 1234"<<endl;
        cout<<"\tNot available from 1:00AM to 8:00AM"<<endl;
        cout<<"\nWrite to us - 9800976540"<<endl;
        cout<<"\tAverage response time 24-48hours"<<endl;
        cout<<"\nPostal address -"<<endl;
        cout<<"Returns processing facility :"<<endl;
        cout<<"\tSurvey number 231,232 and 233,"<<endl;
        cout<<"\tSoukya Road,Samethanahalli village,"<<endl;
        cout<<"\tAnugondanahalli hobli,Hoskote Taluk,"<<endl;
        cout<<"\tBanglore-560067."<<endl;
        cout<<"\nCorporate office :"<<endl;
        cout<<"\tABCD Pvt.Ltd."<<endl;
        cout<<"\tBuildings Alyssa,"<<endl;
        cout<<"\tEmbassy tech village,"<<endl;
        cout<<"\tOuter ring road,"<<endl;
        cout<<"\tVarthur Hobli,"<<endl;
        cout<<"\tBanglore-560103."<<endl;

    }
};

//class feedback
class feedback
{
public:

    void fbb()
    {
        int r;
        cout<<"\nRate Your experience from 1-10 - ";
        cin>>r;
        cout<<" \n\n**THANK YOU FOR SHOPPING FROM US HAVE A NICE DAY**\n\n";
        exit (0);
    }
};


//main function
int main()
{
    cout << "\n\n \t\tONLINE SHOPPING SYSTEM" << endl << endl;
    cout <<"\t   **"<<endl;
    cout << "\t BUY ALL YOUR FAVOURITE PRODUCTS AT REASONABLE PRICE!" << endl;
    cout <<"\t   **"<<endl<<endl;

    user u1;//user object
    customer c;//customer object
    char uname[50],pword[50];
    int ch;
     men m[10];//men object
    women w[10];//women object
    kid k[10];//kid object
    homeappliances h[10];//homeappliances object
    gadgets g[10];//gadgets object
    m[0].getproduct(m);
    w[0].getproduct(w);
    k[0].getproduct(k);
    h[0].getproduct(h);
    g[0].getproduct(g);
    m[1].getproduct(m);
    w[1].getproduct(w);
    k[1].getproduct(k);
    h[1].getproduct(h);
    g[1].getproduct(g);
    m[2].getproduct(m);
    w[2].getproduct(w);
    k[2].getproduct(k);
    h[2].getproduct(h);
    g[2].getproduct(g);
    m[3].getproduct(m);
    w[3].getproduct(w);
    k[3].getproduct(k);
    h[3].getproduct(h);
    g[3].getproduct(g);
    m[4].getproduct(m);
    w[4].getproduct(w);
    k[4].getproduct(k);
    h[4].getproduct(h);
    g[4].getproduct(g);
    m[5].getproduct(m);
    w[5].getproduct(w);
    k[5].getproduct(k);
    h[5].getproduct(h);
    g[5].getproduct(g);
    m[6].getproduct(m);
    w[6].getproduct(w);
    k[6].getproduct(k);
    h[6].getproduct(h);
    g[6].getproduct(g);
    m[7].getproduct(m);
    w[7].getproduct(w);
    k[7].getproduct(k);
    h[7].getproduct(h);
    g[7].getproduct(g);
    m[8].getproduct(m);
    w[8].getproduct(w);
    k[8].getproduct(k);
    h[8].getproduct(h);
    g[8].getproduct(g);
    m[9].getproduct(m);
    w[9].getproduct(w);
    k[9].getproduct(k);
    h[9].getproduct(h);
    g[9].getproduct(g);
   product pt;//product object
   administrator a;//administrator object
   department d[2];//department objects
   d[0].getdepartment(d);
   d[1].getdepartment(d);

   int ch2;
   orders o;//order object
   customerService cs;//customer object
    feedback fb;
    cout<<"  press 1 if you are an existing customer and you want to log in"<<endl;
    cout<<"  press 2 if you are a new customer and you want to register yourself"<<endl;
    cout<<"  press 3 if you are an administrator"<<endl<<endl;
    cout<<"  ";
    cin>>ch;

    if(ch==1)
    {
        cout<<"  enter your username"<<endl;
        cout<<"  ";
        cin>>uname;
        cout<<"  enter your password"<<endl;
         cout<<"  ";
        cin>>pword;
        u1.clogin(uname,pword);
         main:
             getch();
            system("cls");
            cout<<"\n Enter your choice:\n1.DEPARTMENT.\n2.CATEGORIES AND PRODUCTS\n3.ORDER\n4.PAYMENT METHOD\n5.HELP\n6.FEEDBACK\n7.EXIT\n\n\n";
            cin>>ch2;
          if(ch2==1)
            {
                for(int i=0;i<2;i++)
                {
              d[i].display2();
                }

              goto main;
            }

          else if(ch2==2)
          {
             pt.print(m,w,k,h,g);
             cout<<"press any key to continue";
             goto main;
          }

          else if(ch2==3)
          {
            o.show(m,w,k,h,g);
            goto main;
          }

          else if(ch2==4)
          {
         o.pay();
         goto main;
          }

          else if(ch2==5)
          {
              cs.help();
              goto main;
          }

          else if(ch2==6)
          {
               fb.fbb();
               goto main;
          }

          else
          {
              exit(0);
          }
    }

    else if(ch==2)
    {
        c.register1();
        mainnn:
            getch();
            system("cls");
            cout<<" Enter your choice:\n1.DEPARTMENT.\n2.CATEGORIES AND PRODUCTS\n3.ORDER\n4.PAYMENT METHOD\n5.HELP\n6.FEEDBACK\n7.EXIT\n\n";
            cin>>ch2;
          if(ch2==1)
            {
               for(int i=0;i<2;i++)
                {
              d[i].display2();
                }
              goto mainnn;
            }

          else if(ch2==2)
          {
             pt.print(m,w,k,h,g);
             goto mainnn;
          }

          else if(ch2==3)
          {
            o.show(m,w,k,h,g);
            goto mainnn;
          }

          else if(ch2==4)
          {
            o.pay();
            goto mainnn;
          }

           else if(ch2==5)
          {
              cs.help();
          }

          else if(ch2==6)
          {
               fb.fbb();
          }

          else
          {
              exit(0);
          }
    }

    else if(ch==3)
    {
        int c;
        cout<<"  enter your username"<<endl;
        cout<<"  ";
        cin>>uname;
        cout<<"  enter your password"<<endl;
         cout<<"  ";
        cin>>pword;
        u1.alogin(uname,pword);
        cout<<"  PRESS 1 IF YOU WANT TO ADD A NEW CATEGORY"<<endl;
        cout<<"  PRESS 2 IF YOU WANT TO EXIT"<<endl;
        cout<<"  ENTER YOUR CHOICE"<<endl;
          cout<<"  ";
        cin>>c;
        if(c==1)
        {
           a.createcategory();
        }
        else
        {
            exit(0);
        }
    }
}

