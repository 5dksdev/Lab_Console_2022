#include <iostream>
#include <fstream>

constexpr unsigned MaxReadBooks		{ 3 };
constexpr unsigned MaxPlayGames		{ 7 };
constexpr unsigned MaxCleanMyRoom	{ 1 };
constexpr unsigned MaxStudy			{ 2 };
constexpr unsigned MaxWork			{ 3 };
constexpr unsigned MaxWriteStories	{ 2 };
constexpr unsigned MaxGoWalk		{ 1 };
constexpr unsigned MaxExercise		{ 7 };

int main()
{
	std::ifstream in_scheduleData("ScheduleData.txt");

	unsigned nowReadBooks		{ 0 };
	unsigned nowPlayGames		{ 0 };
	unsigned nowClearMyRoom		{ 0 };
	unsigned nowStudy			{ 0 };
	unsigned nowWork			{ 0 };
	unsigned nowWriteStories	{ 0 };
	unsigned nowGoWalk			{ 0 };
	unsigned nowExercise		{ 0 };

	if (in_scheduleData.is_open())
	{
		nowReadBooks	= in_scheduleData.get() - '0';
		nowPlayGames	= in_scheduleData.get() - '0';
		nowClearMyRoom	= in_scheduleData.get() - '0';
		nowStudy		= in_scheduleData.get() - '0';
		nowWork			= in_scheduleData.get() - '0';
		nowWriteStories = in_scheduleData.get() - '0';
		nowGoWalk		= in_scheduleData.get() - '0';
		nowExercise		= in_scheduleData.get() - '0';
	}

	in_scheduleData.close();

	bool quit{ false };

	while (!quit)
	{
		system("cls");

		std::cout << "=== Schedule Manager ==="	<< std::endl;
		std::cout << "1. 체크하기"				<< std::endl;
		std::cout << "2. 되돌리기"				<< std::endl;
		std::cout << "3. 현황 보기"				<< std::endl;
		std::cout << "4. 저장 후 종료"			<< std::endl;
		std::cout << "999. 리셋하기"				<< std::endl;
		std::cout << "========================" << std::endl;
		
		unsigned selection{ 0 };

		std::cout << "선택: ";
		std::cin >> selection;

		system("cls");

		switch (selection)
		{
			case 1:
			{
				std::cout << "=== 체크하기 ==="	<< std::endl;
				std::cout << "1. 책 읽기"		<< std::endl;
				std::cout << "2. 게임하기"		<< std::endl;
				std::cout << "3. 청소하기"		<< std::endl;
				std::cout << "4. 공부하기"		<< std::endl;
				std::cout << "5. 일하기"			<< std::endl;
				std::cout << "6. 글쓰기"			<< std::endl;
				std::cout << "7. 외출하기"		<< std::endl;
				std::cout << "8. 운동하기"		<< std::endl;
				std::cout << "9. 뒤로 가기"		<< std::endl;
				std::cout << "==============="	<< std::endl;

				std::cin >> selection;

				switch (selection)
				{
					case 1: ++nowReadBooks;		break;
					case 2: ++nowPlayGames;		break;
					case 3: ++nowClearMyRoom;	break;
					case 4: ++nowStudy;			break;
					case 5: ++nowWork;			break;
					case 6: ++nowWriteStories;	break;
					case 7: ++nowGoWalk;		break;
					case 8: ++nowExercise;		break;
					case 9: break;
				}

				break;
			}
			case 2:
			{
				std::cout << "=== 되돌리기 ==="	<< std::endl;
				std::cout << "1. 책 읽기"		<< std::endl;
				std::cout << "2. 게임하기"		<< std::endl;
				std::cout << "3. 청소하기"		<< std::endl;
				std::cout << "4. 공부하기"		<< std::endl;
				std::cout << "5. 일하기"			<< std::endl;
				std::cout << "6. 글쓰기"			<< std::endl;
				std::cout << "7. 외출하기"		<< std::endl;
				std::cout << "8. 운동하기"		<< std::endl;
				std::cout << "9. 뒤로 가기"		<< std::endl;
				std::cout << "==============="	<< std::endl;

				std::cin >> selection;

				switch (selection)
				{
					case 1: --nowReadBooks;		break;
					case 2: --nowPlayGames;		break;
					case 3: --nowClearMyRoom;	break;
					case 4: --nowStudy;			break;
					case 5: --nowWork;			break;
					case 6: --nowWriteStories;	break;
					case 7: --nowGoWalk;		break;
					case 8: --nowExercise;		break;
					case 9: break;
				}

				break;
			}
			case 3:
			{
				std::cout << "=== 현황 보기 ==="	<< std::endl;
				std::cout << "책 읽기: "		<< nowReadBooks		<< " / " << MaxReadBooks	<< ((nowReadBooks		>= MaxReadBooks)	? " (완료!)" : "") << std::endl;
				std::cout << "게임하기: "		<< nowPlayGames		<< " / " << MaxPlayGames	<< ((nowPlayGames		>= MaxPlayGames)	? " (완료!)" : "") << std::endl;
				std::cout << "청소하기: "		<< nowClearMyRoom	<< " / " << MaxCleanMyRoom	<< ((nowClearMyRoom		>= MaxCleanMyRoom)	? " (완료!)" : "") << std::endl;
				std::cout << "공부하기: "		<< nowStudy			<< " / " << MaxStudy		<< ((nowStudy			>= MaxStudy)		? " (완료!)" : "") << std::endl;
				std::cout << "일하기: "		<< nowWork			<< " / " << MaxWork			<< ((nowWork			>= MaxWork)			? " (완료!)" : "") << std::endl;
				std::cout << "글쓰기: "		<< nowWriteStories	<< " / " << MaxWriteStories << ((nowWriteStories	>= MaxWriteStories) ? " (완료!)" : "") << std::endl;
				std::cout << "외출하기: "		<< nowGoWalk		<< " / " << MaxGoWalk		<< ((nowGoWalk			>= MaxGoWalk)		? " (완료!)" : "") << std::endl;
				std::cout << "운동하기: "		<< nowExercise		<< " / " << MaxExercise		<< ((nowExercise		>= MaxExercise)		? " (완료!)" : "") << std::endl;
				std::cout << "================"	<< std::endl;

				system("pause");

				break;
			}
			case 4:
			{
				std::ofstream out_scheduleData("ScheduleData.txt");
				
				nowReadBooks	+= '0';
				nowPlayGames	+= '0';
				nowClearMyRoom	+= '0';
				nowStudy		+= '0';
				nowWork			+= '0';
				nowWriteStories += '0';
				nowGoWalk		+= '0';
				nowExercise		+= '0';

				if (out_scheduleData.is_open())
				{
					out_scheduleData.write(reinterpret_cast<char *>(&nowReadBooks), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowPlayGames), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowClearMyRoom), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowStudy), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowWork), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowWriteStories), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowGoWalk), 1);
					out_scheduleData.write(reinterpret_cast<char *>(&nowExercise), 1);
				}

				out_scheduleData.close();

				quit = true;

				break;
			}
			case 999:
			{
				nowReadBooks	= 0;
				nowPlayGames	= 0;
				nowClearMyRoom	= 0;
				nowStudy		= 0;
				nowWork			= 0;
				nowWriteStories = 0;
				nowGoWalk		= 0;
				nowExercise		= 0;

				break;
			}
		}
	}

	return 0;
}