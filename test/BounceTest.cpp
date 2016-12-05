#include "../src/Bounce.hpp"
#include <gtest/gtest.h>

using BounceShould = ::testing::Test;

TEST_F(BounceShould, bounceFromDownToLeftWall)
{
    Bounce b{200};
    ASSERT_EQ(b.hitToLeft(), 340);
}

TEST_F(BounceShould, bounceFromTopToLeftWall)
{
    Bounce b{160};
    ASSERT_EQ(b.hitToLeft(), 380);
}

TEST_F(BounceShould, bounceFromBottomRightWall)
{
    Bounce b{300};
    ASSERT_EQ(b.hitToRight(), 240);
}

TEST_F(BounceShould, bounceFromTopRightWall)
{
    Bounce b{30};
    ASSERT_EQ(b.hitToRight(), 510);
}

TEST_F(BounceShould, bounceFromLeftTopWall)
{
    Bounce b{300};
    ASSERT_EQ(b.hitToTop(), 60);
}

TEST_F(BounceShould, bounceFromRightTopWall)
{
    Bounce b{250};
    ASSERT_EQ(b.hitToTop(), 110);
}

TEST_F(BounceShould, bounceFromLeftBottomWall)
{
    Bounce b{60};
    ASSERT_EQ(b.hitToBottom(), 300);
}

TEST_F(BounceShould, bounceFromRightBottomWall)
{
    Bounce b{120};
    ASSERT_EQ(b.hitToTop(), 240);
}
