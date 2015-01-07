/*********************************************************************
 *	@file		TetrisData.hpp
 *	@brief		Class TetrisData
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#pragma once

/**
 *	\brief	All Preset Data.
 */
class TetrisData {

public:

	/*==========================================================================*/
	/*	Constants																*/
	/*==========================================================================*/

	static const unsigned int PIECE_TYPE_MAX = 7;				/**< 7 type: O,I,S,Z,L,J,T */
	static const unsigned int PIECE_SIZE = 4;					/**< default size: 4 x 4 */
	static const unsigned int PIECE_ROTATION_MAX = 4;			/**< e.g. 'T' has 4 rotational state */
	static const unsigned int PIECE_ANCHOR_X = 2;				/**< 2 from left */
	static const unsigned int PIECE_ANCHOR_Y = 2;				/**< 2 from bottom */

	static const int PIECE_NAME2INDEX[];						/**< e.g. 'O'->0, 'I'->1, 'S'->2, 'Z'->3, 'L'->4, 'J'->5, 'T'->6 */
	static const unsigned int PIECE_ROTATION[PIECE_TYPE_MAX];	/**< each piece's number of rotations */
	static const unsigned int PIECE_STATE_BITS[PIECE_TYPE_MAX][PIECE_ROTATION_MAX][PIECE_SIZE]; /**< e.g. 'O',r0 : {0,6,6,0}  */
	static const unsigned int PIECE_COLOR_BITS[PIECE_TYPE_MAX][PIECE_ROTATION_MAX][PIECE_SIZE]; /**< e.g. 'O',r0 : {0,72,72,0}  */

	static const unsigned int FIELD_WIDTH = 10;					/**< field's width, if > 10, color layer should change "uint" to "ull". And no more than 26. */
	static const unsigned int FIELD_HEIGHT = 20;				/**< field's height. */
	
	static const unsigned int LOC_DELTA_X = PIECE_SIZE - 1;		/**< delta X, displacement of the lower left corner of the field */
	static const unsigned int LOC_DELTA_Y = PIECE_SIZE - 1;		/**< delta Y, displacement of the lower left corner of the field */
	static const unsigned int LOC_MIN_Y = LOC_DELTA_Y;			/**< lowest location Y */
	static const unsigned int LOC_MAX_Y = FIELD_HEIGHT + LOC_DELTA_Y - 1; /**< Highest location Y */
	static const unsigned int LOC_START_X = FIELD_WIDTH / 2; /**< generate location Y */
	static const unsigned int LOC_START_Y = LOC_MAX_Y - 3;		/**< generate location Y */

	static const unsigned int FILLER_FULL = ~0u;				/**< Filler: 0xffffff */
	static const unsigned int FILLER_EMPTY = (~0u << (LOC_DELTA_X + FIELD_WIDTH)) ^ ~(~0u << (LOC_DELTA_X)); /**< Blank filler */

	static const unsigned int COLOR_BITS = 3;					/**< COLOR_BITS = ceil(log(PIECE_TYPE_MAX) / log(2)) */
	static const unsigned int COLOR_MASK = ~(~0u << COLOR_BITS);	/**< default COLOR_MASK = 00000000000000000000000000000111(2) */

private :
	
	/**
	 *	\brief	Constructor
	 *			Useless.
	 */
	TetrisData();
	
	/**
	 *	\brief	Destructor
	 *			Useless.
	 */
	~TetrisData();
};


typedef TetrisData TETRISDATA;
