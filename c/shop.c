#include<stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int orderNum=0, pizza, pasta, gb, drink, baklava;
char name, email, address[50];
void Menu();
void SelectChoice(int choice);
void wait( int seconds );
void PaymentInfo();
int getPzAmount(int num);
int getPsAmount(int num);
void getCart();
void Checkout();
void PaymentHistory(bool pizza, bool pasta);

struct Order
{
    int pizza, pasta;
    struct tm tm;
};

struct Order orders[100];

int main(){
    int choice, x;
	Menu();
    return 0;
}

void Menu(){
    printf("---------------------------------------Menu------------------------------------------");
    printf("\nPizzas :- \n1. 1 large Pizza = 12 AUD\n2. 2 large Pizzas = 22 AUD\n3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)");
    printf("\nPastas :- \n4. 1 large pasta = 8 AUD\n5. 2 large pastas = 15 AUD\n6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)");
    printf("\nFor every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.\n\n7. Payment Information\n8. Cart\n9. Quit");
    printf("\n-------------------------------------------------------------------------------------\nEnter Choice : ");
    int choice;
    char *p, s[100];

    while (fgets(s, sizeof(s), stdin)) {
        choice = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }
    printf("You entered: %d\n", choice);
    SelectChoice(choice);
}

void SelectChoice(int choice){
	int qty, checkout;
	while(1){
		switch(choice) {
			case 1 :
				pizza = 1;
				break;
			case 2 :
				pizza = 2;
                printf("in 2");
				break;
			case 3 :
				printf("\nEnter Quantity : ");
				scanf("%d", &qty);
				if (qty == 1){
					choice = 1;
					continue;				
				}else if(qty == 2){
					choice = 2;
					continue;
				}else{
                    pizza = qty;
                }
				break;
			case 4 :
                pasta = 1;
                break;
			case 5 :
                pasta = 2;
			    break;
            case 6 :
                printf("\nEnter Quantity : ");
                scanf("%d", &qty);
                if (qty == 1){
                    choice = 4;
                    continue;
                }else if(qty == 2){
                    choice = 5;
                    continue;
                }else{
                    pasta = qty;
                }
                break;
            case 7 :
                PaymentInfo();
                break;
            case 8 :
                getCart();
                break;
            case 9 :
                exit(1);
            default :
			 printf("Invalid Choice\nEnter Choice : " );
             scanf("%d", &choice);
		}
        printf("\n1. Menu\n2. Cart\nEnter Choice : ");
        char *p, s[100];

		while (fgets(s, sizeof(s), stdin)) {
		    checkout = strtol(s, &p, 10);
		    if (p == s || *p != '\n') {
		        printf("Please enter an integer: ");
		    } else break;
		}
        if(checkout == 1){
            Menu();
            break;
        }else{
            getCart();
            int checkop;
            printf("\n1. Add More\n2. Checkout\nEnter Choice : ");
            char *p, s[100];

			while (fgets(s, sizeof(s), stdin)) {
				checkop = strtol(s, &p, 10);
				if (p == s || *p != '\n') {
				    printf("Please enter an integer: ");
				} else break;
			}
            if (checkop == 1){
                Menu();
                break;
            }else{
                Checkout();
            }
        }

	}
}



void wait( int seconds )
{   // Pretty crossplatform, both ALL POSIX compliant systems AND Windows
    #ifdef _WIN32
        Sleep( 1000 * seconds );
    #else
        sleep( seconds );
    #endif
}


void PaymentInfo(){
    bool pizza = false, pasta = false;
    int choice;
    printf("\n1. Total payment for pizza\n2. Total payment for pasta\n3. Total payment for pizza and pasta\nEnter your choice : ");
    char *p, s[100];
    int n;

    while (fgets(s, sizeof(s), stdin)) {
        choice = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }
    if(choice = 1){
        pizza = true;
    }else if(choice == 2){
        pasta = true;
    }else{
        pizza = true;
        pasta = true;
    }
    PaymentHistory(pizza, pasta);
}

void PaymentHistory(bool pizza, bool pasta){

    printf("\n------------------------------Payment Information---------------------------------\n");
    printf("\nItem\t\tQuantity\t\tPrice\n");
    for(int i = 0;i<orderNum;i++){
        printf("\nDate & Time\t : \t%d-%d-%d %d:%d:%d\n", orders[i].tm.tm_year + 1900, orders[i].tm.tm_mon + 1, orders[i].tm.tm_mday, orders[i].tm.tm_hour, orders[i].tm.tm_min, orders[i].tm.tm_sec);
        if(pizza){
            printf("Pizza\t\t%d\t\t%d\n", orders[i].pizza, getPzAmount(orders[i].pizza));
        }
        if(pasta){
            printf("Pasta\t\t%d\t\t%d\n", orders[i].pasta, getPsAmount(orders[i].pasta));
        }
    }
}




void getCart(){
    int gtotal = 0;
    printf("\n---------------------------------Cart------------------------------------\n");
    if(pizza>2){
        gb = pizza/3;
    }
    if(pasta>2){
        drink = pasta/3;
    }
    if(pizza > 2 && pasta >2 ){
        baklava = (gb < drink) ? gb : drink;
        baklava /= 3; 
    }
    printf("Item\t\tQuantity\tTotal\n\n");
    if(pizza>0){
        gtotal += getPzAmount(pizza);
        printf("Pizza\t\t%d\t\t%d\n",pizza, getPzAmount(pizza));
    }
    if(pasta>0){
        gtotal += getPsAmount(pasta);
        printf("Pasta\t\t%d\t\t%d\n",pasta, getPsAmount(pasta));
    }
    printf("Garlic Bread\t%d\t\t0\nSoft Drink\t%d\t\t0\nBakalava\t%d\t\t0\n", gb, drink, baklava);
    printf("\t\t\t-----------------------\nGrand Total\t\t\t\%d\n", gtotal);
    printf("\n---------------------------------------------------\n");
}


void Checkout(){
    orders[orderNum].pizza = pizza;
    orders[orderNum].pasta = pasta;
    time_t t = time(NULL);
    orders[orderNum].tm = *localtime(&t);
    pizza = 0;
    pasta = 0;
    orderNum++;
    printf("\nYour order has been confirmed\n");
    Menu();
}

int getPzAmount(int num){
    int price;
    if (num == 1){
        price = 12;
    }else if(num == 2){
        price = 22;
    }else{
        price = 10*num;
    }
    return price;
}


int getPsAmount(int num){
    int price;
    if (num == 1){
        price = 8;
    }else if(num == 2){
        price = 15;
    }else{
        price = 7*num;
    }
    return price;
}
