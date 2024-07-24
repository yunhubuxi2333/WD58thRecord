int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void setDaysOfFeb(int year) {
    if (isLeapYear(year)) {
        daysOfMonth[2] = 29;
    } else {
        daysOfMonth[2] = 28;
    }
}

int main(void) {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);

    day++;
    setDaysOfFeb(year);

    if (day > daysOfMonth[month]) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        year++;
    }

    printf("%4d/%.2d/%2d\n", year, month, day);

    return 0;
}