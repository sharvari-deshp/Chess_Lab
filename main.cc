#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
//new libraries added
#include <cstring>
#include <iostream>

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

//Rook, Bishop, Pawn Unit Tests

void test_rook()
{
    //rook in corner of 4x4 board
    Student::ChessBoard b(4, 4);
    b.createChessPiece(White, Rook, 0, 0);
    assert(b.isValidMove(0, 0, 0, 3)); //along top edge
    assert(b.isValidMove(0, 0, 3, 0)); //down left edge

    assert(b.isValidMove(0, 0, 0, 1)); // singular  step
    assert(!b.isValidMove(0, 0, 1, 1)); //diag
    assert(!b.isValidMove(0, 0, 2, 3)); //knight-ish
    assert(!b.isValidMove(0, 0, 0, 0)); //same square
    assert(!b.isValidMove(0, 0, -1, 0)); //off  board
    assert(!b.isValidMove(0, 0, 0, 4));

    // Blocked paths: friendly piece on the row, enemy on the column
    b.createChessPiece(White, Rook, 0, 2);
    b.createChessPiece(Black, Rook, 2, 0);
    assert(b.isValidMove(0, 0, 0, 1));  // before blocker
    assert(!b.isValidMove(0, 0, 0, 2)); //onto own piece
    assert(!b.isValidMove(0, 0, 0, 3)); //jumping own piece
    assert(b.isValidMove(0, 0, 2, 0));  //capture enemy
    assert(!b.isValidMove(0, 0, 3, 0)); //jump enemy

    //black rook moving upward or leftward toward the blocker
    assert(b.isValidMove(2, 0, 1, 0));
    assert(b.isValidMove(2, 0, 0, 0)); //capture
    assert(b.isValidMove(2, 0, 2, 3));

    std::cout << "all rook tests passed!" << std::endl;
}

void test_bishop()
{
    //bishop in a corner of 4x4 board
    Student::ChessBoard b(4, 4);
    b.createChessPiece(Black, Bishop, 3, 0);
    assert(b.isValidMove(3, 0, 0, 3));  //full diagonal
    assert(b.isValidMove(3, 0, 2, 1));
    assert(!b.isValidMove(3, 0, 2, 0)); //straight
    assert(!b.isValidMove(3, 0, 3, 3)); //straight
    assert(!b.isValidMove(3, 0, 1, 3)); //|drow|!=|dcol|
    assert(!b.isValidMove(3, 0, 4, 1)); //off-board
    assert(!b.isValidMove(3, 0, 2, -1));

    //blocked by enemy in the middle of diagonal
    b.createChessPiece(White, Rook, 1, 2);
    assert(b.isValidMove(3, 0, 2, 1));
    assert(b.isValidMove(3, 0, 1, 2));  //capture
    assert(!b.isValidMove(3, 0, 0, 3)); //jumping

    // Blocked by a friendly piece
    b.createChessPiece(Black, Rook, 1, 2);
    assert(!b.isValidMove(3, 0, 1, 2));
    assert(!b.isValidMove(3, 0, 0, 3));

    //bishop on top edge, all four directions
    Student::ChessBoard e(4, 4);
    e.createChessPiece(White, Bishop, 0, 1);
    assert(e.isValidMove(0, 1, 1, 0));
    assert(e.isValidMove(0, 1, 1, 2));
    assert(e.isValidMove(0, 1, 2, 3));
    assert(!e.isValidMove(0, 1, -1, 0));
    assert(!e.isValidMove(0, 1, -1, 2));

    std::cout << "bishop tests passed!" << std::endl;
}

void test_pawn()
{
    //white pawn on  starting row (n-2=6) of 8x8 board
    Student::ChessBoard b(8, 8);
    b.createChessPiece(White, Pawn, 6, 3);
    assert(b.isValidMove(6, 3, 5, 3));  //one step
    assert(b.isValidMove(6, 3, 4, 3));  //two steps (from start)
    assert(!b.isValidMove(6, 3, 3, 3)); //3 steps
    assert(!b.isValidMove(6, 3, 7, 3)); //backwards
    assert(!b.isValidMove(6, 3, 6, 4)); //sideways
    assert(!b.isValidMove(6, 3, 5, 2)); //diagonal onto empty
    assert(!b.isValidMove(6, 3, 5, 4));
    assert(!b.isValidMove(6, 3, 4, 5)); //long diag

    //diag captures need opp
    b.createChessPiece(Black, Rook, 5, 2);
    b.createChessPiece(White, Rook, 5, 4);
    assert(b.isValidMove(6, 3, 5, 2));  //capture enemy
    assert(!b.isValidMove(6, 3, 5, 4)); //own piece

    //2-step blocked at target square
    b.createChessPiece(Black, Bishop, 4, 3);
    assert(b.isValidMove(6, 3, 5, 3));
    assert(!b.isValidMove(6, 3, 4, 3));

    //blocked directly in front: no forward moves whatsoever
    b.createChessPiece(Black, Bishop, 5, 3);
    assert(!b.isValidMove(6, 3, 5, 3)); //cannot capture straight ahead
    assert(!b.isValidMove(6, 3, 4, 3)); //cannot jump

    // white pawn NOT on starting row
    Student::ChessBoard m(8, 8);
    m.createChessPiece(White, Pawn, 5, 0);
    assert(m.isValidMove(5, 0, 4, 0));
    assert(!m.isValidMove(5, 0, 3, 0));
    assert(!m.isValidMove(5, 0, 4, -1)); //off left edge

    //white pawn on last row cant move forward
    m.createChessPiece(White, Pawn, 0, 7);
    assert(!m.isValidMove(0, 7, -1, 7));
    assert(!m.isValidMove(0, 7, 1, 7));

    //black pawn on starting row (1) moves down the board
    Student::ChessBoard k(8, 8);
    k.createChessPiece(Black, Pawn, 1, 7);
    assert(k.isValidMove(1, 7, 2, 7));
    assert(k.isValidMove(1, 7, 3, 7));
    assert(!k.isValidMove(1, 7, 0, 7)); //backward for black
    assert(!k.isValidMove(1, 7, 2, 8)); //off  right edge
    k.createChessPiece(White, Pawn, 2, 6);
    assert(k.isValidMove(1, 7, 2, 6));  // capture
    assert(k.isValidMove(2, 6, 1, 7));  //white captures back

    //black pawn off of start row
    k.createChessPiece(Black, Pawn, 3, 0);
    assert(k.isValidMove(3, 0, 4, 0));
    assert(!k.isValidMove(3, 0, 5, 0));

    std::cout << "all pawn tests passed!" << std::endl;
}

