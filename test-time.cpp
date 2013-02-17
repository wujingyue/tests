#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  time_t t = time(NULL);
  struct tm *lt = localtime(&t);
  printf("%04d%02d%02d-%02d%02d%02d\n",
         1900 + lt->tm_year, 1 + lt->tm_mon, lt->tm_mday,
         lt->tm_hour, lt->tm_min, lt->tm_sec);
  return 0;
}
