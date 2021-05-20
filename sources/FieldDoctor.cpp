#include "FieldDoctor.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       FieldDoctor::FieldDoctor(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "FieldDoctor";
       }
       Player& FieldDoctor::treat(City c){
         if(!Board::neighboringCities(this->myCity,c) && this->myCity != c){
			 throw invalid_argument{"cant treat in other city"};
			 }
         if(board[c] == 0) {
			 throw invalid_argument{"There is no diseases in this city " };
			 }
         if(board.DiscoverMedicine(Board::getColor(c))){
           board[c] = 0;
           }
         else{
           board[c]--;
         }
         return *this;
       }
      

      }

                      
  