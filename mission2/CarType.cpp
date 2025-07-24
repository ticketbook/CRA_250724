#pragma once

#include <string>

static const char* CAR_TYPE_SEDAN = "SEDAN";
static const char* CAR_TYPE_SUV = "SUV";
static const char* CAR_TYPE_TRUCK = "TRUCK";

using namespace std;

class CarType
{
public:
	CarType() {}
	~CarType() {}

	string get() { return carType_; };

protected:
	string carType_;
};

class CarTypeSedan : public CarType
{
public:
	CarTypeSedan() { carType_ = CAR_TYPE_SEDAN; }
	~CarTypeSedan() {}
};

class CarTypeSuv : public CarType
{
public:
	CarTypeSuv() { carType_ = CAR_TYPE_SUV; }
	~CarTypeSuv() {}
};

class CarTypeTruck : public CarType
{
public:
	CarTypeTruck() { carType_ = CAR_TYPE_TRUCK; }
	~CarTypeTruck() {}
};
