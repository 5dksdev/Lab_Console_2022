#pragma once

#include <iostream>

class Category
{
public:
	enum class Name
	{
		ReadBooks,
		PlayGames,
		CleanMyRoom,
		Study,
		Work,
		WriteStories,
		GoWalk,
		Exercise,
	};

public:
	explicit Category(const Name name);

	bool IsCompleted() const;

	void SetNowValue(const std::size_t nowValue) { m_nowValue = nowValue; }

	const std::size_t GetNowValue() const { return m_nowValue; }

public:
	static bool IsCompletedAll(Category * categories);

public:
	static const std::size_t M_CategoryCount{ 8 };
	static const std::size_t M_MaxValues[M_CategoryCount];
	static const std::string M_CategoryNames[M_CategoryCount];

private:
	const std::size_t m_nameID;
	std::size_t m_nowValue;

};