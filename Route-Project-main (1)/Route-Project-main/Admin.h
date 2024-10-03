
#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include "Client.h"
#include "Validation.h"


using namespace std;

class Admin : public Person
{
private:
    double salary;
    vector<Client*> clients;
    vector<Employee*> employees;

public:
    Admin() { this->salary = 0; }
    Admin(string name, string password, int id, double balance) : Person(name, password, id), salary(salary) {}

    // getters
    double getBalance()
    {
        return salary;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }

    // setters
    void setSalary(double salary)
    {
        Validation::valiSalary(salary);

        this->salary = salary;
    }
    
    void setbalance(double balance)
    {
        this->salary = balance;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        Validation::valiName(name);

        this->name = name;
    }
    void setPassword(string password)
    {
        Validation::valiPassword(password);

        this->password = password;
    }

    void addClient(Client* client)
    {
        clients.push_back(client);

    }
    
    //search
    bool searchClient(int id)
    {
        for (Client* client : clients)
        {
            if (client->getId() == id)
            {
                return true;
            }
        }
        return false;
    }
    //listofclients
    void listofclients()
    {
        for (Client* client : clients)
        {
            client->Displayclientinfo();
        }
    }


    void editClient(int id, string name, string password, double balance){
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i]->getId() == id)
            {
                clients[i]->setName(name);
                clients[i]->setPassword(password);
                clients[i]->setBalance(balance);
            }
        }
    }











    //addd Employee
    void addEmployee(Employee* employee)
    {
        employees.push_back(employee);
    }
    //search
    bool searchEmployee(int id)
    {
        for (Employee* employee : employees)
        {
            if (employee->getId() == id)
            {
                return true;
            }
        }
        return false;
    }
    //edit
    void editEmployee(int id, string name, string password, double salary)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i]->getId() == id)
            {
                employees[i]->setName(name);
                employees[i]->setPassword(password);
                employees[i]->setSalary(salary);
            }
        }
    }

    
    void listofemployees()
    {
        for (Employee* employee : employees)
        {
            employee->DisplayEmployeeinfo();
        }
    }


    


    
    









    // display
    void DisplayAdmininfo()
    {
        cout << " Name    : " << name << endl;
        cout << " ID      : " << id << endl;
        cout << " Salary : " << salary << endl;
        cout << "------------------------------------" << endl;
    }
};

#endif
