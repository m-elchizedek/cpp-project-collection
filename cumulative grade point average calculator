#include <iostream>
#include <vector>
#include <string>


struct Course {
	std::string name;
	double credits;
	double grade_point;
};

class student {
public:
	std::vector<Course> courses;

	double calculate_cgpa() {
		double total_weightd_points = 0;
		double total_credits = 0;

		for (const auto& course : courses) {
			total_weightd_points += (course.credits * course.grade_point);
			total_credits += course.credits;
		}

		return (total_credits == 0) ? 0 : (total_weightd_points / total_credits);
	}
	std::string print_courses() {
		std::string result;
		for (const auto& course : courses) {
			result += course.name + " (" + std::to_string(course.credits) + " credits, Grade Point: " + std::to_string(course.grade_point) + ")\n";
		}
		return result;
	}
	std::string print_cgpa() {
		return "CGPA: " + std::to_string(calculate_cgpa());
	}
	
private:
	
};

int main() {
	student s;
	s.courses.push_back({ "Mathematics", 3.0, 4.0 });
	s.calculate_cgpa();
	std::cout << s.print_courses();
	std::cout << s.print_cgpa();
	return 0;
 
}
