#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
   // reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the 
   // boundries set by "min" or "max" , this function flushes the 
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer

   int read(int min, int max, const char* errorMessage = "");
}
#endif // !