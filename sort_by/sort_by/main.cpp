//
//  main.cpp
//  sort_by
//
//  Created by Andre on 11/01/21.
//
#include "airline_ticket.h"
#include "test_runner.h"
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
/* Реализуйте этот макрос, а также необходимые операторы для классов Date и Time */
#define SORT_BY(field) \
    [](const AirlineTicket& lhs, const AirlineTicket& rhs) {      \
    return lhs.field < rhs.field;                                 \
}

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.year == rhs.year) {
        if (lhs.month == rhs.month) {
            if (lhs.day == rhs.day) {
                return true;
            }
        }
    }
    return false;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year == rhs.year) {
        if (lhs.month == rhs.month) {
            if (lhs.day < rhs.day) {
                return true;
            } else {
                return false;
            }
        } else if (lhs.month < rhs.month) {
            return true;
        } else {
            return false;
        }
    } else if (lhs.year < rhs.year) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setfill('0');
    stream << std::setw(4) << date.year << "-"
           << std::setw(2) << date.month << "-"
           << std::setw(2) << date.day;
    return stream;
}

bool operator<(const Time& lhs, const Time& rhs) {
    if (lhs.hours == rhs.hours) {
        if (lhs.minutes < rhs.minutes) {
            return true;
        } else {
            return false;
        }
    } else if (lhs.hours < rhs.hours) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& stream, const Time& time) {
    stream << std::setfill('0');
    stream << std::setw(2) << time.hours << ":";
    stream << std::setw(2) << time.minutes;
    return stream;
}


void SortTickets(vector<AirlineTicket>& tixs) {
    //stable_sort(begin(tixs), end(tixs), SORT_BY(to));
    stable_sort(begin(tixs), end(tixs), SORT_BY(to));
    stable_sort(begin(tixs), end(tixs), SORT_BY(departure_time));
    stable_sort(begin(tixs), end(tixs), SORT_BY(price));
}

void TestSortBy() {
    vector<AirlineTicket> tixs = {
        {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
        {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
        {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
        {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
        {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
    };
    
    sort(begin(tixs), end(tixs), SORT_BY(price));
    ASSERT_EQUAL(tixs.front().price, 1200);
    ASSERT_EQUAL(tixs.back().price, 9000);
    
    sort(begin(tixs), end(tixs), SORT_BY(from));
    ASSERT_EQUAL(tixs.front().from, "AER");
    ASSERT_EQUAL(tixs.back().from, "VKO");
    
    sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
    ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
    ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSortBy);
}
