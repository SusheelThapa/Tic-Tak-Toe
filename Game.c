#include <stdio.h>
#include <conio.h>

void gamePage();

#if _WIN32

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define CLEAR_THE_SCREEN system("cls")

#define MAX_LIMIT 100

struct TIME
{
    int seconds;
    int minutes;
};

struct GameData
{
    char player_one[MAX_LIMIT];
    char player_two[MAX_LIMIT];
    int game_status;
    struct TIME time_of_game_play;
    struct TIME start;
    struct TIME stop;
};

SYSTEMTIME str_t;

char game_array[3][3];
struct GameData data;

//Design Function
void developerInformation();
void welcome();
void howToPlay();
void thankYou();
void loading();
void pressAkeyToContinue();
void badInput();

void gameHomeDisplay();
void option();

void doublePlayerMode();
void initializeGameArray();

void takeUserData(); //Take User Data

void creatingBoard(); //Create Tic Tak Toe Board
int markingBoard(char[], char); //Updated User choice in the Board

int check(); //Check either if anyone has won the game or not

void writeGameData(); //Write data of player who have won the game

void gameStatistics();  //Read data from Statistics.Dat located in Data folder
void textColorDisplay();//Text Color of Game
void screenBrightness(); //Change Brightness of game

char optionChoice();


void timeOfGamePlay();

int main()
{
    FILE *out_check_data_file;

    char position;

    goto Start;

DoublePlayerMode:

    loading();

    doublePlayerMode();

    printf("\n%10s", "");

    if (data.game_status == 1)
    {
        printf("%s won the game", data.player_one);
    }
    else if (data.game_status == 2)
    {
        printf("%s won the game", data.player_two);
    }
    else if (data.game_status == -1)
    {
        printf("GAME IS DRAW");
    }

    pressAkeyToContinue();

    writeGameData();

    goto Home;

Option:

    loading();

    gamePage(" Options ");

    option();

    position = optionChoice();

    switch (position)
    {
    case 'G':

        loading();

        gamePage("GAME STATISTICS");

        gameStatistics();

        pressAkeyToContinue();

        goto Option;

        break;

    case 'T':

        goto TextColor;

        break;

    case ('S'):

        goto ScreenBrightness;

        break;

    case ('B'):

        goto Home;

        break;

    case 'H':

        loading();

        gamePage("HOW TO PLAY?");

        howToPlay();

        pressAkeyToContinue();

        goto Option;

        break;

    case 'D':

        loading();

        gamePage("DEVELOPER");

        developerInformation();

        pressAkeyToContinue();

        goto Option;

        break;

    default:

        loading();

        badInput();

        pressAkeyToContinue();

        goto Option;

        break;
    }

TextColor:

    loading();

    gamePage("TEXT COLOR");

    textColorDisplay();

    position = optionChoice();

    switch (position)
    {
    case '1':

        system("color 1");
        break;

    case '2':

        system("color 2");
        break;

    case '3':

        system("color 3");
        break;

    case '4':

        system("color 4");
        break;

    case '5':

        system("color 5");
        break;

    case '6':

        system("color 6");
        break;

    case '7':

        system("color 7");
        break;

    case '8':

        system("color 8");
        break;

    case '9':

        system("color 9");
        break;

    case 'A':

        system("color A");
        break;

    case 'B':

        system("color B");
        break;

    case 'C':

        system("color C");
        break;

    case 'D':

        system("color D");
        break;

    case 'E':

        system("color E");
        break;

    case 'F':

        system("color F");
        break;

    default:

        loading();

        badInput();

        pressAkeyToContinue();

        goto TextColor;

        break;
    }

    pressAkeyToContinue();

    goto Option;

ScreenBrightness:

    loading();

    gamePage("SCREEN BRIGHTNESS");

    screenBrightness();

    position = optionChoice();

    switch (position)
    {
    case '1':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,10)");
        break;

    case '2':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,20)");
        break;

    case '3':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,30)");
        break;

    case '4':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,40)");
        break;
    case '5':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,50)");
        break;

    case '6':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,60)");
        break;

    case '7':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,70)");
        break;

    case '8':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,80)");
        break;
    case '9':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,90)");
        break;

    case 'A':
        system("powershell (Get-WmiObject -Namespace root/WMI -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1,100)");
        break;

    default:

        badInput();

        pressAkeyToContinue();

        goto ScreenBrightness;

        break;
    }

    pressAkeyToContinue();

    goto Option;

