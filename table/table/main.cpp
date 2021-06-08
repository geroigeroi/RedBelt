//
//  main.cpp
//  table
//
//  Created by Andre on 12/01/21.
//

#include "test_runner.h"
#include "vector"

using namespace std;

// Реализуйте здесь шаблонный класс Table


template <typename T>
class Table {
private:
    size_t cols_;
    size_t rows_;
    std::vector<vector<T>> table_;
public:
    Table<T>(int cols, int rows) : cols_(cols), rows_(rows) {
        table_.resize(cols_);
        for (int i = 0; i < cols_; ++i) {
            table_[i].resize(rows_);
        }
    }
    void Resize(size_t newCols, size_t newRows) {
        cols_ = newCols;
        rows_ = newRows;
        table_.resize(cols_);
        for (int i = 0; i < cols_; ++i) {
            table_[i].resize(rows_);
        }
    }
    pair<size_t, size_t> Size() const {
        pair<size_t, size_t> result;
        if (cols_ == 0 || rows_ == 0) {
            result.first = 0;
            result.second = 0;
            return result;
        }
        result.first = cols_;
        result.second = rows_;
        return result;
    }
    std::vector<T>& operator[](const size_t& idx) {
        return table_[idx];
    }
    std::vector<T>& operator[](const size_t& idx) const {
        return table_[idx];
    }
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
