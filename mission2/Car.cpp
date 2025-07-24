#pragma once

#include "CarType.cpp"
#include "Engine.cpp"
#include "BrakeSystem.cpp"
#include "SteeringSystem.cpp"

class Car
{
public:
	Car() {}
	~Car() {}
	
	void setCarType(const CarType& carType) { carType_ = carType; }
	void setEngine(const Engine& engine) { engine_ = engine; }
	void setBrakeSystem(const BrakeSystem& brakeSystem) { brakeSystem_ = brakeSystem; }
	void setSteeringSystem(const SteeringSystem& steeringSystem) { steeringSystem_ = steeringSystem; }

	string getCarType() { return carType_.get(); }
	string getEngine() { return engine_.get(); }
	string getBrakeSystem() { return brakeSystem_.get(); }
	string getSteeringSystem() { return steeringSystem_.get(); }

	bool isValidCheck()
	{
		if (!getCarType().compare(CAR_TYPE_SEDAN) && !getBrakeSystem().compare(BRAKE_SYSTEM_CONTINENTAL))
			return false;
		else if (!getCarType().compare(CAR_TYPE_SUV) && !getEngine().compare(ENGINE_TOYOTA))
			return false;
		else if (!getCarType().compare(CAR_TYPE_TRUCK) && !getEngine().compare(ENGINE_WIA))
			return false;
		else if (!getCarType().compare(CAR_TYPE_TRUCK) && !getBrakeSystem().compare(BRAKE_SYSTEM_MANDO))
			return false;
		else if (!getBrakeSystem().compare(BRAKE_SYSTEM_BOSCH) && getSteeringSystem().compare(STEERING_SYSTEM_BOSCH))
			return false;
		return true;
	}

private:
	CarType carType_;
	Engine engine_;
	BrakeSystem brakeSystem_;
	SteeringSystem steeringSystem_;
};
