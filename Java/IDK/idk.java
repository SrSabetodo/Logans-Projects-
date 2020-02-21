import java.util.Scanner;
import java.util.Random;

class idk {
    public static void main(String[] args) {
       
        char response;
        Scanner in = new Scanner(System.in);
        do
       { 
            char lineOneOne = ' ', lineOneTwo = ' ', lineOneThree = ' ';
            char lineTwoOne = ' ', lineTwoTwo = ' ', lineTwoThree = ' ';
            char lineThreeOne = ' ', lineThreeTwo = ' ', lineThreeThree = ' ';

            

            boolean endGame = false;
            boolean compWins = false;
            boolean userWins = false;
            boolean tieGame = false;

            do {

                boolean compSave = false;
                boolean compTryToWin = false;
                boolean sneakyComp = false;

                boolean spaceFull = false;

                display(lineOneOne, lineOneTwo, lineOneThree, lineTwoOne, lineTwoTwo, lineTwoThree, lineThreeOne,
                        lineThreeTwo, lineThreeThree);

                /* ===== Get user selection ===== */
                do {
                    int selection = getSelection();

                    switch (selection) {
                    case 1:
                        if (lineOneOne == ' ') {
                            lineOneOne = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 2:
                        if (lineOneTwo == ' ') {
                            lineOneTwo = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 3:
                        if (lineOneThree == ' ') {
                            lineOneThree = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 4:
                        if (lineTwoOne == ' ') {
                            lineTwoOne = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 5:
                        if (lineTwoTwo == ' ') {
                            lineTwoTwo = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 6:
                        if (lineTwoThree == ' ') {
                            lineTwoThree = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 7:
                        if (lineThreeOne == ' ') {
                            lineThreeOne = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 8:
                        if (lineThreeTwo == ' ') {
                            lineThreeTwo = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    case 9:
                        if (lineThreeThree == ' ') {
                            lineThreeThree = 'X';
                            spaceFull = false;
                        } else {
                            spaceFull = true;
                        }
                        break;
                    default:
                        System.out.print("Please enter a valid choice: ");
                    }
                } while (spaceFull == true);

                /* ===== Make sure the board isn't full ===== */

                if (lineOneOne != ' ' && lineOneTwo != ' ' && lineOneThree != ' ' && lineTwoOne != ' ' && lineTwoTwo != ' '
                        && lineTwoThree != ' ' && lineThreeOne != ' ' && lineThreeTwo != ' ' && lineThreeThree != ' ') {
                    endGame = true;
                    tieGame = true;
                }

                /* ===== Make sure computer can go first ===== */

                if (lineOneOne == 'X' && lineOneTwo == 'X' && lineOneThree == 'X') {
                    endGame = true;
                    userWins = true;
                } // top row
                if (lineTwoOne == 'X' && lineTwoTwo == 'X' && lineTwoThree == 'X') {
                    endGame = true;
                    userWins = true;
                } // middle row
                if (lineThreeOne == 'X' && lineThreeTwo == 'X' && lineThreeThree == 'X') {
                    endGame = true;
                    userWins = true;
                } // bottom row

                if (lineOneOne == 'X' && lineTwoOne == 'X' && lineThreeOne == 'X') {
                    endGame = true;
                    userWins = true;
                } // left column
                if (lineOneTwo == 'X' && lineTwoTwo == 'X' && lineThreeTwo == 'X') {
                    endGame = true;
                    userWins = true;
                } // middle column
                if (lineOneThree == 'X' && lineTwoThree == 'X' && lineThreeThree == 'X') {
                    endGame = true;
                    userWins = true;
                } // right column

                if (lineOneOne == 'X' && lineTwoTwo == 'X' && lineThreeThree == 'X') {
                    endGame = true;
                    userWins = true;
                } // \ diag
                if (lineOneThree == 'X' && lineTwoTwo == 'X' && lineThreeOne == 'X') {
                    endGame = true;
                    userWins = true;
                } // / diag

                if (endGame != true) {
                    /* ===== Try to win ===== */

                    if (lineOneOne == 'O' && lineOneTwo == 'O' && lineOneThree == ' ' && compSave == false) {
                        lineOneThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == ' ' && lineOneTwo == 'O' && lineOneThree == 'O' && compSave == false) {
                        lineOneOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == 'O' && lineOneTwo == ' ' && lineOneThree == 'O' && compSave == false) {
                        lineOneTwo = 'O';
                        compTryToWin = true;
                    }

                    // line two
                    if (lineTwoOne == 'O' && lineTwoTwo == 'O' && lineTwoThree == ' ' && compSave == false) {
                        lineTwoThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineTwoOne == ' ' && lineTwoTwo == 'O' && lineTwoThree == 'O' && compSave == false) {
                        lineTwoOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineTwoOne == 'O' && lineTwoTwo == ' ' && lineTwoThree == 'O' && compSave == false) {
                        lineTwoTwo = 'O';
                        compTryToWin = true;
                    }

                    // line three
                    if (lineThreeOne == 'O' && lineThreeTwo == 'O' && lineThreeThree == ' ' && compSave == false) {
                        lineThreeThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineThreeOne == ' ' && lineThreeTwo == 'O' && lineThreeThree == 'O' && compSave == false) {
                        lineThreeOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineThreeOne == 'O' && lineThreeTwo == ' ' && lineThreeThree == 'O' && compSave == false) {
                        lineThreeTwo = 'O';
                        compTryToWin = true;
                    }

                    // left column
                    if (lineOneOne == 'O' && lineTwoOne == 'O' && lineThreeOne == ' ' && compSave == false) {
                        lineThreeOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == ' ' && lineTwoOne == 'O' && lineThreeOne == 'O' && compSave == false) {
                        lineOneOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == 'O' && lineTwoOne == ' ' && lineThreeOne == 'O' && compSave == false) {
                        lineTwoOne = 'O';
                        compTryToWin = true;
                    }

                    // middle column
                    if (lineOneTwo == 'O' && lineTwoTwo == 'O' && lineThreeTwo == ' ' && compSave == false) {
                        lineThreeTwo = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneTwo == ' ' && lineTwoTwo == 'O' && lineThreeTwo == 'O' && compSave == false) {
                        lineOneTwo = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneTwo == 'O' && lineTwoTwo == ' ' && lineThreeTwo == 'O' && compSave == false) {
                        lineTwoTwo = 'O';
                        compTryToWin = true;
                    }

                    // right column
                    if (lineOneThree == 'O' && lineTwoThree == 'O' && lineThreeThree == ' ' && compSave == false) {
                        lineThreeThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneThree == ' ' && lineTwoThree == 'O' && lineThreeThree == 'O' && compSave == false) {
                        lineOneThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneThree == 'O' && lineTwoThree == ' ' && lineThreeThree == 'O' && compSave == false) {
                        lineTwoThree = 'O';
                        compTryToWin = true;
                    }

                    // \ diag
                    if (lineOneOne == 'O' && lineTwoTwo == 'O' && lineThreeThree == ' ' && compSave == false) {
                        lineThreeThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == ' ' && lineTwoTwo == 'O' && lineThreeThree == 'O' && compSave == false) {
                        lineOneOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneOne == 'O' && lineTwoTwo == ' ' && lineThreeThree == 'O' && compSave == false) {
                        lineTwoTwo = 'O';
                        compTryToWin = true;
                    }

                    // / diag
                    if (lineOneThree == 'O' && lineTwoTwo == 'O' && lineThreeOne == ' ' && compSave == false) {
                        lineThreeOne = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneThree == ' ' && lineTwoTwo == 'O' && lineThreeOne == 'O' && compSave == false) {
                        lineOneThree = 'O';
                        compTryToWin = true;
                    }
                    if (lineOneThree == 'O' && lineTwoTwo == ' ' && lineThreeOne == 'O' && compSave == false) {
                        lineTwoTwo = 'O';
                        compTryToWin = true;
                    }

                    if (compTryToWin == false) {
                        /* ===== Keep user from winning ===== */

                        // line one
                        if (lineOneOne == 'X' && lineOneTwo == 'X' && lineOneThree == ' ' && compSave == false) {
                            lineOneThree = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == ' ' && lineOneTwo == 'X' && lineOneThree == 'X' && compSave == false) {
                            lineOneOne = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == 'X' && lineOneTwo == ' ' && lineOneThree == 'X' && compSave == false) {
                            lineOneTwo = 'O';
                            compSave = true;
                        }

                        // line two
                        if (lineTwoOne == 'X' && lineTwoTwo == 'X' && lineTwoThree == ' ' && compSave == false) {
                            lineTwoThree = 'O';
                            compSave = true;
                        }
                        if (lineTwoOne == ' ' && lineTwoTwo == 'X' && lineTwoThree == 'X' && compSave == false) {
                            lineTwoOne = 'O';
                            compSave = true;
                        }
                        if (lineTwoOne == 'X' && lineTwoTwo == ' ' && lineTwoThree == 'X' && compSave == false) {
                            lineTwoTwo = 'O';
                            compSave = true;
                        }

                        // line three
                        if (lineThreeOne == 'X' && lineThreeTwo == 'X' && lineThreeThree == ' ' && compSave == false) {
                            lineThreeThree = 'O';
                            compSave = true;
                        }
                        if (lineThreeOne == ' ' && lineThreeTwo == 'X' && lineThreeThree == 'X' && compSave == false) {
                            lineThreeOne = 'O';
                            compSave = true;
                        }
                        if (lineThreeOne == 'X' && lineThreeTwo == ' ' && lineThreeThree == 'X' && compSave == false) {
                            lineThreeTwo = 'O';
                            compSave = true;
                        }

                        // left column
                        if (lineOneOne == 'X' && lineTwoOne == 'X' && lineThreeOne == ' ' && compSave == false) {
                            lineThreeOne = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == ' ' && lineTwoOne == 'X' && lineThreeOne == 'X' && compSave == false) {
                            lineOneOne = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == 'X' && lineTwoOne == ' ' && lineThreeOne == 'X' && compSave == false) {
                            lineTwoOne = 'O';
                            compSave = true;
                        }

                        // middle column
                        if (lineOneTwo == 'X' && lineTwoTwo == 'X' && lineThreeTwo == ' ' && compSave == false) {
                            lineThreeTwo = 'O';
                            compSave = true;
                        }
                        if (lineOneTwo == ' ' && lineTwoTwo == 'X' && lineThreeTwo == 'X' && compSave == false) {
                            lineOneTwo = 'O';
                            compSave = true;
                        }
                        if (lineOneTwo == 'X' && lineTwoTwo == ' ' && lineThreeTwo == 'X' && compSave == false) {
                            lineTwoTwo = 'O';
                            compSave = true;
                        }

                        // right column
                        if (lineOneThree == 'X' && lineTwoThree == 'X' && lineThreeThree == ' ' && compSave == false) {
                            lineThreeThree = 'O';
                            compSave = true;
                        }
                        if (lineOneThree == ' ' && lineTwoThree == 'X' && lineThreeThree == 'X' && compSave == false) {
                            lineOneThree = 'O';
                            compSave = true;
                        }
                        if (lineOneThree == 'X' && lineTwoThree == ' ' && lineThreeThree == 'X' && compSave == false) {
                            lineTwoThree = 'O';
                            compSave = true;
                        }

                        // \ diag
                        if (lineOneOne == 'X' && lineTwoTwo == 'X' && lineThreeThree == ' ' && compSave == false) {
                            lineThreeThree = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == ' ' && lineTwoTwo == 'X' && lineThreeThree == 'X' && compSave == false) {
                            lineOneOne = 'O';
                            compSave = true;
                        }
                        if (lineOneOne == 'X' && lineTwoTwo == ' ' && lineThreeThree == 'X' && compSave == false) {
                            lineTwoTwo = 'O';
                            compSave = true;
                        }

                        // / diag
                        if (lineOneThree == 'X' && lineTwoTwo == 'X' && lineThreeOne == ' ' && compSave == false) {
                            lineThreeOne = 'O';
                            compSave = true;
                        }
                        if (lineOneThree == ' ' && lineTwoTwo == 'X' && lineThreeOne == 'X' && compSave == false) {
                            lineOneThree = 'O';
                            compSave = true;
                        }
                        if (lineOneThree == 'X' && lineTwoTwo == ' ' && lineThreeOne == 'X' && compSave == false) {
                            lineTwoTwo = 'O';
                            compSave = true;
                        }

                        /* ===== Prevent user from taking opposite corners and winning ===== */

                        // if square 1 is X & square 9 is open
                        if (lineOneOne == 'X' && lineThreeThree == ' ') {
                            lineThreeThree = 'O';
                            sneakyComp = true;
                        }

                        // if square 9 is X & sqaure 1 is open
                        if (lineThreeThree == 'X' && lineOneOne == ' ') {
                            lineOneOne = 'O';
                            sneakyComp = true;
                        }

                        // if square 3 is X & square 7 is open
                        if (lineOneThree == 'X' && lineThreeOne == ' ') {
                            lineThreeOne = 'O';
                            sneakyComp = true;
                        }

                        // if square 7 is X & square 3 is open
                        if (lineThreeOne == 'X' && lineOneThree == ' ') {
                            lineOneThree = 'O';
                            sneakyComp = true;
                        }

                        /* ===== If there is no need for the computer to save itself ===== */

                        if (compSave == false && sneakyComp == false) {
                            boolean notWork = false;
                            do {
                                int compSelection = compSelection();
                                notWork = false;
                                switch (compSelection) {
                                case 1:
                                    if (lineOneOne == ' ') {
                                        lineOneOne = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 2:
                                    if (lineOneTwo == ' ') {
                                        lineOneTwo = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 3:
                                    if (lineOneThree == ' ') {
                                        lineOneThree = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 4:
                                    if (lineTwoOne == ' ') {
                                        lineTwoOne = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 5:
                                    if (lineTwoTwo == ' ') {
                                        lineTwoTwo = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 6:
                                    if (lineTwoThree == ' ') {
                                        lineTwoThree = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 7:
                                    if (lineThreeOne == ' ') {
                                        lineThreeOne = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 8:
                                    if (lineThreeTwo == ' ') {
                                        lineThreeTwo = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                    break;

                                case 9:
                                    if (lineThreeThree == ' ') {
                                        lineThreeThree = 'O';
                                    } else {
                                        notWork = true;
                                    }
                                }
                            } while (notWork == true);
                        }
                    }
                }
                /* ===== See if computer has won ===== */

                if (lineOneOne == 'O' && lineOneTwo == 'O' && lineOneThree == 'O') {
                    endGame = true;
                    compWins = true;
                } // top row
                if (lineTwoOne == 'O' && lineTwoTwo == 'O' && lineTwoThree == 'O') {
                    endGame = true;
                    compWins = true;
                } // middle row
                if (lineThreeOne == 'O' && lineThreeTwo == 'O' && lineThreeThree == 'O') {
                    endGame = true;
                    compWins = true;
                } // bottom row

                if (lineOneOne == 'O' && lineTwoOne == 'O' && lineThreeOne == 'O') {
                    endGame = true;
                    compWins = true;
                } // left column
                if (lineOneTwo == 'O' && lineTwoTwo == 'O' && lineThreeTwo == 'O') {
                    endGame = true;
                    compWins = true;
                } // middle column
                if (lineOneThree == 'O' && lineTwoThree == 'O' && lineThreeThree == 'O') {
                    endGame = true;
                    compWins = true;
                } // right column

                if (lineOneOne == 'O' && lineTwoTwo == 'O' && lineThreeThree == 'O') {
                    endGame = true;
                    compWins = true;
                } // \ diag
                if (lineOneThree == 'O' && lineTwoTwo == 'O' && lineThreeOne == 'O') {
                    endGame = true;
                    compWins = true;
                } // / diag

                if (lineOneOne != ' ' && lineOneTwo != ' ' && lineOneThree != ' ' && lineTwoOne != ' ' && lineTwoTwo != ' '
                        && lineTwoThree != ' ' && lineThreeOne != ' ' && lineThreeTwo != ' ' && lineThreeThree != ' ') {
                    endGame = true;
                    tieGame = true;
                }

                if (endGame == true) {
                    display(lineOneOne, lineOneTwo, lineOneThree, lineTwoOne, lineTwoTwo, lineTwoThree, lineThreeOne,
                            lineThreeTwo, lineThreeThree);
                }

            } while (endGame != true);

            if (compWins == true) {
                System.out.println("Computer wins!");
            }
            if (userWins == true) {
                System.out.println("User wins!");
            }
            if (tieGame == true) {
                System.out.println("Tie game! No one wins!");
            }

            System.out.print("Play again? (y/n)");
            response = in.next().charAt(0);
        
        }while(response == 'y');

        System.out.println("Thanks for playing!");
        in.close();
    }

    public static void display(char lineOneOne, char lineOneTwo, char lineOneThree, char lineTwoOne, char lineTwoTwo,
            char lineTwoThree, char lineThreeOne, char lineThreeTwo, char lineThreeThree) {
        System.out.println(lineOneOne + "|" + lineOneTwo + "|" + lineOneThree + "   " +       "1|2|3");
        System.out.println(lineTwoOne + "|" + lineTwoTwo + "|" + lineTwoThree + "   " +       "4|5|6");
        System.out.println(lineThreeOne + "|" + lineThreeTwo + "|" + lineThreeThree + "   " + "7|8|9");
    }

    public static int getSelection() {
        Scanner in = new Scanner(System.in);
        int selection;

        System.out.print("Select Box: ");
        selection = in.nextInt();

        return selection;
    }

    public static int compSelection() {
        Random rand = new Random();

        int compSelection = rand.nextInt(9);
        compSelection += 1;

        return compSelection;
    }
}