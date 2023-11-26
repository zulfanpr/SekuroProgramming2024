#include <iostream>

class LinearLine
{
private:
    float x1;
    float y1;
    float x2;
    float y2;

public:
    LinearLine (float x1, float y1, float x2, float y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    float gradient() {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        float gradient = (y2-y1)/(x2-x1);
        return gradient;
    }
    float y_intercept() {
        float y_intercept = LinearLine::gradient()*(-1*x1)+y1; //y_intercept-y1 = m(x_intercept-x1), dengan x_intercept=0
        return y_intercept;
    }
    void operator + (float a) {
        float m = LinearLine::gradient();
        float c2 = LinearLine::y_intercept() + (LinearLine::gradient()*a*-1); //digeser pada sumbu x sejauh a, y_baru = m(x-a)+c
        std::cout<<"y = "<<m<<"x + "<<c2<<std::endl;
    }
    void printEquation() {
        float m = LinearLine::gradient();
        float c = LinearLine::y_intercept();
        std::cout<<"y = "<<m<<"x + "<<c<<std::endl;
    }
    void printPoints() {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        std::cout<<"(x1, y1) = ("<<x1<<", "<<y1<<")"<<std::endl;
        std::cout<<"(x2, y2) = ("<<x2<<", "<<y2<<")"<<std::endl;
    }
};

int main()
{
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f);
    int a = 3;

    line.printPoints();
    std::cout<<"Sehingga didapatkan"<<std::endl;
    std::cout<<"gradient = "<<line.gradient()<<std::endl;
    std::cout<<"y_intercept = "<<line.y_intercept()<<std::endl;
    line.printEquation();
    std::cout<<"\nSetelah digeser sejauh a, didapatkan persamaan baru:"<<std::endl;
    line+(a);
}