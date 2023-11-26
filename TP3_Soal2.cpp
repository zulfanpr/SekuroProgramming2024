#include <iostream>

class Shape
{
private:
    float area;
    float keliling;

public:
    virtual float calculateArea(){return 0;}
    virtual float calculateKeliling(){return 0;}
};

class Rectangle :public Shape
{
private:
    float width;
    float length;

public:
    Rectangle(float width, float length){
        this->width = width;
        this->length = length;
    }

    float calculateArea(){
        this->width = width;
        this->length = length;
        float area = width*length;
        std::cout<<"Area rectangle = "<<area<<std::endl;
        return area;
    }

    float calculateKeliling(){
        this->width = width;
        this->length = length;
        float keliling = 2*(width+length);
        std::cout<<"Keliling rectangle = "<<keliling<<std::endl;
        return keliling;
    }

};

int main()
{
    Rectangle rect (5.0, 4.0);
    Shape* shape1 = &rect;

    shape1->calculateArea();
    shape1->calculateKeliling();

    return 0;
}
