#include "pch.h"
#include "..\StaticLib\Pytnashki.cpp"

TEST(PytnashkiTest, ConstructorTest) {
    Pytnashki game(4);
    std::vector<std::vector<int>> pole = game.GetPole();
    ASSERT_EQ(4, pole.size());
    ASSERT_EQ(4, pole[0].size());
}

TEST(PytnashkiTest, MoveTest) {
    Pytnashki game(4);
    int num = game.GetPole()[3][2];
    game.Move(num);
    std::pair<int, int> movedCell = game.FindPos(num);
    ASSERT_EQ(3, movedCell.first);
    ASSERT_EQ(3, movedCell.second);
}


TEST(PytnashkiTest, InvalidMoveTest) {
    Pytnashki game(4);
    testing::internal::CaptureStdout();
    game.Move(16);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("Нету такого числа.\n", output);
}

TEST(PytnashkiTest, InvalidMoveOutOfRangeTest) {
    Pytnashki game(4);
    std::pair<int, int> emptyCell = game.FindPos(0);
    int emptyRow = emptyCell.first;
    int emptyCol = emptyCell.second;
    std::pair<int, int> adjacentCell1 = game.FindPos(game.GetPole()[emptyRow - 1][emptyCol]);
    std::pair<int, int> adjacentCell2 = game.FindPos(game.GetPole()[emptyRow][emptyCol - 1]);
    testing::internal::CaptureStdout();
    game.Move(game.GetPole()[emptyRow - 1][emptyCol - 1]);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("Вы не можете двигать это число.\n", output);
}

TEST(PytnashkiTest, FindPosTest) {
    Pytnashki game(4);
    std::pair<int, int> pos = game.FindPos(0);
    ASSERT_EQ(3, pos.first);
    ASSERT_EQ(3, pos.second);
}

TEST(PytnashkiTest, MoveNumberOutOfBounds) {
    Pytnashki game(4);
    vector<vector<int>> initialPole = game.GetPole();
    int outOfBoundsNumber = 16;
    game.Move(outOfBoundsNumber);
    vector<vector<int>> updatedPole = game.GetPole();
    EXPECT_EQ(updatedPole, initialPole);
}

TEST(PytnashkiTest, MoveInvalidNumber) {
    Pytnashki game(4);
    vector<vector<int>> initialPole = game.GetPole();
    int invalidNumber = 20; 
    game.Move(invalidNumber);
    vector<vector<int>> updatedPole = game.GetPole();
    EXPECT_EQ(updatedPole, initialPole);
}

