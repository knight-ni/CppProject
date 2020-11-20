//
// Created by knigh on 2020/11/19.
//

#ifndef HUMANMANAGER_WORKER_H
#define HUMANMANAGER_WORKER_H

#endif //HUMANMANAGER_WORKER_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

//抽象类
class Worker{
public:
    virtual void showInfo()=0;
    virtual string getDeptName()=0;

    int m_Id;
    string m_Name;
    int m_Dept;
};


