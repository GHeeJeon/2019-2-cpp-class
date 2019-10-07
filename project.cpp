#include <stdio.h>
#include <stdlib.h> // rand함수 원형 포함하고있는 헤더
#include <time.h> // srand에 Seed로 현재시간을 사용하기위해 사용
#include <Windows.h> // Sleep 함수 사용하기 위해 포함 (sleep 함수 n000을 입력하면 n초만큼 후 다음 동작 반복)


void game_start_field();
void game_start(struct game_info *user_p, int *people_count_p, int *game_count_p);
void game_run(int *winner_p);
void bet(struct game_info *user_p, int *people_count_p, int *game_count_p);
void betting_result(struct game_info *user_p, int *winner_p, int people_count);
void game_result_ready(struct game_info *user_p, int people_count);
void game_result(struct game_info *user, int people_count);

struct game_info // 구조체는 앞에 선언되어야 한다 -> ? 구조체자체도 변수이기 때문에
{		   // 구조체를 통해 사용자 이름, 잔고를 관리
	char name[10]; // 플레이어 이름
	int seed_money; // 플레이어 잔고 ( 기본 5만원 )
	int rank; // 플레이어 순위
	int betting_money; // 플레이어순으로 배팅한 금액
	int player_choice; // 플레이어가 선택한 말의 번호
};

int main()
{
	system("mode con: cols=84 lines=27");      // 콘솔 화면창 조절 cols = 가로 lines = 세로
	int i, t, count = 0;
	int people_count, game_count; // 사람 수, 게임 횟수
	int winner[6] = { 0, }; // 우승말 0값으로 초기화
	//int *people_count_p = &people_count;
	//int *game_count_p = &game_count;
	//int *winner_p[6];

	struct game_info user[11];
	//struct game_info *user_p[11];

	/*
	for (i = 0; i < 6; i++) // winner 포인터 배열 초기화
	{
		winner_p[i] = &winner[i];
	}


	for (i = 0; i < 11; i++) // user 구조체 포인터 배열초기화, result 배열 초기화
	{
		user_p[i] = &user[i];
	}
	*/
	game_start_field(); // 게임시작 화면 함수
	game_start(user, &people_count, &game_count); // 사용자 정보 입력받아 저장, 게임 횟수, 사람수 입력받아 저장

	t = game_count; // 게임 횟수 game_count를 밑에 함수에서 사용해야 해서 놔두고 변수 t에다 값만 저장하여 while문 실행
	while (t > 0) //게임횟수만큼 반복
	{
		bet(user, &people_count, &game_count);
		game_run(winner); // 등 수 구조체주소 넘김
		betting_result(user, winner, people_count);
		t--;
	}

	game_result_ready(user, people_count);
	game_result(user, people_count);

	system("pause");
}

void game_start_field()
{
	printf("\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                             □□□□□□□□□□□                             □");
	printf("□                             □인생역전! 경마게임□                             □");
	printf("□                             □□□□□□□□□□□                             □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□                                                                                □");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	getchar();
	system("cls");
}

void game_start(struct game_info *user_p, int *people_count_p, int *game_count_p) // 포인터 구조체를 받음으로써 user 11개 모두 초기화 가능
{
	int i;
	char yes_or_no;

checkpoint1:
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("                  게임에 참여할 인원을 정해주세요  (최대 10명) : "); // 좌측 띄어쓰기 18개
	scanf("%d", people_count_p);


	if (*people_count_p > 0 && *people_count_p <= 10); // 인원이 0~10 사이라면 넘어가고, 아니라면 다시설정
	else
	{
		printf("\n");
		printf("                             인원을 다시  설정 해주세요.\n"); // 좌측 띄어쓰기 29개
		*people_count_p = 0; // people_count 값 초기화 안할경우 바로 넘어감 게임진입
		while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 하여 위의 printf문이 나타날수있도록함
		getchar();
		system("cls");
		goto checkpoint1;
	}


	printf("                             %d 명이 맞습니까? [Y/N] : ", *people_count_p); // 좌측 띄어쓰기 29개
	scanf(" %c", &yes_or_no);
	printf("\n");

	if (yes_or_no == 'Y' || yes_or_no == 'y');
	else
	{
		printf("                                  다시 설정해주세요.\n\n"); // 좌측 띄어쓰기 34개
		while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 하여 위의 printf문이 나타날수있도록함
		*people_count_p = 0; // people_count 값 초기화 안할경우 바로 넘어감 게임진입
		getchar(); // 초기화 대기
		system("cls");
		goto checkpoint1;
	}

	system("cls"); // 화면 정리

	for (i = 0; i < *people_count_p; i++)
	{
		printf("플레이어 %d의 이름을 입력하세요 : ", i + 1);
		scanf("%s", user_p[i].name);
		printf("\n");
		user_p[i].seed_money = 50000;
		user_p[i].rank = 1;

		printf("*****플레이어 %d*****\n이름 : %s \n보유 잔액 : %d\n********************\n\n", i + 1, user_p[i].name, user_p[i].seed_money);
	}



checkpoint2:
	printf("                         몇 회 게임을 하시겠습니까? : "); // 좌측 띄어쓰기 25개 
														   //while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
	scanf("%d", game_count_p);

	if (*game_count_p > 0 && *game_count_p <= 10);
	else
	{
		printf("                       잘못 눌렀습니다. 다시 설정해주세요.\n"); // 좌측 띄어쓰기 23개
		*game_count_p = 0; // game_count 값 초기화
		while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
		getchar();
		system("cls");
		for (i = 0; i < *people_count_p; i++)
		{
			printf("\n\n");
			printf("*****플레이어 %d*****\n이름 : %s \n보유 잔액 : %d\n********************\n\n", i + 1, user_p[i].name, user_p[i].seed_money);
		}
		goto checkpoint2;
	}

	printf("\n");


	printf("                           잠시후 게임이 시작됩니다."); // 좌측 뜨어쓰기 28개
	Sleep(3000); // 3초 지연
	system("cls"); // 3초 후 화면을 깨끗하게 지워줌
}


