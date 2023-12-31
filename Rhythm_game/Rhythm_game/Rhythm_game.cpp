#include <stdio.h>
#include <Windows.h>
#include <MMSystem.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#pragma comment(lib, "winmm.lib")

#define Background_Run_Lads_Run "Deemo - KillerBlood - Run Lads Run.wav"
#define Background_REUNION "Deemo-3.2_-REUNION-Duo-Blade-Against-Ice-vs-モリモリあつし.wav"
#define Background_ANIMA "Deemo 2.0 - Xi - Anima.wav"
#define MAP_MAX_X 60
#define MAP_MAX_Y 44
#define Sleep_Time(x) x

char Map[40][48] = // 기본 맵
{
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"├---------┼---------┼---------┼---------┤\n",
	"│         │         │         │         │\n",
	"└---------┴---------┴---------┴---------┘\n"
};

char Note_Map[5][48] = // 앞으로 매핑 할 맵
{
	"│ ■■■■│         │         │         │\n",
	"│         │ ■■■■│         │         │\n",
	"│         │         │ ■■■■│         │\n",
	"│         │         │         │ ■■■■│\n",
	"│         │         │         │         │\n"
};

char Mapping_Map[40][48] // 화면에 매핑할 맵
{
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n",
	"│         │         │         │         │\n"
};

char Menu[14][41] // 기본 매뉴 / 화면에 매핑할 매뉴
{
	"┌-----------------------------------┐\n",
	"│                                   │\n",
	"│                      <<---        │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"│                                   │\n",
	"└-----------------------------------┘\n"
};

char Menu_con[3][41] // 메뉴에 매핑할 맵
{
	"│                      <<---        │\n",
	"│                                   │\n",
	"│                        <<---      │\n"
};

char PGM[3][10] // 판정에 따른 Perfect, Great, Miss
{
	"Perfect!!",
	"Great!   ",
	"Miss...  "
};

struct user // 유저 랭킹을 불러올때 값을 저장할 구조체
{
	int score;
	char name[20];
};

char MainMenu[] = "메인 메뉴 : P";

// 함수 원형 선언문들

void Buffer_Create();
void Buffer_Write(int x, int y, char string[]);
void Buffer_Flipping();
void Buffer_Delete();
void Buffer_Close();
void Buffer_Write_Note(char string[]);
void Write_txt(char string[], char *txt);
void gotoxy(int x, int y);
void Player_Scan_Note(const char *txt);
void Play_Rhythm_Game(const char *txt);
char *Num_Change(int num);
void Setting_sink();
void Panjung(int *score, int *count, char *Note);
void Write_User(char *name, int score);
void Print_rank();
void Choice_music(int Mode);

HANDLE hBuffer[2]; //버퍼 핸들
int nScreenIndex = 0; //현재 선택 버퍼가 뭔지 저장

int Note_Y = 0; // 악보 작성시 값을 받기위한 변수
int Time = 40; // 몇 초 단위로 노트를 내릴지 결정

typedef struct user User; // struct user 자료형을 User 자료형으로 변경

