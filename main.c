/* 
  파일이름: [고미현/6025200] 1차 과제
  작 성 자: 고미현
  하 는 일: 프로그램 실행
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{

  system("chcp 65001");
  system("cls");
  
  // 1. 변수 선언 (5개 이상, 3가지 자료형 사용) 
  char initial;
  int hourlyWage;
  int workingHours;
  float foodAllowance;
  int totalPay;
  // 2차 추가 변수
    int totalHoursPerWeek;
    int bonusOption;
    double finalPay, bonusAmount = 0;

  // 2. 프로그램 시작 화면 출력 
  printf("-------- 아르바이트 일당 계산 시스템 --------\n");
  printf("오늘도 업무를 수행하시느라 고생 많으셨습니다!\n\n");

  // 3.사용자 입력 받기
  printf("당신의 영문 이니셜 한 글자를 입력하세요: ");
  scanf("%c", &initial);
  
  printf("현재 본인의 시급(정수)을 입력하세요: ");
  scanf("%d", &hourlyWage);
  
  printf("오늘 실제 근무한 시간(정수)을 입력하세요: ");
  scanf("%d", &workingHours);

  printf("오늘 지급받은 식비 지원금(실수)을 입력하세요: ");
  scanf("%f", &foodAllowance);

  printf("이번 주 총 근무 시간(정수)를 입력하세요: "); // 주휴수당 판별용
  scanf("%d", &totalHoursPerWeek);
  
  // 보너스 등급 선택 (switch문 활용)
    printf("\n오늘의 업무 강도를 선택하세요 (1:보통, 2:바쁨, 3:매우바쁨): ");
    scanf("%d", &bonusOption);

  // switch문: 업무 강도에 따른 보너스 계산
    switch (bonusOption) 
    {
        case 1: bonusAmount = 0; break;
        case 2: bonusAmount = (hourlyWage * workingHours) * 0.05; break; // 5% 보너스
        case 3: bonusAmount = (hourlyWage * workingHours) * 0.1; break;  // 10% 보너스
        default: printf("잘못된 옵션입니다. 보너스는 0원으로 처리됩니다.\n");
    }

    // if ~ else if 중첩문: 주휴수당 및 추가 인센티브 판별
    printf("\n[수당 판별 결과]\n");
    if (totalHoursPerWeek >= 15) 
    {
        printf("- 주휴수당 지급 대상입니다.\n");
        
        // 중첩 if문: 15시간 이상 중에서도 40시간 이상인 경우 '성실 근로자'
        if (totalHoursPerWeek >= 40 && workingHours >= 8) 
        {
            printf("  > 우수 성실 근로자 추가 인센티브 10,000원 확정!\n");
            bonusAmount += 10000;
        }
    }
    else if (totalHoursPerWeek > 0 && totalHoursPerWeek < 15) 
    {
        printf("- 주휴수당 미지급 대상입니다. (15시간 미만)\n");
    }
    else 
    {
        printf("- 근무 시간이 잘못 입력되었습니다.\n");
    }

    // 5. 최종 계산 
   totalPay = (int)finalPay; 
   printf("3. 최종 합산 일당: %d원\n", totalPay);
   
 
  // 4. 산술 연산 수행 (사칙연산 1회 이상 필수)
  // 계산 공식: (hourlyWage * workingHours) + (int)foodAllowance;
  totalPay = (hourlyWage * workingHours) + (int) foodAllowance;
  // 5. 최종 결과 출력 
  printf("\n-------- [ %c 님의 근무 정산 리포트 ] --------\n", initial);
  printf("1. 기본 급여 합계: %d 원\n", hourlyWage * workingHours);
  printf("2. 식비 지원 내역: %.1f 원\n", foodAllowance);
  printf("3.추가 수당 합계: %.0f 원\n", bonusAmount);
  printf("4. 최종 합산 일당: %d원\n", totalPay);
  printf("------------------------------------------------\n");
  printf("내일도 활기찬 하루 되시길 %c 님을 응원합니다!\n", initial);

  

  return 0; 
}
