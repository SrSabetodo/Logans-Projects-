import java.util.Scanner;

class apples3
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        salmon salObj = new salmon();

        System.out.println("Enter your name here: ");
        String name = input.nextLine();

        salObj.simpleMessage(name);
    }
}