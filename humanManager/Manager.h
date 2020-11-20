//
// Created by knigh on 2020/11/19.
//

#ifndef HUMANMANAGER_MANAGER_H
#define HUMANMANAGER_MANAGER_H

#endif //HUMANMANAGER_MANAGER_H
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class Manager:public Worker{
public:
    Manager(int id,string name,int did);
    void showInfo();
    string getDeptName();
};
