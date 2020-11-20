//
// Created by knigh on 2020/11/19.
//

#ifndef HUMANMANAGER_HUMANMANGER_H
#define HUMANMANAGER_HUMANMANGER_H

#endif //HUMANMANAGER_HUMANMANGER_H
#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;
#include <fstream>
#define FILENAME "Worker.txt"

class WorkerManager{
public:
    //记录当前职工人数,用于更新数组长度
    int m_empNum;
    Worker ** m_EmpArray;
    bool m_FileIsEmpty;
    //构造
    WorkerManager();
    //显示菜单
    void showMenu();
    //推出系统
    void exitSystem();
    //析构
    ~WorkerManager();
    //添加员工
    void addWorker();
    //保存文件
    void save();
    //统计文件中人数
    int getEmpNum();
    //初始化数据
    void initEmp();
    //显示信息
    void showEmp();
    //判断员工是否存在
    int isExist(int id);
    //删除职工
    void delEmp();
    //修改职工
    void modEmp();
    //查找职工
    void findEmp();
    //排序职工
    void sortEmp();
    //清空数据
    void cleanFile();
};