void game_run(int *winner_p)
{
	int f, s; // for문 돌리기 위해 쓰이는 기본변수
	int n1 = 9, n2 = 9, n3 = 9, n4 = 9; // 말의 위치 ( 기본 9 값으로 초기화 )
	int random; // 난수값 저장변수
	char field[11][81] =
	{    /*
		 판에 관한 정보
		 총길이 11 X 80 (0~79)
		 도입부 9(0~8) 최종부 5(75~79)말의 최초위치 10(field[][9])
		 마지막 결승라인 field[][75]
		 */
		"################################################################################",
		"#*****S*|------------------------------------------------------------------|***#",
		"#*(1)*T*|@                                                                 |*F*#",
		"#*****A*|------------------------------------------------------------------|*I*#",
		"#*(2)*R*|@                                                                 |*N*#",
		"#*****T*|------------------------------------------------------------------|*I*#",
		"#*(3)*L*|@                                                                 |*S*#",
		"#*****I*|------------------------------------------------------------------|*H*#",
		"#*(4)*N*|@                                                                 |*!*#",
		"#*****E*|------------------------------------------------------------------|***#",
		"################################################################################"
	};

	srand((unsigned int)time(NULL)); // rand() 를 쓰는 동일 함수 내에 있어야 시드역활을 할수있음



	while (n1 != 75 && n2 != 75 && n3 != 75 && n4 != 75) // 말 어느 4개중 마지막 라인 field[][75] 에 들어올때까지 반복
	{
		random = 0;
		printf("\n\n");
		for (f = 0; f < 11; f++)
		{

			if (f == 2)
			{
				if (n1 >= 70 && n1 < 75)
				{
					random = 75 - n1; //70에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
					field[2][n1] = ' '; // 앞 뒤 배열을 바꿔주는 바람에 결승선|가 뒷 부분에 생기게 되므로 그 부분을 수정해 주기위해 따로 예외 지정 
					field[2][n1 + random] = '@'; //이렇게 하면   |    @   가 아니라 깔끔하게        @           이렇게 된다.
					n1 += random; // 더해줘야만 무한루프 탈출 가능
					winner_p[1] = 1; // 1번 말 우승 포인터를 통해 winner에 넣음
				}
				else
				{
					random = (rand() % 5 + 1); // 랜덤함수를 통해 움직이는 값 지정 ( 이 부분은 실험해본 결과 같은 구역"{ }" 안에서는 랜덤값을 변수에 저장해두면 변하지 않고 구역을 벗어나서 재 지정하면 변함) 
					field[2][n1] = field[2][n1 + random];
					field[2][n1 + random] = '@';
					n1 += random;
				}
			}

			if (f == 4)
			{
				if (n2 >= 70 && n2 < 75)
				{
					random = 75 - n2; //70에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
					field[4][n2] = ' '; // 앞 뒤 배열을 바꿔주는 바람에 결승선|가 뒷 부분에 생기게 되므로 그 부분을 수정해 주기위해 따로 예외 지정 
					field[4][n2 + random] = '@'; //이렇게 하면   |    @   가 아니라 깔끔하게        @           이렇게 된다.
					n2 += random;
					winner_p[2] = 2; // 2번 말 우승
				}
				else
				{
					random = (rand() % 5 + 1); // 랜덤함수를 통해 움직이는 값 지정 ( 이 부분은 실험해본 결과 같은 구역"{ }" 안에서는 랜덤값을 변수에 저장해두면 변하지 않고 구역을 벗어나서 재 지정하면 변함) 
					field[4][n2] = field[4][n2 + random];
					field[4][n2 + random] = '@';
					n2 += random;
				}
			}

			if (f == 6)
			{
				if (n3 >= 70 && n3 < 75)
				{
					random = 75 - n3; //70에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
					field[6][n3] = ' '; // 앞 뒤 배열을 바꿔주는 바람에 결승선|가 뒷 부분에 생기게 되므로 그 부분을 수정해 주기위해 따로 예외 지정 
					field[6][n3 + random] = '@'; //이렇게 하면   |    @   가 아니라 깔끔하게        @           이렇게 된다.
					n3 += random;
					winner_p[3] = 3; // 3번 말 우승
				}
				else
				{
					random = (rand() % 5 + 1); // 랜덤함수를 통해 움직이는 값 지정 ( 이 부분은 실험해본 결과 같은 구역"{ }" 안에서는 랜덤값을 변수에 저장해두면 변하지 않고 구역을 벗어나서 재 지정하면 변함) 
					field[6][n3] = field[6][n3 + random];
					field[6][n3 + random] = '@';
					n3 += random;

				}
			}

			if (f == 8)
			{
				if (n4 >= 70 && n4 < 75)
				{
					random = 75 - n4; //70에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
					field[8][n4] = ' '; // 앞 뒤 배열을 바꿔주는 바람에 결승선|가 뒷 부분에 생기게 되므로 그 부분을 수정해 주기위해 따로 예외 지정 
					field[8][n4 + random] = '@'; //이렇게 하면   |    @   가 아니라 깔끔하게        @           이렇게 된다.
					n4 += random;
					winner_p[4] = 4; // 4번 말 우승
				}
				else
				{
					random = (rand() % 5 + 1); // 랜덤함수를 통해 움직이는 값 지정 ( 이 부분은 실험해본 결과 같은 구역"{ }" 안에서는 랜덤값을 변수에 저장해두면 변하지 않고 구역을 벗어나서 재 지정하면 변함) 
					field[8][n4] = field[8][n4 + random];
					field[8][n4 + random] = '@';
					n4 += random;
				}
			}



			for (s = 0; s < 81; s++)
				printf("%c", field[f][s]);    // 배열에 저장된 원소 하나씩 꺼내서 화면 전체를 출력하는 부분

			printf("\n");
		}
		Sleep(50); // 이 부분을 통해 화면을 빨리보여줄지 천천히 보여줄지 결정 할 수 있다.
		system("cls");
	}




	printf("\n\n");
	for (f = 0; f < 11; f++) // 마지막 최종 결과를 보여주기 위해 다시한번 씀
	{
		for (s = 0; s < 81; s++)
			printf("%c", field[f][s]);

		printf("\n");
	}

	printf("\n\n\n");

	printf("                             **********************\n");
	printf("                             **   경마  전광판   **\n");
	printf("                             **********************\n");
	for (f = 1; f < 5; f++) // 각각 말들이 우승하면 표시하기위해
	{
		if (winner_p[f] != 0)
			printf("                             **1등**   %d번 말!   **\n", winner_p[f]);
	}
	printf("                             **********************\n");

	getchar(); // 키하나 입력받아 종료
	system("cls"); //화면 지움
}

