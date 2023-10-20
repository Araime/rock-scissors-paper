#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    srand(time(NULL));

    const char* rock = R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)

    Rock
)";

    const char* scissors = R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)

    Scissors
)";

    const char* paper = R"(
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)

    Paper
)";

    cout << rock << endl << endl;
    cout << paper << endl << endl;
    cout << scissors << endl << endl;
}