Start:

    out_check_data_file = fopen("./Data/Statistics.DAT", "r");

    if (out_check_data_file == NULL)
    {
        system("attrib +h +s Data");

        welcome();

        pressAkeyToContinue();

        fclose(out_check_data_file);
    }

    goto Home;

Home:

    loading();

    gameHomeDisplay();

    position = optionChoice();

    switch (position)
    {
    case 'D':

        goto DoublePlayerMode;

        break;

    case 'O':

        goto Option;

        break;

    case 'E':
        loading();

        gamePage("THANK YOU");

        thankYou();

        pressAkeyToContinue();

        exit(0);

    default:

        loading();

        badInput();

        pressAkeyToContinue();

        goto Home;
    }
}

void developerInformation()
{
    "This will show the developer information";

    FILE *out_developer;

    char ch;

    out_developer = fopen("./Data/Developer.txt", "r");

    while (1)
    {
        ch = fgetc(out_developer);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
        Sleep(10);
    }

    fclose(out_developer);
}

void welcome()
{
    "This will welcome the new user";

    gamePage("");

    FILE *out_welcome;

    char ch;

    out_welcome = fopen("./Data/Welcome.txt", "r");

    while (1)
    {
        ch = fgetc(out_welcome);

        if (ch == EOF)
        {
            break;
        }

        printf("%c", ch);

        Sleep(15);
    }

    fclose(out_welcome);
}

void howToPlay()
{
    "This will teach user how to play the game";

    FILE *out_how_to_play;

    char ch;

    out_how_to_play = fopen("./Data/How_To_Play.txt", "r");

    while (1)
    {
        ch = fgetc(out_how_to_play);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
        Sleep(5);
    }

    fclose(out_how_to_play);
}

void thankYou()
{
    "This will thanks to the user who had played the game";

    FILE *out_thank_you;

    char ch;

    out_thank_you = fopen("./Data/Thank_You.txt", "r");

    while (1)
    {
        ch = fgetc(out_thank_you);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
        Sleep(20);
    }

    fclose(out_thank_you);
}

void loading()
{
    "A pattern of loading the data";

    int i = 0, j = 0;

    CLEAR_THE_SCREEN;

    gamePage("");

    printf("%35s%-15s\n", "", "Loading");

    printf("%35s", "");

    while (i < 10)
    {
        Sleep(50);

        printf("\xdb");

        i++;
    }
}

void pressAkeyToContinue()
{
    "Ask user a key to press to move ahead";

    printf("\n\n%30s", "");

    system("pause");
}

void badInput()
{
    "Display the bad input information to the user";

    gamePage("BAD INPUT");

    printf("%25sPlease try to given valid input.\n", "");

    printf("\n%25sTry again with valid input.\n", " ");
}

void gameHomeDisplay()
{
    "This will show the home page of screen with option";

    gamePage(" TIC TAK TOE");

    printf("\n%30s%-30s", "", "Double Player Mode");
    printf("\n%30s%-30s", "", "Option");
    printf("\n%30s%-30s", "", "Exit");
}

