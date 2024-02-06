// Licensed under the MIT License.

/** Specifies a direction. */
enum Directions
{
    /** No direction. */
    DIRECTIONS_NONE = 0,

    /** The up or top direction. */
    DIRECTIONS_TOP = 1 << 0,
    
    /** The left direction. */
    DIRECTIONS_LEFT = 1 << 1,

    /** The down or bottom direction. */
    DIRECTIONS_BOTTOM = 1 << 2,

    /** The right direction. */
    DIRECTIONS_RIGHT = 1 << 3,
    
    /** The top and left directions. */
    DIRECTIONS_TOP_LEFT = DIRECTIONS_TOP | DIRECTIONS_LEFT,

    /** The bottom and right directions. */
    DIRECTIONS_BOTTOM_RIGHT = DIRECTIONS_BOTTOM | DIRECTIONS_RIGHT,

    /** All directions. */
    DIRECTIONS_ALL = DIRECTIONS_TOP_LEFT | DIRECTIONS_BOTTOM_RIGHT
};

/** Specifies a direction. */
typedef enum Directions Directions;
