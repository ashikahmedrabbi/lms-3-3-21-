#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

/*///////////////////////////////////////////////////////////////////login System Variable Start //////////////////////////////////////////////////////*/
struct login{
    char first_name[20];
    char last_name[20];
    char username[20];
    char password[20];


};
struct Alogin{
    char Afirst_name[20];
    char Alast_name[20];
    char Ausername[20];
    char Apassword[20];
    char Email [30];
    char admin_id[20];


};

struct book
{

    long id;

    char name[30],author[20],subject[30];
    //int intake;

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;
struct messa
{
    char mes[50];
    char rmes[50];
}li,lr;

struct payment
{
    char pass [20],add[20],price [20],AN[20], email[30];
    long ph,cvc,valid;

}pay;
/*/////////////////////////////////////////////////////////////////// login System Variable End //////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////login System Function///////////////////////////////////////////////////////////*/


  /************************registe********/
int registe (){
    FILE *log;
   log=fopen("login_info.dll","w");
    struct login l;
    //FILE *fptr;
    //fptr = fopen("login_info.dll", "w+");
   // if (fptr == NULL)
   // {
    //    printf("File does not exists \n");
    //    return;
    //}
    printf("\n\n\n\t\t\t **************** Enter your information **************** \n");

        fflush(stdin);
        printf("\t\t\t..::Enter Your First Name:\n\t\t\t");
        gets(l.first_name);
        fprintf(fptr, "first_name= %s\n", l.first_name);

        fflush(stdin);
        printf("\t\t\t..::Enter Your last_name:\n\t\t\t");
        gets(l.last_name);
        fprintf(fptr, "last_name= %s\n", l.last_name);

        fflush(stdin);
        printf("\t\t\t..::Enter Your username:\n\t\t\t");
        gets(l.username);
        fprintf(fptr, "username= %s\n", l.username);

        fflush(stdin);
        printf("\t\t\t..::Enter Your password:\n\t\t\t");

        gets(l.password);
        fprintf(fptr, "password= %s\n", l.password);
    fwrite(&l,sizeof(l),1,log);
   fclose(log);
    printf("\n\n Congratulation! Registration Successful : ");
    printf("\n\n Now login with your username and password : ");
    printf("\n\n press any key to continue....... ");
    getch();
    system("CLS");
    login();
}

 /************************registe End ********/


  /************************Login Start ********/
int login(){
    char username[20],password[20];
    FILE *log;
    log =fopen("login_info.dll","r");
    struct login l;

    printf("\n\n\n\t\t\t ****************Enter your Username & Password*************");
    fflush(stdin);
    printf("\n\n\t\t\tUsername:");
    gets(username);
    fflush(stdin);
    printf("\n\n\t\t\tPassword:");
    gets(password);

     while(fread(&l,sizeof(l),1,log)){
        if (strcmp(username,l.username)==0 && strcmp (password,l.password)==0)
        {
             printf("\n\n\n\t\t\t\t **************** Successful Login ****************\n");
             printf("\t\t\t\t\t****** *** ***** ***** ***** **** ****** \n\n");
             printf("\t\t\t\t****** **** Enter What you Want **** ****** \n\n");
             printf("\t\t\t1. USER Dashboard\n");
             int ch;
             printf("\n\t\t\tEnter Your Choice: ");
             scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                    USER_Dashboard();
                    break;

                default:
                    printf("\t\t\tWrong Input\n");
                }


                }

                else{
                  printf("\t\t\tPlease Enter Correct UserID And Password\n");
                   break;
                }
     }
     fclose(log);

}



/************************************************************Admin Login *****************************************************/

int A_registe (){

    FILE *log;
   log=fopen("A_login_info.dll","w");
    struct Alogin li;
    FILE *fptr;
    fptr = fopen("A_login_info.dll", "w+");
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("\n\n\n\t\t\t **************** Enter your information **************** \n");

        fflush(stdin);
        printf("\t\t\t..::Enter Your First Name: \n\t\t\t");
        gets(li.Afirst_name);
        fprintf(fptr, "First Name= %s\n", li.Afirst_name);

        fflush(stdin);
        printf("\t\t\t..::Enter Your last_name: \n\t\t\t");
        gets(li.Alast_name);
        fprintf(fptr, "last_name= %s\n", li.Alast_name);
        fflush(stdin);
        printf("\t\t\t..::Enter Your username: \n\t\t\t");
        gets(li.Ausername);
        fprintf(fptr, "UserName:%s\n", li.Ausername);

        fflush(stdin);
        printf("\t\t\t..::Enter Your password: \n\t\t\t");
        gets(li.Apassword);
        fprintf(fptr, "PassWord:%s\n", li.Apassword);


       /* fflush(stdin);
        printf("\t\t\t..::Enter Your Email: \n\t\t\t");
        gets(li.Email);
        fprintf(fptr, "Email= %s\n", li.Email);
        fflush(stdin);
        printf("\t\t\t..::Enter Your Admin Id: \n\t\t\t");
        gets(li.admin_id);
        fprintf(fptr, "ADmin Id= %s\n", li.admin_id);*/
       fwrite(&li,sizeof(li),1,log);
       fclose(log);



    printf("\n\n Congratulations! You have successfully completed the registration.\n");
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\n ****Please Note:An e-mail has been sent to your e-mail. Please verify your e-mail.*****");
    printf("\nWe will check all your data and if all the information is correct then we will \nsend you another mail and there you will be \ngiven a four digit code." );
    printf("\nYou will need a four-digit secret number to login as an admin." );
    printf("\nRemember, you will not be able to login to the \nadmin panel without a 4-digit secret number. ");
    printf("\nThe secret number of these four numbers is \nexclusively yours so refrain from sharing it with anyone else. Thanks ");
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\n Now login with your username and password  ");
    printf("\n\n press any key to continue....... ");
    getch();
    system("CLS");
    A_login();
}

  /************************registe end********/


  /************************login ********/
