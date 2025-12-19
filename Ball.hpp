#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
private:
    Point center_;
    Velocity velocity_;
    double radius_;
    Color color_;
    bool collidable_;
    

public:
    Ball();
    Ball(double x, double y, double vx, double vy, double radius, double red, double green, double blue, bool isCollidable);
    void setVelocity(const Velocity& velocity);
    void setCenter(const Point& center);
    void setCenter(const double& x, const double& y);
    void setRadius(const double& radius);
    void setColor(const Color& color);
    void setCollidable(const bool& collidable);
    double getRadius() const;
    Velocity getVelocity() const;
    Point getCenter() const;
    double getMass() const;
    bool isCollidable() const;
    void draw(Painter& painter) const;
    friend std::istream& operator>>(std::istream& stream, Ball& variable);
};
