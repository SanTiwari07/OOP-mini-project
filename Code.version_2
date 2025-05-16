#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <stdexcept>
#include <fstream>

using namespace std;
float points = 1000;

// class made to collect user data and more
class user
{
public:
    string name;

protected:
    int value_enter = 0;

public:
    // collecting user detail.
    void intro()
    {
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << endl
             << "Hello, " << name << "!\n\n";
    }
    // points to be taken from user to play.
    void enter_value()
    {
        int chaker;
        cout << "Disclaimer: If you win, you can increase your points or else you might lose your points.\n\n";
        cout << "Enter points to play: ";
        cin >> value_enter;

        try
        {
            if (cin.fail())
            {
                throw invalid_argument("Invalid data Type.\n");
            }
        }
        catch (const char *e)
        {
            cout << "Error: " << e << endl;
        }

        int checker = 0;
        do
        {
            if (value_enter > points)
            {
                cout << "Are you kidding me ! You have " << points;
                cout << endl
                     << "Please enter valid number between 0 and " << points;
                cout << endl
                     << endl
                     << "Enter again: ";
                cin >> value_enter;
                checker = 1;
            }
            else
            {
                checker = 0;
                break;
            }
        } while (checker == 1);
    }
};
// Number guess game
// this class is a child class of user class.
class number_guesser : public user
{
public:
    int number;
    int random;
    int counter = 1;
    // Rules for number guesser game.
    void number_rules()
    {
        cout << "Hello! Welcome to number guesser.\n";
        cout << "This is a game to guess-by logical and analytical thinking\n";
        cout << "Make sure you guess wisely\n";
        cout << "Try to guess within 8 turns and guess between 0 to 100\nAll the best!!\n\n";
    }
    // random number generator for the game.
    void number_generator()
    {
        random_device rd;
        mt19937 gen(time(0));

        uniform_int_distribution<> dis(0, 100);
        random = dis(gen);
    }
    // guess counting part
    void number_guess()
    {

        for (int a = 1; a <= 8; a++)
        {
            cout << "Enter your guess number " << a << ": ";
            cin >> number;
            try
            {
                if (cin.fail())
                {
                    throw invalid_argument("Invalid Data Type.\n");
                }
            }
            catch (const char *e)
            {
                cout << "Error: " << e << endl;
            }

            if (number < random)
            {
                cout << "Please enter larger number.\n";
                counter++;
            }
            else if (number > random)
            {
                cout << "Please enter smaller number\n";
                counter++;
            }
            else
            {
                cout << "You won!";
                break;
            }

            if (counter == 9)
            {
                cout << "You Lost!\n";
                break;
            }
        }
    }
    // points distribution as per result.

    void point_distri()
    {
        if (counter == 1)
        {
            cout << "You 10x your point.\n";
            points += 10 * value_enter;
        }
        else if (counter == 2)
        {
            cout << "You 8x your point.\n";
            points += 8 * value_enter;
        }
        else if (counter == 3)
        {
            cout << "You 6x your point.\n";
            points += 6 * value_enter;
        }
        else if (counter == 4)
        {
            cout << "You 4x your point.\n";
            points += 4 * value_enter;
        }
        else if (counter == 5)
        {
            cout << "You 3x your point.\n";
            points += 3 * value_enter;
        }
        else if (counter == 6)
        {
            cout << "You 2x your point.\n";
            points += 2 * value_enter;
        }
        else if (counter == 7)
        {
            cout << "You 1x your point.\n";
            points += 1 * value_enter;
        }
        else
        {
            cout << "You won 0x point.\n";
            points += 0 * value_enter;
        }
        cout << endl
             << "Your points: " << points << endl;
    }
};
// minesweeper inspired game.
// Inherited from user class.
class minesweeper_4x4 : public user
{
public:
    float count = -1;
    int random_number_1[5];
    int random_number_2[5];

    // rules for MIS
    void game_rule()
    {
        cout << "This is minesweeper inspired game.\n";
        cout << "It has 4x4 grid.\n";
        cout << "You need to save yourself from mines (max 5).\n";
        cout << "for each save you will get 1.75x points.\n\n";
        cout << "You can exit as per your wish and earn 10 more points\n";
        cout << endl
             << "To enter coordinate enter in following ways:\nRow: 1 (ie first row)\nColumn: 1 (ie First Column).\nEnter 0 0 for exit\n";
    }

