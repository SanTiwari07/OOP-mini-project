#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <vector>

using namespace std;

map<string, float> user_scores;

class user
{
protected:
    string name;
    int value_enter = 0;

public:
    static float points;

    void intro()
    {
        cout << "Please enter your name: ";
        cin >> name;

        ifstream infile("scores.txt");
        string stored_name;
        float stored_points;

        bool found = false;

        while (infile >> stored_name >> stored_points)
        {
            if (stored_name == name)
            {
                found = true;
                break;
            }
        }

        infile.close();

        if (found)
        {
            int choice;
            cout << "Welcome back, " << name << "! We found your previous score.\n";
            cout << "Do you want to continue with your previous score of " << stored_points << "? (1 for Yes, 2 for No): ";
            cin >> choice;

            if (choice == 1)
            {
                points = stored_points;
                cout << "Continuing with previous points: " << points << endl;
            }
            else
            {
                points = 1000;
                cout << "Starting fresh. Your points: " << points << endl;
            }
        }
        else
        {
            cout << "Hello, " << name << "! New user created.\n";
            points = 1000;
        }
    }

    void enter_value()
    {
        cout << "Disclaimer: If you win, you can increase your points or else you might lose your points.\n\n";
        cout << "Enter points to play: ";
        cin >> value_enter;
        while (value_enter > points)
        {
            cout << "Are you kidding me! You have " << points << " points.\n";
            cout << "Please enter valid number between 0 and " << points << ": ";
            cin >> value_enter;
        }
    }

    string get_name() const { return name; }

    void save_score()
    {
        map<string, float> all_scores;
        ifstream infile("scores.txt");
        string stored_name;
        float stored_score;

        while (infile >> stored_name >> stored_score)
        {
            all_scores[stored_name] = stored_score;
        }
        infile.close();

        all_scores[name] = points;

        ofstream outfile("scores.txt");
        for (auto &pair : all_scores)
        {
            outfile << pair.first << " " << pair.second << endl;
        }
        outfile.close();
    }
};

float user::points = 1000;

// Number Guesser Game
class number_guesser : public user
{
public:
    int number;
    int random;
    int counter = 1;

    void number_rules()
    {
        cout << "Hello! Welcome to number guesser.\n";
        cout << "Guess a number between 0 and 100 within 8 turns.\n";
    }

    void number_generator()
    {
        random_device rd;
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(0, 100);
        random = dis(gen);
    }

    void number_guess()
    {
        for (int a = 1; a <= 8; a++)
        {
            cout << "Enter your guess number " << a << ": ";
            cin >> number;
            if (number < random)
            {
                cout << "Please enter a larger number.\n";
                counter++;
            }
            else if (number > random)
            {
                cout << "Please enter a smaller number.\n";
                counter++;
            }
            else
            {
                cout << "You won!\n";
                break;
            }

            if (counter == 9)
            {
                cout << "You Lost!\n";
                break;
            }
        }
    }

    void point_distri()
    {
        int multiplier[] = {0, 10, 8, 6, 4, 3, 2, 1, 0};
        cout << "You " << multiplier[counter <= 8 ? counter : 8] << "x your point.\n";
        points += multiplier[counter <= 8 ? counter : 8] * value_enter;
        cout << "Your points: " << points << endl;
    }
};

// Minesweeper Game
class minesweeper_4x4 : public user
{
public:
    float count = -1;
    int random_number_1[5];
    int random_number_2[5];

    void game_rule()
    {
        cout << "This is minesweeper inspired game (4x4 grid, max 5 mines).\n";
        cout << "Avoid mines. Earn 1.75x per safe move. Exit anytime with 10 points.\n";
        cout << "Enter 0 0 to exit.\n";
    }

    void game_weep()
    {
        int row, column;
        random_device rd;
        mt19937 gen(time(0));
        char grid[4][4];
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 4; b++)
                grid[a][b] = ' ';

        for (int a = 0; a < 5; a++)
        {
            uniform_int_distribution<> dis(0, 3);
            random_number_1[a] = dis(gen);
            random_number_2[a] = dis(gen);
        }

