#include <iostream>
#include <Windows.h>
#include <ctime>               // srand(time(0))
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;
void homeScreen();

char map[25][25];       // game map
int y, x;               //the cars coordinates
int a , b;              //the obstacles coordinates
int n ,m;                //the Rcar coordinates
char obstacle = 219;
int key=1;              //home page user selection
int points;             // score
int life;
int color=15,userCarSelection;              //15-white
int p, q;
int g,h;
char cash = '$';
char heart='@';
char Rcar= 719;
bool cashApprove;       // approve cash


    string playerName;      //player name
    struct playerRecord
    {
        string name;
        int score;
    };
    playerRecord hScore[5];


//clear screen
void clearscreen()//used to prevent flicker
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);

}


//help
void help()
{

    cout<<"              <- Move the car to Left"<<endl;Sleep(150);;
    cout<<"             ->  Move the car to Right"<<endl;Sleep(150);
    cout<<"   If you crash the opposite car Game will be Over"<<endl;Sleep(150);
    cout<<"     Your speed increases as our score increases "<<endl;Sleep(150);
    cout<<"   When you catch the $ your points increases by 30 "<<endl;Sleep(150);
    cout<<"      When you catch the @ your Life increases  "<<endl;Sleep(150);
    cout<<"                     Maximum life is 5  "<<endl;

    _getch();
    system("cls");
    homeScreen();
}

//carColor
void carColor() //use to change the car color
{
    int carColorErrorSelection=1;
    while(carColorErrorSelection==1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
        cout<<"1\tBLUE"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        cout<<"2\tCYAN"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout<<"3\tRED"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
        cout<<"4\tMAGENTA"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout<<"5\tBROWN"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout<<"6\tLIGHTGRAY"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout<<"7\tLIGHTBLUE"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"8\tLIGHTGREEN"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"9\tLIGHTRED"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        cout<<"10\tYELLOW"<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

        cin>>userCarSelection;

        switch(userCarSelection)
        {
        case 1:
            color=1;
            carColorErrorSelection=0;
            break;
        case 2:
            color=2;
            carColorErrorSelection=0;
            break;
        case 3:
            color=4;
            carColorErrorSelection=0;
            break;
        case 4:
            color=5;
            carColorErrorSelection=0;
            break;
        case 5:
            color=6;
            carColorErrorSelection=0;
            break;
        case 7:
            color=9;
            carColorErrorSelection=0;
            break;
        case 8:
            color=10;
            carColorErrorSelection=0;
            break;
        case 9:
            color=12;
            carColorErrorSelection=0;
            break;
        case 10:
            color=14;
            carColorErrorSelection=0;
            break;
        default:
            carColorErrorSelection=1;
            break;
        }
        system("cls");
    }
    system("cls");
    homeScreen();
}

//mapColor
void mapColor(int i,int j) //use to print the map with color
{
    switch(map[i][j])
    {
    case '$':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        break;
    case '|':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        break;
    case 219:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        break;
    case 'O':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
        break;
    case 'X':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
        break;
    case 442:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
        break;
    case 719:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        break;
    case '@':
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        break;
    default:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        break;
    }
}

void highScoreMenu()
{
    string name; int score;
    ifstream fin("higeScore.txt");
    while(fin >> name >> score)
    {
        cout<<"\t"<<name<<"\t\t"<<score<<endl;Sleep(100);;
    }
    _getch();
    system("cls");
    homeScreen();
}

//homeScreen
void homeScreen()
{

    int selectionError=1;
	while(selectionError==1)
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"	           __  __  _"<<endl;Sleep(100);
        cout<<"	    |\\  | |   |   | \\"<<endl;Sleep(100);
        cout<<"	    | \\ | |-- |-- |  |"<<endl;Sleep(100);
        cout<<"	    |  \\| |__ |__ |_/ "<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        cout<<"       ____     __  __   __      ____                     "<<endl;Sleep(100);
        cout<<"     _/__|_|   |   |  | |  |   _/__|_|                    "<<endl;Sleep(100);
        cout<<"    (__BMW__)  |-- |  | |--   (__BENZ_)                  "<<endl;Sleep(100);
        cout<<"     (0) (0)   |   |__| | \\_   (0) (0)                    "<<endl;Sleep(100);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"	   ___   __   __  __  _"<<endl;Sleep(100);
        cout<<"	  |     |  | |   |   | \\ "<<endl;Sleep(100);
		cout<<"	  \\---\\ |--- |-- |-- |  |"<<endl;Sleep(100);
		cout<<"	   ___| |    |__ |__ |_/ "<<endl;Sleep(100);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

        cout<< "       <<     1 - Start Game      >>"<<endl;Sleep(50);
        cout<< "       <<       2 - Help          >>"<<endl;Sleep(50);
        cout<< "       << 3 - Car Color Selection >>"<<endl;Sleep(50);
        cout<< "       <<     4 - High Score      >>"<<endl;Sleep(50);
        cout<< "       <<       5 - Exit          >>"<<endl;

        cin>>key;
        switch(key)
        {
        case 1:         //play game
            selectionError=0;
            system("cls");
            break;
        case 2:         //help page
            system("cls");
            selectionError=0;
            help();
            system("cls");
            break;
        case 3:         //selecting car color
            system("cls");
            selectionError=0;
            carColor();
            system("cls");
            break;
        case 4:         //exit
            system("cls");
            selectionError=0;
            highScoreMenu();
            system("cls");
            break;
        case 5:         //exit
            system("cls");
            selectionError=0;
            break;
        default:        //error selection
            selectionError=1;
            system("cls");
            break;
        }
    }
}


