#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void menu_user()
{
    printf("\nMENU\n");
    printf("1-Search\n");
    printf("2-Bestsellers\n");
    printf("3-Deals of the day\n");
    printf("4-Display Cart\n");
    printf("5-Delete from cart\n");
    printf("6-Checkout\n");
    printf("7-Display your orders\n");
    printf("8-Cancel orders\n");
    printf("9-Buy Again\n");
    printf("10-Customer Services\n");
    printf("11-Return and refunds\n");
    printf("Anything else to exit\n");
}
void menu_seller()
{
    printf("MENU\n");
    printf("1- Add items to Catalogue\n");
    printf("2- View orders to fulfil\n");
    printf("Anything else to exit\n");
}
struct product
{
    float rating;
    int price;
    char model[100];
    char sellerman[100];
};
struct user
{
    char name[20];
    char address[50];
    int phone;
    int card;
};
struct seller
{
    char sellername[30];
    char PAN[12];
    char GST[20];

};
struct log
{
    float rate;
    int cost;
    char mod[50];
    char selr[20];
    char usr[20];
};
struct coupon
{
    int s_no;
    char co[50];
};
struct user us[10];
//array of laptops
struct product laptops[100];
//array of mobiles
struct product mobiles[100];
//array of tabs
struct product tabs[100];
//array containing all products sorted acc to ratinng
struct product all[500];
//array containing all pr
struct product allp[500];
//array containing all found elements
struct product searched[100];
//array containing all searched elements
struct product cart[100];
//array containing all orders
struct product y_orders[100];
//array containing all orders in reverse order
struct product y_orders_r[100];
//structure containing a returned item
struct product returns1;
//array of sellers
struct seller sell[15];
//array of logs
struct log lg[100];
//array for seller 1
struct log seller1[20];
//array of seller 2
struct log seller2[20];
//array of seller 3
struct log seller3[20];
struct coupon c[20];

int global_count1=0; //count for laptops
int global_count2=0; //count for mobiles
int global_count3=0; //count for tabs
int global_count4=0; //count after merging all 3 sorted acc to rating
int global_count5=0; //count of items in car
int global_count6=0; //count after merging all 3 sorted acc to price
int global_count7=0; //count of your orders
int global_count8=0; //count of your orders in reverse
int global_count9=0; //count of users
int global_count10=0; //count of sellers
int global_count11=0; //count of log
int global_count12=0; //count of seller 1 orders
int global_count13=0; //count of seller 2 orders
int global_count14=0; //count of seller 3 orders
int global_count15=0;
void load_from_file1()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("laptops.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%f\t%d\t%[^\n]s\t%[^\n]s", &laptops[global_count1].rating, &laptops[global_count1].price,laptops[global_count1].model ,laptops[global_count1].sellerman);

        global_count1++;
    }
    fclose(fp);
}

void load_from_file2()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("mobiles.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%f\t%d\t%[^\n]s\t%[^\n]s", &mobiles[global_count2].rating, &mobiles[global_count2].price, mobiles[global_count2].model, mobiles[global_count2].sellerman);

        global_count2++;
    }
    fclose(fp);
}

void load_from_file3()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("tabs.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%f\t%d\t%[^\n]s\t%[^\n]s", &tabs[global_count3].rating, &tabs[global_count3].price, tabs[global_count3].model, tabs[global_count3].sellerman);

        global_count3++;
    }
    fclose(fp);
}


void load_from_file4()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("users.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s\t%d\t%d", us[global_count9].name, us[global_count9].address, &us[global_count9].phone, &us[global_count9].card);
        //printf("%s\t%s\t%d\t%d", us[global_count9].name, us[global_count9].address, us[global_count9].phone, us[global_count9].card);
        global_count9++;
    }
    fclose(fp);
}

void load_from_file5()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("sellers.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s\t%s", sell[global_count10].sellername, sell[global_count10].PAN, sell[global_count10].GST);
        global_count10++;
    }
    fclose(fp);
}

