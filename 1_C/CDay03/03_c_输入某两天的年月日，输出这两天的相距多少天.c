int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int distance(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days = 0;
    // 计算year1还剩多少天
    setDaysOfFeb(year1);

    days += daysOfMonth[month1] - day1;
    for (int i = month1 + 1; i <= 12; i++) {
        days += daysOfMonth[i];
    }

    // 计算中间年份的天数
    for (int i = year1 + 1; i < year2; i++) {
        days += 365;
        if (isLeapYear(i)) {
            days++;
        }
    }

    // 计算year2过了多少天
    setDaysOfFeb(year2);

    for (int i = 1; i < month2; i++) {
        days += daysOfMonth[i];
    }
    days += day2;

    // 如果 year1 == year2, 那么多算了一整年
    if (year1 == year2) {
        days -= 365;
        if (isLeapYear(year1)) {
            days--;
        }
    }

    return days;
}