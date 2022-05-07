#include "Position.hpp"

Position::Position(const double x, const double y)
    : m_x {x}, m_y {y}
{

}

double Position::x()
{
    return m_x;
}

double Position::y()
{
    return m_y;
}