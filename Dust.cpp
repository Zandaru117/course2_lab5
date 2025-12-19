#include "Dust.h"
#include <random>

Dust::Dust(double x, double y, double vx, double vy){
    Point p{x,y};
    Point vec{vx,vy};
    center_ = p;
    velocity_ = vec;
}

void Dust::setVelocity(const Velocity& velocity){
    velocity_ = velocity;
}

Velocity Dust::getVelocity() const{
    return{velocity_};
}

void Dust::draw(Painter& painter) const{
    painter.draw(center_, radius_, color_);
}

void Dust::setCenter(const Point& center){
    center_ = center;
}

Point Dust::getCenter() const{
    return{center_};
}

double Dust::getRadius() const{
    return{radius_};
}

double Dust::getMass() const{
    return{3.14 * (radius_*radius_*radius_) * 4. / 3};
}

void Dust::setTimeLife(double timeLife){
    timeLife_ = timeLife;
}

double Dust::getTimeLife(){
    return{timeLife_};
}

void Dust::setColor(Color color){
    color_ = color;
}

Dust randomDust(const Point& center){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);
    double vx = distrib(gen);
    double vy = distrib(gen);
    Dust d{center.x, center.y, vx, vy};
    return {d};
    
}