/*********************************************************************
 *	@file		ColorLayer.hpp
 *	@brief		Class ColorLayer
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#pragma once

#include "TetrisData.h"
#include "TetrisPiece.h"

/**
 *	\brief	Color Layer.
 *			Every three bits represent a color.
 *			e.g. 10 x 10, the lower right corner there is a 'O'(001).
 *			Storage:
 *			[ 9]00000000000000000000000000000000
 *			[ 8]00000000000000000000000000000000
 *			[ 7]00000000000000000000000000000000
 *			[ 6]00000000000000000000000000000000
 *			[ 5]00000000000000000000000000000000
 *			[ 4]00000000000000000000000000000000
 *			[ 3]00000000000000000000000000000000
 *			[ 2]00000000000000000000000000000000
 *			[ 1]00000000000000000000000010010000
 *			[ 0]00000000000000000000000010010000
 *				[begin]						[end]
 */
class ColorLayer {

public:

	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/

	/**
	 *	\brief Constructor
	 */
	ColorLayer();
	
	/**
	 *	\brief	Destructor
	 */
	~ColorLayer();

	/*==========================================================================*/
	/*	public Methods, Modify													*/
	/*==========================================================================*/
	
	/**
	 *	\brief	Load a new empty field.
	 */
	void ClearField();

	/**
	 *	\brief	Add the piece to field.
	 *
	 *	\param	type		piece's type.
	 *	\param	rotation	piece's rotation.
	 *	\param	x			piece's x.
	 *	\param	y			piece's y.
	 */
	void PlacePiece(const unsigned int type, const unsigned int rotation, const int x, const int y);

	/**
	 *	\brief	Delete a row.
	 */
	void DeleteRow(const unsigned int i);


	/*==========================================================================*/
	/*	public Methods, Query													*/
	/*==========================================================================*/
	
	/**
	 *	\brief	Check the collision.
	 *
	 *	\param	piece		array that store piece in bits.
	 *	\param	x			piece's x.
	 *	\param	y			piece's y.
	 *
	 *	\return		1, collision. Or 0, no collision.
	 */
	unsigned int GetColorIndex(const unsigned int x, const unsigned int y) const;


private:

	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/

	const int PIECE_RELATIVE_X;				/**< adjust the piece's x coordinate */
	const int PIECE_RELATIVE_Y;				/**< adjust the piece's y coordinate */

	unsigned int * m_Field;					/**< store field in bits */

};

