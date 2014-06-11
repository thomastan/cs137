#include "sf.h"
#include <stdio.h>

#define HASFLUSH 1
#define NOFLUSHES 0
#define CARDPRESENT 1
#define CHUNK 100

// A time limit is given of 5 seconds per test case, and also, n is specified to
// be quite large.  This function is therefore written with some speed
// considerations in mind with the tradeoff of longer code.  Cards on hand are
// checked after a new chunk of cards is added to what has already been
// searched.

int straightflush(struct card hand[], int n) {

	unsigned int onHand[4][15] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	// Need at least 5 cards before checking what's on hand

	if (n <= 4)
		return NOFLUSHES;

	unsigned int i, j, k, unsignedN = (unsigned int) n, suit = 0, consec, end;
	int number;

	for (i = 0; i < unsignedN; i++) {
		number = hand[i].value;

		if (hand[i].suit == 'c')
			onHand[0][number] = CARDPRESENT;
		else if (hand[i].suit == 'd')
			onHand[1][number] = CARDPRESENT;
		else if (hand[i].suit == 'h')
			onHand[2][number] = CARDPRESENT;
		else if (hand[i].suit == 's')
			onHand[3][number] = CARDPRESENT;
		else
			continue;

		if (i % CHUNK == 0)
			for (suit = 0; suit < 4; suit++) {
				onHand[suit][14] = onHand[suit][1];
				for (j = 0; j < 14; j++) {
					if (onHand[suit][j])
						for (k = j + 1; k < j + 5; k++) {
							if (!onHand[suit][k])
								break;
							// printf("%u %u %u\n", suit, j, k);
							return HASFLUSH;
						}
				}
			}
	}

// dump deck
// 	for (suit = 0; suit < 4; suit++) {
// 		for (j = 0; j < 14; j++)
// 			printf("%d ", onHand[suit][j]);
// 		puts("");
// 	}

	for (suit = 0; suit < 4; suit++) {
		onHand[suit][14] = onHand[suit][1];
		for (j = 0; j < 14; j++)
			if (onHand[suit][j]) {
				consec = 0, end = j + 5;
				for (k = j + 1; k < end && end < 15; k++) {
					if (!onHand[suit][k])
						break;
					//	printf("%uconsec suit%u %u->%u\n", consec + 2, suit, j, k);
					if (++consec == 4)
						return HASFLUSH;
				}
			}
	}

	return NOFLUSHES;
}
