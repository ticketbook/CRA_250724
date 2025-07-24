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
            printf_s("� ���� Ÿ���� �����ұ��?\n");
            printf_s("1. Sedan\n");
            printf_s("2. SUV\n");
            printf_s("3. Truck\n");
        }
        else if (step == Engine_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("� ������ ž���ұ��?\n");
            printf_s("0. �ڷΰ���\n");
            printf_s("1. GM\n");
            printf_s("2. TOYOTA\n");
            printf_s("3. WIA\n");
            printf_s("4. ���峭 ����\n");
        }
        else if (step == BrakeSystem_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("� ������ġ�� �����ұ��?\n");
            printf_s("0. �ڷΰ���\n");
            printf_s("1. MANDO\n");
            printf_s("2. CONTINENTAL\n");
            printf_s("3. BOSCH\n");
        }
        else if (step == SteeringSystem_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("� ������ġ�� �����ұ��?\n");
            printf_s("0. �ڷΰ���\n");
            printf_s("1. BOSCH\n");
            printf_s("2. MOBIS\n");
        }
        else if (step == Run_Test_Q)
        {
            printf_s(CLEAR_SCREEN);
            printf_s("���� ������ �ϼ��Ǿ����ϴ�.\n");
            printf_s("� ������ �ұ��?\n");
            printf_s("0. ó�� ȭ������ ���ư���\n");
            printf_s("1. RUN\n");
            printf_s("2. Test\n");
        }
        printf_s("===============================\n");

        printf_s("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strncmp(buf, "exit", 4))
        {
            printf_s("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf_s("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            continue;
        }

        if (step == CarType_Q && !(answer > MIN_CAR_TYPE && answer < MAX_CAR_TYPE))
        {
            printf_s("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
            delay(800);
            continue;
        }
        else if (step == Engine_Q && !(answer >= MIN_ENGINE && answer < MAX_ENGINE))
        {
            printf_s("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
            delay(800);
            continue;
        }
        else if (step == BrakeSystem_Q && !(answer >= MIN_BRAKE_SYSTEM && answer < MAX_BRAKE_SYSTEM))
        {
            printf_s("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
            delay(800);
            continue;
        }
        else if (step == SteeringSystem_Q && !(answer >= MIN_STEERING_SYSTEM && answer < MAX_STEERING_SYSTEM))
        {
            printf_s("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
            delay(800);
            continue;
        }
        else if (step == Run_Test_Q && !(answer >= MIN_RUN_TEST && answer < MAX_RUN_TEST))
        {
            printf_s("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
            delay(800);
            continue;
        }

        // ó������ ���ư���
        if (answer == 0 && step == Run_Test_Q)
        {
            step = CarType_Q;
            continue;
        }

        // �������� ���ư���
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

    printf_s("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", car.getCarType().c_str());
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

    printf_s("%s ������ �����ϼ̽��ϴ�.\n", car.getEngine().c_str());
}

void selectBrakeSystem(BrakeSystemE answer)
{
    if (answer == MANDO_B)
        car.setBrakeSystem(BrakeSystemMando());
    else if (answer == CONTINENTAL_B)
        car.setBrakeSystem(BrakeSystemContinental());
    else if (answer == BOSCH_B)
        car.setBrakeSystem(BrakeSystemBosch());

    printf_s("%s ������ġ�� �����ϼ̽��ϴ�.\n", car.getBrakeSystem().c_str());
}

void selectSteeringSystem(SteeringSystemE answer)
{
    if (answer == BOSCH_S)
        car.setSteeringSystem(SteeringSystemBosch());
    else if (answer == MOBIS_S)
        car.setSteeringSystem(SteeringSystemMobis());

    printf_s("%s ������ġ�� �����ϼ̽��ϴ�.\n", car.getSteeringSystem().c_str());
}

void runProducedCar()
{
    if (car.isValidCheck() == false)
    {
        printf_s("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (!car.getEngine().compare(ENGINE_BROKEN))
        {
            printf_s("������ ���峪�ֽ��ϴ�.\n");
            printf_s("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            printf_s("Car Type : %s\n", car.getCarType().c_str());
            printf_s("Engine : %s\n", car.getEngine().c_str());
            printf_s("Brake System : %s", car.getBrakeSystem().c_str());
            printf_s("SteeringSystem : %s\n", car.getSteeringSystem().c_str());

            printf_s("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (car.isValidCheck() == false)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");

        if (!car.getCarType().compare(CAR_TYPE_SEDAN) && !car.getBrakeSystem().compare(BRAKE_SYSTEM_CONTINENTAL))
        {
            printf_s("SEDAN_T���� Continental������ġ ��� �Ұ�\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_SUV) && !car.getEngine().compare(ENGINE_TOYOTA))
        {
            printf_s("SUV_T���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_TRUCK) && !car.getEngine().compare(ENGINE_WIA))
        {
            printf_s("TRUCK_T���� WIA���� ��� �Ұ�\n");
        }
        else if (!car.getCarType().compare(CAR_TYPE_TRUCK) && !car.getBrakeSystem().compare(BRAKE_SYSTEM_MANDO))
        {
            printf_s("TRUCK_T���� Mando������ġ ��� �Ұ�\n");
        }
        else if (!car.getBrakeSystem().compare(BRAKE_SYSTEM_BOSCH) && car.getSteeringSystem().compare(STEERING_SYSTEM_BOSCH))
        {
            printf_s("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf_s("Error.\n");
        }
    }
    else
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

#endif
