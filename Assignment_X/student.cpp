#include "student.h"
#include <iostream>

int m_age;
int m_height;
std::string m_name;

Student::Student(){
	m_name = " ";
    m_age =  0;
    m_height = 0;
}

Student::Student(std::string name, int age, int height){
	m_name = name;
	m_age = age;
	m_height= height;
}

void Student::set(std::string name, int age, int height){
	m_name = name;
	m_age = age;
	m_height= height;
}

bool Student::setHeight(int height){
	if (height < 60 || height > 300)
    	return false;
    m_height = height;
    return true;
}

std::string Student::getName() const {
	return m_name;
}

int Student::getHeight() const {
    return m_height;
}

int Student::getAge() const {
	return m_age;
}

std::istream &operator>>(std::istream &input, Student &stu){
    input >> stu.m_name >> stu.m_age >> stu.m_height;
    return input;
}

std::ostream &operator<<(std::ostream &output, const Student &stu){
    output << "Name: " << stu.m_name << "\t Age: " << stu.m_age << "\t Height: " << stu.m_height;
    return output;
}

void Student::print(){
    std::cout << "Student Information: " << std::endl;
    std::cout << "\t Name: " << m_name << std::endl;
    std::cout << "\t Age: " << m_age << std::endl;
    std::cout << "\t Height: " << m_height << std::endl;
}