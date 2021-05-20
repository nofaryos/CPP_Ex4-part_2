#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>



namespace pandemic{
 class Board{
    
      static std::map<City,std::set<City>> מeighbors ;
      std::map<City,int> diseases;
      std::set<City> researchStations;
      std::set<Color> medicane;
     
     public: 
      Board();
      int& operator[](City city);
      friend std::ostream& operator<<(std::ostream& output,const Board& board);
      bool is_clean();
      void remove_cures(){medicane.clear();};
      void remove_stations(){researchStations.clear();};

      static bool neighboringCities(City& city_1, City& city_2);
      bool isResearchStations(City c);
      void buildResearchStations(City c);
      static bool citizesInSameColor(City city, Color color);
      static Color getColor(City c);
      void addMedicine(Color c);
      bool DiscoverMedicine(Color c);


 };
}