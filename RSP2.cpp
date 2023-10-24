#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void CreateArray(string arr[])
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

void PrintResponse(int user, int computer, string arr[])
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
        cout << "===You win===" << endl << endl;
    }
    else if (computer == 0 && user == 2)
    {
        cout << "===You loose===" << endl << endl;
    }
    else if (computer > user)
    {
        cout << "===You loose===" << endl << endl;
    }
    else if (user > computer)
    {
        cout << "===You win===" << endl << endl;
    }
    else if (user == computer)
    {
        cout << "===Withdraw===" << endl << endl;
    }
}

int main()
{
    srand(time(NULL));

    const int SIZE = 3;
    string response_options[SIZE];
    string choice;
    int user_choice, computer_choice;
    bool is_running = true;

    CreateArray(response_options);

    while (is_running)
    {
        cout << "Type 0 for Rock, 1 for Paper or 2 for Scissors." << endl;
        cout << "Your choose: "; cin >> user_choice;
        computer_choice = rand() % 3;

        if (user_choice >= 3 or user_choice < 0)
        {
            cout << "You typed an invalid number!!!!!" << endl;
        }
        else
        {
            PrintResponse(user_choice, computer_choice, response_options);
            CalculateResult(user_choice, computer_choice);
        }

        cout << "Play again? y/n: "; cin >> choice;
        if (choice != "y")
        {
            is_running = false;
        }
    }
}
