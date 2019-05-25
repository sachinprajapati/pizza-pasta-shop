#include<stdio.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int orderNum=0, pizza, pasta, gb, drink, baklava;
void Menu();
void SelectChoice(int choice);
void wait( int seconds );
void getOrder();
int getPzAmount(int num);
int getPsAmount(int num);
void getCart();
void PaymentInfo();

struct Order
{
    int pizza, pasta;
    struct tm tm;
};

struct Order arr[100];

int main(){
    int choice;
	Menu();
}

void Menu(){
    printf("---------------------------------------Menu------------------------------------------");
    printf("\nPizzas :- \n1. 1 large Pizza = 12 AUD\n2. 2 large Pizzas = 22 AUD\n3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)");
    printf("\nPastas :- \n4. 1 large pasta = 8 AUD\n5. 2 large pastas = 15 AUD\n6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)");
    printf("\nFor every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.\n\n7. Payment Information\n8. Quit");
    printf("\n-------------------------------------------------------------------------------------\nEnter Choice : ");
    int choice;
    scanf("%d", &choice);
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
			default :
			 printf("Invalid Choice\nEnter Choice : " );
             scanf("%d", &choice);
		}
        printf("\n1. Add More\n2. Cart\nEnter Choice : ");
        scanf("%d", &checkout);
        if(checkout == 1){
            Menu();
            break;
        }else{
            getCart();
            int checkop;
            printf("\n1. Add More\n2. Checkout\nEnter Choice : ");
            scanf("%d", &checkop);
            if (checkop == 1){
                Menu();
                break;
            }else{
                printf("checkout");
                break;
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


void getOrder(){
    for(orderNum;orderNum<5;orderNum++){
        time_t t = time(NULL);
        arr[orderNum].pizza = 2;
        arr[orderNum].pasta = 3;
        arr[orderNum].tm = *localtime(&t);
        wait(2);
    }
    for(int i = 0;i<orderNum;i++){
        printf("pizza is %d\n", arr[i].pizza);
        printf("pasta is %d\n", arr[i].pasta);
        printf("now: %d-%d-%d %d:%d:%d\n", arr[i].tm.tm_year + 1900, arr[i].tm.tm_mon + 1, arr[i].tm.tm_mday, arr[i].tm.tm_hour, arr[i].tm.tm_min, arr[i].tm.tm_sec);
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


void PaymentInfo(){
    printf("payment info");
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
