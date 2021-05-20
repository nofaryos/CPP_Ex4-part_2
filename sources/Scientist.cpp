#include "Scientist.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
      Scientist::Scientist(Board& b , City c, int n): Player(b,c){
            this->board = b;
            this->myCity = c;
            this->num = n;
            this->roleOfPlayer = "Scientist";
      
      } 

      Player& Scientist::discover_cure(Color c) {
         set<City> cardsToerase;
         if(board.isResearchStations(this->myCity))
         {
           if(!board.DiscoverMedicine(c))
           {
            for(const auto& i :this->cards)
            {
                  if(Board::citizesInSameColor(i,c))
                  {
                    cardsToerase.insert(i);  
                  } 
                  if(cardsToerase.size() == this->num) {break;}
            }

              if(cardsToerase.size() == this->num) 
              {
                  board.addMedicine(c);
              }
              else{
				  throw invalid_argument{"You do not have enough cards in the suitable color "};
				  }

              for(const auto& i : cardsToerase)
              {
                this->cards.erase(i);
              }
        }
      }
        
         else{
			 throw invalid_argument{"There is no research station in this city"};
			 }

          return *this;
      }
      

}