void doublePlayerMode()
{
    "Double Player Game Mode";

    char position[3], player_symbol;
    int player = 1, mark_status = 1;

    initializeGameArray();

    takeUserData();

    do
    {
    TOP:
        printf("%10s", "");
        gamePage("DOUBLE PLAYER MODE");

        creatingBoard();

        player = (player % 2) ? 1 : 2;

        (player == 1) ? printf("%s\nPosition: ", data.player_one) : printf("%s\nPosition: ", data.player_two);
        scanf("%s", &position);

        player_symbol = (player == 1) ? 'X' : 'O';

        mark_status = markingBoard(position, player_symbol);

        if (mark_status == 0)
        {
            printf("\n%10sIt may have been already choosen or the option doesnot exist.\n", "");

            pressAkeyToContinue();

            goto TOP;
        }
        data.game_status = check();

        player++;

    } while (data.game_status == 0);

    gamePage("DOUBLE PLAYER MODE");

    creatingBoard();

    GetSystemTime(&str_t);

    data.stop.minutes = str_t.wMinute;
    data.stop.seconds = str_t.wSecond;
}

void initializeGameArray()
{
    "Make all the element of the game array to space";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            game_array[i][j] = ' ';
        }
    }
}

void takeUserData()
{
    "This takes user data like player one name, player two name";

    gamePage("TAKING USER INPUT");

    printf("%30sPlayer One: ", "");
    scanf(" %[^\n]", data.player_one);

    printf("\n");

    printf("%30sPlayer Two: ", "");
    scanf(" %[^\n]", data.player_two);

    data.game_status = 0;

    printf("\n%30sPress any key to start the game", "");

    getch();

    GetSystemTime(&str_t);

    data.start.minutes = str_t.wMinute;
    data.start.seconds = str_t.wSecond;
}

void creatingBoard()
{
    "Display TIC TAK TOE Board";

    printf("%30s%s(X) vrs %s(O) \n\n", "", data.player_one, data.player_two);

    printf("%15s ----------------------- %4s", "", "");
    printf("|");
    printf("%4s ----------------------- \n", "");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s|    %c   |   %c   |   %c  |%4s", "", game_array[0][0], game_array[0][1], game_array[0][2], "");
    printf("|");
    printf("%4s|   %s   |  %s   |  %s  |\n", "", "NW", "NN", "NE");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s ----------------------- %4s", "", "");
    printf("|");
    printf("%4s ----------------------- \n", "");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s|    %c   |   %c   |   %c  |%4s", "", game_array[1][0], game_array[1][1], game_array[1][2], "");
    printf("|");
    printf("%4s|   %s   |  %s   |  %s  |\n", "", "CW", "CC", "CE");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s ----------------------- %4s", "", "");
    printf("|");
    printf("%4s ----------------------- \n", "");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s|    %c   |   %c   |   %c  |%4s", "", game_array[2][0], game_array[2][1], game_array[2][2], "");
    printf("|");
    printf("%4s|   %s   |  %s   |  %s  |\n", "", "SW", "SS", "SE");

    printf("%15s|        |       |      |%4s", "", "");
    printf("|");
    printf("%4s|        |       |      |\n", "");

    printf("%15s ----------------------- %4s", "", "");
    printf("|");
    printf("%4s ----------------------- \n\n", "");
}

int markingBoard(char position[], char player)
{
    "Update Character Array";

    if (strcmpi(position, "NW") == 0 || strcmpi(position, "NN") == 0 || strcmpi(position, "NE") == 0 || strcmpi(position, "CW") == 0 || strcmpi(position, "CC") == 0 || strcmpi(position, "CE") == 0 || strcmpi(position, "SW") == 0 || strcmpi(position, "SS") == 0 || strcmpi(position, "SE") == 0)
    {
        if (strcmpi(position, "NW") == 0)
        {
            if (game_array[0][0] != ' ')
            {
                return 0;
            }
            game_array[0][0] = player;
        }
        else if (strcmpi(position, "NN") == 0)
        {
            if (game_array[0][1] != ' ')
            {
                return 0;
            }
            game_array[0][1] = player;
        }
        else if (strcmpi(position, "NE") == 0)
        {
            if (game_array[0][2] != ' ')
            {
                return 0;
            }
            game_array[0][2] = player;
        }
        else if (strcmpi(position, "CW") == 0)
        {
            if (game_array[1][0] != ' ')
            {
                return 0;
            }
            game_array[1][0] = player;
        }
        else if (strcmpi(position, "CC") == 0)
        {
            if (game_array[1][1] != ' ')
            {
                return 0;
            }
            game_array[1][1] = player;
        }
        else if (strcmpi(position, "CE") == 0)
        {
            if (game_array[1][2] != ' ')
            {
                return 0;
            }
            game_array[1][2] = player;
        }
        else if (strcmpi(position, "SW") == 0)
        {
            if (game_array[2][0] != ' ')
            {
                return 0;
            }
            game_array[2][0] = player;
        }
        else if (strcmpi(position, "SS") == 0)
        {
            if (game_array[2][1] != ' ')
            {
                return 0;
            }
            game_array[2][1] = player;
        }
        else if (strcmpi(position, "SE") == 0)
        {
            if (game_array[2][2] != ' ')
            {
                return 0;
            }
            game_array[2][2] = player;
        }

        return 1;
    }

    else
    {
        return 0;
    }
}

