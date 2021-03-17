#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

int Random(int low, int high);
int main()
{
  srand(time(0));
  int rand1{}, rand2{}, rand3{};
  int choice;
  int chips{1000};
  int bet{};
  do{
    std::cout << "Player's chips: $" << chips << '\n';
    std::cout << "1) Play slot. 2) Exit. ";
    std::cin >> choice;
    switch (choice){
      case 1:{
          while (true){
            std::cout << "Enter your bet: ";
            std::cin >> bet;
            if (bet > chips || bet <= 0)
            std::cout << "You did not enter a valid bet." << '\n';
            else
            break;
          }
          rand1 = Random(2, 7);
          rand2 = Random(2, 7);
          rand3 = Random(2, 7);
          bool seven = rand1 == 7 && rand2 == 7 && rand3 == 7;
          bool three = !seven && (rand1 == rand2 && rand1 == rand3 && rand2 == rand3);
          bool two   = (rand1 == rand2) || (rand1 == rand3) || (rand2 == rand3);
          std::cout << rand1 << " " << rand2 << " " << rand3 << '\n';
          if (seven) {
            chips += bet * 10;
            std::cout << "You win!" << '\n';
          }
          else if (three) {
            chips += bet * 5;
            std::cout << "You win!" << '\n';
          }
          else if (two){
            chips += bet * 3;
            std::cout << "You win" << '\n';
          }
          else
          chips -= bet;
        }break;
      case 2:
        std::cout << "Exiting..." << '\n';
        break;
    }
    if (chips <= 0)
    break;
  }while (choice != 2);
  if (chips <= 0) {
    std::cout << "You lost all your points" << '\n';
  }
  return 0;
}
int Random(int low, int high){
  int random = low + rand() % ((high + 1) - low);
  return random;
}
