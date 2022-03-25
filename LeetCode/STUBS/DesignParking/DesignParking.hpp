// https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
	int m_carSpace[4] = {0, 0, 0, 0};
	
	ParkingSystem(int big, int medium, int small) {
		m_carSpace[1] = big;
		m_carSpace[2] = medium;
		m_carSpace[3] = small;   
	}
	
	bool addCar(int carType) {
		if (m_carSpace[carType]) {
			m_carSpace[carType]--;
			return true;
		}
		return false;
	}
	
	
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */