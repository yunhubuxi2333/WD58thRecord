int weekday(int year, int month, int day) {
    int days = distance(1970, 1, 1, year, month, day);
    return (4 + days) % 7;
}