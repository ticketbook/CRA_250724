#pragma once

#include <string>

static const char* ENGINE_GM = "GM";
static const char* ENGINE_TOYOTA = "TOYOTA";
static const char* ENGINE_WIA = "WIA";
static const char* ENGINE_BROKEN = "고장난 엔진";

using namespace std;

class Engine
{
public:
	Engine() {}
	~Engine() {}

	string get() { return engine_; };

protected:
	string engine_;
};

class EngineGm : public Engine
{
public:
	EngineGm() { engine_ = ENGINE_GM; }
	~EngineGm() {}
};

class EngineToyota : public Engine
{
public:
	EngineToyota() { engine_ = ENGINE_TOYOTA; }
	~EngineToyota() {}
};

class EngineWia : public Engine
{
public:
	EngineWia() { engine_ = ENGINE_WIA; }
	~EngineWia() {}
};

class EngineBroken : public Engine
{
public:
	EngineBroken() { engine_ = ENGINE_BROKEN; }
	~EngineBroken() {}
};
