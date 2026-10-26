#include "BishopPiece.hh"
#include "ChessBoard.hh"

using Student::BishopPiece;

bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    int dRow = toRow-getRow();
    int dCol = toColumn-getColumn();
    if ((dRow == 0) || (dRow != dCol && dRow != -dCol)){
        return false; 
    }
    return isPathClear(toRow,toColumn);
}

const char *BishopPiece::toString()
{
    if (getColor() == White)
    {
        return "♗";
    }
    else
    {
    return "♝";
    }
}
