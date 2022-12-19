# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct user {

char name [50];
char last_name[50];
char branch [50];
int acc_number;
int age;
int pin;
int balance;

};

int account_number;
int pin;

// Ascii color functions decleare


void red();
void yellow();
void green();
void cyan();
void color_reset ();

// system functions
void create_account ();
void login();
void update_account (); 
void delete_account (); 
void deposite (); 
void withdraw();
void view_account();//
void view_balance();//
void menu();

// ASCII color coding functions
void red () {

 printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

void green () {
    printf("\033[0;32m");
}

void cyan () {
    printf ("\033[0;36m");
}

void color_reset () {
      printf("\033[0m");
}


int main () {
    yellow();
    printf ("\n\t Press any key to start Bank management system ............!");
    getch();
    system("cls");


    yellow();
    printf ("\n\t  _________________________________________________");
    printf ("\n\t |=================================================|");
    printf ("\n\t |                    GROUP - 16                   |");

    cyan();
    printf ("\n\t |--------       Bank management System     -------|");
    printf ("\n\t |         Do you have an account in our bank      |");
    green();
    printf ("\n\t |              If you have please log in          |");
    red();
    printf ("\n\t |       If you haven't please create an account   |");
    green();
    printf ("\n\t | # to log in press         --------------- 1     |");
    red();
    printf ("\n\t | # to create account press --------------- 2     |");
    yellow();
    printf ("\n\t |=================================================|");
    printf ("\n\t |_________________________________________________|\n");
    color_reset();

    int re_enter;
    int select;
    re_enter :
    cyan();
    printf ("\n\t Choose a selection : ");
    scanf ("%d",&select);

    switch (select){
        case 1 :
         login();
         break;

        case 2 :
         create_account();
         break;

        default :
         printf("\n\t Invalid selection\n");
         goto re_enter;
    }
}

void create_account () {

system ("cls");
FILE *file;
struct user data;
file = fopen("records.txt","a");
int re_enter;
int pin;

yellow();
printf ("\n\t create your account now......!\n");
cyan();
printf ("\n\t Enter your name : ");
scanf ("%s",data.name);
printf ("\n\t Enter your last name : ");
scanf ("%s",data.last_name);
printf ("\n\t Enter your Branch name : ");
scanf ("%s",data.branch);
printf("\n\t Enter your age : ");
scanf ("%d",&data.age);
printf ("\n\t Enter your account number : ");
scanf ("%d",&data.acc_number);
printf("\n\t Enter amount to deposite : ");
scanf("%d",&data.balance);

re_enter:
printf ("\n\t Enter your pin number : ");
scanf ("%d",&data.pin);
printf ("\n\t Re-enter your pin number : ");
scanf ("%d",&pin);

if (pin == data.pin){
    green();
    printf ("\n\t Account created successfully.....!");
    fprintf (file,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
    fclose(file);

    system("cls");
    login();
}
else {
    red();
    printf ("\n\t pin number different please enter it again ......!");
    goto re_enter;
}
}

void login () {

FILE *file;
struct user data;
int pin_times = 1;
int pin_check = 1;
int re_pin = 0;
file = fopen("records.txt","r");



printf ("\n\t Enter your account number : ");
scanf ("%d",&account_number);

printf ("\n\t Enter your pin number : ");
scanf ("%d",&pin);


while(fscanf(file,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (account_number == data.acc_number){
        re_pin:
        if (pin == data.pin){

            green();
            printf("\n\t WELCOME .....! Mr./Mrs.");
            yellow();
            printf ("%s %s\n",data.name,data.last_name);
            green();
            printf ("\n\t You Logged suceessfully.........!\n");
            color_reset();
            fclose(file);

            printf("\n\t press any key to continue.......");
            getch();
            system("cls");
            menu();


        }

        else {
            if (pin_check < 3){
                yellow();
                printf("\n\t pin is incorrect please re-enter.....!\n");
                pin_check = pin_check + 1;
                printf ("\n\t Enter your pin number : \n");
                scanf ("%d",&pin);
                goto re_pin;

            }
            else {
                red();
                printf("\n\t pin number invalid.....!\n");
                color_reset();
            }


        }
    }

    
    }
    
}



void menu () {



int select;
yellow();
printf ("\n\t|_______________ Main Menu ____________________|");
green();
printf ("\n\t|create Account press       ---------------(1) |");
printf ("\n\t|update Account press       ---------------(2) |");
printf ("\n\t|Delete Account press       ---------------(3) |");
printf ("\n\t|View Account Details press ---------------(4) |");
printf ("\n\t|view balance press         ---------------(5) |");
printf ("\n\t|Withdraw money press       ---------------(6) |");
printf ("\n\t|deposite money press       ---------------(7) |");
printf ("\n\t|to exit press              ---------------(8) |\n");
cyan();
printf ("\n\t select one option (1-8) : ");
scanf ("%d",&select);

switch (select){

case 1:
    create_account ();
    break;

case 2 :
    update_account ();
    break;

case 3 :
    delete_account ();
    break;

case 4 :
    view_account();
    break;

case 5 :
    view_balance();
    break;

case 6 :
    withdraw ();
    break;

case 7 :
    deposite ();
    break;

case 8 :
    color_reset();
    printf("\n\t Press any key to continue.....!");
    getch();
    system("cls");
    exit(1);

default:
    red();
    printf("\n\t you pressed invalid number please try again...........!");
    menu();


}
}

void update_account (){
printf("\n\t press any key to continue.......");
getch();
system("cls");
FILE *file1,*file2;
struct user data;
int re_enter;
int re_pin;
file1 = fopen("records.txt","r");
file2 = fopen("temp.txt","a");

while(fscanf(file1,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (data.acc_number != account_number){
        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
    }

    else {
        yellow();
        printf ("\n\t update your account now......!\n");
        cyan();
        printf ("\n\t Edit your name : ");
        scanf("%s",&data.name);
        printf ("\n\t Edit your last name : ");
        scanf("%s",&data.last_name);
        printf ("\n\t Edit your branch name : ");
        scanf("%s",&data.branch);
        printf ("\n\t Edit your age : ");
        scanf("%d",&data.age);
        re_enter:
        printf ("\n\t change your pin number : ");
        scanf ("%d",&data.pin);
        printf ("\n\t confirm pin number : ");
        scanf ("%d",&re_pin);

        if (re_pin == data.pin){
            green();
            printf ("\n\t Successfully updated your account .......!");
            fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
            fclose (file1);
            fclose (file2);


            remove("records.txt");
            rename ("temp.txt","records.txt");

            getch();
            system("cls");
            menu();

        }
        else {
           red ();
           printf ("\n\t Your pin numbers are different try again......!");
           goto re_enter;
        }



    }
}



}
void delete_account (){
printf("\n\t press any key to continue.......");
getch();
system("cls");
FILE *file1,*file2;
struct user data;
file1 = fopen("records.txt","r");
file2 = fopen("temp.txt","a");

while(fscanf(file1,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (data.acc_number != account_number){
        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
    }
    else {
        red();
        printf ("\n\t Successfully deleted your account.....!");

        fclose (file1);
        fclose (file2);

        remove("records.txt");
        rename ("temp.txt","records.txt");



        //menu ();
        color_reset();
        printf("\n\t press any key to continue.......");
        getch();
        system("cls");
        main();
    }
  }
}
void deposite (){
printf("\n\t press any key to continue.......");
getch();
system("cls");

FILE *file1,*file2;
struct user data;
file1 = fopen("records.txt","r");
file2 = fopen("temp.txt","a");
int deposite;

printf ("\n\t Enter amount to deposite : ");
scanf ("%d",&deposite);

while(fscanf(file1,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (data.acc_number != account_number){
        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
    }

    else {

        data.balance = data.balance + deposite;
        yellow();
        printf ("\n\t _____________________________________________");
        green();
        printf ("\n\t|--------DEPOSITE MONEY TO YOUR ACCOUNT-------|");
        printf ("\n\t|----------------RECIEPT----------------------|");
        printf ("\n\t| Account holder  --------------   %s %s",data.name,data.last_name);
        printf ("\n\t| Branch name     --------------   %s",data.branch);
        printf ("\n\t| Deposite amount --------------   %d",deposite);
        printf ("\n\t| Balance         --------------   %d",data.balance);
        printf ("\n\t|_____________________________________________|");

        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);

        fclose (file1);
        fclose (file2);

        remove("records.txt");
        rename ("temp.txt","records.txt");

        printf ("\n");
        color_reset();
        printf("\n\t press any key to continue.......");
        getch();
        system("cls");
        menu();
        //menu();
    }

 }

}

void withdraw (){
printf("\n\t press any key to continue.......");
getch();
system("cls");
FILE *file1,*file2;
struct user data;
file1 = fopen("records.txt","r");
file2 = fopen("temp.txt","a");
int withdraw;

printf ("\n\t Enter amount to withdraw : ");
scanf ("%d",&withdraw);

while(fscanf(file1,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (data.acc_number != account_number){
        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);
    }

    else {
        if (data.balance > withdraw){
        data.balance = data.balance - withdraw;

        yellow();
        printf ("\n\t _____________________________________________");
        green();
        printf ("\n\t|--------DEPOSITE MONEY TO YOUR ACCOUNT-------|");
        printf ("\n\t|----------------RECIEPT----------------------|");
        printf ("\n\t| Account holder  --------------   %s %s",data.name,data.last_name);
        printf ("\n\t| Branch name     --------------   %s",data.branch);
        printf ("\n\t| Withdraw amount --------------   %d",withdraw);
        printf ("\n\t| Balance         --------------   %d",data.balance);
        printf ("\n\t|_____________________________________________|");
        color_reset();

        fprintf(file2,"%s %s %s %d %d %d %d ",data.name,data.last_name,data.branch,data.acc_number,data.age,data.pin,data.balance);

        fclose (file1);
        fclose (file2);

        remove("records.txt");
        rename ("temp.txt","records.txt");

        printf ("\n");
        printf("\n\t press any key to continue.......");
        getch();
        system("cls");
        menu();

        }
        else {
            red ();
            printf ("\n\t You cannot withdraw RS. %d ,because you haven't insufficient balance......!",withdraw);
            color_reset();

            //menu();
            printf("\n\t press any key to continue.......");
            getch();
            system("cls");
            menu();
        }


    }

 }

}

void view_account(){

printf("\n\t press any key to continue......."); 
getch();
system("cls");
FILE *file;
struct user data;
file = fopen("records.txt","r");

while(fscanf(file,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (account_number == data.acc_number){
        green();
        printf ("\n______________________________________________\n");
        printf ("\nHolder Name     --- %s %s",data.name,data.last_name);
        printf ("\nbranch          --- %s",data.branch);
        printf ("\nage             --- %d",data.age);
        printf ("\nAccount number  --- %d",data.acc_number);
        printf ("\nAccount Balance --- %d",data.balance);
        printf ("\n______________________________________________");
        color_reset();
    }
}

fclose(file);
printf("\n\t press any key to continue.......");
getch();
system("cls");
menu();

//menu();
}


void view_balance(){
printf("\n\t press any key to continue.......");
getch();
system("cls");
FILE *file;
struct user data;
file = fopen("records.txt","r");

while(fscanf(file,"%s %s %s %d %d %d %d ",&data.name,&data.last_name,&data.branch,&data.acc_number,&data.age,&data.pin,&data.balance)!=EOF){
    if (account_number == data.acc_number){
        green();
        printf ("\n\tYour account Balance is : %d",data.balance);
        color_reset();
}



}

fclose(file);
printf("\n\t press any key to continue.......");
getch();
system("cls");
menu();

//menu();
}




