#pragma once
int aiMode();
void makeArr(int* arr,int size);
void shuffle(int* arr, int size);
void swap(int* arr, int idx1, int idx2);
void display(int* arr,int size,int currPosi,bool* selected);
void command(char cmd,int* userArr, int* aiArr, int* currPosi,bool* userSelected, bool* aiSelected,bool * already);
int bingoCheck(bool* selected);
void aiCommand(int* userArr, int * aiArr, bool * userSelected, bool * aiSelected,int size);
void aiHardCommand(int* userArr, int * aiArr, bool * userSelected, bool * aiSelected, int size);
void clearArr(bool* selected, int size);