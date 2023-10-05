#include "./application.h"
#include "./algorithms.h"
#include <gtest/gtest.h>


// Define a fixture for your test
class SortingAlgorithmsTest : public ::testing::Test {
protected:
  Application app;

  // This will be called before each test case
  void SetUp() override {
    for (int i = 0; i < 1000; i++) {
      sortedArray[i] = i + 1;
    }
  }

  int sortedArray[1000];
};

// Test case for the minSort algorithm
TEST_F(SortingAlgorithmsTest, TestMinSort) {
  app.myArray.createArray();
  minSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

// Test case for the maxSort algorithm
TEST_F(SortingAlgorithmsTest, TestMaxSort) {
  app.myArray.createArray();
  maxSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

// Test case for the quickSort algorithm
TEST_F(SortingAlgorithmsTest, TestQuickSort) {
  app.myArray.createArray();
  quickSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

// Test case for the mergeSort algorithm
TEST_F(SortingAlgorithmsTest, TestMergeSort) {
  app.myArray.createArray();
  mergeSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

// Test case for the bubbleSort algorithm
TEST_F(SortingAlgorithmsTest, TestBubbleSort) {
  app.myArray.createArray();
  bubbleSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

// Test case for the swapSort algorithm
TEST_F(SortingAlgorithmsTest, TestSwapSort) {
  app.myArray.createArray();
  swapSort(app, app.getWindow(), 1000);

  // Check if the array has been correctly sorted
  int* resultArray = app.myArray.getArray();
  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(resultArray[i], sortedArray[i]);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
