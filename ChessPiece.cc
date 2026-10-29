#include "ChessPiece.hh"
#include "ChessBoard.hh"

using Student::ChessBoard;
using Student::ChessPiece;

bool ChessPiece::isPathClear(int toRow, int toColumn)
{
    //get row and column vals
    int row = getRow();
    int column = getColumn();

    //unit step towards target: -1, 0 or +1 in each direction
    int dRow = (toRow>row) - (toRow<row);
    int dCol = (toColumn>column) - (toColumn<column);

    int r = row + dRow;
    int c = column + dCol;


    while ((r != toRow)||(c != toColumn))
    {
        if (getBoard().getPiece(r,c) != nullptr)
            return false;
        r += dRow;
        c += dCol;
    }
    return true;
}
