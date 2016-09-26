/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, checkInBounds)
{
	Field minefield;

	ASSERT_TRUE(minefield.inBounds(5, 5));
	ASSERT_FALSE(minefield.inBounds(12, 5));
	ASSERT_FALSE(minefield.inBounds(5, 12));
	ASSERT_TRUE(minefield.inBounds(0, 0));
	ASSERT_TRUE(minefield.inBounds(5, 0));
	ASSERT_TRUE(minefield.inBounds(0, 5));
	ASSERT_FALSE(minefield.inBounds(-1, 5));
	ASSERT_FALSE(minefield.inBounds(5, -1));
	
}

TEST(FieldTest, checkInBoundsResized)
{
	Field minefield(20);

	ASSERT_TRUE(minefield.inBounds(15, 15));
	ASSERT_FALSE(minefield.inBounds(22, 5));
	ASSERT_FALSE(minefield.inBounds(5, 22));
	ASSERT_TRUE(minefield.inBounds(0, 0));
	ASSERT_TRUE(minefield.inBounds(15, 0));
	ASSERT_TRUE(minefield.inBounds(0, 15));
	ASSERT_FALSE(minefield.inBounds(-1, 5));
	ASSERT_FALSE(minefield.inBounds(5, -1));
	
}

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );

	minefield.placeMine(0, 5);
	ASSERT_EQ(MINE_HIDDEN, minefile.get(0,5));

	minefield.placeMine(5, 0);
	ASSERT_EQ(MINE_HIDDEN, minefile.get(5,0));

	minefield.placeMine(0, 0);
	ASSERT_EQ(MINE_HIDDEN, minefile.get(0,0));

	minefield.placeMine(12, 5);
	ASSERT_ANY_THROW(minefile.get(12,5));

	minefield.placeMine(5, 12);
	ASSERT_ANY_THROW(minefile.get(5,12));

	minefield.placeMine(12, 12);
	ASSERT_ANY_THROW(minefile.get(12,12));

	minefield.placeMine(-1, 5);
	ASSERT_ANY_THROW(minefile.get(-1,5));

	minefield.placeMine(5, -1);
	ASSERT_ANY_THROW(minefile.get(5,-1));

	minefield.placeMine(-1, -1);
	ASSERT_ANY_THROW(minefile.get(-1,-1));
}
TEST(FieldTest, checkSafe)
{
	Field minefield;

	minefield.placeMine(5,5);
	minefield.placeMine(0,0);
	minefield.placeMine(0,5);
	minefield.placeMine(5,0);

        ASSERT_TRUE(minefield.isSafe(4,5));
        ASSERT_TRUE(minefield.isSafe(5,4));
        ASSERT_FALSE(minefield.isSafe(5,5));

        ASSERT_TRUE(minefield.isSafe(0,1));
        ASSERT_TRUE(minefield.isSafe(1,0));
        ASSERT_FALSE(minefield.isSafe(0,0));
}
TEST(FieldTest, checkAdjecent)
{
	Field minefield;
}