int main()
{
	int i, Mode_num = 2, Page = 1; // 각각 몇 번째 모드인지 판별하기 위한 변수와 현재 페이지를 나타내는 변수 선언
	char Mode; // 위, 아래를 받기위한 변수 선언

	while (1)
	{
		system("cls"); // 화면 초기화
		system("mode con cols=80 lines=20"); // 가로 80 세로 20으로 cmd창 설정
		PlaySound(NULL, NULL, NULL); // 소리가 재생될시에 소리 off

		Mode_num = 2; // 기본 모드 값을 가장 위인 2로 설정

		for (i = 1; i < 13; i++) // 메뉴를 빈 공간으로 초기화
			strcpy(Menu[i], Menu_con[1]);

		strcpy(Menu[Mode_num], Menu_con[0]); // 현재 모드 값(2)에 <<--를 매핑 

		while (1)
		{
			Page = 1; // 현재 패이지를 1로 설정

			for (i = 0; i < 14; i++) // 메뉴를 출력
			{
				gotoxy(19, 3 + i);
				printf("%s", Menu[i]);
			}

			// 가로 25, 세로 5,8,11,14에 각각 값을 매핑
			gotoxy(25, 5);
			printf("1. 게임 시작");
			gotoxy(25, 8);
			printf("2. 노트 제작");
			gotoxy(25, 11);
			printf("3. 싱크 설정");
			gotoxy(25, 14);
			printf("-> 다음 페이지");

			if (kbhit != 0) // 만약 키보드에서 입력이 있다면
			{
				Mode = getch(); // Mode 변수에 입력 받은 키 값을 저장

				if (Mode == 'w') // Mode가 w이면
				{
					if (Mode_num != 2) // 모드 값이 최고 값이 아닐경우
					{
						// 현재 <<--를 초기화 해주고 3칸 밑에 <<--를 매핑
						strcpy(Menu[Mode_num], Menu_con[1]); 
						Mode_num -= 3;
						strcpy(Menu[Mode_num], Menu_con[0]);
					}

				}
				if (Mode == 's')
				{
					if (Mode_num != 11) // Mode가 s이면
					{
						// 현재 <<--를 초기화 해주고 3칸 위에 <<--를 매핑
						strcpy(Menu[Mode_num], Menu_con[1]);
						Mode_num += 3;
						strcpy(Menu[Mode_num], Menu_con[0]);
					}
				}

				if (Mode == 13) // Mode가 13(엔터)면
					break;
			}
		}
		switch (Mode_num)
		{
		case 2:Choice_music(1); break;
		case 5:Choice_music(2); break;
		case 8:Setting_sink(); break;
		case 11:Page = 2; break; // 페이지를 2로 넘기기위한 값 변경
		}

		if (Page == 2) // Page 변수가 2일 경우
		{

			system("mode con cols=80 lines=20");

			Mode_num = 2;

			for (i = 1; i < 13; i++)
				strcpy(Menu[i], Menu_con[1]);

			strcpy(Menu[Mode_num], Menu_con[0]);

			while (1)
			{
				for (i = 0; i < 14; i++)
				{
					gotoxy(19, 3 + i);
					printf("%s", Menu[i]);
				}

				gotoxy(25, 5);
				printf("4. 유저 랭킹");
				gotoxy(25, 8);
				printf("5. 게임 종료");
				gotoxy(25, 11);
				printf("시공");
				gotoxy(25, 14);
				printf("<- 이전 페이지");

				if (kbhit != 0)
				{
					Mode = getch();

					if (Mode == 'w')
					{
						if (Mode_num == 11) // 중간에 시공부분을 건너뛰어 주기위해
						{
							strcpy(Menu[Mode_num], Menu_con[1]);
							Mode_num -= 6;
							strcpy(Menu[Mode_num], Menu_con[0]);
						}
						else
						{
							if (Mode_num != 2)
							{
								strcpy(Menu[Mode_num], Menu_con[1]);
								Mode_num -= 3;
								strcpy(Menu[Mode_num], Menu_con[0]);
							}
						}

					}
					if (Mode == 's')
					{
						if (Mode_num == 5) // 중간에 시공부분을 건너뛰어 주기위해
						{
							strcpy(Menu[Mode_num], Menu_con[1]);
							Mode_num += 6;
							strcpy(Menu[Mode_num], Menu_con[0]);
						}
						else
						{
							if (Mode_num != 11)
							{
								strcpy(Menu[Mode_num], Menu_con[1]);
								Mode_num += 3;
								strcpy(Menu[Mode_num], Menu_con[0]);
							}
						}
					}

					if (Mode == 13)
						break;
				}
			}
			switch (Mode_num)
			{
			case 2:Print_rank(); break;
			case 5: gotoxy(79, 18); return 0;
			case 8:
			case 11:break;
			}
		}
	}
}


