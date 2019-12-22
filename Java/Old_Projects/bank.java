import java.util.Scanner;

class orange
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in); //input variable..?
        float bal = 0, dep, with;
        int ugly;

        System.out.println("Greetings, how may I help you?");
        
        do{
        
        ugly = 0;
    
        System.out.println("(B)alance (D)eposit (W)ithdrawl e(X)it");
        char sel = in.next().charAt(0);
    
        switch(sel)
        {
            case 'B':
            System.out.print("Account balance is: $");
            System.out.println(bal);
            break;

            case 'D':
            System.out.println("How much would you like to deposit?");
            dep = in.nextFloat();
            bal+=dep; 
            System.out.print("The balance is now $");
            System.out.println(bal);
            break;

            case 'W':
            System.out.println("How much would you like to withdraw?");
            do{
                with = in.nextFloat();
                if(with>bal)
                {
                    System.out.print("Please enter an amount less than or equal to your current balance");
                    with = in.nextFloat();
                }
            }while(with>bal);
                
             bal-=with;
            
            System.out.print("The balance is now $");
            System.out.println(bal);               
            break;
            
            case 'X':
            System.out.println("Have a great day!");
            ugly = 1;
            break;

            default:
            System.out.println("I cannot currently do that operation");
            break;
        }    
    }while(ugly!=1);
    
    in.close();
    }
}