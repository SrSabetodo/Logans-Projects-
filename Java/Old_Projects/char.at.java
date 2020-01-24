import java.util.Scanner;

class apples
{
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        char yed;

        do
        {
            System.out.print("HellO!");
            yed = in.next().charAt(0);
        }while(yed == 'y');

        in.close();
    }



}