void Buffer_Create() // 버퍼를 생성해주는 함수 선언
{

	COORD size = { MAP_MAX_X, MAP_MAX_Y }; // 버퍼 크기 관련 구조체

	CONSOLE_CURSOR_INFO cci; // 콘솔 커서 관련 변수
	SMALL_RECT rect; // 창 크기 관련 구조체

	// 버퍼의 크기를 설정
	rect.Top = 0;
	rect.Bottom = MAP_MAX_Y;
	rect.Right = 0;
	rect.Left = MAP_MAX_X;

	// 첫 번째 버퍼 생성
	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	// 두 번째 버퍼 생성
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	// 콘솔 커서 깜빡임 제어(_ 이부분)
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}

void Buffer_Write(int x, int y, char string[]) // 버퍼에 값을 써주는 함수 선언
{
	DWORD dw;   //좌표를 저장하기 위한 구조채를 선언.
	COORD CursorPosition = { x, y };    //좌표 설정
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);    //좌표 이동
	WriteFile(hBuffer[nScreenIndex], string, strlen(string), &dw, NULL);    //버퍼에 씀
}

void Buffer_Flipping() // 버퍼를 바꿔 주기위한 함수 선언
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);    //버퍼를 활성하 함으로써 화면에 버퍼의 내용을 한번에 출력
	nScreenIndex = !nScreenIndex;   //다음 버퍼 선택
}

void Buffer_Delete() // 버퍼를 지워주기 위한 함수 선언
{
	COORD Coor = { 0, 0 }; //세번째 줄의 함수를 위한 구조체
	DWORD dw; //세번째 줄의 함수를 위한 구조체
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', MAP_MAX_X * MAP_MAX_Y, Coor, &dw);
	//버퍼의 모든 공간에 스페이스바를 넣어 화면이 지워 진거 처럼 만들고 있는 겁니다.
}

void Buffer_Close() // 버퍼들을 삭제 시키기 위한 함수 선언
{
	CloseHandle(hBuffer[0]); //버퍼 해제
	CloseHandle(hBuffer[1]); //버퍼 해제
}

void Buffer_Write_Note(char string[]) // 버퍼에 한 칸씩 노트를 넣어 주기 위한 함수 선언 (노트 제작 전용)
{
	Note_Y %= 35;

	Buffer_Write(0, Note_Y, string);
	Buffer_Flipping();
	Buffer_Write(0, Note_Y, string);
	Buffer_Flipping();
	Note_Y++;
}

void Write_txt(char string[], const char *txt) // 입력된 값을 txt파일에 저장하기 위한 함수 선언 (노트 제작 전용)
{
	FILE *file_pointer;
	file_pointer = fopen(txt, "a");
	fprintf(file_pointer, string);
	fclose(file_pointer);
}

void gotoxy(int x, int y) // 화면의 위치를 제어하기 위한 함수 선언
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

char *Num_Change(int num) // 숫자를 문자열로 바꾸기 위한 함수 선언
{
	int i = 1, tmp, j;
	char Change[10];
	tmp = num / 10;

	while (tmp != 0) // 숫자의 길이를 알기위한 반복문
	{
		i *= 10;
		tmp /= 10;
	}

	for (j = 0; i != 0; j++) // 각각의 숫자를 문자열에 넣어주기 위한 함수
	{
		switch (num / i)
		{
		case 0:Change[j] = '0'; break;
		case 1:Change[j] = '1'; break;
		case 2:Change[j] = '2'; break;
		case 3:Change[j] = '3'; break;
		case 4:Change[j] = '4'; break;
		case 5:Change[j] = '5'; break;
		case 6:Change[j] = '6'; break;
		case 7:Change[j] = '7'; break;
		case 8:Change[j] = '8'; break;
		case 9:Change[j] = '9'; break;
		}
		num %= i;
		i /= 10;
	}

	// 끝에 문자열의 남김을 방지하기 위한 공백 추가
	Change[j] = ' '; 
	Change[j + 1] = ' ';
	Change[j + 2] = ' ';

	// 문자열의 끝을 알리는 널문자 추가
	Change[j + 3] = '\0';
	return Change;
}

