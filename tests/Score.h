#include <stdbool.h>

typedef char* Point;

typedef struct
{
    int who_serves;
    bool is_tie_break;
    bool match_is_over;
    int sets [2];
    int games [2];
    Point points [2];

} Score;