//
// Created by knigh on 2020/11/19.
//

#ifndef HUMANMANAGER_EMPLOYEE_H
#define HUMANMANAGER_EMPLOYEE_H

#endif //HUMANMANAGER_EMPLOYEE_H
#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

//普通员工类
class Employee:public Worker{
public:
    //构造函数
    Employee(int id,string name,int did);
    void showInfo();
    string getDeptName();
};
