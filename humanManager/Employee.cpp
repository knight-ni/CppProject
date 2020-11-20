//
// Created by knigh on 2020/11/19.
//
#include "Employee.h"


Employee::Employee(int id,string name,int did){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Dept = did;
};

void Employee::showInfo(){
    cout << "职工编号: " << this->m_Id
    << "\t职工姓名: " <<this->m_Name
    << "\t岗位: " << this->getDeptName()
    << "\t岗位职责: 混" <<endl;
};

string Employee::getDeptName(){
    return string("员工");
};