int A_login(){
    char Ausername [20],Apassword[20];
    FILE *log;
    log =fopen("A_login_info.dll","r");
    struct Alogin li;
    printf("\n\n\n\t\t\t ****************Enter your Username & Password*************");
    fflush(stdin);
    printf("\n\n\t\t\tUsername:");
    gets(Ausername);
    fflush(stdin);
    printf("\n\n\t\t\tPassword:");
    gets(Apassword);
     while(fread(&li,sizeof(li),1,log)){
        if (strcmp(Ausername,li.Ausername)==0 && strcmp (Apassword,li.Apassword)==0)
        {
             /*int pin;

             printf("\t\t\tEnter Secret pin:");
             scanf("%d",&pin);
             if (pin==7580|| pin==1451 || pin==7418||pin==7651||pin==7481||pin==7849||pin==3668||pin==3175||pin==5123||pin==4187)
                {*/
             printf("\n\n\n\t\t\t\t **************** Login Successful ****************\n");
             printf("\t\t\t\t\t****** *** ***** ***** ***** **** ****** \n\n");
             printf("\t\t\t\t****** **** Enter What you Want **** ****** \n\n");
             printf("\t\t\t1. USER Dashboard\n");
             printf("\t\t\t2. ADMIN Dashboard\n");
             int ch;
             printf("\n\t\t\tEnter Your Choice: ");
             scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                    USER_Dashboard();
                    break;
                case 2:
                    ADMIN_Dashboard();
                    break;

                default:
                    printf("\t\t\tWrong Input\n");

                }

                //}
               // else
                    //printf("Sorry! Yor Are not an Admin ");

                }

                else{
                  printf("\t\t\tPlease Enter Correct UserID And Password\n");
                   break;
                }
     }
     fclose(log);

}

 /************************login end ********/

/*////////////////////////////////////////////////////////////////////////login System Function End//////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////Read Online //////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////Read Online End/////////////////////////////////////////////////////*/





/*///////////////////////////////////////////////////////////////////////////// User Section Start //////////////////////////////////////////////////////*/
int user_reg_sys()
{
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\t\t\t\t\t\t  **** 1.Registration **** ");
    printf("\n\t\t\t\t\t\t  **** 2.Login **** " );
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\t\t\t Please Enter What you want :" );

    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        registe();
        break;
    case 2:
        login();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }
}



int USER_Dashboard()
{
    printf("\n\t\t\t User PANEL OF THE PROJECT: \n");
    printf("\t\t\t1. Book List  \n");
    printf("\t\t\t2. Search Book\n");
    printf("\t\t\t3. Book Purchase  \n");
    printf("\t\t\t4. My Account\n");
    printf("\t\t\t5. Complain \n");
    printf("\t\t\t6. Contact Us \n");
    printf("\t\t\t7. Online Read \n");
    printf("\t\t\t8. Log Out \n");
    printf("\n\t\t\tEnter What You Want: ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          show_books();


        break;
    case 2:
          search_book_u();
        break;
    case 3:
          Book_Purchase();
        break;
    case 4:
        My_Account();
        break;
    case 5:
        Complain();
        break;
    case 6:
        Contact_Us();
        break;
    case 7 :
        online_read() ;
        break;
    case 8 :
        log_out() ;
        break;


    default:
        printf("Wrong Input\n");

    }


}



int show_books()
{
    printf("\t\t\t1. Lattess book \n");
    printf("\t\t\t2. Book List \n");
    printf("\n\t\t\tEnter What You Want: ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          show_book_u_latess();

        break;
    case 2:
        show_book_u();
        break;
    }

}



