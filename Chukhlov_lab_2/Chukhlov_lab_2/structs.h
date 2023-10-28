#pragma once
#include <string>
using namespace std;
struct Pipe
{
    string name = "0";
    int len = 0;
    int diam = 0;
    string maint;
};
struct CS
{
    string name = "0";
    int wksh_num = 0;
    int act_wksh_num = 0; // <=workshop_num!
    int eff = 0; // from 1 to 5
};