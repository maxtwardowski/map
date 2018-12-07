class Employee {
public:
	std::string name;
	std::string position;
	unsigned int age;
	Employee() {

	}
	Employee(std::string name, std::string position, unsigned int age) {
		this->name = name;
		this->position = position;
		this->age = age;
	}
	friend std::ostream& operator<< (std::ostream& stream, const Employee& e) {
		stream << "Name: " << e.name << std::endl;
		stream << "Position: " << e.position << std::endl;
		stream << "Age: " << e.age << std::endl;
		return stream;
	}
};