void test_non_square()
{
    //4x6: white pawn start row is 2, black is 1
    Student::ChessBoard w(4, 6);
    w.createChessPiece(White, Pawn, 2, 5);
    w.createChessPiece(Black, Pawn, 1, 0);
    assert(w.isValidMove(2, 5, 1, 5));
    assert(w.isValidMove(2, 5, 0, 5));
    assert(!w.isValidMove(2, 5, 1, 6)); //off of right edge
    assert(w.isValidMove(1, 0, 2, 0));
    assert(w.isValidMove(1, 0, 3, 0));

    w.createChessPiece(White, Rook, 3, 0);
    assert(!w.isValidMove(1, 0, 3, 0)); //two-step onto a piece
    assert(w.isValidMove(3, 0, 3, 5));  // across the wide axis
    assert(!w.isValidMove(3, 0, 3, 6));
    assert(w.isValidMove(3, 0, 1, 0));  // capture up the column
    assert(!w.isValidMove(3, 0, 0, 0)); // blocked by the pawn

    w.createChessPiece(Black, Bishop, 0, 0);
    assert(w.isValidMove(0, 0, 3, 3));
    assert(!w.isValidMove(0, 0, 3, 4));
    assert(!w.isValidMove(0, 0, 4, 4));

        //6x4: white pawn start row is still 4
    Student::ChessBoard s(6, 4);
    s.createChessPiece(White, Pawn, 4, 2);
    s.createChessPiece(Black, Bishop, 5, 3);
    s.createChessPiece(Black, Rook, 0, 0);
    assert(s.isValidMove(4, 2, 2, 2));  //pawn two-step from start row
    assert(!s.isValidMove(5, 3, 2, 0)); // bishop blocked by pawn at (4,2)
    assert(s.isValidMove(5, 3, 4, 2));  // bishop captures pawn
    assert(!s.isValidMove(5, 3, 4, 4)); //bishop off right edge (cols 0-3)
    assert(s.isValidMove(0, 0, 5, 0));  //rook down full 6-row column
    assert(!s.isValidMove(0, 0, 0, 4)); //rook off right edge


    std::cout << "all non-square tests passed!" << std::endl;
}

void test_path_clear_and_symbols()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(White, Rook, 0, 0);
    b.createChessPiece(Black, Bishop, 3, 3);
    b.createChessPiece(Black, Pawn, 1, 2);
    Student::ChessPiece *rook = b.getPiece(0, 0);
    Student::ChessPiece *bishop = b.getPiece(3, 3);
    Student::ChessPiece *pawn = b.getPiece(1, 2);

    assert(rook->isPathClear(0, 3));
    assert(rook->isPathClear(0, 1)); // adjacent- nothing in between
    assert(rook->isPathClear(3, 3)); // diagonal through (1,1),(2,2)
    assert(bishop->isPathClear(0, 0));
    b.createChessPiece(White, Pawn, 2, 2);
    assert(!rook->isPathClear(3, 3));
    assert(rook->isPathClear(2, 2)); // blocker is target itself

    assert(std::strcmp(rook->toString(),"♖") == 0);
    assert(std::strcmp(bishop->toString(),"♝") == 0);
    assert(std::strcmp(pawn->toString(),"♟") == 0);
    b.createChessPiece(Black, Rook, 0,0);
    b.createChessPiece(White, Bishop, 3,3);
    assert(std::strcmp(b.getPiece(0, 0)->toString(),"♜")== 0);
    assert(std::strcmp(b.getPiece(3, 3)->toString(),"♗")==0);
    assert(std::strcmp(b.getPiece(2, 2)->toString(),"♙")==0);

    std::cout << b.displayBoard().str();
    std::cout << "isPathClear/toString tests passed" << std::endl;
}

int main()
{
    test_part1_4x4_1();
    test_rook();
    test_bishop();
    test_pawn();
    test_non_square();
    test_path_clear_and_symbols();
    return EXIT_SUCCESS;
}
