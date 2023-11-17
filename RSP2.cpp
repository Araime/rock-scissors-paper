#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void CreateImagesArray(string arr[])
{
    const string rock = R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)

    Rock
)";

    const string scissors = R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)

    Scissors
)";

    const string paper = R"(
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)

    Paper
)";

    arr[0] = rock;
    arr[1] = paper;
    arr[2] = scissors;
}

void PrintAnswers(int user, int computer, string arr[])
{
    cout << "Your choice: " << endl;
    cout << arr[user] << endl << endl;
    cout << "Computer choice: " << endl;
    cout << arr[computer] << endl << endl;
}

void CalculateResult(int user, int computer)
{
    if (user == 0 && computer == 2)
    {
        cout << "\x1B[92m===You win===\033[0m" << endl << endl;
    }
    else if (computer == 0 && user == 2)
    {
        cout << "\x1B[91m===You loose===\033[0m" << endl << endl;
    }
    else if (computer > user)
    {
        cout << "\x1B[91m===You loose===\033[0m" << endl << endl;
    }
    else if (user > computer)
    {
        cout << "\x1B[92m===You win===\033[0m" << endl << endl;
    }
    else if (user == computer)
    {
        cout << "===Withdraw===" << endl << endl;
    }
}

int main()
{
    // init randomizer with random seed
    srand(time(NULL));

    // init game variables
    const int SIZE = 3;
    string response_options[SIZE];
    string play_again;
    int user_choice, computer_choice;
    bool is_running = true;

    // create array of images
    CreateImagesArray(response_options);

    cout << "Greetings! This is a game Rock, Scissors, Paper!" << endl;

    // game loop
    while (is_running)
    {
        // ask user choice
        cout << "Type 0 for Rock, 1 for Paper or 2 for Scissors." << endl;
        cout << "Your choose: "; cin >> user_choice;

        // generate computer choice
        computer_choice = rand() % 3;

        // check for incorrect number input
        if (user_choice >= 3 or user_choice < 0)
        {
            cout << "You typed an invalid number!!!!!" << endl;
        }
        // determine the winner and print result
        else
        {
            PrintAnswers(user_choice, computer_choice, response_options);
            CalculateResult(user_choice, computer_choice);
        }

        // ask if user wants to play again
        cout << "Play again? y/n: "; cin >> play_again;
        if (play_again != "y")
        {
            is_running = false;
        }

        // clear console output
        system("cls");
    }
}
