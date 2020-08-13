#pragma once
// Draws a line and adds a label if provided
void line(int n, const char* label = nullptr);
// Performs a fool-proof integer entry
int getInt(int min, int max);
// moves the cursor backwards
void goBack(int n);
// displays the user interface menu
int menu(int noOfSamples);