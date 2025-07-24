#ifdef _DEBUG

#include "gmock/gmock.h"

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Car.cpp"

#define CLEAR_SCREEN "\033[H\033[2J"

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test_Q
};

enum CarTypeE
{
    MIN_CAR_TYPE = 0,
    SEDAN_T,
    SUV_T,
    TRUCK_T,
    MAX_CAR_TYPE
};

enum EngineE
{
    MIN_ENGINE = 0,
    GM_E,
    TOYOTA_E,
    WIA_E,
    BROKEN_E,
    MAX_ENGINE
};

enum BrakeSystemE
{
    MIN_BRAKE_SYSTEM = 0,
    MANDO_B,
    CONTINENTAL_B,
    BOSCH_B,
    MAX_BRAKE_SYSTEM
};

enum SteeringSystemE
{
    MIN_STEERING_SYSTEM = 0,
    BOSCH_S,
    MOBIS_S,
    MAX_STEERING_SYSTEM
};

enum RunTest
{
    MIN_RUN_TEST = 0,
    RUN_R,
    TEST_R,
    MAX_RUN_TEST
};

void selectCarType(CarTypeE answer);
void selectEngine(EngineE answer);
void selectBrakeSystem(BrakeSystemE answer);
void selectSteeringSystem(SteeringSystemE answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

Car car;

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

int main()
{
    char buf[100];
    int step = CarType_Q;

    while (1)
    {
        if (step == CarType_Q)
        {
            printf_s(CLEAR_SCREEN);

            printf_s("        ______________\n");
            printf_s("       /|            | \n");
            printf_s("  ____/_|_____________|____\n");
            printf_s(" |                      O  |\n");
            printf_s(" '-(@)----------------(@)--'\n");
            printf_s("===============================\n");
            printf_s("어떤 차량 타입을 선택할까요?\n");
            printf_s("1. Sedan\n");
            printf_s("2. SUV\n");
            printf_s("3. Truck\n");
        }
        else if (step == Engine_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("어떤 엔진을 탑재할까요?\n");
            printf_s("0. 뒤로가기\n");
            printf_s("1. GM\n");
            printf_s("2. TOYOTA\n");
            printf_s("3. WIA\n");
            printf_s("4. 고장난 엔진\n");
        }
        else if (step == BrakeSystem_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("어떤 제동장치를 선택할까요?\n");
            printf_s("0. 뒤로가기\n");
            printf_s("1. MANDO\n");
            printf_s("2. CONTINENTAL\n");
            printf_s("3. BOSCH\n");
        }
        else if (step == SteeringSystem_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("어떤 조향장치를 선택할까요?\n");
            printf_s("0. 뒤로가기\n");
            printf_s("1. BOSCH\n");
            printf_s("2. MOBIS\n");
        }
        else if (step == Run_Test_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("멋진 차량이 완성되었습니다.\n");
            printf_s("어떤 동작을 할까요?\n");
            printf_s("0. 처음 화면으로 돌아가기\n");
            printf_s("1. RUN\n");
            printf_s("2. Test\n");
        }
        printf_s("===============================\n");

        printf_s("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strncmp(buf, "exit", 4))
        {
            printf_s("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf_s("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        if (step == CarType_Q && !(answer > MIN_CAR_TYPE && answer < MAX_CAR_TYPE))
        {
            printf_s("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            continue;
        }
        else if (step == Engine_Q && !(answer >= MIN_ENGINE && answer < MAX_ENGINE))
        {
            printf_s("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            delay(800);
            continue;
        }
        else if (step == BrakeSystem_Q && !(answer >= MIN_BRAKE_SYSTEM && answer < MAX_BRAKE_SYSTEM))
        {
            printf_s("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            continue;
        }
        else if (step == SteeringSystem_Q && !(answer >= MIN_STEERING_SYSTEM && answer < MAX_STEERING_SYSTEM))
        {
            printf_s("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            delay(800);
            continue;
        }
        else if (step == Run_Test_Q && !(answer >= MIN_RUN_TEST && answer < MAX_RUN_TEST))
        {
            printf_s("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            delay(800);
            continue;
        }

        // 처음으로 돌아가기
        if (answer == 0 && step == Run_Test_Q)
        {
            step = CarType_Q;
            continue;
        }

        // 이전으로 돌아가기
        if (answer == 0 && step >= 1)
        {
            step -= 1;
            continue;
        }

        if (step == CarType_Q)
        {
            selectCarType((CarTypeE)answer);
            delay(800);
            step = Engine_Q;
        }
        else if (step == Engine_Q)
        {
            selectEngine((EngineE)answer);
            delay(800);
            step = BrakeSystem_Q;
        }
        else if (step == BrakeSystem_Q)
        {
            selectBrakeSystem((BrakeSystemE)answer);
            delay(800);
            step = SteeringSystem_Q;
        }
        else if (step == SteeringSystem_Q)
        {
            selectSteeringSystem((SteeringSystemE)answer);
            delay(800);
            step = Run_Test_Q;
        }
        else if (step == Run_Test_Q)
        {
            if (answer == 1)
            {
                runProducedCar();
                delay(2000);
            }
            else if (answer == 2)
            {
                printf_s("Test...\n");
                delay(1500);
                testProducedCar();
                delay(2000);
            }
        }
    }
}

void selectCarType(CarTypeE answer)
{
    if (answer == SEDAN_T)
        car.setCarType(CarTypeSedan());
    else if (answer == SUV_T)
        car.setCarType(CarTypeSuv());
    else if (answer == TRUCK_T)
        car.setCarType(CarTypeTruck());

    printf_s("차량 타입으로 %s을 선택하셨습니다.\n", car.getCarType().c_str());
}

void selectEngine(EngineE answer)
{
    if (answer == GM_E)
        car.setEngine(EngineGm());
    else if (answer == TOYOTA_E)
        car.setEngine(EngineToyota());
    else if (answer == WIA_E)
        car.setEngine(EngineWia());
    else if (answer == BROKEN_E)
        car.setEngine(EngineBroken());

    printf_s("%s 엔진을 선택하셨습니다.\n", car.getEngine().c_str());
}

void selectBrakeSystem(BrakeSystemE answer)
{
    if (answer == MANDO_B)
        car.setBrakeSystem(BrakeSystemMando());
    else if (answer == CONTINENTAL_B)
        car.setBrakeSystem(BrakeSystemContinental());
    else if (answer == BOSCH_B)
        car.setBrakeSystem(BrakeSystemBosch());

    printf_s("%s 제동장치를 선택하셨습니다.\n", car.getBrakeSystem().c_str());
}

void selectSteeringSystem(SteeringSystemE answer)
{
    if (answer == BOSCH_S)
        car.setSteeringSystem(SteeringSystemBosch());
    else if (answer == MOBIS_S)
        car.setSteeringSystem(SteeringSystemMobis());

    printf_s("%s 조향장치를 선택하셨습니다.\n", car.getSteeringSystem().c_str());
}

void runProducedCar()
{
    if (car.isValidCheck() == false)
    {
        printf_s("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (!car.getEngine().compare(ENGINE_BROKEN))
        {
            printf_s("엔진이 고장나있습니다.\n");
            printf_s("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printf_s("Car Type : %s\n", car.getCarType().c_str());
            printf_s("Engine : %s\n", car.getEngine().c_str());
            printf_s("Brake System : %s", car.getBrakeSystem().c_str());
            printf_s("SteeringSystem : %s\n", car.getSteeringSystem().c_str());

            printf_s("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (car.isValidCheck() == false)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");

        if (!car.getCarType().compare(CAR_TYPE_SEDAN) && !car.getBrakeSystem().compare(BRAKE_SYSTEM_CONTINENTAL))
        {
            printf_s("SEDAN_T에는 Continental제동장치 사용 불가\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_SUV) && !car.getEngine().compare(ENGINE_TOYOTA))
        {
            printf_s("SUV_T에는 TOYOTA엔진 사용 불가\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_TRUCK) && !car.getEngine().compare(ENGINE_WIA))
        {
            printf_s("TRUCK_T에는 WIA엔진 사용 불가\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_TRUCK) && !car.getBrakeSystem().compare(BRAKE_SYSTEM_MANDO))
        {
            printf_s("TRUCK_T에는 Mando제동장치 사용 불가\n");
        }
        else if (!car.getBrakeSystem().compare(BRAKE_SYSTEM_BOSCH) && car.getSteeringSystem().compare(STEERING_SYSTEM_BOSCH))
        {
            printf_s("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf_s("Error.\n");
        }
    }
    else
    {
        printf_s("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

#endif