void Player_Scan_Note(const char *txt) // 노트 제작 모드를 실행 하기위한 함수 선언
{
	system("mode con cols=70 lines=44");

	char input;
	int count = 0, i, j, flag = 0;
	clock_t Time_Start, Time_End, Time_This; // 시간을 재기 위한 변수
	FILE *file_pointer; // 파일을 열기위한 포인터 변수 선언

	file_pointer = fopen(txt, "a"); // txt에 저장되어있는 txt파일을 연다

	Buffer_Create(); // 버퍼 생성

	for (i = 0; i < 2; i++) // 버퍼에 화면을 매핑하기위한 반복문
	{
		for (j = 0; j < 40; j++)
			Buffer_Write(0, j, Map[j]);
		Buffer_Flipping();
	}

	// txt에 따라 노래를 재생
	if (!(strcmp(txt, "REUNION.txt")))
		PlaySound(TEXT(Background_REUNION), NULL, SND_ASYNC);
	if (!(strcmp(txt, "Run Lads Run.txt")))
		PlaySound(TEXT(Background_Run_Lads_Run), NULL, SND_ASYNC);
	if (!(strcmp(txt, "ANIMA.txt")))
		PlaySound(TEXT(Background_ANIMA), NULL, SND_ASYNC);

	Time_Start = clock(); // 처음 시간을 잰다

	while (1) // 키 입력을 받기위한 반복문
	{
		if (kbhit() != 0) // 키 입력이 있다면
		{
			input = getch(); // input에 입력 받은 값을 저장

			if (input == 'p') // 입력받은 값이 p일 경우 현재 반복문에서 나감
			{
				PlaySound(NULL, NULL, NULL);
				break;
			}

			if (input == 'd') // 입력받은 값이 d일 경우 Note_Map[0]을 매핑하고 파일에 저장
			{
				Buffer_Write_Note(Note_Map[0]);
				Write_txt(Note_Map[0], txt);
				flag = 1;
			}
			if (input == 'f') // 입력받은 값이 f일 경우 Note_Map[1]을 매핑하고 파일에 저장
			{
				Buffer_Write_Note(Note_Map[1]);
				Write_txt(Note_Map[1], txt);
				flag = 1;
			}
			if (input == 'j') // 입력받은 값이 j일 경우 Note_Map[2]을 매핑하고 파일에 저장
			{
				Buffer_Write_Note(Note_Map[2]);
				Write_txt(Note_Map[2], txt);
				flag = 1;
			}
			if (input == 'k') // 입력받은 값이 k일 경우 Note_Map[3]을 매핑하고 파일에 저장
			{
				Buffer_Write_Note(Note_Map[3]);
				Write_txt(Note_Map[3], txt);
				flag = 1;
			}
		}

		Buffer_Flipping(); // 버퍼를 변경

		// 메인 메뉴 : P 를 매핑
		Buffer_Write(50, 2, MainMenu); 
		nScreenIndex = !nScreenIndex;
		Buffer_Write(50, 2, MainMenu);
		nScreenIndex = !nScreenIndex;

		Time_End = clock(); // 위의 과정을 돌때마다 시간을 저장

		if (flag) // 한번도 입력이 없을 경우 실행되지않음
		{
			if ((double)Time_End - Time_Start > 45) // 위의 과정에서 0.045초를 넘어갈 경우 Note[4]를 매핑하고 파일에 저장
			{
				Buffer_Write_Note(Note_Map[4]);
				Write_txt(Note_Map[4], txt);
				Time_Start = clock(); // 시간을 다시 초기화
			}
		}
	}

	// p를 통해 끝날 경우
	Buffer_Close(); // 앞으로 쓰기위해 버퍼를 종료
	fclose(file_pointer); // 파일을 닫음

	system("cls"); // 화면 초기화
}

