import java.util.*;

class Shop{
    public static void main(String args[]){
        Menu menu = new Menu();
        menu.getMenu();
    }
}


class Menu{
    public static final HashMap<Integer, String> cart = new HashMap<Integer, String>();
    public static final HashMap<Integer, String> offer = new HashMap<Integer, String>();
    public void getMenu(){
        System.out.println("------------------------------Menu---------------------");
        System.out.println("Pizzas :- \n1. 1 large Pizza = 12 AUD\n2. 2 large Pizzas = 22 AUD\n3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)");
        System.out.println("\nPastas :- \n4. 1 large pasta = 8 AUD\n5. 2 large pastas = 15 AUD\n6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)");
        System.out.println("\nFor every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.\n\n7. Payment Information\n8. Quit");
        System.out.println("-------------------------------------------------------");

        Scanner readobj = new Scanner(System.in);
        Integer choice = readobj.nextInt();
        getChoice(choice);

    }

    public void getChoice(Integer choice){
        // switch statement with int data type
        String dayString;
        switch (choice) {
        case 1:
            dayString = "Monday";
            break;
        case 2:
            dayString = "Tuesday";
            break;
        case 3:
            dayString = "Wednesday";
            break;
        case 4:
            dayString = "Thursday";
            break;
        case 5:
            dayString = "Friday";
            break;
        case 6:
            dayString = "Saturday";
            break;
        case 7:
            dayString = "Sunday";
            break;
        default:
            dayString = "Invalid day";
            break;
        }
        System.out.println(dayString);
    }
}