    // logical part of the game
    void game_weep()
    {
        int row, column;
        random_device rd;
        mt19937 gen(time(0));
        char grid[4][4];
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                grid[a][b] = ' ';
            }
        }

        for (int a = 0; a < 5; a++)
        {

            uniform_int_distribution<> dis(0, 3);
            random_number_1[a] = dis(gen);
        }
        for (int a = 0; a < 5; a++)
        {

            uniform_int_distribution<> dis(0, 3);
            random_number_2[a] = dis(gen);
        }
        int step_counter = 0;
        do
        {

            int row_handler = 1;
            do
            {
                cout << "Enter Row: ";
                cin >> row;
                try
                {
                    if (cin.fail())
                    {
                        throw invalid_argument("Invalid Data Type.\n");
                    }
                }
                catch (const char *e)
                {
                    cout << "Error: " << e << endl;
                }

                if (row <= 4 && row >= 0)
                {
                    row_handler = 1;
                }
                else
                {
                    cout << "please Enter again!\n";
                    row_handler = 0;
                }
            } while (row_handler == 0);

            int col_handler = 0;
            do
            {
                cout << "Enter Column: ";
                cin >> column;
                try
                {
                    if (cin.fail())
                    {
                        throw invalid_argument("Invalid Data Type.\n");
                    }
                }
                catch (const char *e)
                {
                    cout << "Error: " << e << endl;
                }
                if (column <= 4 && column >= 0)
                {
                    col_handler = 1;
                }
                else
                {
                    cout << "please Enter again!\n";
                    col_handler = 0;
                }
            } while (col_handler == 0);

            if (row == 0 && column == 0)
            {
                step_counter = 1;
                cout << endl
                     << "You earned 10 more points." << endl;
                points += 10;
            }
            else
            {
                if (grid[row - 1][column - 1] == 'R')
                {
                    cout << "You have Used this coordinate.\n\nEnter other coordinate.\n";
                }
                else
                {
                    for (int a = 0; a < 5; a++)
                    {
                        if (random_number_1[a] == row - 1 && random_number_2[a] == column - 1)
                        {
                            grid[row - 1][column - 1] = 'x';
                            step_counter = 1;
                            break;
                        }
                        else
                        {
                            grid[row - 1][column - 1] = 'R';
                            step_counter = 0;
                        }
                    }
                }
            }

            for (int a = 0; a < 4; a++)
            {
                for (int b = 0; b < 4; b++)
                {
                    cout << "| " << grid[a][b] << " ";
                }
                cout << "|" << endl;
            }

            count++;
        } while (step_counter == 0);
    }

    // points distribution
    void calculation_sweep()
    {
        cout << "You earned ";
        cout << 1.75 * count;
        points += 1.75 * count;
        cout << endl
             << "Your points are " << points;
    }
};

// Play point game(dice).
// it is inherited from user class.
class play_point : public user
{
public:
    int sample[3];

    int sum = 0;
    int guess_play_point;

    // rules for play point
    void play_point_intro()
    {
        cout << "Hello Chief ! This is play_point game.\nHere you need to roll dice 3 times and guess the sum of all 3 dices.\n\n";
        cout << "Example- If sum of all 3 dice is 13-\n5x points if you guess 13\n2x points if you guess 12 or 14\nNo points loss if you guess 11 or 15\nOther guess will lead to loss in points by 2x\n\n";
    }

    // logic for play point game
    void play_point_calculation()
    {
        random_device rd;
        mt19937 gen(time(0));
        for (int a = 0; a < 3; a++)
        {
            sample[a] = 0;
        }

        for (int a = 0; a < 3; a++)
        {
            sleep(1);
            uniform_int_distribution<> dis(1, 6);
            sample[a] = dis(gen);
        }
        for (int a = 0; a < 3; a++)
        {
            cout << "Result of Dice " << a + 1 << " is " << sample[a] << endl;
        }

        for (int a = 0; a < 3; a++)
        {
            sum += sample[a];
        }
    }

