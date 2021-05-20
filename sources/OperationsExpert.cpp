#include "OperationsExpert.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
      OperationsExpert::OperationsExpert(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "OperationsExpert";
      }

      Player& OperationsExpert::build(){
         if(!board.isResearchStations(this->myCity)){
         board.buildResearchStations(this->myCity);
          }
          return *this;
      }

}

