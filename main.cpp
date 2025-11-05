#include <iostream>
#include <cmath>
#include <iomanip>

class Circle {
// complete declaration for Circle class here
	private:
		double m_radius;

	protected:
		double m_area;
		void calcArea(double radius);
	
	public:
		Circle();
		Circle(double radius);
		virtual void display() const;
};

class Cylinder : public Circle {
// complete declaration for Cylinder class here
	private: 
		double m_height;
		double m_volume;
		void calcVolume(double r, double h);

	public:
		Cylinder(double radius, double height);
		void display() const;
};

//default constructor
Circle::Circle() {
	m_radius = 1.00;
	m_area = 3.14;
}

//parameter constructor
Circle::Circle(double radius) {
	m_radius = radius;
	calcArea(m_radius);
}

//calcArea 
void Circle::calcArea(double radius) {
	double radius_squared = pow(m_radius, 2.00);
	m_area = radius_squared * M_PI;
}

//display for circle object
void Circle::display() const {
	std::cout << std::endl;
	std::cout << "The area of a circle with ...\n";
	std::cout << "a radius of " << std::fixed << std::setprecision(2) << m_radius << " inches\n";
	std::cout << "has an area of " << m_area << " square inches.\n";
}

//cylinder parametric constructor
Cylinder::Cylinder(double radius, double height):Circle(radius) {
	m_height = height;
	calcVolume(radius, height);
}

//calcVolume function
void Cylinder::calcVolume(double r, double h) {
	Circle::calcArea(r);
	m_volume = m_area * h;
}
	
//overriding circle display function
void Cylinder::display() const {
	Circle::display();
	std::cout << "And the volume of a Cylinder with...\n";
	std::cout << "a circular end area of " << m_area << " square inches\n";
	std::cout << "and a height of " << m_height << " inches\n";
	std::cout << "has a volume of " << m_volume << " cubic inches.\n";
}

int main() {
	Circle c1, c2(5.25);
	c1.display();
	c2.display();
	Circle *cl1 = new Cylinder(3.5, 8.65);
	cl1->display();
	return 0;
}
