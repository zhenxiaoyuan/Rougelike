#pragma once

class Position
{
public:
    Position(const double x, const double y);
    Position(Position&&);
    Position& operator=(Position&&);

    ~Position() = default;
public:
    double m_x;
    double m_y;
};