void Play_Rhythm_Game(const char *txt) // 리듬게임을 실행하기 위한 함수 선언
{
	system("mode con cols=70 lines=44");
	char tmp[2][48], from_a_txt[48], Mode, show[10], Combo[20], Score[20], Name[20];
	int i, input, count = 0, k, j, flag = 0, Out = 0, score = 0, write = 1;
	FILE *file_pointer; // 파일을 열기위한 포인터 변수 선언

	file_pointer = fopen(txt, "r"); // txt에 저장된 파일을 연다

	Buffer_Create(); // 버퍼 생성

	for (i = 0; i < 2; i++) // 버퍼에 화면을 매핑
	{
		for (j = 0; j < 40; j++)
			Buffer_Write(0, j, Map[j]);
		Buffer_Flipping();
	}

	for (i = 0; i < 40; i++) // 화면에 매핑할 맵을 초기화
		strcpy(Mapping_Map[i], Note_Map[4]);

	if (file_pointer == NULL) // 파일이 없을 경우 실행하지않음
	{
		Buffer_Close();
		printf("파일이없습니다.");
		Sleep(2000);
		return;
	}

	while (!feof(file_pointer)) // 모든 파일을 불러올때까지 반복
	{

		if (flag <= 10) // 아래의 과정을 10번 반복한 후에 노래 재생
		{
			if (!(strcmp(txt, "REUNION.txt")))
				PlaySound(TEXT(Background_REUNION), NULL, SND_ASYNC);
			if (!(strcmp(txt, "Run Lads Run.txt")))
				PlaySound(TEXT(Background_Run_Lads_Run), NULL, SND_ASYNC);
			if (!(strcmp(txt, "ANIMA.txt")))
				PlaySound(TEXT(Background_ANIMA), NULL, SND_ASYNC);
			flag++;
		}

		for (i = 0; i < 35; i++) // 화면에 맵을 매핑
			Buffer_Write(0, i, Mapping_Map[i]);

		Buffer_Write(0, i + 1, Map[36]); // Map[36]이 삭제되는 경우를 방지하기 위해 버퍼에 한번 매핑

		if (kbhit() != 0) // 입력된 값이 있을경우
		{
			input = getch(); // input에 값을 저장

			if (input == 'p') // 입력된 값이 p일 경우
			{
				PlaySound(NULL, NULL, NULL);
				Out = 1; // 아래의 반복문에서 나가기위해 값을 설정
				write = 0; // p를 통해 나갈경우 랭킹에 입력되는 것을 방지하기 위해 값을 설정
				break; // 현재 반복문에서 나감
			}

			if (input == 'd') // 입력된 값이 d일 경우
			{
				// 버퍼에 Note_Map[0]을 매핑
				Buffer_Write(0, 36, Note_Map[0]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[0]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[0]);
			}
			if (input == 'f') // 입력된 값이 f일 경우
			{
				// 버퍼에 Note_Map[1]을 매핑
				Buffer_Write(0, 36, Note_Map[1]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[1]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[1]);
			}
			if (input == 'j') // 입력된 값이 j일 경우
			{
				// 버퍼에 Note_Map[2]을 매핑
				Buffer_Write(0, 36, Note_Map[2]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[2]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[2]);
			}
			if (input == 'k') // 입력된 값이 k일 경우
			{
				// 버퍼에 Note_Map[3]을 매핑
				Buffer_Write(0, 36, Note_Map[3]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[3]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[3]);
			}
		}

		// Combo : 숫자 / Score : 숫자 / 메인 메뉴 : P 를 매핑하기위한 과정
		strcpy(Combo, "Combo : ");
		strcpy(Score, "Score : ");
		strcat(Combo, Num_Change(count));
		strcat(Score, Num_Change(score));
		Buffer_Write(50, 27, Combo);
		Buffer_Write(50, 2, MainMenu);
		Buffer_Write(50, 17, Score);
		nScreenIndex = !nScreenIndex;
		Buffer_Write(50, 27, Combo);
		Buffer_Write(50, 2, MainMenu);
		Buffer_Write(50, 17, Score);
		nScreenIndex = !nScreenIndex;

		// 화면에 매핑될 맵을 한칸씩 밈
		for (i = 1; i < 40; i++)
		{
			if (i == 1)
			{
				strcpy(tmp[i - 1], Mapping_Map[i]);
				strcpy(Mapping_Map[i], Mapping_Map[i - 1]);
			}
			else
			{
				strcpy(tmp[1], Mapping_Map[i]);
				strcpy(Mapping_Map[i], tmp[0]);
				strcpy(tmp[0], tmp[1]);
			}
		}

		// 입력되지 않은 노트를 Miss 처리해주기 위한 과정
		if ((!strcmp(Mapping_Map[39], Note_Map[0])) || (!strcmp(Mapping_Map[39], Note_Map[1])) || (!strcmp(Mapping_Map[39], Note_Map[2])) || (!strcmp(Mapping_Map[39], Note_Map[3])))
		{
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			count = 0;
		}

		// 한 줄씩 파일에서 불러옴
		fgets(from_a_txt, sizeof(from_a_txt), file_pointer);
		strcpy(Mapping_Map[0], from_a_txt);

		// 화면 전환
		Buffer_Flipping();

		Sleep(Sleep_Time(Time)); // 싱크 값의에 따라 노트를 노트를 내림
	}

	for (k = 0; k < 37; k++) // 마지막 노트를을 처리해주기 위한 반복문
	{
		if (Out) // 위에서 p를 눌렀을 경우 탈출
			break;

		for (i = 0; i < 35; i++) // 화면에 맵을 매핑
			Buffer_Write(0, i, Mapping_Map[i]);

		Buffer_Write(0, i + 1, Map[36]);  // Map[36]이 삭제되는 경우를 방지하기 위해 버퍼에 한번 매핑

		if (kbhit() != 0)
		{
			input = getch();

			if (input == 'p')
			{
				PlaySound(NULL, NULL, NULL);
				write = 0;
				break;
			}

			if (input == 'd')
			{
				Buffer_Write(0, 36, Note_Map[0]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[0]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[0]);
			}
			if (input == 'f')
			{
				Buffer_Write(0, 36, Note_Map[1]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[1]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[0]);
			}
			if (input == 'j')
			{
				Buffer_Write(0, 36, Note_Map[2]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[2]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[0]);
			}
			if (input == 'k')
			{
				Buffer_Write(0, 36, Note_Map[3]);
				nScreenIndex = !nScreenIndex;
				Buffer_Write(0, 36, Note_Map[3]);
				nScreenIndex = !nScreenIndex;
				Panjung(&score, &count, Note_Map[0]);
			}
		}

		strcpy(Combo, "Combo : ");
		strcpy(Score, "Score : ");
		strcat(Combo, Num_Change(count));
		strcat(Score, Num_Change(score));
		Buffer_Write(50, 27, Combo);
		Buffer_Write(50, 2, MainMenu);
		Buffer_Write(50, 17, Score);
		nScreenIndex = !nScreenIndex;
		Buffer_Write(50, 27, Combo);
		Buffer_Write(50, 2, MainMenu);
		Buffer_Write(50, 17, Score);
		nScreenIndex = !nScreenIndex;

		for (i = 1; i < 37; i++)
		{
			if (i == 1)
			{
				strcpy(tmp[i - 1], Mapping_Map[i]);
				strcpy(Mapping_Map[i], Mapping_Map[i - 1]);
			}
			else
			{
				strcpy(tmp[1], Mapping_Map[i]);
				strcpy(Mapping_Map[i], tmp[0]);
				strcpy(tmp[0], tmp[1]);
			}
		}

		if ((!strcmp(Mapping_Map[39], Note_Map[0])) || (!strcmp(Mapping_Map[39], Note_Map[1])) || (!strcmp(Mapping_Map[39], Note_Map[2])) || (!strcmp(Mapping_Map[39], Note_Map[3])))
		{
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			count = 0;
		}

		strcpy(Mapping_Map[0], Note_Map[4]);

		Buffer_Flipping();
		Sleep(Sleep_Time(Time));

	}

	// 파일을 닫고 버퍼를 삭제해줌
	fclose(file_pointer);
	Buffer_Close();

	// 아래를 출력 시켜주기위해 화면을 초기화
	system("cls");

	if (write) // p로 위의 과정이 끝나지 않았을경우
	{
		PlaySound(NULL, NULL, NULL); // 노래가 재생중이면 노래 재생을 멈춤
		gotoxy(10, 20); // cmd 좌표 가로10 세로20 으로 이동
		printf("이름을 입력해 주세요 : ");
		scanf("%19s", Name); // 최대 19글자를 입력 받음
		Write_User(Name, score); // 입력받은 이름과 위에서 나온 점수를 파일에 저장
	}
}

