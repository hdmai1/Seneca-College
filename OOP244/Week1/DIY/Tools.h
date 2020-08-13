//Tools.h contains prototypes of ultility functions.
#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H
namespace sdds {
   using namespace std;
   bool valid(long long min, long long max, long long val);
   void getStr(char* str, int len);
   int compare(const Contact* A, const Contact* B);
   void sort(Contact c[], int n);
   void toLowerCase(char* lowerCase, const char* str);
   bool yes();
}
#endif