#ifndef DARKNESS_CONSTRUCTOR_H
#define DARKNESS_CONSTRUCTOR_H

#include <stdlib.h>
#include <vector>
#include <array>

class Room
{
private:
    int x;
    int y;
    int width;
    int height;
    int dispersion;

public:
    /**
     * Creates a room from a model room.
     */
    Room(int x, int y, Room &other);

    /**
     * Creates a model room.
     */
    Room(int width, int height, int r);

    /**
     * Creates a new room with dispersion.
     */
    Room(int x, int y, int width, int height, int dispersion);

    /**
     * Tests if this room collides with another one.
     */
    bool collidesWith(Room &other);
};

class Hall
{
private:
    int from;
    int to;

public:
    /**
     * Constructs a new hall.
     */
    Hall(int from, int to);

    /**
     * Checks if the connection hall is this one.
     */
    bool equals(int from, int to);
};

enum class TileType : int
{
    NONE,
    FLOOR,
    WALL,
    WALL_L,
    WALL_R
};

class Constructor
{
private:
    std::vector<Room> rooms;
    std::vector<Hall> halls;

    size_t roomCount = 0;
    size_t hallCount = 0;
    size_t roomsAmount = 0;

    size_t width;
    size_t height;

    std::vector<TileType> map;
public:
    Constructor(size_t width, size_t height, size_t roomsAmount);

    ~Constructor();
};


#endif //DARKNESS_CONSTRUCTOR_H