int  Book_Purchase()
{
  printf("\n\t\t\t Select  Catagory: \n");
    printf("\t\t\t1. CSE  \n");
    printf("\t\t\t2. EEE \n");
    printf("\t\t\t3. English  \n");
    printf("\t\t\t4. History\n");
    printf("\t\t\t5. Architecture \n");
    printf("\t\t\t6. Civil  \n");
    printf("\t\t\t7. Economic  \n");
    printf("\n\t\t\tEnter What You Want: ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          CSE();

        break;
    case 2:
          EEE();
        break;
    case 3:
          English();
        break;
    case 4:
        History();
        break;
    case 5:
        Architecture();
        break;
    case 6:
        Civil();
        break;
    case 7 :
        Economic() ;
        break;


    default:
        printf("Wrong Input\n");

    }
}
int CSE()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price || \n");
   printf("\t\t\t  *********    || ******  || ********|| ***** || \n");
   printf("\t\t\t  1.CSE-101    ||   A     ||  101    ||  547  || \n");
   printf("\t\t\t  2.CSE-102    ||   B     ||  102    ||  478  || \n");
   printf("\t\t\t  3.CSE-103    ||   C     ||  103    ||  784  || \n");
   printf("\t\t\t  4.CSE-104    ||   D     ||  104    ||  319  || \n");
   printf("\n\t\t\t Enter which Book you want :   ");

   int ch;
   int id,quantity,taka;
            char b_name[30];


            float total_price;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        printf("Enter Id:");
            scanf("%d",&id);
if (id==101)
            {
                taka=547;
                printf("Book Name:CSE-101\n");
                printf("\nId:%d",id);
                printf("\nPrice:%d",taka);
                printf("\nEnter Quantity:");
                scanf("%d",&quantity);
                total_price=taka*quantity;
                printf("\nTotal Price:%.2f",total_price);
                printf("\nBook Name:CSE-101 || Book Id:%d ||Price:%d ||Quantity:%d || Total Price:%f",id,taka,quantity,total_price);
            }

        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }


}
int EEE()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price ||\n");
   printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t  1.EEE-101    ||   A     ||  101    ||  600  ||\n");
   printf("\t\t\t  2.EEE-102    ||   B     ||  102    ||  350  ||\n");
   printf("\t\t\t  3.EEE-103    ||   C     ||  103    ||  840  ||\n");
   printf("\t\t\t  4.EEE-104    ||   D     ||  104    ||  547  ||\n");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int English()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price ||\n");
   printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t  1.Eng-101    ||   A     ||  101    ||  400  ||\n");
   printf("\t\t\t  2.Eng-102    ||   B     ||  102    ||  770  ||\n");
   printf("\t\t\t  3.Eng-103    ||   C     ||  103    ||  256  ||\n");
   printf("\t\t\t  4.Eng-104    ||   D     ||  104    ||  630  ||\n");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int History()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price ||\n");
   printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t  1.His-101    ||   A     ||  101    ||  540  ||\n");
   printf("\t\t\t  2.His-102    ||   B     ||  102    ||  390  ||\n");
   printf("\t\t\t  3.His-103    ||   C     ||  103    ||  875  ||\n");
   printf("\t\t\t  4.His-104    ||   D     ||  104    ||  684  ||\n");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Architecture()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price ||\n");
   printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t  1.ARC-101    ||   A     ||  101    ||  755  ||\n");
   printf("\t\t\t  2.ARC-102    ||   B     ||  102    ||  900  ||\n");
   printf("\t\t\t  3.ARC-103    ||   C     ||  103    ||  645  ||\n");
   printf("\t\t\t  4.ARC-104    ||   D     ||  104    ||  812  ||\n");
   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}


int Civil()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price ||\n");
   printf("\t\t\t  *********    || ******  || ********|| ***** ||\n\n");
   printf("\t\t\t  1.CVl-101    ||   A     ||  101    ||  555  ||\n");
   printf("\t\t\t  2.CVl-102    ||   B     ||  102    ||  768  ||\n");
   printf("\t\t\t  3.CVl-103    ||   C     ||  103    ||  281  ||\n");
   printf("\t\t\t  4.CVl-104    ||   D     ||  104    ||  596  ||\n");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}



int Economic()
{
   printf("\t\t\t  BOOK Name    || Author  || Book Id || Price || \n");
   printf("\t\t\t  *********    || ******  || ********|| ******|| \n\n");
   printf("\t\t\t  1.ECO-101    ||   A     ||  101    ||   500 || \n");
   printf("\t\t\t  2.ECO-102    ||   B     ||  102    ||   400 ||  \n");
   printf("\t\t\t  3.ECO-103    ||   C     ||  103    ||   250 || \n");
   printf("\t\t\t  4.ECO-104    ||   D     ||  104    ||   140 || \n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        payment();
        break;
    case 2:
        payment();
        break;
    case 3:
        payment();
        break;
    case 4:
        payment();
        break;
    default:
        printf("Wrong Input\n");

    }
}
/*.........................................................          payment   Start     ............................................................*/

