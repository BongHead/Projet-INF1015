#include "GameWindow.h"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST
using namespace back_end;
using namespace front_end;
TEST(Plateau,test1) {
	Plateau p;
	EXPECT_EQ(3, 3);
}


#endif