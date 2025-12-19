#include "Ball.hpp"
#include <cmath>
#include <fstream>
#include <memory>

Ball::Ball(){}

Ball::Ball(double x, double y, double vx, double vy, double radius, double red, double green, double blue, bool isCollidable): 
    radius_(radius),
    collidable_(isCollidable){
    Point point{x,y};
    Point vec{vx,vy};
    Color color{red, green, blue};
    center_ = point;
    velocity_ = vec;
    color_ = color;
}

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    velocity_ = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return {velocity_};
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(center_, radius_, color_);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    center_ = center;
}

void Ball::setCenter(const double& x, const double& y){
    center_.x = x;
    center_.y = y;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return {center_};
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return {radius_};
}

void Ball::setRadius(const double& radius){
    radius_ = radius;
}

void Ball::setColor(const Color& color){
    color_ = color;
}

void Ball::setCollidable(const bool& collidable){
    collidable_ = collidable;
}
/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    return {3.14 * (radius_*radius_*radius_) * 4. / 3};
}

bool Ball::isCollidable() const{
    return {collidable_};
}

std::istream& operator>>(std::istream& stream, Ball& variable)
{
    double x;
    double y;
    double vx;
    double vy;
    double radius;

    double red;
    double green;
    double blue;

    bool isCollidable;
    stream >> x >> y >> vx >> vy;
    variable.setCenter(x,y);
    Point p{vx,vy};
    Velocity vec{p};
    variable.setVelocity(vec);
    stream >> red >> green >> blue;
    Color color{red,green,blue};
    variable.setColor(color);
    stream >> radius;
    variable.setRadius(radius);
    stream >> std::boolalpha >> isCollidable;
    variable.setCollidable(isCollidable);
    return stream;
}