void Setting_sink() // 싱크를 설정하기 위한 함수 선언
{
	char input;
	system("cls"); // 화면 초기화
	while (1)
	{
		gotoxy(22, 7);
		printf("현재 싱크 : %3d (기본 40 / 적정 32 ~ 42)", Time); // 현재 싱크를 출력
		gotoxy(9, 12);
		printf("싱크 조절 W 업, S 다운, 엔터키를 입력시 처음 화면으로 돌아갑니다");

		if (kbhit != 0) // 키 입력이 있을경우
		{
			input = getch(); // input에 입력받은 값을 저장

			if (input == 'w') // 입력 받은 값이 w일 경우
			{
				if (Time < 100) // 싱크 값이 100보다 작을 경우
					Time++;
			}
			if (input == 's') // 입력 받은 값이 s일 경우
			{
				if (Time > 0) // 싱크 값이 0보다 작을 경우
					Time--;
			}
			if (input == 13) // 입력 받은 값이 13(엔터)일 경우
				break; // 반복문에서 나가줌
		}

	}
}

void Panjung(int *score, int *count, char *Note) // Perfect. Great, Miss를 확인 하기위한 함수 선언
{
	int i;

	for (i = 0; i < 4; i++) // 가장 밑에서부터 4칸을 확인
	{
		// 4칸중에 Note가 있을경우 count(콤보)를 하나 올리고 점수를 70점 올린뒤 그 위치에 있는 Note를 초기화 해주고 Perfect를 버퍼에 매핑
		if (!(strcmp(Note, Mapping_Map[37 - i])))
		{
			Buffer_Write(50, 22, PGM[0]);
			nScreenIndex = !nScreenIndex;
			Buffer_Write(50, 22, PGM[0]);
			nScreenIndex = !nScreenIndex;
			strcpy(Mapping_Map[37 - i], Note_Map[4]);
			*score += 70;
			*count += 1;
			return;
		}
	}

	for (i = 0; i < 2; i++) // 위에서 확인한 4칸위에 2칸을 확인
	{
		// 2칸중에 Note가 있을경우 count(콤보)를 하나 올리고 점수를 40점 올린뒤 그 위치에 있는 Note를 초기화 해주고 Great를 버퍼에 매핑
		if (!(strcmp(Note, Mapping_Map[33 - i]))) 
		{
			Buffer_Write(50, 22, PGM[1]);
			nScreenIndex = !nScreenIndex;
			Buffer_Write(50, 22, PGM[1]);
			nScreenIndex = !nScreenIndex;
			strcpy(Mapping_Map[33 - i], Note_Map[4]);
			*score += 40;
			*count += 1;
			return;
		}
	}

	for (i = 0; i < 2; i++) // 위에서 확인한 6칸 위에 2칸을 확인
	{
		// 2칸중에 Note가 있을경우 count(콤보)를 0으로 초기화하고 그 위치에 있는 Note를 초기화 해주고 Miss를 버퍼에 매핑
		if (!(strcmp(Note, Mapping_Map[31 - i])))
		{
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			Buffer_Write(50, 22, PGM[2]);
			nScreenIndex = !nScreenIndex;
			strcpy(Mapping_Map[31 - i], Note_Map[4]);
			*count = 0;
			return;
		}
	}
}

