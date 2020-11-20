//
// Created by knigh on 2020/11/19.
//
#ifndef HUMANMANAGER_BOSS_H
#define HUMANMANAGER_BOSS_H

#endif //HUMANMANAGER_BOSS_H
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class Boss:public Worker{
public:
    Boss(int id,string name,int did);
    void showInfo();
    string getDeptName();
};