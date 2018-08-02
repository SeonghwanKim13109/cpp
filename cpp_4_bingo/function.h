#pragma once
void makeArr(int* arr,int size);
void shuffle(int* arr, int size);
void swap(int* arr, int idx1, int idx2);
void display(int* arr,int size,int currPosi,bool* selected);
void command(char cmd, int* currPosi,bool* selected);
int bingoCheck(bool* selected);