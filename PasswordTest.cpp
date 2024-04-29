/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("Z");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multiple_same_letter_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZZZZZ");
  ASSERT_EQ(5, actual);
}

TEST(PasswordTest, multiple_different_letters_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZABCD");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, case_sensitive_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("Zzzz");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, non_alpha_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("111223");
  ASSERT_EQ(3, actual);
}

// Test cases for has_mixed_case function
TEST(PasswordTest, mixed_case_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("Password123");
  ASSERT_TRUE(actual);
}

TEST(PasswordTest, all_upper_case_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("PASSWORD");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, all_lower_case_password) {
  Password my_password;
  bool actual = my_password.has_mixed_case("password");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, no_alpha_characters) {
  Password my_password;
  bool actual = my_password.has_mixed_case("123456");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, empty_string_for_mixed_case) {
  Password my_password;
  bool actual = my_password.has_mixed_case("");
  ASSERT_FALSE(actual);
}

// Add more test cases as needed
