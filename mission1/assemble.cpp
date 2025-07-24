#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test_Q
};

enum CarType
{
    MIN_CAR_TYPE = 0,
    SEDAN_T,
    SUV_T,
    TRUCK_T,
    MAX_CAR_TYPE
};

enum Engine
{
    MIN_ENGINE = 0,
    GM_E,
    TOYOTA_E,
    WIA_E,
    BROKEN_E,
    MAX_ENGINE
};

enum BrakeSystem
{
    MIN_BRAKE_SYSTEM = 0,
    MANDO_B,
    CONTINENTAL_B,
    BOSCH_B,
    MAX_BRAKE_SYSTEM
};

enum SteeringSystem
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

void selectCarType(CarType answer);
void selectEngine(Engine answer);
void selectBrakeSystem(BrakeSystem answer);
void selectSteeringSystem(SteeringSystem answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

CarType carType;
Engine engine;
BrakeSystem brakeSystem;
SteeringSystem steeringSystem;

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
            selectCarType((CarType)answer);
            delay(800);
            step = Engine_Q;
        }
        else if (step == Engine_Q)
        {
            selectEngine((Engine)answer);
            delay(800);
            step = BrakeSystem_Q;
        }
        else if (step == BrakeSystem_Q)
        {
            selectBrakeSystem((BrakeSystem)answer);
            delay(800);
            step = SteeringSystem_Q;
        }
        else if (step == SteeringSystem_Q)
        {
            selectSteeringSystem((SteeringSystem)answer);
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

void selectCarType(CarType answer)
{
    carType = answer;
    if (carType == SEDAN_T)
        printf_s("차량 타입으로 Sedan을 선택하셨습니다.\n");
    else if (carType == SUV_T)
        printf_s("차량 타입으로 SUV을 선택하셨습니다.\n");
    else if (carType == TRUCK_T)
        printf_s("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(Engine answer)
{
    engine = answer;
    if (engine == GM_E)
        printf_s("GM 엔진을 선택하셨습니다.\n");
    else if (engine == TOYOTA_E)
        printf_s("TOYOTA 엔진을 선택하셨습니다.\n");
    else if (engine == WIA_E)
        printf_s("WIA 엔진을 선택하셨습니다.\n");
    else if (engine == BROKEN_E)
        printf_s("고장난 엔진을 선택하셨습니다.\n");
}

void selectBrakeSystem(BrakeSystem answer)
{
    brakeSystem = answer;
    if (brakeSystem == MANDO_B)
        printf_s("MANDO 제동장치를 선택하셨습니다.\n");
    else if (brakeSystem == CONTINENTAL_B)
        printf_s("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    else if (brakeSystem == BOSCH_B)
        printf_s("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(SteeringSystem answer)
{
    steeringSystem = answer;
    if (steeringSystem == BOSCH_S)
        printf_s("BOSCH 조향장치를 선택하셨습니다.\n");
    else if (steeringSystem == MOBIS_S)
        printf_s("MOBIS 조향장치를 선택하셨습니다.\n");
}

int isValidCheck()
{
    if (carType == SEDAN_T && brakeSystem == CONTINENTAL_B)
    {
        return false;
    }
    else if (carType == SUV_T && engine == TOYOTA_E)
    {
        return false;
    }
    else if (carType == TRUCK_T && engine == WIA_E)
    {
        return false;
    }
    else if (carType == TRUCK_T && brakeSystem == MANDO_B)
    {
        return false;
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        return false;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf_s("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (engine == BROKEN_E)
        {
            printf_s("엔진이 고장나있습니다.\n");
            printf_s("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (carType == SEDAN_T)
                printf_s("Car Type : Sedan\n");
            else if (carType == SUV_T)
                printf_s("Car Type : SUV\n");
            else if (carType == TRUCK_T)
                printf_s("Car Type : Truck\n");

            if (engine == GM_E)
                printf_s("Engine : GM\n");
            else if (engine == TOYOTA_E)
                printf_s("Engine : TOYOTA\n");
            else if (engine == WIA_E)
                printf_s("Engine : WIA\n");

            if (brakeSystem == MANDO_B)
                printf_s("Brake System : Mando");
            else if (brakeSystem == CONTINENTAL_B)
                printf_s("Brake System : Continental\n");
            else if (brakeSystem == BOSCH_B)
                printf_s("Brake System : Bosch\n");

            if (steeringSystem == BOSCH_S)
                printf_s("SteeringSystem : Bosch\n");
            else if (steeringSystem == MOBIS_S)
                printf_s("SteeringSystem : Mobis\n");

            printf_s("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (carType == SEDAN_T && brakeSystem == CONTINENTAL_B)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf_s("SEDAN_T에는 Continental제동장치 사용 불가\n");
    }
    else if (carType == SUV_T && engine == TOYOTA_E)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf_s("SUV_T에는 TOYOTA엔진 사용 불가\n");
    }
    else if (carType == TRUCK_T && engine == WIA_E)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf_s("TRUCK_T에는 WIA엔진 사용 불가\n");
    }
    else if (carType == TRUCK_T && brakeSystem == MANDO_B)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf_s("TRUCK_T에는 Mando제동장치 사용 불가\n");
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        printf_s("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf_s("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf_s("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}
