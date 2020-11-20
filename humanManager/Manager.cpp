//
// Created by knigh on 2020/11/19.
//
#include "Manager.h"

Manager::Manager(int id,string name,int did){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Dept  = did;
};

void Manager::showInfo(){
    cout << "职工编号: " << this->m_Id
         << "\t职工姓名: " <<this->m_Name
         << "\t岗位: " << this->getDeptName()
         << "\t岗位职责: 完成老板交付任务,给员工发配任务" <<endl;
};

string Manager::getDeptName(){
    return string("经理");
};