//gaame over
void gameOver()
{

    cout<<"                      Your score "<<points<<endl;
    cout<<"  ___________        _____      _ _       _ _  _________       "<<endl;
    cout<<" / _________ \\      / ___ \\     | _\\     /_ | / ________\\  "<<endl;
    cout<<"| /         \\_\\    / /   \\ \\    | |\\\\   //| | | |        "<<endl;
    cout<<"| |     _____     / /     \\ \\   | | \\\\_// | | | |_____     "<<endl;
    cout<<"| |    |____ \\   / /_______\\ \\  | |  \\_/  | | | |_____|    "<<endl;
    cout<<"| |         | | | |_________| | | |       | | | |              "<<endl;
    cout<<"| \\_________| | | |         | | | |       | | | |________     "<<endl;
    cout<<" \\___________/  |_|         |_| |_|       |_| \\_________/    "<<endl;Sleep(200);

    cout<<"   _________    ___         ___   _________    _________       "<<endl;
    cout<<" /  _______  \\  | |         | |  / ________\\  /  ______ \\   "<<endl;
    cout<<"|  /       \\  | | |         | | | /          |  /      \\ |   "<<endl;
    cout<<"| |         | |  \\ \\       / /  | |_____     | |_______| |   "<<endl;
    cout<<"| |         | |   \\ \\     / /   | |_____|    | |_    ___/    "<<endl;
    cout<<"| |         | |    \\ \\   / /    | |          | | \\_  \\_    "<<endl;
    cout<<"|  \\ ______/  |     \\ \\_/ /     | \\________  | |   \\_  \\_"<<endl;
    cout<<" \\ _________ /       \\___/       \\_________/ |_|     \\___\\"<<endl;

        //color changing
        system("color 0A");
        Sleep(150);
        system("color 0A");
        Sleep(150);
        system("color 0A");
        Sleep(150);
        system("color 0B");
        Sleep(150);
        system("color 0C");
        Sleep(150);
        system("color 0E");
        Sleep(150);
        system("color 0F");
        Sleep(3000);
        _getch();
}


//load map
void LoadMap()      //loads the road with spaces and borders
{
    for(int i=0; i < 20; ++i)
        {
          for(int j=0; j < 20; ++j)
            {
                map[i][0] = '|';
                map[i][18] = '|';
                map[i][j] = ' ';
            }
        }
}

//places car
void PlacesUserCar() //places the car at its default location
{
    map[y][x] = 'X';
    map[y][x+1] = 442;
    map[y][x-1] = 442;
    map[y+1][x-1] = 'O';
    map[y+1][x+1] = 'O';
    map[y-1][x-1] = 'O';
    map[y-1][x+1] = 'O';
}

//Generates obstacles
void PlaceOppositeCar()   //generates the obstacles
{
    map[a][b] = ' ';
    map[a][b] = ' ';
    map[a][b+1] = ' ';
    map[a][b-1] = ' ';
    map[a+1][b-1] = ' ';
    map[a+1][b+1] = ' ';
    map[a-1][b-1] = ' ';
    map[a-1][b+1] = ' ';
    ++a;
    map[a][b] = obstacle;
    map[a][b+1] = obstacle;
    map[a][b-1] = obstacle;
    map[a+1][b-1] = obstacle;
    map[a+1][b+1] = obstacle;
    map[a-1][b-1] = obstacle;
    map[a-1][b+1] = obstacle;
    if(a > 20)
        {
            a = 0;
            b = rand() % 15 + 2; //use to place opposite car randomly every time game start
        }
}

