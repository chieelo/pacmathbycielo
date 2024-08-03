#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char tmp_map[18][32];
char map[18][32] = {
    "+#############################+",
    "|    |                        |",
    "| #  ##   #####               |",
    "|               ##   #######  |",
    "|   |                         |",
    "| | |### |  |           |     |",
    "| |      |  | |###  |   |  |  |",
    "| | #####|  | |      ## |     |",
    "| |           |###  |      |  |",
    "| |##### ###         ##       |",
    "|         ####       ###   ###|",
    "|                             |",
    "|# ### ####      ###    ######|",
    "|                             |",
    "|     ###          ###        |",
    "|                             |",
    "|            ###              |",
    "+############################+#"};
FILE *fp, *file;
    int i, num[100][100], ghost[100][1], c=0;
    int s=0, numCount=0;

void ShowMap()
{
    int i;
    for (i = 0; i < 18; i++)
    {
        printf("%s\n", map[i]);
    }
}

char initial_map[18][32];

void copyInitialMap()
{
    int i;
    for (i = 0; i < 18; i++)
    {
        strcpy(initial_map[i], map[i]); 
    }
}

void resetMap()
{
    int i;
    for (i = 0; i < 18; i++)
    {
        strcpy(map[i], initial_map[i]); 
    }
}

int x,y,ex,ey;

void easynumballs() {
    int numbers[8];
    srand(time(NULL));
    for (i = 0; i < 8; i++) {
        numbers[i] = rand() % 9+1; 
    }

    for (numCount=0;numCount < 8;numCount++) {
    	int x = rand() % 17;
        int y = rand() % 29;

        if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
        	map[x][y] = numbers[numCount];
        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
        	printf ("%d", numbers[numCount]);
        }
        else{
        	numCount--;
		}  
    }
    for (s=0;s<2;s++){
    	int y = rand() % 29;
        int x = rand() % 17;

        if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
        	map[x][y] = num[c][s];
        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
        	printf ("%d", num[c][s]);
        }
        else{
        	s--;
		}
	}
}
void avenumballs() {
    int numbers[8];
    srand(time(NULL));
    for (i = 0; i < 8; i++) {
        numbers[i] = rand() % 20+1; 
    }

    for (numCount=0;numCount < 8;numCount++) {
    	int x = rand() % 17;
        int y = rand() % 29;
        
        if (numbers[i]>9){
        	if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
        	map[x][y] = numbers[numCount];
        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
        	printf ("%d", numbers[numCount]);
	        }
	        else{
	        	numCount--;
			}  
		}
		if (numbers[i]<10){
	        if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
	        	map[x][y] = numbers[numCount];
	        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
	        	printf ("%d", numbers[numCount]);
	        }
	        else{
	        	numCount--;
			}  
		}
    }
    for (s=0;s<2;s++){
    	int y = rand() % 29;
        int x = rand() % 17;

		if (numbers[i]>9){
	        if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
	        	map[x][y] = num[c][s];
	        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
	        	printf ("%d", num[c][s]);
	        }
	        else{
	        	s--;
			}
		}
		if (numbers[i]<10 && numbers[i]>0){
			if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
	        	map[x][y] = num[c][s];
	        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
	        	printf ("%d", num[c][s]);
	        }
	        else{
	        	s--;
			}
		}
	}
}
void hardnumballs() {
    int numbers[8];
    srand(time(NULL));
    for (i = 0; i < 8; i++) {
        numbers[i] = rand() % 40 - 20;
    }

    for (numCount = 0; numCount < 8; numCount++) {
        int x = rand() % 17;
        int y = rand() % 29;

        if (numbers[i] > 9) {
            if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = numbers[numCount];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", numbers[numCount]);
            }
            else {
                numCount--;
            }
        }
        else if (numbers[i] < 10 && numbers[i] > 0) {
            if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = numbers[numCount];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", numbers[numCount]);
            }
            else {
                numCount--;
            }
        }
        else if (numbers[i] < 0 && numbers[i] > -10) {
            if (map[x][y] == ' ' && map[x][y + 1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = numbers[numCount];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", numbers[numCount]);
            }
            else {
                numCount--;
            }
        }
        else if (numbers[i] < -10) {
            if (map[x][y] == ' ' && map[x][y + 1] == ' ' && map[x][y + 2] == ' ' && map[x][y+3] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = numbers[numCount];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", numbers[numCount]);
            }
            else {
                numCount--;
            }
        }
    }
    for (s = 0; s < 2; s++) {
        int y = rand() % 29;
        int x = rand() % 17;

        if (numbers[i] > 9) {
            if (map[x][y] == ' ' && map[x][y + 1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = num[c][s];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", num[c][s]);
            }
            else {
                s--;
            }
        }
        else if (numbers[i] < 10 && numbers[i] > 0) {
            if (map[x][y] == ' ' && map[x][y+1] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = num[c][s];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", num[c][s]);
            }
            else {
                s--;
            }
        }
        else if (numbers[i] < 0 && numbers[i] > -10) {
            if (map[x][y] == ' ' && map[x][y + 1] == ' ' && map[x][y+2] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = num[c][s];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", num[c][s]);
            }
            else {
                s--;
            }
        }
        else if (numbers[i] < -10) {
            if (map[x][y] == ' ' && map[x][y + 1] == ' ' && map[x][y + 2] == ' ' && map[x][y+3] == ' ' && map[x][y-1] == ' ') {
                map[x][y] = num[c][s];
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){y, x});
                printf("%d", num[c][s]);
            }
            else {
                s--;
            }
        }
    }
}



