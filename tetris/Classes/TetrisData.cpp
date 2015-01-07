/*********************************************************************
 *	@file		TetrisData.cpp
 *	@brief		Include all preset data about tetris's piece.
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#include "TetrisData.h"

/*==========================================================================*/
/*	Constants																*/
/*==========================================================================*/

const int TetrisData::PIECE_NAME2INDEX[] = {
	/*a  b   c   d   e   f   g  h [I] [J]  k [L]  m   n [O]  p   q   r [S] [T] u   v   w   x   y [Z] */
	-1, -1, -1, -1, -1, -1, -1, -1, 1, 5, -1, 4, -1, -1, 0, -1, -1, -1, 2, 6, -1, -1, -1, -1, -1, 3
};

const unsigned int TetrisData::PIECE_ROTATION[PIECE_TYPE_MAX] = {
	1, 2, 2, 2, 4, 4, 4
};

/*	note:
 *	e.g. 'T' in binary:
 *	0000	0010	0010    0010
 *	0111	0011	0111    0110
 *  0010	0010	0000    0010
 *  0000	0000	0000    0000
 *	-> (From bottom to top)
 *	0,		0,		0		0
 *	4,		4,		0		4
 *	E,		C,		E		6
 *	0,		4,		4		4
 */
const unsigned int TetrisData::PIECE_STATE_BITS[PIECE_TYPE_MAX][PIECE_ROTATION_MAX][PIECE_SIZE] = {
		{ { 0x0, 0x6, 0x6, 0x0 }, {}, {}, {} },
		{ { 0x0, 0x0, 0xF, 0x0 }, { 0x4, 0x4, 0x4, 0x4 }, {}, {} },
		{ { 0x0, 0x6, 0xC, 0x0 }, { 0x0, 0x8, 0xC, 0x4 }, {}, {} },
		{ { 0x0, 0xC, 0x6, 0x0 }, { 0x0, 0x4, 0xC, 0x8 }, {}, {} },
		{ { 0x0, 0x2, 0xE, 0x0 }, { 0x0, 0xC, 0x4, 0x4 }, { 0x0, 0x0, 0xE, 0x8 }, { 0x0, 0x4, 0x4, 0x6 } },
		{ { 0x0, 0x8, 0xE, 0x0 }, { 0x0, 0x4, 0x4, 0xC }, { 0x0, 0x0, 0xE, 0x2 }, { 0x0, 0x6, 0x4, 0x4 } },
		{ { 0x0, 0x4, 0xE, 0x0 }, { 0x0, 0x4, 0xC, 0x4 }, { 0x0, 0x0, 0xE, 0x4 }, { 0x0, 0x4, 0x6, 0x4 } }
};

/*	note: just enter PIECE_STATE_BITS to the following program
		
	char buffer[1000] = {};
	int cnt = 0;

	while(gets(buffer)) {
		bool isNumber = false;
		int i = -1;
		while(buffer[++i] != '\0') {

			if('0' <= buffer[i] && buffer[i] <= '9') {
				int num = 0;
				sscanf(buffer + i, "%x", &num);
				while(buffer[i] != ' ')
					i++;

				int result = 0;
				for(int k = 9; k >= 0; k--) {
					if(num & (1 << k)) {
						result |= (cnt << (k * 3));
					}
				}

				if(isNumber)
					putchar(',');
				printf("0x%x", result);

				isNumber = true;
			} else {
				putchar(buffer[i]);
				if(buffer[i] != ',' && buffer[i] != ' ')
					isNumber = false;
			}

		}
		putchar('\n');
		cnt ++;
	}
 */
const unsigned int TetrisData::PIECE_COLOR_BITS[PIECE_TYPE_MAX][PIECE_ROTATION_MAX][PIECE_SIZE] = {
		{ { 0x0, 0x48, 0x48, 0x0 }, {}, {}, {} },
		{ { 0x0, 0x0, 0x492, 0x0 }, { 0x80, 0x80, 0x80, 0x80 }, {}, {} },
		{ { 0x0, 0xd8, 0x6c0, 0x0 }, { 0x0, 0x600, 0x6c0, 0xc0 }, {}, {} },
		{ { 0x0, 0x900, 0x120, 0x0 }, { 0x0, 0x100, 0x900, 0x800 }, {}, {} },
		{ { 0x0, 0x28, 0xb68, 0x0 }, { 0x0, 0xb40, 0x140, 0x140 }, { 0x0, 0x0, 0xb68, 0xa00 }, { 0x0, 0x140, 0x140, 0x168 } },
		{ { 0x0, 0xc00, 0xdb0, 0x0 }, { 0x0, 0x180, 0x180, 0xd80 }, { 0x0, 0x0, 0xdb0, 0x30 }, { 0x0, 0x1b0, 0x180, 0x180 } },
		{ { 0x0, 0x1c0, 0xff8, 0x0 }, { 0x0, 0x1c0, 0xfc0, 0x1c0 }, { 0x0, 0x0, 0xff8, 0x1c0 }, { 0x0, 0x1c0, 0x1f8, 0x1c0 } }
};


/*==========================================================================*/
/*	private Constructor \ Destructor										*/
/*==========================================================================*/

TetrisData::TetrisData()
{}

TetrisData::~TetrisData()
{}