int check()
{
    "Check whether anyone has won or not";

    if (game_array[1][1] == 'X')
    {
        if ((game_array[0][0] == 'X' && game_array[2][2] == 'X') || (game_array[0][2] == 'X' && game_array[2][0] == 'X') || (game_array[0][1] == 'X' && game_array[2][1] == 'X') || (game_array[1][0] == 'X' && game_array[1][2] == 'X'))
        {
            return 1;
        }
    }
    if (game_array[0][0] == 'X')
    {
        if ((game_array[1][0] == 'X' && game_array[2][0] == 'X') || (game_array[0][1] == 'X' && game_array[0][2] == 'X'))
        {
            return 1;
        }
    }

    if (game_array[2][2] == 'X')
    {
        if ((game_array[0][2] == 'X' && game_array[1][2] == 'X') || (game_array[2][0] == 'X' && game_array[2][1] == 'X'))
        {
            return 1;
        }
    }

    if (game_array[1][1] == 'O')
    {
        if ((game_array[0][0] == 'O' && game_array[2][2] == 'O') || (game_array[0][2] == 'O' && game_array[2][0] == 'O') || (game_array[0][1] == 'O' && game_array[2][1] == 'O') || (game_array[1][0] == 'O' && game_array[1][2] == 'O'))
        {
            return 2;
        }
    }

    if (game_array[0][0] == 'O')
    {
        if ((game_array[1][0] == 'O' && game_array[2][0] == 'O') || (game_array[0][1] == 'O' && game_array[0][2] == 'O'))
        {
            return 2;
        }
    }

    if (game_array[2][2] == 'O')
    {
        if ((game_array[0][2] == 'O' && game_array[1][2] == 'O') || (game_array[2][0] == 'O' && game_array[2][1] == 'O'))
        {
            return 2;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_array[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return -1;
}

void timeOfGamePlay()
{
    "Calculate time of game play between two player";

    data.time_of_game_play.minutes = data.stop.minutes - data.start.minutes;
    data.time_of_game_play.seconds = data.stop.seconds - data.start.seconds;

    if (data.time_of_game_play.seconds < 0)
    {
        data.time_of_game_play.seconds = data.time_of_game_play.seconds + 60;
        data.time_of_game_play.minutes = data.time_of_game_play.minutes - 1;
    }
}

void writeGameData()
{
    "Write the game data to the file";

    FILE *in_game_data;

    in_game_data = fopen("./Data/Statistics.DAT", "a");

    if (in_game_data == NULL)
    {
        return;
    }

    timeOfGamePlay();

    fprintf(in_game_data, "%-15s%-20s%-20s      %5dsec      %s%s\n", __DATE__, data.player_one, data.player_two, data.time_of_game_play.minutes * 60 + data.time_of_game_play.seconds, (data.game_status == -1) ? ("Draw") : ((data.game_status == 1) ? (data.player_one) : (data.player_two)), (data.game_status != -1) ? (" won") : (" "));

    fclose(in_game_data);
}

void gameStatistics()
{
    "Disply all the game record that has been stored in our data base";

    FILE *out_game_data;
    char ch;

    out_game_data = fopen("./Data/Statistics.DAT", "r");

    if (out_game_data == NULL)
    {
        printf("%10sSome error occured while retrieving the data.\n", "");
        printf("%10sPlease try again later\n", "");
        printf("%10sIf it doesn't work try restarting the game.\n", "");
        return;
    }

    printf("\n\n%-15s%-20s%-20s%-20s%-30s\n", "DATE", "PLAYER ONE", "PLAYER TWO", "TIME OF GAME PLAY", "RESULT");

    for (int i = 0; i < 90; i++)
    {

        printf("=");
    }
    printf("\n\n");

    while (1)
    {
        ch = fgetc(out_game_data);

        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }

    fclose(out_game_data);
}

void option()
{
    "Show option for option in Home page";

    printf("\n%30s%-30s", "", "Game Statistics");
    printf("\n%30s%-30s", "", "Text Color");
    printf("\n%30s%-30s", "", "Screen Brightness");
    printf("\n%30s%-30s", "", "How to Play?");
    printf("\n%30s%-30s", "", "Developer");
    printf("\n%30s%-30s", "", "Back");
}

char optionChoice()
{
    "This will let user to position a option and return the choiced option";

    char position;

    printf("\n\n%28s%-20s", " ", "Choose any one of the above?\n");
    printf("%25s-->", " ");

    fflush(stdin); /*This line is important*/

    position = getch();
    printf("%c", position);
    getch();

    position = toupper(position);

    return position;
}

void textColorDisplay()
{
    "Option for Text Color";

    printf("%25s%-15s%10s%-15s\n", "", "1 = Blue  ", "", "9 = Light Blue  ");
    printf("%25s%-15s%10s%-15s\n", "", "2 = Green ", "", "A = Light Green ");
    printf("%25s%-15s%10s%-15s\n", "", "3 = Aqua  ", "", "B = Light Aqua  ");
    printf("%25s%-15s%10s%-15s\n", "", "4 = Red   ", "", "C = Light Red   ");
    printf("%25s%-15s%10s%-15s\n", "", "5 = Purple", "", "D = Light Purple");
    printf("%25s%-15s%10s%-15s\n", "", "6 = Yellow", "", "E = Light Yellow");
    printf("%25s%-15s%10s%-15s\n", "", "7 = White ", "", "F = Bright White");
    printf("%25s%-15s%10s%-15s\n", "", "8 = Gray  ", "", "");
}

void screenBrightness()
{
    "Option for screen Display";

    printf("%30s%-15s\n", "", " 1 =  10% Brightness ");
    printf("%30s%-15s\n", "", " 2 =  20% Brightness ");
    printf("%30s%-15s\n", "", " 3 =  30% Brightness ");
    printf("%30s%-15s\n", "", " 4 =  40% Brightness ");
    printf("%30s%-15s\n", "", " 5 =  50% Brightness ");
    printf("%30s%-15s\n", "", " 6 =  60% Brightness ");
    printf("%30s%-15s\n", "", " 7 =  70% Brightness ");
    printf("%30s%-15s\n", "", " 8 =  80% Brightness ");
    printf("%30s%-15s\n", "", " 9 =  90% Brightness ");
    printf("%30s%-15s\n", "", " A = 100% Brightness ");
}

#elif __APPLE__

void main()
{
    gamePage("MACHINE ERROR");

    printf("%10sThis game is still under processing to be run in Mac machine", "");

    getch();
}

#elif __linux__

void main()
{
    gamePage("Machine ERROR");

    printf("%10sThis game is still under processing to be run in Linux machine", "");

    getch();
}

#endif

void gamePage(char name[MAX_LIMIT])
{
    "Show the passed string as a heading";

    CLEAR_THE_SCREEN;

    printf("%35s%-25s\n", "", name);

    printf("%35s", "");

    for (int i = 0; i < strlen(name); i++)
    {
        printf("=");
    }

    printf("\n\n\n");
}
