#pragma once

#include <string>

static const char* BRAKE_SYSTEM_MANDO = "MANDO";
static const char* BRAKE_SYSTEM_CONTINENTAL = "CONTINENTAL";
static const char* BRAKE_SYSTEM_BOSCH = "BOSCH";

using namespace std;

class BrakeSystem
{
public:
	BrakeSystem() {}
	~BrakeSystem() {}

	string get() { return brakeSystem_; }

protected:
	string brakeSystem_;
};

class BrakeSystemMando : public BrakeSystem
{
public:
	BrakeSystemMando() { brakeSystem_ = BRAKE_SYSTEM_MANDO; }
	~BrakeSystemMando() {}
};

class BrakeSystemContinental : public BrakeSystem
{
public:
	BrakeSystemContinental() { brakeSystem_ = BRAKE_SYSTEM_CONTINENTAL; }
	~BrakeSystemContinental() {}
};

class BrakeSystemBosch : public BrakeSystem
{
public:
	BrakeSystemBosch() { brakeSystem_ = BRAKE_SYSTEM_BOSCH; }
	~BrakeSystemBosch() {}
};