    // taking user input and also checking whether it is between 3 to 18
    void input_play_point()
    {
        cout << endl
             << "Enter number to guess (between 3 to 18): ";

        int checkker = 0;
        do
        {
            cin >> guess_play_point;
            try
            {
                if (cin.fail())
                {
                    throw invalid_argument("Invalid Data Type.\n");
                }
            }
            catch (const char *e)
            {
                cout << "Error: " << e << endl;
            }
            if (3 <= guess_play_point && guess_play_point <= 18)
            {
                checkker = 0;
            }
            else
            {
                cout << "Enter valid number between 3 to 18: ";
                checkker = 1;
            }
        } while (checkker == 1);
    }

    // point distribution for game
    void point_table()
    {
        if (guess_play_point == sum)
        {
            cout << "You won 5x points\n";
            points = points + 5 * value_enter;
            cout << "Your points: " << points;
        }
        else if (guess_play_point == sum - 1 || guess_play_point == sum + 1)
        {
            cout << "You won 2x points\n";
            points = points + 2 * value_enter;
            cout << "Your points: " << points;
        }
        else if (guess_play_point == sum - 2 || guess_play_point == sum + 2)
        {
            cout << "You won no points\n";
            points = points;
            cout << "Your points: " << points;
        }
        else
        {
            cout << "You lost 2x points\n";
            points = points - 2 * value_enter;
            cout << "Your points: " << points;
        }
    }
};
// coin filp game
// Inherited from user class
class coin_filp : public user
{
private:
    int num;
    int random_num;

public:
    // Basic intro of the game
    void rules_coin()
    {
        cout << "Hello Sir! I am your Assistant,Welcome to filp a coin.";
        cout << endl;
    }
    // Rules of the game
    void coin_input()
    {
        cout << "please select-\n1 for Heads\n2 for Tails\n\nEnter number :";
        cin >> num;
        try
        {
            if (cin.fail())
            {
                throw invalid_argument("Invalid Data Type.\n");
            }
        }
        catch (const char *e)
        {
            cout << "Error: " << e << endl;
        }
    }
    void random_answer()
    {
        random_device rd;
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(1, 2);
        random_num = dis(gen);
        cout << random_num << endl;
    }
    // result checker and point distribution
    void result_check()
    {
        if (num == random_num)
        {
            cout << "Hurrah!! You WON\n";
            points = points + 2 * value_enter;
            cout << "Your points: " << points;
        }
        else
        {
            cout << "Sorry, better luck next time...\n";
            points -= value_enter;
            cout << "Your points: " << points;
        }
    }
};

int main()
{
    fstream file("data_player.txt", ios::in | ios::out | ios::app);

    if (!file.is_open())
    {
        cerr << "Error opening." << endl;
        return 1;
    }

    user s1;
    s1.intro();
    int option;

    int a = 0;
    do
    {
        cout << endl
             << "Welcome To GAME World, where you can play-\n0 - To exit\n1 - Number Guesser\n2 - minesweeper\n3 - play point\n4 - coin filp\n";
        do
        {
            cout
                << endl
                << "Enter valid option between 0 to 4 to play: ";
            cin >> option;

            try
            {
                if (cin.fail())
                {
                    throw invalid_argument("Invalid Data Type.\n");
                }
            }
            catch (const char *e)
            {
                cout << "Error: " << e << endl;
            }
            cout << endl;
        } while (option > 4 || option < 0);
        if (option == 0)
        {
            cout << "Thanks for playing.";
            file << s1.name << " - " << points << endl;
            a = 1;
        }
        else
        {
            if (option == 4)
            {
                coin_filp c1;
                c1.rules_coin();
                c1.enter_value();
                c1.coin_input();
                c1.random_answer();
                c1.result_check();
            }
            else if (option == 3)
            {
                play_point p1;
                p1.play_point_intro();
                p1.enter_value();
                p1.input_play_point();
                p1.play_point_calculation();
                p1.point_table();
            }
            else if (option == 2)
            {
                minesweeper_4x4 m1;
                m1.game_rule();
                m1.game_weep();
                m1.calculation_sweep();
            }
            else if (option == 1)
            {
                number_guesser n1;
                n1.number_rules();
                n1.enter_value();
                n1.number_generator();
                n1.number_guess();
                n1.point_distri();
            }
            a = 0;
        }
    } while (a == 0);

    file.close();
    return 0;
}
