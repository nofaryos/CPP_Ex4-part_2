#include "Medic.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Medic::Medic(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "Medic";
       }

       Player& Medic::treat(City c){
         if(this->myCity != c){throw invalid_argument{"cant treat in other city "};}
         if(board[c] == 0) {throw invalid_argument{"There is no diseases in this city " };}
           
          board[c] = 0  ;         
          return *this;
       }

      Player& Medic::drive(City c){
      Player::drive(c);
      if(board.DiscoverMedicine(Board::getColor(c))){board[c]=0;}
      return *this;

       }

      Player& Medic::fly_direct(City c) {
          Player::fly_direct(c);
          if(board.DiscoverMedicine(Board::getColor(c))){board[c]=0;}
          return *this;

      }
      Player& Medic::fly_charter(City c){
          Player::fly_charter(c);
          if(board.DiscoverMedicine(Board::getColor(c))){board[c]=0;}
          return *this;
      }
      Player& Medic::fly_shuttle(City c){
          Player::fly_shuttle(c);
          if(board.DiscoverMedicine(Board::getColor(c))){board[c]=0;}
          return *this;
      }
}
