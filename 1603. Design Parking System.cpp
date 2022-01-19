// 1603. Design Parking System

class ParkingSystem {
private:
    int big, medium, small; 
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && big == 0 || carType == 2 && medium == 0 || carType == 3 && small == 0)
        {
            return false;
        }
        
        if(carType == 1)
            big--;
        if(carType == 2)
            medium--;
        if(carType == 3)
            small--;
        return true;
    }
};


/*
class ParkingSystem {
public:
    vector <int> parkingLot;
    ParkingSystem(int big, int medium, int small) {
        parkingLot = {big, medium, small};

    }
    
    bool addCar(int carType) {
        return parkingLot[carType-1]-- > 0;
    }
};
*/
