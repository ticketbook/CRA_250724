#include "gmock/gmock.h"

#include "Car.cpp"

class AssembleTest : public ::testing::Test
{
public:
    AssembleTest() {}
    ~AssembleTest() {}

    Car car;

protected:
    virtual void SetUp() override
    {
        car = Car();
    }

    virtual void TearDown() override {}
};

TEST_F(AssembleTest, GetTest)
{
    car.setCarType(CarTypeSedan());
    EXPECT_EQ(car.getCarType().compare(CAR_TYPE_SEDAN), 0);
    car.setCarType(CarTypeSuv());
    EXPECT_EQ(car.getCarType().compare(CAR_TYPE_SUV), 0);
    car.setCarType(CarTypeTruck());
    EXPECT_EQ(car.getCarType().compare(CAR_TYPE_TRUCK), 0);

    car.setEngine(EngineGm());
    EXPECT_EQ(car.getEngine().compare(ENGINE_GM), 0);
    car.setEngine(EngineToyota());
    EXPECT_EQ(car.getEngine().compare(ENGINE_TOYOTA), 0);
    car.setEngine(EngineWia());
    EXPECT_EQ(car.getEngine().compare(ENGINE_WIA), 0);
    car.setEngine(EngineBroken());
    EXPECT_EQ(car.getEngine().compare(ENGINE_BROKEN), 0);

    car.setBrakeSystem(BrakeSystemMando());
    EXPECT_EQ(car.getBrakeSystem().compare(BRAKE_SYSTEM_MANDO), 0);
    car.setBrakeSystem(BrakeSystemContinental());
    EXPECT_EQ(car.getBrakeSystem().compare(BRAKE_SYSTEM_CONTINENTAL), 0);
    car.setBrakeSystem(BrakeSystemBosch());
    EXPECT_EQ(car.getBrakeSystem().compare(BRAKE_SYSTEM_BOSCH), 0);

    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_EQ(car.getSteeringSystem().compare(STEERING_SYSTEM_BOSCH), 0);
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_EQ(car.getSteeringSystem().compare(STEERING_SYSTEM_MOBIS), 0);
}

TEST_F(AssembleTest, SedanTest)
{
    car.setCarType(CarTypeSedan());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());
}

TEST_F(AssembleTest, SuvTest)
{
    car.setCarType(CarTypeSuv());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());
}

TEST_F(AssembleTest, TruckTest)
{
    car.setCarType(CarTypeTruck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineGm());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineToyota());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineWia());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemMando());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemContinental());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemBosch());
    EXPECT_TRUE(car.isValidCheck());

    car.setEngine(EngineBroken());
    car.setBrakeSystem(BrakeSystemBosch());
    car.setSteeringSystem(SteeringSystemMobis());
    EXPECT_FALSE(car.isValidCheck());
}
