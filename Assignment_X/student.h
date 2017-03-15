#ifndef CSC16_STUDENT_H
#define CSC16_STUDENT_H

#include <string>

class Student {
	private:
		int m_age;
		int m_height;
		std::string m_name;

	public:
		Student();
		Student(std::string name, int age, int height);

		void set(std::string name, int age, int height);
		bool setHeight(int height);
		std::string getName() const;
		int getHeight() const;
		int getAge() const;

		friend std::istream &operator>>(std::istream &input, Student &s);
		friend std::ostream &operator<<(std::ostream &output, const Student &s);

		void print();
};

#endif //CSC16_STUDENT_H