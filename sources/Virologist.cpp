#include "Virologist.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Virologist::Virologist(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "Virologist";
       }

       Player& Virologist::treat(City c){
         if(this->cards.count(c)==0 && this->myCity!= c){throw invalid_argument{"cant treat in other city" };}
         if(board[c] == 0) {throw invalid_argument{"There is no diseases in this city  " };}
         if(board.DiscoverMedicine(Board::getColor(c)))
           {
              board[c] = 0;
           }
         else {board[c]--;}

         return *this;
       }

}