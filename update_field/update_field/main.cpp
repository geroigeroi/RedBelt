//
//  main.cpp
//  update_field
//
//  Created by Andre on 12/01/21.
//

#include "airline_ticket.h"
#include "test_runner.h"
#include <iomanip>
using namespace std;

std::istream& operator>>(std::istream& stream, Date& date) {
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return stream;
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

std::istream& operator>>(std::istream& stream, Time& time) {
    stream >> time.hours;
    stream.ignore(1);
    stream >> time.minutes;
    return stream;
}

bool operator==(const Time& lhs, const Time& rhs) {
    if (lhs.hours == rhs.hours) {
        if (lhs.minutes == rhs.minutes) {
            return true;
        }
    }
    return false;
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

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define UPDATE_FIELD(ticket, field, values)         \
if (values.find(#field) != values.end()) {          \
std::istringstream is(values.find(#field)->second); \
is >> ticket.field;                                 \
}

void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {
    UPDATE_FIELD(ticket, to, updates);
    UPDATE_FIELD(ticket, from, updates);
    UPDATE_FIELD(ticket, price, updates);
    UPDATE_FIELD(ticket, airline, updates);
    UPDATE_FIELD(ticket, departure_date, updates);
    UPDATE_FIELD(ticket, departure_time, updates);
    UPDATE_FIELD(ticket, arrival_date, updates);
    UPDATE_FIELD(ticket, arrival_time, updates);
}

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;
    
    const map<string, string> updates1 = {
        {"departure_date", "2018-2-28"},
        {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);
    
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);
    
    const map<string, string> updates2 = {
        {"price", "12550"},
        {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);
    
    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