void clearNumbersFromMap()
{
    int i, j;
    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (map[i][j] >= '0' && map[i][j] <= '9')
            {
                map[i][j] = ' ';
            }
        }
    }
}


void gotoxy(short x, short y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int pts, reg;
void score(){
	gotoxy(0, 20);
			    printf("===========================================================\n");
			    printf("      Conquer the ghost with your mathematical skills!\n\n");
			    printf("        Ghost: %d                         Current Score: %d\n\n", ghost[c][0], reg);
			    printf("===========================================================\n");
			    printf("            Press Q if you want to exit the game.");
}

typedef struct entity
{
    int x;
    int y;
} entity;

typedef struct walk
{
    short walk_count;
    short x;
    short y;
    short back;
} walk;

typedef struct target
{
    short x;
    short y;
} target;

walk BFSArray[1024];
int BFSArray_size = 0;
target walk_queue[1024];
int walk_queue_size = 0;

void AddArray(int x, int y, int wc, int back)
{
    if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.')
    {
        tmp_map[y][x] = '#';
        walk tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.walk_count = wc;
        tmp.back = back;
        BFSArray[BFSArray_size++] = tmp;
    }
}

void FindPath(int sx, int sy, int x, int y)
{
    memcpy(tmp_map, map, sizeof(map));
    BFSArray_size = 0;
    walk tmp;
    tmp.x = sx;
    tmp.y = sy;
    tmp.walk_count = 0;
    tmp.back = -1;
    BFSArray[BFSArray_size++] = tmp;

    int i = 0;
    while (i < BFSArray_size)
    {
        if (BFSArray[i].x == x && BFSArray[i].y == y)
        {
            walk_queue_size = 0;
            target tmp2;
            while (BFSArray[i].walk_count != 0)
            {
                tmp2.x = BFSArray[i].x;
                tmp2.y = BFSArray[i].y;
                walk_queue[walk_queue_size++] = tmp2;

                i = BFSArray[i].back;
            }

            break;
        }

        AddArray(BFSArray[i].x + 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x - 1, BFSArray[i].y, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x, BFSArray[i].y + 1, BFSArray[i].walk_count + 1, i);
        AddArray(BFSArray[i].x, BFSArray[i].y - 1, BFSArray[i].walk_count + 1, i);

        i++;
    }

    BFSArray_size = 0;
}

int width = 150;
int height = 3; 
int main() {
    printf("Press Enter to stop the animation loop.\n");
    int i, j;
    for (i = 1; i <= 100; i++) {
        Sleep(10);
        printf("\r");
        printf("Loading");
        printf("");
        for (j = 1; j <= i; j++) {
            printf(".");
        }
    }
    printf("kimi\n\n");

    printf("Press Enter to stop the animation loop.\n");
    int ans;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int colors[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // Different colors
    int numIterations = 1; // Number of iterations for the animation
    int iteration;
    for (iteration = 0; iteration < numIterations; ++iteration) {
        for (i = 0; i < 15; i++) {
            system("cls"); 
            SetConsoleTextAttribute(h, colors[i]);
			printf("\t\t.----------------. .----------------. .----------------. .----------------. .----------------. .----------------. .----------------.\n");
			printf("\t\t| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n");
			printf("\t\t| | _____  _____ | | |  _________   | | |   _____      | | |     ______   | | |     ____     | | | ____    ____ | | |  _________   | |\n");
			printf("\t\t| ||_   _||_   _|| | | |_   ___  |  | | |  |_   _|     | | |   .' ___  |  | | |   .'    `.   | | ||_   \\  /   _|| | | |_   ___  |  | |\n");
			printf("\t\t| |  | | /\\ | |  | | |   | |_  \\_|  | | |    | |       | | |  / .'   \\_|  | | |  /  .--.  \\  | | |  |   \\/   |  | | |   | |_  \\_|  | |\n");
			printf("\t\t| |  | |/  \\| |  | | |   |  _|  _   | | |    | |   _   | | |  | |         | | |  | |    | |  | | |  | |\\  /| |  | | |   |  _|  _   | |\n");
			printf("\t\t| |  |   /\\   |  | | |  _| |___/ |  | | |   _| |__/ |  | | |  \\ `.___.'\\  | | |  \\  `--'  /  | | | _| |_\\/_| |_ | | |  _| |___/ |  | |\n");
			printf("\t\t| |  |__/  \\__|  | | | |_________|  | | |  |________|  | | |   `._____.'  | | |   `.____.'   | | ||_____||_____|| | | |_________|  | |\n");
			printf("\t\t| |              | | |              | | |              | | |              | | |              | | |              | | |              | |\n");
			printf("\t\t| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n");
			printf("\t\t'----------------' '----------------' '----------------' '----------------' '----------------' '----------------' '----------------'\n");
			printf("\n\n");
			printf("\t\t.----------------. .----------------. .----------------. .----------------. .----------------. .----------------. .----------------.\n");
			printf("\t\t| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n");
			printf("\t\t| |   ______     | | |      __      | | |     ______   | | | ____    ____ | | |      __      | | |  _________   | | |  ____  ____  | |\n");
			printf("\t\t| |  |_   __ \\   | | |     /  \\     | | |   .' ___  |  | | ||_   \\  /   _|| | |     /  \\     | | | |  _   _  |  | | | |_   ||   _| | |\n");
			printf("\t\t| |    | |__) |  | | |    / /\\ \\    | | |  / .'   \\_|  | | |  |   \\/   |  | | |    / /\\ \\    | | | |_/ | | \\_|  | | |   | |__| |   | |\n");
			printf("\t\t| |    |  ___/   | | |   / ____ \\   | | |  | |         | | |  | |\\  /| |  | | |   / ____ \\   | | |     | |      | | |   |  __  |   | |\n");
			printf("\t\t| |   _| |_      | | | _/ /    \\ \\_ | | |  \\ `.___.'\\  | | | _| |_\\/_| |_ | | | _/ /    \\ \\_ | | |    _| |_     | | |  _| |  | |_  | |\n");
			printf("\t\t| |  |_____|     | | ||____|  |____|| | |   `._____.'  | | ||_____||_____|| | ||____|  |____|| | |   |_____|    | | | |____||____| | |\n");
			printf("\t\t| |              | | |              | | |              | | |              | | |              | | |              | | |              | |\n");
			printf("\t\t| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n");
			printf("\t\t'----------------' '----------------' '----------------' '----------------' '----------------' '----------------' '----------------'\n");
            Sleep(300); // Adjust delay for animation speed

            if (_kbhit()) { // Check if a key has been pressed
                char ch = _getch();
                if (ch == '\r') // '\r' is Enter key
                    break;
            }
        }
    }

    
void printCenteredText(const char *text, int width, int height) {
    int paddingH = (width - strlen(text)) / 2;
    int paddingV = (height - 1) / 2; // Subtracting 1 for zero-based indexing
    int i;

    for (i = 0; i < paddingV; i++)
        printf("\n"); // Vertical padding

    for (i = 0; i < paddingH; i++)
        printf(" "); // Horizontal padding

    printf("%s\n", text);
}

void displayMenu() {
	height=3;
	SetConsoleTextAttribute(h, 15);
	printCenteredText("===================================================", width, height);
    printCenteredText("MENU:", width, height);
	printCenteredText("1. PLAY", width, height);
	printCenteredText("2. LEADERBOARD", width, height);
	printCenteredText("3. OBJECTIVES", width, height);
	printCenteredText("4. ABOUT PACMATH", width, height);
	printCenteredText("5. ABOUT THE CREATORS", width, height);
	printCenteredText("===================================================\n\n", width, height);
	printCenteredText("What would you like to select?", width, height);
	printCenteredText("(Press the respective number of your answer): ", width, height);
}	


void displayObjectives() {
	SetConsoleTextAttribute(h, 12);
   

    system("cls");
	height = 3;
    printCenteredText("PacMath is inspired by the classic arcade game released by Namco in 1980, Pacman.", width, height);
    printCenteredText("Players control and navigate the titular character, PacMath, through a maze-like environment", width, height);
    printCenteredText("while evading pursuit from CalcuGhost, a ghostly entity armed with a number. The game challenges", width, height);
    printCenteredText("players to collect scattered Numballs containing numbers and arithmetic operations necessary to solve", width, height);
    printCenteredText("the number presented by CalcuGhost.", width, height);
    SetConsoleTextAttribute(h, 14);
    height = 5;
    printCenteredText("Evade CalcuGhost: ", width, height);
    SetConsoleTextAttribute(h, 12);
    height = 3;
	printCenteredText("PacMath must avoid being caught by CalcuGhost,who relentlessly pursues", width, height);
    printCenteredText("it throughout the maze. Failure to outmaneuver CalcuGhost results in the end of the game.", width, height);
    SetConsoleTextAttribute(h, 14);
    height = 5;
    printCenteredText("Collect Numballs:", width, height); 
    SetConsoleTextAttribute(h, 12);
    height = 3;
	printCenteredText("PacMath must gather all the numballs scattered across the maze.", width, height);
    printCenteredText("These umballs contain the numbers and arithmetic operations required to get the number posed by CalcuGhost.", width, height);
    height = 5;
    printCenteredText("In summary, the objective of PacMath is to utilize quick thinking, mathematical skills, and strategic", width, height);
    height = 3;
    printCenteredText("movement to evade CalcuGhost, gather numballs, and solve numbers within the time limit, aiming to achieve", width, height);
    printCenteredText("the highest score possible and advance through increasingly challenging levels.", width, height);
}


void displayAboutPacMath() {
	SetConsoleTextAttribute(h, 13);
	system("cls");
	SetConsoleTextAttribute(h, 14);
	height = 5;
    printCenteredText("PacMath was founded by CASTech.", width, height);
    SetConsoleTextAttribute(h, 13);
    height = 3;
	printCenteredText("It commences its journey with a foundational value of zero,", width, height); 
	printCenteredText("embarking on a quest to consume numbers that materialize on the screen akin to the classic game Pacman.", width, height);
	height = 5;
	SetConsoleTextAttribute(h, 14);
	printCenteredText("However, there's a twist:", width, height); 
	height = 3;
	SetConsoleTextAttribute(h, 13);
	printCenteredText("PacMath must strategically ingest these numballs to align with the value", width, height); 
	printCenteredText("of the Calcughost,while ensuring that each intake propels rather than impedes its progress.", width, height);
	printCenteredText("Victory against Calcughost and advancement to subsequent levels hinge on PacMath's ability to synchronize", width, height);
	printCenteredText("its numerical essence with that of its spectral adversary before falling prey to Calcughost's pursuit.", width, height);
	printCenteredText("PacMath must also ensure not to fall prey unto the game’s path blockers.", width, height);
}

void displayAboutCreators() {
	SetConsoleTextAttribute(h, 15);
	system("cls");
	height = 3;
    printCenteredText("PacMath is the creation of CASTech which is a group of three", width, height);
	printCenteredText("Applied Mathematics with Information Technology Track students.", width, height);
	printCenteredText("They have collaborated to create a game suited for any ages above 6.", width, height);
	printCenteredText("The name CAS came from the abbreviation of each member's initials.", width, height);
	printCenteredText("Namely:", width, height);
	SetConsoleTextAttribute(h, 14);
    height = 5;
	printCenteredText("C=CONSUELO", width, height);
	SetConsoleTextAttribute(h, 9);
	printCenteredText("A=ANDRE", width, height);
	SetConsoleTextAttribute(h, 13);
	printCenteredText("S=SOPHIA", width, height);
	SetConsoleTextAttribute(h, 15);
	height = 3;
	printCenteredText("We are dedicated to providing you with the best gaming experience with PacMath.", width, height); 
	printCenteredText("Thus, if you have any inquiries, do not hesitate to message us in our hotline: 9132613", width, height);
}

void displayPlay() {
	system("cls");
    printCenteredText("Let us start!", width, height);
}

void displayLD() {
	system("cls");
	height = 3;
	SetConsoleTextAttribute(h, 15);
    printCenteredText("Welcome to Leaderboard!", width, height);
    printCenteredText("Take a look at our", width, height);
    SetConsoleTextAttribute(h, 14);
    height = 5;
	printCenteredText("C- courageous", width, height);
	SetConsoleTextAttribute(h, 9);
	printCenteredText("A - amazing", width, height);
	SetConsoleTextAttribute(h, 13);
	printCenteredText("S - Supercalifragilisticexpialidocious PacMaths!\n\n", width, height);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
			    int ld = 0, tempscore, scores[100];
			    char tempname[20], names[100][20], level[100], templevel;
    do {
        system("cls");
        displayMenu();
        if (scanf("%d", &ans) != 1) {
            clearInputBuffer(); 
            continue; 
        } 
        switch (ans) {
            case 3:
                displayObjectives();
                break;
            case 4:
                displayAboutPacMath();
                break;
            case 5:
                displayAboutCreators();
                break;
            case 1:
                displayPlay();
                	reg=0;
					copyInitialMap();
				    c=0;
				
				    BOOL running = TRUE;
				    int x = 15; // hero x
				    int y = 16; // hero y
				    int old_x;
				    int old_y;
				
				    int ex = 1;
				    int ey = 1;
				
				    int pts = 0;
				height = 5;
				printCenteredText("=====================================================", width, height);
			    printCenteredText("Instruction", width, height);
			    height = 3;
				printCenteredText("Arrow Keys to move your hero", width, height);
				printCenteredText("Eat the dots produced by the Eater to gain points", width, height);
				printCenteredText("Don't get caught by the Eater\n\n", width, height);
			    printCenteredText("H -> Hard", width, height);
				printCenteredText("N -> Normal", width, height);
				printCenteredText("E -> Easy", width, height);
				height = 4;
				printf("\n");
				printf("                                                                      Input : ");
				char diffi;
			    int speedmod = 3;
			    scanf(" %c", &diffi);
				printCenteredText("=====================================================", width, height);
				
			    
			    fp = fopen("pacman.txt", "r");
			    c=0;
				    if (fp == NULL) {
				        printf("Error opening file.\n");
				        return 1;
				    }
				    while (fscanf(fp, "%d %d", &num[c][0], &num[c][1]) == 2 && c < 100) {
				        c++;
				    }
				    c=0;
				    file = fopen("ghost.txt", "r");
				    while (fscanf(file, "%d", &ghost[c][0]) == 1 && c < 100) {
				        c++;
				    }
				    c = rand() % 8; 
				    
			    
			    if (diffi == 'N' || diffi == 'n')
			    {
			    	fp = fopen("pacmannormal.txt", "r");
			    	c=0;
				    if (fp == NULL) {
				        printf("Error opening file.\n");
				        return 1;
				    }
				    while (fscanf(fp, "%d %d", &num[c][0], &num[c][1]) == 2 && c < 100) {
				        c++;
				    }
				    c=0;
				    file = fopen("ghostnormal.txt", "r");
				    while (fscanf(file, "%d", &ghost[c][0]) == 1 && c < 100) {
				        c++;
				    }
				    c = rand() % 8; 
			        speedmod = 2;
			    }
			    else if (diffi == 'H' || diffi == 'h')
			    {
			    	c = 0;
				    fclose(fp); 
				    fclose(file); 
				
				    fp = fopen("pacmanhard.txt", "r");
				    if (fp == NULL) {
				        printf("Error opening file.\n");
				        return 1;
				    }
				    while (fscanf(fp, "%d %d", &num[c][0], &num[c][1]) == 2 && c < 100) {
				        c++;
				    }
				    c = 0;
				    file = fopen("ghosthard.txt", "r");
				    while (fscanf(file, "%d", &ghost[c][0]) == 1 && c < 100) {
				        c++;
				    }
				    c = rand() % 8; 
			        speedmod = 1;
			    }
				int number = 5;
			    system("cls");
			    ShowMap();
				if (diffi == 'N' || diffi == 'n')
			    {
			        easynumballs();
			    }
			    else if (diffi=='E' || diffi == 'e'){
			    	avenumballs();
				}
			    else if (diffi == 'H' || diffi == 'h')
			    {
			        hardnumballs();
			    }
			    gotoxy(x, y);
			    printf("P");
			
			    int frame = 0;
			    score();
			    FindPath(ex, ey, x, y);
				int exit = 0;
				
			    while (running)
			    {
			    	
			    	 if (_kbhit()) {
				    char ch = _getch();
				    if (ch == 'q' || ch == 'Q') {
				        width = 170;
				        height = 5;
				        printCenteredText("=====================================================", width, height);
				        printCenteredText("You chose to quit the game.", width, height); 
				        printCenteredText("Your score will not be recorded.\n", width, height);
				        printCenteredText("Press Enter to exit to the menu...", width, height);
				        exit = 1;
				        clearNumbersFromMap();
					    resetMap();
				        break;
    					}
				    }
				    
			        gotoxy(x, y);
			        printf(" ");
			        gotoxy(ex, ey);
			        printf(" ");
			        old_x = x;
			        old_y = y;
			     if (GetAsyncKeyState(VK_UP))
					{
					    if (map[y - 1][x] >= -20 && map[y - 1][x] <= 20) 
					    {
					        int num = (map[y - 1][x] - 0); 
					        if (map[y - 2][x] >= -20 && map[y - 2][x] <= 20) 
					        {
					            num = num * 10 + (map[y - 2][x] - 0); 
					            map[y - 2][x] = ' '; 
					            y -= 2;
					        }
					        else
					        {
					            map[y - 1][x] = ' '; 
					            y--;
					        }
					        if (num >= 0)
					            {
								pts += num;
								}
					        else
					            pts += num;
					        
					    }
					    else if (map[y - 1][x] == ' ')
					        y--;
					}
					
					if (GetAsyncKeyState(VK_DOWN))
					{
					    if (map[y + 1][x]>= -20 && map[y + 1][x] <= 20)
					    {
					        int num = (map[y + 1][x] - 0); 
					        if (map[y + 2][x]>= -20 && map[y + 2][x] <= 20) 
					        {
					            num = num * 10 + (map[y + 2][x] - 0); 
					            map[y + 2][x] = ' '; 
					            y += 2;
					        }
					        else
					        {
					            map[y + 1][x] = ' '; 
					            y++;
					        }
					        if (num >= 0)
					            {
								pts += num;
								}
					        else
					            pts += num;
					    }
					    else if (map[y + 1][x] == ' ')
					        y++;
					}
					
					if (GetAsyncKeyState(VK_LEFT))
					{
					    if (map[y][x - 1] >= -20 && map[y][x - 1] <= 20) 
					    {
					        int num = (map[y][x - 1] - 0); 
					        if (map[y][x - 2] >= -20 && map[y][x - 2] <= 20) 
					        {
					            num = num * 10 + (map[y][x - 2] - 0); 
					            map[y][x - 2] = ' '; 
					            x -= 2;
					        }
					        else
					        {
					            map[y][x - 1] = ' '; 
					            x--;
					        }
					        if (num >= 0)
					            {
								pts += num;
								}
					        else
					            pts += num;
					    }
					    else if (map[y][x - 1] == ' ')
					        x--;
					}
					
					if (GetAsyncKeyState(VK_RIGHT))
					{
					    if (map[y][x + 1] >= -20 && map[y][x + 1] <= 20) 
					    {
					        int num = (map[y][x + 1] - 0);
					        if (map[y][x + 2] >= -20 && map[y][x + 2] <= 20) 
					        {
					            num = num * 10 + (map[y][x + 2] - 0); 
					            map[y][x + 2] = ' '; 
					            x += 2;
					        }
					        else
					        {
					            map[y][x + 1] = ' '; 
					            x++;
					        }
					        if (num >= 0)
					            {
								pts += num;
								}
					        else
					           pts += num;
					    }
					    else if (map[y][x + 1] == ' ')
					        x++;
					}

					        if (old_x != x || old_y != y)
					        {
					            FindPath(ex, ey, x, y);
					        }
					
					        gotoxy(x, y);
					        SetConsoleTextAttribute(h, 13);
					        printf("P");
					
					        // Clear Eater's previous position
					        map[ey][ex] = ' ';
					
					        if (frame % speedmod == 0 && walk_queue_size != 0)
					        {
					            int new_ex = walk_queue[walk_queue_size - 1].x;
					            int new_ey = walk_queue[walk_queue_size - 1].y;
					            walk_queue_size--;
					
					            // Check if the new position is valid
					            if (map[new_ey][new_ex] == ' ' || map[new_ey][new_ex] == '.')
					            {
					                // Update Eater's position
					                ex = new_ex;
					                ey = new_ey;
					            }
					            else
					            {
					                printf("Invalid position for Eater: (%d, %d)\n", new_ex, new_ey);
					            }
					        }
					
					        gotoxy(ex, ey);
					        SetConsoleTextAttribute(h, 10);
					        printf("E");
					SetConsoleTextAttribute(h, 15);
					        if (ex == x && ey == y)
					        {
					        	if (pts == ghost[c][0]) {
					        		reg++;
					            // Reset positions and points when the Eater catches the hero
					            ex = 1;
					            ey = 1;
					            x = 15;
					            y = 16;
					            pts = 0;
					            c = rand() % 8;
					            
					            clearNumbersFromMap();
					            resetMap();
					            printf("\n\n\n\n");
								            
					            // Clear maze
					            system("cls");
								ShowMap();
								if (diffi == 'N' || diffi == 'n')
							    {
							        avenumballs();
							    }
							    else if (diffi=='E' || diffi == 'e'){
							    	easynumballs();
								}
							    else if (diffi == 'H' || diffi == 'h')
							    {
							        hardnumballs();
							    }
								score();
						        }
						        else{
						        	break;
								}
						    }
					
					        gotoxy(32, 18);
					        gotoxy(32, 1);
					        printf("%d", pts);
					        Sleep(100);
					        frame++;
					    
				}
				fclose(fp);
				system("cls"); 
			    getchar(); 
			   
				if (exit == 0)
				{
				system ("cls");
		        printf ("GAME OVER!\n\n");
				printf ("Score: %d\n", reg);
				printf ("Record your score by inputting your name: ");
				scanf("  %s", names);
				FILE *infile;
				infile = fopen("leaderboard.txt", "a");
				if (infile == NULL) {
					printf("Error opening file");
					return 1;
				}
					else{
						fprintf(infile, "\n%s %d %c", names, reg, diffi);
					    fclose(infile);
					}
					printf ("Recorded!\n\n");
					getchar();
					clearNumbersFromMap();
					resetMap();
		            continue;
				}
				else
				{
					break;
				}
                
            case 2: 
                displayLD();
                printCenteredText("LEADERBOARD\n\n", width, height);
			    FILE *file = fopen("leaderboard.txt", "r");
			    if (file == NULL) {
			        printf("Error opening file!\n");
			        return 1;
			    }
			    while (ld < 100 && fscanf(file, "%19s %d %c", names[ld], &scores[ld], &level[ld]) == 3) {
			        ld++;
			    }
			    
			    fclose(file);
			    int levelValue[128]; 
			    levelValue['H'] = 3;
			    levelValue['N'] = 2;
			    levelValue['E'] = 1;
			    levelValue['h'] = 3;
			    levelValue['n'] = 2;
			    levelValue['e'] = 1;
			
			    for (i = 0; i < ld - 1; i++) {
			        for (j = i + 1; j < ld; j++) {
			            if (levelValue[level[i]] < levelValue[level[j]] ||
			                (levelValue[level[i]] == levelValue[level[j]] && scores[i] < scores[j])) {
			                tempscore = scores[i];
			                scores[i] = scores[j];
			                scores[j] = tempscore;
			
			                templevel = level[i];
			                level[i] = level[j];
			                level[j] = templevel;
			
			                strcpy(tempname, names[i]);
			                strcpy(names[i], names[j]);
			                strcpy(names[j], tempname);
			            }
			        }
			    }
			    printCenteredText("NAME\t         SCORE\t\tLEVEL\n", width, height);
			    for (i = 0; i < ld; i++) {
			        printf("\t\t\t\t\t\t\t%s\t\t\t%d\t\t%c\n", names[i], scores[i], toupper(level[i]));
			    }
                	break;    
            default:
                printf("\n\nWe're sorry. We do not have that option.\n\n");
        }

        if (ans >= 1 && ans <= 5) {
        	SetConsoleTextAttribute(h, 15);
            printf("\n\nPress Enter to return to the menu...");
            while (_getch() != '\r'); 
        }
    } while (1);

    return 0;
}
