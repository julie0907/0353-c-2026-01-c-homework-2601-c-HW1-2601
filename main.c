/* 
  파일이름: [고미현/6025200] 1차 과제
  작 성 자: 고미현
  하 는 일: 프로그램 실행
*/

#include <stdio.h>

int main()
{
  // 1. 변수 선언 (5개 이상, 3가지 자료형 사용) 
  char initial;
  int hourlywage;
  int workingHours;
  float foodAllowance;
  int totalPay

  // 2. 프로그램 시작 화면 출력 
  printf("-------- 아르바이트 일단 계산 시스템 --------\n);
  printf("오늘도 업무를 수행하시느라 고생 많으셨습니다!\n\n");

  // 3.사용자 입력 받기
  printf("당신의 영문 이니셜 한 글자를 입력하세요: ");
  scanf("%c", &initial);
  
  printf("현재 본인의 시급(정수)을 입력하세요: ");
  scanf("%d", &hourlyWage);
  
  printf("오늘 실제 근무한 시간(정수)을 입력하세요: ");
  scanf("%d", &workingHours);

  printf("오늘 지급받은 식비 지원금(살수)을 입력하세요: ");
  scanf("%f", &foodAllowance);

  // 4. 산술 연산 수행 (사칙연산 1회 이상 필수)
  // 계산 공식: (hourlyWage * workingHours) + (int)foodAllowance;

  // 5. 최종 결과 출력 
  printf("\n-------- [ %c 님의 근무 정산 리포트 ] --------\n", initial);
  printf("1. 기본 급여 합계: %d 원\n", hourlyWage * workingHours);
  printf("2. 식비 지원 내역: %.1f 원\n", foodAllowance);
  printf("3. 최종 합산 일당: %%d원\n", totalPay);
  printf("------------------------------------------------\n");
  printf("내일도 활기찬 하루 되시길 %c 님을 응원합니다!\n", initial);

  

  return 0; 
}
