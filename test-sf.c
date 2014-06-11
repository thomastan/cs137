#include <stdio.h>
#include "sf.h"

int main(){
    struct card hand1[] = {{4,'s'}, {9,'s'},{12,'c'},{11,'s'},{8,'s'},
                           {6,'d'}, {3,'d'},{7,'s'},{10,'s'},{12,'d'}};
    struct card hand2[] = {{8,'c'}, {2,'h'},{5,'s'},{6,'c'},{1,'s'},
                           {5,'c'}, {4,'d'},{6,'h'},{13,'d'},{1,'d'}};

    printf ("%d\n", straightflush(hand1, 10));
    printf ("%d\n", straightflush(hand2, 10));

    return 0;
}