void load_from_file6()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("log.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp, "%f\t%d\t%[^\n]s\t%[^\n]s", &lg[global_count11].rate, &lg[global_count11].cost, lg[global_count11].mod, lg[global_count11].selr, lg[global_count11].usr);

        global_count11++;
    }
    fclose(fp);
}
void load_from_file7()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("seller1.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp, "%f\t%d\t%[^\n]s\t%[^\n]s", &seller1[global_count12].rate, &seller1[global_count12].cost, seller1[global_count12].mod, seller1[global_count12].selr, seller1[global_count12].usr);

        global_count12++;
    }
    fclose(fp);
}
void load_from_file8()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("seller2.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp, "%f\t%d\t%[^\n]s\t%[^\n]s", &seller2[global_count13].rate, &seller2[global_count13].cost, seller2[global_count13].mod, seller2[global_count13].selr, seller2[global_count13].usr);

        global_count13++;
    }
    fclose(fp);
}
void load_from_file9()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("seller3.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }



    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp, "%f\t%d\t%[^\n]s\t%[^\n]s", &seller3[global_count14].rate, &seller3[global_count14].cost, seller3[global_count14].mod, seller3[global_count14].selr, seller3[global_count14].usr);

        global_count14++;
    }
    fclose(fp);
}
void load_from_file10()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("coupons.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }
    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp, "%d\t%[^\n]s",&c[global_count15].s_no,c[global_count15].co);
        //printf("%d\t%s\n", c[global_count15].s_no,c[global_count15].co);

        global_count15++;
    }
    fclose(fp);
}

void sort(struct product a[100], int global_count)
{
    int i, j=0;
    struct product k;
    for(i=0;i<global_count;i++)
    {
        k=a[i];
        j=i-1;

        while(j>=0 && k.rating>a[j].rating)
        {

            a[j+1]=a[j];
            j--;

        }
        a[j+1]=k;
    }
}

void bestsellers(struct product laptops[100], struct product mobiles[100], struct product tabs[100], struct product cart[100])
{
    int ch,i;
    sort(laptops, global_count1);
    sort(mobiles, global_count2);
    sort(tabs, global_count3);
    while(1)
    {
        printf("\nBESTSELLERS\n");
        printf("Press\n1 for Laptops\n2 for SmartPhones\n3 for Tabs:\n");
        printf("choose the category from which you want to purchase: ");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:
                printf("Bestsellers in Laptop:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",laptops[i].rating, laptops[i].price,laptops[i].model );
                }


                 int a;
                 printf("\nchoose the model you want to purchase:");
                 printf("\nPress\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&a);
                 if(a==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",laptops[0].rating, laptops[0].price,laptops[0].model);
                       add_to_cart1(cart, laptops[0]);

                 }
                 else if(a==2)
                 {
                    printf("\n%0.1f\t%d\t%s\n",laptops[1].rating, laptops[1].price,laptops[1].model);
                    add_to_cart1(cart, laptops[1]);
                 }
                 else if(a==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n",laptops[2].rating, laptops[2].price,laptops[2].model);
                     add_to_cart1(cart, laptops[2]);
                 }
                 else
                 {
                     printf("invalid choice!");
                 }
                 break;


        case 2: printf("Bestsellers in MobilePhones:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",mobiles[i].rating, mobiles[i].price, mobiles[i].model );
                }


                 int b;
                 printf("\nchoose the model you want to purchase: ");
                 printf("\nPress\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&b);
                 if(b==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",mobiles[0].rating, mobiles[0].price,mobiles[0].model);
                       add_to_cart1(cart, mobiles[0]);

                 }
                else if(b==2)
                {
                    printf("\n%0.1f\t%d\t%s\n",mobiles[1].rating, mobiles[1].price,mobiles[1].model);
                    add_to_cart1(cart, mobiles[1]);
                 }
               else if(b==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n",mobiles[2].rating, mobiles[2].price, mobiles[2].model);
                     add_to_cart1(cart, mobiles[2]);
                 }
               else
                {
                     printf("invalid choice!");
                }
                break;

        case 3:  printf("Bestsellers in Tabs:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",tabs[i].rating, tabs[i].price, tabs[i].model );
                }


                 int c;
                 printf("choose the model you want to purchase:\n");
                 printf("Press\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&c);
                 if(c==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",tabs[0].rating, tabs[0].price, tabs[0].model);
                       add_to_cart1(cart, tabs[0]);

                 }
                else if(c==2)
                {
                    printf("\n%0.1f\t%d\t%s\n", tabs[1].rating, tabs[1].price, tabs[1].model);
                    add_to_cart1(cart, tabs[1]);
                 }
               else if(c==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n", tabs[2].rating, tabs[2].price, tabs[2].model);
                     add_to_cart1(cart, tabs[2]);
                 }
               else
                {
                     printf("invalid choice!");
                }
                break;
        default: return;
        }
    }
}
void sort1(struct product a[100], int global_count)
{
    int i, j=0;
    struct product k;
    for(i=0;i<global_count;i++)
    {
        k=a[i];
        j=i-1;

        while(j>=0 && k.price<a[j].price)
        {

            a[j+1]=a[j];
            j--;

        }
        a[j+1]=k;
    }
}

