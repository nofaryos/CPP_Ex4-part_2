#include "Researcher.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
const int NUM_C = 5;
using namespace std;

namespace pandemic{  
      
       Researcher::Researcher(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "Researcher";
      
      } 

      Player& Researcher::discover_cure(Color c) {
              set<City> cardsToerase;
              if(!board.DiscoverMedicine(c))
              {
              for(const auto& i : this->cards)
              {
                     if(Board::citizesInSameColor(i,c))
                     {
                     cardsToerase.insert(i);  
                     } 
                     if(cardsToerase.size() == NUM_C) {break;}
              }

              if(cardsToerase.size() == NUM_C)
              {
                     board.addMedicine(c);

              }
              else{throw invalid_argument{"There is no enough cards "};}

              for(const auto& i : cardsToerase)
              {
                     this->cards.erase(i);
              }
              }

              return *this;
       }
       
}