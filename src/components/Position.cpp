#include "Position.hpp"

Position::Position(const double x, const double y)
    : m_x {x}, m_y {y}
{
    // no op
}

Position::Position(Position&& pos)
{
    this->m_x = pos.m_x;
    this->m_y = pos.m_y;
}

Position& Position::operator=(Position&& pos)
{
    if (this != &pos)
    {
        this->m_x = pos.m_x;
        this->m_y = pos.m_y;
    }

    return *this;
}