int payment()
{

   printf("\n\t\t\t Select Your Payment System:  \n ");
   printf("\n\t\t\t  1.Mobile Banking\n");
   printf("\n\t\t\t  2.Bank Account\n");
   printf("\n\t\t\t  3.CARD\n");
   printf("\n\t\t\t  4.Paypal\n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Mobile_banking();
        break;
    case 2:
        Bank_Account();
        break;
    case 3:
        Card();
        break;
    case 4:
       Paypal();
       break;
    default:
        printf("Wrong Input\n");

    }
}

int Mobile_banking()
{

   printf("\n\t\t\t Select Your Payment System:  \n ");
   printf("\n\t\t\t  1.Bkash\n");
   printf("\n\t\t\t  2.Roket\n");
   printf("\n\t\t\t  3.Nagad\n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        bkash();
        break;
    case 2:
        roket();
        break;
    case 3:
        nagad();
        break;

    default:
        printf("Wrong Input\n");

    }



}

int Bank_Account()
{
    printf("\n\t\t\t Select Your Payment System:  \n ");
   printf("\n\t\t\t  1.Bank Asia\n");
   printf("\n\t\t\t  2.Islami Bank\n");
   printf("\n\t\t\t  3.Duch Bangla Bank\n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Bank_Asia();
        break;
    case 2:
        islami_bank();
        break;
    case 3:
        Duch_Bangla_Bank();
        break;

    default:
        printf("Wrong Input\n");


    }
}

int Card ()
{
   printf("\n\t\t\t Select Your Payment System:  \n ");
   printf("\n\t\t\t  1.Mastercard\n");
   printf("\n\t\t\t  2.Visa Card\n");
   printf("\n\t\t\t Enter Here:   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Mastercard();
        break;
    case 2:
        visa();
        break;
    default:
        printf("Wrong Input\n");

    }
}



int bkash ()

{
   fflush(stdin);

            printf("Enter Your Bkash Number :");

            scanf("%ld",&pay.ph);

            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            fflush(stdin);

            printf("Enter Your Bkash PassWord :");

            scanf("%[^\n]",&pay.pass);

            printf("\n\t\t\t All Information is Correct \n");


            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }


}

int roket ()
{
    fflush(stdin);

            printf("Enter Your Roket Number :");

            scanf("%ld",&pay.ph);

            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            fflush(stdin);

            printf("Enter Your Roket PassWord :");

            scanf("%[^\n]",&pay.pass);

            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }

}

int nagad ()

{
    fflush(stdin);

            printf("Enter Your Nagad Number :");

            scanf("%ld",&pay.ph);

            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            fflush(stdin);

            printf("Enter Your Nagad PassWord :");

            scanf("%[^\n]",&pay.pass);

            printf("\n\t\t\t All Information is Correct \n");


            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }
}


int Bank_Asia ()
{
            fflush(stdin);

            printf("Enter Your Account Number :");

            scanf("%ld",&pay.ph);
            fflush(stdin);

            printf("Enter Account Holder Name:");

            scanf("%[^\n]",&pay.AN);


            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }



}

int islami_bank()
{
            fflush(stdin);

            printf("Enter Your Account Number :");

            scanf("%ld",&pay.ph);
            fflush(stdin);

            printf("Enter Account Holder Name:");

            scanf("%[^\n]",&pay.AN);


            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }



}

int Duch_Bangla_Bank()
{
            fflush(stdin);

            printf("Enter Your Account Number :");

            scanf("%ld",&pay.ph);
            fflush(stdin);

            printf("Enter Account Holder Name:");

            scanf("%[^\n]",&pay.AN);


            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }




}

int Mastercard()
{
        fflush(stdin);

            printf("Enter Your CARD Number :");

            scanf("%ld",&pay.ph);
            fflush(stdin);

            printf("Enter Your CARD CVC Number :");

            scanf("%ld",&pay.cvc);

            fflush(stdin);

            printf("Enter Your CARD Valid Time :");

            scanf("%ld",&pay.valid);




            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }

}

int visa ()
{
         fflush(stdin);

            printf("Enter Your CARD Number :");

            scanf("%ld",&pay.ph);
            fflush(stdin);

            printf("Enter Your CARD CVC Number :");

            scanf("%ld",&pay.cvc);

            fflush(stdin);

            printf("Enter Your CARD Valid Time :");

            scanf("%ld",&pay.valid);




            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);


            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
            Conform();
             break;

    default:
        printf("Wrong Input\n");

    }

}

