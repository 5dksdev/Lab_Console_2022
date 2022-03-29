#include <iostream>
#include <fstream>

#include "Schedule_Category.h"

enum class Do
{
	Check		= 1,
	Uncheck		= 2,
	Statistics	= 3,
	SaveAndQuit = 4,
	Reset		= 999,
};

const Do SelectWhatToDo();
void LoadData(Category * categories, const std::string & filePath);
void SaveData(Category * categories, const std::string & filePath);
void Check(Category * categories);
void Uncheck(Category * categories);
void Statistics(Category * categories);
void Reset(Category * categories);

int main()
{
	bool quit{ false };

	Category categories[Category::M_CategoryCount]{
		Category(Category::Name::ReadBooks),
		Category(Category::Name::PlayGames),
		Category(Category::Name::CleanMyRoom),
		Category(Category::Name::Study),
		Category(Category::Name::Work),
		Category(Category::Name::WriteStories),
		Category(Category::Name::GoWalk),
		Category(Category::Name::Exercise) };

	LoadData(categories, "ScheduleData.txt");

	while (!quit)
	{
		switch (SelectWhatToDo())
		{
			case Do::Check:
			{
				Check(categories); break;
			}
			case Do::Uncheck:
			{
				Uncheck(categories); break;
			}
			case Do::Statistics:
			{
				Statistics(categories); break;
			}
			case Do::SaveAndQuit:
			{
				quit = true;

				SaveData(categories, "ScheduleData.txt"); break;
			}
			case Do::Reset:
			{
				Reset(categories); break;
			}
		}
	}

	return 0;
}

const Do SelectWhatToDo()
{
	std::cout << "=== Schedule Manager ==="	<< std::endl;
	std::cout << "1. 체크하기"				<< std::endl;
	std::cout << "2. 되돌리기"				<< std::endl;
	std::cout << "3. 현황 보기"				<< std::endl;
	std::cout << "4. 저장 후 종료"			<< std::endl;
	std::cout << "999. 리셋하기"				<< std::endl;
	std::cout << "========================" << std::endl;

	std::size_t selection{ 0 };

	std::cout << "선택: ";
	std::cin >> selection;

	system("cls");

	return static_cast<Do>(selection);
}

void LoadData(Category * categories, const std::string & filePath)
{
	std::ifstream in_scheduleData(filePath);

	if (in_scheduleData.is_open())
	{
		for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
		{
			categories[i].SetNowValue(in_scheduleData.get() - '0');
		}
	}

	in_scheduleData.close();
}

void SaveData(Category * categories, const std::string & filePath)
{
	std::ofstream out_scheduleData(filePath);

	if (out_scheduleData.is_open())
	{
		for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
		{
			char data{ static_cast<char>(categories[i].GetNowValue()) + '0' };

			out_scheduleData.write(&data, 1);
		}
	}

	out_scheduleData.close();
}

void Check(Category * categories)
{
	std::cout << "=== 체크하기 ==="	<< std::endl;

	for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
	{
		std::cout << i + 1 << ". " << Category::M_CategoryNames[i] << std::endl;
	}

	std::cout << "9. 뒤로 가기"		<< std::endl;
	std::cout << "==============="	<< std::endl;

	std::size_t selection{ 0 };

	std::cout << "선택: ";
	std::cin >> selection;

	if (selection < 1 || selection > 8) { return; }

	categories[selection - 1].SetNowValue(categories[selection - 1].GetNowValue() + 1);

	system("cls");
}

void Uncheck(Category * categories)
{
	std::cout << "=== 되돌리기 ==="	<< std::endl;

	for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
	{
		std::cout << i + 1 << ". " << Category::M_CategoryNames[i] << std::endl;
	}

	std::cout << "9. 뒤로 가기"		<< std::endl;
	std::cout << "==============="	<< std::endl;

	std::size_t selection{ 0 };

	std::cout << "선택: ";
	std::cin >> selection;

	if (1 <= selection && selection <= 8 && categories[selection - 1].GetNowValue() > 0)
	{
		categories[selection - 1].SetNowValue(categories[selection - 1].GetNowValue() - 1);
	}

	system("cls");
}

void Statistics(Category * categories)
{
	std::cout << "=== 현황 보기 ==="	<< std::endl;

	for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
	{
		std::cout << Category::M_CategoryNames[i] << ": " << categories[i].GetNowValue() << " / " << Category::M_MaxValues[i];
		std::cout << " (" << static_cast<std::size_t>(static_cast<float>(categories[i].GetNowValue()) / static_cast<float>(Category::M_MaxValues[i]) * 100.0f) << "%";

		if (categories[i].IsCompleted())
		{
			std::cout << " 완료!";
		}

		std::cout << ")" << std::endl;
	}

	std::cout << "================" << std::endl;

	if (Category::IsCompletedAll(categories))
	{
		std::cout << "[ 이번 주 목표 모두 달성! ]" << std::endl << std::endl;
	}

	system("pause");
	system("cls");
}

void Reset(Category * categories)
{
	for (std::size_t i{ 0 }; i < Category::M_CategoryCount; ++i)
	{
		categories[i].SetNowValue(0);
	}

	system("cls");
}