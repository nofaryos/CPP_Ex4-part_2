#include "Board.hpp"
#include "City.hpp"
#include <iostream>

using namespace std;

namespace pandemic{
    
    Board::Board(){}

    int& Board::operator[](City city){
        return diseases[city];
        }

    bool Board::is_clean(){
        for (auto& i : this->diseases){
            if (i.second > 0) {return false;}
    
        }
        return true;

    }
    ostream& operator<<(ostream& output,const Board& board){
        output << "The level of disease in each of the cities:" << endl;
        for (const auto& i : board.diseases){
            output << "City: " << ToStringCity(i.first) << "level of disease:" << i.second << endl;
        }

        output << "The number of research stations:" << endl;
            for (const auto& i : board.researchStations){
                output << ToStringCity(i) << endl;
            }
        
        output << "The number of medicanes:" << endl;
            for(const auto& i : board.medicane){
                output << ToStringColor(i) << endl;
            }

        return output;
        }

    bool Board::neighboringCities(City& city_1,City& city_2){
        return (מeighbors.at(city_1).count(city_2)!=0);
        }

    bool Board::isResearchStations(City c){
        return (researchStations.count(c) !=0 );
    
    }

    void Board::buildResearchStations(City c){
      researchStations.insert(c);
    }

    bool Board::citizesInSameColor(City city, Color color){
        return(citiesColors.at(city) == color);

    }

    Color Board::getColor(City c){
        return citiesColors.at(c);

    }

    bool Board::DiscoverMedicine(Color c) {
        return (medicane.count(c) != 0);
    }

    void Board::addMedicine(Color c){
        medicane.insert(c);
      }

        map<City,set<City>> Board::מeighbors{
        {Algiers,{Madrid,Paris,Istanbul,Cairo}},
        {Atlanta,{Chicago, Miami, Washington}},
        {Baghdad,{Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok,{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing,{Shanghai, Seoul}},
        {Bogota,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires,{Bogota, SaoPaulo}},
        {Cairo,{Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai,{Mumbai, Delhi,Kolkata, Bangkok ,Jakarta}},
        {Chicago ,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi,{Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity,{Jakarta, Bangkok, HongKong, Manila}},
        {HongKong,{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul,{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta,{Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg,{Kinshasa, Khartoum}},
        {Karachi,{Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum,{Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa,{Lagos, Khartoum, Johannesburg}},
        {Kolkata,{Delhi ,Chennai, Bangkok, HongKong}},
        {Lagos,{SaoPaulo ,Khartoum ,Kinshasa}},
        {Lima,{MexicoCity ,Bogota, Santiago}},
        {London,{NewYork ,Madrid, Essen, Paris}},
        {LosAngeles,{SanFrancisco, Chicago ,MexicoCity, Sydney}},
        {Madrid,{London, NewYork, Paris ,SaoPaulo, Algiers}},
        {Manila,{Taipei ,SanFrancisco, HoChiMinhCity ,Sydney, HongKong}},
        {MexicoCity,{LosAngeles ,Chicago, Miami, Lima, Bogota}},
        {Miami,{Atlanta, MexicoCity, Washington ,Bogota}},
        {Milan,{Essen ,Paris, Istanbul}},
        {Montreal,{Chicago, Washington, NewYork}},
        {Moscow,{StPetersburg, Istanbul, Tehran}},
        {Mumbai,{Karachi, Delhi ,Chennai}},
        {NewYork,{Montreal, Washington, London, Madrid}},
        {Osaka,{Taipei, Tokyo}},
        {Paris,{Algiers, Essen, Madrid ,Milan, London}},
        {Riyadh,{Baghdad, Cairo, Karachi}},
        {SanFrancisco ,{LosAngeles ,Chicago, Tokyo, Manila}},
        {Santiago,{Lima}},
        {SaoPaulo ,{Bogota, BuenosAires, Lagos ,Madrid}},
        {Seoul,{Beijing ,Shanghai, Tokyo}},
        {Shanghai,{Beijing ,HongKong, Taipei, Seoul ,Tokyo}},
        {StPetersburg,{Essen, Istanbul, Moscow}},
        {Sydney,{Jakarta, Manila, LosAngeles}},
        {Taipei,{Shanghai ,HongKong, Osaka, Manila}},
        {Tehran,{Baghdad ,Moscow, Karachi ,Delhi}},
        {Tokyo,{Seoul, Shanghai ,Osaka ,SanFrancisco}},
        {Washington,{Atlanta, NewYork,Montreal, Miami}}
    };  

}