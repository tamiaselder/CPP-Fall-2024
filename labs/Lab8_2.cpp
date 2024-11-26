// Implement the class `QuadraticEquation` (`ax^2 + bx + c = 0`). The class should contain:

// - A constructor that takes the 3 coefficients, if the equation has no solutution throw an invalid argument exception
// - The getters and setters for all fields, if the equation has no solutution throw an invalid argument exception
// - Function `get_discriminant` that computes the discriminant `b^2 - 4ac`
// - Function `has_real_solution` that checks if the discriminant is positive
// - Function `is_quadratic` that checks if a is different from zero
// - Function `has_duplicated_solution` that checks if the discriminant is zero
// - Two functions `get_solution1` and `get_solution2` that returns the two solutions 
// (`(-b+sqrt(discriminant))/(2a)` and `(-b-sqrt(discriminant))/(2a)`)
#include <iostream>
#include <cmath>

struct invalid_argument_exception{
    int arg{};
};


class QuadraticEquation{
    private:
    double a;
    double b;
    double c;
    double discriminant;
    
    public:
    QuadraticEquation(double A, double B, double C){
        if(0){
            throw invalid_argument_exception();
        }
        a=A;
        b=B;
        c=C;
        discriminant= B*B -(4*A*C);        
    }

    double get_discriminant(){
        return discriminant;
    }

    bool has_real_solution(){
        if (discriminant>0)
            return 1;
        return 0;
    }

    bool is_quadratic(){
        if (a==0)
            return 0;
        return 1;
    }

    bool has_duplicated_solution(){
        if (discriminant==0)
            return 1;
        return 0;
    }

    double getsol1(){
    double temp = sqrt(discriminant);
        return ((-b+temp)/(2*a));
    }

    double getsol2(){
        double temp = sqrt(discriminant);
        return ((-b-temp)/(2*a));
    }
    
};

int main (){
    QuadraticEquation myquad(1.0, 2.0, -3.0);
    //std::cout ""
    std::cout << "Discriminant: "<< myquad.get_discriminant() << std::endl;
    std::cout << "Real Solution: "<< myquad.has_real_solution() << std::endl;
    std::cout << "is Quad: "<< myquad.is_quadratic() << std::endl;
    std::cout << "Duplicated Solution: "<< myquad.has_duplicated_solution() << std::endl;
    std::cout << "Sol 1: "<< myquad.getsol1() << std::endl;
    std::cout << "Sol 2: "<< myquad.getsol2() << std::endl;
    return 0;
}