void PlaceRcar()   //generates the Rcar
{
    map[n][m] = ' ';
    map[n][m+1] = ' ';
    map[n][m-1] = ' ';
    map[n+1][m] = ' ';
    map[n-1][m-1] = ' ';
    map[n-1][m+1] = ' ';
    map[n-1][m] = ' ';
    n=n+2;
    map[n][m] = Rcar;
    map[n][m+1] = Rcar;
    map[n][m-1] = Rcar;
    map[n+1][m] = Rcar;
    map[n-1][m-1] = Rcar;
    map[n-1][m+1] = Rcar;
    if(n > 20)
        {
            n = 0;
            m = rand() % 10 + 4; //use to place opposite car randomly every time game start
        }
}

//place cash
void PlaceCash()
    {
        map[q][p] = ' ';
        ++q;
        map[q][p] = cash;
        if(q > 20)
            {
                q = 0;
                p = rand() % 15 + 2;
            }
    }

////place cash
void Placeheart()
    {
        if(points%100==0 && life<6) //generate life in every 100 points
            cashApprove= true;

        if(cashApprove)
        {

            map[g][h] = ' ';
            ++g;
            map[g][h] = heart;
            if(g > 20)
                {
                    g = 0;
                    h = rand() % 15 + 2;
                    cashApprove=false;
                }
        }
    }
void getUserData()
{
    ifstream fin("higeScore.txt");
    for(int i=0;i<5;i++)
    fin >> hScore[i].name >> hScore[i].score;
}

//getHighScore
void getHighScore()  //setting high score in to the note pad
{
    ofstream SaveFile("higeScore.txt");
    system("color 0F"); //white color
    cout<<"#   #  #####  #####  #   #     #####  #####  #####  #####  ##### "<<endl;Sleep(100);
    cout<<"#   #    #    #      #   #     #      #      #   #  #   #  #     "<<endl;Sleep(100);
    cout<<"#####    #    #  ##  #####     #####  #      #   #  #####  ##### "<<endl;Sleep(100);
    cout<<"#   #    #    #   #  #   #         #  #      #   #  # #    #     "<<endl;Sleep(100);
    cout<<"#   #  #####  #####  #   #     #####  #####  #####  #   #  ##### "<<endl<<endl;Sleep(100);
    cout<<"                   Your Name ";
    cin>>playerName;

        SaveFile << playerName<<" "<<points<<endl;
        SaveFile << hScore[0].name<<" "<<hScore[0].score<<endl;
        SaveFile << hScore[1].name<<" "<<hScore[1].score<<endl;
        SaveFile << hScore[2].name<<" "<<hScore[2].score<<endl;
        SaveFile << hScore[3].name<<" "<<hScore[3].score<<endl;
}


