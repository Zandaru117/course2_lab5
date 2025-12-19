#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"
#include <random>

class Dust {
private:
    Point center_;
    Velocity velocity_;
    double timeLife_ = 1000.0;
    Color color_{255,0,0};
    double radius_ = 10.0;
    

public:
    Dust(double x, double y, double vx, double vy);
    void clear();
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    void setTimeLife(double timeLife);
    double getTimeLife();
    void setColor(Color color);
};

Dust randomDust(const Point& center);