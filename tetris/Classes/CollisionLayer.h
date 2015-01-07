/*********************************************************************
 *	@file		CollisionLayer.h
 *	@brief		Class CollisionLayer
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#pragma once

#include "TetrisData.h"
#include "TetrisPiece.h"

/**
 *	\brief	Collision Layer.
 *			e.g. 10 x 10, Storage:
 *			[16]11100000000001111111111111111111
 *			[15]11100000000001111111111111111111
 *			[14]11100000000001111111111111111111
 *			[13]11100000000001111111111111111111
 *			[12]11100000000001111111111111111111
 *			[11]11100000000001111111111111111111
 *			[10]11100000000001111111111111111111
 *			[ 9]11100000000001111111111111111111
 *			[ 8]11100000000001111111111111111111
 *			[ 7]11100000000001111111111111111111
 *			[ 6]11100000000001111111111111111111
 *			[ 5]11100000000001111111111111111111
 *			[ 4]11100000000001111111111111111111
 *			[ 3]11100000000001111111111111111111
 *			[ 2]11111111111111111111111111111111
 *			[ 1]11111111111111111111111111111111
 *			[ 0]11111111111111111111111111111111
 *				[begin]						[end]
 */
class CollisionLayer {

public:

	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/

	/**
	 *	\brief Constructor
	 */
	CollisionLayer();
	
	/**
	 *	\brief	Destructor
	 */
	~CollisionLayer();

	/*==========================================================================*/
	/*	public Methods, Modify													*/
	/*==========================================================================*/
	
	/**
	 *	\brief	Load a new field.
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
	 *	\param	type		piece's type.
	 *	\param	rotation	piece's rotation.
	 *	\param	x			piece's x.
	 *	\param	y			piece's y.
	 *
	 *	\return		1, collision. Or 0, no collision.
	 */
	bool IsCollided(const unsigned int type, const unsigned int rotation, const unsigned int x, const unsigned int y) const;

	/**
	 *	\brief	Check the collision.
	 *
	 *	\param	y			line-y.
	 *
	 *	\return		1, full. Or 0, not.
	 */
	bool IsLineFull(const unsigned int y) const;

private:

	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/

	const int PIECE_RELATIVE_X;				/**< adjust the piece's x coordinate */
	const int PIECE_RELATIVE_Y;				/**< adjust the piece's y coordinate */

	unsigned int *m_Field;					/**< store field in bits */

};

