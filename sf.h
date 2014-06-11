struct card{
    int value;
    char suit;
};

/* suit can only be one of these four characters: 'c', 'd', 'h', 's'
   They stand for clubs, diamonds, hearts, and spades respectively.

   value is an integer between 1 and 13.
   The ace, jack, queen, and king have values 1, 11, 12, and 13
   respectively.
*/

int straightflush(struct card hand[], int n);
