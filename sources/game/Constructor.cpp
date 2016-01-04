#include "Constructor.h"

Room::Room(int x, int y, Room &other) :
        x(x),
        y(y),
        width(other.width),
        height(other.height),
        dispersion(other.dispersion)
{

}

Room::Room(int width, int height, int r) :
        x(0),
        y(0),
        width(width),
        height(height),
        dispersion(r)
{

}

Room::Room(int x, int y, int width, int height, int dispersion) :
        x(x),
        y(y),
        width(width + rand() % dispersion - dispersion / 2),
        height(height + rand() % dispersion - dispersion / 2),
        dispersion(dispersion)
{

}

bool Room::collidesWith(Room &other)
{
    return this->x < other.x + other.width && this->x + this->width > other.x &&
            this->y < other.y + other.height && this->y + this->height > other.y;
}

Hall::Hall(int from, int to) :
        from(from),
        to(to)
{

}

bool Hall::equals(int from, int to)
{
    return this->from == from && this->to == to;
}

Constructor::Constructor(size_t width, size_t height, size_t roomsAmount) :
        width(width),
        height(height),
        roomsAmount(roomsAmount),
        rooms(roomsAmount),
        halls(roomsAmount),
        map(width * height)
{

}

Constructor::~Constructor()
{

}