int main()
{

    system("color 0F"); //white color

    for(;;)     //use for repeating game until user exit
    {
        getUserData();  //getting user date in to variables
        homeScreen();   //print home screen

        if (key==5) //exiting game
            return 0;

        LoadMap(); //loads the map with spaces and borders


        srand(time(0));//selecting random number using time

        points = 0;             //points that the player has earned
        int speed = 100;        //determines the speed of the obstacles (and the car)
        q = 0, p = rand() % 15 + 2; //the cash coordinates
        int cashpickedup = 0;   //counting cash pick up
        bool startup = true;
        y = 17; x = 9;          // user car coordinate
        a = 0; b = rand() % 15 + 2; //obstacles car coordinate
        n= 0; m = rand() % 10 + 4; //obstacles car coordinate
        g = 0; h = rand() % 12 + 3; //life coordinate
        life=3;

        char car = 'X';

        //SetConsoleProperties(30,20);
        //the game loop

        for(;;)
            {
                clearscreen();

                PlacesUserCar(); //places the car at its default location

                PlaceCash();    //generates the cash

                Placeheart();    //generates the heart

                PlaceOppositeCar(); //generates the obstacles


                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout<<"           life "<<life;
                cout<<endl<<endl;


                //displays the map
                for(int i=0; i < 20; ++i)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);// print as green color
                        cout<<"*** ";
                        for(int j=0; j < 20; ++j)
                        {

                            mapColor(i,j);  //use to print the map with color
                            cout << map[i][j];
                                if(j >= 19)
                                    {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);// print as green color
                                        cout <<" ***"<< endl;
                                    }
                        }
                    }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);// print as green white
                cout << "         Points: " << points + (cashpickedup*30);  // printing points

                 PlaceRcar();       //generates the heart

                //does so the game starts after a key is pressed
                if(startup)
                {
                      _getch();
                      startup = false;
                }


                //moves the car to the left
                if(GetAsyncKeyState(VK_LEFT))
                    {
                        if(map[y][x-3] != '|')
                            {
                                map[y][x] = ' ';
                                map[y][x+1] = ' ';
                                map[y][x-1] = ' ';
                                map[y+1][x-1] = ' ';
                                map[y+1][x+1] = ' ';
                                map[y-1][x-1] = ' ';
                                map[y-1][x+1] = ' ';
                                x -= 1;     //moving left side with 1 units
                                map[y][x] = 'X';
                                map[y][x+1] = 442;
                                map[y][x-1] = 442;
                                map[y+1][x-1] = 'O';
                                map[y+1][x+1] = 'O';
                                map[y-1][x-1] = 'O';
                                map[y-1][x+1] = 'O';
                            }
                    }

                //moves the car to the right
                if(GetAsyncKeyState(VK_RIGHT))
                    {

                        if(map[y][x+3] != '|')
                            {
                                map[y][x] = ' ';
                                map[y][x+1] = ' ';
                                map[y][x-1] = ' ';
                                map[y+1][x-1] = ' ';
                                map[y+1][x+1] = ' ';
                                map[y-1][x-1] = ' ';
                                map[y-1][x+1] = ' ';
                                x += 1;     //moving right side with 1 unit
                                map[y][x] = 'X';
                                map[y][x+1] = 442;
                                map[y][x-1] = 442;
                                map[y+1][x-1] = 'O';
                                map[y+1][x+1] = 'O';
                                map[y-1][x-1] = 'O';
                                map[y-1][x+1] = 'O';
                          }
                    }
                //checks if the car crashed with car
                if( map[y][x] == obstacle || map[y][x+1] == obstacle || map[y][x-1] == obstacle || map[y+1][x-1] == obstacle || map[y+1][x+1] == obstacle ||map[y-2][x-1] == obstacle || map[y-2][x+1] == obstacle || map[y-1][x] == obstacle)
                {

                    Sleep(1000);
                    --life;
                    map[a][b] = ' ';
                    map[a][b] = ' ';
                    map[a][b+1] = ' ';
                    map[a][b-1] = ' ';
                    map[a+1][b-1] = ' ';
                    map[a+1][b+1] = ' ';
                    map[a-1][b-1] = ' ';
                    map[a-1][b+1] = ' ';
                    a = 0;
                    b = rand() % 15 + 2;
                    if(life==0)
                    {
                        system("cls");
                        gameOver(); //calling game over function
                        _getch();
                        system("cls");

                        //user get High score
                        if(points>=hScore[0].score)
                            getHighScore();
                        break;
                    }


                }

                //checks if the car crashed with Raising car
                if(map[y][x] == Rcar || map[y][x+1] == Rcar || map[y][x-1] == Rcar || map[y+1][x-1] == Rcar || map[y+1][x+1] == Rcar ||map[y-1][x-1] == Rcar || map[y-1][x+1] == Rcar || map[y-1][x] == Rcar)
                {

                    Sleep(1000);
                    --life;
                    map[n][m] = ' ';
                    map[n][m+1] = ' ';
                    map[n][m-1] = ' ';
                    map[n+1][m] = ' ';
                    map[n-1][m-1] = ' ';
                    map[n-1][m+1] = ' ';
                    map[n-1][m] = ' ';
                    n = 0;
                    m = rand() % 10 + 4;
                    if(life==0)
                    {
                        system("cls");
                        gameOver(); //calling game over function
                        _getch();
                        system("cls");

                        //user get High score
                        if(points>=hScore[0].score)
                            getHighScore(); //calling getHighScore function
                        break;
                    }


                }



                //checks if the player picked up cash
                if(map[y][x] == cash || map[y][x+1] == cash || map[y][x-1] == cash || map[y+1][x-1] == cash || map[y+1][x+1] == cash ||map[y-1][x-1] == cash || map[y-1][x+1] == cash || map[y-1][x] == cash)
                    {
                        map[y-2][x] = ' ';
                        map[y-2][x-1] = ' ';
                        map[y-2][x+1] = ' ';
                        ++cashpickedup;
                        q = 0;
                        p = rand() % 15 + 2;

                    }
                //checks if the player picked up heart
                if(map[y][x]==heart || map[y][x+1]==heart || map[y][x-1]==heart || map[y+1][x-1]==heart || map[y+1][x+1]==heart ||map[y-1][x-1]==heart || map[y-1][x+1]==heart || map[y-1][x]==heart)
                    {
                        cashApprove=false;
                        map[y-2][x] = ' ';
                        map[y-2][x-1] = ' ';
                        map[y-2][x+1] = ' ';
                            ++life;
                        g = 0;
                        h = rand() % 15 + 2;

                    }

                ++points;

                //speeds up the obstacles each time the player gets another 100 points
                if(points%100==0)
                    speed =speed-25;

            Sleep(speed);
            }
            system("cls");
    }
  return 0;
}