void Write_User(char *name, int score) // 게임이 실행된 뒤에 사용자의 이름과 점수를 파일에 저장
{
	FILE *file_pointer; // 파일을 열기위한 포인터 변수 선언

	file_pointer = fopen("rank.txt", "a"); // rank.txt파일을 연다

	fprintf(file_pointer, "%s %d\n", name, score); // 이름(%s) 점수(%d)\n을 파일에 입력

	fclose(file_pointer); // 파일을 닫아줌
}

void Print_rank() // 저장된 사용자들의 정보를 출력하기 위한 함수 선언
{
	system("cls"); // 화면 초기화
	FILE *file_pointer; // 파일을 열기위한 포인터 변수 선언
	int i, j, k;
	User temp;
	User *tmp = (User*)malloc(sizeof(User) * 1000), *user; // 기본적으로 tmp를 1000만큼 크기를 키워주고 그 값들을 저장하기위한 user 포인터 선언

	file_pointer = fopen("rank.txt", "rt"); // rank.txt파일을 연다

	if (file_pointer == NULL) // rank.txt파일이 없을 경우
	{
		system("cls");
		printf("파일이 없습니다.\n");
		Sleep(3000);
		return;
	}
	for (i = 0; (!feof(file_pointer)); i++) // 파일에 있는 값을 tmp에 저장
		fscanf(file_pointer, "%s %d\n", &tmp[i].name, &tmp[i].score);

	user = (User*)malloc(sizeof(User)*i); // 파일에 있는 값 만큼 user을 동적할당
	
	for (j = 0; j < i; j++) // 각각의 tmp값을 user에 저장
		user[j] = tmp[j];

	free(tmp); // tmp 변수를 초기화해줌

	fclose(file_pointer); // 파일을 닫아줌

	// 점수별로 유저를 설정하기위한 버블 정렬
	for (j = 0; j < i - 1; j++)
	{
		for (k = 0; k < i - 1 - j; k++)
		{
			if (user[k].score < user[k + 1].score)
			{
				temp = user[k];
				user[k] = user[k + 1];
				user[k + 1] = temp;
			}
		}
	}

	// 상위 10명의 이름과 점수를 출력 10명이 안될경우 있는 만큼 출력
	for (j = 0; (j < i) && (j < 10); j++)
	{
		printf("%s %d\n", user[j].name, user[j].score);
	}

	free(user); // user 변수를 초기화
	Sleep(3000);
}

