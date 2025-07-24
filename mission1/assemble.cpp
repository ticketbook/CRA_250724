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
        printf_s("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    else if (carType == SUV_T)
        printf_s("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    else if (carType == TRUCK_T)
        printf_s("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(Engine answer)
{
    engine = answer;
    if (engine == GM_E)
        printf_s("GM ������ �����ϼ̽��ϴ�.\n");
    else if (engine == TOYOTA_E)
        printf_s("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    else if (engine == WIA_E)
        printf_s("WIA ������ �����ϼ̽��ϴ�.\n");
    else if (engine == BROKEN_E)
        printf_s("���峭 ������ �����ϼ̽��ϴ�.\n");
}

void selectBrakeSystem(BrakeSystem answer)
{
    brakeSystem = answer;
    if (brakeSystem == MANDO_B)
        printf_s("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (brakeSystem == CONTINENTAL_B)
        printf_s("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (brakeSystem == BOSCH_B)
        printf_s("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(SteeringSystem answer)
{
    steeringSystem = answer;
    if (steeringSystem == BOSCH_S)
        printf_s("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    else if (steeringSystem == MOBIS_S)
        printf_s("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
        printf_s("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (engine == BROKEN_E)
        {
            printf_s("������ ���峪�ֽ��ϴ�.\n");
            printf_s("�ڵ����� �������� �ʽ��ϴ�.\n");
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

            printf_s("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (carType == SEDAN_T && brakeSystem == CONTINENTAL_B)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf_s("SEDAN_T���� Continental������ġ ��� �Ұ�\n");
    }
    else if (carType == SUV_T && engine == TOYOTA_E)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf_s("SUV_T���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (carType == TRUCK_T && engine == WIA_E)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf_s("TRUCK_T���� WIA���� ��� �Ұ�\n");
    }
    else if (carType == TRUCK_T && brakeSystem == MANDO_B)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf_s("TRUCK_T���� Mando������ġ ��� �Ұ�\n");
    }
    else if (brakeSystem == BOSCH_B && steeringSystem != BOSCH_S)
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf_s("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf_s("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}
