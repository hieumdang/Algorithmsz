#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int board[8][8];
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			board[i][j] = 0;
		}
	}

	int i, j;
	cout << "Enter i: ";
	cin >> i;
	cout << "Enter j: ";
	cin >> j;
	i -= 1; j -= 1;
	board[i][j] = 1;

	

	for (int m = 2; m <= 64; m++) {
		int npos = 0;
		int KTMOV1[] = { -2,-1,1,2,2,1,-1,-2 };
		int KTMOV2[] = { 1,2,2,1,-1,-2,-2,-1 };
		int NEXTI[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		int NEXTJ[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		
		int nextsquare = 1;
		for (int n = 0; n < 8; n++) {
			int itemp = (i + KTMOV1[n]);
			int jtemp = (j + KTMOV2[n]);
			nextsquare = board[itemp][jtemp];
			if (nextsquare == 0)
			{
				if ((itemp < 8) && (jtemp < 8) && (itemp > -1) && (jtemp > -1)) {
					npos += 1;
					NEXTI[n] = itemp;
					NEXTJ[n] = jtemp;
				}

				else {
					NEXTI[n] = -1;
					NEXTJ[n] = -1;
				}
			}

			else {
				NEXTI[n] = -1;
				NEXTJ[n] = -1;
			}
			nextsquare = 1;
		}

		/*int *NEXTI = new int[npos];
		int *NEXTJ = new int[npos];

		for (int z = 0; z < npos; z++) {
			for (int n = 0; n < 8; n++) {
				int itemp = (i + KTMOV1[n]);
				int jtemp = (j + KTMOV2[n]);
				nextsquare = board[itemp][jtemp];
				if (nextsquare == 0)
				{
 					if ((itemp < 8) && (jtemp < 8) && (itemp > -1) && (jtemp > -1)) {
						NEXTI[z] = i + KTMOV1[n];
						NEXTJ[z] = j + KTMOV2[n];
						break;
					}
				}
				nextsquare = 1;
			}
		}
		*/

		if (npos == 0) {
			cout << "Failure." << endl;
			break;
		}
		/*else if (npos == 1) {
			int MIN_i = 1, MIN_j = 1;
			i = NEXTI[MIN_i];
			j = NEXTJ[MIN_j];
			board[i][j] = m;
			break;
		}*/

		/*int *EXITS = new int[npos];*/
		int EXITS[8] = { 0,0,0,0,0,0,0,0 };
		int nextsquare2 = 1;

		for (int l = 0; l < 8; l++) {
				if (NEXTI[l] > -1 && NEXTJ[l] > -1) {
					for (int k = 0; k < 8; k++)
					{
						int itemp = NEXTI[l] + KTMOV1[k];
						int jtemp = NEXTJ[l] + KTMOV2[k];
						nextsquare2 = board[itemp][jtemp];
						if (nextsquare2 == 0) {
							if ((itemp < 8) && (jtemp < 8) && (itemp > -1) && (jtemp > -1)) {
								EXITS[l] += 1;
							}
						}
						nextsquare2 = 1;
					}
				}
		}
			
		int minm = 0;
		int minval = 0;

		for (int x = 0; x < 7; x++) {
			if ((EXITS[x] == 0) && (EXITS[x + 1] != 0)) {
				if (minval != 0) {
					if ((EXITS[x + 1] < minval)) {
						minm = x + 1;
						minval = EXITS[x + 1];
					}
				}
				else {
					minm = x + 1;
					minval = EXITS[x + 1];
				}
			}

			else if ((EXITS[x] != 0) && (EXITS[x + 1] != 0)) {
				if ((EXITS[x + 1] < EXITS[x])) {
					if (minval != 0) {
						if ((EXITS[x + 1] < minval)) {
							minm = x + 1;
							minval = EXITS[x + 1];
						}
					}
					else {
						minm = x + 1;
						minval = EXITS[x + 1];
					}
				}
				else if ((EXITS[x + 1] == EXITS[x]) && (minval == 0)) {
					minval = EXITS[x];
					minm = x;
				}
				else if ((EXITS[x + 1] == EXITS[x]) && (EXITS[x] < minval)) {
					minval = EXITS[x];
					minm = x;
				}

			}

			else if ((EXITS[x] != 0) && (EXITS[x + 1] == 0)) {
				if (minval != 0) {
					if ((EXITS[x] < minval)) {
						minm = x;
						minval = EXITS[x];
					}
				}
				else {
					minm = x;
					minval = EXITS[x];
				}
			}


		}

		int MIN_i = NEXTI[minm];
		int MIN_j = NEXTJ[minm];

		i = MIN_i;
		j = MIN_j;
		board[i][j] = m;

	}

	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			cout << setw(10) << board[i][j];
		}
		cout << endl;
	}

	system("pause");
}
