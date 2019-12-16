import java.util.Scanner;

class apples
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        
        double first;
        double second;

        System.out.print("Enter first number: ");
        first = in.nextDouble();
        System.out.print("Enter second number: ");
        second = in.nextDouble();

        System.out.print("What operation can I perform for you? ((a)dd, (s)ub, (d)iv, (m)ul: ");

        char operation = in.next().charAt(0);
       
        switch(operation)
        {
            case 'a':
            System.out.print(first);
            System.out.print(" plus ");
            System.out.print(second);
            System.out.print(" equals: ");
            System.out.print(first+second);
            break;

            case 's':
            System.out.print(first);
            System.out.print(" minus ");
            System.out.print(second);
            System.out.print(" equals: ");
            System.out.print(first-second);
            break;

            case 'm':
            System.out.print(first);
            System.out.print(" times ");
            System.out.print(second);
            System.out.print(" equals: ");
            System.out.print(first*second);
            break;

            case 'd':
            System.out.print(first);
            System.out.print(" divided by ");
            System.out.print(second);
            System.out.print(" equals: ");
            System.out.print(first/second);
            break;

            default:
            System.out.println("I cannot do this operation at this time!");
            break;
        }    
    }
}