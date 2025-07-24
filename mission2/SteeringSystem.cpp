#pragma once

#include <string>

static const char* STEERING_SYSTEM_BOSCH = "BOSCH";
static const char* STEERING_SYSTEM_MOBIS = "MOBIS";

using namespace std;

class SteeringSystem
{
public:
	SteeringSystem() {}
	~SteeringSystem() {}

	string get() { return steeringSystem_; };

protected:
	string steeringSystem_;
};

class SteeringSystemBosch : public SteeringSystem
{
public:
	SteeringSystemBosch() { steeringSystem_ = STEERING_SYSTEM_BOSCH; }
	~SteeringSystemBosch() {}
};

class SteeringSystemMobis : public SteeringSystem
{
public:
	SteeringSystemMobis() { steeringSystem_ = STEERING_SYSTEM_MOBIS; }
	~SteeringSystemMobis() {}
};
