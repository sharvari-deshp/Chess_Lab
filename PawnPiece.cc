#include "PawnPiece.hh"
#include "ChessBoard.hh"

using Student::ChessBoard;
using Student::ChessPiece;
using Student::PawnPiece;

bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
    ChessBoard &board = getBoard();
    Color color = getColor();
    int row = getRow();
    int column = getColumn();

    //black moves down board, white moves up
    int forward;
    int startRow;
    if (color == Black)
    {
        forward = 1;   //black moves down board
        startRow = 1;
    }
    else
    {
        forward = -1;  // white moves up board
        startRow = board.getNumRows() - 2;
    }

    int dRow = toRow-row;
    int dCol = toColumn-column;
    ChessPiece *target = board.getPiece(toRow, toColumn);

    //one step ahead onto empty square
    if (dCol == 0 && dRow == forward)
        return target == nullptr;

    //two steps ahead from starting row, both squares empty
    if (dCol == 0 && dRow == 2 * forward && row == startRow)
    {
        return target == nullptr && board.getPiece(row + forward, column) == nullptr;
    }
        

    //diagonal capture of opponent (pawn)
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