        int step_counter = 0;
        do
        {
            cout << "Enter Row: ";
            cin >> row;
            cout << "Enter Column: ";
            cin >> column;

            if (row == 0 && column == 0)
            {
                cout << "You earned 10 more points.\n";
                points += 10;
                break;
            }
            else if (grid[row - 1][column - 1] == 'R')
            {
                cout << "You have already used this coordinate.\n";
            }
            else
            {
                bool is_mine = false;
                for (int a = 0; a < 5; a++)
                {
                    if (random_number_1[a] == row - 1 && random_number_2[a] == column - 1)
                    {
                        grid[row - 1][column - 1] = 'x';
                        step_counter = 1;
                        is_mine = true;
                        break;
                    }
                }
                if (!is_mine)
                {
                    grid[row - 1][column - 1] = 'R';
                    count++;
                }
            }

            for (int a = 0; a < 4; a++)
            {
                for (int b = 0; b < 4; b++)
                    cout << "| " << grid[a][b] << " ";
                cout << "|\n";
            }

        } while (step_counter == 0);
    }

    void calculation_sweep()
    {
        cout << "You earned " << 1.75 * count << " points.\n";
        points += 1.75 * count;
        cout << "Your points: " << points << endl;
    }
};

// Play Point Game
class play_point : public user
{
public:
    int sample[3];
    int sum = 0;
    int guess_play_point;

    void play_point_intro()
    {
        cout << "Play Point: Roll 3 dice and guess the sum.\n";
        cout << "Exact = 5x, ±1 = 2x, ±2 = 0x, else -2x\n";
    }

    void play_point_calculation()
    {
        random_device rd;
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(1, 6);
        sum = 0;

        for (int a = 0; a < 3; a++)
        {
            sleep(1);
            sample[a] = dis(gen);
            cout << "Dice " << a + 1 << " = " << sample[a] << endl;
            sum += sample[a];
        }
    }

    void input_play_point()
    {
        cout << "Enter your guess (3 to 18): ";
        while (true)
        {
            cin >> guess_play_point;
            if (guess_play_point >= 3 && guess_play_point <= 18)
                break;
            cout << "Invalid input. Try again: ";
        }
    }

    void point_table()
    {
        if (guess_play_point == sum)
        {
            cout << "You won 5x points\n";
            points += 5 * value_enter;
        }
        else if (guess_play_point == sum - 1 || guess_play_point == sum + 1)
        {
            cout << "You won 2x points\n";
            points += 2 * value_enter;
        }
        else if (guess_play_point == sum - 2 || guess_play_point == sum + 2)
        {
            cout << "No points won\n";
        }
        else
        {
            cout << "You lost 2x points\n";
            points -= 2 * value_enter;
        }
        cout << "Your points: " << points << endl;
    }
};

// Coin Flip Game
class coin_filp : public user
{
private:
    int num;
    int random_num;

public:
    void rules_coin()
    {
        cout << "Coin Flip: Guess 1 for Heads or 2 for Tails.\n";
    }

    void coin_input()
    {
        cout << "Enter your guess (1=Heads, 2=Tails): ";
        cin >> num;
    }

    void random_answer()
    {
        random_device rd;
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(1, 2);
        random_num = dis(gen);
    }

    void result_check()
    {
        if (num == random_num)
        {
            cout << "You WON! +2x\n";
            points += 2 * value_enter;
        }
        else
        {
            cout << "You LOST! -" << value_enter << " points\n";
            points -= value_enter;
        }
        cout << "Your points: " << points << endl;
    }
};

int main()
{
    user s1;
    s1.intro();
    int option;

    while (true)
    {
        cout << "\nWelcome To GAME World:\n";
        cout << "0 - Exit\n1 - Number Guesser\n2 - Minesweeper\n3 - Play Point\n4 - Coin Flip\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 0)
        {
            s1.save_score();
            cout << "Thanks for playing! Final points: " << user::points << endl;
            break;
        }

        switch (option)
        {
        case 1:
        {
            number_guesser g1;
            g1.number_rules();
            g1.enter_value();
            g1.number_generator();
            g1.number_guess();
            g1.point_distri();
            break;
        }
        case 2:
        {
            minesweeper_4x4 m1;
            m1.game_rule();
            m1.game_weep();
            m1.calculation_sweep();
            break;
        }
        case 3:
        {
            play_point p1;
            p1.play_point_intro();
            p1.enter_value();
            p1.input_play_point();
            p1.play_point_calculation();
            p1.point_table();
            break;
        }
        case 4:
        {
            coin_filp c1;
            c1.rules_coin();
            c1.enter_value();
            c1.coin_input();
            c1.random_answer();
            c1.result_check();
            break;
        }
        default:
            cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}
