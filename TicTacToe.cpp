//////////////////////////////////
// CPE 305 Project 1		      	//
// Neil Howarth & Paul Rose	  	//
// Due 10/15/2014		        		//
//////////////////////////////////

// Design a Tic-Tac-Toe game

#include <iostream>
using namespace std;

bool checkwinner(char n, char csq[]) //checks to see if any of the win conditions are met - Neil
{
	bool bGameNotOver;

		if ( csq[7] == n && csq[8] == n && csq[9] == n)
			bGameNotOver = false;
		else if ( csq[4] == n && csq[5] == n && csq[6] == n)
			bGameNotOver = false;
		else if ( csq[1] == n && csq[2] == n && csq[3] == n)
			bGameNotOver = false;
		else if ( csq[7] == n && csq[4] == n && csq[1] == n)
			bGameNotOver = false;
		else if ( csq[8] == n && csq[5] == n && csq[2] == n)
			bGameNotOver = false;
		else if ( csq[9] == n && csq[6] == n && csq[3] == n)
			bGameNotOver = false;
		else if ( csq[7] == n && csq[5] == n && csq[3] == n)
			bGameNotOver = false;
		else if ( csq[1] == n && csq[5] == n && csq[9] == n)
			bGameNotOver = false;
		else
			bGameNotOver = true;

	return bGameNotOver;
}

void printboard(char csq[]) // prints the updated board - Paul
{
    cout << endl;
	cout << csq[1] << "|" << csq[2] << "|" << csq[3] << endl;
	cout << "-+-+-"<< endl;
	cout << csq[4] << "|" << csq[5] << "|" << csq[6] << endl;
	cout << "-+-+-"<< endl;
	cout << csq[7] << "|" << csq[8] << "|" << csq[9] << endl << endl;
}

int main()
{
	char replay;

	do{ 


    // Declare variables - neil

	char csq[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int iPlayerTurn = 1;
	bool bGameNotOver = true;
	char X = 'X';
	char O = 'O';
	char cPlayerMark;
	bool bValidInput;
	char cNextMove;
	bool notoverX;
	bool notoverO;
	bool notoverT;
	char winner = 'a';

	//game start - paul
	cout << endl << "Welcome to Tic-Tac-Toe 2014 GOTY Deluxe Collectors Gold Plus Edition"<<endl;
	cout << "\t\tBy Neil Howarth & Paul Rose"<<endl<<endl;
	printboard(csq);


	do{

    // selects the current players turn - paul
	cout << "Player" << iPlayerTurn << "'s move:\t";

	if (iPlayerTurn == 1) {
		cPlayerMark = X;
	} else {
		cPlayerMark = O;
	}


	do{
        // enter players move and replaces them in the board - neil
		cin >> cNextMove;
		bValidInput=true;

		if (cNextMove == '1' && csq[1] == '1')
			csq[1] = cPlayerMark;
		else if (cNextMove == '2' && csq[2] == '2')
			csq[2] = cPlayerMark;
		else if (cNextMove == '3' && csq[3] == '3')
			csq[3] = cPlayerMark;
		else if (cNextMove == '4' && csq[4] == '4')
			csq[4] = cPlayerMark;
		else if (cNextMove == '5' && csq[5] == '5')
			csq[5] = cPlayerMark;
		else if (cNextMove == '6' && csq[6] == '6')
			csq[6] = cPlayerMark;
		else if (cNextMove == '7' && csq[7] == '7')
			csq[7] = cPlayerMark;
		else if (cNextMove == '8' && csq[8] == '8')
			csq[8] = cPlayerMark;
		else if (cNextMove == '9' && csq[9] == '9')
			csq[9] = cPlayerMark;
		else
			{
			cout<< " Invalid Input, Try Again: ";
			bValidInput = false;
			}

	
	}while(!bValidInput);


    // switches players turn - paul
	if(iPlayerTurn == 1)
		iPlayerTurn = 2;
	else
		iPlayerTurn = 1;

    // updates board - paul
	printboard(csq);

	// checks to see if the game is a draw - neil
	if(csq[1] != '1' && csq[2] != '2' && csq[3] != '3' && csq[4] != '4' && csq[5] != '5' && csq[6] != '6' && csq[7] != '7' && csq[8] != '8' && csq[9] != '9')
           {
           winner = 'a';
           notoverT = false;
            }

    // checks to see if player x won the game - neil
	notoverX = checkwinner(X,csq);
		if(!notoverX)
			winner = X;

    // checks to see if player o won the game - neil
	notoverO = checkwinner(O,csq);
		if(!notoverO)
			winner = O;

	}while(notoverX && notoverO && notoverT); //does loop unless someone has won - neil

	//prints the outcome of the game - paul
	if(winner == X)
		cout<<"Player 1 is the winner!"<<endl;

	else if(winner == O)
		cout<<"Player 2 is the winner!"<<endl;

    else
        cout<<"Its a Draw!"<<endl;

    //asks user if they want to play again - neil
	cout<<"Play again? (y/n):\t";
	cin >> replay;

	}while(replay=='y'); //loops if they want to play again, terminates otherwise - neil

}
