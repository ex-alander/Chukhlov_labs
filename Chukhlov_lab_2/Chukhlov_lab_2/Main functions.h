#pragma once
using namespace std;
//#include "structs.h"
#include "classes.h"
#include <string>
#include <iostream>
#include "Checking tools.h"
ostream& operator << (ostream& out, Pipe& a);
ostream& operator << (ostream& out, CS& b);
void LogsStash(int a);
void Divider();
void PDivider();
void Record(const string logout);
void SetPipe(int x, Pipe& A);
void SetCS(int x, CS& B);
void PipesSettings(int& id_pipe,map<int, Pipe>& pipes);
void CSSettings(int& id_cs,map<int, CS>& css);
void ViewPipe(Pipe A);
void ViewCS(CS B);
void ViewAll(Pipe A, CS B);
void SaveAll(map<int,Pipe>& A, map<int,CS>& B);
void LoadInfo(map<int,Pipe>& A, map<int,CS>& B, int& id_pipe, int& id_cs);
map<int, Pipe> PipesSearch(map<int, Pipe>a);
map<int, CS> CSSearch(map<int, CS>b);
