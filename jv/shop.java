import java.util.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

class Shop{
    public static void main(String args[]){
        Menu menu = new Menu();
        menu.getMenu();
    }
}


class Menu{
    public static final HashMap<String, Integer> cart = new HashMap<String, Integer>();
    public static final HashMap<String, Integer> offer = new HashMap<String, Integer>();
    public static final HashMap<String, String> user = new HashMap<String, String>();
    public static final HashMap<String, HashMap<String, Integer>> orders = new HashMap<String, HashMap<String, Integer>>();
    public static String name;
    public static String email;
    public static String address;
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
        do{
		    String dayString;
			// switch statement with int data type
            switch (choice) {
		    case 1:
		        cart.put("pizza", 1);
		        System.out.println("1 pizza added to your cart Price : 12");
		        break;
		    case 2:
		        cart.put("pizza", 2);
		        System.out.println("2 pizza added to your cart Price : 22");
		        break;
		    case 3:
		        System.out.print("Please Enter Quantity : ");
		        Scanner readpizza = new Scanner(System.in);
		        Integer qty = readpizza.nextInt();
		        if (qty == 1){
		            choice = 1;
		            continue;
		        }else if (qty == 2){
		            choice = 2;
		            continue;
		        }
		        cart.put("pizza", qty);
                //Integer count = qty/3;
                offer.put("garlic bread", qty/3);
		        System.out.println(qty+" pizza added to your cart Price : "+qty*10+" and offer drink "+qty/3);
		        break;
		    case 4:
		        cart.put("pasta", 1);
                System.out.println("1 pasta added to your cart Price : 8");
                break;
		    case 5:
		        cart.put("pasta", 2);
                System.out.println("2 pastas added to your cart Price : 15");
                break;
		    case 6:
		        System.out.print("Please Enter Quantity : ");
                Scanner readpasta = new Scanner(System.in);
                Integer pqty = readpasta.nextInt();
                if (pqty == 1){
                    choice = 4;
                    continue;
                }else if (pqty == 2){
                    choice = 5;
                    continue;
                }
                cart.put("pasta", pqty);
                //Integer count = qty/3;
                offer.put("soft drink", pqty/3);
                System.out.println(pqty+" pizza added to your cart Price : "+pqty*10+" and offer drink "+pqty/3);
		        break;
		    default:
		        System.out.print("\nInvalid choice\nPlease Enter Valid choice : ");
                Scanner readchoice = new Scanner(System.in);
                Integer validchoice = readchoice.nextInt();
                choice = validchoice;
		        continue;
		    }
			System.out.print("\n1. Add More\n2. Checkout\nEnter Choice : ");
            Scanner readcheck = new Scanner(System.in);
			Integer checkout = readcheck.nextInt();
			if(checkout == 1){
				getMenu();
                break;
			}else{
				getCart();
                break;
			}
		}while(true);
    }

    public void getCart(){
        Integer price = 0 , total = 0, gtotal = 0;
        System.out.println("\n----------------------Cart--------------------\n");
        System.out.println("Name\t\tQuantity\tPrice\t\tTotal\n");
        for (Map.Entry<String, Integer> entry : cart.entrySet()){
            if (entry.getKey().equals("pizza")){
                if(entry.getValue() == 1){
                    price = 12;
                    total = 12;
                    gtotal += total;
                }else if(entry.getValue() == 2){
                    price = 22;
                    total = 22;
                    gtotal += total;
                }else{
                    price = 10;
                    total = price*entry.getValue();
                    gtotal += total;
                }
            }else if (entry.getKey().equals("pasta")){
                if(entry.getValue() == 1){
                    price = 8;
                    total = 8;
                    gtotal += total;
                }else if(entry.getValue() == 2){
                    price = 15;
                    total = 15;
                    gtotal += total;
                }else{
                    price = 7;
                    total = price*entry.getValue();
                    gtotal += total;
                }
            }
            System.out.println(entry.getKey()+"\t\t"+entry.getValue()+"\t*\t"+price+"\t\t"+total);
        }
        System.out.println("\nOffers");
        Integer gb = 0, drink = 0;
        for (Map.Entry<String, Integer> entry : offer.entrySet()){
            if (entry.getValue() >= 3 && entry.getKey().equals("garlic bread")){
                gb = entry.getValue();
            }else if(entry.getValue() >= 3 && entry.getKey().equals("soft drink")){
                drink = entry.getValue();
            }
            System.out.println(entry.getKey()+"\t" + entry.getValue()+"\t\t0\t\t0");
        }
        if(gb >= 3 && drink >= 3){
            System.out.println("Baklava\t\t" + Math.min(gb, drink)+"\t\t0\t\t0");
        }
        System.out.println("\t\t\t\t\t---------------------------\nGrand Total\t\t\t\t\t$"+gtotal+" AUD\n");
        System.out.println("1. Checkout\n2. Payment Information");
        Scanner readobj = new Scanner(System.in);
        Integer checkop = readobj.nextInt();
        if(checkop == 1){
            Checkout();
        }else{
            paymentInfo();
        }
    }


    public void Checkout(){
        Scanner readobj = new Scanner(System.in);
        System.out.print("Name : ");
        name = readobj.nextLine();
        System.out.print("Email : ");
        email = readobj.nextLine();
        System.out.print("Address : ");
        address = readobj.nextLine();
        user.put("name", name);
        user.put("email", email);
        user.put("address", address);
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = new Date();
        String now = dateFormat.format(date);
        orders.put(now, new HashMap<String, Integer>());
        for (Map.Entry<String, Integer> entry : cart.entrySet()){
           orders.get(now).put(entry.getKey(), Integer.parseInt(entry.getValue().toString()));
        }
        cart.clear();
        System.out.print("\n1. Menu\n2. Payment Information\n3. Quit\nEnter your choice : ");
        Integer finalchoice = readobj.nextInt();
        if(finalchoice == 1){
            getMenu();
        }else if(finalchoice == 2){
            paymentInfo();
        }
    }

    public void paymentInfo(){
        boolean pizza = false, pasta = false;
        System.out.print("\n1. Total payment for pizza\n2. Total payment for pasta\n3. Total payment for pizza and pasta\nEnter your choice : ");
        Scanner readpay = new Scanner(System.in);
        Integer payop = readpay.nextInt();
        if(payop == 1){
            pizza = true;
        }else if (payop == 2){
            pasta = true;
        }else{
            pizza = true;
            pasta = true;
        }
        getPaymentAmount(pizza, pasta);
    }

    public void getPaymentAmount(boolean pizza , boolean pasta){
        System.out.println("\n-----------------------------Invoice-----------------------------------");
        System.out.println("\nQuantity\tItem\t\tPrice\t\tTotal");
        for (Object objectName : orders.keySet()){
			Integer price = 0, total = 0, gtotal = 0, qty = 0;
			if(pizza){
                System.out.println("\n\nDate & Time \t:\t "+objectName);
                qty = orders.get(objectName).get("pizza");
				price = getPzPrice(orders.get(objectName).get("pizza"));
                gtotal += price;
                System.out.println(qty+"\t\tPizza\t\t"+price+"\t\t"+price);
            }
            if(pasta){
                qty = orders.get(objectName).get("pasta");
                price = getPsPrice(orders.get(objectName).get("pasta"));
                gtotal += price;
                System.out.println(qty+"\t\tPasta\t\t"+price+"\t\t"+price);
                System.out.println("\t\t\t\t\t-----------------------\nGrand Total\t\t\t\t\t"+gtotal);
			}
        }
        System.out.println("------------------Delivery Detail-------------------");
        System.out.println("Name : "+name);
        System.out.println("Email : "+email);
        System.out.println("Address : "+address+"\n-------------------------------------------\n");
        System.out.println("-----------------------------End Invoice---------------------------------");
        System.out.print("\n1. Menu\n2. Payment Information\n3. Quit\nEnter your choice : ");
        Scanner readlast = new Scanner(System.in);
        Integer finalchoice = readlast.nextInt();
        if(finalchoice == 1){
            getMenu();
        }else if(finalchoice == 2){
            paymentInfo();
        }
    }

    public int getPzPrice(Integer qty){
        Integer price = 0;
        if(qty == 1){
            price = 12;
        }else if (qty == 2){
            price = 22;
        }else if (qty > 2){
            price = qty*10;
        }
        return price;
    }

    public int getPsPrice(Integer qty){
        Integer price = 0;
        if(qty == 1){
            price = 8;
        }else if(qty == 2){
            price = 15;
        }else if (qty > 2){
            price = qty*7;
        }
        return price;
    }
}
