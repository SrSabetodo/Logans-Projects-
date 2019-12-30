 import java.util.Scanner;
 import java.util.Random;
 
 class idk
 {
    public static void main(String []args)
    {    
        char lineOneOne = ' ', lineOneTwo = ' ', lineOneThree = ' ';
        char lineTwoOne = ' ', lineTwoTwo = ' ', lineTwoThree = ' ';
        char lineThreeOne = ' ', lineThreeTwo = ' ', lineThreeThree = ' ';
        
        boolean endGame = false;
        boolean one = false, two = false, three = false;

        int userChoice; 

        do
        {
        /*throw InterruptedException;
        {
         Thread.sleep(2000);
        };*/

        boolean compSave = false;

        display(lineOneOne, lineOneTwo, lineOneThree, lineTwoOne, lineTwoTwo, lineTwoThree, lineThreeOne, lineThreeTwo, lineThreeThree);
        
/*===== Get user selection =====*/

        int selection = getSelection();

        switch(selection)
        {
            case 1:
            if(lineOneOne == ' '){lineOneOne = 'X';}
            userChoice = 1;
            break;
            case 2:
            if(lineOneTwo == ' '){lineOneTwo = 'X';}
            userChoice = 2;
            break;
            case 3:
            if(lineOneThree == ' '){lineOneThree = 'X';}
            userChoice = 3;
            break;
            case 4:
            if(lineTwoOne == ' '){lineTwoOne = 'X';}
            userChoice = 4;
            break;
            case 5:
            if(lineTwoTwo == ' '){lineTwoTwo = 'X';}
            userChoice = 5;
            break;
            case 6:
            if(lineTwoThree == ' '){lineTwoThree = 'X';}
            userChoice = 6;
            break;
            case 7:
            if(lineThreeOne == ' '){lineThreeOne = 'X';}
            userChoice = 7;
            break;
            case 8:
            if(lineThreeTwo == ' '){lineThreeTwo = 'X';}
            userChoice = 8;
            break;
            case 9:
            if(lineThreeThree == ' '){lineThreeThree = 'X';}
            userChoice = 9;
            break;
            default:
            System.out.print("Please enter a valid choice: ");
        }
       
/*===== Get Computer Selection =====*/

//line one 
if(lineOneOne == 'X' && lineOneTwo == 'X' && lineOneThree == ' '){lineOneThree = 'O'; compSave = true;}
if(lineOneOne == ' ' && lineOneTwo == 'X' && lineOneThree == 'X'){lineOneOne = 'O'; compSave = true;}
if(lineOneOne == 'X' && lineOneTwo == ' ' && lineOneThree == 'X'){lineOneTwo = 'O'; compSave = true;}

//line two
if(lineTwoOne == 'X' && lineTwoTwo == 'X' && lineTwoThree == ' '){lineTwoThree = 'O'; compSave = true;}
if(lineTwoOne == ' ' && lineTwoTwo == 'X' && lineTwoThree == 'X'){lineTwoOne = 'O'; compSave = true;}
if(lineTwoOne == 'X' && lineTwoTwo == ' ' && lineTwoThree == 'X'){lineTwoTwo = 'O'; compSave = true;}

//line three
if(lineThreeOne == 'X' && lineThreeTwo == 'X' && lineThreeThree == ' '){lineThreeThree = 'O'; compSave = true;}
if(lineThreeOne == ' ' && lineThreeTwo == 'X' && lineThreeThree == 'X'){lineThreeOne = 'O'; compSave = true;}
if(lineThreeOne == 'X' && lineThreeTwo == ' ' && lineThreeThree == 'X'){lineThreeTwo = 'O'; compSave = true;}

//left column
if(lineOneOne == 'X' && lineTwoOne == 'X' && lineThreeOne == ' '){lineThreeOne = 'O'; compSave = true;}
if(lineOneOne == ' ' && lineTwoOne == 'X' && lineThreeOne == 'X'){lineOneOne = 'O'; compSave = true;}
if(lineOneOne == 'X' && lineTwoOne == ' ' && lineThreeOne == 'X'){lineTwoOne = 'O'; compSave = true;}

//middle column
if(lineOneTwo == 'X' && lineTwoTwo == 'X' && lineThreeTwo == ' '){lineThreeTwo = 'O'; compSave = true;}
if(lineOneTwo == ' ' && lineTwoTwo == 'X' && lineThreeTwo == 'X'){lineOneTwo = 'O'; compSave = true;}
if(lineOneTwo == 'X' && lineTwoTwo == ' ' && lineThreeTwo == 'X'){lineTwoTwo = 'O'; compSave = true;}

//right column
if(lineOneThree == 'X' && lineTwoThree == 'X' && lineThreeThree == ' '){lineThreeThree = 'O'; compSave = true;}
if(lineOneThree == ' ' && lineTwoThree == 'X' && lineThreeThree == 'X'){lineOneThree = 'O'; compSave = true;}
if(lineOneThree == 'X' && lineTwoThree == ' ' && lineThreeThree == 'X'){lineTwoThree = 'O'; compSave = true;}

// \ diag
if(lineOneOne == 'X' && lineTwoTwo == 'X' && lineThreeThree == ' '){lineThreeThree = 'O'; compSave = true;}
if(lineOneOne == ' ' && lineTwoTwo == 'X' && lineThreeThree == 'X'){lineOneOne = 'O'; compSave = true;}
if(lineOneOne == 'X' && lineTwoTwo == ' ' && lineThreeThree == 'X'){lineTwoTwo = 'O'; compSave = true;}

// / diag
if(lineOneThree == 'X' && lineTwoTwo == 'X' && lineThreeOne == ' '){lineThreeOne = 'O'; compSave = true;}
if(lineOneThree == ' ' && lineTwoTwo == 'X' && lineThreeOne == 'X'){lineOneThree = 'O'; compSave = true;}
if(lineOneThree == 'X' && lineTwoTwo == ' ' && lineThreeOne == 'X'){lineTwoTwo = 'O'; compSave = true;}

if(!compSave)
{
    int compSelection = compSelection();
   do
   {
    boolean error = false;
    switch(compSelection)
    {
        case 1:
        if(lineOneOne == ' '){lineOneOne = 'O';}
        else{error = true;}
        break;
        
        case 2:
        if(lineOneTwo == ' '){lineOneTwo = 'O';}
        else{error = true;}
        break;

        case 3:
        if(lineOneThree == ' '){lineOneThree = 'O';}
        else{error = true;}
        break;

        case 4:
        if(lineTwoOne == ' '){lineTwoOne = 'O';}
        else{error = true;}
        break;

        case 5:
        if(lineTwoTwo == ' '){lineTwoTwo = 'O';}
        else{error = true;}
        break;

        case 6:
        if(lineTwoThree == ' '){lineTwoThree = 'O';}
        else{error = true;}
        break;

        case 7:
        if(lineThreeOne == ' '){lineThreeOne = 'O';}
        else{error = true;}
        break;

        case 8:
        if(lineThreeTwo == ' '){lineThreeTwo = 'O';}
        else{error = true;}
        break;

        case 9: 
        if(lineThreeThree == ' '){lineThreeThree = 'O';}
        else{error = true;}
     }
    }
    while(!true);

}
/*===== Validate Game =====*/

    if(lineOneOne == 'O' && lineOneTwo == 'O' && lineOneThree == 'O'){endGame = true;} // top row
    if(lineTwoOne == 'O' && lineTwoTwo == 'O' && lineTwoThree == 'O'){endGame = true;} // middle row
    if(lineThreeOne == 'O' && lineThreeTwo == 'O' && lineThreeThree == 'O'){endGame = true;} //bottom row

    if(lineOneOne == 'O' && lineTwoOne == 'O' && lineThreeOne == 'O'){endGame = true;} //left column 
    if(lineOneTwo == 'O' && lineTwoTwo == 'O' && lineThreeTwo == 'O'){endGame = true;} //middle column
    if(lineOneThree == 'O' && lineTwoThree == 'O' && lineThreeThree == 'O'){endGame = true;} //right column 
    
    if(lineOneOne == 'O' && lineTwoTwo == 'O' && lineThreeThree == 'O'){endGame = true;} // \ diag
    if(lineOneThree == 'O' && lineTwoTwo == 'O' && lineThreeOne == 'O'){endGame = true;} // / diag

    if(lineOneOne == 'X' && lineOneTwo == 'X' && lineOneThree == 'X'){endGame = true;} // top row
    if(lineTwoOne == 'X' && lineTwoTwo == 'X' && lineTwoThree == 'X'){endGame = true;} // middle row
    if(lineThreeOne == 'X' && lineThreeTwo == 'X' && lineThreeThree == 'X'){endGame = true;} //bottom row

    if(lineOneOne == 'X' && lineTwoOne == 'X' && lineThreeOne == 'X'){endGame = true;} //left column 
    if(lineOneTwo == 'X' && lineTwoTwo == 'X' && lineThreeTwo == 'X'){endGame = true;} //middle column
    if(lineOneThree == 'X' && lineTwoThree == 'X' && lineThreeThree == 'X'){endGame = true;} //right column 
    
    if(lineOneOne == 'X' && lineTwoTwo == 'X' && lineThreeThree == 'X'){endGame = true;} // \ diag
    if(lineOneThree == 'X' && lineTwoTwo == 'X' && lineThreeOne == 'X'){endGame = true;} // / diag
   
    if(endGame){display(lineOneOne, lineOneTwo, lineOneThree, lineTwoOne, lineTwoTwo, lineTwoThree, lineThreeOne, lineThreeTwo, lineThreeThree);}
   
    }
    while(!endGame);



    }
    
    public static void display(char lineOneOne, char lineOneTwo, char lineOneThree, char lineTwoOne, char lineTwoTwo, char lineTwoThree,
        char lineThreeOne, char lineThreeTwo,char lineThreeThree)
    {
        System.out.println(lineOneOne + "|" + lineOneTwo + "|" + lineOneThree);
        System.out.println(lineTwoOne + "|" + lineTwoTwo + "|" + lineTwoThree);
        System.out.println(lineThreeOne + "|" + lineThreeTwo + "|" + lineThreeThree);
    }

    public static int getSelection()
    {
        Scanner in = new Scanner(System.in);
        int selection;

        System.out.print("Select Box: ");
        selection = in.nextInt();

        return selection;
    }

    public static int compSelection()
    {
        Random rand = new Random();
        
        int compSelection = rand.nextInt(9); 
        compSelection += 1;

        return compSelection;
    }

}