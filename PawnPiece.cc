#include "PawnPiece.hh"
#include "ChessBoard.hh"

using Student::ChessBoard;
using Student::ChessPiece;
using Student::PawnPiece;

bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
    if (!canLandOn(toRow, toColumn))
        return false;

    ChessBoard &board = getBoard();
    Color color = getColor();
    int row = getRow();
    int column = getColumn();

    int forward;
    int startRow;
    if (color == Black)
    {
        forward = 1;
        startRow = 1;
    }
    else
    {
        forward = -1;
        startRow = board.getNumRows() - 2;
    }

    int dRow = toRow-row;
    int dCol = toColumn-column;
    ChessPiece *target = board.getPiece(toRow, toColumn);

    if (dCol == 0 && dRow == forward)
        return target == nullptr;

    if (dCol == 0 && dRow == 2 * forward && row == startRow)
    {
        return target == nullptr && board.getPiece(row + forward, column) == nullptr;
    }
        

    if ((dCol == 1 || dCol == -1) && dRow == forward)
    {
        return target != nullptr && target->getColor() != color;
    }
        

    return (false);
}


const char *PawnPiece::toString()
{
    if (getColor() == White)
    {
        return "♙";
    }
    else
    {
        return "♟";
    }
}