void Choice_music(int Mode) // Mode에 해당하는 노래를 설정하기위한 함수 선언
{
	int i, Music_num = 2;
	char input;

	for (i = 1; i < 13; i++)
		strcpy(Menu[i], Menu_con[1]);

	strcpy(Menu[Music_num], Menu_con[0]);

	while (1)
	{
		for (i = 0; i < 14; i++)
		{
			gotoxy(19, 3 + i);
			printf("%s", Menu[i]);
		}

		gotoxy(25, 5);
		printf("1. Run Lads Run");
		gotoxy(25, 8);
		printf("2. RE:UNION");
		gotoxy(25, 11);
		printf("3. ANIMA");
		gotoxy(25, 14);
		printf("<- 이전 페이지");

		if (kbhit != 0)
		{
			input = getch();

			if (input == 'w')
			{
				if (Music_num != 2)
				{
					strcpy(Menu[Music_num], Menu_con[1]);
					Music_num -= 3;
					strcpy(Menu[Music_num], Menu_con[0]);
				}

			}
			if (input == 's')
			{
				if (Music_num != 11)
				{
					strcpy(Menu[Music_num], Menu_con[1]);
					Music_num += 3;
					strcpy(Menu[Music_num], Menu_con[0]);
				}
			}

			if (input == 13)
				break;
		}
	}

	// Mode가 1일 경우(게임 시작) 각각의 해당하는 값을 가지고 Play_Rhythm_Game 함수를 실행 2일 경우는 Player_Scan_Note 함수를 실행
	if (Mode == 1)
	{
		switch (Music_num)
		{
		case 2:Play_Rhythm_Game("Run Lads Run.txt"); break;
		case 5:Play_Rhythm_Game("REUNION.txt"); break;
		case 8:Play_Rhythm_Game("ANIMA.txt"); break;
		case 11:return;
		}
	}
	else if (Mode == 2)
	{
		switch (Music_num)
		{
		case 2:Player_Scan_Note("Run Lads Run.txt"); break;
		case 5:Player_Scan_Note("REUNION.txt"); break;
		case 8:Player_Scan_Note("ANIMA.txt"); break;
		case 11:return;
		}
	}
}
