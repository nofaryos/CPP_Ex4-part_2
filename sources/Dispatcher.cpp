#include "Dispatcher.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Dispatcher::Dispatcher(Board& b , City c): Player(b,c){
              this->myCity = c;
              this->roleOfPlayer = "Dispatcher";
       }

       Player& Dispatcher::fly_direct(City c) {
              if(this->myCity == c){
				  throw std::invalid_argument{"cant fly from city to itself"};
				  }
              if(board.isResearchStations(this->myCity))
              {
                this->myCity = c;
                return *this;
              }
              
              return Player::fly_direct(c);
              
              }

       }      
