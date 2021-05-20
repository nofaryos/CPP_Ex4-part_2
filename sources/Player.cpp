#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
#include <string>
#include <set>
const int cardsToCure = 5;
using namespace std;


namespace pandemic{

       Player& Player::drive(City c){
         if(this->myCity == c){
			 throw invalid_argument{"cant fly from city to itself"};
			}
         if(!(Board::neighboringCities(this->myCity,c))){
			throw std::invalid_argument{"The cities are not neighboring "};
         }
          this->myCity = c;
          return *this;        
       }

       Player& Player::fly_direct(City c){
              if(this->myCity == c){
				  throw invalid_argument{"cant fly from city to itself"};
				 }
              if (cards.count(c) == 0)
              {
				throw invalid_argument{"There is no suitable city card "};
              }
              this->myCity = c;
              cards.erase(c); 
              return *this; 
            
           }

       

       Player& Player::fly_charter(City c){
              if(this->myCity == c){
				  throw invalid_argument{"cant fly from city to itself"};
				 }
              if (cards.count(this->myCity) == 0)
              {
				throw invalid_argument{"There is no suitable city card "}; 
   
              }
               cards.erase(this->myCity);  
               this->myCity = c;
               return *this;
              
              }


       Player& Player::fly_shuttle(City c){
            if(this->myCity == c){
				throw invalid_argument{"cant fly from city to itself"};
			}
              if(board.isResearchStations(this->myCity) && board.isResearchStations(c)){
                 this->myCity = c;
                 return *this;
              }
              
                throw invalid_argument{"There is no Research Stations in the cities"};
  
              }
       

       Player& Player::treat(City c){
           if(this->myCity != c){
			   throw invalid_argument{"cant treat in other city "};
			 }
           if(board[c] == 0) {
			   throw invalid_argument{"There is no diseases in this city " };
			 }
           if(board.DiscoverMedicine(Board::getColor(c)))
           {
              board[c] = 0;
           }
           else {
			   board[c]--;
			}

         return *this;
         }
       

       Player& Player::take_card(City c){
         cards.insert(c);
         return *this;
         }
       
       Player& Player::build(){
         if(cards.count(this->myCity) != 0){
			if(!board.isResearchStations(this->myCity)){
				board.buildResearchStations(this->myCity);
				cards.erase(this->myCity);
			}
         }
         else{
			 throw invalid_argument{"There is no suitable city card " };
			 }
         return *this;
       }
       

       Player& Player::discover_cure(Color c){
         set<City> cardsToErase;
         if(board.isResearchStations(this->myCity))
           {
            if(!board.DiscoverMedicine(c))
            {
              for(const auto& i :this->cards)
              {
                    if(Board::citizesInSameColor(i,c))
                    {
                      cardsToErase.insert(i);  
                    } 
                    if(cardsToErase.size() == cardsToCure) {break;}
              }

                if(cardsToErase.size() == cardsToCure) 
                {
                  board.addMedicine(c);

                }

                else{throw invalid_argument{"There is no enough cards"};}

                for(const auto& i : cardsToErase)
                {
                  this->cards.erase(i);
                }
            }
          }

         else{throw invalid_argument{"There is no research station in this city"};}

        return *this;
       }

       string Player::role(){
          return this->roleOfPlayer;
         }
}