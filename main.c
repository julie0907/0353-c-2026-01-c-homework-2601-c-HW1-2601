/* 
  파일이름: [고미현/60252008] 
  작 성 자: 고미현
  하 는 일: 프로그램 실행 + 무한루프 메뉴 시스템 + 함수 분리 (아르바이트 일당 계산)
*/

#include <stdio.h>
#include <stdlib.h>

// ---- 전역변수선언 ---
int g_hourlyWage = 0 ; // 시급
int g_workingHours = 0 ; // 오늘 근무 시간
int g_totalHoursPerWeek = 0 ; // 이번 주 총 근무 시간
double g_foodAllowance = 0 ; // 식비 지원금
char g_initial = 'X' ; // 영문 이니셜
int g_isDataEntered = 0; // 입력 완료 여부 (0: 미입력 , 1: 입력완료)

// ----함수선언----
void inputData(void); //압력(전역변수 변경)
double calculateBonus(int wage, int hours, int option); //보너스 계산 (매계변수 + 변환값)
int analyzeWeekly(int totalHours); //주간 분석 (매개변수 + 변환값)
void printReport(char name); //리포트 출력 (매개변수)


// ---메인함수---

int main()
{

  system("chcp 65001");
  system("cls");
  
  int choice;

  printf("==================================================\n");
  printf("        아르바이트 일당 계산 시스템 v3\n");
  printf("==================================================\n");

  while (1)
    {
      printf("\n------------메인메뉴------------\n");
      printf("1. 근무 정보 입력\n");
      printf("2. 일당 계산 및 리포트 조회\n");
      printf("3. 주간 근무 분석\n");
      printf("4. 종료\n");
      printf("----------------------------------\n");
      scanf("%d", &choice);

      if (choice == 1)
      {
        inputData();
      }
      else if ( choice ==2)
      {
        if (g_isDataEntered == 0)
        {
          printf("\n[알림] 먼저 1번 메뉴에서 근무 정보를 입력해주세요!\n");
        }
        else
        {
          printReport(g_initial);
        }
      }
      else if (choice == 3)
      {
        if (g_isDataEntered == 0)
        {
         printf("\n[알림] 먼저 1번 메뉴에서 근무 정보를 입력해주세요!\n");
        }
        else
        {
          analyzeWeekly(g_totalHoursPerWeek);
        }
      }
      else if (choice == 4)
      {
        printf("\n프로그램을 종료합니다. 오늘도 수고하셨습니다!\n");
        break;
      }
      else
      {
        printf("\n[오류] 1~4 사이의 번호만 입력 가능합니다.\n");
      }
    }
    return 0;
}

// ---- 함수정의 -----

// 1) 사용자 입력 함수 (전역변수 값을 직접 변경)

void inputData(void)
{
  printf("\n---------------근무 정보 입력---------------\n");

  printf("영문 이니셜 한 글자를 입력하세요: ");
  scanf(" %c", &g_initial);
  
  printf("시급(정수)을 입력하세요: ");
  scanf("%d", &g_hourlyWage);
  
  printf("오늘 실제 근무한 시간(정수)을 입력하세요: ");
  scanf("%d", &g_workingHours);

  printf("오늘 지급받은 식비 지원금(실수)을 입력하세요: ");
  scanf("%lf", &g_foodAllowance);

  printf("이번 주 총 근무 시간(정수)를 입력하세요: "); // 주휴수당 판별용
  scanf("%d", &g_totalHoursPerWeek);

  g_isDataEntered = 1;
  printf("\n[완료] 정보가 정상적으로 저장되었습니다.\n");
}

// 2) 보너스 계산 함수 (매개변수 3개 + double 변환)
double calculateBonus(int wage, int hours , int option)
{
  double bonus = 0;
  
  switch (option) 
    {
        case 1:
          bonus = 0;
          break;
        case 2: 
          bonus = (wage * hours) * 0.05; 
          break;
        case 3: 
          bonus = (wage * hours) * 0.1; 
          break;  
        default: 
        printf("[안내] 잘못된 옵션입니다. 보너스는 0원으로 처리됩니다.\n");
        bonus = 0;
    }

    return bonus;
}

// 3) 주간 근무 분석 함수 (매개변수 1개 + int변환)
int analyzeWeekly(int totalHours)
{
  printf("\n---------주간 근무 분석----------\n");
  printf("입력된 주간 총 근무 시간: %d 시간\n" , totalHours);

  if (totalHours >=40)
  {
    printf("- 우수 성실 근로자 등급입니다!\n");
    printf("- 주휴수당 지급 대상입니다.\n");
    return 2;
  }
  else if (totalHours >=15)
  {
    printf("- 주휴수당 지급 대상입니다.\n");
    return 1;
  }
  else
  {
    printf("- 주휴수당 미지급 대상입니다. (15시간 미만)\n");
    return 0;
  }
}

// 4) 리포트 출력 함수 (매개변수 1개)
void printReport(char name)
{
  int bonusOption;
  double bonusAmount;
  double finalPay;

  printf("\n--------------- 일당 정산 --------------\n");
  printf("오늘의 업무 강도를 선택하세요 (1:보통, 2:바쁨, 3:매우바쁨): ");
  scanf("%d" , &bonusOption);

  //매개변수와 반환값을 가진 함수 호출 
  bonusAmount = calculateBonus(g_hourlyWage, g_workingHours, bonusOption);

  //주간 40시간 이상이면 추가 인센티브 1만원 
  if  (g_totalHoursPerWeek >= 40 && g_workingHours >= 8)
  {
    printf("[보너스] 우수 성실 근로자 인센티브 10,000원이 추가됩니다!\n");
    bonusAmount += 10000;
  }
  
  finalPay = (g_hourlyWage * g_workingHours) + g_foodAllowance + bonusAmount;

  // 5. 최종 결과 출력 
  printf("\n-------- [ %c 님의 근무 정산 리포트 ] --------\n", name);
  printf("1. 기본 급여 합계: %d 원\n", g_hourlyWage * g_workingHours);
  printf("2. 식비 지원 내역: %.1f 원\n", g_foodAllowance);
  printf("3. 추가 수당 합계: %.0f 원\n", bonusAmount);
  printf("4. 최종 합산 일당: %.0f 원\n", finalPay);
  printf("------------------------------------------------\n");
  printf("내일도 활기찬 하루 되시길 %c 님을 응원합니다!\n", name);


}
