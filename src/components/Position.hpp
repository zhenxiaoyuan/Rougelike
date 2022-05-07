#pragma once

class Position
{
public:
    Position(const double x, const double y);

    ~Position() = default;

    double x();
    double y();

private:
    double m_x;
    double m_y;

};