void bet(struct game_info *user_p, int *people_count_p, int *game_count_p)
{
	int i;

	for (i = 0; i < *people_count_p; i++)
	{
		if (user_p[i].seed_money == 0)
		{
			printf("\n\n\n\n");
			printf("                               □□□□□□□□□□□\n");
			printf("                               □  죄 송 합 니 다  □\n");
			printf("                               □□□□□□□□□□□");
			printf("\n\n\n\n\n\n\n");
			printf("%d번 플레이어 %s님께서는 현재 잔액이 %d원 이므로 게임에 참여하실수 없습니다.\n", i + 1, user_p[i].name, user_p[i].seed_money);
			getchar();
			system("cls");
			continue; // 만약에 잔고가 0원이면 i 1증가하고 for문 조건으로 다시넘어감
		}
	checkpoint3:

		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("   %d번 플레이어 %s님! 배팅하실 경주마의 번호를 선택해주세요.  (1~4번 마) : ", i + 1, user_p[i].name);
		scanf("%d", &user_p[i].player_choice);

		if (user_p[i].player_choice == 1 || user_p[i].player_choice == 2 || user_p[i].player_choice == 3 || user_p[i].player_choice == 4) // 1,2,3,4번 말중 골랐을 경우
		{
			//printf("%d번 플레이어 %s님께서는 %d번 경주마에 배팅하셨습니다.", i + 1, user_p[i]->name, user_p[i]->player_choice);
			while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
			system("cls");
		}
		else // 1,2,3,4 빼고 다른걸 입력한 경우
		{
			printf("                                 다시 선택해주세요."); // 좌측 띄어쓰기 33개
			user_p[i].player_choice = 0; // game_count 값 초기화
			while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
			getchar();
			system("cls");
			goto checkpoint3;
		}

	checkpoint4:

		printf("***********************************************************************************\n");
		printf("*배팅 최소금액은 만원 이며 소지금이 만원 이하일 경우에는 자동으로 전액 배팅됩니다.*\n");
		printf("***********************************************************************************");
		printf("\n\n\n\n\n\n\n\n");
		printf("%s님! 경마에 배팅할 금액을 설정 해주세요. (현재 계좌 잔고 : %d원)\n", user_p[i].name, user_p[i].seed_money);
		printf("배팅 금액 : ");

		if (user_p[i].seed_money <= 10000) // 남은 돈이 10000원 미만이면
		{
			user_p[i].betting_money = user_p[i].seed_money; // 전부 배팅하고
			user_p[i].seed_money = 0; // 잔고 0으로 만듬
			printf("%d\n", user_p[i].betting_money);
			while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
			system("cls"); //화면 지움
		}

		else
		{
			scanf("%d", &user_p[i].betting_money); // 10000원이상이면 배팅금액설정

			if (user_p[i].betting_money >= 10000 && user_p[i].betting_money <= user_p[i].seed_money)
			{
				user_p[i].seed_money = (user_p[i].seed_money) - (user_p[i].betting_money); // 잔고가 더 많으면 잔고에서 배팅한 만큼 뺌
				while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
				system("cls"); //화면 지움
			}
			else
			{
				printf("                   잘못 눌렀습니다. 금액을 제대로 입력 해주세요.\n"); // 좌측 띄어쓰기 23개
				while (getchar() != '\n'); // getchar를 통해 엔터를 눌러 개행하여 버퍼에 저장된 scanf값을 제거 (제거 안할시에 무한루프 빠짐)
				getchar();
				user_p[i].betting_money = 0; // 배팅머니 값 초기화
				system("cls");
				goto checkpoint4;
			}
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                             잠시후 게임을 실행합니다. ");
	Sleep(2000); // 2초 후 게임 시작
	system("cls");
}

void betting_result(struct game_info *user_p, int *winner_p, int people_count)
{
	int i, j, count = 0;
	for (i = 0; i < people_count; i++)
	{
		for (j = 0; j < 4; j++) // 플레이어가 고른 번호와 1번부터 비교
		{
			if (user_p[i].player_choice != 0 && user_p[i].player_choice == winner_p[j + 1]) // 선택값이 0이아니고(잔고가 0원일때) 플레이어가 고른 번호와 우승번호가 같으면
			{
				printf("\n\n\n\n\n\n\n\n");
				printf("                               □□□□□□□□□□□\n");
				printf("                               □  축 하 합 니 다  □\n");
				printf("                               □□□□□□□□□□□\n");
				printf("\n\n\n\n\n");
				printf("       %d번 플레이어 %s님 께서 %d원 배팅하여 %d원 획득하셨습니다!!!", i + 1, user_p[i].name, user_p[i].betting_money, 2 * (user_p[i].betting_money));
				getchar();
				system("cls"); // 화면지우기
				user_p[i].betting_money = user_p[i].betting_money * 2; // 배팅한 금액을 2배한뒤
				user_p[i].seed_money += user_p[i].betting_money; // 잔액에 다시 넣음
				i++; // 바로 다음플레이어로 넘김
			}
			else count += 1; // 아무도 당청되지 못했을경우를 거르기위해
		}
	}

	if (count == people_count * 4) // 말수 X 사람수 == 결국 아무도 못맞춘거
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                      □□□□□□□□□□□□□□□□□□□□\n");
		printf("                      □아무도 우승말을 맞추지 못하셨습니다.□\n"); //좌측공백 24
		printf("                      □□□□□□□□□□□□□□□□□□□□\n");
		getchar();
		system("cls");
	}
	for (i = 0; i < people_count; i++)
	{
		user_p[i].player_choice = 0; // 말선택 초기화
		user_p[i].betting_money = 0; // 배팅 금액 초기화
	}
	for (i = 1; i < 5; i++)
	{
		winner_p[i] = 0;  // 우승말 초기화
	}
}

void game_result_ready(struct game_info *user_p, int people_count)
{
	int i, j;
	for (i = 0; i < people_count; i++) // 위에서 정한 플레이어숫자(people_count)만큼을 포인터를 이용해 접근
	{

		for (j = 0; j < people_count; j++) // 이중 for문 적용
		{
			if (user_p[i].seed_money < user_p[j].seed_money) (user_p[i].rank)++; // 다른유저와 보유 잔액을 비교해서 더 적으면 등수에 +1을 함
		}
	}
}

void game_result(struct game_info *user, int people_count)
{
	printf("\n\n\n\n");

	printf("                               □□□□□□□□□□□\n");
	printf("                               □  게  임  결  과  □\n");
	printf("                               □□□□□□□□□□□");
	printf("\n\n\n\n");
	printf("                        ***********************************\n"); // 좌측 띄어쓰기 26
	for (int i = 0; i < people_count; i++)
	{
		for (int j = 0; j < people_count; j++)
		{
			if (user[j].rank == i + 1) printf("                        **%d등**%10d원**%10s님** \n", i + 1, user[j].seed_money, user[j].name); //26
		}
	}
	printf("                        ***********************************\n");
	getchar();
}


/*

char run_score = {
"                    ********************                    ",
"                    **  경마  전광판  **                    ",
"                    ********************                    ",
"                    *******           **                    ",
"                    **1등**           **                    ",
"                    *******           **                    ",
"                    **2등**           **                    ",
"                    *******           **                    ",
"                    **3등**           **                    ",
"                    *******           **                    ",
"                    **4등**           **                    ",
"                    ********************                    ",

}
}*/

/*------------------------------------게임판 모양------------------------------------------
printf("################################################################################");
printf("#*****S*|                                                                  |***#");
printf("#*(1)*T*|                                                                  |*F*#");
printf("#*****A*|                                                                  |*I*#");
printf("#*(2)*R*|                                                                  |*N*#");
printf("#*****T*|                                                                  |*I*#");
printf("#*(3)*L*|                                                                  |*S*#");
printf("#*****I*|                                                                  |*H*#");
printf("#*(4)*N*|                                                                  |*!*#");
printf("#*****E*|                                                                  |***#");
printf("################################################################################");
*/

/* ---------------------------------------------------------------------------Fix log------------------------------------------------------------------------------------
20160604 am 01:37

수정 전 :
if (f == 2)
{
if (n1 > 70 && n1 < 75) a = 75 - n1; //68에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
else a = (rand() % 5 + 1);
//tmp = field[2][n];
field[2][n1] = field[2][n1 + a];
field[2][n1 + a] = '@';
n1 += a;
Sleep(50); // 시간을 느리게 처리해서 동점자가 생기거나 프로그램 처리가 너무 빨라서 예외생기는것 방지
}
수정 후 :
if (f == 2)
{
if (n1 > 70 && n1 < 75) a = 75 - n1; //68에서 최대 5칸 가면 75만족 하지만 69~74 사이에서는 75을 넘을수도 있기때문에 a를 변경해서 강제로 75으로 이동
else a = (rand() % 5 + 1);
field[2][n1] = field[2][n1 + a];
field[2][n1 + a] = '@';
n1 += a;
}
수정 내용 : 화면이 이상하게 끊겨서 If 파트별로 Sleep 함수 제거함

20160604 am 02:14

수정 전 : while (field[2][75] != '@' && field[4][75] && '@' && field[6][75] != '@' && field[8][75] != '@') // 말 어느 4개중 마지막 라인 field[][75] 에 들어올때까지 반복

수정 후 : while (n1 != 75 && n2 != 75 && '@' && n3 != 75 && n4 != 75) // 말 어느 4개중 마지막 라인 field[][75] 에 들어올때까지 반복

수정 내용 : 수정 전으로 컴파일 할 시에 finish 라인을 넘어 가는 오류 발생, 아마도 특정값을 검사하기 이전에 실행이 되버려서 이런듯 하다.
그래서 애매 모호하게 기준을 정한걸 확실하게 말의 위치로 정함 n(x) != 75

20160604 am 02:47

수정 전 :



*/
