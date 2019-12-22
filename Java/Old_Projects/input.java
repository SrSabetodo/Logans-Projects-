import java.util.Scanner;

class apples
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        double fnum, snum, answer;
        
        System.out.print("Enter first number: ");
        fnum = in.nextDouble();
        System.out.print("Enter second number: ");
        snum = in.nextDouble();
        answer = fnum + snum;
        System.out.print("The sum of these two numbers is: ");
        System.out.print(answer);
        
    }
}