int Paypal()
{
            printf("You need to login your paypal Account:\n");

            fflush(stdin);

            printf("Enter Your Email:");

            scanf("%[^\n]",&pay.email);

            fflush(stdin);

            printf("Enter Password:");

            scanf("%[^\n]",&pay.pass);


            fflush(stdin);

            printf("Enter Book price:");

            scanf("%[^\n]",&pay.price);



            fflush(stdin);


            printf("Enter your shipping Address:");

            gets(pay.add);
            printf("\t\t\t  1.CSE-101    ||   A     ||  101    ||  547  || \n");


            int id,quantity;
            char b_name[30];
            printf("Enter Id:");
            scanf("%d",&id);
            int taka=547;
            float total_price;

            if (id==101)
            {
                printf("Book Name:CSE-101\n");
                printf("\nId:%d",id);
                printf("\nPrice:%d",taka);
                printf("\nEnter Quantity:");
                scanf("%d",&quantity);
                total_price=taka*quantity;
                printf("\nTotal Price:%.2f",total_price);
                printf("\nBook Name:CSE-101 || Book Id:%d ||Price:%d ||Quantity:%d || Total Price:%f",id,taka,quantity,total_price);
            }

            printf("\n\t\t\t All Information is Correct \n");

            printf("\t\t\tIf all information is ok than select (1) for Conform\n");
            printf("\n\t\t\t Enter (1) Here:   ");

            int ch;
           scanf("%d", &ch);
          switch(ch)
            {
              case 1:
             printf("\nBook Name:CSE-101 || Book Id:%d ||Price:%d ||Quantity:%d || Total Price:%f",id,taka,quantity,total_price);
             printf("Thank You! Oder Conform . ");
             break;

    default:
        printf("Wrong Input\n");

    }

    printf("\n\t\t\Back To Main menu Enter (0):-->");
       //int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}

int Conform()
{
    printf("Thank You! Oder Conform . ");
    printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

    //printf("\n your product details :\t\t  \nBook Name:CSE-101 \n Author Name:A \n Book Code:101\n Book Price :547 \n");
}
/*.........................................................          payment End        ............................................................*/

int Contact_Us()

{
 printf("\n\t\t\t//////////////// ..::Our Phone Number : 0123456789 /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our Email : admin@lms.com  /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our fax : fax id .com  /////////////////// \n");
 printf("\n\t\t\t//////////////// ..::Our address : Mirpur-2 || Dhaka || 1200  /////////////////// \n");
 printf("\t\t\Back To Main menu Enter (0):-->");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Complain()
{

   printf("\n\t\t\ 1.Type Complain :");
   printf("\n\t\t\ 2.View Reply :");
   printf("\n\t\t\ 3.Main Menu :");
   printf("\n\t\t\ Enter what you want :");
   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        submit();
        break;
    case 2 :
        view_reply();
        break;
    case 3:
        USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

}



int submit()
{
    char CMessage[500];
    FILE *fptr;
    fptr = fopen("Complain.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    /* printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
    scanf("%s", CMessage);
    fprintf(fptr, "Complain= %s\n", CMessage);*/

    fflush(stdin);

        printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
        gets(li.mes);
        fprintf(fptr, "Complain= %s\n", li.mes);

    fclose(fptr);


        printf("\n\t\t\t..::1.Conform ");
       // printf("\n\t\t\t..::2.Log Out ");
        printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        sent();
        break;

    default:
        printf("Wrong Input\n");

    }
    printf("\t\t\Back To Main menu Enter (0):-->");
       //int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int view_reply ()
{
  FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("reply.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}




int sent()
{
    printf("\t\t\t\t Message Submit Successful...");
    printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

}



/* ***********************************************************online Read ***************************************************************/

int CSE_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/1.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int CSE_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/2.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int CSE_book3()//3
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   //fp = fopen("file/3.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}







int CSE_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/4.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}



/** EEE ****/




int EEE_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/5.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int EEE_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/6.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int EEE_book3() //3
 {
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/7.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

 }





int EEE_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/8.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}

/*** EEE End**** */



/** ENglish ****/


int Eng_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/9.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int Eng_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/10.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int Eng_book3(){//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/11.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int Eng_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/12.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}



/********** English end   *********/


/*************** History ************/


int his_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/13.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int his_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/14.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int his_book3(){ //3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/15.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int his_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/16.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}


/****************** History End ****************/

/********** Arc********/

int arc_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/17.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int arc_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/18.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int arc_book3(){//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/19.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int arc_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/20.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}


/************** Arc end ************/


int civ_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/21.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int civ_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/22.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int civ_book3(){ //3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/23.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int civ_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/24.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}
/****** civ end ********/

/************* ECO **************/

int eco_book1() //1
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/25.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int eco_book2() //2
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/26.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}




int eco_book3() {//3
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/27.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }
}





int eco_book4() //4
{
     FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("file/28.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);
   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard();
        break;
    default:
        printf("Wrong Input\n");

    }

}

/************* ECO End **************/


int online_read()
{

   printf("\t\t\t  BOOK Name     || Author  || Book Id  \n");
   printf("\t\t\t  *********     || ******  || *****\n");
   printf("\t\t\t  1.CSE-101     ||   A     ||  101\n");
   printf("\t\t\t  2.CSE-102     ||   B     ||  102\n");
   printf("\t\t\t  3.CSE-103     ||   C     ||  103\n");
   printf("\t\t\t  4.CSE-104     ||   D     ||  104\n");
   printf("\t\t\t  5.EEE-101     ||   A     ||  101\n");
   printf("\t\t\t  6.EEE-102     ||   B     ||  102\n");
   printf("\t\t\t  7.EEE-103     ||   C     ||  103\n");
   printf("\t\t\t  8.EEE-104     ||   D     ||  104\n");
   printf("\t\t\t  9.Eng-101     ||   A     ||  101\n");
   printf("\t\t\t  10.Eng-102    ||   B     || 102\n");
   printf("\t\t\t  11.Eng-103    ||   C     || 103\n");
   printf("\t\t\t  12.Eng-104    ||   D     || 104\n");
   printf("\t\t\t  13.His-101    ||   A     || 101\n");
   printf("\t\t\t  14.His-102    ||   B     || 102\n");
   printf("\t\t\t  15.His-103    ||   C     || 103\n");
   printf("\t\t\t  16.His-104    ||   D     || 104\n");
   printf("\t\t\t  17.ARC-101    ||   A     || 101\n");
   printf("\t\t\t  18.ARC-102    ||   B     || 102\n");
   printf("\t\t\t  19.ARC-103    ||   C     || 103\n");
   printf("\t\t\t  20.ARC-104    ||   D     || 104\n");
   printf("\t\t\t  21.CVl-101    ||   A     || 101\n");
   printf("\t\t\t  22.CVl-102    ||   B     || 102\n");
   printf("\t\t\t  23.CVl-103    ||   C     || 103\n");
   printf("\t\t\t  24.CVl-104    ||   D     || 104\n");
   printf("\t\t\t  25.ECO-101    ||   A     || 101\n");
   printf("\t\t\t  26.ECO-102    ||   B     || 102\n");
   printf("\t\t\t  27.ECO-103    ||   C     || 103\n");
   printf("\t\t\t  28.ECO-104    ||   D     || 104\n");

   printf("\n\t\t\t Enter which Book you want to online read :   ");

   int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        CSE_book1();
        break;
    case 2:
        CSE_book2();
        break;
    case 3:
        CSE_book3();
        break;
    case 4:
        CSE_book4();
        break;
    case 5:
        EEE_book1();
        break;
    case 6:
        EEE_book2();
        break;
    case 7:
        EEE_book3();
        break;
    case 8:
        EEE_book4();
        break;
    case 9:
        Eng_book1();
        break;
    case 10:
        Eng_book2();
        break;
    case 11:
        Eng_book3();
        break;
    case 12:
        Eng_book4();
        break;
    case 13:
        his_book1();
        break;
    case 14:
        his_book2();
        break;
    case 15:
        his_book3();
        break;
    case 16:
        his_book4();
        break;

    case 17:
        arc_book1();
        break;
    case 18:
        arc_book2();
        break;
    case 19:
        arc_book3();
        break;
    case 20:
        arc_book4();
        break;


    case 21:
        civ_book1();
        break;
    case 22:
        civ_book2();
        break;
    case 23:
        civ_book3();
        break;
    case 24:
        civ_book4();
        break;
    case 25:
        eco_book1();
        break;
    case 26:
        eco_book2();
        break;
    case 27:
        eco_book3();
        break;
    case 28:
        eco_book4();
        break;

    default:
        printf("Wrong Input\n");

    }



}




int show_book_u()
{
    printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("bookinfo.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
         USER_Dashboard ();
        break;
    default:
        printf("Wrong Input\n");

    }
}


int show_book_u_latess()
{
    printf("\t\t\t  BOOK Name     || Author  || Book Id  \n");
   printf("\t\t\t  *********     || ******  || *****\n");
   printf("\t\t\t  1.CSE-101     ||   A     ||  101\n");
   printf("\t\t\t  2.CSE-102     ||   B     ||  102\n");
   printf("\t\t\t  3.CSE-103     ||   C     ||  103\n");
   printf("\t\t\t  4.CSE-104     ||   D     ||  104\n");
   printf("\t\t\t  5.EEE-101     ||   A     ||  101\n");
   printf("\t\t\t  6.EEE-102     ||   B     ||  102\n");
   printf("\t\t\t  7.EEE-103     ||   C     ||  103\n");
   printf("\t\t\t  8.EEE-104     ||   D     ||  104\n");
   printf("\t\t\t  9.Eng-101     ||   A     ||  101\n");
   printf("\t\t\t  10.Eng-102    ||   B     || 102\n");
   printf("\t\t\t  11.Eng-103    ||   C     || 103\n");
   printf("\t\t\t  12.Eng-104    ||   D     || 104\n");
   printf("\t\t\t  13.His-101    ||   A     || 101\n");
   printf("\t\t\t  14.His-102    ||   B     || 102\n");
   printf("\t\t\t  15.His-103    ||   C     || 103\n");
   printf("\t\t\t  16.His-104    ||   D     || 104\n");
   printf("\t\t\t  17.ARC-101    ||   A     || 101\n");
   printf("\t\t\t  18.ARC-102    ||   B     || 102\n");
   printf("\t\t\t  19.ARC-103    ||   C     || 103\n");
   printf("\t\t\t  20.ARC-104    ||   D     || 104\n");
   printf("\t\t\t  21.CVl-101    ||   A     || 101\n");
   printf("\t\t\t  22.CVl-102    ||   B     || 102\n");
   printf("\t\t\t  23.CVl-103    ||   C     || 103\n");
   printf("\t\t\t  24.CVl-104    ||   D     || 104\n");
   printf("\t\t\t  25.ECO-101    ||   A     || 101\n");
   printf("\t\t\t  26.ECO-102    ||   B     || 102\n");
   printf("\t\t\t  27.ECO-103    ||   C     || 103\n");
   printf("\t\t\t  28.ECO-104    ||   D     || 104\n");


   printf("\t\t\Back To Main menu Enter  (0) or online read Enter(5) :-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
         USER_Dashboard ();
        break;
        case 5:
         online_read();
        break;
    default:
        printf("Wrong Input\n");

    }

}

int search_book_u()
{
  do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("bookinfo.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            //printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard ();
        break;
    default:
        printf("Wrong Input\n");

    }
}





/*#############################################################online Read End$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

/*///////////////////////////////////////////////////////////////////////////// User Section End //////////////////////////////////////////////////////*/


/*///////////////////////////////////////////////////////////////////////////// Admin Section Start //////////////////////////////////////////////////////*/

int Admin_main_menu()
{
      printf("\n\t\t\t1.Admin Dashboard \n\t\t\t2.User DashBoard\n\t\t\t3.Log Out ");
      printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        ADMIN_Dashboard();
        break;
    case 2 :
        USER_Dashboard();
        break;
    case 3 :
        log_out();
        break;
    default:
        printf("Wrong Input\n");
    }

}

int ADMIN_Dashboard()
{

    printf("\n\t\t\t *** ADMIN PANEL OF THE PROJECT *** \n");
    printf("\t\t\t1.Update Book Info  \n");
    printf("\t\t\t2.Search Book\n");
    printf("\t\t\t3.My Account\n");
    printf("\t\t\t4.User Feedback \n");
    printf("\t\t\t5.Log Out \n");


    printf("\n\t\t\tEnter your Choice: ");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          Update_Book  ();
        break;
    case 2:
          Search_Book ();
        break;
    case 3:
          My_Account ();
        break;
    case 4:
        user_feedback();
        break;
    case 5:
        log_out();
        break;

    default:
        printf("Wrong Input\n");

    }




}

int Update_Book()
{
    printf("\t\t\t \n");
    printf("\n\t\t\t1. Add New Book ");
    printf("\n\t\t\t2. Show Book List ");
    printf("\n\t\t\t3. Update Book Info ");
    printf("\n\t\t\t4. Delete Old Info");
    printf("\n\t\t\t5. Log Out");

    int ch;
    printf("\n\n\t\t\t Enter your Choice:");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Add_Book_info();
        break;
    case 2:
        show_Book_list();

        break;
    case 3:
        update_book();
        break;
    case 4:
        delete_info();
        break;
    case 5:
        log_out();
        break;

    default:
        printf("\t\t\tWrong Input\n");

    }

}

int Search_Book()
{
    do

        {

            found=0;

            printf("\n\n\t..::Book SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("bookinfo.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Id\t: %ld\n..::Author\t: %s\n..::Subject\t: %s\n",list.name,list.id,list.author,list.subject);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            //printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}

int My_Account()
{

     printf("\t\t1.Add Your Information");
     printf("\n\t\t2.View Your Information");
     printf("\n\t\t Enter What You want:");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          update_account  ();
        break;
    case 2:
          view_account ();
        break;
    default:
        printf("Wrong Input\n");

    }

}



int update_account()

{
    char name[300];
    FILE *fptr;
    int id;

    float intake, section;
    fptr = fopen("myaccount.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("\t\t\tEnter Student id:");
    scanf("%d", &id);
    fprintf(fptr, "Student Id= %d\n", id);
    printf("\t\t\tEnter Your Name:");
    scanf("%s", name);
    fprintf(fptr, "Name= %s\n", name);
    printf("\t\t\tEnter the Intake:");
    scanf("%f", &intake);
    fprintf(fptr, "Intake= %.2f\n", intake);
    fclose(fptr);


    printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}
int view_account()
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("myaccount.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          USER_Dashboard  ();
        break;
    default:
        printf("Wrong Input\n");

    }

}





int log_out ()
{
    printf("\n\n\t\t\t*************Log Out Successful**************** \n");

}


int Add_Book_info()

{
    //system("cls");

        fp=fopen("bookinfo.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input...:");
            printf("\nEnter Book Name:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Enter Book Id:");

            scanf("%ld",&list.id);

            fflush(stdin);

            printf("Enter Book Author Name:");

            scanf("%[^\n]",&list.author);

            fflush(stdin);

            printf("Enter Book Categories:");

            gets(list.subject);

            //fflush(stdin);

            //printf("Enter Intake or Class:");

            //scanf("%d",&list.intake);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }


}

int show_Book_list()
{
    //system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF Books\n\t\t=============================================\n\nName\t\tId No\tAuthor\t\tSubject=====================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("bookinfo.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nId\t: %ld\nAuthor\t: %s\nSubject\t: %s\n ",list.name,

                           list.id,list.author,list.subject);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }
}
int update_book()
{
    //system("cls");

        fp=fopen("bookinfo.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Update Book info\n===============================\n\n\t..::Enter the name of Book to Update info:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Updating '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::id:");

        scanf("%ld",&list.id);

        fflush(stdin);

        printf("..::Author:");

        scanf("%[^\n]",&list.author);

        fflush(stdin);

        printf("..::Categories:");

        gets(list.subject);

        //fflush(stdin);

        //printf("Enter Intake or Class:");

        //scanf("%d",&list.intake);


        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("bookinfo.dll");

        rename("temp.dat","bookinfo.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }


}

int delete_info()
{
    //system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of Book to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("bookinfo.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("bookinfo.dll");

        rename("temp.dat","bookinfo.dll");

        printf("\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu  ();
        break;
    default:
        printf("Wrong Input\n");

    }



}

int user_feedback()
{

  printf("\t\t1.View Complain");
  printf("\n\t\t2.Reply");
  printf("\n\t\t\What You Want :>");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
          view_complain ();
        break;
    case 2 :
        reply_complain();
        break;

    default:
        printf("Wrong Input\n");

    }
}

int view_complain()
{
    FILE *fp;
   char buff[255];//creating char array to store data of file
   fp = fopen("Complain.txt", "r");
   while(fscanf(fp, "%s", buff)!=EOF){
   printf("%s ", buff);
   }
   fclose(fp);

   printf("\n\t\t\Back To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu ();
        break;
    default:
        printf("Wrong Input\n");

    }

}

int reply_complain()
{


     char rMessage[500];
    FILE *fptr;
    fptr = fopen("reply.txt", "w+");/*  open for writing */
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    /* printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
    scanf("%s", CMessage);
    fprintf(fptr, "Complain= %s\n", CMessage);*/

    fflush(stdin);

        printf("\t\t\t..::Enter Your Message Here: \n\t\t\t");
        gets(lr.rmes);
        fprintf(fptr, "Reply= %s\n", lr.rmes);

    fclose(fptr);


        printf("\n\t\t\t..::1.Conform ");
       // printf("\n\t\t\t..::2.Log Out ");
        printf("\n\t\t\tEnter what you want : ");

    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        sent_reply();
        break;

    default:
        printf("Wrong Input\n");

    }


}

