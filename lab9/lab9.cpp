

#include <iostream>
class triangle 
{
private:
        double m_side1=0;
        double m_side2=0;
        double m_side3=0;
        double m_perimeter=0;
public:
    bool sides(double side1, double side2, double side3) {
        if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0)) {
            std::cout << "wrong side value!" << std::endl;
            return false;
        }
        m_side1 = side1;
        m_side2 = side2;
        m_side3 = side3;
       
    }
    void SumOfSides() {
        m_perimeter = m_side1 + m_side2 + m_side3;
    }
    double znachenie() {
        return m_perimeter;
    }
    ~triangle() {}
   
};

int main()
{
    double s1, s2, s3;
    std::cout << "enter sides of triangle" << std::endl;
    std::cin >> s1 >> s2 >> s3;
    triangle s123;
    s123.sides(s1, s2, s3);
    s123.SumOfSides();
    std::cout<<s123.znachenie()<<std::endl;
}

