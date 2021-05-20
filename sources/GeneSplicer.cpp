#include "GeneSplicer.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
const int NUM_C = 5;
using namespace std;

namespace pandemic{  
      

       GeneSplicer::GeneSplicer(Board& b , City c): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->roleOfPlayer = "GeneSplicer";
      }


      Player& GeneSplicer::discover_cure(Color c) {
         set<City> cardsToerase;
         if(board.isResearchStations(this->myCity))
         {
           if(!board.DiscoverMedicine(c))
           {
            for(const auto& i :this->cards)
            {
              cardsToerase.insert(i); 
              if(cardsToerase.size() == NUM_C) {break;}
            }

              if(cardsToerase.size() == NUM_C) 
              {
                  board.addMedicine(c);
              }
              else{throw invalid_argument{"You do not have enough cards in the suitable color "};}

              for(const auto& i : cardsToerase)
              {
                this->cards.erase(i);
              }
        }
      }
        
         else{throw invalid_argument{"There is no research station in this city"};}

          return *this;
      }

}