int sent_reply()
{

    printf("\n\t\t Reply Sent to User");
    printf("\n\t\tBack To Main menu Enter (0):-->");
       int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
          Admin_main_menu ();
        break;
    default:
        printf("Wrong Input\n");

    }
}

int Admin_reg_sys()
{
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\t\t\t\t\t\t  **** 1.Registration **** ");
    printf("\n\t\t\t\t\t\t  **** 2.Login **** " );
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\t\t\t Please Enter What you want :" );

    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        A_registe();
        break;
    case 2:
        A_login();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }
}

/*///////////////////////////////////////////////////////////////////////////// Admin Section End //////////////////////////////////////////////////////*/



/*///////////////////////////////////////////////////////////////////////////// Main Function Start//////////////////////////////////////////////////////*/

int main ()


{

    printf("\n\n");
    printf("\t\t\t******************* PROJECT NAME : Library Management System *********************\n");
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n\n\n\n\n\n");

    //int cho;
    printf("\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\t\t\t\t\t\t  **** 1.Became a User **** ");
    printf("\n\t\t\t\t\t\t  **** 2.Became an Admin **** " );
    printf("\n\t\t\t\t\t   ****** *** ***** ***** ****** **** ******* \n");
    printf("\n\t\t\t Please Enter What you want :" );

    int ch;

    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        user_reg_sys();
        break;
    case 2:
        Admin_reg_sys();
        break;

    default:
        printf("\t\t\tWrong Input\n");
    }


    return 0;

}

/*///////////////////////////////////////////////////////////////////////////// Main Function End //////////////////////////////////////////////////////*/