void deals(struct product laptops[100], struct product mobiles[100], struct product tabs[100], struct product cart[100])
{
    sort1(laptops, global_count1);
    sort1(mobiles, global_count2);
    sort1(tabs, global_count3);
    int ch, i;
    while(1)
    {
        printf("\nDEALS OF THE DAY!\n");
        printf("Press\n1 for Laptops\n2 for SmartPhones\n3 for Tabs:\n");
        printf("choose the category from which you want to purchase: ");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:
                printf("Bestsellers in Laptop:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",laptops[i].rating, laptops[i].price,laptops[i].model );
                }


                 int a;
                 printf("\nchoose the model you want to purchase:");
                 printf("\nPress\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&a);
                 if(a==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",laptops[0].rating, laptops[0].price,laptops[0].model);
                       add_to_cart1(cart, laptops[0]);

                 }
                 else if(a==2)
                 {
                    printf("\n%0.1f\t%d\t%s\n",laptops[1].rating, laptops[1].price,laptops[1].model);
                    add_to_cart1(cart, laptops[1]);
                 }
                 else if(a==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n",laptops[2].rating, laptops[2].price,laptops[2].model);
                     add_to_cart1(cart, laptops[2]);
                 }
                 else
                 {
                     printf("invalid choice!");
                 }
                 break;


        case 2: printf("Bestsellers in MobilePhones:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",mobiles[i].rating, mobiles[i].price, mobiles[i].model );
                }


                 int b;
                 printf("\nchoose the model you want to purchase: ");
                 printf("\nPress\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&b);
                 if(b==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",mobiles[0].rating, mobiles[0].price,mobiles[0].model);
                       add_to_cart1(cart, mobiles[0]);

                 }
                else if(b==2)
                {
                    printf("\n%0.1f\t%d\t%s\n",mobiles[1].rating, mobiles[1].price,mobiles[1].model);
                    add_to_cart1(cart, mobiles[1]);

                 }
               else if(b==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n",mobiles[2].rating, mobiles[2].price, mobiles[2].model);
                     add_to_cart1(cart, mobiles[2]);

                 }
               else
                {
                     printf("invalid choice!");
                }
                break;

        case 3:  printf("Bestsellers in Tabs:");
                for(i=0;i<3;i++)
                {
                    printf("\n%0.1f\t%d\t%s\n",tabs[i].rating, tabs[i].price, tabs[i].model );
                }


                 int c;
                 printf("choose the model you want to purchase:");
                 printf("\nPress\n1 for MODEL 1\t2 for MODEL2\t3 for MODEL 3:\n");
                 printf("enter your choice:\n");
                 scanf("%d",&c);
                 if(c==1)
                 {
                       printf("\n%0.1f\t%d\t%s\n",tabs[0].rating, tabs[0].price, tabs[0].model);
                       add_to_cart1(cart, tabs[0]);


                 }
                else if(c==2)
                {
                    printf("\n%0.1f\t%d\t%s\n", tabs[1].rating, tabs[1].price, tabs[1].model);
                    add_to_cart1(cart, tabs[1]);

                 }
               else if(c==3)
                 {
                     printf("\n%0.1f\t%d\t%s\n", tabs[2].rating, tabs[2].price, tabs[2].model);
                     add_to_cart1(cart, tabs[2]);

                 }
               else
                {
                     printf("invalid choice!");
                }
                break;
        default: return;
        }
    }
}
void merge(struct product laptops[100], struct product mobiles[100], struct product tabs[100], struct product all[500], int global_count1, int global_count2, int global_count3, int s)
{
    int i, j, k;
    if(s==0)
    {
        sort(laptops, global_count1);
        sort(mobiles, global_count2);
        sort(tabs, global_count3);
    }
    else
    {
        sort1(laptops, global_count1);
        sort1(mobiles, global_count2);
        sort1(tabs, global_count3);
    }

    for(i=0;i<global_count1;i++)
    {
        all[i]=laptops[i];
        if(s==0)
            global_count4++;
        else
            global_count6++;
    }
    for(i=0, j=global_count1;i<global_count2, j<global_count1+global_count2; i++, j++)
    {
        all[j]=mobiles[i];
        if(s==0)
            global_count4++;
        else
            global_count6++;
    }
    for(i=0, k=global_count2+global_count1;i<global_count3, k<global_count1+global_count2+global_count3;i++, k++)
    {
        all[k]=tabs[i];
        if(s==0)
            global_count4++;
        else
            global_count6++;
    }
}
void search_text(struct product all[500], struct product searched[100], int global_count4, char *st)
{
    int M, N, i, j, a, k=0, item, flag=0, qt;
    for(a=0;a<global_count4;a++)
    {
        M = strlen(st);
        N = strlen(all[a].model);

        for (i = 0; i <= N - M; i++)
        {
            j=0;
            while (j < M && st[j] == all[a].model[i+j])
            {
                j=j+1;
            }
            if (j == M)
            {
                printf("\n%0.1f\t%d\t%s\n", all[a].rating, all[a].price,all[a].model);
                searched[k]=all[a];
                printf("Press %d to add this into cart\n", k);
                k++;
                flag=1;
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("No products found\n");
    }
    printf("Press anything else to go back\n");
    scanf("%d", &item);
    if(item<k)
    {
        add_to_cart(searched, cart, item);
    }
    else
        return;

}
void dealz(struct product all[500], int global_count4)
{
    int r1, o;
    struct product r;
    r1= rand() % global_count4;
    r=all[r1];
    printf("--------------------------------------------------------\n");
    printf("Blockbuster Dealzz\n");
    printf("Buy %s at the cost of %d only. \n", all[r1].model, all[r1].price);
    printf("--------------------------------------------------------\n");
    printf("Enter 0 to add to cart\n");
    scanf("%d", &o);
    if(o==0)
        add_to_cart1(cart, r);
    else
        return;
}
void display(struct product a[100], int global_count)
{
    int i;
    for(i=0;i<global_count;i++)
    {
        printf("%0.1f\t%d\t%s\n",a[i].rating, a[i].price, a[i].model,a[i].sellerman);
    }
}
void display_user(struct user us[10], int global_count9)
{
    int i;
    for(i=0;i<global_count9;i++)
    {
        printf("%s\t%s\t%d\t%d\n", us[i].name, us[i].address, us[i].phone, us[i].card);
    }
}
void display_seller(struct seller sell[10], int global_count10)
{
    int i;
    for(i=0;i<global_count10;i++)
    {
        printf("%s\t%s\t%s\n", sell[i].sellername, sell[i].PAN, sell[i].GST);
    }
}
void display_seller_orders(struct log s[100], int global_count)
{
    int i;
    for(i=0;i<global_count;i++)
    {
        printf("%0.1f\t%d\t%s\t%s\t%s\n", s[i].rate, s[i].cost, s[i].mod, s[i].selr, s[i].usr);
    }
}
int totalcart(struct product cart[100], int global_count5)
{
    int i, sum=0;
    for(i=0;i<global_count5;i++)
    {
        sum=sum+cart[i].price;
    }
    //printf("Total %d\n", sum);
    return sum;
}
int total_items_cart(struct product cart[100], int global_count5)
{
    int i, count=0;
    for(i=0;i<global_count5;i++)
    {
        count++;
    }
    return count;
}
void add_to_cart(struct product searched[100], struct product cart[100], int item)
{
    int qt;
    printf("Enter Quantity\n");
    scanf("%d", &qt);
    int i;
    for(i=0;i<qt;i++)
    {
        cart[global_count5]=searched[item];
        if(i==1)
            printf("\n%0.1f\t%d\t%s\n%d of %s\tadded to cart\n", cart[global_count5].rating, cart[global_count5].price, cart[global_count5].model, qt, cart[global_count5].model);
        global_count5++;
    }

}
void add_to_cart1(struct product cart[100], struct product k)
{
    int qt;
    cart[global_count5]=k;
    printf("Enter Quantity\n");
    scanf("%d", &qt);
    int i;
    for(i=0;i<qt;i++)
    {
        cart[global_count5]=k;
        if(i==1)
            printf("\n%0.1f\t%d\t%s\n%d of %s\tadded to cart\n", cart[global_count5].rating, cart[global_count5].price, cart[global_count5].model, qt, cart[global_count5].model);
        global_count5++;
    }
}
void delete_items(struct product cart[100],int del_item,int global_count5)
{
    int i;
    for(i=del_item;i<global_count5;i++)
    {
        cart[i]=cart[i+1];

    }

}
void discount()
{
    int i, total, diff, tot;
    total=totalcart(cart, global_count5);
    printf("Total %d\n", total);
    if(total<50000)
    {
        diff=50000-total;
        printf("Buy %d worth more products to get discounts\n", diff);
    }
    else if(total>=50000 && total<100000)
    {
        tot=total-(0.1*total);
        printf("Total price after discount %d\n", tot);
    }
    else
    {
        tot=total-(0.2*total);
        printf("Total price after discount %d\n", tot);
    }
}
void checkout(struct product cart[100],struct product y[100],int global_count5 )
{
    int i,co_ch;
    char st[50];
    for(i=0;i<global_count5;i++)
    {
        y[i]=cart[i];
        global_count7++;

    }
    printf("Do you have coupons?\n");
    printf("If yes press 1 if no press any button and continue\n");
    scanf("%d",&co_ch);
    switch(co_ch)
    {
        case 1:printf("enter your coupon name\n");
               scanf("%s",st);
               avial_coupons(c,global_count15,st);
               break;
    default :printf("No coupons\n");
                break;

    }

    modes_of_delivery();
}
void avial_coupons(struct coupon c[100],int global_count15,char *st)
{
    //load_from_file10();
    int total;
    int M, N, i, j, l, flag=0;
    printf("\n");

    for(l=0;l<global_count15;l++)
    {

        M = strlen(st);

        N = strlen(c[l].co);



        for (i = 0; i <= N - M; i++)
        {
            j=0;
            while (j < M && st[j] == c[l].co[i+j])
            {
                j=j+1;
            }
            if (j == M)
            {
                printf("You have unlocked this coupon get 10 percent discount on your purchase\n");
                total=totalcart(cart, global_count5);
                printf("Total %d\n", total);
                total=total-(10*total)/100;
                printf("Total amount after availing the coupon is:%d\n", total);
                flag=1;
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("No coupons matched\n");
    }


}
void modes_of_delivery()
{
    int p_ch;
    char card_name[20];
    char card_no[12];
    int exp_month,con_ch;
    int exp_year,CVV,OTP,COD_ch;
    printf("Enter your choice of payment:\n");
    printf("1-Net banking\n2-EMI\n3-COD\n");
    scanf("%d",&p_ch);
    if(p_ch==1)
    {
        printf("You have chosen net banking mode\n");
        printf("enter the name on the card\n");
        scanf("%s",card_name);
        printf("enter the card number\n");
        scanf("%s",card_no);
        printf("enter the expiry month of the card\n");
        scanf("%d",&exp_month);
        printf("enter the expiry year of the card\n");
        scanf("%d",&exp_year);
        printf("enter CVV of your card\n");
        scanf("%d",&CVV);
        printf("Now you have landed on the bank confirmation page\n");
        printf("enter the OTP provided by the bank sent to your mobile");
        scanf("%d",&OTP);
        int fml;
        fml=rand()%1;
        if(fml==0)
        {
            printf("Payment failed\nTry again\n");
        }

        else
        {
           printf("Payment successful\n");

           printf("Confirm your order?\n");
           printf("1-place order,2-go back");
           scanf("%d",&con_ch);
          if(con_ch==1)
           {
            printf("your order has been placed!!\n");
           }
          else
          {
            printf("your order has not been placed\n");
          }

        }

    }
    else if(p_ch==2)
    {
       printf("i donnooo");

    }
    else if(p_ch==3)
    {

            printf("Contact details of your agent\n");
            printf("Name: Chatur Ramalingam\n");
            printf("Phone-Number- 9191234523\n");
    }

}

void logs(struct product y_orders[100], int global_count7, int a, struct user us[100])
{
    FILE *fptr;
    fptr=fopen("log.txt", "a");
    int i;
    for(i=0;i<global_count7;i++)
    {
         fprintf(fptr, "%0.1f\t%d\t%s\t%s\t%s\n", y_orders[i].rating, y_orders[i].price, y_orders[i].model, y_orders[i].sellerman, us[a].name);
    }
}
void buy_again(struct product y_orders[100],struct product y_orders_r[100],int global_count7)
{
    int i,j,k, option;
    for(i=0,j=global_count7-1;j>=0, i<global_count7;i++,j--)
    {
        y_orders_r[i]=y_orders[j];
        global_count8++;
    }
    for(k=0;k<3;k++)
    {
        printf("%0.1f\t%d\t%s\n",y_orders_r[k].rating, y_orders_r[k].price, y_orders_r[k].model);
        printf("Press %d to add this to cart\n", k);
    }
    printf("enter option:\n");
    scanf("%d",&option);
    if(option==0)
    {
        add_to_cart(y_orders_r,cart,0);
        printf("%0.1f\t%d\t%s\tadded to cart\n",y_orders_r[0].rating, y_orders_r[0].price, y_orders_r[0].model);
    }
    else if(option==1)
    {
        add_to_cart(y_orders_r,cart,1);
         printf("%0.1f\t%d\t%s\tadded to cart\n",y_orders_r[1].rating, y_orders_r[1].price, y_orders_r[1].model);
    }
    else if(option==2)
    {
        add_to_cart(y_orders_r,cart,2);
        printf("%0.1f\t%d\t%s\tadded to cart\n",y_orders_r[2].rating, y_orders_r[2].price, y_orders_r[2].model);
    }
    else
    {
        printf("Invalid option");
    }

}
int login_user(struct user us[10], int global_count9, char *username)
{

    //display_user(us, global_count9);
    int M, N, i, j, a, k=0, item, flag=0;
    for(a=0;a<global_count9;a++)
    {
        M = strlen(username);
        N = strlen(us[a].name);

        for (i = 0; i <= N - M; i++)
        {
            j=0;
            while (j < M && username[j] == us[a].name[i+j])
            {
                j=j+1;
            }
            if (j == M)
            {
                printf("\nLogin successful\nWELCOME %s\n", us[a].name);
                flag=1;
                return a;
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("No such user found\n");
        exit(0);
    }
}
int login_seller(struct seller sell[100], int global_count10, char *sellname)
{
    int M, N, i, j, a, k=0, item, flag=0;
    for(a=0;a<global_count10;a++)
    {
        M = strlen(sellname);
        N = strlen(sell[a].sellername);

        for (i = 0; i <= N - M; i++)
        {
            j=0;
            while (j < M && sellname[j] == sell[a].sellername[i+j])
            {
                j=j+1;
            }
            if (j == M)
            {
                printf("\nLogin successful\nWELCOME %s\n", sell[a].sellername);
                flag=1;
                return a;
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("No such seller found\n");
        exit(0);
    }
}

void edit_account()
{
    char name1[20];
    char address1[50];
    int phone1;
    int card1;
    FILE *fptr;
    fptr=fopen("users.txt", "a");
    printf("Enter new name : ");
    scanf("%s", name1);
    printf("\nEnter new address : ");
    scanf("%s", address1);
    printf("\nEnter new number : ");
    scanf("%d", &phone1);
    printf("\nEnter card number :");
    scanf("%d", &card1);
    fprintf(fptr, "%s\t%s\t%d\t%d\n", name1, address1, phone1, card1);
    printf("Added successfully\n");
}
void edit_seller()
{
    char name1[20];
    char pan1[50];
    char gst1[50];
    FILE *fptr;
    fptr=fopen("sellers.txt", "a");
    printf("\nEnter new name : ");
    scanf("%s", name1);
    printf("\nEnter PAN card number : ");
    scanf("%s", pan1);
    printf("\nEnter GST : ");
    scanf("%s", gst1);

    fprintf(fptr, "%s\t%s\t%s\n", name1, pan1, gst1);
    printf("Added successfully\n");
}

void returns_refunds(struct product y_orders[],struct product returns1,int global_count7,int pos)
{
    int i;
    returns1=y_orders[pos];
    printf("%0.1f\t%d\t%s\n",returns1.rating, returns1.price, returns1.model);
    printf("return is complete!!:");

}

void catalouges()
{
    int ca_option;
    char m1[100];
    int cp1;
    float r1;

        printf("1.laptop file 2.mobile file 3.tab file\n");
        printf("enter choice:");
        scanf("%d",&ca_option);
    if(ca_option==1)
    {
         FILE *fptr;
         fptr=fopen("laptops.txt", "a");
         printf("\nEnter new laptop model : ");
         scanf("%s", m1);
         printf("\nEnter laptop ratings : ");
         scanf("%f", &r1);
         printf("\nEnter laptop cost : ");
         scanf("%d", &cp1);

        fprintf(fptr, "%0.1f\t%d\t%s\n", r1, cp1, m1);
        printf("Added successfully\n");
    }
    else if(ca_option==2)
    {
         FILE *fptr;
         fptr=fopen("mobiles.txt", "a");
         printf("\nEnter new mobile model : ");
         scanf("%s", m1);
         printf("\nEnter mobile ratings : ");
         scanf("%f", &r1);
         printf("\nEnter mobile cost : ");
         scanf("%d", &cp1);

        fprintf(fptr,  "%0.1f\t%d\t%s\n", r1, cp1, m1);
        printf("Added successfully\n");
    }
    else if(ca_option==3)
    {
         FILE *fptr;
         fptr=fopen("tabs.txt", "a");
         printf("\nEnter new tab model : ");
         scanf("%s", m1);
         printf("\nEnter tab ratings : ");
         scanf("%f", &r1);
         printf("\nEnter tab cost : ");
         scanf("%d", &cp1);

        fprintf(fptr,  "%0.1f\t%d\t%s\n", r1, cp1, m1);
        printf("Added successfully\n");
    }
    else
    {
        printf("invalid option!");
    }

}
int which_seller(struct seller sell[100], int b)
{
    int flag=0;
    if(strcmp(sell[b].sellername, "seller1")==0)
    {
        flag=1;
    }
    else if(strcmp(sell[b].sellername, "seller2")==0)
    {
        flag=2;
    }
    else if(strcmp(sell[b].sellername, "seller3")==0)
    {
        flag=3;
    }
    else
        printf("Seller not found\n");
    return flag;
}
/*void load_into(struct log seller1[100], int global_count, int a)
{
    int x;
    x=which_seller(a);
    FILE *fptr, *fptr1, *fptr2;
    fptr=fopen("seller1.txt", "a");
    fptr1=fopen("seller2.txt", "a");
    fptr2=fopen("seller3.txt", "a");
    if(x==0)
    {
        fprintf(fptr, "%d\t%d\t%s\t%s\t%s\n", seller1[a].rate, seller1[a].cost, seller1[a].mod, seller1[a].selr, seller1[a].usr);
    }
    else if(x==1)
    {
        fprintf(fptr1, "%d\t%d\t%s\t%s\t%s\n", seller1[a].rate, seller1[a].cost, seller1[a].mod, seller1[a].selr, seller1[a].usr);
    }
    else
    {
        fprintf(fptr2, "%d\t%d\t%s\t%s\t%s\n", seller1[a].rate, seller1[a].cost, seller1[a].mod, seller1[a].selr, seller1[a].usr);
    }
}*/
/*void seller_orders(struct seller sell[100], int b, struct log lg[100], int global_count11, struct log seller1[100], int global_count)
{
    int M, N, i, j, a, k=0, item, flag=0;
    for(a=0;a<global_count11;a++)
    {
        M = strlen(sell[b].sellername);
        N = strlen(lg[a].selr);

        for (i = 0; i <= N - M; i++)
        {
            j=0;
            while (j < M && sell[b].sellername[j] == lg[a].selr[i+j])
            {
                j=j+1;
            }
            if (j == M)
            {
                seller1[k]=lg[a];
                k++;
                flag=1;
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("No orders found\n");
        exit(0);
    }
    global_count=k;
    display_seller_orders(seller1, k);
}*/
int main()
{
    printf("Enter 0 if youre a Buyer\n");
    printf("Enter 1 if youre a Seller\n");
    int choice;
    scanf("%d", &choice);
    if(choice==0)
    {
        int ch4, a;
        printf("\nEnter 0 to create new account\n Anything else to log in\n");
        scanf("%d", &ch4);
        if(ch4==0)
        {
            edit_account();
            printf("Please restart the app\n");
            exit(0);
        }
        load_from_file4();
        char username[200];
        printf("\nLOGIN\n");
        printf("Enter your username : ");
        scanf("%s",username);
        a=login_user(us, global_count9, username);
        load_from_file1();
        load_from_file2();
        load_from_file3();
        int i, ch, sortoption,count,del_item, ch1, ch2, option, pos;
        char st[100];
        printf("\n");
        merge(laptops, mobiles, tabs, all, global_count1, global_count2, global_count3, 0);
        //display(all, global_count4);
        printf("\n");
        merge(laptops, mobiles, tabs, allp, global_count1, global_count2, global_count3, 1);
        //display(allp, global_count6);
         load_from_file10();
        while(1)
        {
            menu_user();
            printf("\n\nEnter Choice : ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1: printf("enter string: ");
                        fflush(stdin);
                        gets(st);
                        printf("Press 0 to sort by rating, 1 to sort by price : ");
                        scanf("%d", &sortoption);
                        if(sortoption==0)
                            search_text(all, searched, global_count4, st);
                        else
                            search_text(allp, searched, global_count6, st);
                        break;

                case 2: bestsellers(laptops, mobiles, tabs, cart);
                        break;

                case 3: deals(laptops, mobiles, tabs, cart);
                        break;

                case 4: if(global_count5==0)
                            printf("Cart empty\n");
                        display(cart, global_count5);
                        totalcart(cart, global_count5);
                        discount();
                        count=total_items_cart(cart, global_count5);
                        break;

                case 5: printf("Enter the location from which u want to delete:\n");
                        scanf("%d",&del_item);
                        delete_items(cart,del_item,global_count5);
                        global_count5--;
                        break;

                case 6: printf("CHECKOUT!!");
                        checkout(cart,y_orders,global_count5);
                        global_count5=0;
                        //display(cart, global_count5);
                        printf("\n");
                        //display(y_orders, global_count7);
                        printf("Your order has been placed :\n");
                        printf("Cart empty\n");
                        dealz(all, global_count4);
                        logs(y_orders, global_count7, a, us);
                        break;

                case 7:display(y_orders,global_count7);
                       break;

                case 8: printf("Cancel orders:\n");
                        printf("enter the location from which u want to delete:\n");
                        scanf("%d",&del_item);
                        delete_items(y_orders,del_item,global_count7);
                        global_count7--;
                        display(y_orders, global_count7);
                        break;

              case 9: printf("Buy again:\n");
                      buy_again(y_orders,y_orders_r,global_count7);
                      break;

              case 10: printf("Customer Services\n");
                      printf("Menu\n1 View Account\n2 Account settings\n");
                      scanf("%d", &ch1);
                      if(ch1==1)
                      {
                          printf("%s\t%s\t%d\t%d\n", us[a].name, us[a].address, us[a].phone, us[a].card);
                      }
                      else if(ch1==2)
                      {
                            printf("Account Settings\n");
                            printf("Account details\n");
                            printf("Press 1 to edit your account\n");
                            scanf("%d", &ch2);
                            if(ch2==1)
                                edit_account(us);
                      }
                      break;
              case 11: printf("Returns and refunds!!\n");
                       printf("enter postion:\n");
                       scanf("%d",&pos);
                       returns_refunds(y_orders,returns1,global_count7,pos);
                       break;

              default : exit(0);

            }
        }
    }
    else if(choice==1)
    {
        printf("Enter 0 to create a new account\nAnything else to login: ");
        int ch5, b, ch6;
        scanf("%d", &ch5);
        if(ch5==0)
        {
            edit_seller();
            printf("\nRestart the app\n");
            exit(0);
        }
        load_from_file5();
        char sellname[200];
        printf("\nLOGIN\n");
        printf("Enter username : ");
        scanf("%s", sellname);
        b=login_seller(sell, global_count10, sellname);
        load_from_file6();
        display_seller_orders(lg, global_count11);
        while(1)
        {
            menu_seller();
            scanf("%d", &ch6);
            switch(ch6)
            {
                case 1: catalouges();
                        break;
                case 2: //seller_orders(sell, lg, global_count11, b, seller1, global_count12);
                        break;
                default: exit(0);
                         break;
            }
        }

    }
    else
        printf("Invalid choice\n");

    return 0;

}

