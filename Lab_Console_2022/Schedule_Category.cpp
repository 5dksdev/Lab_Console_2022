#include "Schedule_Category.h"

const std::size_t Category::M_MaxValues[M_CategoryCount]{
	3,	// Read books
	7,	// Play games
	1,	// Clean my room
	2,	// Study
	3,	// Work
	2,	// Write stories
	1,	// Go walk
	7	// Exercise
};

const std::string Category::M_CategoryNames[M_CategoryCount]{
	"å �б�",
	"�����ϱ�",
	"û���ϱ�",
	"�����ϱ�",
	"���ϱ�",
	"�۾���",
	"�����ϱ�",
	"��ϱ�"
};

Category::Category(const Name name) :
	m_nameID	{ static_cast<std::size_t>(name) },
	m_nowValue	{ 0 }
{

}

bool Category::IsCompleted() const
{
	return m_nowValue >= M_MaxValues[m_nameID];
}

bool Category::IsCompletedAll(Category * categories)
{
	for (std::size_t i{ 0 }; i < M_CategoryCount; ++i)
	{
		if (!categories[i].IsCompleted()) { return false; }
	}

	return true;
}
